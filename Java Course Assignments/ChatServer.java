/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javaapplication31;

import java.io.DataInputStream;
import java.io.IOException;
import java.io.PrintStream;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Vector;
import java.util.logging.Level;
import java.util.logging.Logger;

public class ChatServer {

    ServerSocket MyServer;
    Socket s;

    public static void main(String[] args) {
        new ChatServer();

    }

    public ChatServer() {
        try {
            MyServer = new ServerSocket(5050);
            while (true) {
                s = MyServer.accept();
                new ChatHandler(s);
            }

        } catch (IOException ex) {
            ex.printStackTrace();
        }

    }

}

class ChatHandler extends Thread {

    DataInputStream dis;
    PrintStream ps;
    static Vector<ChatHandler> clientsVector = new Vector<ChatHandler>();
    static int counter =0;
    int removedID;
    public ChatHandler(Socket cs) {
        try {
            dis = new DataInputStream(cs.getInputStream());
            ps = new PrintStream(cs.getOutputStream());
        } catch (IOException ex) {
            ex.printStackTrace();
        }
        clientsVector.add(this);
        counter++;
        ps.println(counter);
        start();
    }

    public void run() {
        while (true) {
            String str = null;
            try {
                str = dis.readLine();
                if(str!=null && str.charAt(0)=='U'){
                System.out.println("Termination");
                removedID = str.charAt(1);
                System.out.println(removedID - 48);
                clientsVector.remove((removedID - 49));
                
                }
            } catch (IOException ex) {
                Logger.getLogger(ChatHandler.class.getName()).log(Level.SEVERE, null, ex);
            }
            sendMessageToAll(str);
        }

    }

    private void sendMessageToAll(String str) {
        for(ChatHandler ch : clientsVector){
            ch.ps.println(str);
        }
    }
}

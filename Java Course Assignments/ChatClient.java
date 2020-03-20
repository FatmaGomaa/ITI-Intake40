/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javaapplication31;

import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.DataInputStream;
import java.io.IOException;
import java.io.PrintStream;
import java.net.Socket;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;
import javax.swing.JTextField;

public class Client extends JFrame {

    Socket mySocket;
    DataInputStream dis;
    PrintStream ps;
    int id;
    volatile  int socketClosed=0;
    public static void main(String[] args) {
        Client c = new Client();
        c.setSize(400, 500);
        c.setVisible(true);
    }

    public Client() {
        try {

            mySocket = new Socket("127.0.0.1", 5050);
            dis = new DataInputStream(mySocket.getInputStream());
            ps = new PrintStream(mySocket.getOutputStream());
            ps.println("Test Test");
            String replyMsg = dis.readLine();
            System.out.println(replyMsg);
            id = Integer.parseInt(replyMsg);

        } catch (IOException ex) {
            ex.printStackTrace();
        }

        this.setLayout(new FlowLayout());
        JTextArea ta = new JTextArea(5, 20);
        JScrollPane scroll = new JScrollPane(ta);
        scroll.setViewportView(ta);
        JTextField tf = new JTextField(30);
        JButton okButton = new JButton("Send");
        JButton closeButton = new JButton("close connection");
        okButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent ae) {
                ///ta.append(tf.getText() + "\n");
                ps.println(tf.getText());

            }
        });

        closeButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent ae) {
                ///ta.append(tf.getText() + "\n");
                try {
                    ps.println("U" + id);
                    ps.close();
                    
                } catch (Exception ex) {
                    ex.printStackTrace();
                }
            }
        });

        add(scroll);
        add(tf);
        add(okButton);
        add(closeButton);

        new Thread(new Runnable() {
            public void run() {
                while (socketClosed != 1) {
                    try {
                        ta.append(dis.readLine() + "\n");
                    } catch (IOException ex) {
                        Logger.getLogger(Client.class.getName()).log(Level.SEVERE, null, ex);
                    }
                }

            }

        }).start();

    }

}

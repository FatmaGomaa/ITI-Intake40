/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javaapplication31;

import java.applet.Applet;
import java.awt.Graphics;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author FatmaGomaa
 */
public class NewApplet extends Applet implements Runnable {

    Thread th;
    int x=0;
    int y=0;
    public void init() {
        th = new Thread(this);
        th.start();
    }

    // TODO overwrite start(), stop() and destroy() methods

    public void paint(Graphics g){
       if(x<getWidth()){ 
       g.drawString("Hello World!", 50+x, 100+y);
       }else{
         x=0; y+= 20; 
         g.drawString("Hello World!", 50+x, 100+y);

       }
    }
    
    @Override
    public void run() {
        while(true){
            x+=20;
            repaint();
            try {
                th.sleep(500);
            } catch (InterruptedException ex) {
                Logger.getLogger(NewApplet.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
    }
}

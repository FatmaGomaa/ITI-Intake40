/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javaapplication31;

import java.applet.Applet;
import java.awt.Graphics;
import java.util.Date;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author FatmaGomaa
 */
public class NewApplet extends Applet implements Runnable {

    Thread th;
    /**
     * Initialization method that will be called after the applet is loaded into
     * the browser.
     */
    public void init() {
       th = new Thread(this);
       th.start(); 
    }

    public void paint(Graphics g){
      Date d = new Date();
      g.drawString(d.toString(), 50, 100);
    }
    
    public void run(){
        while(true){
        repaint();
        try {
            th.sleep(500);
        } catch (InterruptedException ex) {
            Logger.getLogger(NewApplet.class.getName()).log(Level.SEVERE, null, ex);
        }
        
        }
    }
    // TODO overwrite start(), stop() and destroy() methods
}

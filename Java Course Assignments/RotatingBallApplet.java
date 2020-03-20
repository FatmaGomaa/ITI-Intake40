/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javaapplication31;

import java.applet.Applet;
import java.awt.Color;
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
    int y=100;
    public void init() {
        th = new Thread(this);
        th.start();
    }

    // TODO overwrite start(), stop() and destroy() methods

    public void paint(Graphics g){
        g.drawOval(x, y, 50, 50);
        g.setColor(Color.red);
        g.fillOval(x, y, 50, 50);
        
       if(y <= getHeight()/2 ){
          
           if(y <= 50 && x<= getWidth()/2 -50){
              x+=5;
              y-=5;
           }else if(y <= 50 && x> getWidth()/2 -50){
               x+=5;
               y+=5;
           }
           else if(y > 0 && x<= getWidth()/2){
              x+=5;
              y-=5;
           }else if(y > 0 && x> getWidth()/2){
               x+=5;
               y+=5;
           }
           
       }else if(y > getHeight()/2 ){
            
           if(y >= getHeight()-50 && x>= getWidth()/2){
               x-=5;
               y+=5;
           }else if(y >= getHeight()-50 && x< getWidth()/2){
               x-=5;
               y-=5;
           }else if(y < getHeight() && x>= getWidth()/2){
               x-=5;
               y+=5;
           }else if(y < getHeight() && x< getWidth()/2){
               x-=5;
               y-=5;
           }
           
       }
       
    }
    
    @Override
    public void run() {
        while(true){
            repaint();
            try {
                th.sleep(10);
            } catch (InterruptedException ex) {
                Logger.getLogger(NewApplet.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
    }
}

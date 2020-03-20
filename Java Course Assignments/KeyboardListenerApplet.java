
package javaapplication31;

import java.applet.Applet;
import java.awt.Graphics;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;


public class NewApplet extends Applet implements KeyListener{
    int x = 50;
    int y = 100;
   
    public void init() {
        this.addKeyListener(this);
        System.out.println("int");
    }
    
    public void paint(Graphics g){
       g.drawString("java", x, y);
    }

    @Override
    public void keyTyped(KeyEvent e) {}

    @Override
    public void keyPressed(KeyEvent e) {
            int c = e.getKeyCode();
            System.out.println(c);
            switch(c){
                case 37:
                    x-=20;
                    break;
                case 38:
                    y-=20;
                    break;
                case 39:
                    x+=20;
                    break;
                case 40:
                    y+=20;
                    break;
                
            }
            repaint();    
    }

    @Override
    public void keyReleased(KeyEvent e) {}
 

}

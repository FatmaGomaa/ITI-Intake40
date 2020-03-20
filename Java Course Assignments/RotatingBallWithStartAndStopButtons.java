
package javaapplication31;


import java.applet.Applet;
import java.awt.Button;
import java.awt.Color;
import java.awt.Graphics;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.logging.Level;
import java.util.logging.Logger;


public class NewApplet extends Applet implements Runnable {

    Thread th;
    int x=0;
    int y=100;
    Button increment; 
    Button decrement;
    volatile int startFlag = 0;
    
    public void init() {
        th = new Thread(this);
        increment = new Button("start");
        increment.addActionListener(new MyButtonListener());
        add(increment);
        
        decrement = new Button("pause");
        decrement.addActionListener(new MyButtonListener2());
        add(decrement);
        
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
            
            if(startFlag == 1){
            repaint();
            try {
                th.sleep(10);
            } catch (InterruptedException ex) {
                Logger.getLogger(NewApplet.class.getName()).log(Level.SEVERE, null, ex);
            }
            }
            
            
        }
    }
    
    public class MyButtonListener implements ActionListener{

        @Override
        public void actionPerformed(ActionEvent e) {
          startFlag =1;
          
        }     
    }
    
    public class MyButtonListener2 implements ActionListener{

        @Override
        public void actionPerformed(ActionEvent e) {
          startFlag = 0;
        }     
    }
}


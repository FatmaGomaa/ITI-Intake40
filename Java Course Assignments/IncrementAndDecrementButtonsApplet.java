
package javaapplication31;

import java.applet.Applet;
import java.awt.Button;
import java.awt.Graphics;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;


public class NewApplet extends Applet  {
    
    Thread th; 
    int x=0;
    Button increment; 
    Button decrement; 

    public void init() {
        increment = new Button("+");
        increment.addActionListener(new MyButtonListener());
        add(increment);
        
        decrement = new Button("-");
        decrement.addActionListener(new MyButtonListener2());
        add(decrement);
       
        /*
        th = new Thread( new Runnable(){
        @Override
        public void run() {
            if(x>=10){
               x=10; 
            }else if(x<=0){
               x=0; 
            }
            repaint();            
        }        
    }
    );
        th.start();   
        
        */
    }
    
    public void paint(Graphics g){
        if(x>=10){
               x=10; 
            }else if(x<=0){
               x=0; 
            }
        g.drawString("counter = " + x, 100, 100);
        
    }
    
    public class MyButtonListener implements ActionListener{

        @Override
        public void actionPerformed(ActionEvent e) {
        
          x++;  
          repaint();
          
        }     
    }
    
    public class MyButtonListener2 implements ActionListener{

        @Override
        public void actionPerformed(ActionEvent e) {
          
          x--;  
          repaint();
          
        }     
    }
    
    
}

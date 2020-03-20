
package javaapplication31;

import java.applet.Applet;
import java.awt.Graphics;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.event.MouseMotionListener;


public class NewApplet extends Applet{
    
    int x1,x2,y1,y2,row=0, col=0;
    int[][] lines = new int[30][4];

    public void init() {
    this.addMouseListener(new MyMouseListener()); //To change body of generated methods, choose Tools | Templates.

    }
    
    public void paint(Graphics g){
        for(int i=0; i<20;i++){
                g.drawLine(lines[i][0], lines[i][1], lines[i][2], lines[i][3]); 
        }
    }
    
   class MyMouseListener implements MouseListener{

        @Override
        public void mouseClicked(MouseEvent e) {
          
        }

        @Override
        public void mousePressed(MouseEvent e) {
            System.out.println("Mouse clicked");
            x1=e.getX(); col++; lines[row][0] = x1;
            y1=e.getY(); col++; lines[row][1] = y1;
        }

        @Override
        public void mouseReleased(MouseEvent e) {
            x2=e.getX(); col++; lines[row][2] = x2;
            y2=e.getY(); col++;lines[row][3] = y2;
            repaint();
             row++; col=0;
        }

        @Override
        public void mouseEntered(MouseEvent e) {
        }

        @Override
        public void mouseExited(MouseEvent e) {
        }
       
       
   }
   


}

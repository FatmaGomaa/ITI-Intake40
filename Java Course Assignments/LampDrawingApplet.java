/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javaapplication31;

import java.applet.Applet;
import java.awt.Color;
import java.awt.Graphics;

/**
 *
 * @author FatmaGomaa
 */
public class NewApplet extends Applet {

    /**
     * Initialization method that will be called after the applet is loaded into
     * the browser.
     */
    public void init() {
        // TODO start asynchronous download of heavy resources
    }
    
    public void paint(Graphics g){
      g.drawOval(123, 68, 202, 52);
      g.drawLine(123, 90, 102, 173);
      g.drawLine(324, 90, 340, 173);
      g.drawArc(102, 120, 238, 100, 0, -180);
      g.drawLine(201, 220, 184, 275); 
      g.drawLine(240, 220, 260, 276);
      g.drawRect(140, 277, 171, 25);
      g.drawOval(190, 130, 60, 79);
      g.drawOval(130, 140, 40, 45);
      g.drawOval(280, 140, 40, 45);
      g.setColor(Color.red);
      g.fillOval(123, 68, 202, 52);
      g.fillOval(190, 130, 60, 79);
      g.fillOval(130, 140, 40, 45);
      g.fillOval(280, 140, 40, 45);
      
    }

    // TODO overwrite start(), stop() and destroy() methods
}

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javaapplication31;

import java.applet.Applet;
import java.awt.Font;
import java.awt.Graphics;
import java.awt.Toolkit;

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
    String[] s = Toolkit.getDefaultToolkit().getFontList();
    int x=30;
    
    for(String fontName : s){
    
    Font f = new Font(fontName,1,24);
    g.setFont(f);
    g.drawString(fontName,100,x);
    x+=30;
    }
    
    }
    // TODO overwrite start(), stop() and destroy() methods
}

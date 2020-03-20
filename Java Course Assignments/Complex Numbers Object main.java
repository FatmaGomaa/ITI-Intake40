/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javaapplication31;

/**
 *
 * @author FatmaGomaa
 */
public class Lab012_1 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Complex c1 = new Complex(4,5);
        Complex c2 = new Complex(1,2);
        Complex c3 = new Complex();
        
        c1.printComplex();
        c2.printComplex();
        c3.printComplex();
        
        c3 = c1.sumComplex(c2);
        c3.printComplex();
        
        c3 = c1.subComplex(c2);
        c3.printComplex();
    }
    
}

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
public class Complex {
    private float real, imag;
    public Complex(){
        real = imag = 0;
    }
    public Complex(float f){
        real = imag = f;      
    }
    public Complex(float r, float i){
        real = r; 
        imag = i;
    }
    public void setReal(float r){
        real =r;
    }
    public void setImag(float i){
        imag = i;
    }
    public float getReal(){
        return real;
    }
    public float getImag(){
        return imag;
    }
    public Complex sumComplex(Complex c){
        Complex temp = new Complex(); 
        temp.real = this.real + c.real;
        temp.imag = this.imag + c.imag;
        return temp;
    }
    public Complex subComplex(Complex c){
        Complex temp = new Complex(); 
        temp.real = this.real - c.real;
        temp.imag = this.imag - c.imag;
        return temp;
    }
    public void printComplex(){
        System.out.print("The complex number is: "+ real + " + " + "i" + imag + "\n");
    }
}

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<iostream.h>
#include<math.h>


class Complex{
  private:
  float real, imag;

  public:
  //constructors
  Complex();
  Complex(float f);
  Complex(float r, float i);
  //copy constructor
  Complex(Complex &c);
  //deconstructor
  ~Complex();
  //operator overloading
  Complex& operator=(Complex &c);
  Complex& operator++(); //prefix is the default
  Complex operator++(int dummy); //postfix
  operator float();
  friend istream& operator>> (istream &s, Complex &c);
  friend ostream& operator<< (ostream &s, Complex &c);
  //Complex Object Methods
  void setReal(float r);
  void setImag(float i);
  float getReal();
  float getImag();
  void print();
};


void main(void){
  clrscr();
  Complex c1(1,2),c2(10,20),c3;
  cout<<"c1 "; c1.print();
  cout<<"c2 "; c2.print();
  c3=c1++;
  cout<<"C3 = C1++  "; c3.print();
  c3=++c2;
  cout<<"C3 = ++C2  "; c3.print();

  cout<<"cin>>c3 "; cin>>c3;
  cout<<"cout<<c3 "; cout<<c3;

  cout<<"c3= (float)c2 "<<(float)c2<<endl;
  getch();
}

  //constructors
  Complex::Complex(){
	this->real=0; this->imag=0;
  }

  Complex::Complex(float f){
   this->real = this->imag = f;
  }

  Complex::Complex(float r, float i){
   this->real = r; this->imag =i;
  }
  //copy constructor
  Complex::Complex(Complex &c){
   this->real = c.real; this->imag = c.imag;
  }
  //deconstructor
  Complex::~Complex(){
  cout<<"Deconstruction\n";
  }
  //operator overloading
  Complex& Complex::operator=(Complex &c){
   this->real = c.real;
   this->imag = c.imag;
   return *this;
  }
  Complex& Complex:: operator++(){  //prefix
	 this->real ++;
	 this->imag ++;
	 return *this;
  }

  Complex Complex:: operator++(int dummy){ //postfix
	 Complex temp(*this); //calling copy constructor
	// temp.real = this->real;
	// temp.imag = this->imag;
	 this->real++; this->imag++;
	 return temp;
  }
  Complex::operator float(){
	return sqrt( real*real + imag*imag );
  }

  istream& operator>> (istream &s, Complex &c){
	cout<<"please enter the real part\n";
	s>>c.real;
	s>>c.imag;
	return s;
  }

  ostream& operator<< (ostream &s, Complex &c){
	s<<"the complex number is: ";
	s<<c.real << "+i" <<c.imag<<endl;
	return s;
  }

  //Complex Object Methods
  void Complex::setReal(float r){
	this->real = r;
  }
  void Complex::setImag(float i){
	this->imag = i;
  }
  float Complex::getReal(){
   return this->real;
  }
  float Complex::getImag(){
   return this->imag;
  }
  void Complex::print(){
   cout<<"the complex number is: "<<this->real<< "+" <<this->imag<< "i"<<endl;
  }
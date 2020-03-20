#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include <iostream.h>

class complex{
	private :
		float real,imag;

	public:

		complex(){
		 this->imag = this->real =0;
		 cout<<"Construction here\n";
		}

		complex(float real, float imag){
		   this->real = real;
		   this->imag = imag;
		   cout<<"Construction here\n";
		}
		complex(complex &c){ //copy constructor, it's argument is the orignial object
		  real = c.real;
		  imag = c.imag;
		  cout<<"ReConstruction here\n";
		}

		~complex(){
		printf("terminating, bye bye\n");
		}

		void setReal(float f);

		float getReal();

		void setImag(float f);

		float getImag();

		void print();

		complex& operator= (complex &c);
		int operator== (complex &c);
		complex operator+ (complex &c);

};
		complex complex:: operator+ (complex &c){
		 complex temp= complex(this->real + c.real , this->imag + c.imag);
		  return  temp;

		}

		int complex:: operator== (complex &c){
			if(this->real == c.real && this->imag == c.imag){
			   return 1;
			}
		  return 0;
		}

		complex& complex:: operator= (complex &c){
			this->real = c.real;
			this->imag = c.imag;
			return *this;
		}


		void complex::setReal(float f){
		   this->real = f;
		}
		float complex::getReal(){
		   return this->real;
		}

		void complex::setImag(float f){
		   this->imag = f;
		}

		float complex::getImag(){
		   return this->imag;
		}

		void complex::print(){
		if((this->imag) >1 && this->real ){
		 printf("complex number: %f + %fi\n",this->real,this->imag);
		 }else if((this->imag) <-1 && this->real){
		 printf("complex number: %f  %fi\n",this->real,this->imag);
		 }else if((this->imag) ==0 && this->real){
		 printf("complex number: %f\n",this->real);
		 }else if(this->real ==0 && (this->imag)){
		 printf("complex number: %fi\n",this->imag);
		 }else if(this->imag ==1 && (this->real)){
		 printf("complex number:%f + i\n",this->real);
		 }
		}

complex subComplex(complex c1,complex c2){
	complex temp;
	temp.setReal( c1.getReal() - c2.getReal()) ;
	temp.setImag( c1.getImag() - c2.getImag());
	if(temp.getImag()>=0){
		 printf("Sub: %f + %fi\n",temp.getReal(),temp.getImag());
	}else{
		 printf("Sub: %f  %fi\n",temp.getReal(),temp.getImag());
	}
	return temp;
}

complex sumComplex(complex c1,complex c2){
	complex temp;
	temp.setReal( c1.getReal() + c2.getReal() );
	temp.setImag( c1.getImag() + c2.getImag() );
	if(temp.getImag()>=0){
		 printf("Sum: %f + %fi\n",temp.getReal(),temp.getImag());
	}else{
		 printf("Sum: %f  %fi\n",temp.getReal(),temp.getImag());
	}
	return temp;
}

void main (void){
   complex c1,c2,c3;
   float temp;
   clrscr();
   cout<<"please enter first num real part";
   cin>>temp;
   c1.setReal(temp);
   cout<<"\nplease enter first num imag part";
   cin>>temp;
   c1.setImag(temp);
   cout<<"\nplease enter second num real part";
   cin>>temp;
   c2.setReal(temp);
   cout<<"\nplease enter first num imag part";
   cin>>temp;
   c2.setImag(temp);
   cout<<"\n";
   cout <<"C1  " ;
   c1.print();
   cout<< "C2  ";
   c2.print();
  // subComplex(c1,c2);
  // sumComplex(c1,c2);
   c3 = c1;
   cout<< "C3= C1   ";
   c3.print();
   c3= c1 + c2;
   cout<<"C3= C1+C2   ";
   c3.print();
   c3 = c2;
   cout<<"C3 = C2  ";
   if(c3 == c2){cout<<"Complex Numbers are equal\n";}
   getch();
}
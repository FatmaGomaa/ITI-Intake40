#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <iostream.h>
#include <graphics.h>
#include <dos.h>

typedef struct complex{

 float real;
 float imag;

}complex;

template <class T>

class Stack{
  private:
  int tos, size;
  T* stk;
  static int counter;

  public:
  Stack();
  Stack(int s);
  ~Stack();
   static int getcounter(){return counter;}

   Stack(Stack &s);
   Stack & operator= (Stack &s);
   int pop(T data);
   int push(T data);




};

template<class T>
Stack<T>::Stack(){
   tos =0; size = 10;
   stk = new T[size];
   counter++;
  }

template<class T>
Stack<T>::Stack(int s){
   tos =0; size = s;
   stk = new T[size];
   counter++;
  }

template<class T>
Stack<T>::~Stack(){
	if(stk) delete[]stk;
	counter--;
  }


template<class T>
Stack<T>::Stack(Stack<T> &s){
   tos = s.tos;
   size = s.size;
   stk = new T[size];
   for(int i=0;i<s.tos;i++){
	 stk[i] = s.stk[i];
   }

   }

   template <class T>
   Stack<T>& Stack<T>:: operator= (Stack<T> &s){
   if(stk) delete[]stk;
   tos = s.tos;
   size = s.size;
   stk = new T[size];
   for(int i=0;i<s.tos;i++){
	 stk[i] = s.stk[i];
   }
   return *this;
   }

  template <class T>
  int Stack<T>::pop(T data){
   if(tos == 0) return 0;
   tos--; data=stk[tos];
   return 1;
  }

   template <class T>
   int Stack<T>::push(T data){
   if(tos == size) return 0;
   stk[tos] = data; tos++;
   return 1;
  }

  template <class T>
  int Stack<T>::counter =0;

void main(){
clrscr();
 Stack<int> s1(5);
 cout<<s1.getcounter()<<endl;
 Stack<float> s2(12);
 cout<<s2.getcounter()<<endl;
 {
 Stack<int> s3(20);
 cout<<s3.getcounter()<<endl;
 }

 cout<<s2.getcounter()<<endl;
 cout<<s1.getcounter()<<endl;

 Stack<complex> s3,s4;
 cout<<s3.getcounter()<<endl;
 getch();
}
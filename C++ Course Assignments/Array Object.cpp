#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <iostream.h>

class myArray{
 private:
 int size;
 int *data;

 public:
 //constructors
 myArray(int s);

 //copy constructor
 myArray(myArray &arr);

 //deconstructor
 ~myArray();

 //operator overloading
 myArray& operator= (myArray &arr);
 int& operator[](int index);

 //Methods
 myArray& addElement(int index,int d);
 int getElement(int index);
 myArray& resize(int s);
 myArray& setArray();
 void printArray();
};



void main(void){
  clrscr();
  myArray m1(10), m2(5);
  m1.setArray();
  m2.setArray();
  cout<<"setting arr1 "<<endl; m1.printArray();
  cout<<"setting arr2 "<<endl; m2.printArray();
  m1.addElement(9,5);
  m2.addElement(2,10);
  cout<<"m1.addElement(9,5) "<<endl; m1.printArray();
  cout<<"m2.addElement(2,10) "<<endl; m2.printArray();
  cout<<"m1[9] "; cout<<m1[9]<<endl;
  cout<<"m2[2] "; cout<<m2[2]<<endl;
  cout<<"m1=m2 ";
  m1 = m2;
  cout<<endl<<"m1 "<<endl;m1.printArray();
  cout<<"m2 "<<endl;m2.printArray();

  m1.resize(1);
  cout<<"m1.resize(1) "<<endl;m1.printArray();

  getch();
}

 //constructors
 myArray::myArray(int s){
  size =s;
  data = new int[size];
 }

 //copy constructor
 myArray::myArray(myArray &arr){
  arr.size = size;
  arr.data = new int[size];
 }

 //deconstructor
 myArray::~myArray(){
  delete[]data;
 }

 //operator overloading
 myArray& myArray::operator= (myArray &arr){
	//myArray = temp;
	size = arr.size;
	delete[]data;
	data = new int[size];
	int i=0;
	for(i=0;i<size;i++){
	 this->data[i] = arr.data[i];
	}
   return *this;
 }

 int& myArray::operator[](int index){
   return data[index];
 }

 //Methods
 myArray& myArray::addElement(int index,int d){
  data[index] = d;
  return *this;
 }

 int myArray::getElement(int index){
  return data[index];
 }

 myArray& myArray::resize(int s){
 if(s<size){
   cout<< size-s<<" of your data will be deleted\n" ;
 }
   int* temp;
   temp= new int[s];
   int i=0;
   for(i=0;i<s;i++){
	 temp[i] = this->data[i];
   }
   delete[]this->data;
   size =s;
   data = temp;
   return *this;
 }

 myArray& myArray:: setArray(){
   int i=0;
   for(i=0;i<size;i++){
	data[i] = 1;
   }
   return *this;
 }

  void myArray:: printArray(){
   int i=0;
   for(i=0;i<size;i++){
	cout<<data[i]<<"\t";
   }
   cout<<"\n";
 }
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include <iostream.h>

class Stack{
  private:
	int tos,size;
	int *stk;
  static int counter;

  public:
	//Stack();
	Stack(int s);
	Stack(Stack &s);
	~Stack();
	int push(int data);
	int pop(int &data);
	int isEmpty();
	int isFull();
	int peak();
	void operator= (Stack &s);
	Stack operator+ (Stack &s);
	static int getCounter();
	friend void viewStack(Stack s);
};

int Stack::counter=0;
/*
Stack::Stack(){
	tos=0;size=10;
	stk = new int[size];
	if(stk) counter++;
}
*/
Stack::Stack(int s=10){
   tos=0; size=s;
   stk=new int[size];
   if(stk) counter++;
   cout<<"contruction done\n";
}

//copy constructor
Stack::Stack(Stack &s){
  this->tos = s.tos;
  this->size = s.size;
  this->stk = new int[size];
  int i=0;
  for(i=0;i<tos;i++){
   this->stk[i] = s.stk[i];
  }
 cout<<"reconstuction done\n";
}
void Stack:: operator= (Stack &s){
  this->tos = s.tos;
  this->size = s.size;
  delete[]stk;
  stk = new int[size];
  int i=0;
  for(i=0;i<tos;i++){
   this->stk[i] = s.stk[i];
  }
  //return *this;
}

Stack Stack:: operator+ (Stack &s){
  Stack temp;
  int i=0;
  temp.tos = this->tos + s.tos;
  temp.size = this->size + s.size;
  for(i=0;i<this->tos;i++){
   temp.stk[i] = this->stk[i];
  }
  for(i=0;i<s.tos;i++){
   temp.stk[this->tos + i] = s.stk[i];
  }
  return temp;
}

Stack::~Stack(){
	if(stk) delete[]stk;
	cout<<"Deconstruction done\n";
}
int Stack::push(int data){
	if(!isFull()){
	stk[tos] = data;
	tos++;
	return 1;
	}else{
	 return 0;
	}
}
int Stack::pop(int &data){
   if(!isEmpty()){
   tos--;
   data = stk[tos];
   return 1;
   }else{
	return 0;
   }
}
int Stack::isEmpty(){
   return !tos;

}
int Stack::isFull(){
   return tos == size;
}

int Stack::getCounter(){
	return counter;
}

void viewStack(Stack s){
  int i=0;
  cout<<"\nthe Data Stored in the Stack are\n";
  for(i=0;i<s.tos;i++){
   cout<<s.stk[i]<<"\t";
  }
}

int Stack::peak(){
 if(tos>=1){
 return stk[tos-1];
 }else{
  cout<<"there is no element in the stack\n";
 }
 return 0;
}


void main(void){
  clrscr();
  Stack s1(10),s2(10), s3;
  s1.push(1); s1.push(2);  s1.push(3); s1.push(4);
  s2.push(10); s2.push(20); s2.push(30); s2.push(40);
  int temp;
 /* cout<<"\nS1  ";
  viewStack(s1);
  cout<<"\n\nS2  ";
  viewStack(s2);
  *//*
  s3 = s1 + s2;
  cout << "\n\nS3 = S1 + S2  ";
  viewStack(s3);
  */
  s3 = s1;

  cout<<"\n\nS3 = S1  ";
  viewStack(s3);

  getch();
}
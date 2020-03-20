

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include <iostream.h>

class Stack{
private:
    int sizeOfStack, tos;
    int *stk;
    static int counter;
public:
    Stack();
    Stack(int s);
    Stack(Stack &s);
    ~Stack();
    int isFull();
    int isEmpty();
    int push(int data);
    int pop(int &data);
    static int getCounter();
    friend void viewContent(Stack s);
    Stack& operator = (Stack &s);
	Stack operator+ (Stack &s);
	int operator==(Stack &s);
};

int Stack::counter = 0;

Stack::Stack(){
    tos=0; sizeOfStack=10;
    stk = new int[sizeOfStack];
    counter++;
}

Stack::Stack(int s){
    tos=0; sizeOfStack = s;
    stk = new int[sizeOfStack];
    counter++;
}

Stack::Stack(Stack &s){
    this->sizeOfStack = s.sizeOfStack;
    this->tos = s.tos;
    this->stk = new int[this->sizeOfStack];
    for(int i=0;i<tos;i++){
        this->stk[i] = s.stk[i];
    }
}

Stack::~Stack(){
    if(stk) delete[]stk;
    counter--;
}

int Stack::isFull(){
    if(tos == sizeOfStack) return 1;
    return 0;
}

int Stack::isEmpty(){
    return !tos;
}

int Stack::push(int data){
    if(!isFull()){
    stk[tos] = data;
    tos++;
    return 1;
    }
return 0;
}

int Stack::pop(int &data){
    if(!isEmpty()){
        tos--;
        data = stk[tos];
        return 1;
    }
return 0;
}

int Stack::getCounter(){
    return counter;
}

void viewContent(Stack s){
    for(int i=0;i<s.tos;i++){
        cout<<"element number "<<i<<"is: "<<s.stk[i]<<endl;
    }

}

Stack& Stack::operator = (Stack &s){
    sizeOfStack = s.sizeOfStack;
    tos = s.tos;
    if(stk) delete[]stk;
    stk = new int[sizeOfStack];
    for(int i=0;i<tos;i++){
        stk[i] = s.stk[i];
    }
return *this;

}

Stack Stack::operator+ (Stack &s){
    Stack temp;
    temp.tos = s.tos + this->tos;
    temp.sizeOfStack = s.sizeOfStack + this->sizeOfStack;
    temp.stk = new int[temp.sizeOfStack];
    for(int i=0; i<this->tos;i++){
        temp.stk[i] = this->stk[i];
    }
	for(i=0; i<s.tos;i++){
        temp.stk[i + this->tos] = s.stk[i];
    }

return temp;
}

int Stack::operator==(Stack &s){
	if(tos == s.tos && sizeOfStack == s.sizeOfStack){
	   for(int i=0;i<tos;i++){
			if(stk[i] != s.stk[i]) return 0;
	   }
	  return 1;
	}
	 return 0;

}

void main()
{
clrscr();
	int temp;
    Stack s1(5);
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.push(5);
    s1.push(6);
    viewContent(s1);
    s1.pop(temp);
    s1.pop(temp);
    s1.pop(temp);
    viewContent(s1);
    viewContent(s1);

    Stack s2;
    s2 = s1;
    viewContent(s2);

    cout<<endl;
    Stack s3;
    s3 = s1 + s2;
    viewContent(s3);

	getch();
}



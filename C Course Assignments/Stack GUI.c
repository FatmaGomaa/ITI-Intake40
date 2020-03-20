#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

#define downArrow      		    80
#define upArrow        		    72
#define n   	    		     6
#define highlight    		  0x70
#define normal    		      0x07
#define numOfElementsInMenu		 4
#define elementsInStack			 5

char menu[numOfElementsInMenu][20] = {"push","pop","Display","Exit"};
char position =1,key,counter=0,numOfEmployees;
int dx = (80 - n)/(n+1);
int dy = (25 - n)/(n+1);


typedef struct stack{
 int size,tos;
 int *stk;
}stack;

stack mystack;

int initStack(stack *s,int size){
  if( ( s->stk = (int*)malloc(size*sizeof(int))) ){
	s->tos=0;
	s->size = size;
	return 1;
  }else{
   return 0;
  }
}

int isEmptyStack(stack *s){
 return (!(s->tos));
}

int isFullStack(stack *s){
 return ((s->tos == s->size));
}

int push(stack *s, int data){
  if(!isFullStack(s)){
	s->stk[s->tos] = data;
	s->tos++;
	return 1;
  }
  return 0;
}

int pop(stack *s, int* data){
  if(!isEmptyStack(s)){
	s->tos --;
	*data = s->stk[s->tos];
	return 1;
  }
  return 0;
}


void display(void){
   int  i =0;
   //position=1;
   clrscr();
   for(i=1;i<numOfElementsInMenu+1;i++){
   if(i==position){
   textattr(highlight);
   }
   cprintf(menu[i-1]);
   printf("\n");
   textattr(normal);
  }
}

void displayData(stack *s){
  int i= s->tos;
  clrscr();
  if (s->tos == 0) return;
  for(i;i>=1;i--){
	printf("%d \n",s->stk[i-1]);
  }
}

void main(void){
int data;
   initStack(&mystack,elementsInStack);
   clrscr();
   flushall();
   display();

while(!( (key==13) && (position==4) ) ){
  key = getch();
if(key == '\0'){
   key = getch();
  // printf("%d",key);
  switch(key){
	case 80:
	position++;
	if(position>4) position=1;
	display();
	break;

	case 72:
	position--;
	if(position<1) position =4;
	display();
	break;
  }
 }
  switch(key){
	case 13:
		if(position==1){
			clrscr();
			printf("please enter the integer you wanna push\n");
			scanf("%d",&data);
		   if(	push(&mystack,data) ){
			printf("successfully pushed\n");
		   }else{
		   printf("no place to push\n");
		   }
		   getch();
		   display();
		}else if (position==2){
			clrscr();
		   if(data=	pop(&mystack,&data) ){
			printf("successfully popped\n");
		   }else{
		   printf("empty stack\n");
		   }
		   getch();
		   display();
		}else if (position == 3) {
			clrscr();
			displayData(&mystack);
		   getch();
		   display();
		}else if(position==4){
		free(mystack.stk);
		break;
		}

	break;

  }
}
   getch();
}

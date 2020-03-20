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

char menu[numOfElementsInMenu][20] = {"Enqueue","Dequeue","Display","Exit"};
char position =1,key,counter=0,numOfEmployees;
int dx = (80 - n)/(n+1);
int dy = (25 - n)/(n+1);


typedef struct queue{
 int size,in;
 int *que;
}queue;

queue myqueue;

int initQueue(queue *q,int size){
  if( ( q->que = (int*)malloc( size*sizeof(int) ) ) ){
	q->in=0;
	q->size = size;
	return 1;
  }else{
   return 0;
  }
}

int isEmptyQueue(queue *q){
 return (!(q->in));
}

int isFullQueue(queue *q){
 return ((q->in == q->size));
}

int enqueue(queue *q, int data){
  if(!isFullQueue(q)){
	q->que[q->in] = data;
	q->in++;
	return 1;
  }
  return 0;
}

int dequeue(queue *q, int* data){
  int i=0;
  if(!isEmptyQueue(q)){
	q->in --;
	*data = q->que[0];
	for(i=0;i<q->in;i++){
	 q->que[i] = q->que[i+1];
	}
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

void displayData(queue *q){
  int i=0;
  clrscr();
  if (q->in == 0) return;
  for(i=0;i<q->in;i++){
	printf("%d \n",q->que[i]);
  }
}

void main(void){
int data;
   initQueue(&myqueue,elementsInStack);
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
			printf("please enter the integer you wanna add\n");
			scanf("%d",&data);
		   if(	enqueue(&myqueue,data) ){
			printf("successfully added\n");
		   }else{
		   printf("no place to add\n");
		   }
		   getch();
		   display();
		}else if (position==2){
			clrscr();
		   if(data=	dequeue(&myqueue,&data) ){
			printf("successfully removed\n");
		   }else{
		   printf("empty queue\n");
		   }
		   getch();
		   display();
		}else if (position == 3) {
			clrscr();
			displayData(&myqueue);
		   getch();
		   display();
		}else if(position==4){
		free(myqueue.que);
		break;
		}

	break;

  }
}
   getch();
}

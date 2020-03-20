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

typedef struct Node{
	int id;
   //	char name[20];
	struct Node *prev;
	struct Node *next;
}Node;

typedef struct linkedlist{
   struct Node *start;
   struct Node *end;
}linkedlist;

void linkedlistinit(linkedlist *l){
   l->start=NULL;
   l->end=NULL;
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



Node* createNode(void){
   return (Node*)malloc(sizeof(Node));
}

void addNode(linkedlist *l,Node* newele){
clrscr();
	if(newele){ //checks that it's not NULL
		counter++;
		if(l->start == NULL){
			l->start = newele;
			l->end = newele;
			newele->prev = NULL;
			newele->next = NULL;

		}else{
		   l->end->next = newele;
		   newele->prev = l->end;
		   newele->next = NULL;
		   l->end = newele;
		}
	   printf("please enter employee's ID\n");
	   scanf("%d",&newele->id);
	   flushall();
	  /* printf("please enter employee's Name\n");
	   gets(newele->name);*/

	}else{
	printf("Node wasn't created\n");
	}

 getch();
 display();
}

void displayData(linkedlist *l){
  int i=0;
  Node *temp;
  temp = l->end;
  clrscr();
  for(i=counter;i>0;i--){
   //	gotoxy((i+1)*dx,1*dy);
	printf("%d \n",temp->id);

  //	gotoxy((i+1)*dx,2*dy);
   //	printf("%s \n",temp->name);

	temp = temp->prev;
  }
  getch();
  display();
}

Node* searchNode(linkedlist *l, int key){
  Node* temp = l->start;
  while(temp && (temp->id != key) ){
	  temp = temp->next;
  }
	return temp;
}

void freelist (linkedlist* l){
	Node *temp = l-> start;
	while(l->start){
	 l->start = temp->next;
	 free(temp);
	 temp= l->start;
	}
	l->end = NULL;
}

void insertNode(linkedlist* l, Node* newele, int key){
  Node * temp =l-> start;
  clrscr();
	if(newele){ //checks that it's not NULL
	 // counter++;
	  /* if(l->start==NULL){ //no element in array add new one
		 addNode(l,newele);
	   }*/
	   while(temp && (temp->id != key) ){
		 temp = temp->next;
	   }
	   //if reached the last element or doesn't found the key
	  if(!temp){ //this in case there is no lement, or found it in first element or last element
	   addNode(l,newele);
	   //if it's the first element
	  }else if(counter>=2){
	   counter++;
	   printf("please enter employee's ID\n");
	   scanf("%d",&newele->id);
	   flushall();
	  /* printf("please enter employee's Name\n");
	   gets(newele->name);*/
			temp->next->prev = newele;
			newele->next=temp->next;
			newele->prev=temp;
			temp->next= newele;
	   }else if( key != temp->id){
		l->start->next = newele;
		newele->prev = l->start;
		l->end = newele;
		newele->next = NULL;
	   counter++;
	   printf("please enter employee's ID\n");
	   scanf("%d",&newele->id);
	   flushall();
	   /*printf("please enter employee's Name\n");
	   gets(newele->name);*/
	   }else if (key == temp->id){ //if the node is in the middle
	   counter++;
	   printf("please enter employee's ID\n");
	   scanf("%d",&newele->id);
	   flushall();
	  /* printf("please enter employee's Name\n");
	   gets(newele->name);*/
			temp->next->prev = newele;
			newele->next=temp->next;
			newele->prev=temp;
			temp->next= newele;
	   }

	}else{
	printf("Node wasn't created\n");
	}
 getch();
 display();
}


int deleteNode(linkedlist *l,int key){
 Node * temp;
 temp = searchNode(l,key);
 if(!temp) return 0;
 else{
 counter--;
 if(l->start == temp && l->start == l->end){
   l->start=l->end=NULL;
   free(temp);
 }else if(l->start == temp){
   l->start = l->start->next;
   l->start->prev = NULL;
   free(temp);
 }else if(l->end == temp){
   l->end = l->end->prev;
   l->end->next = NULL;
   free(temp);
 }else{
  temp->prev->next = temp->next;
  temp->next->prev = temp->prev;
  free(temp);
 }
 return 1;
 }
}

typedef struct stack{
 int size,tos;
 struct Node *stk;
}stack;

stack mystack;

int initStack(stack *s){
 // if( ( s->stk = (int*)malloc(size*sizeof(int))) ){
	s->tos=counter;
	s->size = counter;
	return 1;
}

int isEmptyStack(stack *s){
 return (!(s->tos));
}

int isFullStack(){
 return 0;
 //((s->tos == s->size));
}

int push(stack *s,linkedlist *l){
  if(!isFullStack()){
	addNode(l,createNode());
	//s->stk[s->tos] = data;
	s->tos=counter;
	return 1;
  }
  return 0;
}

int pop(stack *s,linkedlist *l){
  if(!isEmptyStack(s)){
	s->tos --;
	//counter--;
	deleteNode(l,l->end->id);
	//data->id = s->stk[s->tos];
	return 1;
  }
  return 0;
}


void main(void){
Node data;
 linkedlist emp;
 linkedlistinit(&emp);
   initStack(&mystack);
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
		   //	printf("please enter the integer you wanna push\n");
		   //	scanf("%d",&data);
		   if(	push(&mystack,&emp) ){
			printf("successfully enqueued\n");
		   }else{
		   printf("no place to enqueue\n");
		   }
		   getch();
		   display();
		}else if (position==2){
			clrscr();
		   if(pop(&mystack,&emp) ){
			printf("successfully dequeued\n");
		   }else{
		   printf("empty queue\n");
		   }
		   getch();
		   display();
		}else if (position == 3) {
			clrscr();
			displayData(&emp);
		   getch();
		   display();
		}else if(position==4){
		free(mystack.stk);
		freelist(&emp);
		break;
		}

	break;

  }
}
   getch();
}

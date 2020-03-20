#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

#define downArrow      		    80
#define upArrow        		    72
#define n   	    		     6
#define highlight    		  0x70
#define normal    		      0x07
#define numOfElementsInMenu		 6
//#define numOfEmployees       	 3

char menu[numOfElementsInMenu][20] = {"Name","Adress","Phone","Back","Display","Exit"};
char position =1,location=0,key,counter=0,empID=0,found=0,empID2=0,efound=0,dfound=0,numOfEmployees;
int dx = (80 - n)/(n+1);
int dy = (25 - n)/(n+1);

struct employee{
 char name[20];
 char address[30];
 long long phone;
};
struct employee *emp;

void display(int loc);
void newLoc(void);
void displayData();

void fillData(){
  clrscr();

  switch(position){
   case 1:
   //	counter++;
	gets(emp[location-1].name);
   break;

   case 2:
   gets(emp[location-1].address);
   break;

   case 3:
   scanf("%lld",&emp[location-1].phone);
   break;


  }

	display(location);
}

void display(int loc){
   int  i =0;
  // char key;
   clrscr();
   for(i=1;i<numOfElementsInMenu+1;i++){
   if(i==position){
   textattr(highlight);
   }
   cprintf(menu[i-1]);
   printf("\n");
   textattr(normal);
  }
  while(!( (key==13) && (position==6) ) ){
  key = getch();
  if(key == '\0'){
   key = getch();
  // printf("%d",key);
  switch(key){
	case 80:
	position++;
	if(position>6) position=1;
	display(loc);
	break;

	case 72:
	position--;
	if(position<1) position =6;
	display(loc);
	break;
  }
 }
  switch(key){
	case 13:
		if(position==1){
			fillData();
		}else if (position==2){
			fillData();
		}else if (position == 3) {
			fillData();
		}else if (position == 4){
			location=0;
			position=1;
			newLoc();
		// editSpecificID();
		}
		else if(position==5){
			displayData();
		}else if(position==6){
		break;
		}

	break;

  }
}
// position=1;
}

void newLoc(void){
 clrscr();
 printf("Please enter the Location to save the new employee in\n");
 scanf("%d",&location);
 while(location>numOfEmployees){
 printf("denied Location out of range\nplease re-enter location");
 scanf("%d",&location);
 }
 display(location);
}


void displayData(void){
  int i=0;
	 clrscr();
  for(i=0;i<numOfEmployees;i++){
	gotoxy((i+1)*dx,1*dy);
	printf("%s \n",emp[i].name);

	gotoxy((i+1)*dx,2*dy);
	printf("%s \n",emp[i].address);

	gotoxy((i+1)*dx,3*dy);
	printf("%lld \n",emp[i].phone);
  }
  getch();
  display(location);
}


void main(void){
 //int i=0;
 clrscr();
	/*Allocate Dynamic Memory*/
 printf("please enter the number of employees to allocate\n");
 scanf("%d",&numOfEmployees);
 emp= (struct employee*)calloc(numOfEmployees,sizeof(struct employee));
	/*Get the Location to write in*/
	newLoc();

// getch();

}

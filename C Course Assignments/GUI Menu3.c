#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

#define downArrow      		    80
#define upArrow        		    72
#define n   	    		     3
#define highlight    		  0x70
#define normal    		      0x07
#define numOfElementsInMenu		 5
#define numOfEmployees       	 3

char menu[numOfElementsInMenu][20] = {"New","Display All","Display by ID","Edit by ID","Exit"};
char position =1,counter=0,empID=0,found=0,empID2=0,efound=0,dfound=0;
int dx = (80 - n)/(n+1);
int dy = (25 - n)/(n+1);

struct employee{
 char name[20];
 int id;
 int age;
}emp[numOfEmployees];

void display(void){
   int  i =0;
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

void newEmp(void){
 int i=0;
 int buffer=0;
  clrscr();
  if(counter<numOfEmployees){
  printf("please enter the employee's following data\n Name \t ID \t Age \n");
  flushall();
  gets(emp[counter].name);

  //emp[counter].id = counter+1;  //for automatic generation of ID
   printf("please enter the ID \n");
   //scanf("%d",&emp[counter].id);
  do{
  dfound=0;
  scanf("%d",&buffer);
  for(i=0;i<counter;i++){
   if(emp[i].id==buffer){

	dfound =1;
	break;
	 }
  }
  if(dfound==1){
	printf("duplicate ID\n");
  }else{
   dfound=0;
   emp[counter].id=buffer;
  }

  }while(dfound==1);
  dfound=0;
  printf("please enter Age \n");
  scanf("%d",&emp[counter].age);
  counter++;
  }else{
  printf("all employees are entered.\n Thank you.\n");
  }
  getch();
  display();
}

void displayData(){
  int i=0;
  clrscr();
  for(i=0;i<n;i++){
	gotoxy((i+1)*dx,1*dy);
	printf("%s \n",emp[i].name);

	gotoxy((i+1)*dx,2*dy);
	printf("%d \n",emp[i].id);

	gotoxy((i+1)*dx,3*dy);
	printf("%d \n",emp[i].age);
  }
  getch();
  display();

}

void displaySpecificData(void){
  int i=0;
  clrscr();
  printf("please enter the employee's ID\n");
  scanf("%d",&empID);
  for(i=0;i<numOfEmployees;i++){
	if(emp[i].id == empID){
	   found = 1;

	gotoxy(1*dx,1*dy);
	printf("%s \n",emp[i].name);

	gotoxy(1*dx,2*dy);
	printf("%d \n",emp[i].id);

	gotoxy(1*dx,3*dy);
	printf("%d \n",emp[i].age);

	   //found=0;
	   break;
	}
  }
  if(found==1){
   found =0;
  }else{
   found =0;
   printf("No employee found!\n");
  }
  getch();
  display();
}


void editSpecificID(void){
  int i=0;
  clrscr();
  printf("please enter the employee's ID\n");
  scanf("%d",&empID2);
  for(i=0;i<numOfEmployees;i++){
	if(emp[i].id == empID2){
	  efound = 1;
  printf("please enter the employee's following data\n Name \t ID \t Age \n");
  flushall();
  gets(emp[i].name);
  scanf("%d",&emp[i].id);
  //emp[counter].id = counter+1;
  scanf("%d",&emp[i].age);
	   //found=0;
	   break;
	}
  }
  if(efound==1){
   efound =0;
  }else{
   efound =0;
   printf("No employee found!\n");
  }
  getch();
  display();
}

void main(void){
  char key;
  clrscr();
  display();

  while(!( (key==13) && (position==5) ) ){
  key = getch();
  if(key == '\0'){
   key = getch();
  // printf("%d",key);
  }
  switch(key){
	case 13:
		if(position==1){
			newEmp();
		}else if (position==2){
			displayData();
		}else if (position == 3) {
			displaySpecificData();
		}else if (position == 4){
		 editSpecificID();
		}
		else if(position==5){
		 break;
		}

	break;

	case 80:
	position++;
	if(position>5) position=1;
	display();
	break;

	case 72:
	position--;
	if(position<1) position =5;
	display();
	break;

  }

  }

// getch();


}

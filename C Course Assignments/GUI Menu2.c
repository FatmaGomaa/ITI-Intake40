#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

#define downArrow       80
#define upArrow         72
#define n   	         3
#define highlight     0x70
#define normal        0x07

char menu[3][10] = {"New","Display","Exit"};
char position =1,counter=0;
int dx = (80 - n)/(n+1);
int dy = (25 - n)/(n+1);

struct employee{
 char name[20];
 int id;
 int age;
}emp[3];

void display(void){
   int  i =0;
   clrscr();
   for(i=1;i<4;i++){
   if(i==position){
   textattr(highlight);
   }
   cprintf(menu[i-1]);
   printf("\n");
   textattr(normal);
  }
}

void newEmp(void){
  clrscr();
  if(counter<3){
  printf("please enter the employee's following data\n Name \t ID \t Age \n");
  flushall();
  gets(emp[counter].name);
  scanf("%d",&emp[counter].id);
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

void main(void){
  char key;
  clrscr();
  display();

  while(!( (key==13) && (position==3) ) ){
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
		}else if(position==3){
		 break;
		}

	break;

	case 80:
	position++;
	if(position>3) position=1;
	display();
	break;

	case 72:
	position--;
	if(position<1) position =3;
	display();
	break;

  }

  }

// getch();


}

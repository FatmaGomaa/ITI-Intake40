#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

#define downArrow 80
#define upArrow   72
#define n   	   3

int dx = (80 - n)/(n+1);
int dy = (25 - n)/(n+1);

void mainWindowDisplay(int position){

  int col=1, row=position;
  clrscr();
  gotoxy(col*dx, row*dy);
  printf("->");

  gotoxy(2*dx, 1*dy);
  printf("Name");

  gotoxy(2*dx, 2*dy);
  printf("Age");

  gotoxy(2*dx, 3*dy);
  printf("Exit\n");

  gotoxy(1*dx, 1*dy);

}

void getName(){
 char name[10];
 clrscr();
 printf("Please enter your name\n");
 scanf("%s",&name);
 mainWindowDisplay(1);
// gotoxy(3*dx,1*dy);
// printf("%s",name);
 gotoxy(1*dx,1*dy);
}

void getAge(){
 char age;
 clrscr();
 printf("Please enter your age\n");
 scanf("%d",&age);
 mainWindowDisplay(2);
// gotoxy(3*dx,2*dy);
// printf("%d",age);
 gotoxy(1*dx,2*dy);
}

void main(void){
  char key,position=1;
  clrscr();
  mainWindowDisplay(position);
  while(!( (key==13) && (position==3) ) ){
  key = getch();
  if(key == '\0'){
   key = getch();
  // printf("%d",key);
  }
  switch(key){
	case 13:
		if(position==1){
		 getName();
		}else if (position==2){
		 getAge();
		}else if(position==3){
		 break;
		}

	break;

	case 80:
	position++;
	if(position>=n) position=n;
	mainWindowDisplay(position);
	gotoxy(1*dx, (position)*dy);
	printf("->");
	break;

	case 72:
	position--;
	if(position<1) position =1;
	mainWindowDisplay(position);
	gotoxy(1*dx, (position)*dy);
	printf("->");
	break;

  }

  }

//  getch();


}

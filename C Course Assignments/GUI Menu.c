#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

#define downArrow       80
#define upArrow         72
#define n   	         3
#define highlight     0x70
#define normal        0x07

char menu[3][10] = {"New","Display","Exit"};
char position =1;
int dx = (80 - n)/(n+1);
int dy = (25 - n)/(n+1);

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
		 clrscr();
		 printf("new window created\n");
		 getch();
		 display();
		}else if (position==2){
		 clrscr();
		 printf("another window created\n");
		 getch();
		 display();
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

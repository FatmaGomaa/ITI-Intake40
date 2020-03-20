#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

 #define home    71
 #define end     79
 #define right	 77
 #define left 	 75
 #define esc     27
 #define enter   13
 #define n		  5

 int dx = (80 - n)/(n+1);
 int dy = (25 - n)/(n+1);
 char arr[n]={0},*ptr=arr,position=0,counter=0;

void fillArray(char k){
   if(counter<n){
   arr[counter] =k;
   gotoxy(3*dx+counter,3*dy);
   printf("%c",k);
   counter++;
  }else{
  printf("\nLimit reached\n");
  }
 }

void printArray(char* arrPtr){
  int i=0;
  gotoxy(1,1);
  for(i=0;i<counter;i++){
	printf("%c",*(arrPtr+i));
  }
  gotoxy(3*dx+counter,3*dy);
}

void main(void){
 char key;
 clrscr();
 gotoxy(3*dx,3*dy);
do{
 key = getch();
 if(key == '\0'){
  key = getch();
   switch(key){
   case left :
	position = counter;
	position--;
   break;

   case right:

   break;

   case home:
   gotoxy(1*dx,1*dy);
   break;

   case end:

   break;
  }

 }else{
	switch(key){
	 case esc:
	 break;

	 case enter:
	 printArray(ptr);
	 break;

	 default:
	 fillArray(key);
	 break;

	}
  }
}while(key!=esc);


 getch();

}

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include <string.h>

void main(void){

 char name[2][10];
 char buffer[250];

 clrscr();
 printf("please enter the first name\n");
 gets(buffer);
 if(strlen(buffer)>9){
 printf("you exceeded the aallowed size\n");
 }else{
 strcpy(name[0],buffer);
 printf("please enter the second name\n");
 gets(buffer);
 if(strlen(buffer)>9){
 printf("you exceeded the aallowed size\n");
 }else{
 strcpy(name[1],buffer);
  printf("you name is %s %s",name[0],name[1]);
 }
 }

 getch();
}
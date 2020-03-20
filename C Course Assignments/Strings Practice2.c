#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include <string.h>

void main(void){
 char name[30],buffer[250];
 clrscr();
 printf("pleas enter your name within the range of 30 characters\n");
 gets(buffer);
 if(strlen(buffer)>29){
 printf("you exceeded the allowed storage\n");
 }else{
  strcpy(name,buffer);
  printf("your name is %s\n",name);
 }
 getch();
}

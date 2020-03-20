#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

void main(void){
 char **ptr;
 int n1,n2,i;
 char buffer1[250],buffer2[250];
 clrscr();
 ptr=(char**)malloc(2*sizeof(char*));
 printf("Please enter the first Array Size\n");
 scanf("%d",&n1);
 //n1=getch();
 ptr[0]=(char*)malloc(n1*sizeof(char));
 printf("Please enter the second Array Size\n");
 scanf("%d",&n2);
 //n2=getch();
 ptr[1]=(char*)malloc(n2*sizeof(char));
 printf("now please fill the arrays you created\n");
 flushall();
 gets(buffer1);
 if(strlen(buffer1)>n1){
 do{
 printf("limit exceeded\nplease enter another value\n");
 gets(buffer1);
 }while(strlen(buffer1)>n1);
 }
 strcpy(ptr[0],buffer1);
 flushall();
 gets(buffer2);
 if(strlen(buffer2)>n2){
 do{
 printf("limit exceeded\nplease enter another value\n");
 gets(buffer2);
 }while(strlen(buffer2)>n2);
 }
 strcpy(ptr[1],buffer2);
 gotoxy(30,20);
 printf("the Values you entered are\n");
 for(i=0;i<n1;i++){
 printf("%c",ptr[0][i]);
 }
 printf("\n");
  for(i=0;i<n2;i++){
 printf("%c",ptr[1][i]);
 }
 getch();
}

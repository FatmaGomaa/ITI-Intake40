#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define arrSize 15
#define structNum  5

struct employee{
 int id;
 char name[20];
 float salary;
 };

struct employee emp[structNum]={ {10,"Amira",2000},{25,"Eman",2300},{33,"Fatma",1800},{40,"Gomaa",1700},{54,"Kamal",2500} };
struct employee *ptr = &emp[0];
int number=0,choices;
char tname[20];

void seqSearch(int size,struct employee * sptr){
  int i=0,flag=0;
 if(choices==1){
  for(i=0;i<size;i++){
	if(sptr[i].id==number){
	 printf("it's element number %d\n",i+1);
	 flag=1;
	}
  }

 if(flag==1){
   flag=0;
 }else{
  printf("couldn't find your element\n");
 }

}else if(choices==2){

   for(i=0;i<size;i++){
	if(!strcmp(tname,sptr[i].name)){
	 printf("it's element number %d\n",i+1);
	 flag=1;
	}
  }

 if(flag==1){
   flag=0;
 }else{
  printf("couldn't find your element\n");
 }

}


}

void main(void){
  int i=0;
  clrscr();

  printf("Employees' Data \n");
  for(i=0;i<structNum;i++){
  printf("%d\t%s\t%f\n",emp[i].id,emp[i].name,emp[i].salary);
  }
  printf("please choose what you're searching with 1- id  2-name\n");
  scanf("%d",&choices);
  if(choices==1){
  printf("please enter the id you're searching for\n");
  scanf("%d",&number);
  }else if(choices==2){
  printf("please enter the name you're searching for\n");
  scanf("%s",tname);
  }

  seqSearch(structNum,ptr);
  getch();
}

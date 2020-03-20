#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
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

void binarySearch(int size,struct employee * sptr){
  int low,high,mid,i,flag=0;
  low =0;
  high = size -1;
if(choices==1){
while(high>=low){
  mid = (low+high)/2;
  if(number == sptr[mid].id){
   printf("the number you're searching for exisits in location number %d",mid);
   flag=1;
   return;
  }else if(number>sptr[mid].id){
   low = mid+1;
  }else{
	high = mid-1;
  }
}

 if(flag==1){
   flag=0;
 }else{
  printf("couldn't find your element\n");
 }

}else if(choices ==2){

while(high>=low){
  mid = (low+high)/2;
  if((int)tname[0] ==(int) sptr[mid].name[0]){
  if(!strcmp(tname,sptr[mid].name)){
   printf("the number you're searching for exisits in location number %d",mid);
   flag=1;
   }
   return;
  }else if(tname[0] > sptr[mid].name[0]){
   low = mid+1;
  }else{
	high = mid-1;
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

  binarySearch(structNum,ptr);

 getch();
}

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct employee{
 int id;
 char name[20];
 float salary;
 };

struct employee emp[5]={ {85,"Amira",2000},{25,"Eman",2300},{33,"Fatma",1800},{102,"Gomaa",1700},{54,"Kamal",2500} };
struct employee *ptr = &emp[0];
struct employee temp;

void bubbleSort(struct employee *sptr,int size){
   int i,j,sorted=0;
   for(i=0;(i<size-1)&& !sorted ;i++){
	  sorted=1;
	  for(j=size-1;j>i;j--){
		 if(sptr[j].id<sptr[j-1].id){
		   temp.id=sptr[j].id; temp.salary=sptr[j].salary; strcpy(temp.name,sptr[j].name);
		  // sptr[j]=sptr[j-1];
		   sptr[j].id=sptr[j-1].id; sptr[j].salary=sptr[j-1].salary; strcpy(sptr[j].name,sptr[j-1].name);
		  // sptr[j-1]=temp;
		   sptr[j-1].id=temp.id; sptr[j-1].salary=temp.salary; strcpy(sptr[j-1].name,temp.name);
		   sorted=0;
		 }
	  }

   }


}

void main(void){
int i=0;
  clrscr();
  printf("Employees' Data before sorting \n");
  for(i=0;i<5;i++){
  printf("%d\t%s\t%f\n",emp[i].id,emp[i].name,emp[i].salary);
  }
 bubbleSort(ptr,5);
  printf("Employees' Data after sorting \n");
  for(i=0;i<5;i++){
  printf("%d\t%s\t%f\n",emp[i].id,emp[i].name,emp[i].salary);
  }

getch();
}

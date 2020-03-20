#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define arrSize 6
int choice =0;

void selecSorting(int *aptr,char sptr[6][20],int size){
   int i=0,j=0,index,min,temp;
   char min2[20],temp2[20];
   if(choice==1){
	 for(i=0;i<size-1;i++){
	  min= aptr[i];
	  index=i;
		 for(j=i+1;j<size;j++){
		  if(aptr[j]<min){
		   min=aptr[j];
		   index=j;
		  }
	  }
		  temp= aptr[i];
		  aptr[i] = aptr[index];
		  aptr[index] = temp;

	 }
   }else if(choice ==2){
   for(i=0;i<size-1;i++){
	 strcpy(min2,sptr[i]);
	  index=i;
		 for(j=i+1;j<size;j++){
		  if(strcmp(min2,sptr[j])>0 ){
		  strcpy(min2,(sptr[j]));
		   index=j;
		  }
	  }
		  strcpy(temp2,sptr[i]);
		  strcpy(sptr[i],sptr[index]);
		  strcpy(sptr[index],temp2);

	 }
   }
}

void main(void){
 int arr1[arrSize]= {20,43,98,43,65,32},i=0;
 char arr2[arrSize][20] = {"Aly","Amira","Ola","Malek","May","Hesham"};
// char *ptr=(char *)arr2;
  clrscr();
  printf("please choose what you're searching with 1- id  2-name\n");
  scanf("%d",&choice);
 if(choice==1){
  printf("Array before Sorting:\n");
  for(i=0;i<arrSize;i++){
   printf("%d \t",arr1[i]);
  }
 selecSorting(arr1,arr2,arrSize);
 printf("\nArray after Sorting:\n");
  for(i=0;i<arrSize;i++){
   printf("%d \t",arr1[i]);
  }
}else if(choice==2){
   printf("Array before Sorting:\n");
  for(i=0;i<arrSize;i++){
   printf("%s \t",arr2[i]);
  }
 selecSorting(arr1,arr2,arrSize);
 printf("\n \n Array after Sorting:\n");
  for(i=0;i<arrSize;i++){
   printf("%s \t",arr2[i]);
  }


}
 getch();



}
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define arrSize 15

void seqSearch(int size, int array[], int num){
  int i=0,flag=0;
  for(i=0;i<size;i++){
	if(array[i]==num){
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

void main(void){

  int arr[arrSize]={0},i=0,number=0;
   clrscr();
  printf("please fill an array of Size 15\n");
  for(i=0;i<arrSize;i++){
  scanf("%d",&arr[i]);
  }
  printf("please enter the element you're searching for\n");
  scanf("%d",&number);

  seqSearch(arrSize,arr,number);
  getch();
}

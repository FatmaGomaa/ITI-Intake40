#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

#define ArrayCol 3
#define ArrayRow 3
#define n   	 4

int dx = (80 - n)/(n+1);
int dy = (25 - n)/(n+1);
long array[ArrayCol][ArrayRow]={0};

void getArray(int Col,int Row){
  int i=0,j=0;
  printf("please enter the array\n");
  for(i=0;i<Col;i++){
	for(j=0;j<Row;j++){
   //	scanf("%ld",&array[i][j]);
	while(!(scanf("%4d",&array[i][j]))){
	flushall();
	printf("please enter number within the range\n");
	scanf("%ld",&array[i][j]);
	}

   }
  }
}
/*
void printArray(int Col,int Row,long arr[][])
{
  int i=0,j=0;
  for(i=1;i<Col+1;i++){
  for(j=1;j<Row+1;j++){
  gotoxy(i*dx, j*dy);
  printf("%ld",arr[i-1][j-1]);
  }
  }
}
*/
/*
void getSum(long arr[][]){
  int i=0,j=0;
  long sum=0;
  for(i=1;i<ArrayCol+1;i++){
  for(j=1;j<ArrayRow+1;j++){
  sum += arr[i][j];
  gotoxy(n*dx, i*dy);
  printf("%ld",arr[i-1][j-1]);
  }
  }
}
*/
/*
void getMin(int size, long arr[]){
  int i=0;
  long min=0;
  for(i=0;i<size-1;i++){
	if(arr[i]<arr[i+1]){
	  min=arr[i];
	}else{
	min = arr[i+1];
	}
  }
 // gotoxy(3*dx, 1*dy);
  printf("the min of the Array is %ld\n",min);

}
*/

void main(void){
  int i=0,j=0;
  long sum=0;
  float avg=0;

  clrscr();
  getArray(ArrayCol,ArrayRow);
  clrscr();
  //print
  for(i=1;i<ArrayCol+1;i++){
  for(j=1;j<ArrayRow+1;j++){
  gotoxy(j*dx, i*dy);
  printf("%ld",array[i-1][j-1]);
  }
  }
  //sum
  for(i=1;i<ArrayCol+1;i++){
  for(j=1;j<ArrayRow+1;j++){
  sum += array[i-1][j-1];
  gotoxy(n*dx, i*dy);
  printf("%ld",sum);
  }
  }
  //avg

  for(j=1;j<ArrayCol+1;j++){
	sum=0;
  for(i=1;i<ArrayRow+1;i++){
  sum += array[i-1][j-1];
  }
  avg = sum /(3.0);
  gotoxy(j*dx, n*dy);
  printf("%f",avg);
  }
  //printArray(ArrayCol,ArrayRow,array);
  //getMax(ArrayCol,array);
  //getMin(ArrayCol,array);

  getch();
}

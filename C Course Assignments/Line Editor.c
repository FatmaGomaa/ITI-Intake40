
 #include <stdio.h>
 #include <stdlib.h>
 #include <conio.h>

 #define home    71
 #define end     79
 #define right	 77
 #define left 	 75
 #define esc     27
 #define enter   13
 #define n		  5

 int dx = (80 - n)/(n+1);
 int dy = (25 - n)/(n+1);
 char arr[n]={0},*ptr=arr,position=0,bufferPosition=1,lastPosition=1,counter=0;

void lineEditor(char k){

if(position==counter){
 if(counter<n){

  arr[counter]=k;    //I replaced counter with position
  counter++;
  gotoxy((counter)*dx,1*dy);
  printf("%c",k);
  position=counter;
 // lastPosition = position;
 }else if(position==n){
  arr[position-1]=k;
  gotoxy(position*dx,1*dy);
  printf("%c",arr[position-1]);
 } else{
  printf("\n Array Fully filled\n");
  gotoxy(counter*dx,1*dy);
 }
}else{
  arr[position-1]=k;
  gotoxy((position)*dx,1*dy);
  printf("%c",arr[position-1]);
}
}
 void printArray(void){
 int i=0;
 clrscr();
  for(i=0;i<n;i++){
	printf("%c \t",arr[i]);
  }
 getch();
 return;
 }

 void main(void){
 char key;
 clrscr();
 gotoxy(1*dx,1*dy);
 do{
 key= getch();
 if(key=='\0'){
   key=getch();

   switch(key){
   case left :
	//printf("left detected\n");
	position--;

	//bufferPosition= lastPosition-1;
	//lastPosition--;
	if(position < 1)  position=1;
	gotoxy((position)*dx,1*dy);

   break;

   case right:
	position++;
	if(position > n)  position=n;
	gotoxy(position*dx,1*dy);

   /*	bufferPosition= position+1;
	if(bufferPosition >n+1)  bufferPosition=n;
	gotoxy(bufferPosition*dx,1*dy);
	*/
   break;

   case home:
   gotoxy(1*dx,1*dy);
   break;

   case end:
   gotoxy((counter)*dx,1*dy);
   break;
  }

 }else{
  if( (key != esc)&&(key != enter)){
  lineEditor(key);
  }else if (key == enter){
	printArray();
  }
 }
 }while(key!=esc);

 getch();


 }
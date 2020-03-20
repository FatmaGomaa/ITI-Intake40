#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <iostream.h>
#define highlight    		  0x70
#define normal    		      0x07

class String{
  private:
	int size;
	char *str;

  public:
	//constructor
	String(char *s);

	//copy constructor
	String(String &s);

	//destructor
   ~String();

	//operators overloading
	String & operator= (String &s);
	String operator+ (String& s2);
	String& operator += (String& s2);
	friend ostream& operator<< (ostream& out, String &s);

	//behavior of string class
	char charAt(int index);
	int indexOf(char ch);
	int indexOf(int start, char ch);
	String subString(int start);
	String subString(int start, int end);
	String concat(String s2);
	static String uperCase(String &s);
	static String lowerCase(String &s);

};

void main(void){
   clrscr();
   String s1("Hello");
   String s2("World");
   String s3(" ");
   String s4("My name is");
   String s5("Fatma");
   textattr(highlight);
   cprintf("the created five strings are:");
   textattr(normal);
   cout<<endl<<s1;
   cout<<s2;
   cout<<s3;
   cout<<s4;
   cout<<s5;

   s2 = s1;
   textattr(highlight);
   cprintf("S2 = S1");
   textattr(normal);
   cout<<"\ns1 "<<s1;
   cout<<"s2 "<<s2;

   s3 = s1+s2;
   textattr(highlight);
   cprintf("s3 = s1+s2");
   textattr(normal);
   cout<<endl<<"s3 "<<s3;

   s4 += s5;
   textattr(highlight);
   cprintf("s4 += s5 ");
   textattr(normal);
   cout<<endl<<"s4 "<<s4;

   textattr(highlight);
   cprintf("s1.charAt(0) is:");
   textattr(normal);
   cout<<"  " <<s1.charAt(0)<<endl;
   textattr(highlight);
   cprintf("s1.indexOf('H') is:");
   textattr(normal);
   cout<<"  "<<s1.indexOf('H')<<endl;
   textattr(highlight);
   cprintf("s1.indexOf(1,'H') is:");
   textattr(normal);
   cout<<"  "<<s1.indexOf(1,'H')<<endl;

   s2 = s1.subString(3);
   textattr(highlight);
   cprintf("s2 = s1.subString(3)");
   textattr(normal);
   cout<<endl<<"s2 "<<s2;

   s2 = s1.subString(0,4);
   textattr(highlight);
   cprintf("s2 = s1.subString(0,4)");
   textattr(normal);
   cout<<endl<<"s2 "<<s2;

   s2 = s4.concat(s5);
   textattr(highlight);
   cprintf("s2 = s4.concat(s5)");
   textattr(normal);
   cout<<endl<<"S2 "<<s2;


   textattr(highlight);
   cprintf("s2 upperCase :");
   textattr(normal);
   cout<<String::uperCase(s2);

   textattr(highlight);
   cprintf("s2 lowerCase : ");
   textattr(normal);
   cout<<String::lowerCase(s2);
   getch();
}

	//constructor
	String::String(char *s){
	 int length=0,j=0;
	 const char *p = s;
	 //increment the lenght while the char != NULL
	 while(*p){
	  length++;
	  p++;
	 }
	 length++; //to include NULL
	 p = s;
	 str = new char[length];
	 size = length;
	 for(j=0;j<length;j++){
	   str[j] = *p++;
	 }

	}

	//copy constructor
	String::String(String &s){
	 size = s.size;
	 str = new char[size];
	 for(int i=0; i<size;i++){
	   str[i] = s.str[i];
	 }
	}

	//destructor
   String::~String(){
	 delete[]str;
	 //cout<<"String Destruct\n";

   }

	//operators overloading
	String & String::operator= (String &s){
	  size = s.size;
	  delete[]str;
	  str = new char[size];
	  for(int i=0; i<size;i++){
	   str[i] = s.str[i];
	  }
	  return *this;
	}


	String String::operator+ (String& s2){
	 String temp(" ");
	 temp.size = size + s2.size -1; //taking one Null only
	 delete[]temp.str;
	 temp.str = new char[temp.size];
	 for(int i=0; i<size-1; i++){
	   temp.str[i] = str[i];
	 }
	 for(i=0;i<s2.size;i++){
	   temp.str[size-1+i] = s2.str[i];
	 }
	 return temp;
	}


	String& String::operator += (String& s2){
	 String temp("");
	 temp.size = size + s2.size -1; //taking one Null only
	 delete[]temp.str;
	 temp.str = new char[temp.size];
	 for(int i=0; i<size-1; i++){
	   temp.str[i] = str[i];
	 }
	 for(i=0;i<s2.size;i++){
	   temp.str[size-1+i] = s2.str[i];
	 }
	 temp.str[temp.size-1]='\0';
	 size = temp.size;
	 delete[]str;
	 str = temp.str;
	 return *this;
	}


	ostream& operator<< (ostream& out, String &s){
	 out<<"the String of size "<<s.size<<" is:  ";
	 int i=0;
	 //while the value stored in the string doesn't equal NULL
	 while(i<s.size){
		out<<s.str[i];
		i++;
	 }
	 out<<endl;

	 return out;
	}

	//behavior of string class
	char String::charAt(int index){
		return str[index];
	}


	int String::indexOf(char ch){
	 for(int i=0; i<size; i++){
		if(str[i] == ch){
		   return i;
		}
	 }
	  return -1;
	}

	int String::indexOf(int start, char ch){
	   for(int i=start; i<size; i++){
		if(str[i] == ch){
		   return i;
		}
	 }
	  return -1;

	}


	String String::subString(int start){
	 String temp(" ");

	 if(size>start){
	 temp.size = size - start;
	 delete[]temp.str;
	 temp.str = new char[temp.size];
	 for(int i=0; i<temp.size; i++){
		temp.str[i] = str[i+start];
	 }
	 }
	 return temp;
	}

	String String::subString(int start, int end){
	  String temp(" ");

	  if(size>end && start >= 0){
		temp.size = end - start +1;
		delete[]temp.str;
		temp.str = new char[temp.size];
		for(int i=0; i<temp.size-1;i++){
		  temp.str[i] = str[start+i];
		}
		temp.str[i] ='\0';
	  }
	  return temp;
	}


	String String::concat(String s2){
	 String temp(" ");
	 temp.size = size + s2.size -1; //taking one Null only
	 delete[]temp.str;
	 temp.str = new char[temp.size];
	 for(int i=0; i<size-1; i++){
	   temp.str[i] = str[i];
	 }
	 for(i=0;i<s2.size;i++){
	   temp.str[size-1+i] = s2.str[i];
	 }
	 return temp;

	}


	String String::uperCase(String &s){
	 String temp("");
	 temp = s;
	 for(int i=0;i<s.size;i++){
		if(s.str[i]>=97){
		  temp.str[i]=s.str[i] - 32;
		}else{
		  temp.str[i] = s.str[i];
		}
	 }
	return temp;
	}

   String String::lowerCase(String &s){
	 String temp("");
	 temp = s;
	 for(int i=0;i<s.size;i++){
		if(s.str[i]>=65 && s.str[i]<=90){
		  temp.str[i]=s.str[i] + 32;
		}else{
		  temp.str[i] = s.str[i];
		}
	 }
	return temp;

   }



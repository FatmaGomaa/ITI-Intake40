#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <iostream.h>

class Base{
  private:
	int x;
  protected:
	int y;
  public:
	Base();
	Base(int a);
	Base(int a, int b);
	Base(Base &b);
	~Base();
	Base& operator= (Base &b);
	void setx(int a);
	void sety(int a);
	void setxy(int a,int b);
	int getx();
	int gety();
	int calcSum();
};

class Derived : public Base{
  private:
	int z;

  public:
	Derived();
	Derived(int a, int b, int c);
	Derived(Derived &d);
	~Derived();
	Derived& operator= (Derived& d);
	void setz(int a);
	int getz();
	int calcSum();


};

void main(void){
  clrscr();
  Base b1;
  Base b2(12,14);
  cout<<b1.calcSum()<<endl;
  cout<<b2.calcSum()<<endl;

  Derived d1;
  Derived d2(2,4,6);
  cout<<d1.calcSum()<<endl;
  cout<<d2.calcSum()<<endl;
  d1.setx(0);
  d1.sety(0);
  d1.setz(0);
  cout<<d1.calcSum()<<endl;

  d1 =d2;
  cout<<d1.calcSum()<<endl;
  getch();
}

/**************************Base*******************************/
	Base::Base(){x=y=0;cout<<"Base Constructor\n";}
	Base::Base(int a){x=y=a;cout<<"Base Constructor\n";}
	Base::Base(int a, int b){x=a; y=b;cout<<"Base Constructor\n";}
	Base::Base(Base &b){x = b.x; y=b.y;cout<<"Copy Base Constructor\n";}
	Base::~Base(){cout<<"Base destruct\n";}
	Base& Base::operator= (Base &b){x =b.x; y=b.y;cout<<"Copy Base Constructor\n";return *this;}
	void Base::setx(int a){x=a;}
	void Base::sety(int a){y=a;}
	void Base::setxy(int a,int b){x=a; y=b;}
	int Base::getx(){return x;}
	int Base::gety(){return y;}
	int Base::calcSum(){return x+y;}

/****************************Derived****************************/

	Derived::Derived(){/*setx(0); y=0; */z=0;cout<<"Derived Constructor\n";}
	Derived::Derived(int a, int b, int c){setx(a);y=b;z=c;cout<<"Derived Constructor\n";}
	Derived::Derived(Derived &d){z=d.z;cout<<"copy Derived Constructor\n";}
	Derived::~Derived(){cout<<"Derived Destruct\n";}
	Derived& Derived::operator= (Derived& d){setx(d.getx()); y=d.y; z=d.z;cout<<"copy Derived Constructor\n"; return *this;}
	void Derived::setz(int a){z=a;}
	int Derived::getz(){return z;}
	int Derived::calcSum(){return Base::calcSum() + z;}
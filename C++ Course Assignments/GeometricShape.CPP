#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <iostream.h>
#include <graphics.h>


class GeoShape{
  protected:
  float dim1,dim2;

  public:
  GeoShape(){dim1=dim2=0;}
  GeoShape(float f1, float f2){dim1 = f1; dim2 = f2;}
  ~GeoShape(){};
  virtual float calcArea()=0;
  void setdim1(float f){dim1 = f;}
  void setdim2(float f){dim2 = f;}
  float getdim1(){return dim1;}
  float getdim2(){return dim2;}

};

class Rect : public GeoShape{
  public:
  Rect(): GeoShape(0,0){}
  Rect(float w, float l): GeoShape(w,l){}
  ~Rect(){};
  float calcArea(){return dim1*dim2;}
};

class Circle: public GeoShape{
  public:
  Circle(): GeoShape(0,0){}
  Circle(float r): GeoShape(r,r){}
  ~Circle(){};
  float calcArea(){return 3.14*dim1*dim2;}

};

class Triangle: public GeoShape{
  public:
  Triangle(): GeoShape(0,0){}
  Triangle(float b, float h): GeoShape(b,h){}
  ~Triangle(){};
  float calcArea(){return .5*dim1*dim2;}

};

class Square: public GeoShape{
  public:
  Square(): GeoShape(0,0){}
  Square(float l): GeoShape(l,l){}
  ~Square(){};
  float calcArea(){return dim1*dim2;}

};

float sumAreas(GeoShape *p1, GeoShape *p2, GeoShape *p3);

void main(){
clrscr();
 Rect r(5,4); Circle c(4);
 Triangle t(10,10); Square s(10);
 cout<<"r(5,4)"<<endl<<"c(4)"<<endl<<"t(10,10)"<<endl<<"s(10)"<<endl;
 cout<<"Rect Area: "<<r.calcArea()<<endl;
 cout<<"Circle Area: "<<c.calcArea()<<endl;
 cout<<"Triangle Area: "<<t.calcArea()<<endl;
 cout<<"Square Area: "<<s.calcArea()<<endl;
 cout<<"Sum of Areas for Rect + Circle + Triangle: "<<sumAreas(&r,&c,&t)<<endl;

 getch();
}

float sumAreas(GeoShape *p1, GeoShape *p2, GeoShape *p3){

 return p1->calcArea() + p2->calcArea() + p3->calcArea();

}
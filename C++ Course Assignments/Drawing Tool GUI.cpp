#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <iostream.h>

class Shape{
 private:
	int color;
 public:
	Shape(){color =0;}
	Shape(int c){color =c;}
	setColor(int c){color = c;}
 int getColor(){return c;}

}

class Point: public Shape{
  private:
  int x,y;

  public:
  //constructors
  Point();
  Point(int x, int y);
  //copy constructors
  Point(Point &p);
  //destructor
  ~Point();
  //equal operator assignment
  Point& operator=(Point& p);

  //Methods
  void setx(int x);
  void sety(int y);
  void setxy(int x, int y);
  int getx();
  int gety();
  void print();


};

class Line: public Shape{
  private:
  Point start,end;

  public:
  Line();
  Line(int x1,int y1,int x2,int y2);
  Line(Point &p1, Point &p2);
  ~Line();
  Line(Line &l);
  Line& operator=(Line &l);
  void setStart(int x, int y);
  void setEnd(int x, int y);
  void setStart(Point &p);
  void setEnd(Point &p);
  void print();

};

class Circle : public Shape{
  private:
  Point center; int rad;

  public:
  Circle();
  Circle(int x1,int y1,int r);
  Circle(Point &p, int r);
  Circle(Circle &c);
  Circle& operator=(Circle &c);
  ~Circle();
  void setCenter(int x,int y);
  void setCenter(Point &p);
  void setRad(int r);
  Point getCenter();
  int getRad();
  void print();

};

class Rect : public Shape{
  private:
  Point UpperLeft,LowerRight;

  public:
  Rect();
  Rect(int x1,int y1,int x2,int y2);
  Rect(Point &p1, Point &p2);
  ~Rect();
  Rect(Rect &r);
  Rect& operator=(Rect &r);
  void setUpper(int x, int y);
  void setLower(int x, int y);
  void setUpper(Point &p);
  void setLower(Point &p);
  void print();

};

void main(){
clrscr();
 Point p1(5,7), p2(10,12);
 Line l,l1(10,5,30,40);
 Line l2(p1,p2);
 Circle c1(10,20,5),c2(p1,4),c3;
 Rect r1(100,200,300,400);
 p1.print();
 p2.print();
 p1 =p2;
 p1.print();
 l1.print();
 //l.print();
 c1.print();
 //c2.print();
 //c3.print();
 r1.print();
getch();
}
  /***************************Point Class******************************/
  //constructors
  Point::Point(){
	x=y=0;
  }

  Point::Point(int x, int y){
   this->x = x, this->y = y;
  }
  //copy constructors
  Point::Point(Point &p){
   p.x =this->x;
   p.y =this->y;
  }
  //destructor
  Point::~Point(){
   cout<<"point destruct\n";
  }
  //equal operator assignment
  Point& Point::operator=(Point& p){
	this->x = p.x;
	this->y =p.y;

	return *this;
  }

  //Methods
  void Point::setx(int x){
	this->x = x;
  }
  void Point::sety(int y){
	this->y = y;
  }
  void Point::setxy(int x,int y){
   this->x = x; this->y = y;
  }
  int Point::getx(){
	return this->x;
  }
  int Point::gety(){
	return this->y;
  }
  void Point::print(){
	cout<<"point has cordinates ("<<x<<","<<y<<")"<<endl;
  }
/****************************Line Class******************************/
  Line::Line():start(0,0),end(0,0){
   start.setxy(0,0);
   end.setxy(0,0);
  }
  Line::Line(int x1,int y1,int x2,int y2):start(0,0),end(0,0){
   start.setxy(x1,y1);
   end.setxy(x2,y2);
  }
  Line::Line(Point &p1, Point &p2):start(0,0),end(0,0){
   start = p1;
   end = p2;
  }
  Line::~Line(){
   cout<<"Line destruct\n";
  }
  Line::Line(Line &l):start(0,0),end(0,0){
   l.start = this->start;
   l.end = this->end;

  }
  Line& Line::operator=(Line &l){
   this->start = l.start;
   this->end = l.end;
  return *this;
  }
  void Line::setStart(int x, int y){
   start.setxy(x,y);
  }
  void Line::setEnd(int x, int y){
   end.setxy(x,y);
  }
  void Line::setStart(Point &p){
   start = p;
  }
  void Line::setEnd(Point &p){
   end = p;
  }
  void Line::print(){
   cout<<"line is here\n";
   cout<<"start has cordinates ("<<start.getx()<<","<<start.gety()<<")"<<endl;
   cout<<"end has cordinates ("<<end.getx()<<","<<end.gety()<<")"<<endl;
  }

/***********************Circle Class********************/
  Circle::Circle(){
	center.setxy(0,0);
	rad=0;
  }
  Circle::Circle(int x1,int y1,int r){
   center.setxy(x1,y1);
   rad =r;
  }
  Circle::Circle(Point &p, int r){
   center =p;
   rad =r;
  }
  Circle::Circle(Circle &c){
   c.center = this->center;
   c.rad = this->rad;
  }
  Circle& Circle::operator=(Circle &c){
   this->center = c.center;
   this->rad = c.rad;
   return *this;
  }
  Circle::~Circle(){
   cout<<"circle deconstruct";
  }
  void Circle::setCenter(int x,int y){
   center.setxy(x,y);
  }
  void Circle::setCenter(Point &p){
   center =p;
  }
  void Circle::setRad(int r){
   rad = r;
  }
  Point Circle::getCenter(){
   return center;
  }
  int Circle::getRad(){
   return rad;
  }
  void Circle::print(){
	cout<<"Circle is here\n";
	cout<<"center has cordinates ("<<center.getx()<<","<<center.gety()<<")"<<endl;
	cout<<"radius is: "<<rad<<endl;

  }


/****************************Rect Class******************************/
  Rect::Rect():UpperLeft(0,0),LowerRight(0,0){
   UpperLeft.setxy(0,0);
   LowerRight.setxy(0,0);
  }
  Rect::Rect(int x1,int y1,int x2,int y2):UpperLeft(0,0),LowerRight(0,0){
   UpperLeft.setxy(x1,y1);
   LowerRight.setxy(x2,y2);
  }
  Rect::Rect(Point &p1, Point &p2):UpperLeft(0,0),LowerRight(0,0){
   UpperLeft = p1;
   LowerRight = p2;
  }
  Rect::~Rect(){
   cout<<"Rect destruct\n";
  }
  Rect::Rect(Rect &r):UpperLeft(0,0),LowerRight(0,0){
   r.UpperLeft = this->UpperLeft;
   r.LowerRight = this->LowerRight;

  }
  Rect& Rect::operator=(Rect &r){
   this->UpperLeft = r.UpperLeft;
   this->LowerRight = r.LowerRight;
  return *this;
  }
  void Rect::setUpper(int x, int y){
   UpperLeft.setxy(x,y);
  }
  void Rect::setLower(int x, int y){
   LowerRight.setxy(x,y);
  }
  void Rect::setUpper(Point &p){
   UpperLeft = p;
  }
  void Rect::setLower(Point &p){
   LowerRight = p;
  }
  void Rect::print(){
   cout<<"Rect is here\n";
   cout<<"UpperLeft has cordinates ("<<UpperLeft.getx()<<","<<UpperLeft.gety()<<")"<<endl;
   cout<<"LowerRight has cordinates ("<<LowerRight.getx()<<","<<LowerRight.gety()<<")"<<endl;
  }
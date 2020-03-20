#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <iostream.h>
#include <graphics.h>
#include <dos.h>

class Shape{
 private:
	int color;
 public:
	Shape(){color =10;}
	Shape(int c){color =c;}
 void setColor(int c){color = c;}
 int getColor(){return color;}
 virtual void draw()=0;
};

class Point{
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
  Line(int x1,int y1,int x2,int y2, int c);
  Line(Point &p1, Point &p2);
  ~Line();
  Line(Line &l);
  Line& operator=(Line &l);
  void setStart(int x, int y);
  void setEnd(int x, int y);
  void setStart(Point &p);
  void setEnd(Point &p);
  void print();
  void draw();
};

class Circle : public Shape{
  private:
  Point center; int rad;

  public:
  Circle();
  Circle(int x1,int y1,int r);
  Circle(int x1,int y1,int r, int c);
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
  void draw();
};

class Rect : public Shape{
  private:
  Point UpperLeft,LowerRight;

  public:
  Rect();
  Rect(int x1,int y1,int x2,int y2);
  Rect(int x1,int y1,int x2,int y2, int c);
  Rect(Point &p1, Point &p2);
  ~Rect();
  Rect(Rect &r);
  Rect& operator=(Rect &r);
  void setUpper(int x, int y);
  void setLower(int x, int y);
  void setUpper(Point &p);
  void setLower(Point &p);
  void print();
  void draw();
};

class Pic{
  private:
  int nl,nc,nr;
  Line * lp;
  Circle * cp;
  Rect * rp;

  public:
  Pic();
  Pic(int a, int b,int c, Line *p1, Circle *p2, Rect *p3);
  ~Pic();
  void setLines(int l, Line *p);
  void setCircles(int c, Circle *p);
  void setRects(int r, Rect *p);
  void paint();

};

void main(){
 clrscr();
int gdriver = DETECT, gmode, errorcode;

/* initialize graphics and local variables */
initgraph(&gdriver, &gmode, "");

/* read result of initialization */
errorcode = graphresult();
if (errorcode != grOk)  /* an error occurred */
{
   printf("Graphics error: %s\n", grapherrormsg(errorcode));
   printf("Press any key to halt:");
   getch();
   exit(1); /* terminate with an error code */
}


 else{
  Pic mypic;
  Circle cArr[1] = { Circle(200,200,200,2)};
  //Rect rArr[2] = { Rect(30,40,170,100,11), Rect(420,50,500,300,12) };
  //Line lArr[2] = { Line(200,200,200,50,3), Line(200,200,100,100,3)};
  mypic.setCircles(1,cArr);
  for(int i=0;i<15;i++){
  Line lArr[2] = { Line(200,200,200,100,3), Line(200,200,200+(i*8),50+(i*10),3)};
  mypic.setLines(2,lArr);
  mypic.paint();
  delay(400);
  cleardevice();
  }
  for(i=0;i<15;i++){
  Line lArr[2] = { Line(200,200,200,100,3), Line(200,200,312-(i*8),190+(i*10),3)};
  mypic.setLines(2,lArr);
  mypic.paint();
  delay(400);
  cleardevice();
  }
  for(i=0;i<15;i++){
  Line lArr[2] = { Line(200,200,200,100,3), Line(200,200,200-(i*8),330-(i*10),3)};
  mypic.setLines(2,lArr);
  mypic.paint();
  delay(400);
  cleardevice();
  }
   for(i=0;i<15;i++){
  Line lArr[2] = { Line(200,200,200,100,3), Line(200,200,88+(i*8),190-(i*10),3)};
  mypic.setLines(2,lArr);
  mypic.paint();
  delay(400);
  cleardevice();
  }
 }
 getch();
 closegraph();
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
   //cout<<"point destruct\n";
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

  Line::Line(int x1,int y1,int x2,int y2, int c){
   start.setxy(x1,y1);
   end.setxy(x2,y2);
   setColor(c);
  }
  Line::Line(Point &p1, Point &p2):start(0,0),end(0,0){
   start = p1;
   end = p2;
  }
  Line::~Line(){
   //cout<<"Line destruct\n";
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
  void Line::draw(){
   setcolor(getColor());
   line(start.getx(), start.gety(), end.getx(), end.gety());
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
  Circle::Circle(int x1,int y1,int r, int c){
   center.setxy(x1,y1);
   rad =r;
   setColor(c);
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
   //cout<<"circle deconstruct";
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
  void Circle::draw(){

   setcolor(getColor());
   circle(center.getx(),center.gety(),rad);
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
   Rect::Rect(int x1,int y1,int x2,int y2, int c):UpperLeft(0,0),LowerRight(0,0){
   UpperLeft.setxy(x1,y1);
   LowerRight.setxy(x2,y2);
   setColor(c);
  }
  Rect::Rect(Point &p1, Point &p2):UpperLeft(0,0),LowerRight(0,0){
   UpperLeft = p1;
   LowerRight = p2;
  }
  Rect::~Rect(){
   //cout<<"Rect destruct\n";
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
 void Rect::draw(){

   setcolor(getColor());
  rectangle(UpperLeft.getx(), UpperLeft.gety(), LowerRight.getx(), LowerRight.gety());

 }


/*****************************PIC Methods********************************/

  Pic::Pic(){
	nl = nc = nr =0;
	lp = NULL;
	cp = NULL;
	rp = NULL;
  }

  Pic::Pic(int a, int b,int c, Line *p1, Circle *p2, Rect *p3){
	nl = a;  nc = b;  nr = c;
	lp = p1; cp = p2; rp = p3;
  }

  Pic::~Pic(){
   //cout<<"pic destruction\n";
  }

  void Pic::setLines(int l, Line *p){
	nl = l; lp = p;
  }

  void Pic::setCircles(int c, Circle *p){
	nc = c; cp = p;
  }

  void Pic::setRects(int r, Rect *p){
	nr = r; rp = p;
  }

  void Pic::paint(){
	for(int i=0; i<nl && lp; i++){
	 lp[i].draw();
	}
	for(i=0; i<nc && cp; i++){
	 cp[i].draw();
	}
	for(i=0; i<nr && rp; i++){
	 rp[i].draw();
	}
  }
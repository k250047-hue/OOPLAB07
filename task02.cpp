#include<iostream>
using namespace std;

class Shape
{
    int position,border;
    string color;
 
public:
    Shape(int p,string c,int b):position(p),color(c),border(b){}

    void draw()
    {
        cout<<endl<<"This Shape is drawn at position:"<<position
            <<endl<<"Its color is:"<<color
            <<endl<<"Its border thickness is:"<<border<<endl;
    }

    void calculateArea()
    {
        cout<<endl<<"Formula of area not defined"<<endl;
    }

    void calculateParameter()
    {
        cout<<endl<<"Formula for parameter is not defined"<<endl;
    }
};

class Circle:public Shape
{
    double radius,center;

public:
    Circle(int p,string c,int b,double r,double cen)
        :Shape(p,c,b)
    {
        radius=r;
        center=cen;
    }

    void draw()
    {
        cout<<endl<<"Drawing Circle"<<endl;
        cout<<"Radius:"<<radius<<endl;
        cout<<"Center:"<<center<<endl;
    }
};

class Rectangle:public Shape
{
    double width,height;

public:
    Rectangle(int p,string c,int b,double w,double h)
        :Shape(p,c,b)
    {
        width=w;
        height=h;
    }

    void draw()
    {
        cout<<endl<<"Drawing Rectangle"<<endl;
        cout<<"Width:"<<width<<endl;
        cout<<"Height:"<<height<<endl;
    }
};

class Triangle:public Shape
{
    double base,height;

public:
    Triangle(int p,string c,int b,double ba,double h)
        :Shape(p,c,b)
    {
        base=ba;
        height=h;
    }

    void draw()
    {
        cout<<endl<<"Drawing Triangle"<<endl;
        cout<<"Base:"<<base<<endl;
        cout<<"Height:"<<height<<endl;
    }
};

class Polygon:public Shape
{
    int sides;

public:
    Polygon(int p,string c,int b,int s)
        :Shape(p,c,b)
    {
        sides=s;
    }

    void draw()
    {
        cout<<endl<<"Drawing Polygon"<<endl;
        cout<<"Number of sides:"<<sides<<endl;
    }
};

int main()
{
    Circle c(10,"Red",2,5,3);
    Rectangle r(20,"Blue",1,8,4);
    Triangle t(30,"Green",2,6,5);
    Polygon p(40,"Yellow",3,7);

    c.draw();
    r.draw();
    t.draw();
    p.draw();

    return 0;
}
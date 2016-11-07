#include <iostream>
using namespace std;

class Shape{
public:
	Shape():x(0),y(0){cout << "Shape::Shape()" << endl;}
	virtual ~Shape(){cout << "Shape::~Shape()" << endl;}
	virtual  void speak(){cout << "I\'m Shape" << endl;}
private:
	float x,y;
};

class Ellipse: public Shape{
public:
	Ellipse():long_len(10),short_len(5){cout << "Ellipse::Ellipse()" << endl;}
	virtual ~Ellipse(){cout << "Ellipse::~Ellipse()" << endl;}
	virtual  void speak(){cout << "I\'m Ellipse" << endl;}
private:
	float long_len, short_len;
};

class Circle: public Ellipse{
public:
	Circle(){cout << "Circle::Circle()" << endl;}
	virtual~Circle(){cout << "Circle::~Circle()" << endl;}
	virtual void speak(){cout << "I\'m Circle" << endl;}
};

void speak(Shape* p){
	p->speak();
}
void speak(Shape& p){
	p.speak();
}
int main(){
	Shape sh;
	Ellipse ell;
	Circle circ;
	//sh.speak();
	//ell.speak();
	//circ.speak();
	speak(&sh);
	speak(&ell);
	speak(&circ);
	cout << "***************************" << endl;
	speak(sh);
	speak(ell);
	speak(circ);	
	return 0;
}
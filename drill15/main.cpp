/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o ch13 `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"

double one(double x) {return 1;}
double slope(double x) {return x/2;}
double square(double x) {return x*x;}
double sloping_cos(double x) {return cos(x) + slope(x);}

int main()
{
    Simple_window win {Point{200,200},600,600,"Function graphs"};

	Axis x {Axis::x, Point{100, 300}, 400, 20, "1 == 20 pixels"};
	x.set_color(Color::red);
    
	Axis y {Axis::y, Point{300, 500}, 400, 20, "1 == 20 pixels"};
	y.set_color(Color::red);

	win.attach(x);
	win.attach(y);



	Function fnc1 {one,-10,11,Point{300,300},400,20,20};
	win.attach(fnc1);

	Function fnc2 {slope,-10,11,Point{300,300},400,20,20,}; //Label?????
	win.attach(fnc2);

	//win.attach(new Function{cos,-10,11,Point{300,300},400,20,20});
	Function fnc3 {square,-10,10,Point{300,300},400,20,20};
	win.attach(fnc3);

	Function fnc4 {cos,-10,10,Point{300,300},400,20,20};
	fnc4.set_color(Color::blue);
	win.attach(fnc4);

	Function fnc5 {sloping_cos,-10,10,Point{300,300},400,20,20};
	win.attach(fnc5);




	win.wait_for_button();
}
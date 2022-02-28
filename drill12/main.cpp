/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"

int main()
{
    using namespace Graph_lib;

	Point tl {100, 100};
	Simple_window win {tl, 1600, 900, "Canvas"};
	win.color(Color::white);
	// 2D koordinátarendszer
	Axis xa {Axis::x, Point{20,300}, 500, 10, "x axis"};
	win.attach(xa);
	
	Axis ya {Axis::y, Point(20,300),280,10,"y axis"};
	ya.set_color(Color::cyan);
	ya.label.set_color(Color::dark_red);
	win.attach(ya);

	// Sin fv
	Function sine {sin,0,100,Point{20,150},1000,50,50};
	win.attach(sine);

	// Polygon
	Polygon poly;
	poly.add(Point{300,200});
	poly.add(Point{350,100});
	poly.add(Point{350,200});
	poly.add(Point{400,100});

	poly.set_color(Color::blue);
	poly.set_fill_color(Color::dark_blue);
	poly.set_style(Line_style(Line_style::dash,4));

	win.attach(poly);

	// Rectangle
	Rectangle r {Point{200,200},100,50};
	r.set_fill_color(Color::yellow);
	r.set_style(Line_style::dot);
	win.attach(r);

	// Poly rect
	Closed_polyline poly_rect;
	poly_rect.add(Point{100,50});
	poly_rect.add(Point{200,50});
	poly_rect.add(Point{200,100});
	poly_rect.add(Point{100,100});
	poly_rect.add(Point{50,75});
	
	poly_rect.set_style(Line_style(Line_style::dash,2));
	poly_rect.set_fill_color(Color::green);
	win.attach(poly_rect);

	// Text
	Text t {Point{10,30},"Hello, graphincal world!!!!!!"};
	t.set_font_size(30);

	win.attach(t);

	//--------------------//
    win.wait_for_button();
}
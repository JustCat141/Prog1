/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o ch13 `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"

int main()
{
    using namespace Graph_lib;

    Simple_window win {Point{100,100},700,480,"Canvas"};

	win.wait_for_button();

}
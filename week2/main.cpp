/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o ch13 `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"

int main()
{
    using namespace Graph_lib;

    const int xmax = 800;
    const int ymax = 800;

    Simple_window win {Point{100,100}, xmax, ymax, "Canvas"};

	const int grid_width = 100;
	const int grid_height = 100;

	// Grids
	Lines grid;
	for (int i = 0; i < xmax/grid_width+1; i++)
	{
		for (int x = 0; x < xmax/grid_width; x++)
		{
			grid.add(Point{x*grid_width,i*grid_height},Point{(x+1)*grid_width,i*grid_height});
		}
		for (int y = 0; y < ymax/grid_height; y++)
		{
			grid.add(Point{i*grid_width,y*grid_height},Point{i*grid_width,(y+1)*grid_height});
		}
	}
	
	win.attach(grid);

	// Red grids XDDDDDDD
	Vector_ref<Rectangle> rects;

	for (int i = 0; i < grid_height; i++)
	{
		rects.push_back(new Rectangle(Point{0,grid_height*i},grid_width,grid_height));
		rects[i].set_color(Color::red);
		win.attach(rects[i]);
	}
	
    win.wait_for_button();

}
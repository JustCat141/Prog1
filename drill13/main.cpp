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

    const int window_width = 800;
    const int window_height = 1000;

	// 1. Simple window
    Simple_window win {Point{500,100}, window_width, window_height, "Drill"};

	const int grid_width = 100;
	const int grid_height = 100;

	// 2. Grids
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

	// 3. Red grids
	Vector_ref<Rectangle> rects;

	for (int i = 0; i < ymax/grid_height; i++)
	{
		rects.push_back(new Rectangle(Point{grid_width*i,grid_height*i},grid_width+1,grid_height+1));
		rects[i].set_color(Color::red);
        rects[i].set_fill_color(Color::invisible);
		win.attach(rects[i]);
	}

    // 4. Images
    Image im1 {Point{200,0},"badge.jpg"};
    im1.set_mask(Point{100,100},200,200);
    Image im2 {Point{400,200},"badge.jpg"};
    im2.set_mask(Point{100,100},200,200);
    Image im3 {Point{600,200},"badge.jpg"};
    im3.set_mask(Point{100,100},200,200);

    win.attach(im1);
    win.attach(im2);
    win.attach(im3);
	

	// 5. 100x100 image move

	Image image {Point{0,0},"badge.jpg"};
	image.set_mask(Point{150,150},100,100);
	win.attach(image);
	
	
	for (int y = 0; y < 8; y++)
	{
		win.wait_for_button();
		if(y<8) {
			for (int x = 0; x < 7; x++)
			{
				image.move(100,0);
				win.wait_for_button();
			}
			image.move(-700,100);
		}
	}	
}
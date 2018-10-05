#include "Box.h"
#include "fstream"
#include <cstdlib>



//constructor.
Box::Box(){
	
		length = rand()%26 +5;
		width = rand()%26 +5;
		height = rand()%26 +5;
	    }
//function which gets the Width of the box.
int Box::get_width(){
		return width;
	}	
//function which gets the Height of the box.
int Box::get_height(){
		return height;
	}
//function which gets the length of the box.
int Box::get_length(){
		return length;
	}


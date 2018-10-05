#ifndef BOX_H
#define BOX_H



//class of box
class Box
{	private:
	    int length;
	    int width;
	    int height;
	public:
    	Box();
	    //function which gets the Width of the box.
		int get_width();
		//function which gets the Height of the box.
		int get_height();
		//function which gets the length of the box.
		int get_length();
    
};
#endif

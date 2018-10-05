#pragma once
#ifndef TRUCK_H
#define TRUCK_H
#include "Box.h"

//Making a class of truck
class Truck
{	private:
	    char driver[32];
	    int petrol;
	    int money;
	    int fullMileage;
	    int emptyMileage;
	    Box* box;
	      
	public:
		//functions to store names of the drivers.
		void setDriver(char* name);
		char* getDriver();
		//functions to store the values of the petrol.
		void setPetrol(int petrol);
		int getPetrol();
		//functions to store the values of the money.
		void setMoney(int money);
		int getMoney();
		//functions to store the values of the full mileage.
		void setFullMileage(int fullMileage);
		int getFullMileage();
		//functions to store the values of the empty mileage.
		void setEmptyMileage(int emptyMileage);
		int getEmptyMileage();
		
	    //calculates the cost.
	    float Cost();
	    //calculates the reamining petrol after the journey.
	    float petrolLeft();
	    
	    
	    //function which loads the boxes.
	    void Load(int numBox);            //numbox produces 12 to 20 boxes.
	 	//function which unloads the boxes.
	    void Unload(int numBox);
	    
	    
};

#endif

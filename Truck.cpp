#include <iostream>
#include "Truck.h"
#include "Box.h"


//functions to store names of the drivers.
void Truck::setDriver(char* name){
		
		for (int i =0; i < 32; i++){
			this->driver[i]= name[i];
		}	  	
	}
char* Truck::getDriver(){
		return this->driver; 
	}
//functions to store the values of the petrol.	
void Truck::setPetrol(int petrol){
		int temp = petrol;
		this -> petrol = temp;			
	}
	
int Truck::getPetrol(){
		return petrol;
	}
//functions to store the values of the money.	
void Truck::setMoney(int money){
		this -> money= money ;
	}

int Truck::getMoney(){
		return this ->money;
	}
//functions to store the values of the full mileage.
void Truck::setFullMileage(int fullMileage){
		this -> fullMileage= fullMileage;
	}

int Truck::getFullMileage(){
		return this ->fullMileage;
	}
//functions to store the values of the empty mileage.	
void Truck::setEmptyMileage(int emptyMileage){
		this -> emptyMileage= emptyMileage;
	}

int Truck::getEmptyMileage(){
		return this->emptyMileage;
	}
//calculates the reamining petrol after the journey.	
float Truck::Cost(){
	
		float price= 2.73;
		
		float loadedPetrol= 50 -petrol;
			
		float cost = loadedPetrol*price;
		float Money= money-cost;		
		return Money;
	    }
//calculates the remaining money.
float Truck::petrolLeft(){
	int totalPetrol=50;
	float distance= 60.0;
	float fullMileageDistance= distance/fullMileage;
	float emptyMileageDistance= distance/emptyMileage;		
	float remainingPetrol = 50-(fullMileageDistance +emptyMileageDistance);
	
	return remainingPetrol;	}
	
//function which loads the boxes.	
void Truck::Load(int numBox)            
	{	
	box = new Box[numBox];
	std::cout<< "----------------Loading---------------- \n";
	for(int i=0; i< numBox; i++){	
	    //std::cout << box[i].get_length()<< "  "<< "Width "<<  box[i].get_width()<< " "<< "Height "<< box[i].get_height()<<std::endl;}
		std::cout << "Dimensions " <<box[i].get_length()<< ","<<  box[i].get_width()<< ","<<  box[i].get_height()<<std::endl;}
	}
//function which unloads the boxes.
void Truck:: Unload(int numBox)
	{	std::cout<< "----------------Unloading---------------- \n";
	    for(int i=0; i<numBox; i++){
			//std::cout << "Length "<< box[i].get_length()<< "  "<< "Width "<<  box[i].get_width()<< " "<< "Height "<< box[i].get_height()<<std::endl;	        	
			std::cout <<"Dimensions " <<box[i].get_length()<< ","<<  box[i].get_width()<< ","<<  box[i].get_height()<<"\n";
			}
		std::cout<< "\n\n";
		delete []box;	
	    }

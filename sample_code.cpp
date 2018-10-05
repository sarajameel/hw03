#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fstream>

#include "Truck.h"
#include "Truck.cpp"
#include "Box.h"
#include "Box.cpp"

using namespace std;
//function to read lines in the drivers.txt file.
int LineCounter(char* fileName)
{
    FILE* filePointer;                          //Declaring a file pointer
    char buff[32];                              //Declaring a character array to store a line

    filePointer = fopen(fileName, "r");         //Opening file as read only

    if (filePointer == NULL)                    //If file is not found
    {
        perror ("Error opening file");          //Show Error
        return 0;
    }

    int counter = 0;                            //Counts the lines in file

    while(fgets(buff, 32, (FILE*)filePointer) !=NULL)   //If line read is not NULL
    {
        counter++;                                      //increase line count
    }
    fclose(filePointer);                                //close file when done
    return counter;                                     //return line count
}
int main()
{	
	srand(time(0));
    Truck T;
    char filename[]= "Drivers.txt";
    int size = LineCounter(filename)/5;    //declaring the size of array
	//cout<<LineCounter("Drivers.txt")<<endl;		//displaying the line counter
	
    FILE* filePointer;                          //Declaring a file pointer
    char buff[32];                              //Declaring a character array to store a line

    filePointer = fopen("Drivers.txt", "r");    //Opening file as read only

    if (filePointer == NULL)
    {
        perror ("Error opening file");
        return 0;
    }
    
	int counterPeopleCanMakeTrip=0;             //counter which evaluates how many people/trucks can make the trip
    
    filePointer = fopen("Drivers.txt", "r");
    int calculatePetrol=0;
    int calculateMoney=0;
    float calculateCost=0; 
    bool* j = new bool[size];
    fgets(buff, 32, (FILE*)filePointer);
    
    //Reading only the petrol and money to check if the truck/person can make the journey
    for (int count=0; count < size; count++){
    	fgets(buff, 32, (FILE*)filePointer);
    	calculatePetrol=atoi(buff);
    
    	fgets(buff, 32, (FILE*)filePointer);
    	calculateMoney = atoi(buff);
    	
    	calculateCost=(50-calculatePetrol)*2.73;
		if(calculateMoney-calculateCost>=0){
			j[count]=1;
			counterPeopleCanMakeTrip++;}
		else{
			j[count]=0;
		}
		
		//counterPeopleCanMakeTrip++;
    	fgets(buff, 32, (FILE*)filePointer);
    	fgets(buff, 32, (FILE*)filePointer);
    	fgets(buff, 32, (FILE*)filePointer);	
	}
	std::cout<< counterPeopleCanMakeTrip  <<"  people can make the Trip \n\n";
	fclose(filePointer);
	
	filePointer = fopen("Drivers.txt", "r");    //Opening file as read only
    
    if (filePointer == NULL)
    {
        perror ("Error opening file");
        return 0;
    }
    //creating an array of size of the number of people who can make the trip. This ensures the truck object is only created for those who can make the journey. 
    Truck* truckArray= new Truck [counterPeopleCanMakeTrip];
    int c1 = 0;
    //adding atributes to the array
	for (int i=0; i < size;i++){
	
		if (j[i]==true){
		
	    fgets(buff, 32, (FILE*)filePointer);                     //Reading and storing the name of the driver directly
		truckArray[c1].setDriver(buff);
		
		
	    fgets(buff, 32, (FILE*)filePointer);                     //reading and storing the values of petrol 
	    truckArray[c1].setPetrol(atoi(buff));
	  
	
	    fgets(buff, 32, (FILE*)filePointer);                     //reading and storing the values of money
		truckArray[c1].setMoney(atoi(buff));
		
	
	    fgets(buff, 32, (FILE*)filePointer);                     //reading and storing the values of fullMileage
	  	truckArray[c1].setFullMileage(atoi(buff));
	  	
	
	    fgets(buff, 32, (FILE*)filePointer);                     //reading and storing the values of emptyMileage
		truckArray[c1].setEmptyMileage(atoi(buff));
		c1++;
		}
		else
		{
			fgets(buff, 32, (FILE*)filePointer);                //if the truck cannot make the journey. reading but not storing the values in the array.Skipping these lines and moving to the next driver.
			fgets(buff, 32, (FILE*)filePointer);
			fgets(buff, 32, (FILE*)filePointer);
			fgets(buff, 32, (FILE*)filePointer);
			fgets(buff, 32, (FILE*)filePointer);	
		}
	}
	     fclose(filePointer);
	    
		 int x=rand()%9+12;
		 
		ofstream myfile;
    	myfile.open ("trip.txt");
		 
	 for (int i=0; i<counterPeopleCanMakeTrip ; i++)
	
	 {		//	WITITNG TO FILE called trip.txt
	 
	 		myfile<< "Truck driver is: " << truckArray[i].getDriver();
	 		myfile<<"Truck petrol after journey is: " << truckArray[i].petrolLeft()<<endl;
	 		
	 		myfile<<"Truck full mileage is: " << truckArray[i].getFullMileage()<<endl;
	 		myfile<<"Truck empty mileage is: " << truckArray[i].getEmptyMileage()<<"\n";
		 	myfile<<"Money remaining "<< truckArray[i].Cost()<<"\n\n\n";
		 	
		 	
		 	//displaying the name, petrol, money, fullMileage, emptyMileage, dimensions of boxes during load and unload, moneyleft and petrolLeft. 
	 		cout << "Truck driver is: " << truckArray[i].getDriver();//ural.driver;
		    //cout << "Truck petrol is: " << truckArray[i].getPetrol()<<endl;
		    //cout << "Truck money is: " << truckArray[i].getMoney()<<endl;
		    //cout << "Truck full mileage is: " << truckArray[i].getFullMileage()<<endl;
		 	//cout << "Truck empty mileage is: " << truckArray[i].getEmptyMileage()<<"\n\n\n";
			truckArray[i].Load(x);
		 	truckArray[i].Unload(x);
		 	//cout << "Money remaining "<< truckArray[i].Cost()<<"\n";
			//cout<< "Remaining Petrol is "<< truckArray[i].petrolLeft()<<" liters \n\n\n";
			 }
			 
			delete []truckArray;		
    return 0;
}

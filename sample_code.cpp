#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct Box
{
  int length;
  int width;
  int height;

  Box()
  {
    length = width = height = 5;
  }


  int Volume()
  {
    return 0;
  }
};

struct Truck
{
  char driver[32];
  int petrol;
  int money;
  int full_mileage;
  int empty_mileage;
  Box box;

  void load(int num_box)
  {

  }
  void unload()
  {

  }

  float cost()
  {

  }
};

int line_counter(char* filename)
{
  // Open filename and read it using a file pointer and a character
  // buffer. Report error and exit if file cannot be opened.
  char buff[32];
  FILE* file_pointer = fopen(filename, "r");
  if (file_pointer == NULL) {
    perror ("Error opening file");
    return 0;
  }
  // Count the lines in the file.
  int counter = 0;
  while(fgets(buff, 32, (FILE*)file_pointer) !=NULL) {
    counter++;
  }
  // Wrap up.
  fclose(file_pointer);
  return counter;
}

int main()
{
  Truck ural;
  char* filename = "Drivers.txt";
  cout << line_Counter(filename) << endl;
  // Open filename and read it using a file pointer and a character
  // buffer. If file cannot be opened, report error and return with an
  // error code.
  char buff[32];
  FILE* file_pointer = fopen(filename, "r");
  if (file_pointer == NULL) {
    perror ("Error opening file");
    return -1;
  }
  // Read truck information from file and close file.
  fgets(ural.driver, 32, (FILE*)file_pointer);
  fgets(buff, 32, (FILE*)file_pointer);
  ural.petrol = atoi(buff);
  fgets(buff, 32, (FILE*)file_pointer);
  ural.money = atoi(buff);
  fgets(buff, 32, (FILE*)file_pointer);
  ural.fullMileage = atoi(buff);
  fgets(buff, 32, (FILE*)file_pointer);
  ural.emptyMileage = atoi(buff);
  fclose(file_pointer);
  // Display the information read from file.
  cout << "Truck driver is: " << ural.driver;
  cout << "Truck petrol is: " << ural.petrol << endl;
  cout << "Truck money is: " << ural.money << endl;
  cout << "Truck full mileage is: " << ural.full_mileage << endl;
  cout << "Truck empty mileage is: " << ural.empty_mileage << endl;
  cout << "The width of the box in truck is: " << ural.box.width << endl;
  return 0;
}

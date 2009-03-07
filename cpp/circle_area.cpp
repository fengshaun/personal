//calculating the area of a circle
//my first C++ code

//including iostream and string to the code and using standard namespace
#include <iostream>
using namespace std;

//defining PI value
#define PI 3.14159

//starting the code
int main()
{
  //declaring variables
  int a = 5;
  int b = 10;
  int c = 15;
  float radius;

  //first question to appear
  cout << "This program will calculate the area of a circle with given radius";
  cout << "\n";
  cout << "Please enter the radius of the circle:";
  
  //user input: user enters "radius" value
  cin >> radius;

  //declaring the formula to calculate the area of a circle
  float area = radius * radius * PI;

  //printing the result
  cout << area << endl;
  
}

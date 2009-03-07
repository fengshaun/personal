//the main calculator function to be used in ac_calc.cpp

#include <iostream>
#include <string>

using namespace std;

int main ();

void calc_Function ()
{

  //what shape?  user input
  string Shape;
  string circle = "circle";
  string triangle = "triangle";
  string rectangle = "rectangle";
  string square = "square";


  cout << "\nWhat shape do you want to work with? ";
  cin >> Shape;

  //if shape is not valid
  if ( Shape != circle && Shape != square && Shape != rectangle && Shape != triangle )
  {
    cout << "Invalid shape!   Go to help section for more information.\n\n";
    main ();
  }

  //if Shape is a circle
  if ( Shape == circle)
  {
    //declaring variables
    #define PI 3.14159
    string area_circumference;
    string area = "area";
    string circumference = "circumference";

    //what? area or circumference
    cout << "Do you want to calculate area or circumference? ";
    cin >> area_circumference;

    //if user wants area
    if (area_circumference == area)
    {
      //circle variables
      float radius;
      float area;

      //radius?  user input
      cout << "Enter the radius of the circle: ";
      cin >> radius;

      //declaring the formula to calculate the area of the circle
      area = radius * radius * PI;

      //printing the result
      cout << "The answer is:  " << area << endl;
    }

    //if user wants circumference
    if (area_circumference == circumference)
    {
      //circle variables
      float radius;
      float circumference;

      //radius?  user input
      cout << "Enter the radius of the circle: ";
      cin >> radius;

      //declaring the formula to calculate the circumference of the circle
      circumference = (radius * 2) * PI;

      //printing the results
      cout << "The answer is:  " << circumference << endl;
    }	//finished with circle area and circumference
  }

  //if Shape is a square
  if (Shape == square)
  {
    string area_circumference;
    cout << "Do you want to calculate the area or the circumference of the square?";

    cin >> area_circumference;

    string area = "area";
    string circumference = "circumference";

    //if user wants area
    if (area_circumference == area)
    {
      float side;
      float area;

      cout << "Enter the value of one side of the square: ";
      cin >> side;

      //declaring the formula
      area = side * side;

      cout << "The answer is:  " << area << endl;
    }

    //if user wants circumference
    if (area_circumference == circumference)
    {
      float side;
      float circumference;

      cout << "Enter the value of one side of the square: ";
      cin >> side;

      //declaring the formula
      circumference = side * 4;

      cout << "The answer is:  " << circumference << endl;
    }	//finished with square area and circumference
  }

  if (Shape == triangle)
  {
    string area_circumference;
    string area = "area";
    string circumference = "circumference";

    cout << "Do you want to calculate the area or circumference of the triangle? ";
    cin >> area_circumference;

    //if user wants area
    if (area_circumference == area)
    {
      float base;
      float height;
      float area;

      cout << "Enter the value of the base of the triangle: ";
      cin >> base;

      cout << "Enter the value of the height of the triangle: ";
      cin >> height;

      //declaring the formula to calculate the area of the triangle
      area = (base * height) / 2;

      cout << "The answer is:  " << area << endl;
    }

    //if user wants circumference
    if (area_circumference == circumference)
    {
      float side1;
      float side2;
      float side3;
      float circumference;

      cout << "Enter the value of first side of the triangle: ";
      cin >> side1;

      cout << "Enter the value of second side of the triangle: ";
      cin >> side2;

      cout << "Enter the value of third side of the triangle: ";
      cin >> side3;

      //declaring the formula to calculate the circumference
      circumference = side1 + side2 + side3;

      cout << "The answer is:  " << circumference << endl;
    }	//finished with triangle area and circumference
  }

  if (Shape == rectangle)
  {
    string area_circumference;
    string area = "area";
    string circumference = "circumference";

    cout << "Do you want to calculate the area or circumference of the rectangle? ";
    cin >> area_circumference;

    //if user wants area
    if (area_circumference == area)
    {
      float side1;
      float side2;
      float area;

      cout << "Enter the value of the length: ";
      cin >> side1;

      cout << "Enter the value of the width: ";
      cin >> side2;

      //declaring the formula
      area = side1 * side2;

      cout << "The answer is:  " << area << endl;
    }

    //if user wants circumference
    if (area_circumference == circumference)
    {
      float side1;
      float side2;
      float circumference;

      cout << "Enter the value of the first side: ";
      cin >> side1;

      cout << "Enter the value of the side adjacent to the first side: ";
      cin >> side2;

      //declaring the formula
      circumference = (side1 + side2) * 2;

      cout << "The answer is:  " << circumference << endl;
    }	 //finished with rectangle area and circumference 
  }
}

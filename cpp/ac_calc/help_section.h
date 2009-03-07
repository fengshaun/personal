//help function to be used in ac_calc.cpp

#include <iostream>
#include <string>

using namespace std;

void help_Function ()
{

  int q_num;

  cout << "\nYou are in help section...\n";
  cout << "To see a list of options for 'shape question' press 1\n";
  cout << "To see a list of options for 'area/circumference question' press 2\n";
  cout << "To see both options at the same time, type 12\n";
  cout << "[1/2/12]? ";

  cin >> q_num;

  switch (q_num)
  {
    case 1:

      cout << "\n\nThis is a list of options you have when asked 'what shape do you want to work with?: \n Please note that these values are all case sensitive and entering them inappropirately results in malprocessing by the program.\n\n";
      cout << "option:         what it does:\n";
      cout << "square		lets you to work with the area and/or circumference of a square\n";
      cout << "cirlce		lets you to work with the area and/or circumference of a circle\n";
      cout << "rectangle	lets you to work with the area and/or circumference of a rectangle\n";
      cout << "triangle 	lets you to work with the area and/or circumference of a triangle\n";

    break;

    case 2:

      cout << "\n\nThis is a list of options you have when asked 'what (area or circumference) do you want to calculate?:\n*Please note that these values are all case sensitive and etering them inappropriately results in malprocessing by the program.\n\n";
      cout << "option:         what it does:\n";
      cout << "area		lets you calculate the area of the given shape\n";
      cout << "circumference	lets you calculate the circumference of the given shape\n";

    break;

    case 12:

      cout << "\n\nThis is a list of options you have for both questions.\n*Please note that these values are all case sensitive and entering them inappropriately results in malprocessing by the program.\n\n";
      cout << "option:         what it does:\n";
      cout << "square		lets you to work with the area and/or circumference of a square\n";
      cout << "cirlce		lets you to work with the area and/or circumference of a circle\n";
      cout << "rectangle	lets you to work with the area and/or circumference of a rectangle\n";
      cout << "triangle 	lets you to work with the area and/or circumference of a triangle\n";
      cout << "area		lets you calculate the area of the given shape\n";
      cout << "circumference	lets you calculate the circumference of the given shape\n";

    break;

    default:
      cout << "invalid option, returning to program...\n";

    break;

  }
}

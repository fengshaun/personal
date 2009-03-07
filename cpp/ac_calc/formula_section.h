//forumula function to be used in ac_calc.cpp

#include <iostream>
#include <string>

using namespace std;

int main ();

void formula_Function()
{
  string square_area = "side * side";
  string square_circumference = "side * 4";
  string rectangle_area = "length * width";
  string rectangle_circumference = "(length + width) * 2";
  string circle_area =  "(radius^2) * 3.14159";
  string circle_circumference = "(radius * 2) * 3.14159";
  string triangle_area = "(base * height) / 2";
  string triangle_circumference = "side1 + side2 + side3";

  int which_formula;

  cout << "\nWhich formula do you want to be shown?  Type the number in front of the one you want to see.";
  cout << "\n1- square area \n2- square circumference \n3- rectangle area \n4- rectangle circumference \n5- circle area \n6- circle circumference \n7- triangle area \n8- triangle circumference \n";

  cin >> which_formula;

  switch (which_formula)
  {
    case 1:
      cout << "\n" << "The formula is:  " << square_area << endl;
    break;

    case 2:
      cout << "\n" << "The formula is:  " << square_circumference << endl;
    break;

    case 3:
      cout << "\n" << "The formula is:  " << rectangle_area << endl;
    break;

    case 4:
      cout << "\n" << "The formula is:  " << rectangle_circumference << endl;
    break;

    case 5:
      cout << "\n" << "The formula is:  " << circle_area << endl;
    break;

    case 6:
      cout << "\n" << "The formula is:  " << circle_circumference << endl;
    break;

    case 7:
      cout << "\n" << "The formula is:  " << triangle_area << endl;
    break;

    case 8:
      cout << "\n" << "The formula is:  " << triangle_circumference << endl;
    break;

    default:
      cout << "\n" << "Invalid option.  Returning to program...\n\n";
      main ();
    break;
  }
}

//this program is for calculating the area and circumference of given polygons

#include <iostream>
#include <string>
#include "help_section.h"
#include "calc_section.h"
#include "formula_section.h"

using namespace std;

void help_Function ();
void formula_Function ();
void calc_Function ();
void exit (int exitcode);

int main()
{

  cout << "This program calculates the area and/or circumference of the chosen polygon using given parameters.\n";


loop:

  cout << "\nIf you want to go to help section, press 1.\nIf you want to see the formulas used in this program, press 2.\nIf you want to calculate the area and/or circumference of a polygon, press 3.\n";

  int help_formula_prog;
  cin >> help_formula_prog;

  switch (help_formula_prog)
  {
    case 1:
      help_Function ();
    break;

    case 2:
      formula_Function ();
    break;

    case 3:
      calc_Function ();
    break;

    default:
      cout << "Invalid option.  Returning...\n\n";
      goto loop;
    break;
  }

  string y1 = "y";
  string n1 = "n";
  string y_n1;

exit_program:

 cout << "\n\nDo you want to exit the program? [y/n] ";
  cin >> y_n1;
  cout << "\n\n";

  if (y_n1 == "n")
  {
    goto loop;
  } 
  else if (y_n1 == "y") {
    void exit (int exitcode);
  } 
  else {
    cout << "Invalid option.";
    goto exit_program;
  }

}


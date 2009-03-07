#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
using namespace std;

void instructUser();
double doDivideZero(double &);




int main()
{
	instructUser();
	
	
	double displayedVal;
	double newEntry;
	char command_character ;

	
	displayedVal = 0.0;

	
	cout << "  Enter accepted Operator:" ;
	cin >> command_character;
	while (command_character != 'Q' || command_character != 'q')
{
		switch(command_character)
{
	case 'c':
		case 'C': displayedVal = 0.0;
				  break;
		case '+': cout << "  Enter Number:";
				  cin >> newEntry;
				  displayedVal = displayedVal + newEntry;
				  break;
		case '-': cout << "  Enter Number:";
				  cin >> newEntry;
				  displayedVal = displayedVal - newEntry;
				  break;
		case '*': cout << "  Enter Number:";
				  cin >> newEntry;
				  displayedVal = displayedVal * newEntry;
				  break;
		case '/': cout << "  Enter Number:";
			      cin >> newEntry;
				  displayedVal = displayedVal / newEntry;
				  if (newEntry == 0)
{
					  doDivideZero(displayedVal);
}
				  
				  break;
		case '^': cout << "  Enter Number:";
				  cin >> newEntry;
				  displayedVal = pow (displayedVal,newEntry);
				  break;
				  default : cout << "  Unacceptable Operator(" << command_character << ")" << endl;
}
		cout << "  The result so far is: " <<displayedVal<< endl;
		cout << "  Enter Operator:";
		cin >> command_character;
		
		
}




	system ("pause");
	return 0;
}

void instructUser()

{
		cout << "                    " <<endl;
		cout << "  ***************************************************************************" <<endl;
		cout << "  *  This program takes your input and selected mathematical operator       *" <<endl;
		cout << "  *  and returns the answer to the screen. If an illegal operator is        *" << endl;
		cout << "  *  selected, an error message will be displayed. Be careful which         *" <<endl;
		cout << "  *  operator you select because the program depends on you for input.      *" <<endl;
		cout << "  *  The only error check function it has, is for unacceptable opreators.   *" <<endl;
		cout << "  *  Acceptable operators are : (+ , - , / , * ,^,c). The character c sets  *" <<endl;
		cout << "  *  the value stored to ZERO. Enter Q to exit. ENJOY YOUR PROGRAM !!!!!!   *" <<endl;
		cout << "  ***************************************************************************" <<endl;
		cout << "                     " <<endl;



}

double doDivideZero(double &)
{
	double newEntry;
	double displayedVal;
	newEntry =0;
	displayedVal = 0.0;
	


	if (newEntry !=0)
{
		displayedVal = displayedVal / newEntry;
} else cout << "Wrong Operation, Cannot Divide by Zero" << endl;
	
		
		
	
	return 0;	
}

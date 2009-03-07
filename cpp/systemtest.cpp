//put the command you want to execute in system("yourcommand");
#include <cstdlib>  //adds system() functionality
#include <iostream>
using namespace std;

int main()
{
	cout << "Running Konversation (IRC Client), Kmail (Mail Client),\nKopete (Instant messenger), and Konqueror (Web Browser)..." << endl;
	system("cd /usr/bin && ./konversation && ./kmail && ./kopete && ./konqueror");
}

#include <iostream>
using namespace std;
 
void CalcAverage(int Amount, int PtrScores[], int &Total, float &Average);
void SortScores(int Amount, int PtrScores[]);
void PrintReport(int Amount, float Average, int Total, int PtrScores[]);
 
int main()
{
        int *PtrScores;
        int Amount,Total,hold;
        float Average;
 
        cout << "Enter the amount of scores you have: " << endl;
        cin >> Amount;
 
        PtrScores = new int[Amount];
 
        cout << "Enter the test scores: " << endl;
        for (int i=0; i < Amount; i++)
        {
                cin >> PtrScores[i];
        }
 
        cout << endl << "Unsorted Test Scores: " << endl;
        for (int i=0; i < Amount; i++)
        {
                cout << PtrScores[i] << " ";
        }
 
        CalcAverage(Amount,PtrScores,Total,Average);
        SortScores(Amount,PtrScores);
        PrintReport(Amount,Average,Total,PtrScores);
 
 
        cin >> hold;
        return 0;
}
 
void SortScores(int Amount, int PtrScores[])
{
        int temp;
 
				for ( int pass = 0; pass < Amount +1; pass++ ) {
					for (int i=0; i < Amount; i++) {
						if( PtrScores[i] > PtrScores[i+1] ) {
                        temp = PtrScores[i];
                        PtrScores[i] = PtrScores[i+1];
                        PtrScores[i+1] = temp;
						}
          }
				}
        cout << endl;
}
 
void CalcAverage(int Amount, int PtrScores[], int &total, float &Average)
{
 
        for(int i=0; i < Amount; i++)
        {
                total = total + PtrScores[i];
        }
 
        Average = total / Amount;
}
 
void PrintReport(int Amount, float Average, int Total, int PtrScores[])
{
        cout << "Sorted Test Scores: " << endl;
        for (int i=0; i < Amount; i++)
        {
                cout << PtrScores[i] << " ";
        }
 
        cout << endl << endl;
        cout << "Total Score is: " << Total << endl;
        cout << "Average Score is: " << Average;
}

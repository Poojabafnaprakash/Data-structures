/*

 Name: Pooja and Amrutha
 
*/



#include<iostream>
using namespace std;
int mul(int , int );
int main(){

	int x,y,z;
    double executionTime;
    clock_t tStart = clock();
		  cout << "Enter the integers to be multiplied" << endl;
		  cin >> x >> y ;
		  z = mul(x,y);
		  cout << "The product is: " << z << endl;
    executionTime = (double)(clock() - tStart)/(double)CLOCKS_PER_SEC;
    cout << "\nTime taken=" << executionTime << " milliseconds" << endl;
	return 0;

	}

int mul(int x, int y)
{
    return x * y;
}
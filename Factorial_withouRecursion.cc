/*
 
 Name: Pooja and Amrutha
 
 */



#include<iostream>
using namespace std;
long int fact(int);
int main(){
    
    long int j,f;
		  cout << "The the number to be factorised" << endl;
		  cin >> j;
    double executionTime;
    clock_t tStart = clock();
		  f = fact(j);
		  cout << "The Factorial of " << j << " is:" << f <<endl;
    executionTime = (double)(clock() - tStart)/(double)CLOCKS_PER_SEC;
    cout << "\nTime taken=" << executionTime << " milliseconds" << endl;
    return 0;
    
}

long int fact(int n)
{

    long int f = 1;
    for (int i = 1; i<=n; i++)
        f = f * i;
    return f;
    
}
/*
 
 Name: Pooja and Amrutha
 
 */



#include<iostream>
using namespace std;
int fibo(int);
int main(){
    
    int n,i;
          cout << "Enter the number of fibonacci series" << endl ;
          cin >> n;
    double executionTime;
    clock_t tStart = clock();
    cout << "The fibonacci series is:\n";
          for (i=0;i<n;i++)
          {
            cout << fibo(i) << " " ;
          }
    executionTime = (double)(clock() - tStart)/(double)CLOCKS_PER_SEC;
    cout << "\nTime taken=" << executionTime << " milliseconds" << endl;
    return 0;
    
}

int fibo(int i)
{
    if (i==0)
    {
        return 0;
    }
    else if (i==1)
    {
        return 1;
    }

    else 
    {
        return fibo(i-1)+fibo(i-2);
    }
}
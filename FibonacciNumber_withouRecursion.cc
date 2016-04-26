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
          cout << "The fibonacci Series is:" << endl;
          for (i=0;i<n;i++)
          {
            cout << fibo(i) << " " ;
          }
    executionTime = (double)(clock() - tStart)/(double)CLOCKS_PER_SEC;
    cout << "\nTime taken=" << executionTime << " milliseconds" << endl;
    return 0;
    
}

int fibo(int n)
{
    int a, b, c;
    a = 0;
    b = 1;
    if (n == 0)
        return a;
    else if (n == 1)
            return b;
    else
        {
        for( int i = 2; i <= n; i++)
            {
                c = a + b;
                a = b;
                b = c;
            }
        }
    return c;

}
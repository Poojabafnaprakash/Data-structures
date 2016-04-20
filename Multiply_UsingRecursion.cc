/*

 Name: Pooja and Amrutha
 
*/



#include<iostream>
using namespace std;
int mul(int , int );
int main(){

	int x,y,z;
		  cout << "Enter the integers to be multiplied" << endl;
		  cin >> x >> y ;
    double executionTime;
    clock_t tStart = clock();
		  z = mul(x,y);
		  cout << "The product is: " << z << endl;
    executionTime = (double)(clock() - tStart)/(double)CLOCKS_PER_SEC;
    cout << "\nTime taken=" << executionTime << " milliseconds" << endl;
	return 0;

	}

	int mul(int x, int y) 
	{
      if(y==0){
    	  return 0;
      }
      else if (y == 1)
	      {
	        return x;
	      }
	  else
	      {
	         return x + mul(x, y - 1);
	      }
	  }
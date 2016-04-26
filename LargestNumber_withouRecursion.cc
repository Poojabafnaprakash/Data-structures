/*
 
 Name: Pooja and Amrutha
 
 */



#include<iostream>
using namespace std;
int findLargest(int*,int);
int main(){
    
          int size,k;
          int *a;

      cout<< "Enter the size of the array" << endl;
      cin >> size;
      a = new int[size];
      cout<< "Enter the array elements" << endl;
      for(k=0;k<size;k++){
        cin >> a[k];
      }
    double executionTime;
    clock_t tStart = clock();
      cout << "The largest number in the array is: " << findLargest(a,size) << endl;
    executionTime = (double)(clock() - tStart)/(double)CLOCKS_PER_SEC;
    cout << "\nTime taken=" << executionTime << " milliseconds" << endl;
    return 0;
    
}

int findLargest(int *arr,int size)
{
    int max;
    max=arr[0];
    for (int i = 1; i < size; i++)
        {
            if( max < arr[i] )
                max = arr[i];
        }
    
    return max;
}
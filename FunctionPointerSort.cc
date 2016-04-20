/*
 * FuctionPointerSort.cpp
 *
 *  Created on: Mar 2, 2016
 *      Author: Amrutha and Pooja
 */

#include<iostream>
#include<stdlib.h>
using namespace std;

int asc(int[]);
int dsc(int[]);
int sortarray(int[],string);
int n;

int main(){

	int a[100];
    int k=0, num ;
    n=0;
	cout<< "Enter the numbers" << endl;

	for(k=0;k<100;k++){
        
        cin>>num;
        if (num>=0)
        {
		a[k]=num;
		n++;
        }
        else { break; }

	}

	string order;
	cout << "Enter ASC for ascending order or DSC for descending order." << endl;;
	cin >> order ;

	int (*p)(int[],string);
	p= sortarray;
	(*p)(a,order);


   return 0;
}

int sortarray(int array[] ,string order){

	int (*aof)(int[]);
	aof = asc;
	int (*dof)(int[]);
	dof = dsc;

    if(order=="ASC")
    	(*aof)(array);
    else if(order=="DSC")
    	(*dof)(array);
		else
			cout<<"Please Enter either ASC or DSC";


	return 0;

}

int asc(int a[])
{
	int i,j,temp;
		for(i=0;i<n-1;i++)
		    {
		        for(j=0;j<n-1;j++)
		           {
		               if(a[j+1]<a[j])
		                  {
		                      temp = a[j];
		                      a[j] = a[j+1];
		                      a[j+1] = temp;
		                    }
		            }
		 }
		int l;
                 cout << "The function signature is: " << __PRETTY_FUNCTION__ << endl;
                 cout << " The values in ASCENDING Order are: ";
		         for(l=0;l<n;l++)
                 {
		        	 cout << a[l] << " ";
		         }
    cout << endl;
    
		return 0;
}

int dsc(int a[])
{
	int i,j,temp;
		for(i=0;i<n-1;i++)
		    {
		        for(j=0;j<n-1;j++)
		           {
		               if(a[j+1]>a[j])
		                  {
		                      temp = a[j];
		                      a[j] = a[j+1];
		                      a[j+1] = temp;
		                    }
		            }
		 }
		int l;
		cout << "The function signature is: " << __PRETTY_FUNCTION__  << endl;
        cout << " The values in DESCENDING Order are: ";
				         for(l=0;l<n;l++)
                         {
				        	 cout << a[l] << " ";
				         }
    cout << endl;
		return 0;
}




/*
 
 Team number: 14
 Name1: Pooja Prakashchand      SJSU ID:010814258
 Name2: Amrutha Bellave         SJSU ID:010174229
 
 */


#include <iostream>
#include <stdlib.h>
using namespace std;
int const MAX_SIZE = 65536;

class arrayList {
	int list[MAX_SIZE], size;
	long int swapCount = 0 , compCount = 0 ;
public:
	arrayList(int);
	void createList();
	void displayList();
	void swap(int,int);
	void selectionSort(int);
	void getCount();
	void insertionSort(int);
};

arrayList::arrayList(int n){
	size = n;
}

    //Used to create the array
void arrayList::createList(){
	int i;
	for(i=0;i<size;i++){
		list[i]= rand()%MAX_SIZE;
	}
}

//USed to display the array
void arrayList::displayList(){
	int i;
	for(i=0;i<size;i++){
		cout << list[i] << " " ;
	}
	cout<< endl;
}

//Gets the count of the number of comparisions and the number of swaps
void arrayList::getCount(){
	cout << "Number of Swaps: " << swapCount << endl;
	cout << "Number of comparisons: " << compCount << endl;

}

//Implements the swaping function
void arrayList::swap(int first, int second){
	int temp;
	temp = list[first];
	list[first] = list[second];
	list[second] = temp;
	swapCount++;

}

//Implements the selection sort algorithm
void arrayList::selectionSort(int size){

    
    
    int maxIndex = 0, temp = 0, index = 0;
    for ( index = maxIndex; index < size; index++ ) {
        compCount++;
        if ( list[index] > list[maxIndex] ) {
            maxIndex = index;
        }
    }
    swapCount++;
    temp = list[size-1];
    list[size-1] = list[maxIndex];
    list[maxIndex] = temp;
    
    if ( size > 1 ) {
        selectionSort (--size) ;
    }

}

//Implements the Insertion Sort Algorithm
void arrayList::insertionSort(int length)
		{
        
        
        int i, key, j;
        for (i = 1; i < length; i++)
            {
            key = list[i];
            j = i-1;
            
            /* Move elements of arr[0..i-1], that are
             greater than key, to one position ahead
             of their current position */
            while (j >= 0 && list[j] > key)
                {
                    compCount++;
                    swapCount++;
                    list[j+1] = list[j];
                    j = j-1;
                }
            list[j+1] = key;
            }

		}

int main(){

    //Declarations
	int n, opr;
    double executionTime;
    clock_t tStart = clock();
    
    //Inputs the size of the list
	cout << "Enter the size of the list" << endl;
	cin >> n ;
	arrayList list1(n);
	list1.createList();
    
        //Displays the list before sorting
	cout << "The list before sorting is : " << endl;
	list1.displayList();
	cout << "Enter:\n 1 for selection sort\n 2 for insertion sort\n"  << endl;
	cin >> opr ;
	switch(opr)
    {

            case 1 :
                    {
                        //Implements the selection Sort algorithm
                        list1.selectionSort(n);
                    
                        //Display the sorted list
                        list1.displayList();
                    
                        //Calculates the time
                        executionTime = (double)(clock() - tStart)/(double)CLOCKS_PER_SEC;
                        cout << "Time taken=" << executionTime << " milliseconds" << endl;
                    
                        //Gets the count of comparisions and swaps
                        list1.getCount();
                        cout << endl;
                        break;
                    }
            case 2 : {
                        list1.insertionSort(n);
                
                        //Display the sorted list
                        list1.displayList();
                
                        //Calculates the time
                        executionTime = (double)(clock() - tStart)/(double)CLOCKS_PER_SEC;
                        cout << "Time taken=" << executionTime << " milliseconds" << endl;
                
                        //Gets the count of comparisions and swaps
                        list1.getCount();
                        cout << endl;
                        break;

                    }
	}
    
	return 0;

} //end of main

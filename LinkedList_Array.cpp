#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
using namespace std;
int const MAX_SIZE = 65536;


class LLNode {


      int arr[MAX_SIZE],size;

  public:
        LLNode();
        LLNode(int);
        void storeList();
        void displayList();
        int insertNode();
        int deleteNode();
        void nextNode();
        void countList();
        void nodeValue();
        void searchList();
        void operator=(const LLNode&);
        ~LLNode();
};

double PCFreq = 0.0;
__int64 CounterStart = 0;

void StartCounter()
{
    LARGE_INTEGER li;
    if(!QueryPerformanceFrequency(&li))
    cout << "QueryPerformanceFrequency failed!" << endl;

    PCFreq = double(li.QuadPart)/1000.0;

    QueryPerformanceCounter(&li);
    CounterStart = li.QuadPart;
}

double GetCounter()
{
    LARGE_INTEGER li;
    QueryPerformanceCounter(&li);
    return double(li.QuadPart-CounterStart)/PCFreq;
}

LLNode::LLNode(){
	size = MAX_SIZE;
	cout<< "A list of size " << MAX_SIZE << "is created";
}

LLNode::LLNode(int s) {
	size = s;
}


void LLNode::storeList(){
    if(size==0){
    	cout << "No nodes are created as size is 0" << endl;
    }
    else {
	int i;
    for(i=0;i<size;i++){
         arr[i]=rand()%MAX_SIZE;
       }
    }
}
 
void LLNode::displayList(){
	if(size==0){
	    	cout << "No elements to display as size is 0" << endl;
	    }
	 else {
     cout << "The list elements are:"  << endl;
     int j;
     for(j=0;j<size;j++){
        cout<< arr[j] << " " ;

        }
     cout<<endl;
	 }
}

int LLNode::deleteNode(){
	if(size==0){
	    	cout << "No nodes are available to delete as size is 0" << endl;
	     }
    else {
	     int DIdx , shift ;
	     cout << "Enter the node to be deleted" << endl;
	     cin >> DIdx ;
	     if ((DIdx>size-1)|| (DIdx<0)){
		      cout<< "Enter a valid index as only existing nodes can be deleted" << endl;
	        }
	     else {
		      for(shift=DIdx;shift<size-1;shift++){
			       arr[shift]= arr[shift+1];
		      }
		      arr[size-1]= 0;
		      size--;
	     }
    }
	return size;

}

int LLNode::insertNode()
{

    int NewIdx, NewVal, shift;
    cout << "Input the index to where the value has to be stored" << endl;
    cin >> NewIdx;

    if ((NewIdx > size) || (NewIdx < 0))
    {
        cout << "Enter a  valid index as nodes can be added only next to an existing node." << endl;
    }
    else
    {
        cout << "Enter the value to be stored" << endl;
        cin >> NewVal;
        for(shift = size; shift > NewIdx; shift--) {
            arr[shift] = arr[shift - 1];
        }
        arr[NewIdx] = NewVal;
        size++;
    }
    return size;
}

void LLNode::nodeValue(){
	if(size==0){
		    	cout << "No nodes to display as size is 0" << endl;
		 }
    else {
       int indx;
       cout << "Enter the node number" << endl;
       cin>> indx  ;
       if((indx < size) && (indx > -1)){
         cout << "The node value is: " << arr[indx] << endl;
       }
       else
    	   cout<<"index out of bound" << endl;
    }
}

void LLNode::searchList(){
	if(size==0){
		    	cout << "Nothing to search as size is 0" << endl;
		     }
	else {
	     int val, j,found =0,i;

	     cout<< "Enter the element value to get the node number"<< endl;
	     cin >> val ;

	     StartCounter();
	     for (i=0;i<size;i++){
		       if(arr[i]==val){
			       cout << "The node number with the value " << val << " is " << i << endl;
			       found = 1;
			       break;
		       }
	     }
	     for (i=0 ; i<1000;i++){
	    	 for(j=0;j<1000;j++){

	    	 }
	     }

         cout << "Time taken - " << GetCounter() << " microseconds" << endl;
         if(found < 1){
		     cout << "The value is not found in the list" << endl;

	     }
	}


}

void LLNode::nextNode(){

	if(size==0){
		    	cout << "No nodes can be found as size is 0" << endl;
		     }
	else {

	     int Indx;
	     cout<< "Enter the value of the node to find its next node" << endl;
	     cin >> Indx ;
	     if((Indx < size-1) && (Indx >= -1)){
	          cout << "The value of the node next to " << Indx << " is " << arr[Indx+1]<< endl;
	     }
	     else
	    	 cout << "Index out of bound" << cout;
	}
}

void LLNode::countList(){
	cout << "The list has " << size << " elements" << endl;
}

void LLNode::operator=( const LLNode& list2){
	int i;


	for (i=0;i<list2.size;i++){
		  arr[i]=list2.arr[i] ;
	}
	if(size > list2.size){
		for(i=list2.size;i<size;i++){
			  arr[i] = 0 ;
		}
	}
    size = list2.size;
}

LLNode::~LLNode(){

	cout << "List deleted" << endl;
}

int main(){


    char opr;
    int sz,sz2;

    cout<< "Enter the size of the list" << endl;
    cin >> sz;

    LLNode list(sz);
    list.storeList();




    while(1){
    	  cout << "#########################################################################" << endl;
          list.displayList();
          cout<< endl << "Specify the operation you want to perform on the list:- " << endl;
    	  cout<< "Enter 'i' to insert a new node, 'd' to delete a node, 'v' to get value of a node, 's' to search for a value, 'n' to get the next node, 'p' to print the list, 'c' to get the count of nodes,'l' to get a new list and to copy second list to first list, 'e' to exit" << endl;
          cin >> opr;

          switch (opr){

              case 'i': sz = list.insertNode();
                 break;

              case 'd': sz = list.deleteNode();
                 break;

              case 'v': list.nodeValue();
                 break;

              case 's': list.searchList();
                 break;

              case 'n': list.nextNode();
                 break;

              case 'p': list.displayList();
    		     break;

              case 'c': list.countList();
                 break;

              case 'l':{
            	  cout << "Enter the size of the new list" << endl;
            	  cin >> sz2;
            	  LLNode linkedList(sz2);
                  linkedList.storeList();
                  linkedList.displayList();
                  list = linkedList;
                  cout << "Lists after copying:" << endl;
                  list.displayList();
                  linkedList.displayList();
                  break;
              }

              case 'e':  list.~LLNode();
                          exit(0);
            	       	  break;

              default : cout << "Please enter a valid operation" << endl;



          }
    }

    return 0 ;
    }

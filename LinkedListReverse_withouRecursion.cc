
/*

 Team number: 14
 Name1: Pooja Prakashchand      SJSU ID:010814258
 Name2: Amrutha Bellave         SJSU ID:010174229
 
*/



#include<iostream>
#include<stdlib.h>
using namespace std;

class node
{
public:
    int data;
    node *next;
};

class LinkedList:public node
{
public:
      node *head;
      node *last;
    
LinkedList()
    {
        cout << "Constructor is being called\n";
        head=NULL;
        last=NULL;
    }
    
    void insertNode(node *&head, node *&last, int value);
    void insertNode(node *&head, node *&last, int value, int position);
    void Display(node *current);
    bool IsEmpty(node * head);
    void Reverse(node** head);
    ~LinkedList();
};

LinkedList::~LinkedList()
{
    cout << "Destructor is being called\n";
    node* temp = head;
    while(temp != NULL)
        {
        temp = temp->next;
        delete (head);
        head = temp;
        }
}

void LinkedList::insertNode(node *&head, node *&last, int value)
{
    node *temp;
    temp = new node;
    if (IsEmpty(head))
        {
            temp->data = value;
            temp->next = NULL;
            head = temp;
            last=temp;
        }
    else
        {
            temp->data = value;
            temp->next = NULL;
            last->next = temp;
            last=temp;
        }
}


void LinkedList::Reverse(node** head)
{
    node* prev   = NULL;
    node* current = *head;
    node* next;
    while (current != NULL)
        {
        next  = current->next;
        current->next = prev;
        prev = current;
        current = next;
        }
    *head = prev;
}

void LinkedList::Display(node *current)
{
    
    if(IsEmpty(current))
        cout << "No data is present" << endl;
    else
        {
        cout << "The list is: \n";
        while (current != NULL)
            {
            cout << current->data << endl;
            current=current->next;
            }
        }
    
}

bool LinkedList::IsEmpty(node * head)
{
    if (head == NULL)
        return true;
    else
        return false;
}

int main()
{
    LinkedList lists;
    int choice;
    int num, i, value;
    double executionTime;
    clock_t tStart = clock();
    
    do{
        cout << "\nEnter the choice of operation on linked list: \n 1:Insert at the end \n 2:Display \n 3:Reverse \n 4:Exit" << endl;
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter the number of values" << endl;
                cin >> num;
                for(i=0;i<num;i++ )
                    {
                        value=rand()%65536;
                        lists.insertNode(lists.head, lists.last,value);
                    }
                break;
            case 2:
                lists.Display(lists.head); break;
            case 3:
                cout << "The Reversed List is:" << endl;
                lists.Reverse(&lists.head);
                lists.Display(lists.head);
                executionTime = (double)(clock() - tStart)/(double)CLOCKS_PER_SEC;
                cout << "\nTime taken=" << executionTime << " milliseconds" << endl; break;
            case 4:
                lists.~LinkedList();
                exit(0); break;
            default:
                cout << "Enter the right choice" << endl;
            }
    }while (choice !=4);
    return 0;
}
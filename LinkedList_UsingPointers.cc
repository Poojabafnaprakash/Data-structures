
/*

 Team number: 14
 Name1: Pooja Prakashchand      SJSU ID:010814258
 Name2: Amrutha Bellave         SJSU ID:010174229
 
*/



#include<iostream>
#include<time.h>
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
    void deleteNode(node *&head, node *&last);
    void Display(node *current);
    bool IsEmpty(node * head);
    int countList(node *current);
    void searchValue(node *current, int valueToBeSearched);
    void nextNode(int position, node *current);
    LinkedList& operator=(LinkedList &LList);
    
    
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



void LinkedList::insertNode(node *&head, node *&last, int value, int position)
{
    node *temp1, *temp2;
    int i,count=0;
    temp1 = new node;
    temp2 = new node;
    temp1->data = value;
    temp1->next = NULL;
    
    if (position==1)
        {
            temp1->next = head;
            head = temp1;
            last = temp1;
            return;
        }
    else
        {
            temp2=head;
            for (i=0;i<position-2;i++)
                {
                    temp2 = temp2->next;
                }
        
                temp1->next = temp2->next;
                temp2->next = temp1;
        
        
        }
}


void LinkedList::deleteNode(node *&head, node *&last)
{
    node *temp;
    if(IsEmpty(head))
        cout << "No data is present" << endl;
    else if (head == last)
        {
            cout << "The deleted data is: " << head->data << endl;
            delete head;
            head = NULL;
            last = NULL;
        }
    else
        {
            temp = head;
            head = head->next;
            cout << "The deleted data is: " << temp->data << endl;
            delete temp;
        }
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

int LinkedList::countList(node *current)
{
    int count=0;
    if(IsEmpty(current))
        cout << "The Count is:" << count << endl;
    else
        {
        cout << "The Count is: \n";
        while (current != NULL)
            {
            current=current->next;
            count++;
            }
        cout << count << endl;
        }
    return count;
}


void LinkedList::searchValue(node *current, int valueToBeSearched)
{
    bool flag=false;
    int position = 0;
    if(IsEmpty(current))
        cout << "The List is empty" << endl;
    else
        {
        
        for( position=0;current != NULL; position++)
            {
                if(current->data == valueToBeSearched)
                    {
                        position = position + 1;
                        cout << "The searched value " << valueToBeSearched << " is at Position:";
                        cout << position << endl;
                        flag=true;
                        break;
                    }
                current=current->next;
            }
        }
    if( flag == false)
        cout << "Value not Found\n";
}


void LinkedList::nextNode(int position, node *current)
{
    int i;
    if(IsEmpty(current))
        cout << "The list is empty" << endl;
    else
        {
                for (i=0;i<position-1;i++)
                    {
                        current = current->next;
                    }
        
        if(current->next!=NULL)
            {
                cout << "The current node value is:" << current->data << endl;
                current=current->next;
                cout << "The next node value is:" << current->data << endl;
            }
        else
            {
                cout << "There is no next element\n";
            }
        }
 
}

LinkedList& LinkedList::operator=(LinkedList &LList)
{
    node *last=LList.last;
    node *current = LList.head;
        if(IsEmpty(current))
          cout << "The List is empty";
    if(this != &LList)
        {
        while (current->next != NULL)
            {
                node* newlink = new node;
                newlink->data = current->data;
                newlink->next=current->next;
                head = newlink;
                current = current->next;
            }
        }
    return *this;
}


int main()
{
    LinkedList lists, copyList;
    int choice;
    int num, i, value, serValue, position,nextPosition;
    double executionTime;
    clock_t tStart = clock();
  
    
    do{
        cout << "\nEnter the choice of operation on linked list: \n 1:Insert at the end \n 2:Delete \n 3:Display \n 4:Count the list \n 5:Search the list \n 6:Find the Next Node \n 7:Insert at a position \n 8:CopyList \n 9:Exit" << endl;
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
                 copyList = lists;
                break;
            case 2:
                lists.deleteNode(lists.head, lists.last); break;
            case 3:
                lists.Display(lists.head); break;
            case 4:
                lists.countList(lists.head);break;
            case 5:
                cout << "Enter the value to be searched for:\n";
                cin >> serValue;
                lists.searchValue(lists.head, serValue);
                executionTime = (double)(clock() - tStart)/(double)CLOCKS_PER_SEC;
                cout << "Time taken=" << executionTime << " milliseconds" << endl;
                break;
            case 6:
                cout << "Enter the position to get the next node value\n";
                cin >> nextPosition;
                lists.nextNode(nextPosition,lists.head); break;
            case 7:
                cout << "Enter the position for the value to be inserted:\n";
                cin >> position;
                value=rand()%65536;
                lists.insertNode(lists.head, lists.last,value, position);
                break;
            case 8:
                copyList = lists;
                cout << "\nCopy using Overloaded = Operator\n";
                copyList.Display(lists.head); break;
            case 9:
                lists.~LinkedList();
                exit(0); break;
            default:
                cout << "Enter the right choice" << endl;
            }
    }while (choice !=9);
    return 0;
}
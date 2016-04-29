/*
 
 Team number: 14
 Name1: Pooja Prakashchand      SJSU ID:010814258
 Name2: Amrutha Bellave         SJSU ID:010174229

 */


#include <iostream>
#include <stack>
#include<time.h>

using namespace std;


class BinaryTree
{
private:
    
        //declare a structure for a node to implement Binary Search Tree and Balanced Binary Search Tree
    struct Node{
        int data;
        Node* LeftLink;
        Node* RightLink;
        int height;
    };
    
        //Inorder display with recursion
    void InorderPrivate(Node* ptr)
    {
    if(root != NULL)
        {
        if ( ptr->LeftLink != NULL)
            {
            InorderPrivate(ptr->LeftLink);
            }
        cout << ptr->data << " ";
        if (ptr->RightLink != NULL)
            {
            InorderPrivate(ptr->RightLink);
            }
        
        }
    else
        {
        cout << "The Tree is empty\n";
        }
    }
    
    
        //Post Order display with recursion
    void PostOrderPrivate(Node* ptr)
    {
    if(root != NULL)
        {
            if ( ptr->LeftLink != NULL)
            {
                PostOrderPrivate(ptr->LeftLink);
            }
        
            if (ptr->RightLink != NULL)
            {
                PostOrderPrivate(ptr->RightLink);
            }

            cout << ptr->data << " ";
        }
    else
        {
        cout << "The Tree is empty\n";
        }
    }

        //Pre order display with recursion
    void PreOrderPrivate(Node* ptr)
    {
    if(root != NULL)
        {
        cout << ptr->data << " ";
            if( ptr->LeftLink != NULL)
            {
                PreOrderPrivate(ptr->LeftLink);
            }
            if (ptr->RightLink != NULL)
            {
                PreOrderPrivate(ptr->RightLink);
            }
        
        }
    else
        {
        cout << "The Tree is empty\n";
        }
    }
        //to remove the root match in BST
    void RemoveRootMatch()
    {
    
    if(root != NULL)
        {
        Node* delPtr =root;
        int rootData = root->data;
        int SValueInRSubTree;
        
            //Case 0 = 0 children
        
        if(root->LeftLink == NULL && root->RightLink == NULL)
            {
            root = NULL;
            delete delPtr;
            }
        
            //Case 1 = 1 child
        else if (root->LeftLink == NULL && root->RightLink != NULL)
            {
            root = root->RightLink;
            delPtr->RightLink = NULL;
            delete delPtr;
            cout << "The root node (" << rootData << ") is deleted.\n " << endl;
            }
        else if (root->LeftLink != NULL && root->RightLink == NULL)
            {
            root = root->LeftLink;
            delPtr->LeftLink = NULL;
            delete delPtr;
            cout << "The root node (" << rootData << ") is deleted.\n The new Root is " << root->data  << endl;
            }
        
            //case 2 = 2 children
        else
            {
            SValueInRSubTree = FindSmallestPrivate(root->RightLink);
            RemoveNodePrivate(SValueInRSubTree, root);
            root->data = SValueInRSubTree;
            cout << "The Root value (" << rootData << ") was deleted" << endl;
            }
        
        }
    else
        {
        cout << "Tree is empty, Cant remove";
        }
    }
    
    void removeMatch(Node* parent, Node* match, bool LeftLink)
    {
    if(root !=  NULL)
        {
        Node* delPtr;
        int matchValue = match->data;
        int SmallestInRightSubTree ;
        
            //case 0: 0 children
        if(match->LeftLink == NULL && match->RightLink == NULL)
            {
            delPtr = match;
            LeftLink == true ? parent->LeftLink = NULL: parent->RightLink = NULL;
            delete delPtr;
            cout << "The root " << matchValue <<" was deleted" << endl;
            }
        
            //Case 1 = 1 child
        else if (match->LeftLink == NULL && root->RightLink != NULL)
            {
            LeftLink == true ? parent->LeftLink = match->RightLink: parent->RightLink = match->RightLink;
            match->RightLink = NULL;
            delPtr = match;
            delete delPtr;
             cout << "The root " << matchValue <<" was deleted" << endl;
            }
        else if (match->LeftLink == NULL && root->RightLink != NULL)
            {
            LeftLink == true ? parent->LeftLink = match->LeftLink: parent->RightLink = match->LeftLink;
            match->RightLink = NULL;
            delPtr = match;
            delete delPtr;
            cout << "The root " << matchValue <<" was deleted" << endl;
            }
        
            //case 2 = 2 children
        else
            {
            SmallestInRightSubTree = FindSmallestPrivate(match->RightLink);
            RemoveNodePrivate(SmallestInRightSubTree, match);
            match->data = SmallestInRightSubTree;
            cout << "The Root value " << matchValue << " was deleted" << endl;
            }
        
        }
    else
        {
        cout << "Cannot remove as tree is empty\n";
        }
    }
    
        //insert the node in a tree for Binary Search Tree
    void CreateTreePrivate(Node* ptr, int value)
    {
    if (isEmpty(root))
        {
        root = InsertNode(value);
        }
    else if ( value == ptr->data ){
        cout << "Number already present" << endl;
    }
    
    else if ( value < ptr->data)
        {
        if (ptr->LeftLink != NULL)
             CreateTreePrivate(ptr->LeftLink, value);
        else
            ptr->LeftLink = InsertNode(value);
        }
    else
        {
        if (ptr->RightLink != NULL)
            CreateTreePrivate(ptr->RightLink, value);
        else
            ptr->RightLink = InsertNode(value);
        }
    }
    
    
        //used to get the smallest element
    int FindSmallestPrivate(Node* ptr)
    {
        if(root == NULL)
            {
            cout << "The tree is empty" << endl;
            return -1000;
            }
    else
        {
        if(ptr->LeftLink !=NULL)
            return FindSmallestPrivate(ptr->LeftLink);
        else
            return ptr->data;
        }
    }
    
        //used to remove the node
    void RemoveNodePrivate(int value, Node* parent)
    {
        if(!isEmpty(root))
            {
                if(value == root->data)
                    {
                    RemoveRootMatch();
                    }
            else if( value < parent->data  && parent->LeftLink != NULL)
                {
                    if(parent->LeftLink->data == value)
                        {
                        removeMatch(parent, parent->LeftLink, true);
                        }
                else
                    RemoveNodePrivate(value, parent->LeftLink);
                }
                    else if( value > parent->data  && parent->RightLink != NULL)
                        {
                            if(parent->RightLink->data == value)
                                {
                                removeMatch(parent, parent->RightLink, false);
                                }
                            else
                                RemoveNodePrivate(value, parent->RightLink);
                        }
            else
                {
                cout << " The value " << value << " was not found in the tree" << endl;
                }
            }
        else
            {
                cout << "The tree is Empty" << endl;
            }
    }
    
public:
 Node* root;
    
        //constructor
    BinaryTree()
    {
        root = NULL;
    }
        //destuctor
    ~BinaryTree()
    {
        cout << "Calling the destructor\n" << endl;
    }
    
    bool isEmpty(Node* root)
    {
        if (root == NULL)
            return 1;
        else return 0;
    }
    
        //used to create a node
    Node* InsertNode(int d)
    {
        Node* newnode = new Node;
        newnode->data = d;
        newnode->RightLink = NULL;
        newnode->LeftLink = NULL;
        newnode->height = 1;
        return newnode;
    
    }
    
    
        //creates the tree
    void CreateTree(int value)
    {
    
        CreateTreePrivate(root,value);
    
    }
        //display in order
    void InorderDisplay()
    {
        InorderPrivate(root);
    }
    
        //display pre order
    void PreOrderDisplay()
    {
        PreOrderPrivate(root);
    }
    
        //post order
    void PostOrderDisplay()
    {
        PostOrderPrivate(root);
    }
    
        //used for search
    void search(int num)
    {
    Node* head=root;
    while (head!=NULL)
        {
        if (head->data == num)
            break;
        else if (num > head->data)
            head=head->RightLink;
        else head=head->LeftLink;
        }
    if (head==NULL)
        cout << "Number not present" << endl;
    else if (head->data==num)
        cout << "Number is present" << endl;
        
    }
    
        //used to delete the node in a BST
    void deleteNode(int num)
    {
        RemoveNodePrivate(num, root);
    }
    
    int HeightOfTree(Node* n)
    {
        if (n == NULL)
            return 0;
    else
        {
            int left = HeightOfTree(n->LeftLink);
            int right = HeightOfTree(n->RightLink);
    
            if (left > right)
                return (left + 1);
            else return (right + 1);
        }
    }
    
        //counts the number of nodes
    int countNodes(Node* p)
    {
    if( p == NULL)
        return(0);
    else
        if( p->LeftLink == NULL && p->RightLink == NULL)
            return(1);
        else
            return(1 + (countNodes(p->LeftLink) + countNodes(p->RightLink)));
    }
    
        //gets the number of leaves
    int GetLeafCount(Node* n)
    {
    if(n == NULL)
        return 0;
    else if(n->LeftLink==NULL && n->RightLink==NULL)
        return 1;
    else return GetLeafCount(n->LeftLink) + GetLeafCount(n->RightLink);
    }
    
        //used to copy the BST
    Node* copyBST(Node* OTree, Node *parent){
        
        if (OTree == NULL) //base case to end recursion when at tree end
            return NULL;
        
            //create the node and set the new key to original
        struct Node* newTree = new Node;
        newTree->data = OTree->data;
        
            // Just call recursively to copy the subtrees:
        newTree->LeftLink = copyBST(OTree->LeftLink, newTree);
        newTree->RightLink = copyBST(OTree->RightLink, newTree);
        
        return newTree;
    }
    
        //Iterative Preorder display
    void iterativePreorder(Node *root)
    {
    if (root==NULL)
        return;
    
        // Create an empty stack and push root to it
    stack<Node*> nodeStack;
    nodeStack.push(root);
    
    /* Pop all items one by one. Do following for every popped item
     a) print it
     b) push its right child
     c) push its left child
     Note that right child is pushed first so that left is processed first */
    while (nodeStack.empty() == false)
        {
            // Pop the top item from stack and print it
        struct Node *node = nodeStack.top();
        cout<<node->data<<" ";
        nodeStack.pop();
        
            // Push right and left children of the popped node to stack
        if (node->RightLink)
            nodeStack.push(node->RightLink);
        if (node->LeftLink)
            nodeStack.push(node->RightLink);
        }
    }
    
        //iterative post order display
    void iterativePostorder(Node *root)
    {
    if (!root) return;
    stack<Node*> s;
    s.push(root);
    struct Node *prev = NULL;
    while (!s.empty())
        {
        struct Node *curr = s.top();
        if (!prev || prev->LeftLink == curr || prev->RightLink == curr)
            {
            if (curr->LeftLink)
                s.push(curr->LeftLink);
            else if (curr->RightLink)
                s.push(curr->RightLink);
            }
        else if (curr->LeftLink == prev)
            {
            if (curr->RightLink)
                s.push(curr->RightLink);
            }
        else
            {
            cout << curr->data << " ";
            s.pop();
            }
        prev = curr;
        }
    }
    
        //iterative inorder display
    void iterativeInorder(Node *root)
    {
    stack<Node*> s;
    struct Node *current = root;
    bool done = false;
    while (!done)
        {
        if (current)
            {
            s.push(current);
            current = current->LeftLink;
            }
        else 
            {
            if (s.empty()) 
                {
                done = true;
                } 
            else 
                {
                current = s.top();
                s.pop();
                cout << current->data << " ";
                current = current->RightLink;
                }
            }
        }
    }
    
        //gets the maximum node value
    int max(int a, int b)
    {
    return (a > b)? a : b;
    }
    
        //right rotate the AVL tree
    struct Node *rightRotate(struct Node *y)
    {
    struct Node *x = y->LeftLink;
    struct Node *T2 = x->RightLink;
    
        // Perform rotation
    x->RightLink = y;
    y->LeftLink = T2;
    
        // Update heights
    y->height = max(HeightOfTree(y->LeftLink), HeightOfTree(y->RightLink))+1;
    x->height = max(HeightOfTree(x->LeftLink), HeightOfTree(x->RightLink))+1;
    
        // Return new root
    return x;
    }
    
        // Get Balance factor of node N
    int getBalance(struct Node *N)
    {
    if (N == NULL)
        return 0;
    return HeightOfTree(N->LeftLink) - HeightOfTree(N->RightLink);
    }
    
    
        //Left Rotate the AVL tree
    struct Node *leftRotate(struct Node *x)
    {
    struct Node *y = x->RightLink;
    struct Node *T2 = y->LeftLink;
    
        // Perform rotation
    y->LeftLink = x;
    x->RightLink = T2;
    
        //  Update heights
    x->height = max(HeightOfTree(x->LeftLink), HeightOfTree(x->RightLink))+1;
    y->height = max(HeightOfTree(y->LeftLink), HeightOfTree(y->RightLink))+1;
    
        // Return new root
    return y;
    }
    
    struct Node* insert(struct Node* node, int key)
    {
    /* 1.  Perform the normal BST rotation */
    if (node == NULL)
        return(InsertNode(key));
    
    if (key < node->data)
        node->LeftLink  = insert(node->LeftLink, key);
    else
        node->RightLink = insert(node->RightLink, key);
    
    /* 2. Update height of this ancestor node */
    node->height = max(HeightOfTree(node->LeftLink), HeightOfTree(node->RightLink)) + 1;
    
    /* 3. Get the balance factor of this ancestor node to check whether
     this node became unbalanced */
    int balance = getBalance(node);
    
        // If this node becomes unbalanced, then there are 4 cases
    
        // Left Left Case
    if (balance > 1 && key < node->LeftLink->data)
        return rightRotate(node);
    
        // Right Right Case
    if (balance < -1 && key > node->RightLink->data)
        return leftRotate(node);
    
        // Left Right Case
    if (balance > 1 && key > node->LeftLink->data)
        {
        node->LeftLink =  leftRotate(node->LeftLink);
        return rightRotate(node);
        }
    
        // Right Left Case
    if (balance < -1 && key < node->RightLink->data)
        {
        node->RightLink = rightRotate(node->RightLink);
        return leftRotate(node);
        }
    
    /* return the (unchanged) node pointer */
    return node;
    }
    
    
    
    struct Node * minValueNode(struct Node* node)
    {
    struct Node* current = node;
    
    /* loop down to find the leftmost leaf */
    while (current->LeftLink != NULL)
        current = current->LeftLink;
    
    return current;
    }
    
    
        //TO delete a note in a Balanced Binary Search Tree
    struct Node* deleteNodeBalancedTree(struct Node* root, int key)
    {
        // STEP 1: PERFORM STANDARD BST DELETE
    
    if (root == NULL)
        return root;
    
        // If the key to be deleted is smaller than the root's key,
        // then it lies in left subtree
    if ( key < root->data )
        root->LeftLink = deleteNodeBalancedTree(root->LeftLink, key);
    
        // If the key to be deleted is greater than the root's key,
        // then it lies in right subtree
    else if( key > root->data )
        root->RightLink = deleteNodeBalancedTree(root->RightLink, key);
    
        // if key is same as root's key, then This is the node
        // to be deleted
    else
        {
            // node with only one child or no child
        if( (root->LeftLink == NULL) || (root->RightLink == NULL) )
            {
            struct Node *temp = root->LeftLink ? root->LeftLink : root->RightLink;
            
                // No child case
            if(temp == NULL)
                {
                temp = root;
                root = NULL;
                }
            else // One child case
                *root = *temp; // Copy the contents of the non-empty child
            
            delete temp;
            }
        else
            {
                // node with two children: Get the inorder successor (smallest
                // in the right subtree)
            struct Node* temp = minValueNode(root->RightLink);
            
                // Copy the inorder successor's data to this node
            root->data = temp->data;
            
                // Delete the inorder successor
            root->RightLink = deleteNodeBalancedTree(root->RightLink, temp->data);
            }
        }
    
        // If the tree had only one node then return
    if (root == NULL)
        return root;
    
        // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE
    root->height = max(HeightOfTree(root->LeftLink), HeightOfTree(root->RightLink)) + 1;
    
        // STEP 3: GET THE BALANCE FACTOR OF THIS NODE (to check whether
        //  this node became unbalanced)
    int balance = getBalance(root);
    
        // If this node becomes unbalanced, then there are 4 cases
    
        // Left Left Case
    if (balance > 1 && getBalance(root->LeftLink) >= 0)
        return rightRotate(root);
    
        // Left Right Case
    if (balance > 1 && getBalance(root->LeftLink) < 0)
        {
        root->LeftLink =  leftRotate(root->LeftLink);
        return rightRotate(root);
        }
    
        // Right Right Case
    if (balance < -1 && getBalance(root->RightLink) <= 0)
        return leftRotate(root);
    
        // Right Left Case
    if (balance < -1 && getBalance(root->RightLink) > 0)
        {
        root->RightLink = rightRotate(root->RightLink);
        return leftRotate(root);
        }
    
    return root;
    }
    
    
};

int main()
{
    BinaryTree tree,CopyTree, BalancedTree;
    int choice;
    int value,num,i;
    int height, countNode, countLeaf;
    double executionTime;
    clock_t tStart = clock();
    
        while (1)
        {
            cout << "\nEnter the choice\n1: To Check if tree is empty\n2: To insert a node in a Binary Search Tree\n3: To Traverse the tree in Inorder(with recursion)\n4: To Traverse the tree in Pre order(with recursion)\n5: To Traverse the tree in Post Order(with recursion)\n6: Search a value\n7: To delete a value\n8: To find the height of the tree\n9: To  count number of nodes in the BST\n10: To count the number of leaves in the BST\n11: To copy BST\n12: To Traverse the tree in Inorder(without recursion)\n13: To Traverse the tree in Pre order(without recursion)\n14: To Traverse the tree in Post Order(without recursion)\n15: Sort the Binary Search Tree\n16: Balanced Binary tree-insert and display\n17: Delete the node from balanced Binary Tree\n18: Pre-order display of Balanced binary tree\n" ;
            cin >> choice;

        switch(choice)
            {
                case 1:if (tree.isEmpty(tree.root))
                            cout << "The Tree is empty" << endl;
                        else  cout << "The Tree is not empty" << endl;break;
                case 2: cout << "Enter the number of values" << endl;
                        cin >> num;
                        for(i=0;i<num;i++ )
                            {
                            value=rand()%65536;
                            tree.CreateTree(value);
                            }break;
                case 3: cout << "Inorder Display\n";
                        tree.InorderDisplay(); cout << endl;
                        executionTime = (double)(clock() - tStart)/(double)CLOCKS_PER_SEC;
                        cout << "Time taken=" << executionTime << " milliseconds" << endl;break;
                case 4: cout << "Pre Order Display\n";
                        tree.PreOrderDisplay(); cout << endl;
                        executionTime = (double)(clock() - tStart)/(double)CLOCKS_PER_SEC;
                        cout << "Time taken=" << executionTime << " milliseconds" << endl;break;
                case 5: cout << "Post Order Display\n";
                        tree.PostOrderDisplay(); cout << endl;
                        executionTime = (double)(clock() - tStart)/(double)CLOCKS_PER_SEC;
                        cout << "Time taken=" << executionTime << " milliseconds" << endl;break;
                case 6: cout << "Enter a value to be searched\n";
                        cin >> value;
                        tree.search(value);
                        executionTime = (double)(clock() - tStart)/(double)CLOCKS_PER_SEC;
                        cout << "Time taken=" << executionTime << " milliseconds" << endl;break;
                case 7: cout << "Enter value to be deleted\n";
                        cin >> value;
                        tree.deleteNode(value);break;
                case 8: cout << "The height is ";
                        height = tree.HeightOfTree(tree.root);
                        cout << height << endl; break;
                case 9: cout << " The count of the nodes in the BST is ";
                        countNode = tree.countNodes(tree.root);
                        cout << countNode << endl; break;
                case 10:cout << " The count of the leaves in the BST is ";
                        countLeaf = tree.GetLeafCount(tree.root);
                        cout << countLeaf << endl; break;
                case 11:CopyTree.root = CopyTree.copyBST(tree.root,CopyTree.root);
                        cout << "display of copy Tree in in-order\n";
                        CopyTree.InorderDisplay(); break;
                case 12:cout << "Inorder Display\n";
                        tree.iterativeInorder(tree.root); cout << endl;break;
                case 13:cout << "Pre Order Display\n";
                        tree.iterativePreorder(tree.root); cout << endl;break;
                case 14:cout << "Post Order Display\n";
                        tree.iterativePostorder(tree.root); cout << endl;break;
                case 15:cout << "The Tree in Sorted Order:";
                        tree.InorderDisplay(); break;
                case 16:cout << "Enter the number of values" << endl;
                        cin >> num;
                        for(i=0;i<num;i++ )
                            {
                                value=rand()%65536;
                                BalancedTree.root = BalancedTree.insert(BalancedTree.root, value);
                            }break;
                case 17: cout << "Enter the number to be deleted for Balanced Binary Tree\n";
                        cin >> value;
                        BalancedTree.root = BalancedTree.deleteNodeBalancedTree(BalancedTree.root, value);break;
                case 18: cout << "pre-order display of Balanced tree\n";
                        BalancedTree.PreOrderDisplay(); break;
                default : exit(0); break;
                
            }
        }
    
    return 0;
}
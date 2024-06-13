#include <iostream>
#include <string>
using namespace std;


class Node
{
public:
    string info;
    Node* leftchild;
    Node* rightchild;

    // Contructor for the node class
    Node(string i, Node* l, Node* r)
    {

        info = i;
        leftchild = l;
        rightchild = r;
    }

};

class BinaryTree
{
public:
    Node* ROOT;

    BinaryTree()
    {
        ROOT = nullptr; // initialiring ROOT to null
    }

    void insert(string element) // insert a node in the Binary search tree
    {
        Node* newNode = new Node(element, nullptr, nullptr); // Allocate memory for the new node
        newNode->info = element; // assign value to the data field of the new node
        newNode->leftchild = nullptr; // make the field child of the new node point to NULL
        newNode->rightchild = nullptr; // Make the right child of the new node point to NULL

        Node* parent = nullptr;
        Node* currentNode = nullptr;
        search(element, parent, currentNode); // locate the node which will be the parent of the node to be insert

        if (parent == nullptr) // if the parent is NULL(tree is empty)
        {
            ROOT - newNode; // mark the new node as ROOt
            return; // Exit
        }

        if (element < parent->info) // If the value in the data field of the new node is less than that of the 
        {
            parent->leftchild = newNode; // Make the left child of the parent point to the new node
        }
        else if (element > parent->info) // if the value in the data field of the  new node is greater than that
        {
            parent->rightchild = newNode; // Make the right child of the parent point to new node
        }
    }

    void search(string element, Node*& parent, Node*& currentNode)
    {
        //this function searches the currentNode of the specifield Node as null as the current Node of itw parrent
        currentNode = ROOT;
        parent = nullptr;
        while ((currentNode != nullptr) && (currentNode->info != element))
        {
            parent = currentNode;
            if (element < currentNode->info)
                currentNode = currentNode->leftchild;
            else
                currentNode = currentNode->rightchild;
        }
    }

    void inorder(Node* ptr)
    {
        if (ROOT == nullptr)
        {
            cout << "tree is empty" << endl;
            return; if (ptr != nullptr)
            {
                inorder(ptr->leftchild);
                cout << ptr->info << " ";
                inorder(ptr->rightchild);
            }
        }
    }

    void preorder(Node* ptr)
    {
        if (ROOT == nullptr)
        {
            cout << "tree is empty" << endl;
            return; if (ptr != nullptr)
            {
                cout << ptr->info << " ";
                preorder(ptr->leftchild);
                preorder(ptr->rightchild);
            }
        }
    }

    void postorder(Node* ptr)
    {
        if (ROOT == nullptr)
        {
            cout << "tree is empty" << endl;
            return; if (ptr != nullptr)
            {
                postorder(ptr->leftchild);
                postorder(ptr->rightchild);
                cout << ptr->info << " ";
            }
        }
    }
};

int main()
{
    BinaryTree x;
    while (true)
    {
        cout << "\nMenu" << endl;
        cout << "1. Implemented insert operation" << endl;
        cout << "2. Perform inorder traversal" << endl;
        cout << "3. Perform preorder traversal" << endl;
        cout << "4. Perform postorder traversal" << endl;
        cout << "5. exit" << endl;
        cout << "\nEnter your choice (1-) : ";

        char ch;
        cin >> ch;
        cout << endl;

        switch (ch)
        {
        case '1':
        {
            cout << "Enter a word; ";
            string word;
            cin >> word;
            x.insert(word);
            break;
        }
        case '2':
        {
            x.inorder(x.ROOT);
            break;
        }
        case '3':
        {
            x.preorder(x.ROOT);
            break;
        }
        case '4':
        {
            x.postorder(x.ROOT);
            break;
        }
        }
    }
}
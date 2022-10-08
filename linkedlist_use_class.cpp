#include <iostream>

using namespace std;

class Node
{
public:
    int getdata() { return data; }
    Node() : data(0), next(NULL) {}
    Node(int n) : data(n), next(NULL) {}
    Node *next;

private:
    int data;
};

Node *head;

void insert()
{
    int data;
    cout << "Insert data:";
    cin >> data;
    Node *newnode = new Node(data);
    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        int flag = 0;
        if (data > head->getdata())
        {
            newnode->next = head;
            head = newnode;
        }
        else if (data == head->getdata())
        {
            cout << "The data is exist !!" << endl;
        }
        else
        {
            Node *cur = head;
            while (cur->next != NULL)
            {
                // cout << cur->getdata() << endl;
                if (data == cur->next->getdata())
                {
                    flag = 1;
                    // cout << "The data is exist !!" << endl;
                    break;
                }
                cur = cur->next;
            }
            if (flag == 1)
            {
                cout << "The data is exist !!" << endl;
            }
            else
            {
                newnode->next = cur->next;
                cur->next = newnode;
            }
        }
    }
}

void print()
{
    Node *cur = head;
    if (head == NULL)
    {
        cout << "NULL" << endl;
    }
    else
    {
        while (cur->next != NULL)
        {
            cout << cur->getdata() << "=>";
            cur = cur->next;
        }
        cout << cur->getdata() << "=>";
        cout << "NULL" << endl;
    }
}

void deleteNode()
{
    int data;
    cout << "delete data: ";
    cin >> data;
    Node *cur = head;
    if (data == head->getdata())
    {
        cur = cur->next;
        head = cur;
        cout << "The data was killed !!" << endl;
    }
    else
    {
        while (cur->next != NULL)
        {
            // cout << cur->getdata() << "=>" ;
            if (data == cur->next->getdata())
            {
                cur->next = cur->next->next;
                cout << "The data was killed !!" << endl;
                break;
            }
            cur = cur->next;
        }
    }
}

int main()
{
    int opt = 0;
    while (cin >> opt)
    {
        if (opt == 1)
        {
            insert();
            // print();
        }
        if (opt == 2)
        {
            print();
        }
        if (opt == 3)
        {
            deleteNode();
        }
    }

    return 0;
}
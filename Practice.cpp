# include <iostream>
# include <vector>

using namespace std;

// vector<int> tower1, tower2, tower3;

// // void push(vector<int> v, int val) {
// //     v.push_back(val);
// //     // return v;
// // }

// // void pop(vector<int> v) {
// //     v.pop_back();
// //     // return v;
// // }

// void printStack() {
//     cout << "Tower1:";
//     if (tower1.empty()) {
//         cout << endl;
//     }else {
//         for (auto &i : tower1) {
//             cout << i << " ";
//         }
//         cout << endl;
//     }
//     cout << "Tower2:";
//     if (tower2.empty()) {
//         cout << endl;
//     }else {
//         for (auto &i : tower2) {
//             cout << i << " ";
//         }
//         cout << endl;
//     }
//     cout << "Tower3:";
//     if (tower3.empty()) {
//         cout << endl;
//     }else {
//         for (auto &i : tower3) {
//             cout << i << " ";
//         }
//         cout << endl;
//     }
// }

// void slove(int len, int x, int y, int z) {
//     if (len == 1) {
//         tower1.pop_back();

//     }
// }

// int main() {
//     int n = 0;
//     cin >> n;

//     for (int i = n; i > 0; i--) {
//         tower1 = push(tower1, i);
//     }
//     if (tower1.size() == 1) {
//         tower3 = push(tower3, 1);
//         tower1 = pop(tower1);
//     }else {
//         slove(n, );
//     }

//     return 0;
// }

typedef struct node {
    int value;
    node *next;
}Node;

typedef node *NodePtr;

void push(NodePtr *head, int i);
void printStack(NodePtr head);
int deleteNode(NodePtr head);

int main() {
    int n = 0;
    cin >> n;
    NodePtr head = NULL;
    for (int i = 1; i < 4; i++) {
        push(&head, i);
        printStack(head);
    }

    return 0;
}

void push(NodePtr *head, int i) {
    NodePtr newNode = new Node();

    if (newNode != NULL) {
        newNode->value = i;
        newNode->next = *head;
        *head = newNode;
    }else {
        printf("No memery available\n");
    }
}

void printStack(NodePtr currentPtr) {
    if (currentPtr == NULL)
    {
        puts("The stack is empty.\n");
    }
    else
    {
        puts("The stack is: ");

        while (currentPtr != NULL)
        {
            printf("%d ", currentPtr->value);
            currentPtr = currentPtr->next;
        }

        cout << endl;
        // puts("NULL\n");
    }
}

int deleteNode(NodePtr head) {
    if (head == NULL)
    {
        puts("The stack is empty.\n");
    }
    else
    {
        // puts("The stack is: ");

        while (head != NULL)
        {
            // printf("%d ", currentPtr->value);
            head = head->next;
        }

        cout << endl;
        // puts("NULL\n");
    }
}
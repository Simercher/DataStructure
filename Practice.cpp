# include <iostream>
# include <vector>
# include <cmath>

using namespace std;

vector<int> tower1, tower2, tower3;
int count = 0, maxnum = 0;

void printStack() {
    count++;
    cout << "Tower1:";
    if (tower1.empty()) {
        cout << endl;
    }else {
        for (auto &i : tower1) {
            if (i != tower1.back())
            {
                cout << i << " ";
            }else {
                cout << i;
            }
        }
        cout << endl;
    }
    cout << "Tower2:";
    if (tower2.empty()) {
        cout << endl;
    }else {
        for (auto &i : tower2) {
            if (i != tower2.back())
            {
                cout << i << " ";
            }else {
                cout << i;
            }
        }
        cout << endl;
    }
    cout << "Tower3:";
    if (tower3.empty()) {
        cout << "\n" <<endl;
    }else {
        for (auto &i : tower3) {
            if (i != tower3.back())
            {
                cout << i << " ";
            }else {
                cout << i;
            }
        }
        if (count <= pow(2, maxnum) - 1){
            cout << "\n" << endl;
        }else {
            // cout << pow(2, maxnum) - 1 << " test " << endl;
            cout << endl;
        }
        
    }
}

void slove(int len, int x, int y, int z) {
    if (len == 1) {
        // cout << "test\n";
        if (x == 1) {
            if (z == 2) {
                tower2.push_back(tower1.at(tower1.size() - 1));
                tower1.pop_back();
            }else {
                // cout << "test\n";
                tower3.push_back(tower1.at(tower1.size() - 1));
                // cout << "test\n";
                tower1.pop_back();
            }
        }else if (x == 2) {
            if (z == 1) {
                tower1.push_back(tower2.at(tower2.size() - 1));
                tower2.pop_back();
            }else {
                tower3.push_back(tower2.at(tower2.size() - 1));
                tower2.pop_back();
            }
        }else if (x == 3) {
            if (z == 2) {
                tower2.push_back(tower3.at(tower3.size() - 1));
                tower3.pop_back();
            }else {
                tower1.push_back(tower3.at(tower3.size() - 1));
                tower3.pop_back();
            }
        }
        printStack();
    }else {
        slove(len - 1, x, z, y);
        if (x == 1) {
            if (z == 2) {
                tower2.push_back(tower1.at(tower1.size() - 1));
                tower1.pop_back();
            }else {
                // cout << "test\n";
                tower3.push_back(tower1.at(tower1.size() - 1));
                // cout << "test\n";
                tower1.pop_back();
            }
        }else if (x == 2) {
            if (z == 1) {
                tower1.push_back(tower2.at(tower2.size() - 1));
                tower2.pop_back();
            }else {
                tower3.push_back(tower2.at(tower2.size() - 1));
                tower2.pop_back();
            }
        }else if (x == 3) {
            if (z == 2) {
                tower2.push_back(tower3.at(tower3.size() - 1));
                tower3.pop_back();
            }else {
                tower1.push_back(tower3.at(tower3.size() - 1));
                tower3.pop_back();
            }
        }
        printStack();
        slove(len - 1, y, x, z);
    }
}

int main() {
    int n = 0;
    cin >> n;
    maxnum = n;
    for (int i = n; i > 0; i--) {
        tower1.push_back(i);
    }
    printStack();
    slove(n, 1, 2, 3);

    return 0;
}

// typedef struct node {
//     int value;
//     node *next;
// }Node;

// typedef node *NodePtr;

// void push(NodePtr *head, int i);
// void printStack();
// int deleteNode(NodePtr *head);
// void TowerofHanoi(int len, NodePtr c, NodePtr b, NodePtr a);

// NodePtr headc = NULL, headb = NULL, heada = NULL;

// int main() {
//     int n = 0;
//     cin >> n;
    
//     for (int i = n; i > 0; i--) {
//         push(&headc, i);
//         printStack();
//     }

//     // TowerofHanoi(n, headc, headb, heada);
//     // for (int i = 1; i < 4; i++) {
//     //     // push(&head, i);
//     //     int num = deleteNode(&headc);
//     //     printStack(headc);
//     //     cout << num << endl;
//     // }

//     return 0;
// }

// void TowerofHanoi(int len, NodePtr c, NodePtr b, NodePtr a) {
//     if (len == 1) {
//         push(&a, deleteNode(&c));
//     }else {
//         TowerofHanoi(len - 1, c, a, b);
//         TowerofHanoi(len, c, b, a);
//         TowerofHanoi(len - 1, b, c, a);
//     }
// }

// void push(NodePtr *head, int i) {
//     NodePtr newNode = new Node();
//     newNode->value = i;
//     newNode->next = NULL;
//     if (*head == NULL) {
//         *head = newNode;
//     } else {
//         NodePtr tempPtr = *head;
//         // cout << "test\n";
//         while (tempPtr != NULL)
//         {
//             tempPtr = tempPtr->next;
//             // cout << "test\n";
//         }
//         tempPtr = newNode;
//     }
    
// }

// void printStack() {
//     // if (currentPtr == NULL)
//     // {
//     //     puts("The stack is empty.\n");
//     // }
//     // else
//     // {
//     //     puts("The stack is: ");
//     // cout << "test\n";
//     cout << "Tower1:";
//     if (headc != NULL) {
//         while (headc->next != NULL)
//         {
//             printf("%d ", headc->value);
//             headc = headc->next;
//         }
//         printf("%d\n", headc->value);
//         // cout << "test" << endl;
//     }else {
//         cout << endl;
//     }
//     cout << "Tower2:";
//     if (headb != NULL) {
//         while (headb->next != NULL)
//         {
//             printf("%d ", headb->value);
//             headb = headb->next;
//         }
//         printf("%d\n", headb->value);
//     }else {
//         cout << endl;
//     }
//     cout << "Tower3:";
//     if (heada != NULL) {
//         while (heada->next != NULL)
//         {
//             printf("%d ", heada->value);
//             heada = heada->next;
//         }
//         printf("%d", heada->value);
//     }else {
//         cout << endl;
//     }
//     // puts("NULL\n");
//         // cout << endl;
//     // }
// }

// int deleteNode(NodePtr *head) {

//     int deleteNum = 0;
//     // if (head == NULL) {
//     //     deleteNum = head->value;
//     //     delete(head);
//     //     cout << "test" << endl;
//     //     return deleteNum;
//     // }
//     if ((*head)->next == NULL) {
//         NodePtr tempPtr = *head;
//         deleteNum = tempPtr->value;
//         // deleteNum = head->value;
//         // delete(head->next);
//         delete(tempPtr);
//         cout << "test";
//     }else {
//         while ((*head)->next->next != NULL)
//         {
//             (*head) = (*head)->next;
//         }
//         NodePtr tempPtr = (*head)->next;
//         deleteNum = tempPtr->value;
//         (*head)->next = (*head)->next->next;
//         delete(tempPtr);
//     }
//     // NodePtr tempPtr = *head;
//     // deleteNum = tempPtr->value;
//     // *head = (*head)->next;
//     // free(tempPtr);

//     return deleteNum;
// }
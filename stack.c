#include "stdio.h"
#include "stdlib.h"

struct stackNode
{
    int data;
    struct stackNode *nextptr;
};

typedef struct stackNode StackNode;
typedef StackNode *StackNodePtr;

void push(StackNodePtr *topPtr, int info);
void printlist(StackNodePtr currentPtr);

int main()
{
    StackNodePtr stackPtr = NULL; //指標位址指向NULL
    // char buffer[20];
    int value;
    while (scanf("%d", &value))
    {
        push(&stackPtr, value);
        printlist(&stackPtr);
    }

    return 0;
}
void push(StackNodePtr *topPtr, int info)
{
    StackNodePtr newPtr = malloc(sizeof(StackNode));

    if (newPtr != NULL)
    {
        newPtr->data = info;
        newPtr->nextptr = *topPtr;
        *topPtr = newPtr;
    }
    else
    {
        printf("%d not inserted. No memory available.\n", info);
    }
}

void printlist(StackNodePtr currentPtr)
{
    if (currentPtr == NULL)
    {
        puts("The stack is empty.\n");
    }
    else
    {
        puts("The stack is: ");

        while (currentPtr != NULL)
        {
            printf("%d --> ", currentPtr->data);
            currentPtr = currentPtr->nextptr;
        }

        puts("NULL\n");
    }
}
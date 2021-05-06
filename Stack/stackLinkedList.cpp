#include<iostream>
using namespace std;

struct Stack{
    int data;
    struct Stack *next;
};

struct Stack *top = NULL;

int isEmpty(struct Stack *top)
{
    if(top==NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct Stack *top)
{
    struct Stack *n = new struct Stack[sizeof(struct Stack)];
    if(n==NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

struct Stack* push(struct Stack *top, int val)
{
    if(isFull(top))
    {
        cout<<"Stack Overflow"<<endl;
    }
    else
    {
        struct Stack *n = new struct Stack[sizeof(struct Stack)];
        n->data = val;
        n->next = top;
        top = n;
        return top;
    }
};

int pop(struct Stack *tp)
{
    if(isEmpty(tp))
    {
        cout<<"Stack Underflow"<<endl;
    }
    else
    {
        struct Stack* n = tp;
        top = tp->next;
        int val = n->data;
        delete n;
        return val;
    }
}

int stackTop(struct Stack *top)
{
    return top->data;
}

int stackPeek( int pos)
{
    struct Stack *ptr = top;
    for(int i=0; (i<pos-1) && ptr!=NULL; i++)
    {
        ptr = ptr->next;
    }

    if(ptr!=NULL)
    {
        return ptr->data;
    }
    else
    {
        return -1;
    }
}

void Traversal(struct Stack *ptr)
{
    int i=0;
    while(ptr!=NULL)
    {
        cout<<"Element "<<i<<" :"<<ptr->data<<endl;
        ptr = ptr->next;
        i++;
    }
}

int main()
{
    top = push(top, 10);
    top = push(top, 20);
    top = push(top, 30);
    top = push(top, 40);
    top = push(top, 50);
    top = push(top, 60);

    Traversal(top);
    int popElem = pop(top);
    cout<<"Popped Element from stack "<<popElem<<endl;
    cout<<"Top Element of the Stack "<<stackTop(top)<<endl;
    cout<<"Position of the Element in the Stack 2:  v"<<stackPeek(2)<<endl;
    Traversal(top);

    return 0;
}

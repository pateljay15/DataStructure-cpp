#include<iostream>
#include<stdlib.h>
using namespace std;

struct Stack{

    int sizze;
    int top;
    int *arr;
};


int isEmpty(struct Stack *s)
{
    if(s->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct Stack *s)
{
    if(s->top == s->sizze-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct Stack *s, int val)
{
    if(isFull(s))
    {
        cout<<"Stack Overflow"<<endl;
    }
    else
    {
        s->top++;
        s->arr[s->top] = val;
    }
}

int pop(struct Stack *s)
{
    int val;
    if(isEmpty(s))
    {
        cout<<"Stack Underflow"<<endl;
    }
    else
    {
        val = s->arr[s->top];
        s->top--;
        return val;
    }
}

int stackTop(struct Stack *s)
{
    if(isEmpty(s))
    {
        cout<<"Stack Underflow"<<endl;
    }
    else
    {
        return s->arr[s->top];
    }
}

int stackBottom(struct Stack *s)
{
    if(isEmpty(s))
    {
        cout<<"Stack Underflow"<<endl;
    }
    else
    {
        return s->arr[0];
    }
}

int stackPeek(struct Stack *s,int pos)
{
    if(isEmpty(s))
    {
        cout<<"Stack Underflow"<<endl;
    }
    else
    {
        int iter = s->top;
        while(iter!=pos-1)
        {
            iter--;
        }

        return s->arr[iter];
    }
}

void display(struct Stack *s)
{
    for(int i=s->top; i>=0; i--)
    {
        cout<<"Element "<<i<<":"<<" "<<s->arr[i]<<endl;
    }
}

int main()
{
    struct Stack *s = new struct Stack[sizeof(struct Stack)];
    s->sizze = 8;
    s->top = -1;
    s->arr = new int[s->sizze];
    //s->arr = (int *)malloc(s->sizze*sizeof(int));

    push(s, 10);
    push(s, 20);
    push(s, 30);
    push(s, 40);
    push(s, 50);
    push(s, 60);
    display(s);
    int popElem = pop(s);
    cout<<"Popped Element from Stack is :"<<popElem<<endl;
    display(s);
    cout<<"Top of the Stack :"<<stackTop(s)<<endl;
    cout<<"Bottom of the Stack :"<<stackBottom(s)<<endl;
    cout<<"Value in Stack at position "<<3<<": "<<stackPeek(s, 3)<<endl;
    return 0;
}

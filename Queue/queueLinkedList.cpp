#include<iostream>
using namespace std;


struct Node{
    int data;
    struct Node *next;
};

struct Node *f = NULL;
struct Node *r = NULL;


void enqueue(int val)
{
    struct Node *n = new struct Node[sizeof(struct Node)];
    if(n==NULL)
    {
        cout<<"Queue Overflow"<<endl;
    }
    else
    {
        n->data = val;
        n->next = NULL;

        if(f==NULL)
        {
            f = r = n;
        }
        else
        {
            r->next = n;
            r=n;
        }
    }
}

int dequeue()
{
    int val = -1;
    struct Node *ptr = f;

    if(f==NULL)
    {
        cout<<"Queue Underflow"<<endl;
    }
    else
    {
        val = f->data;
        f = f->next;
        return val;
    }
}

void Traversal(struct Node *ptr)
{
    int i=0;
    while(ptr!=NULL)
    {
        cout<<"Element at "<<i+1<<" :"<<ptr->data<<endl;
        ptr = ptr->next;
        i++;
    }
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    Traversal(f);
    int deElem = dequeue();
    cout<<"Dequeuing element "<<deElem<<endl;
     deElem = dequeue();
    cout<<"Dequeuing element "<<deElem<<endl;
    enqueue(60);
    Traversal(f);
}

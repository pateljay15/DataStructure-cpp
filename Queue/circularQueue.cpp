#include<iostream>
using namespace std;

struct Queue{
    int sizze;
    int f;
    int r;
    int *arr;
};

int isEmpty(struct Queue *q)
{
    if(q->f==q->r)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct Queue *q)
{
    if((q->r+1)%q->sizze==q->f)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enqueue(struct Queue *q, int val)
{
    if(isFull(q))
    {
        cout<<"Queue Overflow"<<endl;
    }
    else
    {
        q->r = (q->r +1)%q->sizze;
        q->arr[q->r] = val;
    }
}

int dequeue(struct Queue *q)
{
    if(isEmpty(q))
    {
        cout<<"Queue Underflow"<<endl;
    }
    else
    {
        q->f = (q->f +1)%q->sizze;
        return q->arr[q->f];
    }
}

void display(struct Queue *q)
{
    int i=q->f+1;
    while(i!=q->r)
    {
        //cout<<q->r<<"::"<<endl;
        cout<<"Element at "<<i<<" :"<<q->arr[i]<<endl;
        i=(i+1)%q->sizze;
    }
}


int main()
{
    struct Queue *q = new struct Queue[sizeof(struct Queue)];
    q->sizze = 6;
    q->f = 0;
    q->r = 0;
    q->arr = new int[q->sizze];

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);
    enqueue(q, 60);
    enqueue(q, 70);
    display(q);
    int deElem = dequeue(q);
    cout<<"Dequeued Element is :"<<deElem<<endl;
     deElem = dequeue(q);
    cout<<"Dequeued Element is :"<<deElem<<endl;
    enqueue(q, 60);
    enqueue(q, 70);
    //cout<<q->r<<endl;
    display(q);

}

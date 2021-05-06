#include<iostream>
using namespace std;


struct Queue{
    int sizze;
    int f;
    int r;
    int *arr;
};

int isFull(struct Queue *q)
{
    if(q->r==q->sizze-1){
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmpty(struct Queue *q)
{
    if(q->r==q->f){
        return 1;
    }
    else
    {
        return 0;
    }
}

void enqueue(struct Queue *q, int val)
{
    if(isFull(q)){
        cout<<"Queue Overflow"<<endl;
    }
    else
    {
        q->r = q->r+1;
        q->arr[q->r] = val;
    }
}

int dequeue(struct Queue *q)
{
    if(isEmpty(q)){
        cout<<"Queue Underflow"<<endl;
    }
    else
    {
        q->f++;
        return q->arr[q->f];
    }
}

int queuePeek(struct Queue *q, int index)
{
    int f = q->f+1;
    for(int i=0; (i<index-1 && q->f!=q->r); i++)
    {
        f++;
    }

    if(f-1!=q->r){
        return q->arr[f];
    }
    else
    {
        return -1;
    }
}

void display(struct Queue *q)
{
    int i = q->f+1;
    while(i<=q->r)
    {
        cout<<"Element "<<i<<" :"<<q->arr[i]<<endl;
        i++;
    }
}


int main()
{
    struct Queue *q = new struct Queue[sizeof(struct Queue)];
    q->sizze = 8;
    q->f = -1;
    q->r = -1;
    q->arr = new int[q->sizze];

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);
    display(q);

    int deElem = dequeue(q);
    cout<<"Dequeued Element "<<deElem<<endl;
    /*deElem = dequeue(q);
    cout<<"Dequeued Element "<<deElem<<endl;
    deElem = dequeue(q);
    cout<<"Dequeued Element "<<deElem<<endl;
    deElem = dequeue(q);
    cout<<"Dequeued Element "<<deElem<<endl;*/
    display(q);

    int peekElem = queuePeek(q, 2);
    if(peekElem!=-1){
        cout<<"peek Element "<<peekElem<<endl;
    }else{
        cout<<"Element Not Found"<<endl;
    }

    return 0;
}

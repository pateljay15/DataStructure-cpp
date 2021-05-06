#include<iostream>
using namespace std;


struct Node{
    int data;
    struct Node *prev;
    struct Node *next;
};

void linkedListTraversal(struct Node *head)
{
    int i=0;
    while(head!=NULL){
        cout<<"Element "<<i<<" :"<<head->data<<endl;
        head = head->next;
        i++;
    }
}

struct Node* insertAtFirst(struct Node *head, int val)
{
    struct Node *ptr = new struct Node[sizeof(struct Node)];
    ptr->data = val;
    ptr->prev=NULL;
    ptr->next = head;
    head->prev = ptr;
    return ptr;
};

struct Node* insertAtIndex(struct Node *head, int data, int index)
{
    struct Node *ptr = new struct Node[sizeof(struct Node)];
    struct Node *p = head;

    for(int i=0; i<index-1; i++){
        p = p->next;
    }

    ptr->prev=p;
    ptr->data = data;
    ptr->next = p->next;
    p->next->prev=ptr;
    p->next = ptr;
    return head;
};

struct Node* insertAtEnd(struct Node *head, int val)
{
    struct Node *ptr = new struct Node[sizeof(struct Node)];
    struct Node *p = head;

    while(p->next!=NULL){
        p = p->next;
    }
    ptr->data = val;
    p->next = ptr;
    ptr->prev = p;
    ptr->next = NULL;
    return head;
};

struct Node* insertAfterNode(struct Node* head, struct Node *prevNode, int val)
{
    struct Node *ptr = new struct Node[sizeof(struct Node)];
    ptr->data = val;
    ptr->prev = prevNode;
    ptr->next = prevNode->next;
    prevNode->next->prev = ptr;
    prevNode->next = ptr;
    return head;
};

struct Node* deleteAtFirst(struct Node* head)
{
    struct Node *ptr = head;
    head = head->next;
    head->prev = NULL;
    delete ptr;
    return head;
};

struct Node* deleteAtEnd(struct Node* head)
{
    struct Node *p = head;
    struct Node *q = head->next;

    while(q->next!=NULL)
    {
        p = p->next;
        q = q->next;
    }

    p->next = NULL;
    delete q;
    return head;
};

struct Node* deleteAtValue(struct Node* head, int val)
{
    struct Node* p = head;
    struct Node* q = head->next;

    while(q->data!=val && q->next!=NULL)
    {
        p = p->next;
        q = q->next;
    }

    if(q->data == val){
        q->next->prev = p;
        p->next = q->next;
        delete q;
    }
    return head;
};

struct Node* deleteAtIndex(struct Node* head, int index)
{
    struct Node* p = head;
    struct Node* q = head->next;

    for(int i=0; i<index-1; i++){
        p = p->next;
        q = q->next;
    }

    q->next->prev = p;
    p->next = q->next;
    delete q;
    return head;
};

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    head = new struct Node[sizeof(struct Node)];
    second = new struct Node[sizeof(struct Node)];
    third = new struct Node[sizeof(struct Node)];
    fourth = new struct Node[sizeof(struct Node)];

    head->prev=NULL;
    head->data=10;
    head->next=second;

    second->prev=head;
    second->data=20;
    second->next=third;

    third->prev=second;
    third->data=30;
    third->next=fourth;

    fourth->prev=third;
    fourth->data=40;
    fourth->next=NULL;
    cout<<"Insertion operation"<<endl;
    linkedListTraversal(head);

    cout<<"Insert Element at the beginning of the linked list"<<endl;
    head = insertAtFirst(head, 50);
    linkedListTraversal(head);

    cout<<"Insert Element at a given position in the linked list"<<endl;
    head = insertAtIndex(head, 100, 3);
    linkedListTraversal(head);

    cout<<"Insert Element at a End of the linked list"<<endl;
    head = insertAtEnd(head, 200);
    linkedListTraversal(head);

    cout<<"Insert Element after a node in the linked list"<<endl;
    head = insertAfterNode(head, fourth, 300);
    linkedListTraversal(head);

    cout<<"Deletion Operations"<<endl;
    cout<<"Deletion of the node from the first"<<endl;
    head = deleteAtFirst(head);
    linkedListTraversal(head);

    cout<<"Deletion of the node at a particular node value"<<endl;
    head = deleteAtValue(head, 100);
    linkedListTraversal(head);

    cout<<"Deletion of the node at a particular index"<<endl;
    head = deleteAtIndex(head, 3);
    linkedListTraversal(head);

    cout<<"Deletion of the node at the end"<<endl;
    head = deleteAtEnd(head);
    linkedListTraversal(head);
    return 0;
}


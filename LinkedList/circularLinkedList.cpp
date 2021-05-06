#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node *next;
};

void circularTraversal(struct Node* head)
{
    struct Node *ptr = head;
    int i=0;
    do{
        cout<<"Element "<<i<<" :"<<ptr->data<<endl;
        ptr = ptr->next;
        i++;
    }while(ptr!=head);
}

struct Node* insertAtFirst(struct Node* head, int val)
{
    struct Node* ptr = new struct Node[sizeof(struct Node)];
    ptr->data = val;
    struct Node *q = head->next;

    while(q->next!=head){
        q = q->next;
    }

    ptr->next = q->next;
    q->next = ptr;
    return ptr;
};

struct Node* insertAtIndex(struct Node* head, int val, int index)
{
    struct Node* ptr = new struct Node[sizeof(struct Node)];
    ptr->data = val;
    struct Node *q = head;
    for(int i=0; (i<index-1 && q->next!=head); i++){
        q = q->next;
    }

    if(q->next!=head){
        ptr->next = q->next;
        q->next = ptr;
    }
    return head;
};

struct Node* insertAtEnd(struct Node* head, int val)
{
    struct Node* ptr = new struct Node[sizeof(struct Node)];
    ptr->data = val;
    struct Node *q = head->next;

    while(q->next!=head){
        q = q->next;
    }

    ptr->next = q->next;
    q->next = ptr;

    return head;
};

struct Node* insertAfterNode(struct Node* head, struct Node* prevNode, int val)
{
    struct Node* ptr = new struct Node[sizeof(struct Node)];
    ptr->data = val;

    ptr->next = prevNode->next;
    prevNode->next = ptr;

    return head;
};

struct Node* deleteAtFirst(struct Node* head)
{
    struct Node *p = head;
    struct Node *q = head->next;

    while(p->next!=head){
        p = p->next;
        q = q->next;
    }

    p->next = q->next;
    delete q;
    return p->next;
};

struct Node* deleteAtValue(struct Node* head, int val)
{
    struct Node *p = head;
    struct Node *q = head->next;

    while(q->next!=head && q->data!=val){
        p = p->next;
        q = q->next;
    }

    if(q->data==val){
        p->next = q->next;
        delete q;
    }
    return head;
};

struct Node* deleteAtIndex(struct Node* head, int index)
{
    struct Node *p = head;
    struct Node *q = head->next;
    int i=0;
    while(q->next!=head && i<index-2){
        p = p->next;
        q = q->next;
        i++;
    }

    p->next = q->next;
    delete q;
    return head;
};

struct Node* deleteAtEnd(struct Node* head)
{
    struct Node *p = head;
    struct Node *q = head->next;

    while(q->next!=head){
        p = p->next;
        q = q->next;
    }

    p->next = q->next;
    delete q;
    return p->next;
};

int main()
{
    struct Node* head;
    struct Node* second;
    struct Node* third;
    struct Node* fourth;

    head = new struct Node[sizeof(struct Node)];
    second = new struct Node[sizeof(struct Node)];
    third = new struct Node[sizeof(struct Node)];
    fourth = new struct Node[sizeof(struct Node)];

    head->data=10;
    head->next=second;

    second->data=20;
    second->next=third;

    third->data=30;
    third->next=fourth;

    fourth->data=40;
    fourth->next=head;

    circularTraversal(head);
    cout<<"Insertion operation"<<endl;

    cout<<"Insert Element at the beginning of the linked list"<<endl;
    head = insertAtFirst(head, 50);
    circularTraversal(head);

    cout<<"Insert Element at a given position in the linked list"<<endl;
    head = insertAtIndex(head, 100, 3);
    circularTraversal(head);

    cout<<"Insert Element at a End of the linked list"<<endl;
    head = insertAtEnd(head, 200);
    circularTraversal(head);

    cout<<"Insert Element after a node in the linked list"<<endl;
    head = insertAfterNode(head, fourth, 300);
    circularTraversal(head);

    cout<<"Deletion Operations"<<endl;
    cout<<"Deletion of the node from the first"<<endl;
    head = deleteAtFirst(head);
    circularTraversal(head);

    cout<<"Deletion of the node at a particular value"<<endl;
    head = deleteAtValue(head, 100);
    circularTraversal(head);

    cout<<"Deletion of the node at a particular index"<<endl;
    head = deleteAtIndex(head, 3);
    circularTraversal(head);

    cout<<"Deletion of the node at the end"<<endl;
    head = deleteAtEnd(head);
    circularTraversal(head);

    return 0;
}

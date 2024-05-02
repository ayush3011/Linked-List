#include<bits/stdc++.h>
using namespace std;

struct Node{
    Node *prev;
    int data;
    Node *next;
} *first = NULL;

void Create(int A[], int n){
    struct Node *t, *last;
    int i;

    first = new Node;
    first->data = A[0];
    first->prev=first->next=NULL;
    last = first;

    for (int i = 1; i < n; i++){
        t = new Node;
        t->data = A[i];
        t->next = last->next;
        t->prev = last;
        last->next=t;
        last = t;
    }
}

void Display(struct Node *p){
    while(p!=NULL){
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int Length(struct Node *p){
    int len = 0;
    while(p){
        len++;
        p = p->next;
    }
    return len;
}

void Insert(struct Node *p, int index, int x){
    struct Node *t;
    int i;

    if(index<0 || index>Length(p))
        return;
    if(index==0){
        t = new Node;
        t->data = x;
        t->prev = NULL;
        t->next = first;
        first->prev = t;
        first = t;
    }
    else{
        for (i = 0; i < index - 1; i++)
            p = p->next;
        t = new Node;
        t->data = x;

        t->prev = p;
        t->next = p->next;
        if(p->next)
            p->next->prev = t;
        p->next = t;
    }
}

int Delete(struct Node *p, int index){
    int x = -1, i;

    if(index<1 || index>Length(p))
        return -1;
    if(index==1)
    {
        first = first->next;
        if(first)
            first->prev = NULL;
        x = p->data;
        delete p;
    }
    else{
        for (i = 0; i < index - 1; i++){
            p = p->next;
        }
        p->prev->next = p->next;
        if(p->next)
            p->next->prev = p->prev;
        x = p->data;
        delete p;
    }
    return x;
}

void Reverse(struct Node *p){
    struct Node *temp;
    while(p!=NULL){
        temp = p->next;
        p->next = p->prev;
        p->prev = temp;
        p = p->prev;
        if(p!=NULL && p->next==NULL)
            first = p;
    }
}

int main(){
    int A[] = {1,2,3,4,5,6};
    Create(A, 6);
    // cout << Length(first)<<endl;

    // Insert(first, 2,79);
    // cout << Delete(first, 1) << endl;

    Reverse(first);
    Display(first);
    return 0;
}
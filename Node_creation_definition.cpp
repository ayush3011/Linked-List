// A linked list is always created in heap
// linked list is a collection of nodes where each node contain data and pointer to the next node
#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next; // Self Referential
};

int main(){
    struct Node *p;
    p = new Node;
    p->data = 10;
    p->next = 0; // this is creating a node
    return 0;
}
#include<iostream>
using namespace std;

struct node{
    int data;
    node *prev;
    node *next;
};

node *head = NULL;
node *tail = NULL;

void insertAtHead(int num){
    node *temp = new node;
    temp->data = num;
    temp->next = NULL;
    temp->prev = NULL;
    if (head == NULL){
        head = temp;
        tail = temp;
        return;
    }
    temp->next = head;
    head->prev = temp;
    head = temp;
}

void insertAtTail(int num){
    node *temp = new node;
    temp->data = num;
    temp->next = NULL;
    temp->prev = NULL;
    if (head == NULL){
        head = temp;
        tail = temp;
        return;
    }
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}

void insertAtPos(int num, int pos){
    node *temp = new node;
    temp->data = num;
    temp->next = NULL;
    temp->prev = NULL;
    if (head == NULL){
        head = temp;
        tail = temp;
        return;
    }
    if (pos == 1){
        temp->next = head;
        head->prev = temp;
        head = temp;
        return;
    }
    node *aft = head;
    for (int i = 0; i < pos-1; i++){
        aft = aft->next;
    }
    node *bef = aft->prev;
    bef->next = temp;
    temp->prev = bef;
    aft->prev = temp;
    temp->next = aft;
}

void del(int pos){
    node *temp = head;
    if(pos == 1){
        head = temp->next;
        head->prev = NULL;
        delete temp;
        return;
    }
    for(int i = 0; i < pos-1; i++)
        temp = temp->next;
    //deletion from tail
    if(temp->next == NULL){
        node *pre = temp->prev;
        pre->next = NULL;
        delete temp;
        tail = pre;
        return;
    }    
    node *bef = temp->prev;
    node *aft = temp->next;
    delete temp;
    bef->next = aft;
    aft->prev = bef;
}

void print(){
    node *ptr = head;
    while (ptr != NULL){
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
    ptr = tail;
    while (ptr != NULL){
        cout << ptr->data << " ";
        ptr = ptr->prev;
    }
    cout << endl;
}

int main(){
    insertAtPos(0,1);
    insertAtHead(5);
    insertAtTail(12);
    insertAtTail(10);
    insertAtPos(1,1);
    insertAtPos(8,5);
    print();
    del(1);
    print();
    return 0;
}

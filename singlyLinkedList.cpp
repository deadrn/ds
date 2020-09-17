#include <iostream>
using namespace std;

struct node{
    int data;
    node *next;
};

node *head = NULL;
node *tail = NULL;

void insertAtHead(int num){
    node *temp = new node;
    temp->data = num;
    temp->next = head;
    head = temp;
    if(tail == NULL)
        tail = temp;
}

void insertAtTail(int num){
    node *temp = new node;
    temp->data = num;
    temp->next = NULL;
    if(head == NULL){
        head = temp;
        tail = temp;
        return;
    }
    tail->next = temp;
    tail = temp;
}

void insertAtPos(int num, int pos){
    node *temp = new node;
    temp->data = num;
    temp->next = NULL;
    if (pos == 1){
        temp->next = head;
        head = temp;
        return;
    }
    node *pre = head;
    for (int i = 0; i < pos-2; i++)
        pre = pre->next;
    temp->next = pre->next;
    pre->next = temp;
}

void del(int pos){
    node *temp = head;
    if (pos == 1){
        head = head->next;
        delete temp;
        return;
    }
    node *temp1 = NULL;
    for (int x = 0; x < pos-2; x++)
        temp = temp->next;
    temp1 = temp->next;
    temp->next = temp1->next;
    delete temp1;
}

void display(){
    node *ptr = head;
    while (ptr != NULL){
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

int main(){
    insertAtHead(9);
    insertAtTail(1);
    insertAtTail(2);
    insertAtTail(5);
    insertAtHead(4);
    insertAtPos(2,3);
    display();
}

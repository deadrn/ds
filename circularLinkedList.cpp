#include<iostream>
using namespace std;

struct node{
    int data;
    node *next;
};

node *head = NULL;

void insert(int num){
    node *temp = new node;
    temp->data = num;
    temp->next = NULL;
    if(head == NULL){
        head = temp;
        head->next = head;
        return;
    }
    node *ptr = head;
    while (ptr->next != head)
        ptr = ptr->next;
    temp->next = head;
    ptr->next = temp;
    head = temp;
}

void del(int pos){
    node *temp = head;
    if (pos == 1){
        node *ptr = head;
        while(temp->next != head){
            temp = temp->next;
        }
        temp->next = ptr->next;
        head = temp->next;
        delete ptr;
        return;
    }
    node *bef = head;
    for(int i = 0; i < pos-2; i++){
        bef = bef->next;
    }
    temp = bef->next;
    node *aft = temp->next;
    delete temp;
    bef->next = aft;
}

void display(){
    node *ptr = head;
    while(ptr->next != head){
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << ptr->data;
    cout << endl;
}

int main(){
    insert(0);
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    insert(5);
    display();
    del(1);
    display();
}

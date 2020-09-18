//using Linked List
#include<iostream>
using namespace std;

struct node{
    int data;
    node *next;
};

class stack{
    private:
    node *top = NULL;
    public:
    void push(int n);
    void pop();
    bool isEmpty();
    int topp();    
    void print();
};

void stack::push(int n){
    node *temp = new node;
    temp->data = n;
    temp->next = top;
    top = temp;
}

void stack::pop(){
    if(isEmpty()){
        cout << "Stack underflow." << "\n";
        return;
    }
    node *temp = top;
    int n = top->data;
    top = top->next;
    delete temp;
    cout << "Popped element: " << n << "\n";
}

bool stack::isEmpty(){
    return (top == NULL);
}

int stack::topp(){
    return top->data;
}

void stack::print(){
    if(isEmpty()){
        cout << "Stack underflow." << "\n";
        return;
    }
    node *ptr = top;
    while(ptr != NULL){
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << "\n";
}

int main(){
    stack s;
    s.push(1);
    s.push(2);
    s.pop();
    s.pop();
    s.pop();
    s.print();
}

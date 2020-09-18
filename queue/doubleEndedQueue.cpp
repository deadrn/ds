#include<iostream>
using namespace std;

struct node{
    int data;
    node *next;
};

class DQ{
    private:
    node *head;
    node *tail;
    public:
    void inF(int n); //front insertion
    void inR(int n); //rear insertion
    void deF(); //front deletion
    void deR(); //rear deletion
    void front(); //first element
    void rear(); //last element
    bool empty();
    void print();
    DQ(){
        head = NULL;
        tail = NULL;
    }
};

void DQ::inF(int n){
    node *temp = new node;
    temp->data = n;
    temp->next = head;
    head = temp;
    if(tail == NULL)
        tail = temp;
}

void DQ::inR(int n){
    node *temp = new node;
    temp->data = n;
    temp->next = NULL;
    if(empty()){
        head = temp;
        tail = temp;
        return;
    }
    tail->next = temp;
    tail = temp;
}

void DQ::deF(){
    node *temp = head;
    cout << temp->data << " deleted\n";
    head = head->next;
    delete temp;
}

void DQ::deR(){
    node *temp = tail;
    cout << temp->data << " deleted\n";
}

void DQ::front(){
    cout << "Front: " << head->data << "\n";
}

void DQ::rear(){
    cout << "Rear: " << tail->data << "\n";
}

bool DQ::empty(){
    return (head == NULL && tail == NULL);
}

void DQ::print(){
    node *temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

int main(){
    DQ q;
    q.inF(1);
    q.inR(5);
    q.inF(6);
    q.print();
    q.deF();
}

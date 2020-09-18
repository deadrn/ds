//who said it C++ and not pu-C
#include<iostream>
using namespace std;

struct node{
    int data;
    node *next;
};

class Q{
    private:
    node *head = NULL;
    node *tail = NULL;
    public:
    void enQ(int n);
    void deQ();
    bool isEmpty();
    void front();
    void print();
};

void Q::enQ(int n){
    node *temp = new node;
    temp->data = n;
    temp->next = NULL;
    if(isEmpty()){
        head = temp;
        tail = temp;
        return;
    }
    tail->next = temp;
    tail = temp;
}

void Q::deQ(){
    if(isEmpty()){
        cout << "Queue is empty." << "\n";
        return;
    }
    node *temp = head;
    head = head->next;
    cout << temp->data << " removed from Q." << "\n";
    delete temp;
}

bool Q::isEmpty(){
    return (head == NULL)?1:0;    
}

void Q::front(){
    cout << head->data << endl;
}
void Q::print(){
    node *ptr = head;
    while(ptr != NULL){
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << "\n";
}

int main(){
    Q o;
    o.enQ(1);
    o.enQ(2);
    o.front();
    o.deQ();
    o.deQ();
    o.deQ();
    o.print();
}

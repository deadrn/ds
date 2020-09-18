//using arrays
#include<iostream>
using namespace std; 
#define MAX_SIZE 10

class CQ{
    private:
	int A[MAX_SIZE];
	int front, rear; 
    public:
	bool empty();
	bool full();
	void deQ();
	void enQ(int n);
	void print();
	CQ(){
		front = -1; 
		rear = -1;
	}
};

bool CQ::empty(){
	return (front == -1 && rear == -1); 
}

bool CQ::full(){
	return (rear+1)%MAX_SIZE == front ? true : false;
}

void CQ::enQ(int x){
	if(full()){
		cout << "Queue is full\n";
		return;
	}
	if(empty())
		front = rear = 0; 
	else
	    rear = (rear+1)%MAX_SIZE;
	A[rear] = x;
}

void CQ::deQ(){
	if(empty()){
		cout << "Queue is empty\n";
		return;
	}
	else if(front == rear)
		rear = front = -1;
	else
		front = (front+1)%MAX_SIZE;
}

void CQ::print(){
	int count = (rear+MAX_SIZE-front)%MAX_SIZE + 1;
	cout << "Queue: ";
	for(int i = 0; i < count; i++){
		int index = (front+i) % MAX_SIZE;
		cout<<A[index]<<" ";
	}
	cout << "\n";
}

int main(){
   CQ Q;
   Q.enQ(2);
   Q.print();
   Q.deQ();
   Q.deQ();
   Q.print();
}

#include <iostream>

using namespace std;

const int MAX_SIZE = 100;

class Queue {
private:
    int arr[MAX_SIZE];
    int front, rear;

public:
    Queue(){
        front = -1;
        rear = -1;
    }

    bool isEmpty(){
        return front == -1 && rear == -1;
    }

    bool isFull(){
        return (rear + 1) % MAX_SIZE == front;
    }

    void enqueue(int value){
        if (isFull()) {
            cout << "Antria penuh!" << endl;
            return;
        } else if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % MAX_SIZE;
        } 

        arr[rear] = value;
    }

    int dequeue(){
        int value;
        if (isEmpty()) {
            cout << "Antrian kosong" << endl;
            return -1;
        } else if (front == rear) {
            value = arr[front];
            front = rear = -1;
        } else {
            value = arr[front];
            front = (front + 1) % MAX_SIZE;
        }
        return value;
    }

    int peek() {
        if (isEmpty()){
            cout << "Antrian kosong!" << endl;
            return -1;
        }
        return arr[front];
    }

    void display(){
        if (isEmpty()){
            cout << "Antrian kosong!" << endl;
            return;
        }
        cout << "Antrian : ";
        for (int i = front; i != rear; i = (i + 1) % MAX_SIZE){
            cout << arr[i] << " ";
        }
        cout << arr[rear] << endl;
    }
};

int main(){
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();
    cout << "Elemen yang dikeluarkan: " << q.dequeue() << endl;
    q.display();
    cout << "Elemen terdepan: " << q.peek() << endl;

    return 0;
}

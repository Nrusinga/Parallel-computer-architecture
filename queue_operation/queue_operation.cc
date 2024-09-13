#include <iostream>
using namespace std;

#define MAX 100

class Queue {

private:
    int arr[MAX];
    int front,rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    void enqueue(int item) {
        if (rear == MAX -1 ){
            cout << " Queue overflow" << endl;
        } else {
            if (front == -1) front = 0;
            rear++;
            arr[rear]=item;
            cout << "Enqueued" << item << endl;
        }
    }

    void dequeue() {
        if(is_empty()){
            cout << "Queue is empty" << endl;
        } else {
            front++;
            if(front > rear) front = rear = -1;
        }
    }

    bool is_empty() const{
        return front == -1;
    }

    void delete_item(int item) {
        if(is_empty()) {
            cout << " Queue is empty" << endl;
            return;
        }
        int index=-1;
        for( int i = front; i <= rear ; i++){
            if(arr[i]==item) {
                index = i;
                break;
            }
        }

        if ( index==-1) {
            cout << " Item " << item << " not found in the queue" << endl;
            return;
        }
        for(int i= index; i < rear; i++) {
            arr[i] = arr[i+1];
        }

        rear--;
        cout << " Deleted " << item << endl;

        // If the queue becomes empty after deletion
        if (front > rear) {
            front = rear = -1;
        }

    }

    void display() {
        if(is_empty()) {
            cout << " Queue is empty" << endl;
        } else {
            cout << " Queue contents" << endl;
            for( int i = front; i <= rear; i++) {
                cout << arr[i] << " ";
            }
            cout<< endl;
        }
    }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();

    // Dequeue operation
    q.dequeue();
    q.display();

    // Delete operation
    q.delete_item(20);
    q.display();

    q.display();

    // Try deleting an element not in the queue
    q.delete_item(40);
    q.display();
}


#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Queue {

private:
    Node* front;
    Node* rear;

public:
    Queue(){
        rear=front=nullptr;
    }

    void enqueue(int item) {
        Node* temp = new Node();
        temp->data=item;
        temp->next=nullptr;

        if(rear==nullptr){
            front=rear=temp;
        } else {
            rear->next = temp;
            rear=temp;
        }

        cout << "Enqueued: " << item << endl;
    }

    void dequeue() {
        if (is_empty()) {
            cout << " Queue is empty" << endl;
            return;
        }

        Node* temp;
        temp=front;
        front=front->next;

        if ( front == nullptr) {
            rear=nullptr;
        }
        cout << " Dequeued: " << temp->data << endl;
        delete temp;

    }

    void delete_item(int item) {
        if (is_empty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        Node* temp = front,*prev=nullptr;
       

        if(temp !=nullptr && temp->data==item) {
            front=temp->next;
            if(front == nullptr) rear = nullptr;
            delete temp;
            cout << "Deleted" << item << endl;
            return;
        }

        while (temp!=nullptr && temp->data!=item) {
            prev=temp;
            temp=temp->next;
        }

        prev->next=temp->next;
        if (prev->next == nullptr) rear = prev;
        delete temp;
        cout << "Deleted: " << item << endl;
        

    }
    bool is_empty() const {
        return front == nullptr;
    }

    void display() const {
        if (is_empty()) {
            cout << "Queue is empty" << endl;
        } else {
            Node* temp = front;
            cout << "Queue contents: ";
            while (temp != nullptr) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }

};

int main() {
    Queue q;

    // Enqueue operations
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

    return 0;
}
#include <iostream>
using namespace std;

struct Node {
    int playerId;
    Node* next;
};

class CircularQueue {
    private:
        Node* front;
        Node* rear;

    public:
        CircularQueue() {
            front = rear = NULL;
        }

      
        void addPlayer(int playerId) {
            Node* newNode = new Node();
            newNode->playerId = playerId;
            newNode->next = NULL;

            if (rear == NULL) {
                front = rear = newNode;
                rear->next = front;
            } else {
                rear->next = newNode;
                rear = newNode;
                rear->next = front;
            }

            cout << "Player " << playerId << " added." << endl;
        }

       
        void nextTurn() {
            if (front == NULL) {
                cout << "Queue is empty." << endl;
                return;
            }

            Node* temp = front;
            front = front->next;
            rear->next = front;

            cout << "Player " << temp->playerId << "'s turn ended." << endl;
            delete temp;
        }

        void displayQueue() {
            if (front == NULL) {
                cout << "Queue is empty." << endl;
                return;
            }

            cout << "Current queue: ";
            Node* temp = front;

            do {
                cout << temp->playerId << " ";
                temp = temp->next;
            } while (temp != front);

            cout << endl;
        }
};

int main() {
    CircularQueue playerQueue;

    playerQueue.addPlayer(1);
    playerQueue.addPlayer(2);
    playerQueue.addPlayer(3);

    playerQueue.displayQueue();

    playerQueue.nextTurn();

    playerQueue.displayQueue();

    return 0;
}


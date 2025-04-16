#include <iostream>
using namespace std;

const int MAX_SIZE = 5; 

class CircularQueue {
    private:
        int requests[MAX_SIZE]; 
        int front, rear, count; 

    public:
        CircularQueue() {
            front = rear = count = 0; 
        }

   
        void addRequest(int requestId) {
            if (count == MAX_SIZE) {
                cout << "Queue is full. Cannot add request." << endl;
                return;
            }

            requests[rear] = requestId; 
            rear = (rear + 1) % MAX_SIZE; 
            count++; 

            cout << "Request " << requestId << " added to the queue." << endl;
        }

        // Function to process the oldest request
        void processRequest() {
            if (count == 0) {
                cout << "Queue is empty. No requests to process." << endl;
                return;
            }

            int processedId = requests[front]; 
            requests[front] = 0; 
            front = (front + 1) % MAX_SIZE; 
            count--; 

            cout << "Request " << processedId << " processed." << endl;
        }

       
        void displayQueue() {
            if (count == 0) {
                cout << "Queue is empty." << endl;
                return;
            }

            cout << "Current queue:" << endl;
            int tempFront = front; 

            for (int i = 0; i < count; i++) {
                cout << requests[tempFront] << " "; 
                tempFront = (tempFront + 1) % MAX_SIZE; 
            }

            cout << endl;
        }
};

int main() {
    CircularQueue requestQueue;

   
    requestQueue.addRequest(1);
    requestQueue.addRequest(2);
    requestQueue.addRequest(3);

    
    requestQueue.displayQueue();


    requestQueue.processRequest();

 
    requestQueue.displayQueue();

    
    requestQueue.addRequest(4);
    requestQueue.addRequest(5);


    requestQueue.displayQueue();

    return 0;
}


#include <iostream>
using namespace std;

const int MAX_SIZE = 3;  
char stack[MAX_SIZE];    
int top = -1;           


void push(char plate) {
    if (top == MAX_SIZE - 1) {
        cout << "Cannot add plate '" << plate << " The stack is full." << endl;
        return;
    }
    stack[++top] = plate;
    cout << "Added plate '" << plate << "' to the stack." << endl;
}


char pop() {
    if (top == -1) {
        cout << "Cannot remove a plate the stack is empty." << endl;
        return 0;
    }
    cout << "Removed plate '" << stack[top] << "' from the stack." << endl;
    return stack[top--];  
}


char peek() {
    if (top == -1) {
        cout << "The stack is empty" << endl;
        return 0; 
    }
    return stack[top];  
}


void display() {
    if (top == -1) {
        cout << "The stack is empty." << endl;
        return;
    }
    cout << "Plates in the stack: ";
    for (int i = top; i >= 0; --i) {
        cout << stack[i] << " ";
    }
    cout << endl;
}

int main() {
    push('A');  
    push('B'); 
    push('C');  
    push('D'); 

    display();  

    cout << "Top plate: " << peek() << endl;

    cout << "Popped: " << pop() << endl;  
    display();  

    pop();
    pop();  
    pop();  

    return 0;
}


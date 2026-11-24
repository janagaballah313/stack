#include <iostream>
using namespace std;
//****************   Stack   ******************************
const int n = 100;
struct statusUpdate {
    int claim_ID;
    string old_status;
    string new_status;
};
statusUpdate stack[n];
int top = -1;
bool ISfull() {
    return (top == n - 1);
}
void push(statusUpdate val) {
    if (ISfull()) {
        cout << "stack is overflow" << endl;
    }
    else {
        top++;
        stack[top] = val;

    }
}
bool ISempty() {
    return(top == -1);
}
void pop() {
    if (ISempty()) {
        cout << "stack is underflow" << endl;
    }
    else {
        cout << "the element is poped:" << stack[top].claim_ID << endl;
        top--;
    }
}
void Top() {
    if (ISempty()) {
        cout << "stack is Empty" << endl;
    }
    else {
        cout << "claim_id:" << stack[top].claim_ID << endl;
        cout << "old status:" << stack[top].old_status << endl;
        cout << "naw status:" << stack[top].new_status << endl;
    }
}
int Size() {
    return(top + 1);
}
void Display() {
    if (ISempty()) {
        cout << "stack is Empty" << endl;
    }
    else {
        cout << "stack element (top to bottom):" << endl;
        for (int i = top; i >= 0; i--) {
            cout << "claim id:" << stack[i].claim_ID << endl;
            cout << "old status:" << stack[i].old_status << endl;
            cout << "new status:" << stack[i].new_status << endl;
        }
    }
} 
//*********************    Queue   *********************************
const int m = 100;

struct queueClaim {
    int claim_ID;
    string customer_name;
    string claim_type;
    double amount;
};

queueClaim qarr[m];
int front = -1;
int rear = -1;
int count = 0;

bool qIsFull() {
    return (count == m);
}
bool qIsEmpty() {
    return  (count == 0);

}
void enqueue(queueClaim value) {
    if (qIsFull()) {
        cout << "The queue is full." << endl;
    }
    else {
        if (qIsEmpty()) {
            front = 0;
            rear = 0;
        }
        else {
            rear = (rear + 1) % m;
        }
        qarr[rear] = value;
        count++;
    }
    cout << "Claim: " << value.claim_ID << "added successfully." << endl;
}
void dequeue() {
    if (qIsEmpty()) {
        cout << "No claims are waiting for assessment" << endl;
    }
    else {
        cout << " The Claim  " << qarr[front].claim_ID << "(" << qarr[front].customer_name << ") has been processed and removed from the queue." << endl;

        if (count == 1) {
            front = -1;
            rear = -1;
        }
        else {
            front = (front + 1) % m;
        }
        count--;
    }
}
void getfront() {
    if (qIsEmpty()) {
        cout << "No claims are waiting" << endl;
    }
    else {
        cout << "Next claim : " << qarr[front].claim_ID << "(" << qarr[front].customer_name << ")" << endl;
    }
}

void SIZE() {
    if (qIsEmpty()) {
        cout << " No claims waiting ." << endl;
    } 
    cout << "  Claims waiting : " << count << endl;
}
void qdisplay() {
    if (qIsEmpty()) {
        cout << " No claims waiting." << endl;
    }
    else {
        cout << "All waiting claims:" << endl;
        cout << "--------------------------------------------------------" << endl;

        for (int i = 0; i < count; i++) {
            int indx = (front + i) % m;
            cout << "Claim number " << i + 1 << endl;
            cout << "  ID       : " << qarr[indx].claim_ID << endl;
            cout << "  Customer : " << qarr[indx].customer_name << endl;
            cout << "  Type     : " << qarr[indx].claim_type << endl;
            cout << "  Amount   : " << qarr[indx].amount << " EGP" << endl;
            cout << "--------------------------------------------------------" << endl;
        }
    }
}
//*********************   Linked List  ********************************

int main()
{
    int choice;
    do {
        cout << "******* Claims Management ********" << endl;
        cout << " 1. Add claim to queue" << endl;
        cout << " 2. Process next claim" << endl;
        cout << " 3. Show waiting claims" << endl;
        cout << " 4. Add status change" << endl;
        cout << " 5. Remove last status change" << endl;
        cout << " 6. Show status changes" << endl;   
        cout << "7. Show all claims " << endl;
        cout << " 0. Exit" << endl;
        cout << "  Enter your choice: ";

        cin >> choice;


        switch (choice) {
        case 1: {
            queueClaim c;
            cout << "Claim ID: ";
            cin >> c.claim_ID;
            cout << "Customer name (one word): ";
            cin >> c.customer_name;
            cout << "Claim type : ";
            cin >> c.claim_type;
            cout << "Amount (EGP): ";
            cin >> c.amount;
            enqueue(c);
            break;
        }
        case 2: dequeue();  break;
        case 3: QDisplay(); break;
        case 4: {
            statusUpdate u;
            cout << "Claim ID: ";
            cin >> u.claim_ID;
            cout << "Old status (one word): ";
            cin >> u.old_status;
            cout << "New status (one word): ";
            cin >> u.new_status;
            push(u);
            break;
        }
        case 5: pop();      break;
        case 6: Display();  break;
        case 7: qdisplay();  break;

        case 0: cout << "Goodbye." << endl; break;
        default: cout << "Invalid choice. Please  a number from the menu." << endl;
        }
    } while (choice != 0);

    return 0;
}


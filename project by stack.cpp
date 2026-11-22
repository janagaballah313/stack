#include <iostream>
using namespace std;
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
    else{
        cout << "the element is poped:" << stack[top].claim_ID<< endl;
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

int main()
{
    statusUpdate s1{ 101,"Pending","Approved" };
    statusUpdate s2{ 102,"Pending","Rejected" };
    statusUpdate s3{ 103,"Under Review ","Aprroved" };
    push(s1);
    push(s2);
    push(s3);
    Display();
    Top();
    cout << "stack size:" << Size() << endl;

}


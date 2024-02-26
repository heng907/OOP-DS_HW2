#include <iostream>
// please note that you are not allowed to include any container, such as <vector>, <list>, <queue>
using namespace std;


struct ListNode{
    // TODO: define your own ListNode with data and a pointer points to the next ListNode.
    int value;
    ListNode* next;
};

class Queue {
public:
    Queue(): head(nullptr), tail(nullptr) {}

    void push(int data) {
        // TODO: add a new data in the queue.
        ListNode* node=new ListNode;
        node->value=data;
        node->next=nullptr;

        if(isEmpty()){
                head=node;
        }
        else {
            tail->next=node;
        }
        tail=node;
    }

    int pop() {
        // TODO: pop a data from the queue,
        //       remember to deal with the case when there's already empty in the queue.

        if(isEmpty()) throw "Empty Queue.";

        int value = head->value;
        ListNode* tmp = head->next;
        if(!head->next) tail = nullptr;

        delete head;

        head = tmp;
        return value;

    }

    bool isEmpty() {
        // TODO: return true if the queue is empty, otherwise, false.
        return(head==nullptr&&tail==nullptr);

    }

    void printQueue() {

        // TODO: output all the data in the queue.

         if(isEmpty()) {
            cout << "Empty Queue." << endl;
            return;
         }
         cout << "Queue:";
        for(ListNode* n = head; n != nullptr; n = n->next) {
            cout << " " << n->value;
        }
        cout << endl;

    }

private:
    ListNode* head;
    ListNode* tail;
};

int main()
{
    Queue q;

    int num;
    while (cin >> num && num != -1){
        // TODO: create the initial queue
        q.push(num);
    }


    int selection; // selection: 1->push, 0->pop, -1->end
    while (cin >> selection && selection != -1){
        // TODO: allows user to do push or pop

          switch(selection) {
            case 0:
                try {
                    cout << q.pop() << endl;
                } catch(...) {
                    cout << "Invalid.\n-1" << endl;
                }
                break;
            case 1:
                cin >> selection;
                q.push(selection);
                break;
        }
    }

    // TODO: print every data in the queue at the end,
    //       you can check the empty case by using isEmpty() you create.

    q.printQueue();

    return 0;
}




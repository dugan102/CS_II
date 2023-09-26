#include <iostream>
using namespace std;
//jackson Dugan
//5755661

class LLData {
private:
    int data;
    LLData *next;
    LLData() {}
public:
    LLData(int d, LLData *nxt) {
        data = d;
        next = nxt;
    }
    int getData() { return data; }
    LLData* getNext() { return next; }
    void setData(int d) { data = d; }
    void setNext(LLData* nxt) { next = nxt; }
};
class LinkedList {
private:
    //LLData* first;
    LLData* dummyHead;
    LLData* dummyTail;
public:
    LinkedList() {
        //first = NULL;
        dummyHead = new LLData(-1, nullptr);
        dummyTail = new LLData(-1, nullptr);
        dummyHead->setNext(dummyTail);
    }
    LLData* getHead() { return dummyHead; }
    LLData* getTail() {return dummyTail; }
    //LLData *getFirst() { return first; }
    void addItem(int d) {
        LLData* newNode = new LLData(d, nullptr);
        newNode->setNext(dummyHead->getNext());
        dummyHead->setNext(newNode);

        //first = new LLData(d,first);
    }
    void showList() {
        LLData *curr = getHead();
        curr = curr->getNext();
        while (curr != getTail()) {
            cout << curr->getData() << " -> ";
            curr = curr->getNext();
        }
        cout << endl;
    }
    void addItemAtEnd(int d) {
        if (dummyHead->getNext() == dummyTail) {
            LLData* newNode = new LLData(d, nullptr);
            newNode->setNext(dummyHead->getNext());
            dummyHead->setNext(newNode);
        }
        else {
            LLData* curr = dummyHead;
            while (curr->getNext() != dummyTail) {
                curr = curr->getNext();
            }
            curr->setNext(new LLData(d,curr->getNext()));
        }
    }
};

int main() {
    LinkedList myList;
    myList.addItem(1);
    myList.addItemAtEnd(2);
    myList.addItem(3);
    myList.addItemAtEnd(4);
    myList.showList();
    myList.addItem(5);
    myList.addItemAtEnd(6);
    myList.showList();
    return 0;
}
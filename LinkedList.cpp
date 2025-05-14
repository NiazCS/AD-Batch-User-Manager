// LinkedList.cpp
// niaz hussain
// ad batch user manager
// cst 202 – data structures

#include "LinkedList.h"

// constructor initializes empty list
LinkedList::LinkedList() : head(nullptr), tail(nullptr) {}

// destructor deletes all nodes
LinkedList::~LinkedList() {
    ListNode* curr = head;
    while (curr) {
        ListNode* tmp = curr;
        curr = curr->next;
        delete tmp;
    }
}

bool LinkedList::isEmpty() const {
    return head == nullptr;
}

// add record to end of list
void LinkedList::append(const UserRecord& ur) {
    ListNode* node = new ListNode(ur);
    if (!head) {
        head = tail = node;
    }
    else {
        tail->next = node;
        tail = node;
    }
}

// get pointer to first node
ListNode* LinkedList::getHead() const {
    return head;
}

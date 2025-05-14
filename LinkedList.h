// LinkedList.h

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "UserRecord.h"

// singly?linked node storing one UserRecord
struct ListNode {
    UserRecord data;
    ListNode* next;
    ListNode(const UserRecord& ur) : data(ur), next(nullptr) {}
};

// simple queue?style linked list
class LinkedList {
private:
    ListNode* head;
    ListNode* tail;

public:
    LinkedList();
    ~LinkedList();

    bool isEmpty() const;
    void append(const UserRecord& ur);
    ListNode* getHead() const;
};

#endif

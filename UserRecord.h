// UserRecord.h
// niaz hussain
// ad batch user manager
// cst 202 – data structures

#ifndef USERRECORD_H
#define USERRECORD_H

#include <string>

// holds one csv entry: a user name and the action to take
struct UserRecord {
    std::string username;
    std::string action;    // "create", "disable", or "delete"

    UserRecord(const std::string& u = "", const std::string& a = "")
        : username(u), action(a) {
    }
};

#endif

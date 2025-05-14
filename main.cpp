// main.cpp
// niaz hussain
// ad batch user manager
// cst 202 – data structures

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <ctime>
#include "LinkedList.h"

// write one line to audit.log and echo to console
void logAction(const std::string& action,
    const std::string& user,
    std::ofstream& audit)
{
    // get current time
    std::time_t now = std::time(nullptr);
    // format into a buffer safely
    char timebuf[26];
    ctime_s(timebuf, sizeof(timebuf), &now);
    // remove trailing newline from ctime_s
    if (timebuf[24] == '\n') timebuf[24] = '\0';

    // log with timestamp
    audit << timebuf << " " << action << " user: " << user << "\n";
    std::cout << timebuf << " " << action << " user: " << user << "\n";
}

int main() {
    std::cout << "enter csv filename (username,action per line): ";
    std::string filename;
    std::getline(std::cin, filename);

    std::ifstream in(filename);
    if (!in.is_open()) {
        std::cerr << "cannot open " << filename << "\n";
        return 1;
    }

    // load all records into the list
    LinkedList list;
    std::string line;
    while (std::getline(in, line)) {
        if (line.empty()) continue;
        std::stringstream ss(line);
        std::string user, action;
        std::getline(ss, user, ',');
        std::getline(ss, action);
        list.append(UserRecord(user, action));
    }
    in.close();

    // open audit log (append mode)
    std::ofstream audit("audit.log", std::ios::app);
    if (!audit.is_open()) {
        std::cerr << "cannot open audit.log for writing\n";
        return 1;
    }

    // process each record in order
    ListNode* curr = list.getHead();
    while (curr) {
        const auto& rec = curr->data;
        if (rec.action == "create") {
            logAction("Created", rec.username, audit);
        }
        else if (rec.action == "disable") {
            logAction("Disabled", rec.username, audit);
        }
        else if (rec.action == "delete") {
            logAction("Deleted", rec.username, audit);
        }
        else {
            std::cout << "unknown action '" << rec.action
                << "' for user: " << rec.username << "\n";
        }
        curr = curr->next;
    }

    audit.close();
    std::cout << "audit log updated in audit.log\n";
    return 0;
}

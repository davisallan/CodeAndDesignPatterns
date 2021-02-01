/*
 * File Name: Client_A.cpp
 * Lab # and Assignment #: Lab 7 Exercise D
 * Lab section: B01
 * Completed by: Davis Allan, 10016543
 * Submission Date: Nov 6 2020
 */
#include "User.hpp"
#include "Client_A.hpp"

#include <iostream>
using namespace std;

Client_A::Client_A() {
    instance = LoginServer::getInstance();
}

Client_A::Client_A(const Client_A& source) {
    instance = LoginServer::getInstance();
}

Client_A& Client_A::operator = (const Client_A& rhs) {
    if (this != &rhs) {
        instance = LoginServer::getInstance();
    }
    return *this;
}

void Client_A::add(string username, string password) {
    instance->add(username, password);
}

User* Client_A::validate(string username, string password) {
    User* foundUser = instance->validate(username, password);
    return foundUser;
}

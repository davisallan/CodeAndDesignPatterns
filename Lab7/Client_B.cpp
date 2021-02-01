/*
 * File Name: Client_B.cpp
 * Lab # and Assignment #: Lab 7 Exercise D
 * Lab section: B01
 * Completed by: Davis Allan, 10016543
 * Submission Date: Nov 6 2020
 */
#include "User.hpp"
#include "Client_B.hpp"

#include <iostream>
using namespace std;

Client_B::Client_B() {
    instance = LoginServer::getInstance();
}

Client_B::Client_B(const Client_B& source) {
    instance = LoginServer::getInstance();
}

Client_B& Client_B::operator = (const Client_B& rhs) {
    if (this != &rhs) {
        instance = LoginServer::getInstance();
    }
    return *this;
}


void Client_B::add(string username, string password) {
    instance->add(username, password);
}

User* Client_B::validate(string username, string password) {
    User* foundUser = instance->validate(username, password);
    return foundUser;
}
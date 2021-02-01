/*
 * File Name: Client_B.hpp
 * Lab # and Assignment #: Lab 7 Exercise D
 * Lab section: B01
 * Completed by: Davis Allan, 10016543
 * Submission Date: Nov 6 2020
 */
#include "User.hpp"
#include "LoginServer.hpp"

#ifndef CLIENT_B_H
#define CLIENT_B_H

class Client_B {

public:
    Client_B();
    //  PROMISES: constructs a Client_A object and initializes its instance data member
    //  to the single instance of LoginServer

    Client_B(const Client_B& source);
    //  REQUIRES: source is a reference to a Client_A object
    //  PROMISES: constructs a new Client_A object and sets its instance data member to the 
    //  single instance of LoginServer

    Client_B& operator = (const Client_B& rhs);
    //  REQUIRES: rhs is a reference to a Client_A object
    //  PROMISES: copy and assign the data members of the rhs object to the Client_A
    //  object invoking this assignment

    void add(string username, string password);
    //  REQUIRES: username is not already entered in the user list
    //  PROMISES: creates a new User and adds it to the list

    User* validate(string username, string password);
    //  PROMISES: returns a pointer to the User matching the username and password arguments, 
    //  returns NULL if not found/username or password is incorrect

private:
    LoginServer* instance;
};

#endif
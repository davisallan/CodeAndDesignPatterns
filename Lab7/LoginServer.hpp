/*
 * File Name: LoginServer.hpp
 * Lab # and Assignment #: Lab 7 Exercise D
 * Lab section: B01
 * Completed by: Davis Allan, 10016543
 * Submission Date: Nov 6 2020
 */
#include <vector>
#include "User.hpp"

#ifndef LOGIN_SERVER_H
#define LOGIN_SERVER_H

class LoginServer{
    
public:
    static LoginServer* getInstance();
    //  PROMISES: returns the only instance of LoginServer

    void add(string username, string password);
    //  REQUIRES: username does not already exist in the server
    //  PROMISES: adds a new user to the system with the associated 
    //  username and password


    User* validate(string username, string password);
    //  REQUIRES: username and password are an exact match
    //  PROMISES: searches through the user vector returns a pointer to a 
    //  User struct with the matching username and password


private:
    LoginServer();
    //  PROMISES: constructs a new LoginServer object

    LoginServer(const LoginServer& src);
    //  REQUIRES: src is a reference to another LoginServer object
    //  PROMISES: constructs a copy of LoginServer object and ensures the object
    //  refers to the single instance of LoginServer, deep copies the user vector

    LoginServer& operator = (const LoginServer& rhs);
    //  REQUIRES: rhs is a reference to a LoginServer object
    //  PROMISES: copy and assign the data members of the rhs object to the LoginServer
    //  object invoking this assignment
    
    vector<User> users;
    static LoginServer* instance; 
};

#endif
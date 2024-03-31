#ifndef USER_HPP
#define USER_HPP

#include <bits/stdc++.h>
#include "Utility.hpp"

using namespace std;

class User
{
public:
    User() = default;
    User(const string &username, const string &password);
    ~User() = default;

    string getUsername() const;
    unsigned long getPasswordHash() const;

    void setPassword(const string &password);

    static int addUserToList(const string &username, const string &password);
    static int removeUserFromList(const string &username);
    static int editUserInList(const string &username, const string &password);
    static void displayUsersInList();

    static User getUserByUsername(const string &username);
    static set<User> getAllUsers();

    bool operator==(const User &user) const;
    bool operator<(const User &user) const;

    friend ifstream &operator>>(ifstream &in, User &user);
    friend ofstream &operator<<(ofstream &out, const User &user);

private:
    string username;
    unsigned long passwordHash;
};

void login(const string &username, const string &password);
void logout();
bool isLoggedIn();
User *getCurrentUser();

#endif
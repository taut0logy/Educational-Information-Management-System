#ifndef USER_HPP
#define USER_HPP

#include "Utility.hpp"

using namespace std;

class User
{
    public:
        
        ~User() = default;

        void setUsername(const string& username);
        void setPassword(const string& password);

        string getUsername() const;
        unsigned long getPasswordHash() const;

        static int addUserToList(const string& username, const string& password);
        static int removeUserFromList(const string& username);
        static int editUserInList(const string& username, const string& password);
        static void displayUsersInList();

        static User getUserByUsername(const string& username);
        static set<User> getAllUsers();

        bool operator==(const User& user) const;
        bool operator<(const User& user) const;

        friend ifstream &operator>>(ifstream &in, User &user);
        friend ofstream &operator<<(ofstream &out, const User &user);
        friend void login(string username, string password);



    private:
        string username;
        unsigned long passwordHash;

        User() = default;
        User(const string &username, const string &password);
};

#endif
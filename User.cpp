#include "User.hpp"

User::User(const string &username, const string &password)
{
    this->username = username;
    this->passwordHash = hashcode(password);
}

void User::setUsername(const string &username)
{
    this->username = username;
}

void User::setPassword(const string &password)
{
    passwordHash = hashcode(password);
}

string User::getUsername() const
{
    return username;
}

unsigned long User::getPasswordHash() const
{
    return passwordHash;
}

bool User::operator==(const User &user) const
{
    return username == user.username;
}

bool User::operator<(const User &user) const
{
    return username < user.username;
}

int User::addUserToList(const string &username, const string &password)
{
    User user(username, password);
    ifstream in("data/_users.txt");
    if (!in)
    {
        ofstream out("data/_users.txt");
        out << user;
        out.close();
        return 1;
    }
    in.close();
    set<User> users = getAllUsers();
    if (users.find(user) != users.end())
    {
        throw UserException("User already exists!");
    }
    ofstream out("data/_users.txt", ios::app);
    out << user;
    out.close();
    return 1;
}

int User::removeUserFromList(const string &username)
{
    ifstream in("data/_users.txt");
    if (!in)
    {
        throw UserException("Error: UserList File could not be opened!");
    }
    ofstream out("tempdata/_users.txt");
    if (!out)
    {
        throw UserException("Error: TempUserList File could not be opened!");
    }
    User temp;
    int flag = 0;
    while (in >> temp)
    {
        if (temp.getUsername() == username)
        {
            flag = 1;
            continue;
        }
        out << temp;
    }
    in.close();
    out.close();
    remove("data/_users.txt");
    rename("tempdata/_users.txt", "data/_users.txt");
    if (flag == 0)
    {
        throw UserException("Error: User not found!");
    }
    return 1;
}

int User::editUserInList(const string &username, const string &password)
{
    ifstream in("data/_users.txt");
    if (!in)
    {
        throw UserException("Error: UserList File could not be opened!");
    }
    ofstream out("tempdata/_users.txt");
    if (!out)
    {
        throw UserException("Error: TempUserList File could not be opened!");
    }
    User temp;
    int flag = 0;
    while (in >> temp)
    {
        if (temp.getUsername() == username)
        {
            flag = 1;
            temp.setPassword(password);
            out << temp;
            continue;
        }
        out << temp;
    }
    in.close();
    out.close();
    remove("data/_users.txt");
    rename("tempdata/_users.txt", "data/_users.txt");
    if (flag == 0)
    {
        throw UserException("Error: User not found!");
    }
    return 1;
}

void User::displayUsersInList()
{
    ifstream in("data/_users.txt");
    if (!in)
    {
        throw UserException("Error: UserList File could not be opened!");
    }
    User temp;
    while (in >> temp)
    {
        cout << temp.username << endl;
    }
    in.close();
}

User User::getUserByUsername(const string &username)
{
    ifstream in("data/_users.txt");
    if (!in)
    {
        throw UserException("Error: UserList File could not be opened!");
    }
    User temp;
    while (in >> temp)
    {
        if (temp.getUsername() == username)
        {
            in.close();
            return temp;
        }
    }
    in.close();
    throw UserException("Error: User not found!");
}

set<User> User::getAllUsers()
{
    ifstream in("data/_users.txt");
    if (!in)
    {
        throw UserException("Error: UserList File could not be opened!");
    }
    set<User> users;
    User temp;
    while (in >> temp)
    {
        users.insert(temp);
    }
    in.close();
    return users;
}

ifstream &operator>>(ifstream &in, User &user)
{
    in >> user.username >> user.passwordHash;
    return in;
}

ofstream &operator<<(ofstream &out, const User &user)
{
    out << user.username << "\t" << user.passwordHash << endl;
    return out;
}

User *currentUser = nullptr;

void login(string username, string password)
{
    ifstream in("data/_users.txt");
    if (!in)
    {
        throw UserException("UserList File could not be opened!");
    }
    User temp;
    while (in >> temp)
    {
        if (temp.getUsername() == username && temp.getPasswordHash() == hashcode(password))
        {
            currentUser = new User(temp);
            return;
        }
    }
    throw UserException("Invalid Username or Password!");
}

void logout()
{
    delete currentUser;
    currentUser = nullptr;
}

bool isLoggedIn()
{
    return currentUser != nullptr;
}

User *getCurrentUser()
{
    return currentUser;
}
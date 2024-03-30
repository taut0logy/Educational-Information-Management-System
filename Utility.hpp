#ifndef UTILITY_HPP
#define UTILITY_HPP

#include <iostream>
#include <fstream>
#include <exception>
#include <stdexcept>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <random>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

#include "User.hpp"

using namespace std;

class TeacherException : public exception
{
public:
    TeacherException(const string &message) : message(message) {}
    TeacherException() : message("") {}
    virtual const char *what() const noexcept override
    {
        if (message.empty())
        {
            return "Teacher Exception!";
        }
        return message.c_str();
    }

private:
    string message;
};

class CourseException : public exception
{
public:
    CourseException(const string &message) : message(message) {}
    CourseException() : message("") {}
    virtual const char *what() const noexcept override
    {
        if (message.empty())
        {
            return "Course Exception!";
        }
        return message.c_str();
    }

private:
    string message;
};

class UserException : public exception
{
public:
    UserException(const string &message) : message(message) {}
    UserException() : message("") {}
    virtual const char *what() const noexcept override
    {
        if (message.empty())
        {
            return "User Exception!";
        }
        return message.c_str();
    }

private:
    string message;
};

void clearTerminal()
{
#ifdef _WIN32
    system("cls"); // For Windows
#else
    system("clear"); // For Unix-like systems
#endif
}

void inputPassword(string &password)
{
    char ch;
    password = "";
    while (true)
    {
        ch = cin.get();
        if (ch == '\n')
        {
            break;
        }
        password += ch;
        cout << '*';
    }
}

string getRandomID()
{
    string id = "";
    for (int i = 0; i < 6; i++)
    {
        id += to_string(rand() % 10);
    }
    return id;
}

unsigned long hashcode(const string &str)
{
    unsigned long hash = 5381;
    for (char c : str)
    {
        hash = ((hash << 5) + hash) + c;
    }
    return hash;
}

#endif
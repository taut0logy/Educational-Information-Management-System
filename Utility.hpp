#ifndef UTILITY_HPP
#define UTILITY_HPP

#include <bits/stdc++.h>
#include <conio.h>

using namespace std;

class TeacherException : public exception
{
public:
    TeacherException(const string &message);
    TeacherException();
    virtual const char *what() const noexcept override;

private:
    string message;
};

class CourseException : public exception
{
public:
    CourseException(const string &message);
    CourseException();
    virtual const char *what() const noexcept override;

private:
    string message;
};

class UserException : public exception
{
public:
    UserException(const string &message);
    UserException();
    virtual const char *what() const noexcept override;

private:
    string message;
};
string toLowerCase(const string& str);

string toUpperCase(const string& str);

void clearTerminal();


void inputPassword(string &password);


string getRandomID();

unsigned long hashcode(const string &str);


#endif
#ifndef COURSE_HPP
#define COURSE_HPP

#include "Utility.hpp"
#include <bits/stdc++.h>

using namespace std;

class Course
{
public:
    Course() = default;
    Course(const string &name, const string &code, const double &creditHours, const string &department, const int &semester, const int &year, const string &teacherID);
    ~Course() = default;

    void setName(const string &name);
    void setCode(const string &code);
    void setCreditHours(const double &creditHours);
    void setDepartment(const string &department);
    void setSemester(const int &semester);
    void setYear(const int &year);
    void setTeacherID(const string &teacherID);

    string getName() const;
    string getCode() const;
    double getCreditHours() const;
    string getDepartment() const;
    int getSemester() const;
    int getYear() const;
    string getTeacherID() const;

    static int addCourseToList(const Course &course);
    static int removeCourseFromList(const Course &course);
    static int editCourseInList(const Course &course);
    static void displayCoursesInList();

    static Course getCourseByCode(const string &code);
    static set<Course> getCoursesByName(const string &name);
    static set<Course> getCoursesByDepartment(const string &department);
    static set<Course> getCoursesBySemester(const int &semester);
    static set<Course> getCoursesByYear(const int &year);
    static set<Course> getCoursesByTeacherID(const string &teacherID);
    static set<Course> getAllCourses();

    bool operator==(const Course &course) const;
    bool operator<(const Course &course) const;

    friend ostream &operator<<(ostream &out, const Course &course);
    friend ifstream &operator>>(ifstream &in, Course &course);
    friend ofstream &operator<<(ofstream &out, const Course &course);

private:
    string name;
    string code;
    double creditHours;
    string department;
    int semester;
    int year;
    string teacherID;
};

#endif
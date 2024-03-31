#ifndef TEACHER_HPP
#define TEACHER_HPP

#include <bits/stdc++.h>
#include "Utility.hpp"
#include "Course.hpp"

using namespace std;

class Teacher {
    public:
        Teacher() = default;
        Teacher(const string &name, const string &id, const string &department, const string &email, const string &phone, const string &address, const int &officeRoom, const string &designation, const string &joiningDate, const string &qualification);
        Teacher(const Teacher& teacher);
        Teacher(Teacher&& teacher) noexcept;
        Teacher& operator=(const Teacher& teacher);
        Teacher& operator=(Teacher&& teacher) noexcept;

        bool operator==(const Teacher& teacher) const;
        bool operator<(const Teacher& teacher) const;

        static set<string> getTeachersIdList();
        static set<Teacher> getTeachersList();
        static Teacher getTeacherById(const string& id);
        static set<Teacher> getTeacherByName(const string& name);
        static set<Teacher> getTeacherByDepartment(const string& department);
        static set<Teacher> getTeacherByDesignation(const string& designation);

        static Teacher createNewTeacher(const string& name, const string& department, const string& email, const string& phone, const string& address, const int& officeRoom, const string& designation, const string& joiningDate, const string& qualification);
        void deletePermenantly();
        int edit(Teacher& teacher);

        void setName(const string& name);
        void setId(const string& id);
        void setDepartment(const string& department);
        void setEmail(const string& email);
        void setPhone(const string& phone);
        void setAddress(const string& address);
        void setOfficeRoom(const int& officeRoom);
        void setDesignation(const string& designation);
        void setJoiningDate(const string& joiningDate);
        void setQualification(const string& qualification);

        int addCourse(const string &courseID);
        void removeCourse(const string &courseID);
        void editCourse(const Course& course);
        void displayCourses() const;

        string getName() const;
        string getId() const;
        string getDepartment() const;
        string getEmail() const;
        string getPhone() const;
        string getAddress() const;
        int getOfficeRoom() const;
        string getDesignation() const;
        string getJoiningDate() const;
        string getQualification() const;
        vector<Course> getCourses() const;

        friend ostream &operator<<(ostream &out, const Teacher &teacher);
        friend ifstream &operator>>(ifstream &in, Teacher &teacher);
        friend ofstream &operator<<(ofstream &out, const Teacher &teacher);

    private:
        string name;
        string id;
        string department;
        string email;
        string phone;
        string address;
        int officeRoom;
        string designation;
        string joiningDate;
        string qualification;
        vector<Course> courses;
};

#endif
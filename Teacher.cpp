#include "Teacher.hpp"

Teacher::Teacher(const string &name, const string &id, const string &department, const string &email, const string &phone, const string &address, const int &officeRoom, const string &designation, const string &joiningDate, const string &qualification)
{
    this->name = name;
    this->id = id;
    this->department = department;
    this->email = email;
    this->phone = phone;
    this->address = address;
    this->officeRoom = officeRoom;
    this->designation = designation;
    this->joiningDate = joiningDate;
    this->qualification = qualification;
    this->courses = {};
}

Teacher::Teacher(const Teacher &teacher)
{
    name = teacher.name;
    id = teacher.id;
    department = teacher.department;
    email = teacher.email;
    phone = teacher.phone;
    address = teacher.address;
    officeRoom = teacher.officeRoom;
    designation = teacher.designation;
    joiningDate = teacher.joiningDate;
    qualification = teacher.qualification;
    courses = vector<Course>(teacher.courses.begin(), teacher.courses.end());
}

Teacher::Teacher(Teacher &&teacher) noexcept
{
    name = move(teacher.name);
    id = move(teacher.id);
    department = move(teacher.department);
    email = move(teacher.email);
    phone = move(teacher.phone);
    address = move(teacher.address);
    officeRoom = move(teacher.officeRoom);
    designation = move(teacher.designation);
    joiningDate = move(teacher.joiningDate);
    qualification = move(teacher.qualification);
    courses = move(teacher.courses);
}

Teacher &Teacher::operator=(const Teacher &teacher)
{
    if (this == &teacher)
    {
        return *this;
    }
    name = teacher.name;
    id = teacher.id;
    department = teacher.department;
    email = teacher.email;
    phone = teacher.phone;
    address = teacher.address;
    officeRoom = teacher.officeRoom;
    designation = teacher.designation;
    joiningDate = teacher.joiningDate;
    qualification = teacher.qualification;
    courses = vector<Course>(teacher.courses.begin(), teacher.courses.end());
    return *this;
}

Teacher &Teacher::operator=(Teacher &&teacher) noexcept
{
    if (this == &teacher)
    {
        return *this;
    }
    name = move(teacher.name);
    id = move(teacher.id);
    department = move(teacher.department);
    email = move(teacher.email);
    phone = move(teacher.phone);
    address = move(teacher.address);
    officeRoom = move(teacher.officeRoom);
    designation = move(teacher.designation);
    joiningDate = move(teacher.joiningDate);
    qualification = move(teacher.qualification);
    courses = move(teacher.courses);
    return *this;
}

set<string> Teacher::getTeachersIdList()
{
    set<string> teachers;
    ifstream in("data/_teacherList.txt");
    if (!in.is_open())
    {
        return teachers;
    }
    Teacher t;
    while (in >> t)
    {
        string id = t.getId();
        teachers.insert(id);
        cout << "";
    }
    in.close();
    return teachers;
}

set<Teacher> Teacher::getTeachersList()
{
    set<Teacher> teachers;
    ifstream in("data/_teacherList.txt");
    if (!in.is_open())
    {
        throw TeacherException("File could not be opened!");
    }
    Teacher t;
    while (in >> t)
    {
        teachers.insert(t);
    }
    in.close();
    return teachers;
}

Teacher Teacher::getTeacherById(const string &id)
{
    ifstream in("data/_teacherList.txt");
    if (!in.is_open())
    {
        throw TeacherException("File could not be opened!");
    }
    Teacher t;
    while (in >> t)
    {
        if (t.getId() == id)
        {
            in.close();
            return t;
        }
    }
    in.close();
    throw TeacherException("Teacher not found!");
}

set<Teacher> Teacher::getTeacherByName(const string &name)
{
    set<Teacher> teachers;
    ifstream in("data/_teacherList.txt");
    if (!in.is_open())
    {
        throw TeacherException("File could not be opened!");
    }
    Teacher t;
    while (in >> t)
    {
        if (t.getName() == name)
        {
            teachers.insert(t);
        }
    }
    in.close();
    return teachers;
}

set<Teacher> Teacher::getTeacherByDepartment(const string &department)
{
    set<Teacher> teachers;
    ifstream in("data/_teacherList.txt");
    if (!in.is_open())
    {
        throw TeacherException("File could not be opened!");
    }
    Teacher t;
    while (in >> t)
    {
        if (t.getDepartment() == department)
        {
            teachers.insert(t);
        }
    }
    in.close();
    return teachers;
}

set<Teacher> Teacher::getTeacherByDesignation(const string &designation)
{
    set<Teacher> teachers;
    ifstream in("data/_teacherList.txt");
    if (!in.is_open())
    {
        throw TeacherException("File could not be opened!");
    }
    Teacher t;
    while (in >> t)
    {
        if (t.getDesignation() == designation)
        {
            teachers.insert(t);
        }
    }
    in.close();
    return teachers;
}

Teacher Teacher::createNewTeacher(const string &name, const string &department, const string &email, const string &phone, const string &address, const int &officeRoom, const string &designation, const string &joiningDate, const string &qualification)
{

    set<string> teachers = Teacher::getTeachersIdList();
    string id = "T" + getRandomID();
    while (teachers.find(id) != teachers.end())
    {
        id = "T" + getRandomID();
    }

    Teacher teacher(name, id, department, email, phone, address, officeRoom, designation, joiningDate, qualification);
    ifstream in("data/_teacherList.txt");
    if (!in.is_open())
    {
        ofstream out("data/_teacherList.txt");
        if (!out.is_open())
        {
            throw TeacherException("File could not be opened!");
        }
        out << teacher;
        out.close();
        return teacher;
    }
    ofstream out("data/_tempTeacherList.txt");
    if (!out.is_open())
    {
        throw TeacherException("Temp File could not be opened!");
    }
    Teacher t;
    while (in >> t)
    {
        // cout << t.getId() << ' ' << t.getName() << endl;
        out << t;
    }
    out << teacher;
    in.close();
    out.close();
    remove("data/_teacherList.txt");
    rename("data/_tempTeacherList.txt", "data/_teacherList.txt");
    return teacher;
}

void Teacher::deletePermenantly()
{
    ifstream in("data/_teacherList.txt");
    if (!in.is_open())
    {
        throw TeacherException("File could not be opened!");
    }
    ofstream out("data/_tempTeacherList.txt");
    Teacher t;
    while (in >> t)
    {
        if (t == *this)
        {
            continue;
        }
        out << t;
    }
    in.close();
    out.close();
    remove("data/_teacherList.txt");
    rename("data/_tempTeacherList.txt", "data/_teacherList.txt");
}

int Teacher::edit(Teacher &teacher)
{
    ifstream in("data/_teacherList.txt");
    if (!in.is_open())
    {
        throw TeacherException("File could not be opened!");
    }
    ofstream out("data/_tempTeacherList.txt");
    Teacher t;
    int flag = 0;
    while (in >> t)
    {
        if (t == *this)
        {
            flag = 1;
            out << teacher;
        }
        else
        {
            out << t;
        }
    }
    in.close();
    out.close();
    remove("data/_teacherList.txt");
    rename("data/_tempTeacherList.txt", "data/_teacherList.txt");
    return flag;
}

void Teacher::setName(const string &name)
{
    this->name = name;
}

void Teacher::setId(const string &id)
{
    this->id = id;
}

void Teacher::setDepartment(const string &department)
{
    this->department = department;
}

void Teacher::setEmail(const string &email)
{
    this->email = email;
}

void Teacher::setPhone(const string &phone)
{
    this->phone = phone;
}

void Teacher::setAddress(const string &address)
{
    this->address = address;
}

void Teacher::setOfficeRoom(const int &officeRoom)
{
    this->officeRoom = officeRoom;
}

void Teacher::setDesignation(const string &designation)
{
    this->designation = designation;
}

void Teacher::setJoiningDate(const string &joiningDate)
{
    this->joiningDate = joiningDate;
}

void Teacher::setQualification(const string &qualification)
{
    this->qualification = qualification;
}

int Teacher::addCourse(const string &courseID)
{
    Course course = Course::getCourseByCode(courseID);
    if (course.getTeacherID() != "")
    {
        if (course.getTeacherID() == id)
        {
            return -1;
        }
        return 0;
    }
    courses.push_back(course);
    course.setTeacherID(id);
    Course::editCourseInList(course);
    Teacher::edit(*this);
    return 1;
}

void Teacher::removeCourse(const string &courseID)
{
    Course course = Course::getCourseByCode(courseID);
    for (auto it = courses.begin(); it != courses.end(); it++)
    {
        if (it->getCode() == course.getCode())
        {
            it->setTeacherID("");
            Course::editCourseInList(*it);
            courses.erase(it);
            Teacher::edit(*this);
            break;
        }
    }
    throw TeacherException("Course not found!");
}

void Teacher::editCourse(const Course &course)
{
    for (auto it = courses.begin(); it != courses.end(); it++)
    {
        if (it->getCode() == course.getCode())
        {
            *it = course;
            Course::editCourseInList(course);
            break;
        }
    }
}

void Teacher::displayCourses() const
{
    for (auto it = courses.begin(); it != courses.end(); it++)
    {
        cout << "Course Name: " << it->getName() << "\t"; // "Course Name:
        cout << "Course Code: " << it->getCode() << endl;
    }
}

string Teacher::getName() const
{
    return name;
}

string Teacher::getId() const
{
    return id;
}

string Teacher::getDepartment() const
{
    return department;
}

string Teacher::getEmail() const
{
    return email;
}

string Teacher::getPhone() const
{
    return phone;
}

string Teacher::getAddress() const
{
    return address;
}

int Teacher::getOfficeRoom() const
{
    return officeRoom;
}

string Teacher::getDesignation() const
{
    return designation;
}

string Teacher::getJoiningDate() const
{
    return joiningDate;
}

string Teacher::getQualification() const
{
    return qualification;
}

vector<Course> Teacher::getCourses() const
{
    return courses;
}

bool Teacher::operator==(const Teacher &teacher) const
{
    return id == teacher.id;
}

bool Teacher::operator<(const Teacher &teacher) const
{
    return id < teacher.id;
}

ostream &operator<<(ostream &out, const Teacher &teacher)
{
    out << "---ID: " << teacher.id << "---\n";
    out << "Name: " << teacher.name << endl;
    out << "Department: " << teacher.department << endl;
    out << "Email: " << teacher.email << endl;
    out << "Phone: " << teacher.phone << endl;
    out << "Address: " << teacher.address << endl;
    out << "Office Room: " << teacher.officeRoom << endl;
    out << "Designation: " << teacher.designation << endl;
    out << "Joining Date: " << teacher.joiningDate << endl;
    out << "Qualification: " << teacher.qualification << endl;
    out << "Courses: " << endl;
    for (Course c : teacher.courses)
    {
        out << c;
    }
    out << endl;
    return out;
}

ifstream &operator>>(ifstream &in, Teacher &teacher)
{
    getline(in, teacher.id);
    getline(in, teacher.name);
    getline(in, teacher.department);
    getline(in, teacher.email);
    getline(in, teacher.phone);
    getline(in, teacher.address);
    in >> teacher.officeRoom;
    in.ignore();
    getline(in, teacher.designation);
    getline(in, teacher.joiningDate);
    getline(in, teacher.qualification);
    int n;
    in >> n;
    in.ignore();
    Course c;
    for (int i = 0; i < n; i++)
    {
        in >> c;
        teacher.courses.push_back(c);
    }
    return in;
}

ofstream &operator<<(ofstream &out, const Teacher &teacher)
{
    out << teacher.id << "\n"
        << teacher.name << "\n"
        << teacher.department << "\n"
        << teacher.email << "\n"
        << teacher.phone << "\n"
        << teacher.address << "\n"
        << teacher.officeRoom << "\n"
        << teacher.designation << "\n"
        << teacher.joiningDate << "\n"
        << teacher.qualification << "\n"
        << teacher.courses.size() << "\n";
    for (Course c : teacher.courses)
    {
        out << c << "\n";
    }
    return out;
}
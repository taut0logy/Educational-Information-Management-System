#include "Course.hpp"

Course::Course(const string &name, const string &code, const double &creditHours, const string &department, const int &semester, const int &year, const string &teacherID)
{
    this->name = name;
    this->code = code;
    this->creditHours = creditHours;
    this->department = department;
    this->semester = semester;
    this->year = year;
    this->teacherID = teacherID;
}

bool Course::operator==(const Course &course) const
{
    return code == course.code;
}

bool Course::operator<(const Course &course) const
{
    return code < course.code;
}

void Course::setName(const string &name)
{
    this->name = name;
}

void Course::setCode(const string &code)
{
    this->code = code;
}

void Course::setCreditHours(const double &creditHours)
{
    this->creditHours = creditHours;
}

void Course::setDepartment(const string &department)
{
    this->department = department;
}

void Course::setSemester(const int &semester)
{
    this->semester = semester;
}

void Course::setYear(const int &year)
{
    this->year = year;
}

void Course::setTeacherID(const string &teacherID)
{
    this->teacherID = teacherID;
}

string Course::getName() const
{
    return name;
}

string Course::getCode() const
{
    return code;
}

double Course::getCreditHours() const
{
    return creditHours;
}

string Course::getDepartment() const
{
    return department;
}

int Course::getSemester() const
{
    return semester;
}

int Course::getYear() const
{
    return year;
}

string Course::getTeacherID() const
{
    return teacherID;
}

int Course::addCourseToList(const Course &course)
{
    ifstream file("data/_courseList.txt");
    if (!file.is_open())
    {
        ofstream file2("data/_courseList.txt");
        if (!file2.is_open())
        {
            throw CourseException("CourseList File could not be created!");
        }
        file2 << course;
        file2.close();
        return 1;
    }
    file.seekg(0, ios::beg);
    Course temp;
    while (file >> temp)
    {
        cout << temp.getCode() << " " << course.getCode() << endl;
        if (temp.getCode() == course.getCode())
        {
            file.close();
            return 0;
        }
    }
    file.close();
    ofstream file2("data/_courseList.txt", ios::app);
    if (!file2.is_open())
    {
        throw CourseException("CourseList File could not be opened!");
    }
    file2 << course;
    file2.close();
    return 1;
}

int Course::removeCourseFromList(const Course &course)
{
    ifstream file("data/_courseList.txt");
    if (!file.is_open())
    {
        throw CourseException("CourseList File could not be opened!");
    }
    ofstream file2("data/_tempCourseList.txt");
    if (!file2.is_open())
    {
        throw CourseException("TempCourseList File could not be opened!");
    }
    Course temp;
    int flag = 0;
    while (file >> temp)
    {
        if (temp == course)
        {
            flag = 1;
            continue;
        }
        file2 << temp;
    }
    file.close();
    file2.close();
    remove("data/_courseList.txt");
    rename("data/_tempCourseList.txt", "data/_courseList.txt");
    return flag;
}

int Course::editCourseInList(const Course &course)
{
    ifstream file("data/_courseList.txt");
    if (!file.is_open())
    {
        throw CourseException("CourseList File could not be opened!");
    }
    ofstream file2("data/_tempCourseList.txt");
    if (!file2.is_open())
    {
        throw CourseException("TempCourseList File could not be opened!");
    }
    Course temp;
    int flag = 0;
    while (file >> temp)
    {
        if (temp == course)
        {
            flag = 1;
            file2 << course;
            continue;
        }
        file2 << temp;
    }
    file.close();
    file2.close();
    remove("data/_courseList.txt");
    rename("data/_tempCourseList.txt", "data/_courseList.txt");
    return flag;
}

void Course::displayCoursesInList()
{
    ifstream file("data/_courseList.txt");
    if (!file.is_open())
    {
        throw CourseException("CourseList File could not be opened!");
    }
    Course temp;
    while (file >> temp)
    {
        cout << temp;
    }
    file.close();
}

Course Course::getCourseByCode(const string &code)
{
    ifstream file("data/_courseList.txt");
    if (!file.is_open())
    {
        throw CourseException("CourseList File could not be opened!");
    }
    Course temp;
    while (file >> temp)
    {
        if (toLowerCase(temp.getCode()) == toLowerCase(code))
        {
            file.close();
            return temp;
        }
    }
    file.close();
    throw CourseException("Course not found!");
}

set<Course> Course::getCoursesByName(const string &name)
{
    ifstream file("data/_courseList.txt");
    if (!file.is_open())
    {
        throw CourseException("CourseList File could not be opened!");
    }
    Course temp;
    set<Course> courses;
    while (file >> temp)
    {
        if (toLowerCase(temp.getName()).find(toLowerCase(name)) != string::npos)
        {
            courses.insert(temp);
        }
    }
    file.close();
    return courses;
}

set<Course> Course::getCoursesByDepartment(const string &department)
{
    ifstream file("data/_courseList.txt");
    if (!file.is_open())
    {
        throw CourseException("CourseList File could not be opened!");
    }
    Course temp;
    set<Course> courses;
    while (file >> temp)
    {
        if (toLowerCase(temp.getDepartment()) == toLowerCase(department))
        {
            courses.insert(temp);
        }
    }
    file.close();
    return courses;
}

set<Course> Course::getCoursesBySemester(const int &semester)
{
    ifstream file("data/_courseList.txt");
    if (!file.is_open())
    {
        throw CourseException("CourseList File could not be opened!");
    }
    Course temp;
    set<Course> courses;
    while (file >> temp)
    {
        if (temp.getSemester() == semester)
        {
            courses.insert(temp);
        }
    }
    file.close();
    return courses;
}

set<Course> Course::getCoursesByYear(const int &year)
{
    ifstream file("data/_courseList.txt");
    if (!file.is_open())
    {
        throw CourseException("CourseList File could not be opened!");
    }
    Course temp;
    set<Course> courses;
    while (file >> temp)
    {
        if (temp.getYear() == year)
        {
            courses.insert(temp);
        }
    }
    file.close();
    return courses;
}

set<Course> Course::getCoursesByTeacherID(const string &teacherID)
{
    ifstream file("data/_courseList.txt");
    if (!file.is_open())
    {
        throw CourseException("CourseList File could not be opened!");
    }
    Course temp;
    set<Course> courses;
    while (file >> temp)
    {
        if (temp.getTeacherID() == teacherID)
        {
            courses.insert(temp);
        }
    }
    file.close();
    return courses;
}

set<Course> Course::getAllCourses()
{
    ifstream file("data/_courseList.txt");
    if (!file.is_open())
    {
        throw CourseException("CourseList File could not be opened!");
    }
    Course temp;
    set<Course> courses;
    while (file >> temp)
    {
        courses.insert(temp);
    }
    file.close();
    return courses;
}

ostream &operator<<(ostream &out, const Course &course)
{
    out << "--- Course Code: " << course.code << " ---\n"
        << "Course Name: " << course.name
        << "\t Credit Hours: " << course.creditHours << "\t Department: "
        << course.department << "\t Semester: " << course.semester
        << "\t Year: " << course.year << "\t Assigned Teacher ID: "
        << ((course.teacherID.empty() || course.teacherID == "**") ? "[Unassigned]" : course.teacherID) << endl
        << endl;
    return out;
}

ifstream &operator>>(ifstream &in, Course &course)
{
    in >> course.code;
    in.ignore();
    getline(in, course.name);
    in >> course.creditHours >> course.department >> course.semester >> course.year >> course.teacherID;
    return in;
}

ofstream &operator<<(ofstream &out, const Course &course)
{
    out << course.code << "\n"
        << course.name << "\n"
        << course.creditHours << " " << course.department << " " << course.semester << " " << course.year << " " << ((course.teacherID.empty()) ? "**" : course.teacherID) << endl;
    return out;
}

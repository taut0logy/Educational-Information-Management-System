#include "Teacher.hpp"
// #include "Course.hpp"
#include "User.hpp"
// #include "Utility.hpp"

using namespace std;

void showWelcomeMessage()
{
    cout << "      __--__                                          __--__" << endl;
    cout << "  __--      --__          Welcome to the          __--      --__" << endl;
    cout << "--__          __--   Eduicational Information   --__          __--" << endl;
    cout << "    --__  __--  |        Management System          --__  __--  |" << endl;
    cout << "     |  --  |   |                                    |  --  |   |" << endl;
    cout << "      --__--    *                                     --__--    *" << endl;
    cout << endl
         << endl;
}

void showAboutMessage()
{
    cout << "This is an Educational Information Management System." << endl;
    cout << "It is designed to manage and access the information teachers, and courses." << endl;
    cout << "An admin can add, remove, and display users, Teachers or Courses." << endl;
    cout << "Students can view detailed information about their teachers." << endl;
    cout << "Press Enter to continue...";
}

void showMainMenu()
{
    cout << "         Please select an option from the following menu:" << endl;
    cout << "                         1. Login" << endl;
    cout << "                         2. About" << endl;
    cout << "                         3. Exit" << endl;
    cout << endl;
}

void showAdminMenu()
{
    cout << "         Please select an option from the following menu:" << endl
         << endl;
    cout << "                         1. Add User" << endl;
    cout << "                         2. Remove User" << endl;
    cout << "                         3. Display Users" << endl;
    cout << "                         4. Manage Teachers" << endl;
    cout << "                         5. Manage Courses" << endl;
//    cout << "                         6. Change Password" << endl;
    cout << "                         6. Logout" << endl;
    cout << "                         0. Exit" << endl;
    cout << endl;
}

void showAdminCourseMenu()
{
    cout << "         Please select an option from the following menu:" << endl
         << endl;
    cout << "                         1. Add Course" << endl;
    cout << "                         2. Remove Course" << endl;
    cout << "                         3. Edit Course" << endl;
    cout << "                         4. Display All Courses" << endl;
    cout << "                         5. Display Course by Code" << endl;
    cout << "                         6. Display Courses by Name" << endl;
    cout << "                         7. Display Courses by Department" << endl;
    cout << "                         8. Display Courses by Semester" << endl;
    cout << "                         9. Display Courses by Year" << endl;
    cout << "                         10. Display courses assigned to teacher" << endl;
    cout << "                         11. Assign Teacher" << endl;
    cout << "                         12. Unassign Teacher" << endl;
    cout << "                         13. Logout" << endl;
    cout << "                         14. Go Back" << endl;
    cout << "                         0. Exit" << endl;
    cout << endl;
}

void showAdminTeacherMenu()
{
    cout << "         Please select an option from the following menu:" << endl
         << endl;
    cout << "                         1. Add Teacher" << endl;
    cout << "                         2. Remove Teacher" << endl;
    cout << "                         3. Edit Teacher" << endl;
    cout << "                         4. Display All Teachers" << endl;
    cout << "                         5. Find Teacher by ID" << endl;
    cout << "                         6. Display Teachers by Name" << endl;
    cout << "                         7. Display Teachers by Department" << endl;
    cout << "                         8. Display Teachers by Designation" << endl;
    cout << "                         9. Logout" << endl;
    cout << "                         10. Go Back" << endl;
    cout << "                         0. Exit" << endl;
    cout << endl;
}

void showUserMenu()
{
    cout << "         Please select an option from the following menu:" << endl
         << endl;
    cout << "                         1. View Teachers" << endl;
    cout << "                         2. View Courses" << endl;
    cout << "                         3. Change Password" << endl;
    cout << "                         4. Logout" << endl;
    cout << "                         0. Exit" << endl;
    cout << endl;
}

void showUserTeacherMenu()
{
    cout << "         Please select an option from the following menu:" << endl
         << endl;
    cout << "                         1. View Teacher by ID" << endl;
    cout << "                         2. View Teacher by Name" << endl;
    cout << "                         3. View Teacher by Department" << endl;
    cout << "                         4. View Teacher by Designation" << endl;
    cout << "                         5. Go Back" << endl;
    cout << "                         6. Logout" << endl;
    cout << "                         0. Exit" << endl;
    cout << endl;
}

void showUserCourseMenu()
{
    cout << "         Please select an option from the following menu:" << endl
         << endl;
    cout << "                         1. View Course by ID" << endl;
    cout << "                         2. View Course by Name" << endl;
    cout << "                         3. View Course by Department" << endl;
    cout << "                         4. View Course by Semester" << endl;
    cout << "                         5. View Course by Year" << endl;
    cout << "                         6. View Course by Teacher" << endl;
    cout << "                         7. Go Back" << endl;
    cout << "                         8. Logout" << endl;
    cout << "                         0. Exit" << endl;
    cout << endl;
}

int main()
{
    // Teacher teacher = Teacher::getTeacherById("T940817");
    // teacher.removeCourse("CS102");
    // cout << (teacher.getId()) << endl;
    //  Course course("OOP", "CS102", 36, "CSE", 2, 1, "");
    //  int res = Course::addCourseToList(course);
    //  cout << res << endl;
    // cin.ignore();

    int choice;
    do
    {
        clearTerminal();
        showWelcomeMessage();
        // cout << "Enter your choice: ";
        // cin >> choice;
        // cin.ignore();
        // clearTerminal();
        if (!isLoggedIn())
        {
            showMainMenu();
            cout << "Enter your choice: ";
            cin >> choice;
            clearTerminal();
            switch (choice)
            {
            case 1:
            {
                string username, password;
                cout << "Enter your username: ";
                cin >> username;
                cout << "Enter your password: ";
                inputPassword(password);
                try
                {
                    login(username, password);
                }
                catch (UserException &e)
                {
                    cout << e.what() << endl;
                    cout << "Press Enter to continue...";
                    cin.ignore();
                    cin.ignore();
                }
                break;
            }
            case 2:
            {
                showAboutMessage();
                cin.ignore();
                cin.ignore();
                break;
            }
            case 3:
            {
                char ch;
                cout << "Are you sure you want to exit? (Y/N): ";
                cin >> ch;
                if (ch == 'Y' || ch == 'y')
                {
                    exit(0);
                }
                break;
            }
            default:
            {
                cout << "Invalid choice! Please try again." << endl;
                cout << "Press Enter to continue...";
                cin.ignore();
                cin.ignore();
                break;
            }
            }
        }
        else if (getCurrentUser()->getUsername() == "admin")
        {
            showAdminMenu();
            cout << "Enter your choice: ";
            cin >> choice;
            clearTerminal();
            switch (choice)
            {
            case 1:
            {
                string username, password;
                cout << "Enter the username: ";
                cin >> username;
                cout << "Enter the password: ";
                inputPassword(password);
                try
                {
                    User::addUserToList(username, password);
                }
                catch (UserException &e)
                {
                    cout << e.what() << endl;
                }
                cout << "Press Enter to continue...";
                cin.ignore();
                cin.ignore();
                break;
            }
            case 2:
            {
                string username;
                cout << "Enter the username: ";
                cin >> username;
                try
                {
                    User::removeUserFromList(username);
                }
                catch (UserException &e)
                {
                    cout << e.what() << endl;
                }
                cout << "Press Enter to continue...";
                cin.ignore();
                cin.ignore();
                break;
            }
            case 3:
            {
                try
                {
                    cout << "The list of users is as follows:" << endl
                         << endl;
                    User::displayUsersInList();
                }
                catch (UserException &e)
                {
                    cout << e.what() << endl;
                }
                cout << endl;
                cout << "Press Enter to continue...";
                cin.ignore();
                cin.ignore();
                break;
            }
            case 4:
            {
                showAdminTeacherMenu();
                cout << "Enter your choice: ";
                cin >> choice;
                clearTerminal();
                switch (choice)
                {
                case 1:
                {
                    string name, department, email, phone, address, designation, joiningDate, qualification;
                    int officeRoom;
                    cin.ignore();
                    cout << "Enter the name: \n";
                    getline(cin, name);
                    cout << "Enter the department: \n";
                    getline(cin, department);
                    cout << "Enter the email: \n";
                    getline(cin, email);
                    cout << "Enter the phone: \n";
                    getline(cin, phone);
                    cout << "Enter the address: \n";
                    getline(cin, address);
                    cout << "Enter the office room: \n";
                    cin >> officeRoom;
                    cin.ignore();
                    cout << "Enter the designation: \n";
                    getline(cin, designation);
                    cout << "Enter the joining date: \n";
                    getline(cin, joiningDate);
                    cout << "Enter the qualification: \n";
                    getline(cin, qualification);
                    try
                    {
                        Teacher teacher = Teacher::createNewTeacher(name, department, email, phone, address, officeRoom, designation, joiningDate, qualification);
                    }
                    catch (TeacherException &e)
                    {
                        cout << e.what() << endl;
                    }
                    cout << "Press Enter to continue...";
                    cin.ignore();
                    cin.ignore();
                    break;
                }
                case 2:
                {
                    string id;
                    cout << "Enter the ID: ";
                    getline(cin, id);
                    char ch;
                    cout << "Are you sure you want to delete the teacher with ID " << id << "? (Y/N): ";
                    cin >> ch;
                    if (ch == 'Y' || ch == 'y')
                    {
                        try
                        {
                            Teacher teacher = Teacher::getTeacherById(id);
                            teacher.deletePermenantly();
                        }
                        catch (TeacherException &e)
                        {
                            cout << e.what() << endl;
                        }
                    }
                    cout << "Press Enter to continue...";
                    cin.ignore();
                    cin.ignore();
                    break;
                }
                case 3:
                {
                    string id;
                    cout << "Enter the ID: ";
                    getline(cin, id);
                    try
                    {
                        Teacher teacher = Teacher::getTeacherById(id);
                        string name, department, email, phone, address, designation, joiningDate, qualification;
                        int officeRoom = 0;
                        Teacher newTeacher;
                        cin.ignore();
                        cout << "Enter the new name (Press Enter to skip): \n";
                        getline(cin, name);
                        if (!name.empty())
                        {
                            newTeacher.setName(name);
                        }
                        else
                        {
                            newTeacher.setName(teacher.getName());
                        }
                        cout << "Enter the new department (Press Enter to skip): \n";
                        getline(cin, department);
                        if (!department.empty())
                        {
                            newTeacher.setDepartment(department);
                        }
                        else
                        {
                            newTeacher.setDepartment(teacher.getDepartment());
                        }
                        cout << "Enter the new email (Press Enter to skip): \n";
                        getline(cin, email);
                        if (!email.empty())
                        {
                            newTeacher.setEmail(email);
                        }
                        else
                        {
                            newTeacher.setEmail(teacher.getEmail());
                        }
                        cout << "Enter the new phone (Press Enter to skip): \n";
                        getline(cin, phone);
                        if (!phone.empty())
                        {
                            newTeacher.setPhone(phone);
                        }
                        else
                        {
                            newTeacher.setPhone(teacher.getPhone());
                        }
                        cout << "Enter the new address (Press Enter to skip): \n";
                        getline(cin, address);
                        if (!address.empty())
                        {
                            newTeacher.setAddress(address);
                        }
                        else
                        {
                            newTeacher.setAddress(teacher.getAddress());
                        }
                        cout << "Enter the new office room (Press 0 to skip): \n";
                        cin >> officeRoom;
                        cin.ignore();
                        if (officeRoom == 0)
                        {
                            newTeacher.setOfficeRoom(teacher.getOfficeRoom());
                        }
                        else if (officeRoom >= 101 && officeRoom <= 505)
                        {
                            newTeacher.setOfficeRoom(officeRoom);
                        }
                        else
                        {
                            cout << "Invalid office room! Please try again." << endl;
                        }
                        cout << "Enter the new designation (Press Enter to skip): \n";
                        getline(cin, designation);
                        if (!designation.empty())
                        {
                            newTeacher.setDesignation(designation);
                        }
                        else
                        {
                            newTeacher.setDesignation(teacher.getDesignation());
                        }
                        cout << "Enter the new joining date (Press Enter to skip): \n";
                        getline(cin, joiningDate);
                        if (!joiningDate.empty())
                        {
                            newTeacher.setJoiningDate(joiningDate);
                        }
                        else
                        {
                            newTeacher.setJoiningDate(teacher.getJoiningDate());
                        }
                        cout << "Enter the new qualification (Press Enter to skip): \n";
                        getline(cin, qualification);
                        if (!qualification.empty())
                        {
                            newTeacher.setQualification(qualification);
                        }
                        else
                        {
                            newTeacher.setQualification(teacher.getQualification());
                        }
                        teacher.edit(newTeacher);
                    }
                    catch (TeacherException &e)
                    {
                        cout << e.what() << endl;
                    }
                    cout << "Press Enter to continue...";
                    cin.ignore();
                    cin.ignore();
                    break;
                }
                case 4:
                {
                    try
                    {
                        cout << "The list of teachers is as follows:" << endl
                             << endl;
                        Teacher::getTeachersList();
                    }
                    catch (TeacherException &e)
                    {
                        cout << e.what() << endl;
                    }
                    cout << "Press Enter to continue...";
                    cin.ignore();
                    cin.ignore();
                    break;
                }
                case 5:
                {
                    string id;
                    cout << "Enter the ID: ";
                    cin >> id;
                    try
                    {
                        Teacher teacher = Teacher::getTeacherById(id);
                        cout << "The teacher with ID " << id << " is as follows:" << endl
                             << endl;
                        cout << teacher;
                    }
                    catch (TeacherException &e)
                    {
                        cout << e.what() << endl;
                    }
                    cout << "Press Enter to continue...";
                    cin.ignore();
                    cin.ignore();
                }
                case 6:
                {
                    string name;
                    cout << "Enter the name: \n";
                    cin.ignore();
                    getline(cin, name);
                    try
                    {
                        set<Teacher> teachers = Teacher::getTeacherByName(name);
                        cout << "The teachers with name " << name << " are as follows:" << endl
                             << endl;
                        for (Teacher teacher : teachers)
                        {
                            cout << teacher;
                        }
                    }
                    catch (TeacherException &e)
                    {
                        cout << e.what() << endl;
                    }
                    cout << "Press Enter to continue...";
                    cin.ignore();
                    cin.ignore();
                }
                case 7:
                {
                    string department;
                    cout << "Enter the department: \n";
                    cin.ignore();
                    getline(cin, department);
                    try
                    {
                        set<Teacher> teachers = Teacher::getTeacherByDepartment(department);
                        cout << "The teachers in department " << department << " are as follows:" << endl
                             << endl;
                        for (Teacher teacher : teachers)
                        {
                            cout << teacher;
                        }
                    }
                    catch (TeacherException &e)
                    {
                        cout << e.what() << endl;
                    }
                    cout << "Press Enter to continue...";
                    cin.ignore();
                    cin.ignore();
                }

                case 8:
                {
                    string designation;
                    cout << "Enter the designation: \n";
                    cin.ignore();
                    getline(cin, designation);
                    try
                    {
                        set<Teacher> teachers = Teacher::getTeacherByDesignation(designation);
                        cout << "The teachers with designation " << designation << " are as follows:" << endl
                             << endl;
                        for (Teacher teacher : teachers)
                        {
                            cout << teacher;
                        }
                    }
                    catch (TeacherException &e)
                    {
                        cout << e.what() << endl;
                    }
                    cout << "Press Enter to continue...";
                    cin.ignore();
                    cin.ignore();
                }

                case 9:
                {
                    char ch;
                    cout << "Are you sure you want to logout? (Y/N): ";
                    cin >> ch;
                    if (ch == 'Y' || ch == 'y')
                    {
                        logout();
                    }
                    break;
                }

                case 10:
                {
                    break;
                }
                case 0:
                {
                    char ch;
                    cout << "Are you sure you want to exit? (Y/N): ";
                    cin >> ch;
                    if (ch == 'Y' || ch == 'y')
                    {
                        exit(0);
                    }
                    break;
                }

                default:
                {
                    cout << "Invalid choice! Please try again." << endl;
                    cout << "Press Enter to continue...";
                    cin.ignore();
                    cin.ignore();
                    break;
                }
                }
                break;
            }
            case 5:
            {
                showAdminCourseMenu();
                cout << "Enter your choice: ";
                cin >> choice;
                clearTerminal();
                switch (choice)
                {
                case 1:
                {
                    string name, code, department, teacherID;
                    int semester, year;
                    double creditHours;
                    cout << "Enter the name: \n";
                    cin.ignore();
                    getline(cin, name);
                    cout << "Enter the code: \n";
                    cin >> code;
                    cout << "Enter the credit hours: \n";
                    cin >> creditHours;
                    cout << "Enter the department: \n";
                    cin >> department;
                    cout << "Enter the semester: \n";
                    cin >> semester;
                    cout << "Enter the year: \n";
                    cin >> year;
                    cout << "Enter the teacher ID (Press Enter to skip): ";
                    cin >> teacherID;
                    if (teacherID.empty())
                    {
                        teacherID = "";
                    }
                    if (name.empty() || code.empty() || department.empty())
                    {
                        cout << "Error: Please fill all the fields!" << endl;
                        cout << "Press Enter to continue...";
                        cin.ignore();
                        cin.ignore();
                        break;
                    }
                    if (semester > 2 || semester < 1)
                    {
                        cout << "Error: Invalid semester!" << endl;
                        cout << "Press Enter to continue...";
                        cin.ignore();
                        cin.ignore();
                        break;
                    }
                    if (year < 1 || year > 4)
                    {
                        cout << "Error: Invalid year!" << endl;
                        cout << "Press Enter to continue...";
                        cin.ignore();
                        cin.ignore();
                        break;
                    }
                    try
                    {

                        Course course(name, code, creditHours, department, semester, year, teacherID);
                        Course::addCourseToList(course);
                    }
                    catch (CourseException &e)
                    {
                        cout << e.what() << endl;
                    }
                    cout << "Press Enter to continue...";
                    cin.ignore();
                    cin.ignore();
                    break;
                }
                case 2:
                {
                    string code;
                    cout << "Enter the code: ";
                    cin >> code;
                    char ch;
                    cout << "Are you sure you want to delete the course with code " << code << "? (Y/N): ";
                    cin >> ch;
                    if (ch == 'Y' || ch == 'y')
                    {
                        try
                        {
                            Course course = Course::getCourseByCode(code);
                            Teacher teacher = Teacher::getTeacherById(course.getTeacherID());
                            teacher.removeCourse(code);
                            Course::removeCourseFromList(course);
                        }
                        catch (CourseException &e)
                        {
                            cout << e.what() << endl;
                        }
                    }
                    cout << "Press Enter to continue...";
                    cin.ignore();
                    cin.ignore();
                    break;
                }
                case 3:
                {
                    string code;
                    cout << "Enter the code: ";
                    cin >> code;
                    try
                    {
                        Course course = Course::getCourseByCode(code);
                        string name, department, teacherID;
                        int semester, year;
                        double creditHours;
                        cout << "Enter the new name (Press Enter to skip): \n";
                        cin.ignore();
                        getline(cin, name);
                        cout << "Enter the new department (Press Enter to skip): \n";
                        cin >> department;
                        cout << "Enter the new credit hours (Press 0 to skip): \n";
                        cin >> creditHours;
                        cout << "Enter the new semester (Press 0 to skip): \n";
                        cin >> semester;
                        cout << "Enter the new year (Press 0 to skip): \n";
                        cin >> year;
                        cout << "Enter the new teacher ID (Press Enter to skip): \n";
                        cin >> teacherID;
                        Course newCourse;
                        if (!name.empty())
                        {
                            newCourse.setName(name);
                        }
                        else
                        {
                            newCourse.setName(course.getName());
                        }
                        if (!department.empty())
                        {
                            newCourse.setDepartment(department);
                        }
                        else
                        {
                            newCourse.setDepartment(course.getDepartment());
                        }
                        if (creditHours != 0)
                        {
                            newCourse.setCreditHours(creditHours);
                        }
                        else
                        {
                            newCourse.setCreditHours(course.getCreditHours());
                        }
                        if (semester != 0)
                        {
                            newCourse.setSemester(semester);
                        }
                        else
                        {
                            newCourse.setSemester(course.getSemester());
                        }
                        if (year != 0)
                        {
                            newCourse.setYear(year);
                        }
                        else
                        {
                            newCourse.setYear(course.getYear());
                        }
                        if (!teacherID.empty())
                        {
                            newCourse.setTeacherID(teacherID);
                        }
                        else
                        {
                            newCourse.setTeacherID(course.getTeacherID());
                        }
                        Course::editCourseInList(newCourse);
                    }
                    catch (CourseException &e)
                    {
                        cout << e.what() << endl;
                    }
                    cout << "Press Enter to continue...";
                    cin.ignore();
                    cin.ignore();
                }
                case 4:
                {
                    try
                    {
                        cout << "The list of courses is as follows:" << endl
                             << endl;
                        Course::displayCoursesInList();
                    }
                    catch (CourseException &e)
                    {
                        cout << e.what() << endl;
                    }
                    cout << "Press Enter to continue...";
                    cin.ignore();
                    cin.ignore();
                    break;
                }
                case 5:
                {
                    string code;
                    cout << "Enter the code: ";
                    cin >> code;
                    try
                    {
                        Course course = Course::getCourseByCode(code);
                        cout << "The course with code " << code << " is as follows:" << endl
                             << endl;
                        cout << course;
                    }
                    catch (CourseException &e)
                    {
                        cout << e.what() << endl;
                    }
                    cout << "Press Enter to continue...";
                    cin.ignore();
                    cin.ignore();
                    break;
                }
                case 6:
                {
                    string name;
                    cout << "Enter the name: \n";
                    cin.ignore();
                    getline(cin, name);
                    try
                    {
                        set<Course> courses = Course::getCoursesByName(name);
                        cout << "The courses with name " << name << " are as follows:" << endl
                             << endl;
                        for (Course course : courses)
                        {
                            cout << course;
                        }
                    }
                    catch (CourseException &e)
                    {
                        cout << e.what() << endl;
                    }
                    cout << "Press Enter to continue...";
                    cin.ignore();
                    cin.ignore();
                    break;
                }
                case 7:
                {
                    string department;
                    cout << "Enter the department: ";
                    cin >> department;
                    try
                    {
                        set<Course> courses = Course::getCoursesByDepartment(department);
                        cout << "The courses in department " << department << " are as follows:" << endl
                             << endl;
                        for (Course course : courses)
                        {
                            cout << course;
                        }
                    }
                    catch (CourseException &e)
                    {
                        cout << e.what() << endl;
                    }
                    cout << "Press Enter to continue...";
                    cin.ignore();
                    cin.ignore();
                    break;
                }
                case 8:
                {
                    int semester;
                    cout << "Enter the semester: ";
                    cin >> semester;
                    try
                    {
                        set<Course> courses = Course::getCoursesBySemester(semester);
                        cout << "The courses in semester " << semester << " are as follows:" << endl
                             << endl;
                        for (Course course : courses)
                        {
                            cout << course;
                        }
                    }
                    catch (CourseException &e)
                    {
                        cout << e.what() << endl;
                    }
                    cout << "Press Enter to continue...";
                    cin.ignore();
                    cin.ignore();
                    break;
                }
                case 9:
                {
                    int year;
                    cout << "Enter the year: ";
                    cin >> year;
                    try
                    {
                        set<Course> courses = Course::getCoursesByYear(year);
                        cout << "The courses in year " << year << " are as follows:" << endl
                             << endl;
                        for (Course course : courses)
                        {
                            cout << course;
                        }
                    }
                    catch (CourseException &e)
                    {
                        cout << e.what() << endl;
                    }
                    cout << "Press Enter to continue...";
                    cin.ignore();
                    cin.ignore();
                    break;
                }
                case 10:
                {
                    string teacherID;
                    cout << "Enter the teacher ID: ";
                    cin >> teacherID;
                    try
                    {
                        set<Course> courses = Course::getCoursesByTeacherID(teacherID);
                        cout << "The courses assigned to teacher with ID " << teacherID << " are as follows:" << endl
                             << endl;
                        for (Course course : courses)
                        {
                            cout << course;
                        }
                    }
                    catch (CourseException &e)
                    {
                        cout << e.what() << endl;
                    }
                    cout << "Press Enter to continue...";
                    cin.ignore();
                    cin.ignore();
                    break;
                }
                case 11:
                {
                    string teacherID, courseID;
                    cout << "Enter the teacher ID: ";
                    cin >> teacherID;
                    cout << "Enter the course ID: ";
                    cin >> courseID;
                    try
                    {
                        Course course = Course::getCourseByCode(courseID);
                        Teacher teacher = Teacher::getTeacherById(teacherID);
                        teacher.addCourse(courseID);
                        cout << "The course " << courseID << " has been assigned to teacher with ID " << teacherID << "." << endl;
                    }
                    catch (CourseException &e)
                    {
                        cout << e.what() << endl;
                    }
                    cout << "Press Enter to continue...";
                    cin.ignore();
                    cin.ignore();
                    break;
                }
                case 12:
                {
                    string teacherID, courseID;
                    cout << "Enter the teacher ID: ";
                    cin >> teacherID;
                    cout << "Enter the course ID: ";
                    cin >> courseID;
                    try
                    {
                        Course course = Course::getCourseByCode(courseID);
                        Teacher teacher = Teacher::getTeacherById(teacherID);
                        teacher.removeCourse(courseID);
                        cout << "The course " << courseID << " has been unassigned from teacher with ID " << teacherID << "." << endl;
                    }
                    catch (CourseException &e)
                    {
                        cout << e.what() << endl;
                    }
                    cout << "Press Enter to continue...";
                    cin.ignore();
                    cin.ignore();
                    break;
                }
                case 13:
                {
                    cout << "Are you sure you want to logout? (Y/N): ";
                    char ch;
                    cin >> ch;
                    if (ch == 'Y' || ch == 'y')
                    {
                        logout();
                    }
                    break;
                }
                case 14:
                {
                    break;
                }
                case 0:
                {
                    char ch;
                    cout << "Are you sure you want to exit? (Y/N): ";
                    cin >> ch;
                    if (ch == 'Y' || ch == 'y')
                    {
                        exit(0);
                    }
                    break;
                }
                default:
                {
                    cout << "Invalid choice! Please try again." << endl;
                    cout << "Press Enter to continue...";
                    cin.ignore();
                    cin.ignore();
                    break;
                }
                }
            }
            // case 6:
            // {
            //     string password;
            //     cout << "Enter your new password: ";
            //     inputPassword(password);
            //     string password2;
            //     cout << "Re-enter your new password: ";
            //     inputPassword(password2);
            //     if (password != password2)
            //     {
            //         cout << "Error: Passwords do not match!" << endl;
            //         cout << "Press Enter to continue...";
            //         cin.ignore();
            //         cin.ignore();
            //         break;
            //     }
            //     string oldPassword;
            //     cout << "Enter your old password: ";
            //     inputPassword(oldPassword);
            //     if (hashcode(oldPassword) != getCurrentUser()->getPasswordHash())
            //     {
            //         cout << "Error: Incorrect password!" << endl;
            //         cout << "Press Enter to continue...";
            //         cin.ignore();
            //         cin.ignore();
            //         break;
            //     }
            //     try
            //     {
            //         getCurrentUser()->setPassword(password);
            //         setAdminPasswordHash(hashcode(password));
            //         cout << "Password changed successfully!" << endl;
            //     }
            //     catch (UserException &e)
            //     {
            //         cout << e.what() << endl;
            //     }

            //     cout << "Press Enter to continue...";
            //     cin.ignore();
            //     cin.ignore();
            //     break;
            // }
            case 6:
            {
                cout << "Are you sure you want to logout? (Y/N): ";
                char ch;
                cin >> ch;
                if (ch == 'Y' || ch == 'y')
                {
                    logout();
                }
                break;
            }
            case 0:
            {
                char ch;
                cout << "Are you sure you want to exit? (Y/N): ";
                cin >> ch;
                if (ch == 'Y' || ch == 'y')
                {
                    exit(0);
                }
                break;
            }
            default:
            {
                cout << "Invalid choice! Please try again." << endl;
                cout << "Press Enter to continue...";
                cin.ignore();
                cin.ignore();
                break;
            }
            }
        }
        else
        {
            showUserMenu();
            cout << "Enter your choice: ";
            cin >> choice;
            clearTerminal();
            switch (choice)
            {
            case 1:
            {
                showUserTeacherMenu();
                cout << "Enter your choice: ";
                cin >> choice;
                clearTerminal();
                switch (choice)
                {
                case 1:
                {
                    string id;
                    cout << "Enter the ID: ";
                    cin >> id;
                    try
                    {
                        Teacher teacher = Teacher::getTeacherById(id);
                        cout << "The teacher with ID " << id << " is as follows:" << endl
                             << endl;
                        cout << teacher;
                    }
                    catch (TeacherException &e)
                    {
                        cout << e.what() << endl;
                    }
                    cout << "Press Enter to continue...";
                    cin.ignore();
                    cin.ignore();
                    break;
                }
                case 2:
                {
                    string name;
                    cout << "Enter the name: \n";
                    cin.ignore();
                    getline(cin, name);
                    try
                    {
                        set<Teacher> teachers = Teacher::getTeacherByName(name);
                        cout << "The teachers with name " << name << " are as follows:" << endl
                             << endl;
                        for (Teacher teacher : teachers)
                        {
                            cout << teacher;
                        }
                    }
                    catch (TeacherException &e)
                    {
                        cout << e.what() << endl;
                    }
                    cout << "Press Enter to continue...";
                    cin.ignore();
                    cin.ignore();
                    break;
                }
                case 3:
                {
                    string department;
                    cout << "Enter the department: ";
                    cin >> department;
                    try
                    {
                        set<Teacher> teachers = Teacher::getTeacherByDepartment(department);
                        cout << "The teachers in department " << department << " are as follows:" << endl
                             << endl;
                        for (Teacher teacher : teachers)
                        {
                            cout << teacher;
                        }
                    }
                    catch (TeacherException &e)
                    {
                        cout << e.what() << endl;
                    }
                    cout << "Press Enter to continue...";
                    cin.ignore();
                    cin.ignore();
                    break;
                }
                case 4:
                {
                    string designation;
                    cout << "Enter the designation: \n";
                    cin.ignore();
                    getline(cin, designation);
                    try
                    {
                        set<Teacher> teachers = Teacher::getTeacherByDesignation(designation);
                        cout << "The teachers with designation " << designation << " are as follows:" << endl
                             << endl;
                        for (Teacher teacher : teachers)
                        {
                            cout << teacher;
                        }
                    }
                    catch (TeacherException &e)
                    {
                        cout << e.what() << endl;
                    }
                    cout << "Press Enter to continue...";
                    cin.ignore();
                    cin.ignore();
                    break;
                }
                case 5:
                {
                    break;
                }
                case 6:
                {
                    cout << "Are you sure you want to logout? (Y/N): ";
                    char ch;
                    cin >> ch;
                    if (ch == 'Y' || ch == 'y')
                    {
                        logout();
                    }
                    break;
                }
                case 0:
                {
                    char ch;
                    cout << "Are you sure you want to exit? (Y/N): ";
                    cin >> ch;
                    if (ch == 'Y' || ch == 'y')
                    {
                        exit(0);
                    }
                    break;
                }
                default:
                {
                    cout << "Invalid choice! Please try again." << endl;
                    cout << "Press Enter to continue...";
                    cin.ignore();
                    cin.ignore();
                    break;
                }
                }
                break;
            }
            case 2:
            {
                showUserCourseMenu();
                cout << "Enter your choice: ";
                cin >> choice;
                clearTerminal();
                switch (choice)
                {
                case 1:
                {
                    string code;
                    cout << "Enter the code: ";
                    cin >> code;
                    try
                    {
                        Course course = Course::getCourseByCode(code);
                        cout << "The course with code " << code << " is as follows:" << endl
                             << endl;
                        cout << course;
                    }
                    catch (CourseException &e)
                    {
                        cout << e.what() << endl;
                    }
                    cout << "Press Enter to continue...";
                    cin.ignore();
                    cin.ignore();
                    break;
                }
                case 2:
                {
                    string name;
                    cout << "Enter the name: \n";
                    cin.ignore();
                    getline(cin, name);
                    try
                    {
                        set<Course> courses = Course::getCoursesByName(name);
                        cout << "The courses with name " << name << " are as follows:" << endl
                             << endl;
                        for (Course course : courses)
                        {
                            cout << course;
                        }
                    }
                    catch (CourseException &e)
                    {
                        cout << e.what() << endl;
                    }
                    cout << "Press Enter to continue...";
                    cin.ignore();
                    cin.ignore();
                    break;
                }
                case 3:
                {
                    string department;
                    cout << "Enter the department: ";
                    cin >> department;
                    try
                    {
                        set<Course> courses = Course::getCoursesByDepartment(department);
                        cout << "The courses in department " << department << " are as follows:" << endl
                             << endl;
                        for (Course course : courses)
                        {
                            cout << course;
                        }
                    }
                    catch (CourseException &e)
                    {
                        cout << e.what() << endl;
                    }
                    cout << "Press Enter to continue...";
                    cin.ignore();
                    cin.ignore();
                    break;
                }
                case 4:
                {
                    int semester;
                    cout << "Enter the semester: ";
                    cin >> semester;
                    try
                    {
                        set<Course> courses = Course::getCoursesBySemester(semester);
                        cout << "The courses in semester " << semester << " are as follows:" << endl
                             << endl;
                        for (Course course : courses)
                        {
                            cout << course;
                        }
                    }
                    catch (CourseException &e)
                    {
                        cout << e.what()
                             << endl;
                    }
                    cout << "Press Enter to continue...";
                    cin.ignore();
                    cin.ignore();
                    break;
                }
                case 5:
                {
                    int year;
                    cout << "Enter the year: ";
                    cin >> year;
                    try
                    {
                        set<Course> courses = Course::getCoursesByYear(year);
                        cout << "The courses in year " << year << " are as follows:" << endl
                             << endl;
                        for (Course course : courses)
                        {
                            cout << course;
                        }
                    }
                    catch (CourseException &e)
                    {
                        cout << e.what() << endl;
                    }
                    cout << "Press Enter to continue...";
                    cin.ignore();
                    cin.ignore();
                    break;
                }
                case 6:
                {
                    string teacherID;
                    cout << "Enter the teacher ID: ";
                    cin >> teacherID;
                    try
                    {
                        set<Course> courses = Course::getCoursesByTeacherID(teacherID);
                        cout << "The courses assigned to teacher with ID " << teacherID << " are as follows:" << endl
                             << endl;
                        for (Course course : courses)
                        {
                            cout << course;
                        }
                    }
                    catch (CourseException &e)
                    {
                        cout << e.what() << endl;
                    }
                    cout << "Press Enter to continue...";
                    cin.ignore();
                    cin.ignore();
                    break;
                }
                case 7:
                {
                    break;
                }
                case 8:
                {
                    cout << "Are you sure you want to logout? (Y/N): ";
                    char ch;
                    cin >> ch;
                    if (ch == 'Y' || ch == 'y')
                    {
                        logout();
                    }
                    break;
                }
                case 0:
                {
                    char ch;
                    cout << "Are you sure you want to exit? (Y/N): ";
                    cin >> ch;
                    if (ch == 'Y' || ch == 'y')
                    {
                        exit(0);
                    }
                    break;
                }
                default:
                {
                    cout << "Invalid choice! Please try again." << endl;
                    cout << "Press Enter to continue...";
                    cin.ignore();
                    cin.ignore();
                    break;
                }
                }
                break;
            }
            case 3:
            {
                string password;
                cout << "Enter your new password: ";
                inputPassword(password);
                string password2;
                cout << "Re-enter your new password: ";
                inputPassword(password2);
                if (password != password2)
                {
                    cout << "Error: Passwords do not match!" << endl;
                    cout << "Press Enter to continue...";
                    cin.ignore();
                    cin.ignore();
                    break;
                }
                string oldPassword;
                cout << "Enter your old password: ";
                inputPassword(oldPassword);
                if (hashcode(oldPassword) != getCurrentUser()->getPasswordHash())
                {
                    cout << "Error: Incorrect password!" << endl;
                    cout << "Press Enter to continue...";
                    cin.ignore();
                    cin.ignore();
                    break;
                }
                try
                {
                    getCurrentUser()->setPassword(password);
                }
                catch (UserException &e)
                {
                    cout << e.what() << endl;
                }
                cout << "Press Enter to continue...";
                cin.ignore();
                cin.ignore();
                break;
            }
            case 4:
            {
                cout << "Are you sure you want to logout? (Y/N): ";
                char ch;
                cin >> ch;
                if (ch == 'Y' || ch == 'y')
                {
                    logout();
                }
                break;
            }
            case 0:
            {
                char ch;
                cout << "Are you sure you want to exit? (Y/N): ";
                cin >> ch;
                if (ch == 'Y' || ch == 'y')
                {
                    exit(0);
                }
                break;
            }
            default:
            {
                cout << "Invalid choice! Please try again." << endl;
                cout << "Press Enter to continue...";
                cin.ignore();
                cin.ignore();
                break;
            }
            }
        }
    } while (true);
    return 0;
}

#include "Teacher.hpp"
#include "Course.hpp"
#include "Utility.hpp"

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

void showMainMenu()
{
    cout << "         Please select an option from the following menu:" << endl;
    cout << "                         1. Admin Login" << endl;
    cout << "                         2. Student Login" << endl;
    cout << "                         3. About" << endl;
    cout << "                         4. Exit" << endl;
    cout << endl;
}

int main(int, char **)
{
    Teacher teacher = Teacher::createNewTeacher("Ali", "CSE", "ali@gmail.com", "123456789", "Lahore", 101, "Lecturer", "01-01-2021", "BS");
    cout<<(teacher.getName())<<endl;
    // int choice;
    // while (true)
    // {
    //     showWelcomeMessage();
    //     int choice;
    //     cout << "Enter your choice: ";
    //     cin >> choice;
    //     switch (choice)
    //     {
    //     case 1:
    //         // Admin Login
    //         break;
    //     case 2:
    //         // Student Login
    //         break;
    //     case 3:
    //         // About
    //         break;
    //     case 4:
    //         cout << "Are you sure you want to exit? (Y/N): ";
    //         char ch;
    //         cin >> ch;
    //         if (ch == 'Y' || ch == 'y')
    //         {
    //             cout << "Exiting the program..." << endl;
    //             exit(0);
    //         }
    //         break;
    //     default:
    //         cout << "Invalid choice! Please try again." << endl;
    //         cin.ignore();
    //         break;
    //     }
    // }
}

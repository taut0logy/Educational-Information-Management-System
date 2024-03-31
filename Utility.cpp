#include "Utility.hpp"

TeacherException::TeacherException(const string &message)
{
    this->message = message;
}

TeacherException::TeacherException()
{
    this->message = "Teacher Exception!";
}

const char *TeacherException::what() const noexcept
{
    return message.c_str();
}

CourseException::CourseException(const string &message)
{
    this->message = message;
}

CourseException::CourseException()
{
    this->message = "Course Exception!";
}

const char *CourseException::what() const noexcept
{
    return message.c_str();
}

UserException::UserException(const string &message)
{
    this->message = message;
}

UserException::UserException()
{
    this->message = "User Exception!";
}

const char *UserException::what() const noexcept
{
    return message.c_str();
}

string toLowerCase(const string &str)
{
    string lowerCaseStr = "";
    for (char c : str)
    {
        lowerCaseStr += tolower(c);
    }
    return lowerCaseStr;
}

string toUpperCase(const string &str)
{
    string upperCaseStr = "";
    for (char c : str)
    {
        upperCaseStr += toupper(c);
    }
    return upperCaseStr;
}

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
    password = "";
    char ch;
    while ((ch = _getch()) != '\r')
    { // On Windows, use _getch() from conio.h
        if (ch == '\b')
        { // Handle backspace
            if (!password.empty())
            {
                password.pop_back();
                std::cout << "\b \b"; // Move cursor back, overwrite character, move back again
            }
        }
        else
        {
            password += ch;
            std::cout << '*';
        }
    }
    std::cout << std::endl;
}

string getRandomID()
{
    string randomString;                                                // String to store random string
    auto seed = chrono::system_clock::now().time_since_epoch().count(); // Use current time as seed
    mt19937 gen(seed);                                                  // Seed the generator
    uniform_int_distribution<> dis(0, 9);                               // Define the range of digits (0-9)

    for (size_t i = 0; i < 6; ++i)
    {
        randomString += to_string(dis(gen)); // Generate random digit and append to string
    }

    return randomString;
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

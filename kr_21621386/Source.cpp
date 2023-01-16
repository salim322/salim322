//21621386%12+1=3
//3zad


#include <set>
#include <vector>
#include <iostream>
#include <string>
#include <exception>
using namespace std;




class Scholarship
{
public:
    virtual set<Student> extractStudentsForScholarship(const set<Student>& report, int lowerGrade, int upperGrade) const = 0;
};

class Student
{
private:
    int grade;
    string facultyNumber;

public:
    // Default constructor
    Student() : grade(0), facultyNumber("") {}

    // SE-exclusive constructor
    Student(int grade, string facultyNumber) : grade(grade), facultyNumber(facultyNumber) {}

    // Function to read the members of the class
    void readMembers()
    {
        cout << "Grade: " << grade << endl;
        cout << "Faculty Number: " << facultyNumber << endl;
    }

    // Operator for comparison by grade
    bool operator<(const Student& other) const
    {
        return grade < other.grade;
    }

    // Operator for equivalence by faculty number
    bool operator==(const Student& other) const
    {
        return facultyNumber == other.facultyNumber;
    }

    // Redefine stream operator for output
    friend ostream& operator<<(ostream& out, const Student& student)
    {
        out << "Grade: " << student.grade << endl;
        out << "Faculty Number: " << student.facultyNumber << endl;
        return out;
    }

    // Redefine stream operator for input
    friend istream& operator>>(istream& in, Student& student)
    {
        in >> student.grade;
        in >> student.facultyNumber;
        return in;
    }
};

class ScholarshipProtocol : public Scholarship {
private:
    string specialtyName;
    vector<Student> students;

public:
    // Explicit constructor
    explicit ScholarshipProtocol(string dataFileName) {
        // code to initialize data from file, including specialtyName and students container
        // throw exception if needed
    }

    // Destructor
    ~ScholarshipProtocol() {
        // code to release resources if needed
    }

    // Function to read the name of the major
    string getSpecialtyName() const { return specialtyName; }

    // Virtual function
    virtual set<Student> EXTRACTSTUDENTSFORSCHOLARSHIP(const set<Student>& REPORT, int LOWERGRADE, int UPPERGRADE) const {
        // code to determine students who have grades in the specified interval
        // return the set of students
    }

    // Function to create and return an array of students with their semester results
    vector<Student> getSemesterResults() const { return students; }

    // Comparison operators
    bool operator<(const ScholarshipProtocol& other) const { return specialtyName < other.specialtyName; }
    bool operator==(const ScholarshipProtocol& other) const { return specialtyName == other.specialtyName && students == other.students; }

    // Stream operators
    friend ostream& operator<<(ostream& os, const ScholarshipProtocol& scholarship) {
        os << "Specialty Name: " << scholarship.specialtyName << ", Students: ";
        for (const Student& student : scholarship.students) {
            os << student << " ";
        }
        return os;
    }

    friend istream& operator>>(istream& is, ScholarshipProtocol& scholarship) {
        is >> scholarship.specialtyName;
        // code to read students from input stream
        return is;
    }
};

int main() {
    // Create object of ScholarshipProtocol class and initialize it from file1
    try {
        ScholarshipProtocol scholarship1("file1.txt");
    }
    catch (const exception& e) {
        cerr << e.what() << endl;
        return 1;
    }

    // Output the object information on the console
    cout << scholarship1 << endl;

    // Create object of ScholarshipProtocol class and initialize it from file2
    try {
        ScholarshipProtocol scholarship2("file2.txt");
    }
    catch (const exception& e) {
        cerr << e.what() << endl;
        return 1;
    }

    // Output the object information on the console
    cout << scholarship2 << endl;

    // Output an array of students from scholarship1 and output its contents
    vector<Student> students1 = scholarship1.getSemesterResults();
    cout << "Students in Scholarship 1:" << endl;
    for (const Student& student : students1) {
        cout << student << endl;
    }

    // Output an array of students from scholarship2 and output its contents
    vector<Student> students2 = scholarship2.getSemesterResults();
    cout << "Students in Scholarship 2:" << endl;
    for (const Student& student : students2) {
        cout << student << endl;
    }

    // Identify a student between the two sets and throw an exception if not found
    Student targetStudent;
    cin >> targetStudent;
    bool found = false;
    for (const Student& student : students1) {
        if (student == targetStudent) {
            found = true;
            break;
        }
    }
    if (!found) {
        for (const Student& student : students2) {
            if (student == targetStudent) {
                found = true;
                break;
            }
        }
    }
    if (!found) {
        throw runtime_error("Target student not found in both sets");
    }
    cout << "Target student found!" << endl;

    return 0;
}

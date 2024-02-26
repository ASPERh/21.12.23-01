#include <iostream>
#include <string>

using namespace std;

class Date {
private:
    int day, month, year;

public:
    Date(int d, int m, int y) : day(d), month(m), year(y) {}

    void display() const {
        cout << day << "." << month << "." << year;
    }
};

const int MAX_GRADES = 100;

class Student {
private:
    string lastName;
    string firstName;
    string patronymic;
    Date birthDate;
    Date enrollmentDate;
    string homeAddress;
    string phoneNumber;

    int practiceGrades[MAX_GRADES];
    int homeworkGrades[MAX_GRADES];
    int examGrades[MAX_GRADES];

    int practiceGradeCount;
    int homeworkGradeCount;
    int examGradeCount;

public:
    Student(const string& lName, const string& fName, const string& patr,
        const Date& bDate, const Date& eDate, const string& address,
        const string& phone)
        : lastName(lName), firstName(fName), patronymic(patr),
        birthDate(bDate), enrollmentDate(eDate),
        homeAddress(address), phoneNumber(phone),
        practiceGradeCount(0), homeworkGradeCount(0), examGradeCount(0) {}

    Student(const string& lName, const string& fName, const string& patr,
        int birthDay, int birthMonth, int birthYear,
        int enrollmentDay, int enrollmentMonth, int enrollmentYear,
        const string& address, const string& phone)
        : lastName(lName), firstName(fName), patronymic(patr),
        birthDate(birthDay, birthMonth, birthYear),
        enrollmentDate(enrollmentDay, enrollmentMonth, enrollmentYear),
        homeAddress(address), phoneNumber(phone),
        practiceGradeCount(0), homeworkGradeCount(0), examGradeCount(0) {}

    ~Student() {}

    void setLastName(const string& lName) { lastName = lName; }
    string getLastName() const { return lastName; }

    void addPracticeGrade(int grade) {
        if (practiceGradeCount < MAX_GRADES) {
            practiceGrades[practiceGradeCount++] = grade;
        }
        else {
            cout << "Max practice grades reached" << endl;
        }
    }

    void addHomeworkGrade(int grade) {
        if (homeworkGradeCount < MAX_GRADES) {
            homeworkGrades[homeworkGradeCount++] = grade;
        }
        else {
            cout << "Max homework grades reached" << endl;
        }
    }

    void addExamGrade(int grade) {
        if (examGradeCount < MAX_GRADES) {
            examGrades[examGradeCount++] = grade;
        }
        else {
            cout << "Max exam grades reached" << endl;
        }
    }

    void displayPracticeGrades() const {
        cout << "Practice Grades: ";
        for (int i = 0; i < practiceGradeCount; ++i) {
            cout << practiceGrades[i] << " ";
        }
        cout << endl;
    }

    int getPracticeGradeAtIndex(int index) const {
        if (index >= 0 && index < practiceGradeCount) {
            return practiceGrades[index];
        }
        else {
            return -1;
        }
    }
};

int main() {
    Date birth(1, 1, 2000);
    Date enrollment(1, 1, 2020);

    Student student("Иванов", "Иван", "Иванович", birth, enrollment, "ул. Пушкина 10", "123-456-7890");

    student.addPracticeGrade(5);
    student.addPracticeGrade(4);
    student.addHomeworkGrade(3);
    student.addHomeworkGrade(4);
    student.addExamGrade(4);

    student.displayPracticeGrades();

    return 0;
}
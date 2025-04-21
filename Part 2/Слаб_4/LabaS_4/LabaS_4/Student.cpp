//Student.cpp
#include "Student.h"

Student::Student(string F, int S, string FF, int SS) : Person(F, S)
{
    subject = FF;
    assessment = SS;
}
Student::Student()
{
    subject = "";
    assessment = 0;
}
Student::Student(const Student& p)
{
    subject = p.subject;
    assessment = p.assessment;
}

void Student::set_FF(string f){
    subject = f;
}
void Student::set_SS(int s){
    assessment = s;
}

void Student::check(){
    if (assessment < 4){
        cout << assessment << " has an unsatisfactory assessment (" << assessment << ") in " << subject << "." << endl;
    }
    else{
        cout << assessment << " has a satisfactory assessment (" << assessment << ") in " << subject << "." << endl;
    }
}
Student& Student::operator=(const Student& other)
{
    if (this == &other) return *this;
   
    name = other.name;
    age = other.age;
    subject = other.subject;
    assessment = other.assessment;
    return *this;
}

istream& operator>>(istream& in, Student& s)
{
    cout << "\nName:"; in >> s.name;
    cout << "Age:"; in >> s.age;
    cout << "Subject:"; in >> s.subject;
    cout << "Assessment:"; in >> s.assessment;
    return in;
}
ostream& operator<<(ostream& out, const Student& s)
{
    cout << "\nName:" << s.name;
    cout << "\nAge:" << s.age;
    cout << "\nSubject:" << s.subject;
    cout << "\nAssessment:" << s.assessment;
    return out;
}
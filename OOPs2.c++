#include <iostream>
using namespace std;

class Student {
    public:
    string branch;
    string name;
    int rollNo;

    Student() {
        branch = "mechanical";
        name = "Aditya Rai";
        rollNo = 22135011;
    }

    Student(string branch, string name, int rollNo) {
        this->branch = branch;
        this->name = name;
        this->rollNo = rollNo;
    }

    void print(){
        cout<<" The name of branch is: "<< this->branch << endl;
        cout<<" The name of student is: "<< this->name << endl;
        cout<<" The rollNo of student is: "<< this->rollNo << endl;
    }

};

int main() {

    Student Aditya;
    
    Student Abhinav("Electronics", "Abhinav", 22135008);

    Student Avipsa(Abhinav);

    Avipsa.name = "Avipsa";
    Avipsa.branch = "Mechanical";
    Avipsa.rollNo = 22135035;

    Aditya.print();
    Abhinav.print();
    Avipsa.print();

    return 0;
}
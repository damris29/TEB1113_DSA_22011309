#include <iostream>
#include <string>
using namespace std;

struct Student{
    int id;
    string name;
    string contact;
    string email;
};
int main() {
    Student student[5];
    for (int i = 0; i < 5; i ++){
        cout << "Enter the information for Student " << i+1 << ": " << endl;
        cout << "Id: "; cin >> student[i].id;
        cout << "Name: "; cin >> student[i].name;
        cout << "Contact: "; cin >> student[i].contact;
        cout << "Email: "; cin >> student[i].email;
        cout << endl;
    }
    cout << "===Students Information===" << endl;
    for(int i = 0; i < 5; i++){
        cout << "Id: " << student[i].id << endl;
        cout << "Name: " << student[i].name << endl;
        cout << "Contact: " << student[i].contact << endl;
        cout << "Email: " << student[i].email << "\n" << endl;
    }
    return 0;
}
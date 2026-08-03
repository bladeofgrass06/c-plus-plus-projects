#include <fstream>
#include <iostream>
#include <string>

using namespace std;

struct EmployeeData {
    string fName = "", lName = "";
    char initial = ' ';
    int id = 0, hours = 0;
    double wage = 0, pay = 0;
    EmployeeData *nextE = nullptr;
};

class LinkedList {
    private:
        EmployeeData *head;
    public:
        LinkedList() { head = nullptr; }
        ~LinkedList() {
            EmployeeData *currentE = head;
            while (currentE) {
                EmployeeData *nextE = currentE->nextE;
                delete currentE;
                currentE = nextE;
            }
        }
        void addEmployee(string f, string l, char in, int id, int h, double w, double p) {
            EmployeeData *newE = new EmployeeData{f, l, in, id, h, w, p};
            if (head == nullptr) head = newE;
            else {
                EmployeeData *temporaryE = head;
                while (temporaryE->nextE) temporaryE = temporaryE->nextE;
                temporaryE->nextE = newE;
            }
        }
        void findByName(string f, string l, char i) {
            EmployeeData *currentE = head;
            while (currentE) {
                if ((currentE->fName == f) && (currentE->lName == l) && (currentE->initial == i)) {
            		cout << endl << left << setw(20) << "First Name:" << currentE->fName << endl
                         << setw(20) << "Last Name:" << currentE->lName << endl
                         << setw(20) << "Initial:" << currentE->initial << endl
                         << setw(20) << "ID Number:" << currentE->id << endl
                         << setw(20) << "Hours Worked:" << currentE->hours << endl
                         << setw(20) << "Wage:" << currentE->wage << endl << setprecision(2)
                         << setw(20) << "Gross Pay:" << fixed << currentE->pay << endl << endl;
			        return;
                }
                currentE = currentE->nextE;
            }
            cerr << "Error: An employee with these details was not found!" << endl << endl;
        }
};

int main() {
    ifstream file("/Users/noahborden/Downloads/Programs/c-plus-plus-projects/Class/CS_I/Homework_6/Employee_Data.txt");
    if (!file) {
        cerr << endl << "Error: 'Employee_Data.txt' not found!" << endl << endl;
        file.close();
        return 0;
    }

    LinkedList employeeList;

    string line = "";
    getline(file, line);
    getline(file, line);

    string fName = "", lName = "";
    char initial = ' ';

    while (getline(file, line)) {
        int id = 0, hours = 0;
        double wage = 0, pay = 0;
        file >> fName >> lName >> initial >> id >> hours >> wage >> pay;
        employeeList.addEmployee(fName, lName, initial, id, hours, wage, pay);
    }

    cout << endl << "Enter the first name, middle initial, and last name of the employee: ";
    cin >> fName >> initial >> lName;

    employeeList.findByName(fName, lName, initial);

	file.close();
    return 0;
}
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Employee {
    int id;
    string name;
    double salary;

    // Serialize employee data to a file
    void writeToFile(ofstream &out) {
        out << id << endl;
        out << name << endl;
        out << salary << endl;
    }

    // Deserialize employee data from a file
    void readFromFile(ifstream &in) {
        in >> id;
        in.ignore(); // Ignore the newline character after ID
        getline(in, name);
        in >> salary;
    }
};

void addEmployee(const string &filename) {
    ofstream file(filename.c_str(), ios::app); // Explicit conversion
    if (!file) {
        cerr << "Error opening file for writing!" << endl;
        return;
    }

    Employee emp;
    cout << "Enter Employee ID: ";
    cin >> emp.id;
    cin.ignore(); // Ignore leftover newline
    cout << "Enter Employee Name: ";
    getline(cin, emp.name);
    cout << "Enter Employee Salary: ";
    cin >> emp.salary;

    emp.writeToFile(file);
    file.close();
    cout << "Employee record added successfully!" << endl;
}

void readEmployees(const string &filename) {
    ifstream file(filename.c_str()); // Explicit conversion
    if (!file) {
        cerr << "Error opening file for reading!" << endl;
        return;
    }

    Employee emp;
    cout << "\nEmployee Records:\n";
    while (file.peek() != EOF) { // Check for end of file
        emp.readFromFile(file);
        cout << "ID: " << emp.id << endl;
        cout << "Name: " << emp.name << endl;
        cout << "Salary: " << emp.salary << endl;
        cout << "------------------" << endl;
    }

    file.close();
}

int main() {
    string filename = "employees.txt";
    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Add Employee\n";
        cout << "2. View Employees\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addEmployee(filename);
                break;
            case 2:
                readEmployees(filename);
                break;
            case 3:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 3);

    return 0;
}

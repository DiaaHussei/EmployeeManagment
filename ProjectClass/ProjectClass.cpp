#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

// Employee class definition
struct Employee {
public:
    string name;
    int id;
    float salary;
    string phoneNumber; // added missing member variable
};

// function declarations

bool validatePhoneNumber(string& PhoneNumber) {
    //check the number
    for (char c : PhoneNumber) {
        if (!isdigit(c))return false;
    }
    return true;
}
void employeeMenu(vector<Employee>& employees);
void Menu(vector<Employee>& employees, int t);
void showAll(vector<Employee>& employees) {
    cout << "Showing all employees: " << endl;
    for (int i = 0; i < employees.size(); i++) {
        cout << "Employee ID: " << employees[i].id << endl;
        cout << "Name: " << employees[i].name << endl;

        cout << "Salary: " << employees[i].salary << endl;
        cout << endl;
    }
}
void addEmployee(vector<Employee>& employees) {
    Employee emp;
    string x;
    cout << "Enter employee's name: ";
    cin.ignore();
    getline(cin, emp.name);
    cout << "Enter employee's ID: ";
    cin >> emp.id;
    cout << "Enter the Phone number: ";
        cin >> x;
        if (validatePhoneNumber(x)) {
            emp.phoneNumber = x;
        }
        else {
            cout << "Sorry the foramt of the phone numebr is must be just in digit";
            return;
        }



    cout << "Enter employee's salary: ";
    cin >> emp.salary;
    employees.push_back(emp);

    ofstream outFile("employees.txt", ios::app); // open file in append mode
    if (!outFile) {
        cout << "Error: Failed to open employees.txt" << endl;
        return;
    }
    outFile << emp.name << "," << "," << emp.salary << endl; // write employee data to file
    outFile.close();

    cout << "Employee added successfully." << endl;
}
//void editEmployee(vector<Employee>& employees);
//void deleteEmployee(vector<Employee>& employees);
//void searchEmployee(vector<Employee>& employees);
//void findTopThree(vector<Employee>& employees);

int main() {
    vector<Employee> employees;
    ifstream inFile("employees.txt");
    if (inFile) {
        // Read employee data from file
        while (true) { // changed to infinite loop with break condition inside
            Employee emp;
            getline(inFile, emp.name);
            if (inFile.eof()) { // break if end of file reached
                break;
            }
            inFile >> emp.id >> emp.salary;
            inFile.ignore();
            getline(inFile, emp.phoneNumber); // read phone number as string
            employees.push_back(emp);
        }
        inFile.close();
    }
    int choice;
    do {
        // Display menu
        cout << "                  Employee Management System\n";
        cout << "                  --------------------------\n";
        cout << "                   1. Employee\n";
        cout << "                   2. Search Employee\n";
        cout << "                   3. Find Top Three Employees\n";
        cout << "                   4. Exit\n";
        cout << "                   Enter your choice (1-4): ";
        cin >> choice;
        system("cls");
        if (choice == 1) {
            employeeMenu(employees);
        }
        else if (choice == 2) { // changed if to else if to ensure only one option is selected
            searchEmployee(employees);
        }
        else if (choice == 3) { // same as above
           findTopThree(employees);
        }
        else if (choice != 4) { // added condition for invalid choice
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);
    ofstream outFile("employees.txt");
    if (outFile) {
        for (Employee emp : employees) {
            outFile << emp.name << endl;
            outFile << emp.id << " " << emp.salary << " " << emp.phoneNumber << endl;
        }
        outFile.close();
    }
    return 0;
}

void employeeMenu(vector<Employee>& employees) {
    int x;
    do {
        cout << "1-salaried Employee\n"; // fixed typo
        cout << "2-Hourly Employee\n";
        cout << "3-Commission Employee\n"; // fixed typo
        cout << "4-Back\n";
        cout << "Choice from 1-4: ";
        cin >> x;
        system("cls");
        switch (x) {
        case 1:
            Menu(employees, 1);
            break;
        case 2:
            Menu(employees, 2);
            break;
        case 3:
            Menu(employees, 3);
            break; // added break statement
        case 4:
            break;
        default:
            cout << "Invalid choice. Please try again.\n"; // added error message
            break;
        }
    } while (x != 4);
}

//void Menu(vector<Employee>& employees, int t) {
//    int x;
//    do {
//        cout << "Menu Options:\n";
//        cout << "1. Add an employee\n";
//        cout << "2. Remove an employee\n";
//        cout << "3. Display all employees\n";
//        cout << "4. Display all employees by type\n";
//        cout << "5. Display total salary\n";
//        cout << "6. Exit\n";
//        cout << "Enter your choice: ";
//        cin >> x;
//        switch (x) {
//        case 1: {
//            string name, type;
//            double salary;
//            cout << "Enter name, type and salary of the employee: ";
//            cin >> name >> type >> salary;
//
//            // Create an employee object and add it to the vector
//            Employee emp;
//            employees.push_back(emp);
//            cout << "Employee added successfully.\n";
//            break;
//        }
//
//        case 2: {
//            string n;
//            cout << "Enter name of the employee to be removed: ";
//            cin >> n;
//
//            // Remove the employee from the vector
//            bool found = false;
//            for (auto it = employees.begin(); it != employees.end(); it++) {
//                if (it->name == n) {
//                    employees.erase(it);
//                    found = true;
//                    break;
//                }
//            }
//
//            if (found) {
//                cout << "Employee removed successfully.\n";
//            }
//            else {
//                cout << "Employee not found.\n";
//            }
//            break;
//        }
//
//        case 3: {
//            // Display all employees
//            cout << "All Employees:\n";
//            for (const auto& emp : employees) {
//                cout << emp.id << "\n" << emp.name << endl;
//            }
//            break;
//        }
//
//
//
//        case 5: {
//            // Display total salary
//            double totalSalary = 0;
//            for (const auto& emp : employees) {
//                totalSalary += emp.salary;
//            }
//            cout << "Total salary: " << totalSalary << endl;
//            break;
//        }
//
//        case 6: {
//            // Exit the program
//            cout << "Exiting program.\n";
//            break;
//        }
//
//        default: {
//            cout << "Invalid choice. Please try again.\n";
//            break;
//        }
//        }
//    } while (x != 6);
//}


void Menu(vector<Employee>& employees, int t) {
    int x;
    do {
        cout << ".................................." << endl;
        cout << "1. Show All Employee\n";
        cout << "2. Add Employee\n";
        cout << "3. Edit Employee\n";
        cout << "4. Delete Employee\n";
        cout << "5. Back\n";
        cout << "Choice from 1-5 \n";
        cin >> x;

        // Switch statement to determine which action to take based on user input
        switch (x) {
        case 1:
           showAll  (employees);
            break;
        case 2:
            addEmployee(employees);
            break;
        case 3:
         //   editEmployee(employees);
            break;
        case 4:
          //  deleteEmployee(employees);
            break;
        case 5:
            // Exit the loop and return to the calling function
            return;
        default:
            // Handle invalid input
            cout << "Invalid input, please enter a number from 1-5." << endl;
            break;
        }
    } while (true); // Loop indefinitely until the user chooses to exit
}
//void writeToFile(vector<Employee>& employees, string filename) {
//    ofstream file(filename);
//    if (file.is_open()) {
//        for (int i = 0; i < employees.size(); i++) {
//            file << employees[i].name << ","  << "," << employees[i].salary << endl;
//        }
//        file.close();
//        cout << "Data written to file successfully!" << endl;
//    } else {
//        cout << "Error opening file!" << endl;
//    }
//}
//void showEmployeesFromFile(const string& filename) {
//    ifstream infile(filename);
//    if (!infile) {
//        cout << "Error: could not open file " << filename << endl;
//        return;
//    }
//
//    cout << "List of Employees:\n";
//    cout << "ID\tName\t\tAge\tSalary\n";
//    cout << "----------------------------------------------\n";
//
//    Employee emp;
//    while (infile >> emp.id >> emp.name  >> emp.salary) {
//        cout << emp.id << "\t" << emp.name << "\t\t"  << "\t" << emp.salary << endl;
//    }
//
//    infile.close();
//}



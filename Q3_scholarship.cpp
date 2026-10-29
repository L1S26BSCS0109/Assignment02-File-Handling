/*
 * Name       : Syed Qasim Iqbal
 * Reg No     : L1S26BSCS0109
 * Assignment : 02 - File Handling
 * Question   : Q3 - Scholarship List  
 */

#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main()
{
    char path[100];
    cout << "Enter the file name: ";
    cin.getline(path, 100);

    ifstream inFile(path);
    if (!inFile.is_open()) 
    {
        cout << "Could not open " << path << "!" << endl;
        return 1;
    }

    int n;
    inFile >> n;
    inFile.ignore(100, '\n');       

    if (n > 30) {
        cout << "Too many students!" << endl;
        return 1;
    }

    ofstream outFile("scholarship.txt");   

    char name[30];
    double cgpa;
    double sum = 0;
    double top = -1;
    char topName[30] = "";
    int count = 0, eligible = 0;

    for (int i = 0; i < n; i++) 
    {
        if (!inFile.getline(name, 30, ',')) 
        {
            break;
        }
        if (!(inFile >> cgpa)) 
        {
            break;
        }
        inFile.ignore(100, '\n');

        cout << "[" << name << "] CGPA: " << cgpa << endl;

        count++;
        sum = sum + cgpa;

        if (cgpa >= 3.50) 
        {
            outFile << name << "," << cgpa << endl;
            eligible++;
        }

        if (cgpa > top) 
        {             
            top = cgpa;
            strcpy(topName, name);
        }
    }

    inFile.close();
    outFile.close();

    if (count < n) 
    {
        cout << "Warning: only " << count << " of " << n << " records found." << endl;
    }

    if (count == 0) 
    {
        cout << "No students found!" << endl;
        return 0;
    }

    cout << "Students: " << count << endl;
    cout << "Average CGPA: " << sum / count << endl;
    cout << "Eligible for scholarship: " << eligible << endl;
    cout << "Top student: " << topName << " (" << top << ")" << endl;

    return 0;
}
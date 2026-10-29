/*
 * Name       : Syed Qasim Iqbal
 * Reg No     : L1S26BSCS0109
 * Assignment : 02 - File Handling
 * Question   : Q2 - Parking Report
 */

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main() 
{
    ifstream inFile("parking.txt");
    if (!inFile) 
    {
        cout << "parking.txt not found!" << endl;
        return 1;
    }

    int d, m, y;
    char slash;
    inFile >> d >> slash >> m >> slash >> y;
    inFile.ignore(100, '\n');      
    inFile.ignore(100, '\n');      

    ofstream receipts("receipts.txt");  

    cout << "Parking report for " << d << "/" << m << "/" << y << endl;
    receipts << "Receipts for " << d << "/" << m << "/" << y << endl;

    char plate[15];
    char type;
    int inH, inM, outH, outM;
    char colon;

    int count = 0, cars = 0, bikes = 0, total = 0;
    int longest = -1;
    char longestPlate[15] = "";

    while (count < 30 && inFile >> plate >> type >> inH >> colon >> inM >> outH >> colon >> outM) 
    {
        int minutes = (outH * 60 + outM) - (inH * 60 + inM);

        int hoursCharged = (minutes + 59) / 60;
        if (hoursCharged == 0) 
        {
            hoursCharged = 1;
        }

        int fee;
        if (type == 'C')
        {
            fee = hoursCharged * 100;
            cars++;
            cout << plate << " Car ";
        }
        else
        {
            fee = hoursCharged * 40;
            bikes++;
            cout << plate << " Bike ";
        }

        cout << minutes / 60 << " h " << minutes % 60 << " min Fee: " << fee << endl;
        receipts << plate << " " << fee << endl;

        total = total + fee;

        if (minutes > longest) 
        {        
            longest = minutes;
            strcpy(longestPlate, plate);
        }

        count++;
    }

    inFile.close();
    receipts.close();

    if (count == 0) {
        cout << "No vehicles found!" << endl;
        return 0;
    }

    cout << "Vehicles: " << count << endl;
    cout << "Cars: " << cars << " Bikes: " << bikes << endl;
    cout << "Total collected: " << total << endl;
    cout << "Longest stay: " << longestPlate << " (" << longest / 60 << " h " << longest % 60 << " min)" << endl;

    return 0;
}
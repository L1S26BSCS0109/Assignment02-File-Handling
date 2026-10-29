/*
 * Name       : Syed Qasim Iqbal
 * Reg No     : L1S26BSCS0109
 * Assignment : 02 - File Handling
 * Question   : Q1 - Stock Report (Debugging)
 */

#include <iostream>
#include <fstream> // FIX 1: <fstream> was missing so ifstream and ofstream were unknown
using namespace std;

int main() {
    ifstream inFile("stock.txt");
    if (!inFile) // FIX 2: if files finds its program exit so we need (!infile) if file not found then exits. 
    {        
        cout << "stock.txt not found!" << endl;
        return 1;
    }

    ofstream reorder("reorder.txt", ios::app); // FIX 3: Added ios::app so that new low-stock items get added to the end without deleting past records

    char code[10];
    int qty, count = 0, low = 0;
    double price;
    double total = 0;  // FIX 4: int total to double total to keep all the decimal Values.

    inFile.ignore(1000, '\n');    // FIX 5: inFile.ignore was missing,so the program would try to read the text header line as item data

    while (count < 50 && inFile >> code >> qty >> price) {
        count++;
        total = total + qty * price;
        if (qty < 10) {
            reorder << code << " " << qty<<endl; // FIX 6: endl was missing when writing to reorder.txt
            low++;
        }
    }
    inFile.close();
    reorder.close();

    cout << "Items: " << count << endl;
    cout << "Total stock value: " << total << endl;
    cout << "Low stock items: " << low << endl;
    return 0;
}

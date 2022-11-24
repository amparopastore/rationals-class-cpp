/*
* Application file for class rationals
*
* Date: 11/24/2022
* Author: Amparo Godoy Pastore
*/

#include <string>
#include <fstream>
#include "rationals.h"
#include <iostream>

using namespace std;
using namespace Amparo_ns1;

//TEST DRIVE FOR CLASS RATIONAL

int main()
{
    /*gets user input*/
    cout << "Class Implementation Testing...\n\n"
    "*Legal rational input formats: x/x, -x/x, -x/-x, or x/-x.\n*Input forms x/-x and -x/-x will be converted to -x/x and x/x, respectively.\n\n"
    "Enter a rational number.\n> ";
    rational test1;
    //testing >> overloading
    cin >> test1;
    //testing << overloading
    cout << "You entered the number " << test1
    << "\n\nEnter a second rational number.\n> ";
    rational test2;
    cin >> test2;
    cout << "You entered the number " << test2;

    /*tests arithmetic operators*/
    cout << "\n\nArithmetic operator testing:\n"
    "---------------------------\n";
    rational result;

    result = test1 + test2;
    cout << test1 << " + " << test2 << " = " << result << endl;

    result = test1 - test2;
    cout << test1 << " - " << test2 << " = " << result << endl;

    result = test1 * test2;
    cout << test1 << " * " << test2 << " = " << result << endl;

    result = test1 / test2;
    cout << test1 << " / " << test2 << " = " << result << endl;

    /*tests comparison operators*/
    cout << "\nComparison operator testing:\n"
    "---------------------------\n";

    cout << "Is " << test1 << " smaller than " << test2 << " ?\n";
    test1 < test2 ? cout << "Yes\n" : cout << "No\n";

    cout << "Is " << test1 << " smaller than or equal to " << test2 << " ?\n";
    test1 <= test2 ? cout << "Yes\n" : cout << "No\n";

    cout << "Is " << test1 << " larger than " << test2 << " ?\n";
    test1 > test2 ? cout << "Yes\n" : cout << "No\n";

    cout << "Is " << test1 << " larger than or equal to " << test2 << " ?\n";
    test1 >= test2 ? cout << "Yes\n" : cout << "No\n";

    cout << "Is " << test1 << " equal to " << test2 << " ?\n";
    test1 == test2 ? cout << "Yes\n" : cout << "No\n";

    /*tests arithmetic and booleans with objects and ints*/
    int z;
    cout << "\nTesting with types rational and int:\n"
    "------------------------------------\n"
    << "\nEnter an integer: ";
    cin >> z;
    cout << "\nNow testing with the values " << z << " and " << test1 << endl << endl;

    cout << test1 << " + " << z << " = " << test1 + z << endl;

    cout << test1 << " - " << z << " = " << test1 - z << endl;

    cout << test1 << " * " << z << " = " << test1 * z << endl;

    cout << test1 << " / " << z << " = " << test1 / z << endl << endl;

    cout << "Is " << test1 << " smaller than " << z << " ?\n";
    test1 < z ? cout << "Yes\n" : cout << "No\n";

    cout << "Is " << test1 << " smaller than or equal to " << z << " ?\n";
    test1 <= z ? cout << "Yes\n" : cout << "No\n";

    cout << "Is " << test1 << " larger than " << z << " ?\n";
    test1 > z ? cout << "Yes\n" : cout << "No\n";

    cout << "Is " << test1 << " larger than or equal to " << z << " ?\n";
    test1 >= z ? cout << "Yes\n" : cout << "No\n";

    cout << "Is " << test1 << " equal to " << z << " ?\n";
    test1 == z ? cout << "Yes\n" : cout << "No\n";


    /*constructor testing*/
    cout << "\nTesting constructors:\n"
    "---------------------\n";
    int x, y;
    cout << "\nEnter two integers: \n";
    cin >> x >> y;
    //default
    rational test3;
    cout << "\na) Default: " << test3;
    //single int
    rational test4(x);
    cout << "\nb) Single integer: " << test4;
    //two ints
    rational test5(x, y);
    cout << "\nc) Two integers: " << test5 << endl;


    //--------TESTING FILE OUTPUT/INPUT--------

    /*inputs from file*/
    cout << "\nTesting input from a file:\n"
    "---------------------------\n";
    rational test6;
    string ifile_name;
    cout << "\nEnter the name of your input file and file extension type: ";
    cin >> ifile_name;
    ifstream input(ifile_name);
    if(input.fail())
    {
        cout << "File opening failed.\n";
        exit(1);
    }
    while (!input.eof()) //reads input from file
    {
        input >> test6;
        cout << test6 << endl;
    }

    input.close();

    /*testing output to a file*/
    string ofile_name;
    cout << "\nEnter the name of your input file and file extension type: ";
    cin >> ofile_name;
    ofstream output(ofile_name);
    if(output.fail())
    {
        cout << "File opening failed.\n";
        exit(1);
    }
    output << "test 1: " << test1 << endl << "test 2: " << test2;
    output.close();

    cout << "\nEND OF CLASS TESTING :)!!\n\n";

    return 0;
}

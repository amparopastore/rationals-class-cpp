#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <cstdio>
#include <cmath>

using namespace std;

class rational {

public:
    /*constructors*/
    rational();
    rational(int);
    rational(int, int);
    /*operators*/
    friend istream& operator >>(istream&, rational&);
        //Overloads the >> operator so it can be used to input values of type rational.
        //Notation for inputting values of type rational is a/b, -a/b, -a/-b, or a/-b, where b != 0.
        //Pre: If ins is a file input stream, then ins has already been connected to a file.
    friend ostream& operator <<(ostream&, const rational&);
        //Overloads the << operator so it can be used to output values of type rational.
        //Pre: If outs is a file output stream, then outs has already been connected to a file.
    friend bool operator ==(const rational&, const rational&);
        //Precondition: num1 and num2 have been given values.
        //Returns true if num1 is equal to num2.
    friend bool operator <(const rational&, const rational&);
        //Precondition: num1 and num2 have been given values.
        //Returns true if num1 is smaller than num2.
    friend bool operator <=(const rational&, const rational&);
        //Precondition: num1 and num2 have been given values.
        //Returns true if num1 is smaller than or equal to num2.
    friend bool operator >(const rational&, const rational&);
        //Precondition: num1 and num2 have been given values.
        //Returns true if num1 is larger than num2.
    friend bool operator >=(const rational&, const rational&);
        //Precondition: num1 and num2 have been given values.
        //Returns true if num1 is larger than or equal to num2.
    friend rational operator +(const rational&, const rational&);
        //Pre: num1 and num2 have been given values.
        //Returns the sum of the values of num1 and num2.
    friend rational operator -(const rational&, const rational&); //binary
        //Pre: num1 and num2 have been given values.
        //Returns the difference of the values of num1 and num2.
    friend rational operator *(const rational&, const rational&);
        //Pre: num1 and num2 have been given values.
        //Returns the product of the values of num1 and num2.
    friend rational operator /(const rational&, const rational&);
        //Pre: num1 and num2 have been given values.
        //Returns the quotient of the values of num1 and num2.
    friend rational operator -(const rational&); //unary
        //Pre: num has been given a value.
        //Returns negative num.

private:
    int numerator;
    int denominator;

};
//TEST DRIVE
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

//---------------CONSTRUCTORS---------------
rational::rational() : numerator(0), denominator(1) {}

rational::rational(int x) : numerator(x), denominator(1){}

rational::rational(int x, int y) : numerator(x), denominator(y){
    if(y == 0)
    {
       cout << "\nIllegal input.\n";
       exit(1);
    }
}

//---------------OVERLOADED OPERATORS---------------
istream& operator >>(istream& ins, rational& num)
{
    char slash;
    int x, y;

    ins >> x >> slash >> y; //reads input

    if(y < 0 && x > 0)
    {
        y = abs(y);
        x = -x;
    }
    else if (y < 0 && x < 0)
    {
        y = abs(y);
        x = abs(x);
    }

    //checks if input is legal
    if(slash != '/' || y == 0)
    {
        cout << "\nIllegal input form of rational. Process terminated.\n";
        exit(1);
    }

    num.numerator = x;
    num.denominator = y;

    return ins;

}

ostream& operator <<(ostream& outs, const rational& num)
{
    outs << num.numerator << "/" << num.denominator;
    return outs;
}

bool operator ==(const rational& num1, const rational& num2)
{
    return (num1.numerator * num2.denominator) == (num2.numerator * num1.denominator);
}

bool operator <(const rational& num1, const rational& num2)
{
    return (num1.numerator * num2.denominator) < (num2.numerator * num1.denominator);
}

bool operator <=(const rational& num1, const rational& num2)
{
    return (num1.numerator * num2.denominator) <= (num2.numerator * num1.denominator);
}

bool operator >(const rational& num1, const rational& num2)
{
    return (num1.numerator * num2.denominator) > (num2.numerator * num1.denominator);
}

bool operator >=(const rational& num1, const rational& num2)
{
    return (num1.numerator * num2.denominator) >= (num2.numerator * num1.denominator);
}

rational operator +(const rational& num1, const rational& num2)
{
    rational temp;
    temp.numerator = num1.numerator * num2.denominator + num1.denominator * num2.numerator;
    temp.denominator = num1.denominator * num2.denominator;
    return temp;
}

rational operator -(const rational& num1, const rational& num2) //binary
{
    rational temp;
    temp.numerator = num1.numerator * num2.denominator - num1.denominator * num2.numerator;
    temp.denominator = num1.denominator * num2.denominator;
    return temp;
}

rational operator *(const rational& num1, const rational& num2)
{
    rational temp;
    temp.numerator = num1.numerator * num2.numerator;
    temp.denominator = num1.denominator * num2.denominator;
    return temp;
}

rational operator /(const rational& num1, const rational& num2)
{
    rational temp;
    temp.numerator = num1.numerator * num2.denominator;
    temp.denominator = num2.numerator * num1.denominator;
    return temp;
}

rational operator -(const rational& num) //unary
{
    rational temp;
    temp.numerator = -num.numerator;
    temp.denominator = num.denominator;
    return temp;
}

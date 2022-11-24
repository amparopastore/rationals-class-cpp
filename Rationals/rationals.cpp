/*
* Implementation file for class rationals
*
* Date: 11/24/2022
* Author: Amparo Godoy Pastore
*
*/

#include <fstream>
#include <string>
#include <cctype>
#include <cstdio>
#include <cmath>
#include "rationals.h"
#include <iostream>

using namespace std;

namespace Amparo_ns1
{
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
// >> operator overloading
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
// << operator overloading
    ostream& operator <<(ostream& outs, const rational& num)
    {
        outs << num.numerator << "/" << num.denominator;
        return outs;
    }
// == operator overloading
    bool operator ==(const rational& num1, const rational& num2)
    {
        return (num1.numerator * num2.denominator) == (num2.numerator * num1.denominator);
    }
// < operator overloading
    bool operator <(const rational& num1, const rational& num2)
    {
        return (num1.numerator * num2.denominator) < (num2.numerator * num1.denominator);
    }
// <= operator overloading
    bool operator <=(const rational& num1, const rational& num2)
    {
        return (num1.numerator * num2.denominator) <= (num2.numerator * num1.denominator);
    }
// > operator overloading
    bool operator >(const rational& num1, const rational& num2)
    {
        return (num1.numerator * num2.denominator) > (num2.numerator * num1.denominator);
    }
// >= operator overloading
    bool operator >=(const rational& num1, const rational& num2)
    {
        return (num1.numerator * num2.denominator) >= (num2.numerator * num1.denominator);
    }
// + operator overloading
    rational operator +(const rational& num1, const rational& num2)
    {
        rational temp;
        temp.numerator = num1.numerator * num2.denominator + num1.denominator * num2.numerator;
        temp.denominator = num1.denominator * num2.denominator;
        return temp;
    }
// - operator overloading
    rational operator -(const rational& num1, const rational& num2) //binary
    {
        rational temp;
        temp.numerator = num1.numerator * num2.denominator - num1.denominator * num2.numerator;
        temp.denominator = num1.denominator * num2.denominator;
        return temp;
    }
// * operator overloading
    rational operator *(const rational& num1, const rational& num2)
    {
        rational temp;
        temp.numerator = num1.numerator * num2.numerator;
        temp.denominator = num1.denominator * num2.denominator;
        return temp;
    }
// / operator overloading
    rational operator /(const rational& num1, const rational& num2)
    {
        rational temp;
        temp.numerator = num1.numerator * num2.denominator;
        temp.denominator = num2.numerator * num1.denominator;
        return temp;
    }
// - operator overloading
    rational operator -(const rational& num) //unary
    {
        rational temp;
        temp.numerator = -num.numerator;
        temp.denominator = num.denominator;
        return temp;
    }
}




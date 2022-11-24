/*
* Interface for class rationals
*
* Date: 11/24/2022
* Author: Amparo Godoy Pastore
*/

#ifndef RATIONALS_H
#define RATIONALS_H

#include <iostream>
using namespace std;

namespace Amparo_ns1
{
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
}

#endif // RATIONALS_H

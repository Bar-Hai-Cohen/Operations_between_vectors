#include <iostream>
#include "Vector.h"

using namespace std;

int main() {
    Vector a(4);
    double arr[] = {2.1, 3.5, 6.2, 4.8, 5};
    double arr1[] = {1, 1, 1.2, 1.8, 5};

    Vector b(arr, 5);

    Vector t(arr1, 5);
    Vector d(4);


    //operator *
    Vector c = b * 2;
    cout << c << endl;


    Vector mult = d * 10;
    cout << "The multi is" << mult << endl;


    //Cout tester:
    cout << a << " " << b << " " << c << " " << d << endl;
    cout << a << endl << b << endl << c << endl << d << endl;
    cout << a.getSize() << " " << b.getSize() << " " << c.getSize() << " " << d.getSize() << " " << endl;

    //copy constructor
    Vector copy(c);
    cout << copy << endl;

    //Cout to [] operator
    cout << d[-1] << endl; // error
    cout << d[5] << endl; // error
    cout << d[0] << endl; //  return zero --> 0

    //Cout to + operator
    Vector plus = a + 5;
    cout << plus << endl;

    Vector plus2 = b + 5;
    cout << plus2 << endl;

    //tester ==
    if (c == b) {
        cout << "works" << endl;
    } else {
        cout << "not works" << endl;
    }

    if (a == d) {
        cout << "works" << endl;
    } else {
        cout << "not works" << endl;
    }

    //Operator =

    Vector newvec = plus;
    plus = b;
    cout << plus << endl;

    //operator *

    cout << plus.dot(b) << endl;

    // operator * vectors

    //TODO: check why he do error on this line

//    Vector v_x = a * b;
//    cout << v_x << endl;

    //Friend function

    Vector v = 2 + a;
    cout << v << endl;


    Vector v1 = 5 * t;
    cout << v1 << endl;


    return 0;
}

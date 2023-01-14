//
// Created by   bar cohen on 12/01/2023.
//

#ifndef VECTOR_VECTOR_H
#define VECTOR_VECTOR_H
#define ERROR -999

#include <iostream>
#include <ostream>
using namespace  std;

class Vector {
    friend Vector operator+(double d,Vector &v); //The function will add a scalar d to the vector v and return a new vector with the result.
    friend Vector operator*(double d, Vector& v); //The function will multi a vector d to the vector v and return a new vector with the result.
    friend ostream& operator<<(ostream& out, Vector& v); // function that print to cout from ostream the vector

private:
    double *elements; // The pointer for the vector
    int size; // The size of the vector

public:
//    void print();
    Vector(int n); // Constructor
    Vector(double a[], int n); //Another Constructor that copy the 'a' vector to out vector
    Vector(const Vector &v); //Copy Constructor
    int getSize(); //Return the size of the vector
    Vector operator=(Vector &v); // Operator that copy the v vector to this vector
    double operator[](int ind); // return the element in this index
    Vector operator+(double d);// function that add a scalar d to the vector v and return a new vector with the result.
    double dot(Vector &v);// The function will perform a scalar multiplication between two vectors.
    bool operator==(Vector &v);//Return true if the both of the vector are equals else false
    Vector operator*(double d);// The function will perform a scalar multiplication d on the vector and return a new vector with the result.
    ~Vector(); // Destructor
    Vector operator*(const Vector &v); //The function will perform a multiplication between two vectors and return a new vector with the result.






};


#endif //VECTOR_VECTOR_H

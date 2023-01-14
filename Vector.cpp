//
// Created by   bar cohen on 12/01/2023.
//

#include "Vector.h"

Vector::Vector(int n) { // Constructor
    if (n <= 0) { // TODO: what to do when i get n zero
        return;
    }
    this->elements = new double[n]; // Create the vector
    this->size = n;
    for (int i = 0; i < n; ++i) { // Reset all the elements to zero
        this->elements[i] = 0;
    }
}

Vector::Vector(double a[], int n) {
    if (n <= 0) {
        return;
    }
    this->elements = new double[n];// Create the vector
    this->size = n;
    for (int i = 0; i < n; ++i) { // Copy the elements from 'a' to our vector
        this->elements[i] = a[i];
    }
}

Vector::Vector(const Vector &v) {
    int size = v.size; //Check if the size is zero
    if (size == 0) // if zero break
        return;
    this->elements = new double[v.size];// Create the vector
    this->size = v.size;
    for (int i = 0; i < v.size; ++i) { // Copy the elements from 'v' to our vector
        this->elements[i] = v.elements[i];
    }
}

int Vector::getSize() { // Return the size of the vector
    return this->size;
}

Vector Vector::operator=(Vector &v) { //Operator to copy the value from the 'v' vector to this vector
    if (this->elements == v.elements || v.size == 0) {
        return *this; // return this is they are equal
    } else {
        delete[] this->elements; // free the pointer
        this->elements = new double[v.size];
        this->size = v.size;
        for (int i = 0; i < v.size; ++i) { // Copy the elements from 'v' to our vector
            this->elements[i] = v.elements[i];
        }
        return *this;
    }
}

double Vector::operator[](int ind) { // Return the
    if (ind >= this->size || ind < 0) //TODO: check if its also equals?
        //TODO:what to do when i get vector in different size
        return ERROR;
    return this->elements[ind];
}

Vector Vector::operator+(double d) {
    /*
     * The function will add a scalar d to the vector v and return a new vector with the result.
     */
    Vector newVec(this->size); // // Create new Vector on the size of this vector
    for (int i = 0; i < this->size; ++i) {
        newVec.elements[i] = this->elements[i] + d; // add the d scalar with the elements
    }
    return newVec;
}

double Vector::dot(Vector &v) {
    if (v.size == 0 || v.size != this->size) // if v is empty return
        return ERROR;

    double sum = 0;
    for (int i = 0; i < this->size; ++i) { // sum all the multi between two elements
        sum += this->elements[i] * v.elements[i];
    }
    return sum; // return sum
}

bool Vector::operator==(Vector &v) {
    if (this->size != v.size || v.size == 0) // if the size are not equal or the size of v is zero return false
        return false;
    for (int i = 0; i < v.size; ++i) { // else compare all the elements if there are no equal return false
        if (this->elements[i] != v.elements[i])
            return false;
    }
    return true;// return true
}

Vector Vector::operator*(double d) {
    /*
     *  The function will perform a scalar multiplication d
     *  on the vector and return a new vector with the result.
     */
    Vector newVec(this->size); // // Create new Vector on the size of this vector
    for (int i = 0; i < this->size; ++i) {
        newVec.elements[i] = this->elements[i] * d; // Multi the d scalar with the elements
    }
    return newVec;
}

Vector::~Vector() { // Destructor
    delete[] this->elements; // delete the pointer
}

Vector operator+(double d, Vector &v) {
    return v + d; // use operator +
}

Vector operator*(double d, Vector &v) {
    return v * d; // use operator multi *
}

Vector Vector::operator*(const Vector &v) {
    if (this->size != v.size) { // if the size are not equal
        Vector v(0);
        return v;// TODO: RETURN VECTOR ZERO
    } else {
        Vector v1(v.size); // Crate constructor
        for (int i = 0; i < v.size; ++i) {
            v1.elements[i] = this->elements[i] * v.elements[i]; // multi each element from this on v
        }
        return v1; // return v1
    }
}

ostream &operator<<(ostream &out, Vector &v) { // function that print to out vector

    out << "[";
    for (int i = 0; i < v.size; ++i) { // add the element to out
        out << v.elements[i];
        if(i!=v.getSize()-1){
            out<<",";
        }
    }
    out << "]";
    return out; // return out
}

//void Vector::print() {
//    for (int i = 0; i < this->size; ++i) {
//        std::cout << this->elements[i] << " ";
//    }
//}




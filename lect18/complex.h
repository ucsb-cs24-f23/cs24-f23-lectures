//complex.h
#include <iostream> 
#include <cmath>

using namespace std;

// Represent a complex number as ADT: a + jb
class Complex{
    public:
        // constructor is a special function
        // no return value, same name as class
        // initialize the member variables
        Complex(double re = 0, double im = 0){
            real = re;
            imag = im;
        }
        // getters or accessors 
        void print() const{
            cout << real << " + " << imag << "j" << endl;
        }
        double magnitude() const {
            return sqrt(pow(getReal(),2) + pow(getImag(), 2));
        }

        Complex operator+(Complex c) const{
            return Complex(c.real + real , c.imag + imag );
        }

        double getReal() const { return real;}
        double getImag() const { return imag;}
        void conjugate() {
            imag = -1 * imag;
        }
   
    private:
        double real;
        double imag; 
};

// Non-member functions
ostream& operator<<(ostream& out, Complex x){
    x.print();
    return out;
}

bool operator<(const Complex& a, const Complex& b){
    return a.magnitude() < b.magnitude();
}

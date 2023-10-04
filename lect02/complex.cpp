//complex.cpp
#include <iostream> // inout output

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
        double magnitude() const;

        Complex add(Complex c) const{
            return Complex(c.real + real , c.imag + imag );
        }

        
        double getReal() const { return real;}
        double getImag() const;
        void conjugate() {
            imag = -1 * imag;
        }
        // void setReal(double re);
        // void setImag(double im);
       
    private:
        double real;
        double imag; 
};

int main(int argc, char const *argv[])
{
    Complex c(1, 2);
    Complex p(4, 3);
    Complex z = p.add(c);
    //cout << c.real; // This won't work
    z.print();
    return 0;
}

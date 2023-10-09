//complex.cpp
#include <iostream> // input output
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

// Non-member function
// Complex operator+(Complex x, Complex y){
//     return Complex(x.getReal() + y.getReal() , x.getImag() + y.getImag() );

// }
ostream& operator<<(ostream& out, Complex x){
    x.print();
    return out;
}


int main(int argc, char const *argv[])
{
    Complex c(1, 2);
    Complex p(4, 3);
    Complex q(1, 1);
    cout << p.magnitude() << endl;
    Complex z = p + c + q;
    //z.print();
    cout << z << c;
    return 0;
}

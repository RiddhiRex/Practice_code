
============ Coding exercise ================================================
You will be creating three classes. The first class is called Number, which supports three
operations: display, "==" and "+".
 
1.    display: This operation displays the Number itself in its original form (I will
       explain later).
2.    ==: This operation returns true if two Numbers are numerically the same.
3.    +: This operation adds the Number itself with another Number and returns a third
       Number whose numeric value is equal to the sum of the numeric values of the former
       two.
 
The second class is called Integer, which is represented by its integer value. The third class is Fraction, which is represented by its numerator and denominator (both are integers).
Integer and Fraction are the only two kinds of Numbers. Naturally, they support all three operations of Number. To be more precise, you can add two Integers, or two Fractions, or one Integer and one Fraction.
 
For a Fraction, it needs to be displayed in its original form. That is, "2/4" has to be displayed as such, not "1/2" or "0.5".
-----------------------------------


#include <iostream>
using namespace std;

class integer;
class fraction;

class number {
public:
    virtual void display() =0;
    virtual bool isEqual(integer n);
    virtual bool isEqual(fraction f);
};

class integer : public number {
private:
    int data;
public:
    integer() {
        data=0;
    }   
    integer(int n) {
        data=n;
    }
    void display() {
        cout<<"Integer Output :"<<data<<endl;
    }
    //Checking equality
    bool isEqual(integer n) {
        return (data==n.data);
    }
    //addition of two integers
    int addition(integer n) {
        return (data+n.data);
    }
    int getData() {
        return data;
    }
    //addition of a integer and a fraction
    integer addition(fraction ob2);
};


class fraction: public number {
private:
    int numerator;
    int denominator;
public:
    fraction(int n, int d) {
        numerator = n;
        if(d==0) {
            cout<<"Error: division by zero"<<endl;
            exit(0);
        }
        else {
            denominator = d;
        }
    }
    fraction(int n) {
        numerator = n;
        denominator = 1;
    }
    fraction() {
        numerator = 1;
        denominator = 1;
    }
    int getNumerator() {
        return numerator;
    }
    int getDenominator() {
        return denominator;
    }
    //Checking equality
    bool isEqual(fraction f) {
        return (((float)numerator/(float)denominator) == ((float)f.numerator/(float)f.denominator));
    }
    //Addition of two fractions
    fraction addition(fraction f) {
        int num=1;
        int deno =1;
        if(denominator == f.denominator) {
            num = numerator + f.numerator;
            deno = denominator;
        }
        else {
            num = numerator*f.denominator+ f.numerator*denominator;
            deno = denominator*f.denominator;
        }
        return fraction(num, deno);
    }
    //Addition of a integer and a fraction
    fraction addition(integer ob2) {
        int num=1;
        int deno=1;
        if(denominator == 1) {
            num = numerator + ob2.getData();
            deno = denominator;
        }
        else {
            num = numerator+ ob2.getData()*denominator;
            deno = denominator;
        }
        return fraction(num ,deno);
    }
    void display() {
        if (denominator==1) {
            cout<<"Fraction Output :"<<numerator<<endl;
        }
        else {
            cout<<"Fraction Output: "<<numerator <<"/"<<denominator<<endl;
        }
    }
};
//Function definition of addition function of integer class
integer integer::addition(fraction ob2) {
        int num=1;
        int deno=1;
        if(ob2.getDenominator()==1) {
            num = data + ob2.getNumerator();
            deno = ob2.getDenominator();
        }
        else {
            num = data*ob2.getDenominator()+ ob2.getNumerator();
            deno = ob2.getDenominator();
        }
        return integer(num/deno);
    }
    

//Base class numbers function definition
bool number::isEqual(integer n) {}
bool number::isEqual(fraction f) {}


int main() {

	//Object creation for ineteger class
	integer i1(1);
	integer i2(3);
	integer i3;
	//Object creation for fraction class
	fraction f1(10, 3);
    fraction f2(9, 5);
    fraction f3;

	//Functionalities with integer obj
	number *no = &i1;
	number *no1 = &i3;
    cout<<"Addition of two integers : "<<i1.addition(i2)<<endl;
	if(no->isEqual(i2)) 
		cout<<"Integers are equal"<<endl;
	else 
	    cout<<"Integers are not equal"<<endl;
	i3 = i1.addition(f1);
	no1->display();
	
	//Functionalities with fraction obj
	no = &f1;
    number *no2 = &f3;
	f3 = f1.addition(f2);
    no2->display();
	if(no->isEqual(f2)) 
		cout<<"The Fractions are equal"<<endl;
	else 
	    cout<<"The fractions are not equal"<<endl;
	 f3= f1.addition(i1);
	 no2->display();	
}

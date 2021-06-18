/*
 Gerardo Galan Garzafox A00821196
 CREATED_AT  2021-03-20
 MODIFIED_AT 2021-04-05
 
 DESCRIPTION
 The objective of this class is to abstract the handling of
 inputs and outputs from the main class by asking and checking the required
 attributes in read() from the user, then send this to main class 
 and wait for it to call print() to display the expected format
*/

#include <iostream>

using namespace std;

#ifndef IO_h
#define IO_h

//.i
class IO{
    //.b=72
    public:
        IO();
        int read();
        void print();
        
        long double getX();
        int getDOF();
        long double getP();
        void setX(long double);
        void setDOF(int);
        void setP(long double);
    private:
        long double x;
        int dof;
        long double p;
};

//.i
IO::IO(){
    setX(0.0L);
    setDOF(0);
    setP(0.0L);
}

//.i 
/*
 This is intended as the method for reciving
 inputs from the user, it doesn't have any 
 parameters, it return a 0 if it catched an 
 error and 1 if it didnt, it verifies the user
 input for several fail scenarios
 */
int IO::read(){
    long double input1;
    int input2;
    
    cout << "dame el valor de la p: " << endl;//.m
    try{
        cin >> input1;
        if(!cin.good()){
            cout << "Error entrada no valida para p" << endl;//.m
            throw exception();
        }
        if(input1 < 0 || input1 > 0.5){
            cout << "Error p es un número real >= 0 y menor a 0.5" << endl;//.m
            throw exception();
        }
    }catch(const exception&){
        return 0;   
    }
    setP(input1);//.m
    
    cout << "dame el valor de dof: " << endl;
    try{
        cin >> input2;
        if(!cin.good()){
            cout << "Error entrada no valida para dof" << endl;
            throw exception();
        }
        if(input2 < 0){
            cout << "Error dof es un número entero >= 0" << endl;
            throw exception();
        }

    }catch(const exception&){
        return 0;
    }
    setDOF(input2);
    return 1;
}

//.i
/*
 This function is intended to handle
 the outputs of this class, donsent recive
 nor return any variables, it just calls
 the class getters and prints their results
 in the specified format
 */
void IO::print(){
    printf("\t  p = %.5Lf\n", getP());//.m
    printf("\tdof = %d\n", getDOF());
    printf("\t  x = %.5Lf\n", getX());//.m
    return;
}

//.i
long double IO::getX(){
    return x;
}

//.i
int IO::getDOF(){
    return dof;
}

//.i
long double IO::getP(){
    return p;
}

//.i
void IO::setX(long double value){
    x = value;
    return;
}

//.i
void IO::setDOF(int value){
    dof = value;
    return;
}

//.i
void IO::setP(long double value){
    p = value;
    return;
}

#endif 

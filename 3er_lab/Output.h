#include <iostream>
#include "Regression.h"
using namespace std;

#ifndef Output_h
#define Output_h

//.i
class Output{
    public:
        Output(Regression);
        void print();
        Regression getReg();
        void setReg(Regression);
    private:
        Regression reg;
};

//.i
Output::Output(Regression R){
    setReg(R);
}

//.i
void Output::print(){
    printf("\tN  = %d\n",   getReg().getN());
    printf("\txk = %d\n",   getReg().getXk());
    printf("\tr  = %.5Lf\n", getReg().getR());
    printf("\tr2 = %.5Lf\n", getReg().getR2());
    printf("\tb0 = %.5Lf\n", getReg().getB0());
    printf("\tb1 = %.5Lf\n", getReg().getB1());
    printf("\tyk = %.5Lf\n", getReg().getYk());
    return;
}

//.i
Regression Output::getReg(){
    return reg;
}

//.i
void Output::setReg(Regression R){
    reg = R;
    return;
}

#endif 

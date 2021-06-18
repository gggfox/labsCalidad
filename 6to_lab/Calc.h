/*
 Gerardo Galan Garzafox A00821196
 CREATED_AT  2021-04-21
 MODIFIED_AT 2021-04-22
 
 DESCRIPTION
    The objective of this class is to comute the 
    significance, range, Upper limit and Lower limit
    given 2 vectors and return the resuts with the getData()
    method.
*/

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

#ifndef Calc_h
#define Calc_h

#include"Regression.h"//recibes vector X vector Y and 
#include"Simpson.h"

//.i
class Calc{
    public:
        Calc(vector<long double>, vector<long double>, long double);
        long double standardDeviation(
          vector<long double>, vector<long double>);
        long double calcRan(
          vector<long double>, vector<long double>, long double);
        vector<long double> getData();

        Regression getRegression();
        void setRegression(Regression);
        Simpson getSimpson();
        void setSimpson(Simpson);

        long double getSig();
        void setSig(long double);
        long double getRan();
        void setRan(long double);
        long double getLS();
        void setLS(long double);
        long double getLI();
        void setLI(long double);
    private:
        Regression reg;
        Simpson simp;

        long double sig;
        long double ran;
        long double LS;
        long double LI;
};
/*
The objective of this constructor is to
initialize a regression and simpson object
then compute the significance, range, 
upper limit and lower limit
*/
//.i
Calc::Calc(vector<long double> x, vector<long double> y, long double xk){
    long double r;
    long double yk;
    long double sig;
    long double corr;
    long double li;
    int dof;
    dof = x.size() - 2;

    Regression reg(x, y, xk);
    setRegression(reg);
    Simpson simp(dof);
    setSimpson(simp);

    r = getRegression().getR();
    yk = getRegression().getYk();
    corr = (abs(r)*sqrt(dof))/sqrt(1 - pow(r,2));
    sig = 1 - 2*getSimpson().approximateP(corr);

    setSig(sig);
    setRan(calcRan(x,y,xk));
    setLS(yk + getRan());
    li = yk - getRan();
    if(li < 0.0L){
        li = 0.0L;
    }
    setLI(li);
}

/*
The objective of this method is to compute
the value of range
________________________________
:params: vector<long double> x
:params: vector<long double> y
_______________________________
returns: long double
*/
//.i
long double Calc::calcRan(
  vector<long double> x, vector<long double> y, long double xk){
    long double simpX;
    long double numerator;
    long double denominator=0.0L;
    long double res;
    long double xMean;
    int n = x.size();
    xMean = getRegression().getXMean();
    simpX = getSimpson().approximateX(0.35);

    numerator = pow((xk - xMean),2);
    for(int i = 0; i < n; i++){
        denominator += pow((x[i] - xMean), 2);
    }
    
    res = sqrt(1.0L + (1.0L/n) + (numerator/denominator));

    res = res * simpX * standardDeviation(x,y);
    return res;
}

/*
The objective of this method is to decouple 
the load of the calcRan() method by computing 
the standard deviation of 2 vectors
________________________________
:params: vector<long double> x
:params: vector<long double> y
_______________________________
returns: long double
*/
//.i
long double Calc::standardDeviation(
  vector<long double> x, vector<long double> y){
    long double res=0.0L;
    long double b0;
    long double b1;
    int n = y.size();
    b0 = getRegression().getB0();
    b1 = getRegression().getB1();

    for(int i = 0; i < n; i++){
        res += pow((y[i] -b0-b1*x[i]), 2);
    }

    res = sqrt(res * 1.0L/(n-2));
    return res;
}

/*
The objective of this method is to send all
of the calculations to main as a vector so it 
can be printed by the IO class.
________________________________
:params: none
_______________________________
returns: vector<long double>, of size 10
*/
vector<long double> Calc::getData(){
    vector<long double> data;
    data.push_back(getRegression().getXk());
    data.push_back(getRegression().getR());
    data.push_back(getRegression().getR2());
    data.push_back(getRegression().getB0());
    data.push_back(getRegression().getB1());
    data.push_back(getRegression().getYk());
    data.push_back(getSig());
    data.push_back(getRan());
    data.push_back(getLS());
    data.push_back(getLI());
    return data;
}

/*
THE REST OF THE FILE ARE GETTERS AND SETTERS
*/

//.i
Regression Calc::getRegression(){
    return reg;
}
//.i
void Calc::setRegression(Regression value){
    reg = value;
    return;
}

//.i
Simpson Calc::getSimpson(){
    return simp;
}
//.i
void Calc::setSimpson(Simpson value){
    simp = value;
    return;
}
//.i
long double Calc::getSig(){
    return sig;
}
//.i
void Calc::setSig(long double value){
    sig = value;
    return;
}

//.i
long double Calc::getRan(){
    return ran;
}
//.i
void Calc::setRan(long double value){
    ran = value;
    return;
}


//.i
long double Calc::getLS(){
    return LS;
}
//.i
void Calc::setLS(long double value){
    LS = value;
    return;
}

//.i
long double Calc::getLI(){
    return LI;
}
//.i
void Calc::setLI(long double value){
    LI = value;
    return;
}
#endif
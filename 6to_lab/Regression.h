/*
 Gerardo Galan Garzafox A00821196
 CREATED_AT  2021-03-20
 MODIFIED_AT 2021-04-22
 
 DESCRIPTION
 The objective of this class is to make a regression from an xk
 and 2 arrays x and y
*/
#include<iostream>
#include<vector>
#include<cmath> //pow, sqrt
#include<numeric> //accumulate, inner_product

using namespace std;

#ifndef Regression_h
#define Regression_h

//.i
class Regression{
    public:
    //.b=172
        Regression();
        Regression(vector<long double>, vector<long double>, int);
        
        long double getX();
        void setX(long double);
        long double getY();
        void setY(long double);
        long double getX2();
        void setX2(long double);
        long double getXY();
        void setXY(long double);
        long double getY2();
        void setY2(long double);
        long double getXMean();
        void setXMean(long double);
        long double getYMean();
        void setYMean(long double);
        
        int getN();
        void setN(int);
        long double getXk();
        void setXk(long double);
        long double getR();
        void setR(long double);
        long double calcR();
        long double getR2();
        void setR2(long double);
        long double getB0();
        void setB0(long double);
        long double getB1();
        void setB1(long double);
        long double calcB1();
        long double getYk();
        void setYk(long double);
    private:
        long double x;
        long double y;
        long double x2;
        long double XY;
        long double y2;
        long double xMean;
        long double yMean;
        
        int n;
        long double xk;
        long double r;
        long double r2;
        long double b0;
        long double b1;
        long double yk;

};


//.i
/*
Empty constructor of class regression receves 
noting and sets all varaibles to 0
*/
Regression::Regression(){
    setN(0);
    setXk(0);
    
    setX(0.0L);
    setY(0.0L);
    setX2(0.0L);
    setXY(0.0L);
    setY2(0.0L);
    setXMean(0.0L);
    setYMean(0.0L);
    
    setR(0.0L);
    setR2(0.0L);
    setB1(0.0L);
    setB0(0.0L);
    setYk(0.0L);
}


/*
Constructor of class regression it reciebes a pair of 
lists of x and y values and an xk std:accumulate just 
sums a iterable object, inner_product is used here only 
to multiply calcR and CalcB1 call methods of this 
Regression class
*/
//.i
Regression::Regression(vector<long double> x, vector<long double> y, int xk){
    setN(x.size());
    setXk(xk);
    
    setX(accumulate(x.begin(), x.end(), 0.0L));
    setY(accumulate(y.begin(), y.end(), 0.0L));
    setX2(inner_product(x.begin(), x.end(), x.begin(), 0.0L));
    setXY(inner_product(x.begin(), x.end(), y.begin(), 0.0L));
    setY2(inner_product(y.begin(), y.end(), y.begin(), 0.0L));
    setXMean(getX()/(getN()*1.0L));
    setYMean(getY()/(getN()*1.0L));
    
    setR(calcR());
    setR2(pow(getR(),2.0L));
    setB1(calcB1());
    setB0(getYMean() - (getB1() * getXMean()));
    setYk(getB0() + (getB1() * (getXk() * 1.0L)));
}

/*
calcR gets varaibles N, x, y, XY and y2 from getters
returns R that is called by the constructor inside setR
_____________________________
:params: none
_____________________________
retrun: long double
*/
//.i
long double Regression::calcR(){
    long double numerator = 0.00L;
    long double denomintor = 0.00L;
    long double x2, y2;
    x2 = pow(getX(),2.0L);
    y2 = pow(getY(),2.0L);
    
    numerator  = (getN()  * getXY()) - (getX() * getY());
    denomintor = sqrt((getN() * getX2() - x2) * (getN() * getY2() - y2));
    
    return (numerator/denomintor);
}

/*
calcB1 gets varaibles N, XY, xMean, yMean and x2 from getters
returns B1 that is called by the constructor inside setB1
____________________________
:params: none
____________________________
return: long double
*/
//.i
long double Regression::calcB1(){
    long double numerator = 0.00L;
    long double denomintor = 0.00L;
    numerator  = getXY() - (getN() * getXMean() * getYMean());
    denomintor = getX2() - (getN() * pow(getXMean(),2.0L));
    return (numerator/denomintor);
}

/*
THE REST OF THE FILE ARE GETTERS AND SETTERS
*/
//.i
long double Regression::getX(){
    return x;
}

//.i
void Regression::setX(long double value){
    x = value;
    return;
}

//.i
long double Regression::getY(){
    return y;
}

//.i
void Regression::setY(long double value){
    y = value;
    return;
}

//.i
long double Regression::getX2(){
    return x2;
}

//.i
void Regression::setX2(long double value){
    x2 = value;
    return;
}

//.i
long double Regression::getXY(){
    return XY;
}

//.i
void Regression::setXY(long double value){
    XY = value;
    return;
}

//.i
long double Regression::getY2(){
    return y2;
}

//.i
void Regression::setY2(long double value){
    y2 = value;
    return;
}

//.i
long double Regression::getXMean(){
    return xMean;
}

//.i
void Regression::setXMean(long double value){
    xMean = value;
    return;
}

//.i
long double Regression::getYMean(){
    return yMean;
}

//.i
void Regression::setYMean(long double value){
    yMean = value;
    return;
}

//.i       
int Regression::getN(){
    return n;
}

//.i
void Regression::setN(int value){
    n = value;
    return;
}

//.i
long double Regression::getXk(){
    return xk;
}

//.i
void Regression::setXk(long double value){
    xk = value;
    return;
}

//.i
long double Regression::getR(){
    return r;
}
//.i
void Regression::setR(long double value){
    r = value;
    return;
}

//.i
long double Regression::getR2(){
    return r2;
}

//.i
void Regression::setR2(long double value){
    r2 = value;
    return;
}

//.i
long double Regression::getB0(){
    return b0;
}

//.i
void Regression::setB0(long double value){
    b0 = value;
    return;
}

//.i
long double Regression::getB1(){
    return b1;
}

//.i
void Regression::setB1(long double value){
    b1 = value;
    return;
}

//.i
long double Regression::getYk(){
    return yk;
}

//.i
void Regression::setYk(long double value){
    yk = value;
    return;
}

#endif 
#include<vector>
#include<iostream>
#include<cmath> //pow, sqrt
#include<numeric> //accumulate, inner_product

using namespace std;

#ifndef Regression_h
#define Regression_h

//.i
class Regression{
    public:
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
        int getXk();
        void setXk(int);
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
        long double X;
        long double Y;
        long double X2;
        long double XY;
        long double Y2;
        long double X_mean;
        long double Y_mean;
        
        int N;
        int xk;
        long double r;
        long double r2;
        long double b0;
        long double b1;
        long double yk;

};

//.i
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

//.i
Regression::Regression(vector<long double> X, vector<long double> Y, int xk){
    setN(X.size());
    setXk(xk);
    
    setX(accumulate(X.begin(), X.end(), 0.0L));
    setY(accumulate(Y.begin(), Y.end(), 0.0L));
    setX2(inner_product(X.begin(), X.end(), X.begin(), 0.0L));
    setXY(inner_product(X.begin(), X.end(), Y.begin(), 0.0L));
    setY2(inner_product(Y.begin(), Y.end(), Y.begin(), 0.0L));
    setXMean(getX()/(getN()*1.0L));
    setYMean(getY()/(getN()*1.0L));
    

    
    setR(calcR());
    setR2(pow(getR(),2.0L));
    setB1(calcB1());
    setB0(getYMean() - (getB1() * getXMean()));
    setYk(getB0() + (getB1() * (getXk() * 1.0L)));
}

//.i
long double Regression::getX(){
    return X;
}

//.i
void Regression::setX(long double value){
    X = value;
    return;
}

//.i
long double Regression::getY(){
    return Y;
}

//.i
void Regression::setY(long double value){
    Y = value;
    return;
}

//.i
long double Regression::getX2(){
    return X2;
}

//.i
void Regression::setX2(long double value){
    X2 = value;
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
    return Y2;
}

//.i
void Regression::setY2(long double value){
    Y2 = value;
    return;
}

//.i
long double Regression::getXMean(){
    return X_mean;
}

//.i
void Regression::setXMean(long double value){
    X_mean = value;
    return;
}

//.i
long double Regression::getYMean(){
    return Y_mean;
}

//.i
void Regression::setYMean(long double value){
    Y_mean = value;
    return;
}

//.i       
int Regression::getN(){
    return N;
}

//.i
void Regression::setN(int value){
    N = value;
    return;
}

//.i
int Regression::getXk(){
    return xk;
}

//.i
void Regression::setXk(int value){
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

//.i
long double Regression::calcR(){
    long double numerator = 0.00L;
    long double denomintor = 0.00L;
    long double xpow2, ypow2;
    long double n = getN() * 1.0L;
    xpow2 = pow(getX(),2.0L);
    ypow2 = pow(getY(),2.0L);
    
    numerator  = (n  * getXY()) - (getX() * getY());
    denomintor = sqrt((n * getX2() - xpow2) * (getN() * getY2() - ypow2));
    
    return (numerator/denomintor);
}

//.i
long double Regression::calcB1(){
    long double numerator = 0.00L;
    long double denomintor = 0.00L;
    long double n = getN() * 1.0L;
    numerator  = getXY() - (n * getXMean() * getYMean());
    denomintor = getX2() - (n * pow(getXMean(),2.0L));
    return (numerator/denomintor);
}

#endif 

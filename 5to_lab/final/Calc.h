/*
 Gerardo Galan Garzafox A00821196
 CREATED_AT  2021-03-20
 MODIFIED_AT 2021-04-06
 
 DESCRIPTION
 The objective of this class is to abstract the handling of
 all the necesary calculations, approximations from the main class, 
*/
#include <iostream>
#include <math.h> //sqrt

using namespace std;

# define PI          3.141592653589793238462643383279502884L
# define E           0.00000001L//.m

#ifndef Calc_h
#define Calc_h

//.i
class Calc{
    //.b=91
    public:
        Calc(long double, int);
        
        int getDOF();
        long double getX();
        long double getP();
        void setDOF(int);
        void setX(long double);
        void setP(long double);
    private:
        long double x;
        int dof;
        long double p;
        int numSegments;
        
        long double approximate();
        long double simpson();
        long double tDistribution(long double);
        long double gamma(long double);
        
        int getNumSegments();
        void setNumSegments(int);
};

//.i
Calc::Calc(long double inP, int inDOF){//.m
    setP(inP);//.m
    setDOF(inDOF);
    setNumSegments(1000000);//.m
    setX(1.0L);//.m
    approximate();
}

//.i
/*
The objective of this method is to get an approximation 
to the X value, that will be obtained throught the simpson rule 
saved at variable curr with certain with a margin of errror expresssed 
by constant E comparing the absoulte value of prev and curr
*/
long double Calc::approximate(){
    long double curr;
    long double prev = 0.0L;
    long double diff = 0.0L;
    long double d = 0.5L;
    string direction = "";
    //.d=3
    curr = simpson();
    if (curr <= getP()){
        direction = "right";
        setX(getX() + d);
    }else{
        direction = "left";
        setX(getX() - d);
    }
    
    do{
        prev = curr;
        curr = simpson();
        diff = abs(curr - prev);//.m
        
        if(curr < getP()){
            if(direction == "left"){
                d /= 2;
            }
            direction = "right";
            setX(getX() + d);
        }
        if(curr > getP()){
            if(direction == "right"){
                d /= 2;
            }
            direction = "left";
            setX(getX() - d);
        }
        
    }while(diff > E);
    return curr;
}

/*
This method serves to get a simposon rule
approximation from 0 to x of the t distribution 
function with the current number of segments 
*/
//.i
long double Calc::simpson(){
    long double w = getX() / getNumSegments();
    long double p = w / 3.0L;
    long double temp = tDistribution(0.0L);
    
    int num = 0;
    for(int i = 1; i < (getNumSegments() - 1); i++){
        if(i%2==0){
            num = 2;
        }else{
            num = 4;
        }
        temp += num * tDistribution(i * w);
    }
    temp += tDistribution(getX());
    p *= temp;
    return p;
}


/*
 The pourpose of this function is to make 
 a Student T-Distribution, it recives a value x
 that is a small segment of the simpson rule integral
 and the degres of freedom, it makes 2 distinct calls to
 the gamma function it return a PDF of the given segment.
 */
//.i
long double Calc::tDistribution(long double x){
    long double res = 0.0L;
    long double dof = getDOF() * 1.0L;
    
    res =  gamma((dof + 1) / 2);
    res *= pow(1 + (x * x / dof), (dof + 1) / -2);
    res /= sqrt(dof * PI) * gamma(dof / 2);
    return res;
}


/*
The gama function recives a value and 
return a factorail positive number, it is 
implemented in a recursive manner.
*/
//.i
long double Calc::gamma(long double value){
    if(value == 1.0L){
        return value;
    }
    if(value == 0.5L){
        return sqrt(PI);
    }
    return ((value - 1) * gamma(value - 1));
}

//.i
int Calc::getDOF(){
    return dof;
}

//.i
long double Calc::getX(){
    return x;
}

//.i
long double Calc::getP(){
    return p;
}

//.i
void Calc::setDOF(int value){
    dof = value;
    return;
}

//.i
void Calc::setX(long double value){
    x = value;
    return;
}

//.i
void Calc::setP(long double value){
    p = value;
    return;
}

//.i
int Calc::getNumSegments(){
    return numSegments;
}

//.i
void Calc::setNumSegments(int value){
    numSegments = value;
    return;
}

#endif 

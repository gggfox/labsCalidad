/*
 Gerardo Galan Garzafox A00821196
 CREATED_AT  2021-03-20
 MODIFIED_AT 2021-04-22
 
 DESCRIPTION
 The objective of this class is to abstract the handling of
 all the necesary calculations, approximations from the main class, 
*/
#include <iostream>
#include <math.h> //sqrt

using namespace std;

# define PI          3.141592653589793238462643383279502884L
# define E           0.000000000001L

#ifndef Simpson_h
#define Simpson_h

//.i
class Simpson{
    //.b=110
    public:
        Simpson();
        Simpson(long double);
        long double getDof();
        void setDof(long double);
        long double approximateX(long double);
        long double approximateP(long double);
    private:
        int dof;
        
        long double simpsonMethod(long double,int);
        long double tDistribution(long double);
        long double gamma(long double);
        
        int getNumSegments();
        void setNumSegments(int);
};

/*
Constructor for the simpson class
it only sets the given degrees of freedom
to 0 for the simpson object
*/
//.i
Simpson::Simpson(){
    setDof(0.0L);
}

/*
Constructor for the simpson class
it only sets the given degrees of freedom
for the simpson object
*/
//.i
Simpson::Simpson(long double inDof){
    setDof(inDof);
}

/*
The objective of this method is to get an approximation 
to the X value, that will be obtained throught the simpson rule 
saved at variable curr with certain with a margin of errror expresssed 
by constant E comparing the absoulte value of prev and curr
__________________________________________
:param: long double p
__________________________________________
return: long double
*/

//.i
long double Simpson::approximateX(long double p){
    long double curr;
    long double prev = 0.0L;
    long double diff = 0.0L;
    long double d = 0.5L;
    long double x = 1.0L;
    string direction = "";
    
    int segments = pow(2,21);
    curr = simpsonMethod(x,segments);
    if(p > 0 && p < 0.5 && getDof() > 0){
        
        if (curr <= p){
            direction = "right";
            x += d;
        }else{
            direction = "left";
            x -= d;
        }
        
        do{
            prev = curr;
            curr = simpsonMethod(x,segments);
            diff = abs(curr - prev);
            if(curr < p){
                if(direction == "left"){
                    d /= 2;
                }
                direction = "right";
                x += d;
            }
            if(curr > p){
                if(direction == "right"){
                    d /= 2;
                }
                direction = "left";
                x -= d;
            }
            
        }while(diff > E);
    }else{
        cout << "error en simpson"<< endl;
    }
    return x;
}

//.i
/*
The objective of this method is to get an approximation 
of P with the simpson rule saved at variable curr with 
certain margin of errror expresssed by constant E comparing 
the absoulte value of prev minus curr
_______________________________________
:param: long double x
_______________________________________
retrun long double
*/
long double Simpson::approximateP(long double x){
    int segments = 10;
    long double curr = simpsonMethod(x,segments);
    long double prev = 0.0L;
    long double diff = 0.0L;
    
    do{
        prev = curr;
        segments *= 2;
        curr = simpsonMethod(x,segments);
        diff = abs(prev - curr);
    }while(diff > E);
    
    return curr;
}

/*
This method serves to get a simposon rule
approximation from 0 to x of the t distribution 
function with the given number of segments 
___________________________________________
:param: long double x
:param: int segments
_____________________
return long double 
*/
//.i
long double Simpson::simpsonMethod(long double x, int segments){
    long double w = x / segments;
    long double p = w / 3.0L;
    long double temp = tDistribution(0.0L);
    
    int num = 0;
    for(int i = 1; i < (segments - 1); i++){
        if(i%2==0){
            num = 2;
        }else{
            num = 4;
        }
        temp += num * tDistribution(i * w);
    }
    temp += tDistribution(x);
    p *= temp;
    return p;
}


/*
 The pourpose of this function is to make 
 a Student T-Distribution, it recives a value x
 that is a small segment of the simpson rule integral
 and the degres of freedom, it makes 2 distinct calls to
 the gamma function it return a PDF of the given segment.
 __________________________________
 :param: long double x
 __________________________________
 return: long double
 */
//.i
long double Simpson::tDistribution(long double x){
    long double res = 0.0L;
    long double dof = getDof() * 1.0L;
    
    res =  gamma((dof + 1) / 2);
    res *= pow(1 + (x * x / dof), (dof + 1) / -2);
    res /= sqrt(dof * PI) * gamma(dof / 2);
    return res;
}


/*
The gama function recives a value and 
return a factorail positive number, it is 
implemented in a recursive manner.
________________________________
:params: long double value
________________________________
return: long double (>0)
*/
//.i
long double Simpson::gamma(long double value){
    if(value == 1.0L){
        return value;
    }
    if(value == 0.5L){
        return sqrt(PI);
    }
    return ((value - 1) * gamma(value - 1));
}

/*
THE REST OF THE FILE ARE GETTERS AND SETTERS
*/

//.i
long double Simpson::getDof(){
    return dof;
}

//.i
void Simpson::setDof(long double value){
    dof = value;
    return;
}

//.i
int Simpson::getNumSegments(){
    return numSegments;
}

//.i
void Simpson::setNumSegments(int value){
    numSegments = value;
    return;
}

#endif 

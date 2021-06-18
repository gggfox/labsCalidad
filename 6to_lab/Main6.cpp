/*
 Gerardo Galan Garzafox A00821196
 CREATED_AT  2021-03-20
 MODIFIED_AT 2021-04-05
 
 DESCRIPTION
 The objective of this class is to unify 
 the abstactions of the IO class and the
 Calc class in the most simple way possible
*/

#include <iostream>

#include "IO.h"
#include "Calc.h"

using namespace std;

//.i
int main(int argc, char *argv[]){
    //.b=12
    IO io;
    if(io.read()){
        Calc calc(io.getX(), io.getY(), io.getXk());//.m
        io.print(calc.getData());//.m
    }
    //.d=2
    return 0;
}

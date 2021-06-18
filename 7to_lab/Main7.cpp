/*
 Gerardo Galan Garzafox A00821196
 CREATED_AT  2021-03-20
 MODIFIED_AT 2021-05-01
 
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
    //.b=10
    IO io;
    if(io.read()){
        Calc calc(io.getWkXkYk(), io.getWXYZ());//.m
        io.print(calc.getData());
    }
    return 0;
}

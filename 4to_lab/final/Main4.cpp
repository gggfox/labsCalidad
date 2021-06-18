/*
 Gerardo Galan Garzafox A00821196
 CREATED_AT  2021-03-20
 MODIFIED_AT 2021-03-22
 
 DESCRIPTION
 The objective of this class is to unify 
 the abstactions of the IO class and the
 Calc class in the most simple way possible
*/

#include <iostream>
#include "Calc.h"
#include "IO.h"

using namespace std;

//.i
int main(int argc, char *argv[]){
    //.b=56
    //.d=51
    IO io;//.m
    if(!io.read()){
        return 0;
    }
    Calc calc(io.getX(), io.getDOF());//.m
    io.setP(calc.getP());//.m
    io.print();//.m
    
    return 0;
}

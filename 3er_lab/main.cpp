#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <limits> //numeric_limits

#include "Regression.h"
#include "Output.h"
using namespace std;

//.d=39

int main(int argc, char *argv[]){
    //.b=134
    ifstream scanner;
    string file;//.m
    string line;
    vector<long double> X;
    vector<long double> Y;
    long double temp_x=0.0L, temp_y=0.0L;
    int xk = -1, comma=-1;
    //.d=13
    cout << "Escribe el nombre de tu archivo" << endl;
    cin >> file;
    scanner.open(file);//.m
        if(scanner.is_open() && scanner.peek() != std::ifstream::traits_type::eof()){
            while(!scanner.eof()){
                //.d=13
                getline(scanner, line);
                if(xk == -1){
                    try{
                        xk = stoi(line);
                        if(xk < 0){
                            cout << "error xk no puede ser menor a 0" << endl;
                            return 0;
                        }
                        continue;
                    }catch(exception const & e){
                        cout << "error de formato" << endl;
                        return 0;
                    }
                }else{
                    try{
                        comma = line.find(',');
                        if(comma == -1){
                            break;
                        }
                        
                        temp_x = stod(line.substr(0, comma));
                        temp_y = stod(line.substr(comma + 1, line.length()));

                        X.push_back(temp_x * 1.0L);
                        Y.push_back(temp_y * 1.0L);
                    }catch(exception const & e){
                        cout << "error de formato" << endl;
                        return 0;
                    }
                }
            }
        }else{
            cout << "El archivo no existe" << endl;//.m
            return 0;
        }
    scanner.close();
    //.d=60
    Regression reg(X, Y, xk);
    Output out(reg);
    out.print();
    //clear vectors
    X.clear();
    X.shrink_to_fit();
    Y.clear();
    Y.shrink_to_fit();
    
    
    
    
    return 0;
}

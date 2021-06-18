#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "WhiteLines.h"
#include "Comments.h"
#include "LOC.h"

using namespace std;

//.i
vector<string> getFiles(){
    vector<string> files;
    string file;
    int num;
    cout << "Escribe la cantidad de archivos a leer" <<endl;
    cin >> num;
    cout << "Escribe los nombres de tus archivos" << endl;
    for(int i = 0; i < num; i++){
        cin >> file;
        files.push_back(file);
    }
    return files;
} 

//.d=11

//.i
string printBase(LOC loc){
    string str = "";
    str += "  " + loc.getFilename() + ": " + "T=" + to_string(loc.getT()) + ", I="; 
    str += to_string(loc.getI()) + ", B=" + to_string(loc.getB()) + ", D="; 
    str += to_string(loc.getD()) + ", M=" + to_string(loc.getM()) + ", A=";
    str += to_string(loc.getA()) + string("\n");
    
    return str;
}

//.i
string printNew(LOC loc){
    string str = "";
    str += "  " + loc.getFilename() + ": " + "T=" + to_string(loc.getT()) + ", I=";
    str += to_string(loc.getI()) + string("\n");
    return str;
}

//.i
string printReused(LOC loc){
    string str = "";
    str += "   " + loc.getFilename() + ": " + "T=" + to_string(loc.getT()) + ", I=";
    str += to_string(loc.getI()) + ", B=" + to_string(loc.getB()) + string("\n");
    return str;
}

int main(int argc, char *argv[]){
    //.b=46
    ifstream scanner;
    vector<string> files;
    
    files = getFiles();
    LOC loc_list[files.size()];
    int x;
    for(int i = 0; i < files.size(); i++){
        string line;
        WhiteLines whites;
        Comments comments;
        
        scanner.open(files[i]);
        files[i].erase(files[i].find("."), files[i].length());
        loc_list[i].setFilename(files[i]);
        x = i;
        for(int j = 0; j <= i; j++){
            if(loc_list[j].getFilename() == files[i]){
                x = j;
                break;
            }
        }
        
        if(scanner.is_open()){
            while(!scanner.eof()){
                getline(scanner, line);
                if(scanner.eof() && line.length() == 0){
                 break;   
                }
                
                if(whites.isWhite(line)){//.m
                    continue;
                }
                if(loc_list[x].readLine(line)){
                    continue;
                }
                if(comments.isSingleLine(line)){//.m
                    continue;   
                }
                if(comments.isMultiline(line)){
                    while(comments.isMultiline(line)){
                    getline(scanner, line);
                    }
                    continue;
                }


                loc_list[x].setT(loc_list[x].getT() + 1);
            }
        }else{
            cout << "Uno o mas de los archivos no existen" << endl;
            return 0;
        }
        scanner.close();
    }
    
    for(int i = 0; i < files.size(); i++){
        string msg = "";
        if(loc_list[i].getB() == 0 && loc_list[i].getM() > 0){
            msg = "error no puede haber modificaciones con base vacia";
        }
        if(loc_list[i].getB() == 0 && loc_list[i].getD() > 0){
            msg = "error no puede haber lineas borradas con base vacia";
        }
        if(loc_list[i].getB() == 0 && loc_list[i].getM() == 0 && 
            loc_list[i].getD() == 0 && loc_list[i].getA() == 0){
            msg = "error no puede haber archivos vacios";
        }
        if(msg != ""){
            cout << msg << endl;
            return 0;
        }
        
    }
    
    int sum = 0;
    cout << "CLASES BASE: \n";
    for(int i = 0; i < files.size(); i++){
        if(loc_list[i].whichClass() == "base"){
            cout << printBase(loc_list[i]);
            sum += loc_list[i].getT();
        }
    }
    cout << "--------------------------------------------\n";
    cout << "CLASES NUEVAS: \n";
    for(int i = 0; i < files.size(); i++){
        if(loc_list[i].whichClass() == "new"){
            cout << printNew(loc_list[i]);
            sum += loc_list[i].getT();
        }
    }
    cout << "--------------------------------------------\n";
    cout << "CLASES REUSADAS: \n";
    for(int i = 0; i < files.size(); i++){
        if(loc_list[i].whichClass() == "reused"){
            cout << printReused(loc_list[i]);
            sum += loc_list[i].getT();
        }
    }
    cout << "--------------------------------------------\n";
    cout << "Total de LDC=";
    cout << sum;
    cout << "\n";
    
    
    
    ofstream output;
    output.open("ConteoLDC.txt");
    
    sum = 0;
    output << "CLASES BASE: \n";
    for(int i = 0; i < files.size(); i++){
        if(loc_list[i].whichClass() == "base"){
            output << printBase(loc_list[i]);
            sum += loc_list[i].getT();
        }
    }
    output << "--------------------------------------------\n";
    output << "CLASES NUEVAS: \n";
    for(int i = 0; i < files.size(); i++){
        if(loc_list[i].whichClass() == "new"){
            output << printNew(loc_list[i]);
            sum += loc_list[i].getT();
        }
    }
    output << "--------------------------------------------\n";
    output << "CLASES REUSADAS: \n";
    for(int i = 0; i < files.size(); i++){
        if(loc_list[i].whichClass() == "reused"){
            output << printReused(loc_list[i]);
            sum += loc_list[i].getT();
        }
    }
    output << "--------------------------------------------\n";
    output << "Total de LDC=";
    output << sum;
    output << "\n";
    
    output.close();
    return 0;
}

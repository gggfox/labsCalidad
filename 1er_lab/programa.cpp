#include <iostream>
#include <string>
#include <fstream>
#include "WhiteLines.h"
#include "Comments.h"

using namespace std;

string get_file(){
    string file;
    cout << "Escribe el nombre del archivo" << endl;
    cin >> file;
    cout << endl;
    return file;
} 

void print(string file, int whites, int comments, int total){
    int code = (total - whites - comments);
    code = code < 0 ? 0: code;
    cout << "Nombre del archivo: " << file << endl;
    cout << "--------------------------------------------" << endl;
    cout << "Cantidad de líneas en blanco: " << whites << endl;
    cout << "Cantidad de líneas con comentarios: " << comments << endl;
    cout << "Cantidad de líneas con código: " << code << endl;
    cout << "--------------------------------------------" << endl;
    cout << "Cantidad total de líneas:" << total <<endl;
    return;
}

int main(){
    ifstream scanner;
    string file, line;
    int total_lines=0;
    WhiteLines whites;
    Comments comments;

    file = get_file();
    scanner.open(file);

    if(scanner.is_open()){
        while(!scanner.eof()){
            getline(scanner, line);
            total_lines++;
            whites.isWhite(line);
            while(comments.isMultiline(line)){
                total_lines++;
                getline(scanner, line);
            }
            comments.isSingleLine(line);
        }
    }else{
        cout << "No existe un archivo con ese nombre" << endl;
        return 0;
    }
    
    scanner.close();
    print(file, whites.getCont(), comments.getCont(), total_lines);
    return 0;
}
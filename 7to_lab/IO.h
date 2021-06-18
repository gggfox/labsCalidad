/*
 Gerardo Galan Garzafox A00821196
 CREATED_AT  2021-03-20
 MODIFIED_AT 2021-05-01
 
 DESCRIPTION
 The objective of this class is to abstract the handling of
 inputs and outputs from the main class by asking and checking the required
 attributes in read() from the user, then send this to main class 
 and wait for it to call print() to display the expected format
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <map>

using namespace std;

#ifndef IO_h
#define IO_h

//.i
class IO{
    //.b=98
    //.d=3
    public:
        IO();
        bool read();
        void print(vector<double>);
        
        int getN();
        void setN(int);

        map<string, double> getWkXkYk();//.m
        void setWkXkYk(map<string,double>);//.m

        map<string,vector<double>> getWXYZ();//.m
        void setWXYZ(map<string,vector<double>>);//.m
    private:
        int n;
        map<string, double> mapWkXkYk;//.m
        map<string,vector<double>> mapWXYZ;//.m
};

/*
  Default constructor
*/
//.i
IO::IO(){
    setN(0);
}

/*
  This is intended as the method for reciving
  inputs from the user. It verifies the user
  input for several fail scenarios  false if 
  it catched an error and true if it didn't.
  _____________________
  :parametes: none
  _____________________
  return: bool
*/
//.i 
bool IO::read(){
    string fileName;//.m
    ifstream fileReader;
   
    cout << "dame el valor de la el nombre del archivo: " << endl;
    cin >> fileName;//.m
    fileReader.open(fileName);

    try{
        if(!fileReader.is_open()){
            cout << "Error no existe este archivo." << endl;
            throw exception();
        }

        string line;
        if(fileReader.is_open()){
            if(fileReader.peek() == std::ifstream::traits_type::eof()){
                cout << "Error el archivo está vacío." << endl;
                throw exception();
            }

            getline(fileReader, line);
            
            stringstream ss(line);
            vector<string> str;
            while(ss.good()){
                string substr;
                getline(ss,substr,',');
                str.push_back(substr);
            }
            
            map<string, double> mWkXkYk;
            mWkXkYk["wk"] = stod(str[0]);
            mWkXkYk["xk"] = stod(str[1]);
            mWkXkYk["yk"] = stod(str[2]);
            
            //.d=1
            
            if(mWkXkYk["wk"]<0 || mWkXkYk["xk"]<0 || mWkXkYk["yk"]<0){//.m
                cout << "Error el valor de wk,xk,yk no puede ser menor a 0.";
                cout << endl;//.m
                throw exception();
            }
            setWkXkYk(mWkXkYk);
            
            vector<double> w, x, y, z;
            map<string,vector<double>> mWXYZ; //.m
            int cont = 0;
            while(!fileReader.eof()) {
                str = {};
                getline(fileReader, line);
                stringstream ss(line);
                while(ss.good()){
                    string substr;
                    getline(ss,substr,',');
                    str.push_back(substr);
                }

                mWXYZ["w"].push_back(stod(str[0]));
                mWXYZ["x"].push_back(stod(str[1]));
                mWXYZ["y"].push_back(stod(str[2]));
                mWXYZ["z"].push_back(stod(str[3]));
                
                if(mWXYZ["w"][getN()]<0 || mWXYZ["x"][getN()]<0 || 
                  mWXYZ["y"][getN()]<0 || mWXYZ["z"][getN()]<0){
                    cout << "Error el valor de w,x,y,z no puede ser menor a 0";
                    cout << endl;
                    throw exception();
                }

                //.d=2
                setN(getN() + 1);
            }

            setWXYZ(mWXYZ);
            //.d=1
            fileReader.close();
        }

    }catch(const exception&){
        return false;   
    }
   
    return true;
}

/*
 This function is intended to handle
 the outputs, just prints the results
 in the specified format
 _______________________________________
 :params: data is an array that contains most of the data to be printed
 _______________________________________
 void return
*/
//.i
void IO::print(vector<double> data){
    printf("\t  N   = %d\n",     getN());
    printf("\t  wk  = %.5f\n",  data[0]);//.m
    printf("\t  xk  = %.5f\n",  data[1]);//.m
    printf("\t  yk  = %.5f\n",  data[2]);//.m
    printf("\t-----------------------\n");//.m
    printf("\t  b0  = %.5f\n",  data[3]);
    printf("\t  b1  = %.5f\n",  data[4]);
    printf("\t  b2  = %.5f\n",  data[5]);//.m
    printf("\t  b3  = %.5f\n",  data[6]);//.m
    printf("\t-----------------------\n");//.m
    printf("\t  zk  = %.5f\n",  data[7]);//.m
    return;
}
/*
THE REST OF THE FILE ARE GETTERS AND SETTERS
*/


//.i
int IO::getN(){
    return n;
}
//.i
void IO::setN(int value){
    n = value;
    return;
}

//.i
map<string,double> IO::getWkXkYk(){//.m
    return mapWkXkYk;//.m
}
//.i
void IO::setWkXkYk(map<string,double> value){//.m
    mapWkXkYk = value;//.m
    return;
}

//.i
map<string,vector<double>> IO::getWXYZ(){//.m
    return mapWXYZ;//.m
}
//.i
void IO::setWXYZ(map<string,vector<double>> value){//.m
    mapWXYZ = value;//.m
    return;
}

#endif 

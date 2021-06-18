/*
 Gerardo Galan Garzafox A00821196
 CREATED_AT  2021-03-20
 MODIFIED_AT 2021-04-22
 
 DESCRIPTION
 The objective of this class is to abstract the handling of
 inputs and outputs from the main class by asking and checking the required
 attributes in read() from the user, then send this to main class 
 and wait for it to call print() to display the expected format
*/

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

#ifndef IO_h
#define IO_h

//.i
class IO{
    //.b=72
    public:
        IO();
        bool read();
        void print(vector<long double>);
        
        int getN();//.m
        void setN(int);//.m

        long double getXk();
        void setXk(long double);

        vector<long double> getX();//.m
        void setX(vector<long double>);//.m

        vector<long double> getY();//.m
        void setY(vector<long double>);//.m
    private:
        int n;
        long double xk;
        vector<long double> x;
        vector<long double> y;//.m
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
   
    cout << "dame el valor de la el nombre del archivo: " << endl;//.m
    cin >> fileName;//.m
    fileReader.open(fileName);

    try{
        if(!fileReader.is_open()){
            cout << "Error no existe este archivo." << endl;//.m
            throw exception();
        }

        string line;
        if(fileReader.is_open()){
            if(fileReader.peek() == std::ifstream::traits_type::eof()){
                cout << "Error el archivo está vacío." << endl;
                throw exception();
            }

            getline(fileReader, line);
            setXk(stod(line));
            if(getXk() < 0){
                cout << "Error el valor de xk no puede ser menor a 0." <<endl;
                throw exception();
            }

            vector<long double> x, y;
            long double valueX, valueY;
            while(!fileReader.eof()) {
                getline(fileReader, line);

                valueX = stod(line.substr(0, line.find(',')));
                valueY = stod(line.substr(line.find(',') + 1, line.length()));

                if(valueX < 0 || valueY < 0){
                    cout << "Error el valor de x o y no puede ser menor a 0" << endl;
                    throw exception();
                }

                x.push_back(valueX);
                y.push_back(valueY);
                setN(getN() + 1);
            }

            setX(x);
            setY(y);
            fileReader.close();
        }

    }catch(const exception&){
        return false;   
    }
   
    //.d=12
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
void IO::print(vector<long double> data){
    printf("\t  N   = %d\n",     getN());//.m
    printf("\t  xk  = %.5Lf\n",  data[0]);//.m
    printf("\t  r   = %.5Lf\n",  data[1]);//.m
    printf("\t  r2  = %.5Lf\n",  data[2]);
    printf("\t  b0  = %.5Lf\n",  data[3]);
    printf("\t  b1  = %.5Lf\n",  data[4]);
    printf("\t  yk  = %.5Lf\n",  data[5]);
    printf("\t  sig = %.10Lf\n", data[6]);
    printf("\t  ran = %.5Lf\n",  data[7]);
    printf("\t  LS  = %.5Lf\n",  data[8]);
    printf("\t  LI  = %.5Lf\n",  data[9]);
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
long double IO::getXk(){
    return xk;
}
//.i
void IO::setXk(long double value){
    xk = value;
    return;
}

//.i
vector<long double> IO::getX(){
    return x;
}
//.i
void IO::setX(vector<long double> value){
    x = value;
    return;
}

//.i
vector<long double> IO::getY(){
    return y;
}
//.i
void IO::setY(vector<long double> value){
    y = value;
    return;
}

#endif 

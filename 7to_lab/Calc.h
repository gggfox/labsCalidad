/*
 Gerardo Galan Garzafox A00821196
 CREATED_AT  2021-04-21
 MODIFIED_AT 2021-05-01
 
 DESCRIPTION
    The objective of this class is to comute the 
    significance, range, Upper limit and Lower limit
    given 2 vectors and return the resuts with the getData()
    method.
*/

#include <iostream>
#include <vector>
#include<iomanip>
#include<cmath>
#include <map>
using namespace std;

#ifndef Calc_h
#define Calc_h
//.d=2"

//.i
class Calc{
     //.b=130
    public:
        Calc(map<string, double>, map<string, vector<double>>);//.m
        
        map<string,double> gaussMethod(map<string, vector<double>>);//.m
        vector<vector<double>> configMatrix(map<string, vector<double>>);//.m
        double calcZk(map<string, double>,map<string, double>);//.m
        double sumV1xV2(vector<double>, vector<double>);//.m
        vector<double> getData();

        //.d=4

        map<string, double> getWkXkYk();
        void setWkXkYk(map<string, double>);
        map<string, double> getB0123();
        void setB0123(map<string, double>);
        
        double getZk();//.m
        void setZk(double);//.m
    private:
        //.d=3
        
        map<string, double> mapWkXkYk;//.m
        map<string, double> mapB0123;//.m
        double zk;
};
/*
The objective of this constructor is to
initialize a regression and simpson object
then compute the significance, range, 
upper limit and lower limit
*/
//.i
Calc::Calc(map<string, double> mapWkXkYk, 
           map<string, vector<double>> mapWXYZ){//.m 
    //.d=19
    setB0123(gaussMethod(mapWXYZ));
    setZk(calcZk(getB0123(),mapWkXkYk));
    setWkXkYk(mapWkXkYk);
}

/*
 * The objective of this function is to obtain 
 * b0, b1, b2 and b3, by using the gaussMethod to 
 * get the diagonal of the configured matrix.
 *_________________________________________________________
 *recives map<string,vector<double>> mapWXYZ 
 * aka columns for WXYZ 
 *_________________________________________________________
 *returns map<string,double>["b0","b1","b2","b3"] 
*/
//.i
map<string, double> Calc::gaussMethod(map<string, vector<double>> mapWXYZ){
    vector<vector<double>>vB;
    vB = configMatrix(mapWXYZ);
    
    int n = vB.size();
    double temp = 0.0;
    for(int j=0; j<n; j++){
        for(int i=0; i<n; i++){
            if(i!=j){
                temp = vB[i][j] / vB[j][j];
                for(int k=0; k < n+1; k++){
                    vB[i][k] -= vB[j][k] * temp;
                }
            }
        }
    }

    map<string,double> res;
    res["b0"] = vB[0][n]/vB[0][0];
    res["b1"] = vB[1][n]/vB[1][1];
    res["b2"] = vB[2][n]/vB[2][2];
    res["b3"] = vB[3][n]/vB[3][3];
    
    return res;
}


/*The objective of this method is to arrange a given matrix 
 * in the shape we want in order to use the gauss method
 * ________________________________________________________
 *recives map<string,vector<double>> mapWXYZ 
 * aka columns for WXYZ 
 * ________________________________________________________
 * return vector<vector<double>>
 * the matrix with the valus where we want them
*/
//.i
vector<vector<double>> Calc::configMatrix(map<string,vector<double>> mapWXYZ){
    double n, w, x, y, z, w2, wx, wy, wz, x2, xy, xz, y2, yz;
    n = mapWXYZ["w"].size();
    vector<double>ones(n);
    fill(ones.begin(), ones.end(), 1);
    
    w = sumV1xV2(mapWXYZ["w"], ones);
    x = sumV1xV2(mapWXYZ["x"], ones);
    y = sumV1xV2(mapWXYZ["y"], ones);
    z = sumV1xV2(mapWXYZ["z"], ones);
    
    w2 = sumV1xV2(mapWXYZ["w"], mapWXYZ["w"]);
    wx = sumV1xV2(mapWXYZ["w"], mapWXYZ["x"]);
    wy = sumV1xV2(mapWXYZ["w"], mapWXYZ["y"]);
    wz = sumV1xV2(mapWXYZ["w"], mapWXYZ["z"]);
    
    x2 = sumV1xV2(mapWXYZ["x"], mapWXYZ["x"]);
    xy = sumV1xV2(mapWXYZ["x"], mapWXYZ["y"]);
    xz = sumV1xV2(mapWXYZ["x"], mapWXYZ["z"]);
    
    y2 = sumV1xV2(mapWXYZ["y"], mapWXYZ["y"]);
    yz = sumV1xV2(mapWXYZ["y"], mapWXYZ["z"]);
    
    vector<vector<double>> vB; 
    vB = 
    {
        {n,  w,  x,  y,  z}, 
        {w, w2, wx, wy, wz}, 
        {x, wx, x2, xy, xz}, 
        {y, wy, xy, y2, yz}
        
    };
    
    return vB;
}

/*
The objective of this method is to compute
the value of Zk
___________________________________________________________
:param: map<string, double>mapB0123 aka b0,b1,b2,b3
:param: map<string, double>mapWkXkYk aka wk, xk, yk
___________________________________________________________
returns: double zk
*/
//.i
double Calc::calcZk(map<string, double> mapB0123, 
                    map<string, double> mapWkXkYk){
    //.d=6
    long double res = 0.0;
  
    res += mapB0123["b0"];
    res += mapB0123["b1"] * mapWkXkYk["wk"];
    res += mapB0123["b2"] * mapWkXkYk["xk"];
    res += mapB0123["b3"] * mapWkXkYk["yk"];
    return res;
}

/*
The objective of this method is to return the sum of
the multiplication of elements of 2 different vectors
___________________________________________________________
:param: vector<double> v1
:param: vector<double> v2
___________________________________________________________
returns:  double
*/
//.i
double Calc::sumV1xV2(vector<double> v1, vector<double> v2){
    double res=0.0;
    //.d=5
    int n = v1.size();

    for(int i = 0; i < n; i++){
        res += v1[i] * v2[i];
    }

    return res;
}

/*
The objective of this method is to send all
of the calculations to main as a vector so it 
can be printed by the IO class.
________________________________
:params: none
_______________________________
returns: vector<double>, of size 8
*/
//.i
vector<double> Calc::getData(){//.m
    vector<double> data;//.m

    data.push_back(getWkXkYk()["wk"]);//.m
    data.push_back(getWkXkYk()["xk"]);//.m
    data.push_back(getWkXkYk()["yk"]);//.m
    data.push_back(getB0123()["b0"]);//.m
    data.push_back(getB0123()["b1"]);//.m
    data.push_back(getB0123()["b2"]);//.m
    data.push_back(getB0123()["b3"]);//.m
    data.push_back(getZk());//.m

    //.d=2
    return data;
}

/*
THE REST OF THE FILE ARE GETTERS AND SETTERS
*/

//.d=15
//.i
map<string, double> Calc::getWkXkYk(){//.m
    return mapWkXkYk;//.m
}
//.i
void Calc::setWkXkYk(map<string, double> value){//.m
    mapWkXkYk = value;//.m
    return;
}

//.i
map<string, double> Calc::getB0123(){//.m
    return mapB0123;//.m
}
//.i
void Calc::setB0123(map<string, double> value){//.m
    mapB0123 = value;
    return;
}

//.i
double Calc::getZk(){//.m
    return zk;//.m
}
//.i
void Calc::setZk(double value){//.m
    zk = value;//.m
    return;
}

#endif

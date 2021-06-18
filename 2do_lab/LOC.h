#include <string>

using namespace std;

class LOC{
    public:
        LOC();
        string whichClass();
        int getT();
        int getI();
        int getB();
        int getD();
        int getM();
        int getA();
        void setT(int);
        string getFilename();
        void setFilename(string);
        bool readLine(string);
    private:
        bool isNumber(char);
        bool isBase();
        bool isNew();
        bool isReused();
        string filename;
        int T;
        int I;
        int B;
        int D;
        int M;
        
};

//.i
LOC::LOC(){
    this->T = 0;
    this->I = 0;
    this->B = 0;
    this->D = 0;
    this->M = 0;
    this->filename = "";
}

//.i 
string LOC::whichClass(){
  if(isBase()){
    return "base";
  }
  if(isNew()){
    return "new";   
  }
  if(isReused()){
    return "reused";   
  }
  return "error";
}

//.i
bool LOC::isBase(){
  if((getB() > 0) && ((getM() > 0) || (getD() > 0) || (getA() > 0))){
    return true;
  }
  return false;
}


//.i
bool LOC::isNew(){
  if((getB() == 0) && (getM() == 0) && (getD() == 0) && (getA() > 0)){
    return true;
  }
  return false;
}

//.i
bool LOC::isReused(){
  if((getB() > 0) && (getM() == 0) && (getD() == 0) && (getA() == 0)){
    return true;
  }
  return false;
}

//.i
bool LOC::isNumber(char character){
    char numbers [10]= {'0','1','2','3','4','5','6','7','8','9'};
    for(int i = 0; i<10; i++){
        if(character == numbers[i]){
            return true;
        }
    }
    return false;
}

//.i
bool LOC::readLine(string line){
    int curr = 0;
    for(int i = 0; i < line.length(); i++){
        if(line[i]=='\"'){
            i++;
            while(line[i] != '\"'){
                i++;
            }
        }
        if(line[i]=='/' && line[i+1]=='.'){
            i+=2;
            char num[100];
            int j = 0;
            switch(line[i]){
                case 'i':
                    I++;
                    return true;
                    break;
                case 'b':
                    i+=2;
                    while(isNumber(line[i])){
                      num[j]=line[i];
                      i++;
                      j++;
                    }
                    B += atoi(num);
                    return true;
                    break;
                case 'd':
                    i+=2;
                    while(isNumber(line[i])){
                      num[j]=line[i];
                      j++;
                      i++;
                    }
                    D += atoi(num);
                    return true;
                    break;
                case 'm':
                    M++;
                    break;
            }
        }
    }
    
    return false;
}

//.i
int LOC::getT(){
    return T;
}

//.i
int LOC::getI(){
    return I;
}

//.i
int LOC::getB(){
    return B;
}

//.i
int LOC::getD(){
    return D;
}

//.i
int LOC::getM(){
    return M;
}

//.i
void LOC::setT(int num){
    T=num;
}

//.i
int LOC::getA(){
    return T-B+D;
}

string LOC::getFilename(){
    return filename;
}

void LOC::setFilename(string name){
  filename = name;   
}

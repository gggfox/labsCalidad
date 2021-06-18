#include <string>
#include <algorithm>
#include <regex>

using namespace std;

class Comments {
    //.b=30
    public:
        Comments();
        int getCont();
        bool isSingleLine(std::string);
        bool isMultiline(std::string);
    private:
        int cont;
        bool multiline;
};

//.i
Comments::Comments(){
    this->cont = 0;
    this->multiline = false;
}

//.i
int Comments::getCont(){
    return cont;
}

//.i
bool Comments::isSingleLine(string linea){
    try{
       remove(linea.begin(), linea.end(), ' ');
       remove(linea.begin(), linea.end(), '\t');
       if(linea[0] == '/' && linea[1] == '/' && linea[2] != '.'){
            return true;
        }
        return false;
    }catch(string error){
        return false;
    }
    //.d=8
}

//.i
bool Comments::isMultiline(std::string linea){
    if(linea.find("/*") != std::string::npos){
        multiline = true;
        cont++;
        return true;
    }
    if(multiline){
        cont++;
    }
    if(linea.find("*/") != std::string::npos){
        multiline = false;
    }
    return multiline;
}

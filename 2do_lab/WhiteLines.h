#include <string>

using namespace std;

class WhiteLines {
    //.b=21
    public:
        WhiteLines();
        bool isWhite(string);
        int getCont();
    private:
        int cont;
};

//.i
WhiteLines::WhiteLines(){
    this->cont = 0;
}

//.i
int WhiteLines::getCont(){
    return cont;
}

//.i
bool WhiteLines::isWhite(string line){
    //.d=1
    for(int i = 0; i < line.length(); i++){
        if(!isspace(line[i]) && line[i] != '{' && line[i] != '}'  && line[i] != ';'){//.m
            return false;//.m
        }
    }
    //.d=1
    cont++;
    return true;//.m
}


#include <string>

using namespace std;

class WhiteLines {
    public:
        WhiteLines();
        bool isWhite(string);
        int getCont();
    private:
        int cont;
};

WhiteLines::WhiteLines(){
    this->cont = 0;
}

int WhiteLines::getCont(){
    return cont;
}

bool WhiteLines::isWhite(string line){
    bool is_white = true;
    for(int i = 0; i < line.length(); i++){
        if(!isspace(line[i])){
            is_white = false;
        }
    }
    if(is_white){
        cont++;
    }
    return is_white;
}


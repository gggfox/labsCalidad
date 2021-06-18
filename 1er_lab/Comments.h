#include <string>

class Comments {
    public:
        Comments();
        int getCont();
        bool isSingleLine(std::string);
        bool isMultiline(std::string);
    private:
        int cont;
        bool multiline;
};

Comments::Comments(){
    this->cont = 0;
    this->multiline = false;
}

int Comments::getCont(){
    return cont;
}

bool Comments::isSingleLine(std::string linea){
    if(linea.find("//") != std::string::npos){
        cont++;
        return true;
    }
    return false;
}

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
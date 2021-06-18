#include <iostream>
#include <string>

int main(){
    std::string text;
    getline(std::cin, text, ",");
    std::cout << text << "\n";
    return 0;
}

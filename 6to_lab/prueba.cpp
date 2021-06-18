#include <iostream>
#include <valarray>

using namespace std;

int main(){

    valarray<int> x,y;
    x = {1,2,3,4,5};
    x+=1;
    for(int i = 0; i< x.size();i++){
        cout << x[i] << endl;
    }

    return 0;
}
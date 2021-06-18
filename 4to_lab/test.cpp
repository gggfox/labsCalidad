#include <iostream>

using namespace std;

int main(){
        long double x;
        long double val;

        cin >> x;
        val = x +1;
        bool overflow = val < x;
        cout << x << endl;
        cout << val <<endl;
        cout << overflow << endl;
        return 0;
}

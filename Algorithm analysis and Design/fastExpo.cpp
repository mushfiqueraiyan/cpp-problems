#include <iostream>
using namespace std;

long long fastPower(long long n, long long expo) {
   
    if (expo == 0) {
        return 1;
    }

    long long half = fastPower(n, expo / 2);

    if (expo % 2 == 0) {
        return half * half;
    } else {
        return n * half * half;
    }
}

int main() {
    long long n, expo;

    cout << "Enter a number: ";
    cin >> n;

    cout << "Enter exponent: ";
    cin >> expo;

    cout << n << "^" << expo << " = "
         << fastPower(n, expo) << endl;

    return 0;
}

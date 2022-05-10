#include<iostream>
#include <stack>
#include <vector>

using namespace std;

stack<int> tns;
long long int cn;
int r, n , k;

bool ipn(long long int _n) {
    if (_n == 1 || !_n) return false;
    for (long long int _i(2); _i * _i < _n + 1; _i++)
        if (!(_n % _i)) return false;
    return true;
}

int main(void) {
    cin >> n >> k;
    do tns.push(n % k);
    while (n /= k);
    while (!tns.empty()) {
        cn = 0;
        while (!tns.empty() && tns.top()) {
            cn *= 10;
            cn += tns.top(); tns.pop();
        }
        if (!tns.empty()) tns.pop();
        if (ipn(cn)) r++;
    }
    return r;
}
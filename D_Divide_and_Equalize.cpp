#include <iostream>
#include <cmath>

using namespace std;

#define f(i,j,n) for(int i=j; i<n; i++)
#define int long long

// Custom power function
double power(double base, double exponent) {
    if (exponent == 0) 
        return 1;
    else if (exponent < 0) 
        return 1 / power(base, -exponent);
    else 
        return exp(exponent * log(base));
}

bool isInteger(double num) {
    return num == floor(num);
}

void solve() {
    double n;
    cin >> n;
    double val = 1;

    f(i,0,n) {
        double num;
        cin >> num;
        num = power(num, (1.0 / n)); // Using custom power function for fractional exponentiation
        val *= num;
    }
    
    if (isInteger(val)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

signed main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

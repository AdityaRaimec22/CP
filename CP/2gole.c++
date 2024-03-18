#include <bits/stdc++.h>
#include <vector>
#include <cmath>
using namespace std;

double dist(double a, double b, double c, double d)
{
    double distance = sqrt(pow(a - b, 2) + pow(c - d, 2));
    return distance;
}

void solve()
{
    double px, py, ax, ay, bx, by;
    cin >> px >> py >> ax >> ay >> bx >> by;

    double ao = dist(ax, 0, ay, 0);
    double ap = dist(ax, px, ay, py);
    // cout << "ap is: " << ap << " " << ao << endl;   
    double bo = dist(bx, 0, by, 0);
    double bp = dist(bx, px, by, py);
    double rad = dist((double)((ax + bx) / 2), ax, ay, (double)((ay + by) / 2));
    double num = min(max(ao, ap), max(bo, bp));
    double rad2 = INT_MAX;
    bool p = false;
    bool o = false;

    if (rad > bp || rad > ap)
    {
        p = true;
    }
    if (rad > bo || rad > ao)
    {
        o = true;
    }
    if (p && o)
    {
        rad2 = rad;
    }

    cout << fixed << setprecision(7) << min(num, rad2) << endl;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }
    return 0;
}

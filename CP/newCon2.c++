#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i, j, n) for (int i = j; i < n; i++)
#define fo(i, j) for (auto i : j)
#define vec vector<int>

void solve() {
    int size;
    cin >> size;
    int arr[size];
    unordered_map<int, int> countMap;
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
        countMap[arr[i]]++;
    }
    int counter = 0;
    set<int> set1, set2;
    while (countMap[counter] >= 2) {
        set1.insert(counter);
        set2.insert(counter);
        counter++;
    }
    if (countMap[counter] > 0) {
        cout << -1 << endl;
    } else {
        int result = 0;
        for (int i = 0; i < size; i++) {
            if (set1.find(arr[i]) != set1.end()) {
                set1.erase(arr[i]);
            }
            if (set1.size() == 0) {
                result = i + 1;
                break;
            }
        }
        for (int i = result; i < size; i++) {
            if (set2.find(arr[i]) != set2.end()) {
                set2.erase(arr[i]);
            }
        }
        if (set2.size() == 0) {
            cout << 2 << endl;
            cout << 1 << " " << result << endl;
            cout << result + 1 << " " << size << endl;
        } else {
            cout << -1 << endl;
        }
    }
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
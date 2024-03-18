#include <bits/stdc++.h>
using namespace std;

// Function to swap two elements in a vector
template<typename T>
void swap(vector<T>& vec, int i, int j) {
    T temp = vec[i];
    vec[i] = vec[j];
    vec[j] = temp;
}

// Function to generate all permutations recursively
template<typename T>
int permute(vector<T>& vec, int l, int r) {
    int ans = INT_MIN;
    if (l == r) {
        // Base case: when the current permutation is complete, print it
        for(auto i: vec) {
            cout << i << " ";
        }
        cout << endl;
        int sum = 0;
        int maxi = INT_MIN;
        for (int i = 1; i <= vec.size(); i++) {
            maxi = max(maxi, vec[i]*i);
            sum += vec[i-1]*i;
        }
        cout << maxi << " " << sum << endl;
        ans = max(ans, sum - maxi);
        cout << ans << endl;
    } else {
        // Recursive case: generate permutations by fixing one element at a time
        for (int i = l; i <= r; i++) {
            swap(vec, l, i);
            permute(vec, l + 1, r);
            swap(vec, l, i); // backtrack
        }
    }
    return ans;
}

int main() {
    // Input vector
    vector<int> nums = {1, 2}; // Modify this with your desired vector

    cout << permute(nums, 0, nums.size() - 1) << endl;

    return 0;
}

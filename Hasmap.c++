#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

int maximumFrequency(vector<int> &arr, int n)
{
    unordered_map<int, int> count;

    int maxfreq = 0;
    int maxAns = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        count[arr[i]]++;
        maxfreq = max(maxfreq, count[arr[i]]);
    }

    for (int i = 0; i < arr.size(); i++)
    {
        if (maxfreq == count[arr[i]])
        {
            maxAns = arr[i];
            break;
        }
    }

    return maxAns;
    
}

int main()
{
    unordered_map<string, int> m;

    m["rai"] = 1;

    cout << m["salman"] << endl;
    cout << m["rai"] << endl;
    cout << m["adi"] <<" " <<m["adhira"] << endl;
    cout << m.size() << endl;

    return 0;

}
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i, j, n) for (int i = j; i < n; i++)
#define fo(i, j) for (auto i : j)
#define vec vector<int>

bool customCompare(const pair<int, pair<int, int>>& a, const pair<int, pair<int, int>>& b) {
    // Compare based on the first element of the pair in descending order
    return a.first > b.first;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        int sum = 0;

        vector<pair<int, pair<int, int>>> mp;
        vector<pair<int, pair<int, int>>> ans;

        f(i, 0, 3)
        {
            f(j, 0, n)
            {
                int a;
                cin >> a;
                pair<int, int> p1 = make_pair(i, j);
                pair<int, pair<int, int>> p = make_pair(a, p1);
                mp.push_back(p);
            }
        }

        sort(mp.begin(), mp.end(), customCompare);

        fo(i, mp)
        {
            cout << "< " << i.first << " < " << i.second.first << ", " << i.second.second << "> "
                 << ">" << endl;
        }

        fo(i, mp)
        {
            if (ans.empty())
            {
                pair<int, int> p1 = make_pair(i.second.first, i.second.second);
                pair<int, pair<int, int>> p = make_pair(i.first, p1);
                sum += i.first;
                ans.push_back(p);
            }

            int count = 0;

            f(j, 0, ans.size())
            {
                if (i.second.first != ans[j].second.first && i.second.second != ans[j].second.second && count < 2)
                {
                    count++;
                }
                if (count == 2)
                {
                    break;
                }
            }

            if (count == ans.size())
            {
                pair<int, int> p1 = make_pair(i.second.first, i.second.second);
                pair<int, pair<int, int>> p = make_pair(i.first, p1);
                sum += i.first;
                ans.push_back(p);
            }
            if (ans.size() == 3)
            {
                break;
            }
        }

        cout << sum << endl;
    }

    return 0;
}
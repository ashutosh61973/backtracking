#include "bits/stdc++.h"
using namespace std;
#define ll long long
map<string, int> mp;
vector<string> words;
int cnt = 0;
void display()
{
    cout << "(";
    for (auto x : words)
    {
        cout << x;
    }
    cout << ")";
}
void wordbreak(int i, string &str, int n)
{
    if (i == (n))
    {
        display();
        cout << " ";
        cnt++;
        return;
    }
    if (i > n)
    {
        return;
    }
    for (int j = i; j < n; j++)
    {
        if (mp.count(str.substr(i, j + 1)))
        {
            words.push_back(str.substr(i, j + 1) + " ");
            wordbreak(j + 1, str, n);
            words.pop_back();
        }
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {

        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            mp[s] = 1;
        }
        string str;
        cin >> str;
        int len = str.length();
        wordbreak(0, str, len);
        if (cnt == 0)
            cout << "no way to break the string " << endl;
        //  cout << cnt << endl;
        cnt = 0;
        cout << endl;
        mp.clear();
    }
}

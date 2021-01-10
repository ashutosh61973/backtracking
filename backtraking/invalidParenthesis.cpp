#include "bits/stdc++.h"

using namespace std;
#define inti long long
#define ll long long
vector<char> v;
int cnt = 0;
int mini = 1000;
bool check(int left, int right, int remove_cnt)
{
    if (left != right)
        return false;
    else
    {
        if (remove_cnt <= mini)
        {
            mini = remove_cnt;
            return true;
        }
        else
        {
            return false;
        }
    }
}
void display()
{
    for (auto x : v)
    {
        cout << x;
    }
}
void RIP(int i, int left, int right, int remove_cnt, string &s, int n)
{
    if (i >= n)
    {

        if (check(left, right, remove_cnt))
        {

            cnt++;
            cout << cnt << ".";
            cout << "[";
            display();
            cout << ']';
            cout << " ";
            cout << endl;
        }
        return;
    }

    char c = (char)s[i];

    if ((c != '(') && (c != ')'))
    {
        v.push_back(c);
        RIP(i + 1, left, right, remove_cnt, s, n);
        v.pop_back(); //back to initial state
    }
    if (c == '(')
    {
        v.push_back(c);
        RIP(i + 1, left + 1, right, remove_cnt, s, n);
        v.pop_back(); //back to initial state
        RIP(i + 1, left, right, remove_cnt + 1, s, n);
    }
    if (c == ')')
    {
        //this is the pruning step in backtracking i.e eleminating some calls
        //in recursion
        if (right < left)
        {
            v.push_back(c);
            RIP(i + 1, left, right + 1, remove_cnt, s, n);
            v.pop_back(); //back to initial state
            RIP(i + 1, left, right, remove_cnt + 1, s, n);
        }
    }

    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // RIP-> remove invalid parenthesis(fullform).
    string str;
    cin >> str;
    int left = 0, right = 0;
    int i = 0;
    int remove_cnt = 0;
    int len = str.length();
    //cout << "[";
    RIP(i, left, right, remove_cnt, str, len);
    //cout << "]";
    cout << endl;
}

#include "bits/stdc++.h"

using namespace std;
#define inti long long
#define ll long long
const long long INF = 1e18;
const int32_t M = 1e9 + 7;
const int32_t mod = 1e9 + 7;
const int32_t MM = 998244353;

bool prime[100000]; //primes under 10^5
//////////////////////////////////seive for prime/////////////////////////////
/*
void primes() 
{ 
  int n=100000;
    for (int p=2; p*p<=n; p++) 
    { 
        if (prime[p] == true) 
        { 
            for (int i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
  
        // Print all prime numbers 
           // for (int p=2; p<=n; p++) 
        // if (prime[p]) 
         // cout << p << " "; 
} 
*/
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////NCR////////////////////////////////////////
/*const int N=5000;
 
#define NCR
#define PRIME	M
inti pw(inti a,inti p=M-2,inti MOD=M){
    inti result = 1;
    while (p > 0) {
        if (p & 1)
            result = a * result % MOD;
        a = a * a % MOD;
        p >>= 1;
    }
    return result;
}
inti fact[N],invfact[N];
void init(){
    inti p=PRIME;
    fact[0]=1;
    inti i;
    for(i=1;i<N;i++){
        fact[i]=i*fact[i-1]%p;
    }
    i--;
    invfact[i]=pw(fact[i],p-2,p);
    for(i--;i>=0;i--){
        invfact[i]=invfact[i+1]*(i+1)%p;
    }
}
inti ncr(inti n,inti r){
    if(r > n || n < 0 || r < 0)return 0;
    return fact[n]*invfact[r]%PRIME*invfact[n-r]%PRIME;
}*/
///////////////////////////////////////////////////////////////////////////////

////\\//////\\/////////\\///////////\\\////////\\/////////////\\\/////
/*
ll power(ll a, ll b) //time complexity is  o(log(b));
{
  if (a == 0)
    return 0;
  ll ans = 1;
  a = a % mod;
  while (b > 0)
  {
    if ((b & 1) == 1)
      ans = (ans * a) % mod;
    b = b >> 1;
    a = (a * a) % mod;
  }
  return ans;
}*/
//\\////\\//////\\//////\//////\\///////\\//////////\\/////\\///
/*bool isPrime(int n) {
 
  if (n == 1) {
    return false;
  }
 
  for (int i = 2; i*i <= n; i++) {
    if (n % i == 0) return false;
  }
 
  return true;
}*/
//////////////\\\\\\\\////////\\\\\\\\\\//////////\\\\////

///////////////////////////////////////////////////////////////////////

/*
//sort string by there length ==>

sort(v.begin(), v.end(), [&] (const string &s, const string &t) {
        return s.size() < t.size();
    });
*/

///////////////////////////////////////////////////////////////////////
int cnt = 0;
bool check(vector<vector<int>> &graph, vector<int> &col, int c, int node)
{
    if (col[node] != 0)
        return false;
    for (auto x : graph[node])
    {
        if (col[x] == c)
        {
            return false;
        }
    }
    return true;
}
bool correct_col(vector<vector<int>> &graph, int n, vector<int> &visited, vector<int> &col)
{
    for (int i = 1; i <= n; i++)
    {
        for (auto x : graph[i])
        {
            if (col[x] == col[i])
            {
                return false;
            }
        }
    }
    return true;
}
void display(vector<int> col, int n)
{
    cout << "(";
    for (int i = 1; i <= n; i++)
    {
        if (i == n)
        {
            cout << col[i];
            continue;
        }
        cout << col[i] << ",";
    }
    cout << ')';
}
void mcolor(int node, int n, int m, vector<vector<int>> &graph, vector<int> &visited, vector<int> &col)
{

    if (node == (n + 1))
    {
        cnt++;
        display(col, n);
        cout << endl;
        return;
    }

    for (int i = 1; i <= m; i++)
    {
        if (check(graph, col, i, node))
        {
            col[node] = i;
            mcolor(node + 1, n, m, graph, visited, col);
            col[node] = 0;
        }
    }

    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // memset(prime, true, sizeof(prime));
    //primes(); // primes under 1lakh

    /*
  #ifdef NCR
        init();
    #endif
*/
    int n;
    int m;
    int e;
    cin >> n >> m >> e;
    vector<vector<int>> graph(n + 1);
    vector<int> visited(n + 1, 0);
    for (int i = 1; i <= e; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    vector<int> col(n + 1, 0);
    mcolor(1, n, m, graph, visited, col);
    cout << "total number of ways to colr the graph with no two adjacent node have same color=>";
    cout << cnt << endl;
}

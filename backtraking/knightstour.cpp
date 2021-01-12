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
int x_dir[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int y_dir[8] = {1, 2, 2, 1, -1, -2, -2, -1};

void display(vector<vector<int>> &grid, int n)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cout << " " << grid[i][j] << "  ";
    }
    cout << endl;
  }
  return;
}
bool is_safe(int x, int y, vector<vector<int>> &grid, int n)
{
  return (x < n) and (x >= 0) and (y < n) and (y >= 0) and (grid[x][y] == -1);
}
bool knightTour(int x, int y, int movei, vector<vector<int>> &grid, int n)
{
  if (movei == (n * n))
  {
    display(grid, n);
    cout << endl;
    return true;
  }
  for (int k = 0; k < 8; k++)
  {

    if (is_safe(x + x_dir[k], y + y_dir[k], grid, n))
    {
      grid[x + x_dir[k]][y + y_dir[k]] = movei;
      if (knightTour(x + x_dir[k], y + y_dir[k], movei + 1, grid, n) == true)
        return 1;
      else
      {
        grid[x + x_dir[k]][y + y_dir[k]] = -1;
      }
    }
  }
  return false;
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
  cin >> n;
  vector<vector<int>> grid(n, vector<int>(n, -1));
  grid[0][0] = 0;
  knightTour(0, 0, 1, grid, n);
}

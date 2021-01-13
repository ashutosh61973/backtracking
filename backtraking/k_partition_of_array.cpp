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
void display(vector<int> &arr, vector<vector<int>> &part, int k)
{
    for (int i = 0; i < k; i++)
    {
        cout << "[";
        int size = part[i].size();
        int j;
        for (j = 0; j <= size - 2; j++)
        {
            cout << part[i][j] << ',';
        }
        cout << part[i][j];
        cout << "]";
    }

    cout << endl;
}
void k_partition(int i, vector<int> &arr, vector<vector<int>> &part, int non_empty_subset_so_far, int n, int k)
{
    if (i >= n)
    {
        if (non_empty_subset_so_far == k) //to element non empty subset
        {
            display(arr, part, k);
        }
        return;
    }
    for (int j = 0; j < k; j++)
    {
        if (part[j].size() > 0)
        {
            part[j].push_back(arr[i]);
            k_partition(i + 1, arr, part, non_empty_subset_so_far, n, k);
            part[j].pop_back();
        }
        else
        {
            part[j].push_back(arr[i]);
            k_partition(i + 1, arr, part, non_empty_subset_so_far + 1, n, k);
            part[j].pop_back();
            break; //to stop permutation;
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
    int k;
    cin >> n >> k;
    vector<int> arr(n);
    vector<vector<int>> part(k);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    k_partition(0, arr, part, 0, n, k);
}

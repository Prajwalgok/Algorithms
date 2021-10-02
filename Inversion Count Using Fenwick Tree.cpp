#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const ll N = 2000000;
ll BIT[N+5],A[N+5];
ll n;
// Fenwick Tree 
// Update Query Complexity : O(log(n))
// Range  Query Complexity : O(log(n))
// Inversion count complexity  : O(log(n))
// Space  Complexity       : O(n)
//Incrementing the value at index x by val
void update(ll x,ll val)
{
      while(x<=N)
      {
         BIT[x]+=val;
         x += (x & (-x));
      }
}
// Gives The Prefix sum upto index x
ll query(ll x)
{
     ll sum = 0;
     while(x>0)
     {
        sum += BIT[x];
        x -= (x & (-x));
     }
     return sum;
}

// Constraint : 0 <= A[i] <= 2000000
// if value of A[i] is large (or negative)  like -1e18 <=  A[i] <= 1e18 We can Use Coordinate Compression  
int main()
{
    cin>>n;
    for(ll i=0;i<=N;i++) BIT[i]=0;
    ll inv_count=0;
    ll pref_greater[n+1];
    ll z;
    for(ll i=1;i<=n;i++)
    {
         cin>>A[i];
         update(A[i],1);
         // First i elements of the Array Have been Iterated so far
         // query (A[i]) gives number of elements <= A[i] in Prefix i
         // z = i - query(A[i]) gives number of elements > A[i] in Prefix i
         // z is contribution if A[i] to inversion count
         z=i-query(A[i]);
         pref_greater[i]=z;
         inv_count += z;
    }  
    for(ll i=1;i<n;i++) cout<<pref_greater[i]<<' ';
    cout<<"\n"<<inv_count;
}
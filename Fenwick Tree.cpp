#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const ll N = 2000000;
ll BIT[N+5],A[N+5];
ll n;
// Fenwick Tree 
// Update Query Complexity : O(log(n))
// Range  Query Complexity : O(log(n))
// Space  Complexity       : O(n)
//Incrementing the value at index x by val
void update(ll x,ll val)
{
      while(x<=n)
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
int main()
{
    cin>>n;
    for(ll i=0;i<=n;i++) BIT[i]=0;
    for(ll i=1;i<=n;i++)
    {
        cin>>A[i];
        update(i,A[i]);
    }
    ll query_count;
    cin>>query_count;
    while(query_count--)
    {
        ll type;
        cin>>type;
        if(type==1)
        {
            ll ind , val;
            cin>>ind>>val;
            // We have to Update  A[ind] to val
            ll diff=val-A[ind];
            A[ind]=val;
            update(ind,diff);
        }
        else
        {
            ll l , r;
            cin>>l>>r;
            // Sum Range Query 
            cout<<query(r)-query(l-1)<<"\n";
        }
    }
}
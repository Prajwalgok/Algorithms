#include <bits/stdc++.h>
using namespace std;
const int N=200004;
int   z=21;

int level[N+1];
int Parent[N+1][30];
int visited[N+1];

void dfs(int node,vector <int> v[])
{
   visited[node]=1;
   for(auto x : v[node])
   {
      if(!visited[x])
       {
	Parent[x][0]=node;
	level[x]=1+level[node];
	dfs(x,v);
       }
   }
}

// Gives Kth ancestor of node u
int ancestor(int u,int k)
{
    for(int i=z-1;i>=0;i--)
    {
    	if((1<<i)<=k)
    	{
          k-=(1<<i);
          u=Parent[u][i];
    	}
    	if(u==-1) break;
    }
    return u;
}
int lca(int u,int v)
{
    if(level[u]<level[v]) swap(u,v);

    for(int i=z-1;i>=0;i--)
    {
    	if((level[u]-(1<<i))>=level[v])
    	{
    	  u=Parent[u][i];
    	}
    }

    // Now u and v have been  brought to the same level

    if(u==v) return u;

    for(int i=z-1;i>=0;i--)
    {
    	if(Parent[u][i]!=-1 && Parent[u][i]!=Parent[v][i])
    	{
	 u=Parent[u][i];
	 v=Parent[v][i];
    	}
    }

    return Parent[u][0];
}

int dis(int u,int v)
{
    return level[u]+level[v]-2*level[lca(u,v)];
}
int main()
{
  int n;cin>>n;
  vector <int> v[n+1];
  for(int i=1;i<n;i++)
  {
  	  visited[i+1]=0;
  	  int x,y;
  	  cin>>x>>y;
  	  v[x].push_back(y);
  	  v[y].push_back(x);
  }
  // Assuming 1 as the Root Node 
  memset(Parent,-1,sizeof(Parent));
  level[1]=0;
  visited[1]=0;
  dfs(1,v);
  // 2^i th  parent of x == 2^(i-1) th parent of 2^(i-1) th parent of x
  for(int j=1;j<z;j++)
  {
      for(int i=1;i<=n;i++)
      {
          if(Parent[i][j-1]!=-1)
          {
          	 Parent[i][j]=Parent[Parent[i][j-1]][j-1];
          }
      }
  }
}

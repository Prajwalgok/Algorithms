void topo_sort(int n,vector <int> v[])
{
   vector <int> T(n);
   int p=0;
   int visited[n+1],in_deg[n+1];
   for(int i=1;i<=n;i++)
   {
   	  visited[i]=in_deg[i]=0;
   }
   for(int i=1;i<=n;i++)
   {
   	 for(auto z:v[i]) in_deg[z]++;
   }
   queue <int> q;
   for(int i=1;i<=n;i++) 
   {
   	  if(in_deg[i]==0) 
   	  	{
   	  		q.push(i);
   	  		visited[i]=1;
   	  	}
   }
   while(!q.empty())
   {
   	   int node=q.front();
   	   q.pop();
   	   T[p++]=node;
   	   for(auto z:v[node])
   	   {
   	   	  in_deg[z]--;
   	   	  if(in_deg[z]==0)
   	   	  {
   	   	  	q.push(z);
   	  		visited[z]=1;
   	   	  }
   	   } 
   }
   for(int i=0;i<n;i++) cout<<T[i]<<' ';
}
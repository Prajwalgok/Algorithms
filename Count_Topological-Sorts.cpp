// As The Number Can be Quite Large , We are Calculating it modulo 1000000007
// Expected Time Complexity : O(n+m)
// Factorials are Precalculated
long long int mod = 1e9 + 7
long long int fact[200005];
void factorial()
{
   fact[0]=1;
   for(int i=1;i<=200000;i++) fact[i]=(i*fact[i-1])%mod;
}
void count_topo(int n,int T[],vector v[])
{
   // n = number of nodes
   // T = one of The Possible Topo Sorted Array
   // v = adjacency list

   int pos[n+1];
   for(int i=0;i<n;i++) pos[T[i]]=i;
   int c=0;
   int mn=n;
   long long int count=1;
   for(int i=0;i<n;i++)
   {
   	  c++;
   	  for(auto z : v[i])
   	  {
            if(pos[z]>pos[i])
            {
              mn=min(mn,pos[z]);
            }
   	  }
   	  if(mn==(i+1))
   	  {
            count=(count*fact[c])%mod;
            c=0;
            mn=n;
        }
   }
   cout<<count;
}

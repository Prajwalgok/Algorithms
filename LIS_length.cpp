 int longestSubsequence(int n, vector <int> a)
 {
    // your code here
   vector <int> v;
   for(int i=0;i<n;i++)
   {
   	  if(i==0) v.push_back(a[i]);
   	  else
   	  {
   	  	 if(a[i]>v[v.size()-1]) v.push_back(a[i]);
   	  	 else
   	  	 {
   	  	 	int y=upper_bound(v.begin(),v.end(),a[i])-v.begin();
            v[y]=a[i];
   	  	 }
   	  }
   	  // length of LIS upto prefix i
   }
   return v.size();
 }
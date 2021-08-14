int tree[4000005];

// Time Complexity for Building The Segment Tree: O(N)
void build(int node,int start,int end)
{
	if(start==end)
	{
	   // leaf node
	   tree[node]=A[start];
	}
	else
	{
	   int mid = (start+end)/2;

	   // left Child
	   build(2*node,start,mid);

	   // right child
	   build(2*node+1,mid+1,end);

       // Internal node will have the sum of both of its children
       tree[node]=tree[2*node]+tree[2*node+1];
	}
}

//Updating the Value at idx by val
//Time Complexity : O(logN)
void update(int node, int start, int end, int idx, int val)
{
    if(start == end)
    {
        // Leaf node
        A[idx] += val;
        tree[node] += val;
    }
    else
    {
        int mid = (start + end) / 2;
        if(start <= idx and idx <= mid)
        {
            // If idx is in the left child, recurse on the left child
            update(2*node, start, mid, idx, val);
        }
        else
        {
            // if idx is in the right child, recurse on the right child
            update(2*node+1, mid+1, end, idx, val);
        }
        // Internal node will have the sum of both of its children
        tree[node] = tree[2*node] + tree[2*node+1];
    }
}

//Getting Sum of values from l to r
//Time Complexity : O(logN)
int query(int node, int start, int end, int l, int r)
{
    if(r < start or end < l)
    {
        // range represented by a node is completely outside the given range
        return 0;
    }
    if(l <= start and end <= r)
    {
        // range represented by a node is completely inside the given range
        return tree[node];
    }
    // range represented by a node is partially inside and partially outside the given range
    int mid = (start + end) / 2;
    int p1 = query(2*node, start, mid, l, r);
    int p2 = query(2*node+1, mid+1, end, l, r);
    return (p1 + p2);
}

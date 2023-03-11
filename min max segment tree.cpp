#include<bits/stdc++.h>
using namespace std;
long long min_tree[400001];
long long max_tree[400001];
long long arr[100001];
void create(int node,int s,int f)
{
    if(s==f)
    {
        max_tree[node]=arr[s-1];
        min_tree[node]=arr[s-1];
        return;
    }
    long long left=node*2;
    long long right=node*2+1;
    long long mid=(s+f)/2;
    create(left,s,mid);
    create(right,mid+1,f);
    min_tree[node]=min(min_tree[left],min_tree[right]);
    max_tree[node]=max(max_tree[left],max_tree[right]);
}
long long max_que(int node,int s,int f,int i,int j)
{
    if(i>f || j<s)
    {
        return 0;
    }
    else if(s>=i && f<=j)
    {
        return max_tree[node];
    }
    long long left=node*2;
    long long right=node*2+1;
    long long mid=(s+f)/2;
    long long p1=max_que(left,s,mid,i,j);
    long long p2=max_que(right,mid+1,f,i,j);
    return max(p1,p2);
}
long long min_que(int node,int s,int f,int i,int j)
{
    if(i>f || j<s)
    {
        return 100000001;
    }
    else if(s>=i && f<=j)
    {
        return min_tree[node];
    }
    long long left=node*2;
    long long right=node*2+1;
    long long mid=(s+f)/2;
    long long p1=min_que(left,s,mid,i,j);
    long long p2=min_que(right,mid+1,f,i,j);
    return min(p1,p2);
}
int main()
{
    ios::sync_with_stdio(0);
    long long t,k;
    cin>>t;
    for(k=1; k<=t; k++)
    {
        long long n,d,i,x,y;
        cin>>n>>d;
        for(i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        create(1,1,n);
        long long ans=0;
        for(i=1; i<=n-d+1; i++)
        {
            x=max_que(1,1,n,i,i+d-1);
            y=min_que(1,1,n,i,i+d-1);
            ans=max(ans,x-y);
        }
        cout<<"Case "<<k<<": "<<ans<<endl;
    }
}

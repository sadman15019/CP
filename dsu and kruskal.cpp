#include<bits/stdc++.h>
using namespace std;
long long parent[200005];
long long siz[200005];
void make_set(long long n)
{
    long long i;
    for(i=0; i<n; i++)
    {
        parent[i]=i;
        siz[i]=1;
    }
}
long long Find(long long x)
{
    if(parent[x]==x)
    {
        return x;
    }
    return parent[x]=Find(parent[x]);
}
void uni(long long a,long long b)
{
    a=Find(a);
    b=Find(b);
    if(a!=b)
    {
        if(siz[a]<siz[b])
        {
            swap(a,b);
        }
        parent[b]=a;
        siz[a]=+siz[b];
    }
}
struct edge
{
    long long a,b,c;
    bool operator<(edge const& other)
    {
        return c < other.c;
    }
};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    while(1)
    {
        long long n,m;
        cin>>n>>m;
        if(n==0 && m==0)
        {
            break;
        }
        else
        {
            edge sad;
            vector<edge>v;
            vector<edge>::iterator j;
            long long x,y,c,i,cost,sum=0,cou=0;
            make_set(n);
            for(i=0; i<m; i++)
            {
                cin>>x>>y>>cost;
                sad.a=x;
                sad.b=y;
                sad.c=cost;
                cou=cou+cost;
                v.push_back(sad);
            }
            sort(v.begin(),v.end());
            for(j=v.begin(); j!=v.end(); j++)
            {
                if(Find((*j).a)!=Find((*j).b))
                {
                    sum+=(*j).c;
                    uni((*j).a,(*j).b);
                }
            }
            cout<<cou-sum<<endl;
            v.clear();
        }
    }
}

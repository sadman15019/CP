#include<bits/stdc++.h>
using namespace std;
long long parent[200009];
long long siz[200009];
long long Find(long long x)
{
    if(parent[x]==x)
    {
        return x;
    }
    return parent[x]=Find(parent[x]);
}
long long uni(long long a,long long b)
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
    siz[a]+=siz[b];
    }
    return siz[a];
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    long long sad;
    cin>>sad;
    while(sad--)
    {
    map<string,long long>m;
    long long n,x=1,i,y;
    cin>>n;
    for(i=1;i<=2*n+2;i++)
    {
        parent[i]=i;
        siz[i]=1;
    }
    for(i=0; i<n; i++)
    {
        string a,b;
        cin>>a>>b;
        if(!m[a])
        {
            m[a]=x;
            x++;
        }
        if(!m[b])
        {
            m[b]=x;
            x++;
        }
        y=uni(m[a],m[b]);
        cout<<y<<endl;
        a.clear();
        b.clear();
    }
    m.clear();
    }
}




#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define sorti1 sort(v.begin(),v.end())
#define sorti2 sort(v.rbegin(),v.rend())
#define rever reverse(v.begin(),v.end())
#define ll long long
#define refi for(i=0;i<n;i++)
#define ff first
#define ss second
#define pii pair<long long,long long>
#define vp pair<pii, long long>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
/*vector<long long> b(1000009,0);//for prime check
void prime()
{
    long long y,j,i;
    long long x=sqrt(1000009);
    b[1]=1;
    for (i=3; i<=x; i=i+2)
    {
        for(j=i*i; j<=1000009; j=j+i*2)
        {
            if(b[j]==0)
            {
                b[j]=1;
            }
        }
    }
    for(i=4; i<=1000008; i+=2)
    {
        b[i]=1;
    }
}
vector<ll> prime_fac(ll n)
{
    ll i,a;
    vector<ll>factor;
    if(n%2==0)
    {
        while(n%2==0)
        {
            factor.pb(2);
            n=n/2;
        }
    }
    for(i=3; i<=sqrt(n); i++)
    {
        if(n%i==0)
        {
            while(n%i==0)
            {
                factor.pb(i);
                n=n/i;
            }
        }
    }
    if(n>2)
    {
        factor.pb(n);
    }
    return factor;
}
vector<ll> divisor(ll n)
{
    ll i,a;
    vector<ll>v;
    for(i=2; i<=sqrt(n); i++)
    {
        if(n%i==0)
        {
            v.pb(i);
            v.pb(n/i);
        }
    }
    return v;
}
ll modinverse(ll x)
{
    ll res=1;
    x=x%mod;
    ll y=mod-2;
    while(y>0)
    {
        if(y%2!=0)
        {
            res=(res*x)%mod;
        }
        y=y/2;
        x=(x*x)%mod;
    }
    return res;
}
ll ncr(int n, int k)
{
    if (k < 0 || k > n)
        return 0;
    return (arr[n] * inv[k]%mod * inv[n - k]%mod)%mod ;
}
ll bigmod(ll a,ll b)
{
    if(b==0)
       {return 1;}
    if(b==1)
        {return a%mod;}
    ll xx=cal(a,b/2);
    if(b%2==0)
        {return ((xx%mod)*(xx%mod))%mod;}
    else
        {return (((xx%mod)*(xx%mod)%mod)*(a%mod))%mod;}
}
bool cmp(const pair<ll,ll> &p, const pair<ll,ll> &q)
{
    if(p.ff!=q.ff)
    {
        return p.ff<q.ff;
    }
    else
    {
        return p.ss>q.ss;
    }
}*/
//base 9 means all the numbers can be represented only with 0..8
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    ll t ;
    cin>>t;
    while(t--)
    {
        ll n,i,a,b,ans=0,x;
        vector<pii>v;
        ordered_set s;
        cin>>n;
        refi
        {
            cin>>a>>b;
            v.pb({a,b});
        }
        sort(v.begin(),v.end());
        refi
        {
            s.insert(v[i].second);
            x=s.order_of_key(v[i].second);
            //cout<<x<<endl;
            ans+=s.size()-x-1;
        }
        cout<<ans<<endl;
    }
}
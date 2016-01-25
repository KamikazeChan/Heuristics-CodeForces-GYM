#include<bits/stdc++.h>
#define assn(n,a,b) assert(n<=b and n>=a)
#define pb push_back
#define mp make_pair
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(a) (int)(a.size())
#define SET(a,b) memset(a,b,sizeof(a))
#define LET(x,a) __typeof(a) x(a)
#define TR(v,it) for( LET(it,v.begin()) ; it != v.end() ; it++)
#define repi(i,n) for(int i=0; i<(int)n;i++)
#define sd(n) scanf("%d",&n)
#define si(n) scanf("%d",&n)
#define sl(n) scanf("%lld",&n)
#define sortv(a) sort(a.begin(),a.end())
#define all(a) a.begin(),a.end()
using namespace std;

FILE *fin = freopen("b.in","r",stdin);
FILE *fout = freopen("b.out","w",stdout);

#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
       cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
       const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector< PII > VPII;

#define MOD 1000000007ll
LL mpow(LL a, LL n) 
{LL ret=1;LL b=a;while(n) {if(n&1) 
ret=(ret*b)%MOD;b=(b*b)%MOD;n>>=1;}
return (LL)ret;}

int gcd(int a, int b){
    if(b==0)return a;
    return gcd(b, a%b);
}

int flag[1000009];
int dist[1000009];

int main()
{
    ios_base::sync_with_stdio(false);
    int x, y, gc, cnt=0;
    cin >> x >> y;
    x = x%y;
    gc = gcd(x, y);
    x /= gc;
    y /= gc;

    while(1){
        if(flag[x]){
            if(x)cout << dist[x] << " " << cnt-dist[x] << endl;
            else cout << dist[x] << " " << cnt-dist[x]-1 << endl;
            return 0;
        }
        flag[x] = 1;
        dist[x] = cnt;
        if(x < y) x *= 10;
        x = x%y;
        cnt ++;
    }
    return 0;
}



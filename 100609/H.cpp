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

#ifdef ONLINE_JUDGE
FILE *fin = freopen("high.in","r",stdin);
FILE *fout = freopen("high.out","w",stdout);
#endif

unordered_map < string, int > M[32];
string H[50009][32];
int myar[50009][32];
string str[50009];
LL ans[5];
int cnt[32];
vector< pair<int, bool> > nextm[32];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,len=5;
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> str[i];

    for(int i=0; i<(1<<len); i++)
        cnt[i]=__builtin_popcount(i);

    for(int i=0; i<(1<<len); i++){
        for(int j=0; j<n; j++){
            string s="";
            for(int k=0; k<len; k++)
                if(i&(1<<k))
                    s += str[j][k];
            M[i][s]++;
            H[j][i]=s;
        }

        VI tmp;
        int p;
        for(int k=0; k<len; k++)
            if(not (i&(1<<k)))
                tmp.pb(k);
        p=tmp.size();

        for(int k=0; k<(1<<p); k++){
            int nmask=i;
            for(int l=0; l<p; l++)
                if(k&(1<<l))
                    nmask |= (1<<tmp[l]);
            nextm[i].pb({nmask, cnt[k]%2});
        }
    }

    for(int i=0; i<(1<<len); i++)
        for(int j=0; j<n; j++)
            myar[j][i] = M[i][H[j][i]];

        // for(int i=0; i<(1<<len); i++)
   //     for(auto &c: M[i])
   //         trace(i, c.F, c.S);

    for(int i=0; i<n; i++){
        for(int j=0; j<(1<<len); j++){
            LL tot=0;

            for(auto &my: nextm[j]){
                if(my.S)
                    tot -= myar[i][my.F];
                else
                    tot += myar[i][my.F];
            }
    //        trace(i, j, tot);
            ans[cnt[j]] += tot;
        }
    }
    ans[len]-=n;
    for(int i=len; i>=0; i--) cout<<ans[i]/2<<" ";  cout<<endl;
    return 0;
}



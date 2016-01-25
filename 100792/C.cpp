// heuristics
#ifdef __APPLE__

    #include<iostream>
    #include<iomanip>
    #include<ctime>
    #include<cstdio>
    #include<vector>
    #include<algorithm>
    #include<utility>
    #include<queue>
    #include<stack>
    #include<string>
    #include<cstring>
    #include<sstream>
    #include<map>
    #include<set>
    #include<unordered_map>
    #include<unordered_set>

#else

    #include<bits/stdc++.h>

#endif  // __APPLE__

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

#define si(x) scanf("%d",&x)
#define F first
#define S second
#define PB push_back
#define MP make_pair


typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;

int f(int lx, int hx)
{
    int ret;
    while(hx>lx)
    {
        printf("%d %d\n",lx,0); cout.flush(); si(ret);
        printf("%d %d\n",hx,0); cout.flush(); si(ret);
        if(ret == 0)
        {
            hx = (lx+hx)/2;
        }
        else
        {
            lx = (1+lx+hx)/2;
        }
    }
    return lx;
}
int g(int lx, int hx)
{
    int ret;
    while(hx>lx)
    {
        printf("%d %d\n",0,lx); cout.flush(); si(ret);
        printf("%d %d\n",0,hx); cout.flush(); si(ret);
        if(ret == 0)
        {
            hx = (lx+hx)/2;
        }
        else
        {
            lx = (1+lx+hx)/2;
        }
    }
    return lx;
}
int main()
{
    int x = f(0,1000000000);
    int y = g(0,1000000000);
    cout<<"A "<<x<<" "<<y<<endl;
    return 0;	
}

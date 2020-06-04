#include<bits/stdc++.h>
using namespace std;
#define faster cin.tie(0);ios_base::sync_with_stdio(0)
#define ll long long
#define pii pair<ll,ll>
 
const int mx=1e5+10;
 
 
ll n,e,q;
vector<pii> g[mx];
 
void dijkstra(ll source,ll *dist,bool *vis,vector<pii> g[])
{
    for(int i=0;i<=n;i++)
    {
        vis[i]=false;
        dist[i]=LONG_MAX;
    }
 
    multiset<pii> s;
    s.insert({0,source});
    dist[source]=0;
 
    while(!s.empty())
     {
         pair<ll,ll> p=*s.begin();
         s.erase(s.begin());
         ll u=p.second;
         if(vis[u]) continue;
         vis[u]=1;
         for(ll i=0;i<g[u].size();i++)
         {   ll val;
             ll v=g[u][i].first;
             
             if(dist[u]%2==g[u][i].second)
             val=1;
             else
             val=2;
             if(dist[u]+val<dist[v])
              {
                  dist[v]=dist[u]+val;
                  s.insert({dist[v],v});
              }
 
         }
     }
 
}
 
 
int main()
{
    faster;
    cin>>n>>e>>q;
 
    while(e--)
    {
        ll u,v; cin>>u>>v;

        // only one graph
        g[u].push_back({v,0});
        g[v].push_back({u,1});
    }
 
    bool vis[n+1];
    ll dist[n+1];
    ll src=1;

    dijkstra(src,dist,vis,g);
  
    
    while(q--)
    {
           ll t;
           cin >>t;
           if(dist[n]<=t)
           cout <<"GGMU"<<endl;
           else cout <<"FML"<<endl;
    }
    return 0;
}

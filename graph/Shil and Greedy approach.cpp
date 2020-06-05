// learned how to invert group of bits
// simple bfs problem

#include<bits/stdc++.h>
using namespace std;
#define faster cin.tie(0);ios_base::sync_with_stdio(0)
#define ll long long
#define pii pair<int,int>

int num=0;
bool vis[1<<20];

int main()
{
    faster;
    int n; cin>>n;
    string s; cin>>s;
    memset(vis,0,sizeof(vis));

    for(int i=0;i<n;i++)
    {
        // if black the set the bit
        if(s[i]=='B') num=num^(1<<i);
    }

    queue<pii> q;

    int ans1=0;
    int ans2=(1<<n)-1;
    q.push({num,0});

    while(!q.empty())
    {
        auto curr=q.front(); q.pop();

        // if state found
        if(curr.first==ans1 || curr.first==ans2)
        {
            cout<<curr.second;
            return 0;
        }

        if(vis[curr.first]) continue;
        vis[curr.first]=1;

        int mask=curr.first;
        for(int i=0;i<=n-2;i++)
        {
            int currmask=mask ^ (1<<(i)) ^ (1<<(i+1));
            if(!vis[currmask]) q.push({currmask,curr.second+1});
        }

        for(int i=0;i<=n-3;i++)
        {
            int currmask=mask ^ (1<<(i)) ^ (1<<(i+1)) ^(1<<(i+2));
            if(!vis[currmask]) q.push({currmask,curr.second+1});
        }

    }
    return 0;
}

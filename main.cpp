//
//  main.cpp
//  nik codeforces problems
//
//  Created by PREEYADARSHEE DEV on 15/06/18.
//  Copyright © 2018 PREEYADARSHEE DEV. All rights reserved.
//
// train hard win easy :D
// by the way nik is love
// nik is motivation
// going off the grid for some time
//
//
//
#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ll long long
#define ss second
#define ff first
#define fr(i,a,b) for(ll i=a;i<b;i++)
#define f(i,n) fr(i,0,n)
#define rf(i,b,a) for(ll i=b-1;i>=a;i--)
#define r(i,n) rf(i,n,0)
#define inf 1<<30
#define eps 0.00000000000000001
#define endl '\n'
using namespace std;
vector<int>par(30111,-1);
int valid(int x,int y)
{
    if(x<=0||x>152||y<=0||y>152)
        return 0;
    return 1;
}
vector<int> prime(30111,0);
void sieve()
{
    prime[1]=1;
    for(int i=2;i<=30110;i++)
    {
        if(prime[i]==0)
        {
            for(int j=2;j*i<=30110;j++)
            {
                prime[j*i]=1;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a[152][152];
    int k=0;
    int sr=75,sc=75;
    int num=1;
    a[sr][sc]=1;
    while(k<151)
    {
        k++;
        for(int i=1;i<=k;i++)
        {
            a[sr][sc+1]=num+1;
            num++;
            sc++;
        }
        for(int i=1;i<=k;i++)
        {
            a[sr-1][sc]=num+1;
            sr--;
            num++;
        }
        k++;
        for(int i=1;i<=k;i++)
        {
            a[sr][sc-1]=num+1;
            num++;
            sc--;
        }
        for(int i=1;i<=k;i++)
        {
            a[sr+1][sc]=num+1;
            num++;
            sr++;
        }
    }
    sieve();
    vector<int>adj[30200];
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};
    for(int i=1;i<=141;i++)
    {
        for(int j=1;j<=141;j++)
        {
            int val=a[i][j];
            f(k,4)
            {
                int x=i+dx[k];
                int y=j+dy[k];
                if(valid(x,y)&&prime[a[x][y]]==1)
                {
                    adj[val].pb(a[x][y]);
                }
            }
        }
    }
    bitset<100001>vis;
    for(int i=1;i<=10000;i++)
    {
        if(vis[i]==0&&prime[i]==1)
        {
            par[i]=i;
            queue<int>q;
            q.push(i);
            vis[i]=1;
            while(!q.empty())
            {
                auto v=q.front();
                q.pop();
                for(auto j:adj[v])
                {
                    if(vis[j]==0)
                    {
                        q.push(j);
                        vis[j]=1;
                        par[j]=i;
                    }
                }
            }
        }
    }
    int t=0;
    int x,y;
    while(cin>>x>>y)
    {
        t++;
        if(par[x]!=par[y])
        {
            cout<<"Case "<<t<<": "<<"impossible"<<endl;
        }
        else
        {
            vis.reset();
            queue<pair<int,int>>q;
            q.push(mp(x,0));
            if(x==y)
            {
                cout<<"Case "<<t<<": "<<0<<endl;
            }
            else
            {
                vis[x]=1;
                int flag=0;
                while(vis[y]==0)
                {
                    auto v=q.front();
                    q.pop();
                    for(auto i:adj[v.ff])
                    {
                        if(vis[i]==0)
                        {
                            q.push(mp(i,v.ss+1));
                            vis[i]=1;
                            if(i==y)
                            {
                                cout<<"Case "<<t<<": "<<v.ss+1<<endl;
                                flag=1;
                                break;
                            }
                        }
                    }
                    if(flag==1)
                        break;
                }
            }
        }
    }
}



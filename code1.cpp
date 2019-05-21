#include<bits/stdc++.h>

using namespace std;
void solve (vector<vector<int> > A, vector<int> x1, int sy, int sx, vector<int> y1) {
    int n=A.size();
    int m=A[0].size();
    
   bool visited[n][m];
   int ans[n][m];
   for(int i=0;i<n;i++)
   {
       for(int j=0;j<m;j++)
       {
       visited[i][j]=0;
       ans[i][j]=INT_MAX;
       }
   }
   queue<pair<int,int> > q;
   ans[sx-1][sy-1]=0;
   q.push({sx-1,sy-1});
   while(!q.empty())
   {
       pair<int,int> t=q.front();
       q.pop();
       int req=A[t.first][t.second];
       int x=t.first;
       int y=t.second;
       for(int i=0;i<req;i++)
       {
           for(int j=0;j<req;j++)
           {
                if((x+i)<n&&(y+j)<m)
               {
                   if(i+j==A[x][y]&&ans[x+i][y+j]>ans[x][y]+1)
                   {
                       q.push({x+i,y+j});
                       ans[x+i][y+j]=ans[x][y]+1;
                   }
               }
               if((x+i)<n&&(y-j)>=0)
               {
                   if(i+j==A[x][y]&&ans[x+i][y-j]>ans[x][y]+1)
                   {
                       q.push({x+i,y-j});
                       ans[x+i][y-j]=ans[x][y]+1;
                   }
               }
               if((x-i)>=0&&(y+j)<m)
               {
                   if(i+j==A[x][y]&&ans[x-i][y+j]>ans[x][y]+1)
                   {
                       q.push({x-i,y+j});
                       ans[x-i][y+j]=ans[x][y]+1;
                   }
               }
                    if((x-i)>=0&&(y-j)>=0)
               {
                   if(i+j==A[x][y]&&ans[x-i][y-j]>ans[x][y]+1)
                   {
                       q.push({x-i,y-j});
                       ans[x-i][y-j]=ans[x][y]+1;
                   }
               }
               
           }
       }
   }
  
  /* for(int i=0;i<n;i++)
   {
       for(int j=0;j<m;j++)
       {
           if(ans[i][j]!=INT_MAX)
           cout<<ans[i][j]<<" ";
           else
           cout<<-1;
       }
       cout<<"\n";
   }*/

for(int i=0;i<x1.size();i++)
{
   if(ans[x1[i]-1][y1[i]-1]!=INT_MAX)
   cout<<ans[x1[i]-1][y1[i]-1];
   else
   cout<<"-1";
   cout<<"\n";
}

}

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n,m;
	    cin>>n>>m;
	    vector<vector<int> > v(n, vector<int>(m));
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<m;j++)
	        {
	            cin>>v[i][j];
	        }
	    }
	    int sx,sy;
	    cin>>sx>>sy;
	    int q;
	    cin>>q;
	    vector<int> x;
	    vector<int> y;
	    while(q--)
	    {
	        int x1,y1;
	        cin>>x1>>y1;
	        x.push_back(x1);
	        y.push_back(y1);
	    }
	    solve(v,x,sy,sx,y);
	    cout<<"\n";
	}
	return 0;
}

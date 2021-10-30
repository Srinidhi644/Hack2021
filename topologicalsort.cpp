#include<bits/stdc++.h>
using namespace std;
vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int>ans;
	  
	   vector<int>indegree(V);
	   for(int i=0;i<V;i++)
	   {
	       for(auto x:adj[i])
	       {
	           indegree[x]++;
	       }
	   }
	   queue<int>q;
	   for(int i=0;i<V;i++)
	   {
	       if(indegree[i]==0) q.push(i);
	   }
	   while(!q.empty())
	   {
	       auto node=q.front();
	       q.pop();
	        ans.push_back(node);
	       for(auto x:adj[node])
	       {
	           indegree[x]--;
	           if(indegree[x]==0)q.push(x);
	       }
	   }
	   return ans;
	}
    int main()
    {
        int t;
        cin>>t;
        while(t--)
        {
            int V,E;
            cin>>V>>E;
            vector<int>adj[V];
            for(int i=0;i<E;i++)
            {
                int u,v;
                cin>>u>>v;
                adj[u].push_back(v);
            }
        vector<int>val=topoSort(V,adj);
        for(int i=0;i<(int)val.size();i++)
        {
            cout<<val[i]<<" ";
        }
        cout<<endl;
        }
        return 0;
    }
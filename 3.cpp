//Greedy Algorithm
//Kruskal's Algorithm

#include<bits/stdc++.h>
using namespace std;
int find(int parent[],int i)
{
	if(parent[i]==-1)
		return i;
	return find(parent,parent[i]);
}
void uni(int parent[],int i,int j)
{
	int x=find(parent,i);
	int y=find(parent,j);
	parent[x]=y;
}
int main()
{
	int n,m;
	cout<<"Total number of vertices:-";
    cin>>n;
    cout<<"Total number of edges:-";
    cin>>m;
    int parent[n+1];
	for(int i=1;i<=n;i++)
	{
		parent[i]=-1;
	}
    vector<pair<int,pair<int,int> > >weight;
    cout<<"Enter edges and weight:-\n";
    for(int i=0;i<m;i++)
    {
    	int x,y,w;
    	cin>>x>>y>>w;
    	weight.push_back(make_pair(w,make_pair(x,y)));
    }
    sort(weight.begin(),weight.end());
    int sum=0;
    cout<<"Taken edges are:-\n";
	for(int i=0;i<m;i++)
	{
		int x=weight[i].second.first;
		int y=weight[i].second.second;
		int m=find(parent,x);
		int n=find(parent,y);
		if(m!=n)
		{
			uni(parent,m,n);
			sum+=(weight[i].first);
			cout<<"Edge:-"<<x<<" "<<y<<endl;
		}
	}
	cout<<"Value of minimum MST is:-"<<sum<<endl;
	return 0;
}
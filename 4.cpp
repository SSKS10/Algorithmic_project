//Topological Sort using DFS

#include<bits/stdc++.h>
using namespace std;

vector<int>a[100];
bool check[100];
int times=0;
int start[100],end[100];

void depth_f_search(int t) 
{
	//cout<<t<<" ";
    check[t]=1;
    times++;
    start[t]=times;
    for(int i=0;i<a[t].size();i++)    
    {
     	if(check[a[t][i]]==0)
        	depth_f_search(a[t][i]);
    }
    times++;
    end[t]=times;
}

int main() 
{
	int n,m;
	cout<<"Total number of vertices:-";
    cin>>n;    
    cout<<"Total number of edges:-";                   
    cin>>m;  
    cout<<"Enter edges:-\n";                     
    for(int i=0;i<m;i++) 
    {
    	int x,y;
     	cin>>x>>y;     
     	a[x].push_back(y);                                      
    }
    for(int i=0;i<100;i++)
     	check[i]=0;
 
    for(int i=1;i<=n;i++)
     {
     	if(check[i]==0)   
     	{
	        depth_f_search(i);
     	}
    }
    cout<<"Edge StartTime EndTime\n";
    vector<pair<int,int> >v;
    for(int i=1;i<=n;i++)
    {
    	v.push_back(make_pair(end[i],i));
    	cout<<i<<"\t"<<start[i]<<"\t"<<end[i]<<endl;
    }
    sort(v.begin(),v.end());
    cout<<"Topological sorting is:-\n";
    for(int i=n-1;i>=0;i--)
    {
    	cout<<v[i].second<<" ";
    }
    cout<<endl;
    return 0;
}
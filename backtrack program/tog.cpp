//dijkstras
#include<iostream>
#include<limits.h>
using namespace std;

int V=9;
int find(int dist[],bool flag[])
{
	int temp=INT_MAX;
	int index;
	for(int i=0;i<V;i++)
	{
		if(flag[i]!=1 && dist[i]<temp)
		{
			temp=dist[i],index=i;
		}
	}
	return index;
}

int d(int a[10][10],int s)
{
	int dist[V];
	for(int i=0;i<V;i++)
		dist[i]=INT_MAX;
	bool flag[V]={0};
	dist[s]=0;
	flag[0]=1;
	for(int i=0;i<V-1;i++)
	{
		int u=find(dist,flag);
		flag[u]=1;
		for(int v=0;v<10;v++)
		{
			if(a[u][v] && dist[v]>dist[u]+a[u][v] && flag[v]!=1)
				{dist[v]=dist[u]+a[u][v];}
		}
	}
	for(int i=0;i<V;i++)
		cout<<i<<" "<<dist[i]<<endl;
}

int main()
{
	int a[10][10]={{0, 4, 0, 0, 0, 0, 0, 8, 0}, 
                      {4, 0, 8, 0, 0, 0, 0, 11, 0}, 
                      {0, 8, 0, 7, 0, 4, 0, 0, 2}, 
                      {0, 0, 7, 0, 9, 14, 0, 0, 0}, 
                      {0, 0, 0, 9, 0, 10, 0, 0, 0}, 
                      {0, 0, 4, 14, 10, 0, 2, 0, 0}, 
                      {0, 0, 0, 0, 0, 2, 0, 1, 6}, 
                      {8, 11, 0, 0, 0, 0, 1, 0, 7}, 
                      {0, 0, 2, 0, 0, 0, 6, 7, 0} 
                     }; 
   d(a,0);
}

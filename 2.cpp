//Greedy Algorithm
//Optimum Merge Pattern

#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cout<<"Enter total numbers:-";
	cin>>n;
	priority_queue <int, vector<int>, greater<int> > p_queue;
	cout<<"Enter numbers in merging pattern:-\n";
	for(int i=0;i<n;i++)
	{
		int temp;
		cin>>temp;
		p_queue.push(temp);
	}
	int sum=0;
	for(int i=0;i<n-1;i++)
	{
		int a=p_queue.top();
		p_queue.pop();
		int b=p_queue.top();
		p_queue.pop();
		sum+=(a+b);
		cout<<"Merging:-"<<a<<" "<<b<<endl;
		p_queue.push(a+b);
	}
	cout<<"Moves required are:-"<<sum;
	cout<<endl;
	return 0;
}
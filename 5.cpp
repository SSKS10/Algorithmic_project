//Dynamic Programming
//Longest Common Subsequence

#include<bits/stdc++.h>
using namespace std;
char flag[100][100];
void print_sub(char a[100],int i,int j)
{
	if(i==0 || j==0)
		return;
	if(flag[i][j]=='q')
	{
		print_sub(a,i-1,j-1);
		cout<<a[i-1];
	}
	else if(flag[i][j]=='w')
		print_sub(a,i-1,j);
	else if(flag[i][j]=='a')
		print_sub(a,i,j-1);
} 
int main()
{
	int n,m; 
	char a[100],b[100];
	cout<<"Enter string1:-\n";
	cin>>a;
	cout<<"Enter string2:-\n";
	cin>>b;
	n=strlen(a);
	m=strlen(b);
	int check[n+1][m+1];
	
	for(int i=0;i<n+1;i++)
	{
		check[i][0]=0;
		flag[i][0]='0';
	}
	for(int i=1;i<m+1;i++)
	{
		check[0][i]=0;
		flag[0][i]='0';
	}
	for(int i=1;i<n+1;i++)
	{
		for(int j=1;j<m+1;j++)
		{
			if(a[i-1]==b[j-1])
			{
				check[i][j]=check[i-1][j-1]+1;
				flag[i][j]='q';
			}
			else
			{
				check[i][j]=max(check[i-1][j],check[i][j-1]);
				if(check[i-1][j]>=check[i][j-1])
				{
					flag[i][j]='w';
				}
				else
				{
					flag[i][j]='a';
				}
			}
		}
	}
	cout<<"Maximum length of common subsequence is:-"<<check[n][m]<<endl;
	cout<<"Common subsequence is:-\n";
	print_sub(a,n,m);
	cout<<endl;	
	return 0;
}
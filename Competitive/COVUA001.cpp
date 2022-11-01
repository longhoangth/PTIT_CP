#include<bits/stdc++.h>

using namespace std;

int t, n, k, x, y, a[20][20];
int l[]={-2,-2,-1,-1,1,1,2,2};
int r[]={-1,1,-2,2,-2,2,-1,1};

bool check(int x , int y , int n)
{
	if(1<=x && x<=n && 1<=y && y<=n) return true;
    return false;
}

void ktr(int x , int y , int dem)
{
	if(dem==k+1) return ;
	a[x][y]=1;
	for(int i=0 ; i<=7 ; i++)
	{
		if(check(x+l[i],y+r[i],n)==true) ktr(x+l[i],y+r[i],dem+1);
	}
}

int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n>>k>>x>>y;
		int s=0;
		for(int i=1 ; i<=n ; i++)
		{
			for(int j=1 ; j<=n ; j++)
			{
				a[i][j]=0;
			}
		}
		ktr(x,y,0);
		for(int i=1 ; i<=n ; i++)
		{
			for(int j=1 ; j<=n ; j++)
			{
				if(a[i][j]==1) s++;
			}
		}
		cout<<s<<endl;
	}
	return 0;
}
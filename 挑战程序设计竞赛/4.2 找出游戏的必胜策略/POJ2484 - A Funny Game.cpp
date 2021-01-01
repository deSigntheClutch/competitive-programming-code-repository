#include<cstdio>
int main()
{
	int n;
	while(!scanf("%d",&n))
	{
		if(n==0) break;
		else if(n==1||n==2) printf("Alice\n");
		else printf("Bob\n");
	}
	return 0;
}

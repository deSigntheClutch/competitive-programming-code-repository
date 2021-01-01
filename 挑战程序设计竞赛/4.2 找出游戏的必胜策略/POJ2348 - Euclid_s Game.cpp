#include<cstdio>

int main()
{
       long long a,b;
       while(~scanf("%lld%lld",&a,&b)){
           if(a==0&&b==0) break;
           long long temp;
           int flag=1;

           while(1){
            if(a<b) {temp=a; a=b; b=temp;}
            if (a%b==0){break;}
            if(a/b>=2){break;}
            a=a-b;
            flag=flag*(-1);
             }
       if(flag==1) printf("Stan wins\n");
       else if (flag==-1)printf("Ollie wins\n");
       }
   return 0;
}/*15 24
 3 5
 107 45
 15 89
 4 7
 1 8
 26 54
  6 4
  1564564564563 123123123156*/
/*#include <stdio.h>
int main()
{
	int a,b,t;
	while(scanf("%d%d",&a,&b)!=EOF)
	{
		if(a+b==0)break;
		if(a<b)
			a=a^b,b=a^b,a=a^b;
		t=0;
		while(a%b!=0)
		{
			if(a/b>=2)break;
			a=a-b;
			if(a<b)
			a=a^b,b=a^b,a=a^b;
			t=!t;
		}
		if(!t)
			printf("Stan wins\n");
		else
			printf("Ollie wins\n");
	}
	return 0;
}*/

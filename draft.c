#include<stdio.h>
int main()
{
	int n;
	char st[31];
	scanf("%d\n",&n); 
	for(int i=1;i<=n;i++)
	{
		scanf("%s",st);
		int j=0,k=1;
		while(st[j]!='\0')
		{
		    k++;
		    j++;
		}
		if(k<6)
		  printf("no");
		else if(k>=6)
		{
			int a=0,b=0,c=0,d=0;
			for(int i=0;i<k;i++)
			{
				if(st[i]>='a'&&st[i]<='z')
				{
					a=1;
                    goto step1;
				} 
				
                step1:
				if(st[i]>='A'&&st[i]<='Z')
				{
					b=1;
                    goto step2;
				}

				step2:
				if(st[i]>='0'&&st[i]<='9')
				{
					c=1;
                    goto step3;
				}

				step3:
				if((st[i]>='!'&&st[i]<='/')||(st[i]>=':'&&st[i]<='@')||(st[i]>='['&&st[i]<='-')||(st[i]>='{'&&st[i]<='~'))
				{
					d=1;
				}
				
			}
			if(a+b+c+d==3||a+b+c+d==4)
			printf("yes");
            else
            {
                printf("no");
            }
            
		}
	}
	return 0;
}
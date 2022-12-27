#include<stdio.h>
#include<time.h>
main()
{int a,i,n,c=0,f=0;
printf("enter number of elements\n");
scanf("%d",&n);
int l[n];
printf("enter element to find\n");
scanf("%d",&a);
for(i=0;i<n;i++)
	{printf("enter element %d:",i+1);
	scanf("%d",&l[i]);
	}
for(i=0;i<n;i++)
	{if(l[i]==a)
		{c=i;
		printf("position of element is %d\n",c+1);
		f=1;
		break;
		}
	}
if(f==0)
	{printf("element not found\n");
	}
}

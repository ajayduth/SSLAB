int lfu(int *a)
{
int *frame=(int *)malloc(f*sizeof(int *));
int fault=f;

int max=a[0];
for(int i=1;i<n;i++)
{
if(a[i]>max)
max=a[i];
}
int *frequency=(int *)malloc(max*sizeof(int *));
for(int i=0;i<max;i++)
frequency[i]=0;
printf("Frames:\n");
for(int i=0;i<n;i++)
{
if(i<f)
{
frame[i]=a[i];
frequency[(a[i]-1)]++;
for(int j=0;j<=i;j++)
printf("%d ",frame[j]);
printf("\n");
continue;
}
for(int k=0;k<f;k++)
for(int j=1;j<f-k;j++)
{
if(frequency[(frame[j-1]-1)]>frequency[(frame[j]-1)])
{
int temp=frame[j];
frame[j]=frame[j-1];
frame[j-1]=temp;
}
}
int flag=0;
for(int j=0;j<f;j++)
{
if(a[i]==frame[j])
{
flag=1;
break;
}
}
frequency[(a[i]-1)]++;
if(!flag)
{
fault++;
for(int j=0;j<f-1;j++)
{
frame[j]=frame[j+1];
}
frame[f-1]=a[i];
}
for(int j=0;j<f;j++)
printf("%d ",frame[j]);

printf("\n");
}
return fault;
}
void main()
{
printf("Enter the number of frames: ");
scanf("%d",&f);
printf("Enter the number of page requests: ");
scanf("%d",&n);
int *p=(int *)malloc(n*sizeof(int *));
printf("Enter the requested pages: \n");
for(int i=0;i<n;i++)
scanf("%d",&p[i]);
printf("Enter the choice:\n1.FIFO\n2.LRU\n3.LFU\nYour Choice:");
int c, result;
scanf("%d",&c);
switch(c)
{
case 1: result=fifo(p);
break;
case 2: result=lru(p);
break;
case 3: result=lfu(p);
break;
default: printf("Wrong choice");
}
printf("\nNumber of page faults: %d\n",result);
}

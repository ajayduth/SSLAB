#include<stdio.h>

struct memory{
int pageName;
int count;
int flag;
int time;
struct memory *next;
}*header,*ptr,*rear;

struct memory create_memory(int,int,int);

void main()
{
int no_frames, no_pages, frames[10], pages[30], time=0, fault=0;
printf("Enter number of frames:");
scanf("%d', &no_frames);
printf("Enter no of pages:");
scanf("%d",&no_pages);
printf("Enter reference string:");
for(i=0;i<no_pages;i++)
	scanf("%d",&pages[i]);
for(i=0;i<no_frames;i++)
	frames[i]=-1;

//implementing lfu
for(i=0;i<no_pages;i++)
	{
	flag1=flag2=0;
	for(j=0;j<no_frames;j++)
		{
		if(frames[j]==pages[i])
			{
			time++;
			//increment count-update time-flag to 1
			flag1=flag2=1
			break;
			}

		}
	if(flag1==0;)
	for(j=0;j<no_frames;j++)
		{
		if(frames[j==-1])
			{
			time++;
			//create new memeory- increment count -update time
			frames[j]=pages[i];
			flag2=1;
			break;
			}
		}



	}



}



struct memory create_memory(int pageName, int count, int time)
{
struct memory *node;
node=(struct memory*)malloc(sizeof(struct memory));
node->pageName=pageName;
node->count=count;
node->flag=0;
node->time=time;
if(header==NULL)
	header=rear=node;
else
	{
	rear->next=node;
	rear=node;
	}

return node;
}

struct memory search_memory(int pageName)
{
ptr=header;
while(ptr!=NULL)
	{
	if(ptr->pageName==pageName)break;
	}
return ptr;
}


struct memory find_lfu()
{
int min=header->count;
ptr=header;
while(ptr!=NULL)
	{
	if(ptr->count!=0)
		{
		if(min > ptr->count)
		min=ptr->count;
		}
	ptr=ptr->next;
	}

}

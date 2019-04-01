#include<stdio.h>
#include"sqstack.h"
//#include"Lstack.h"
#include"Sqqueue.h"
#include<vld.h>
int main()
{
	Queue qu;
	InitQueueS(&qu);
	Queue qu1;
	InitQueueS(&qu1);
	for(int i = 0;i < 10;i++)
	{
		Push(&qu,i);//0-8
	}
	Show(&qu);
	PopStack(&qu, &qu1);

	//int tmp = 0;
	//Pop(&qu,&tmp);
	//printf("%d\n",tmp);//0
	//Pop(&qu,&tmp);
	//printf("%d\n",tmp);//1
	//Pop(&qu,&tmp);
	//printf("%d\n",tmp);//2
	//Show(&qu);//3-8
	//int len = GetLength(&qu);
	//printf("%d\n",len);//8
	getchar();
	return 0;
}
#if 0
int main()
{
	Node head;
	InitStack(&head);
	Push(&head,10);
	Push(&head,20);
	Push(&head,30);
	Push(&head,40);
	int tmp = 0;
	Pop(&head,&tmp);
	printf("%d\n",tmp);//40
	Pop(&head,&tmp);
	printf("%d\n",tmp);//30
	Pop(&head,&tmp);
	printf("%d\n",tmp);//20
	Destroy(&head);
	return 0;
}

int main()
{
	Sqstack sq;
	InitStack(&sq);
	for(int i = 0;i < STACK_LEN;i++)
	{
		Push(&sq,i);//0-9
	}
	Show(&sq);
	int tmp = 0;
	Pop(&sq,&tmp);
	printf("%d\n",tmp);//9
	Pop(&sq,&tmp);
	printf("%d\n",tmp);//8
	Pop(&sq,&tmp);
	printf("%d\n",tmp);//7
	Show(&sq);//0-6
	return 0;
}
#endif
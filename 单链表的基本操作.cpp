#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

typedef int ElemType;
typedef struct Node {
	char site[256];
    ElemType fre;
    struct Node * next;
}Node;
typedef struct Node* linkList;
int initList(linkList *L)
{
    (*L) = (linkList)malloc(sizeof(Node));
    (*L)->next = NULL;
    printf("链表初始化成功\n");
    return 1;
}  //初始化链表 


int createListTail(linkList *L, int n) {
    linkList p, temp;
    temp = (*L);
    int i;
    srand((int)time(0));
    for (i = 0; i < n;i++) {
        p = (linkList)malloc(sizeof(Node));
        printf("请输入网址：\n");
        scanf("%s",&p->site);
        printf("请输入访问频率：\n");
        scanf("%d",&p->fre);
        p->next = NULL;
        temp->next = p;
        temp = p;
    }
    printf("您创建的网站如下所示：\n");
    return 1;
} //以尾插法插入数据 

int printList(linkList *L) {
    linkList p;
    int i = 0;
    p = (*L)->next;//p指向第一个节点；
    
    if (p==NULL) {
        printf("这是一个空链表.\n");
    }
    while (p) {
        i++;
        printf("%s        %d\n",p->site,p->fre);
        
        p = p->next;
    }
    return 1;
}


int insertListTail(linkList *L)
{
    linkList temp;
    linkList p=(*L);
    while(p) {
        temp = p; 
        p = p->next;
    }
    p = (linkList)malloc(sizeof(Node));
   printf("请输入新的网址：\n");
   scanf("%s",&p->site);
   printf("请输入访问频率：\n");
   scanf("%d",&p->fre); 
    
    p->next = NULL;
    temp->next = p;
    printf("------节点插入成功-------\n");
    return 1;
}
/*int deleteList(linkList *L, int i, ElemType data)
{
    linkList p,pnext;
    int j = 0;
    p = (*L);
    if (p->next == NULL) {
        printf("链表为空，无法删除指定节点.\n");
        data = -1;
        return 0;
    }
    while (p->next && j<i-1) {
        j++;
        p = p->next;
        //printf("j=%d\t p->data=%d\n",j,p->data);
    }//条件最多定位到最后一个节点；
    if ( p->next == NULL) {
        printf("您要删除的节点，超过了链表的长度 %d，请重新操作！\n", j);
        data = -1;
        return 0;
    }
    pnext = p->next;
    p->next = pnext->next;
    data = pnext->fre;
    free(pnext);
    printf("节点删除成功\n");
    return 1;
}*/
int deleteList(linkList *L, int i)
{
    linkList p,pnext;
    int j = 0;
    p = (*L);
    
    while (p->next && j<i-1) {
        j++;
        p = p->next;
        
    }
    
    pnext = p->next;
    p->next = pnext->next;
    
    free(pnext);
    printf("节点删除成功\n");
    return 1;
}


int getElem(linkList *L) {
    linkList p;
    p = (*L)->next;
    char name[256];
    printf("请输入要查找的网站：\n");
    scanf("%s",&name);
	while (p) 
		{
		if(strcmp(p->site,name) == 0){
			printf("%s存在，此网站的访问次数为%d\n",p->site,p->fre);
			p->fre += 1;
			return 0;
		}
		else{
			printf("不存在此网站！"); 
		} 
        p = p->next;
    }
    return 1;
}



int main()
{
     	
	linkList *link;
	initList(link);
    int a,b;
	printf("请输入你要创建链表的长度：\n");
	scanf("%d",&a); 
	
	createListTail(link,a);
	printList(link);
    printf("-------现在执行插入操作-------\n"); 
	insertListTail(link);
	printf("-------插入以后的链表为：-------\n"); 
	
	printList(link);
	printf("-------现在执行查询与更新操作-------\n"); 
	getElem(link);
	printf("-------查询并更新以后的链表为：-------\n");
	printList(link); 
	printf("-------现在执行删除操作-------\n");
	printf("请输入您要删除的节点位置：\n");
	scanf("%d",&b);
	deleteList(link,b);
	printf("-------删除第一个节点以后的链表为：---\n");
	printList(link);
}

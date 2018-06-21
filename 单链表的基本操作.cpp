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
    printf("�����ʼ���ɹ�\n");
    return 1;
}  //��ʼ������ 


int createListTail(linkList *L, int n) {
    linkList p, temp;
    temp = (*L);
    int i;
    srand((int)time(0));
    for (i = 0; i < n;i++) {
        p = (linkList)malloc(sizeof(Node));
        printf("��������ַ��\n");
        scanf("%s",&p->site);
        printf("���������Ƶ�ʣ�\n");
        scanf("%d",&p->fre);
        p->next = NULL;
        temp->next = p;
        temp = p;
    }
    printf("����������վ������ʾ��\n");
    return 1;
} //��β�巨�������� 

int printList(linkList *L) {
    linkList p;
    int i = 0;
    p = (*L)->next;//pָ���һ���ڵ㣻
    
    if (p==NULL) {
        printf("����һ��������.\n");
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
   printf("�������µ���ַ��\n");
   scanf("%s",&p->site);
   printf("���������Ƶ�ʣ�\n");
   scanf("%d",&p->fre); 
    
    p->next = NULL;
    temp->next = p;
    printf("------�ڵ����ɹ�-------\n");
    return 1;
}
/*int deleteList(linkList *L, int i, ElemType data)
{
    linkList p,pnext;
    int j = 0;
    p = (*L);
    if (p->next == NULL) {
        printf("����Ϊ�գ��޷�ɾ��ָ���ڵ�.\n");
        data = -1;
        return 0;
    }
    while (p->next && j<i-1) {
        j++;
        p = p->next;
        //printf("j=%d\t p->data=%d\n",j,p->data);
    }//������ඨλ�����һ���ڵ㣻
    if ( p->next == NULL) {
        printf("��Ҫɾ���Ľڵ㣬����������ĳ��� %d�������²�����\n", j);
        data = -1;
        return 0;
    }
    pnext = p->next;
    p->next = pnext->next;
    data = pnext->fre;
    free(pnext);
    printf("�ڵ�ɾ���ɹ�\n");
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
    printf("�ڵ�ɾ���ɹ�\n");
    return 1;
}


int getElem(linkList *L) {
    linkList p;
    p = (*L)->next;
    char name[256];
    printf("������Ҫ���ҵ���վ��\n");
    scanf("%s",&name);
	while (p) 
		{
		if(strcmp(p->site,name) == 0){
			printf("%s���ڣ�����վ�ķ��ʴ���Ϊ%d\n",p->site,p->fre);
			p->fre += 1;
			return 0;
		}
		else{
			printf("�����ڴ���վ��"); 
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
	printf("��������Ҫ��������ĳ��ȣ�\n");
	scanf("%d",&a); 
	
	createListTail(link,a);
	printList(link);
    printf("-------����ִ�в������-------\n"); 
	insertListTail(link);
	printf("-------�����Ժ������Ϊ��-------\n"); 
	
	printList(link);
	printf("-------����ִ�в�ѯ����²���-------\n"); 
	getElem(link);
	printf("-------��ѯ�������Ժ������Ϊ��-------\n");
	printList(link); 
	printf("-------����ִ��ɾ������-------\n");
	printf("��������Ҫɾ���Ľڵ�λ�ã�\n");
	scanf("%d",&b);
	deleteList(link,b);
	printf("-------ɾ����һ���ڵ��Ժ������Ϊ��---\n");
	printList(link);
}

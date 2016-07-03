//
//  list_t.c
//  Linked_List
//
//  Created by WZJ on 16/7/2.
//  Copyright © 2016 WZJ. All rights reserved.
//

#include "list_t.h"
#include "stdlib.h"
#include "string.h"
node_t *Initialize(char ch)
{
    node_t *head;
    head=(node_t*)calloc(1,sizeof(node_t));
    if(head==NULL){
        printf("Failed to assign memory!\n");
        exit(0);
    }
    head->next=NULL;
    head->ch=ch;
    return head;
}
void PrintList(node_t *head){
    node_t *temp=head;
    printf("***Print Linked List***\n");
    while(temp!=NULL)
    {
        printf("%c ",temp->ch);
        temp=temp->next;
    }
    printf("\n****Print Finished****\n\n");
}
void FreeList(node_t **head){
    node_t *tmp=NULL;
    node_t *pHead=*head;
    while(pHead->next!=NULL){
        tmp=pHead;
        pHead=pHead->next;
        free(tmp);
    }
    free(pHead);
}
//Students write below.



int SizeList(node_t *head)
{
    int size = 0;
    while(head != NULL)
    {
        size++;
        head = head->next;
    }
    return size;
}
bool IsEmptyList(node_t *head)
{
    if(head == NULL)
        return true;
    else return false;
}
void InsertLastList(node_t **head,char insert_char)
{
    node_t *Insert=NULL, *pHead=NULL, *Tmp=NULL;
    pHead = *head;
    Tmp = pHead;
    Insert = (node_t*)calloc(1,sizeof(node_t));
    Insert->ch = insert_char;
    Insert->next=NULL;
    while(pHead->next != NULL)
    {
        pHead = pHead->next;
    }
    pHead->next = Insert;
    *head = Tmp;
}
void InsertFirstList(node_t **head,char insert_char)
{
    node_t *Insert;
    Insert = (node_t *)calloc(1,sizeof(node_t));
    Insert-> ch = insert_char;
    Insert->next = *head;
    *head = Insert;
}
void DeleteFirstList(node_t **head){
    node_t *pHead=*head;
    if(IsEmptyList(pHead->next))
        *head=NULL;
    else{
        node_t *Tmp=pHead;
        pHead=pHead->next;
        free(Tmp);
        *head=pHead;
    }
}
void DeleteLastList(node_t **head){
    node_t *pHead=*head;
    while(pHead->next->next!=NULL)
        pHead=pHead->next;
    node_t *Tmp=pHead->next;
    free(Tmp);
    pHead->next=NULL;
}
int SearchList(node_t **head, char target){
    int cnt=0;
    node_t *pHead=*head;
    while(1){
        if(pHead->ch==target)
            cnt++;
        if(pHead->next==NULL)
            return cnt;
        else pHead=pHead->next;
    }
}
void SplitList(node_t **head, node_t **tail, int pos){
    if(pos>=SizeList(*head)){
        printf("Wrong input for position!\n");
        exit(0);
    }
    int cnt=1;
    node_t *pHead=*head;
    node_t *pTail=NULL;
    while(cnt!=pos){
        pHead=pHead->next;
        cnt++;
    }
    pTail=pHead->next;
    *tail=pTail;
    pHead->next=NULL;
}
void MergeList(node_t **head1, node_t **head2){
    node_t *pHead1=*head1;
    node_t *pHead2=*head2;
    while(pHead1->next!=NULL){
        pHead1=pHead1->next;
    }
    pHead1->next=pHead2;
}

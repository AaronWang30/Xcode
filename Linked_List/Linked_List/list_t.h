//
//  list_t.h
//  Linked_List
//
//  Created by WZJ on 16/7/2.
//  Copyright © 2016 WZJ. All rights reserved.
//

#ifndef LIST_T_H
#define LIST_T_H

#include <stdio.h>

typedef struct node{
    char ch;
    struct node *next;
}node_t;
typedef enum{false, true} bool;
node_t *Initialize(char ch);
void PrintList(node_t *head);
void FreeList(node_t **head);
//Functions below are what you are required to write.
bool IsEmptyList(node_t *head);
//Return true if the list is empty, false otherwise.
void InsertFirstList(node_t **head,char insert_char);
//Insert one node before the existed list.
void InsertLastList(node_t **head,char insert_char);
//Insert one node after the existed list.
void DeleteFirstList(node_t **head);
//Delete the first element in the list.
void DeleteLastList(node_t **head);
//Delete the last element in the list.
int SizeList(node_t *head);
//Return the size of the list
int SearchList(node_t **head, char target);
//Return the times the target is found in the list.
void SplitList(node_t **head, node_t **tail, int pos);
//Split list head into two lists head and tail.
//The first one: 0-(pos-1)
//The second one: pos-end
void MergeList(node_t **head1, node_t **head2);
//Merge two lists head1 and head2 into one list head1.

#endif /* LIST_T_H */

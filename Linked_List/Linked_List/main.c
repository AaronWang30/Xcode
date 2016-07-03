//
//  main.c
//  Linked_List
//
//  Created by WZJ on 16/7/2.
//  Copyright © 2016 WZJ. All rights reserved.
//

#include <stdio.h>
#include "list_t.h"
int main(int argc, const char * argv[]) {
    node_t *a=Initialize('1');
    node_t *b=NULL;
    PrintList(a);
    InsertFirstList(&a, 'V');
    InsertFirstList(&a, 'M');
    PrintList(a);
    InsertLastList(&a, 'C');
    PrintList(a);
    SplitList(&a, &b, 2);
    PrintList(a);
    PrintList(b);
    DeleteFirstList(&a);
    PrintList(a);
    InsertLastList(&a, 'G');
    DeleteLastList(&b);
    PrintList(b);
    InsertLastList(&b,'0');
    PrintList(b);
    InsertLastList(&b, '1');
    PrintList(b);
    MergeList(&a,&b);
    PrintList(a);
    char target='G';
    printf("Count '%c': %d\n",target, SearchList(&a,target));
    target='1';
    printf("Count '%c': %d\n",target, SearchList(&a,target));
    FreeList(&a);
    return 0;
}

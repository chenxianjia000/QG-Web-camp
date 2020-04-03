#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>
/**
 *  @name        : Status InitList(LinkList *L);
 *	@description : initialize an empty linked list with only the head node without value
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList(LinkedList *L) {
        *L = (LinkedList)malloc(sizeof(LNode));
        if(!(*L)) return ERROR;
        (*L)->next = NULL;
        return SUCCESS;
}

/**
 *  @name        : void DestroyList(LinkedList *L)
 *	@description : destroy a linked list, free all the nodes
 *	@param		 : L(the head node)
 *	@return		 : None
 *  @notice      : None
 */
void DestroyList(LinkedList *L) {
        LinkedList p;
        while(*L){
            p = (*L)->next;
            free(*L);
            *L = p;
        }
}

/**
 *  @name        : Status InsertList(LNode *p, LNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : Status
 *  @notice      : None
 */
Status InsertList(LNode *p, LNode *q) {
       if(!p) { puts("该节点不存在！"); return ERROR; }
        q->next = p->next;
        p->next = q;
        return SUCCESS;

}

/**
 *  @name        : Status DeleteList(LNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : Status
 *  @notice      : None
 */
Status DeleteList(LNode *p, ElemType *e) {
        if (!p) {puts("指定节点不存在"); return ERROR; }
        if (!(p->next)) { puts("该节点已是最后一个节点！"); return ERROR; }
        LNode *t = p->next;
        *e = t->data;
        p->next = t->next;
        free(t);
        return SUCCESS;
}

/**
 *  @name        : void TraverseList(LinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : None
 *  @notice      : None
 */
void TraverseList(LinkedList L, void (*visit)(ElemType e)) {
        while(L){
            visit(L->data);
            L = L->next;
        }
        printf("\n");
}

/**
 *  @name        : Status SearchList(LinkedList L, ElemType e)
 *	@description : find the first node in the linked list according to e
 *	@param		 : L(the head node), e
 *	@return		 : Status
 *  @notice      : None
 */
Status SearchList(LinkedList L, ElemType e) {
        while(L){
            if(L->data == e)return SUCCESS;
            L = L->next;
        }
        return ERROR;
}

/**
 *  @name        : Status ReverseList(LinkedList *L)
 *	@description : reverse the linked list
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status ReverseList(LinkedList *L) {
        if(!(*L)) return ERROR;
        LinkedList p1,p2,p3;
         p1 = *L;
         p2 = p3 = p1->next;
         p1->next = NULL;

         while(p3){
            p3 = p3->next;
            p2->next = p1;
            p1 = p2;
            p2 = p3;
         }
         *L = p1;
         return SUCCESS;
}

/**
 *  @name        : Status IsLoopList(LinkedList L)
 *	@description : judge whether the linked list is looped
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status IsLoopList(LinkedList L) {
        if(!L)return ERROR;
        LinkedList p1,p2;
        while( (!p1)&&(!p2) )
        {
            p2 = p2->next->next;
            p1 = p1->next;
            if(p1 == p2)return SUCCESS;
        }
        return ERROR;
}


/**
 *  @name        : LNode* FindMidNode(LinkedList *L)
 *	@description : find the middle node in the linked list
 *	@param		 : L(the head node)
 *	@return		 : LNode
 *  @notice      : choose to finish
 */
LNode* FindMidNode(LinkedList *L) {
        LinkedList p1,p2;
        p1 = p2 = *L;

        while(p2->next)
        {
            p2 = p2->next->next;
            p1 = p1->next;
            if(!p2)break;
        }
        return p1;
}


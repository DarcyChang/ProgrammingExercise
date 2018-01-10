/* �{���d��: Ch8-4-2.c */
#include <stdio.h>
#include <stdlib.h>
#include "Ch8-4-2.h"
/* ���: �إ߹ϧΪ���u��C */ 
void createEdge(int len, int *edge) {
  EdgeList newnode;           /* �s��u�`�I���� */
  EdgeList last;              /* �̫���u�`�I���� */
  int i;
  for (i = 0; i < len; i++) { /* �إ���u��C�D�j�� */
     /* �إ߷s��u�O���� */
     newnode = (EdgeList)malloc(sizeof(struct Edge));
     newnode->from = edge[3*i];  /* ��u���_�I */
     newnode->to = edge[3*i+1];  /* ��u�����I */
     newnode->weight = edge[3*i+2]; /* �إߦ������e */
     newnode->next = NULL;       /* �]�w���Ъ�� */
     if ( first == NULL ) {      /* ��C���Ĥ@�Ӹ`�I */
        first = newnode;         /* �إߦ�C�}�l���� */
        last = first;            /* �O�d�̫�`�I���� */
     } else {
        last->next = newnode;    /* �쵲�̫ܳ�`�I */
        last = newnode;          /* �O�d�̫�`�I���� */
     }
  }
}
/* ���: �s�W��P�@�Ӷ��X */ 
void addSet(int from, int to) {
   int to_root = to;             /* �q���I���I�� */
   while ( vertice[to_root] > 0 )
      to_root = vertice[to_root];
   vertice[to_root] = from;      /* ���X��ӳ��I */
}
/* ���: ��ӳ��I�O�_�O�P�@�Ӷ��X, �֦��P�@�Ӯڳ��I */ 
int isSameSet(int from, int to) {
   int from_root = from;         /* �q�}�l���I�� */
   int to_root = to;             /* �q���I���I�� */
   while ( vertice[from_root] > 0 ) /* ��M�ڳ��I */ 
      from_root = vertice[from_root];
   while ( vertice[to_root] > 0 )   /* ��M�ڳ��I */
      to_root = vertice[to_root];
   if ( from_root == to_root )   /* �O�_�O�P�@�ڳ��I */
         return 1;               /* �P�@���X */ 
   else  return 0;               /* ���P���X */ 
}
/* ���: �̧C�����X�i�� */ 
void minSpanTree() {
   EdgeList ptr = first;          /* ���V��C���}�l */
   int i, total = 0;
   for ( i=1; i < MAX_VERTICE;i++ )/* ��l���I�}�C */
      vertice[i] = -1;
   while ( ptr != NULL ) {
      /* �O�_�O�P�@�Ӷ��X, �ۦP�|���Ͱj�� */
      if ( !isSameSet(ptr->from,ptr->to) ) {
         /* �[�J�̧C�����X�i����u */
         printf("���I V%d -> V%d ����: %d\n",ptr->from,
                  ptr->to,ptr->weight);
         total += ptr->weight;          /* �p�⦨�� */      
         addSet(ptr->from,ptr->to);     /* �s�W�ܶ��X */
      }
      ptr = ptr->next;           /* �U�@����u */
   }
   printf("�̧C�����X�i�𪺦���: %d\n", total); 
}
/* �D�{�� */
int main() {
   int edge[8][3] = { { 1, 2, 2 }, /* ������u�}�C */
                      { 2, 4, 3 },
                      { 1, 4, 4 },
                      { 3, 5, 5 },
                      { 2, 5, 6 },
                      { 2, 3, 8 },
                      { 3, 4, 10 },
                      { 4, 5, 15 } };
   int i;
   createEdge(8, &edge[0][0]);  /* �إ���u��C */
   printf("�ϧΪ��̧C�����X�i��:\n");
   minSpanTree();               /* �إ̤߳p�����X�i�� */
   printf("���I�}�C���e: ");
   for ( i = 1; i < MAX_VERTICE; i++ )
      printf("[%d]", vertice[i]); /* ��ܳ��I�}�C */
   printf("\n");
   system("PAUSE");
   return 0; 
}

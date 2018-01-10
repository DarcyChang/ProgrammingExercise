/* �{���d��: radixQueue.c */
#define MAX_LEN 9
#define DIGIT_SIZE 10
struct Node {              /* ��C���c���ŧi */
   int data;               /* ��� */
   struct Node *next;      /* ���c���� */
};
typedef struct Node QNode; /* ��C�`�I���s���A */
typedef QNode *RQueue;     /* ��C���s���A */
/* ���: �N��Ʀs�J��C */
void enqueue(RQueue head[], int i, int d) {
   RQueue newnode, rear;
   /* �t�m�`�I�O���� */
   newnode = (RQueue) malloc( sizeof(QNode));
   newnode->data = d;      /* �s�J��C�`�I */
   newnode->next = NULL;   /* �]�w��� */
   if ( head[i] == NULL )  /* ��1�Ӹ`�I */ 
      head[i] = newnode;
   else {
      rear = head[i];      /* ���o��C���}�l���� */ 
      /* ���̫�1�Ӹ`�I */ 
      while (rear->next != NULL )
         rear = rear->next;
      rear->next = newnode; /* ���J�����̫�1�Ӹ`�I */ 
   }
}
/* ���: �q��C���X��� */
int dequeue(RQueue head[], int i) {
   int temp;
   RQueue ptr = head[i];    /* ���o��C���}�l���� */ 
   head[i] = head[i]->next; /* �R����1�Ӹ`�I */ 
   temp = ptr->data;        /* ���o��� */ 
   free(ptr);
   return temp;
}

/* �{���d��: queue.c */
struct Node {              /* ��C���c���ŧi */
   int data;               /* ��� */
   struct Node *next;      /* ���c���� */
};
typedef struct Node QNode; /* ��C�`�I���s���A */
typedef QNode *LQueue;     /* ��C��C���s���A */
LQueue front = NULL;       /* ��C���e�� */
LQueue rear = NULL;        /* ��C������ */
/* ��H��ƫ��A���ާ@��ƫŧi */
extern int isQueueEmpty();
extern void enqueue(int d);
extern int dequeue();
/* ���: �ˬd��C�O�_�O�Ū� */
int isQueueEmpty() {
   if ( front == NULL ) return 1;
   else                 return 0;
}
/* ���: �N��Ʀs�J��C */
void enqueue(int d) {
   LQueue new_node;
   /* �t�m�`�I�O���� */
   new_node = (LQueue)malloc(sizeof(QNode));
   new_node->data = d;      /* �s�J��C�`�I */
   new_node->next = NULL;   /* �]�w��� */
   if ( rear == NULL )      /* �O�_�O�Ĥ@���s�J */
      front = new_node;     /* front���Vnew_node */
   else
      rear->next = new_node;/* ���Jrear���� */
   rear = new_node;         /* rear���Vnew_node */
}
/* ���: �q��C���X��� */
int dequeue() {
   LQueue ptr;
   int temp;
   if ( !isQueueEmpty() ) {   /* ��C�O�_�O�Ū� */
      if ( front == rear )    /* �p�G�O�̫�@�Ӹ`�I */
         rear = NULL;         
      ptr = front;            /* ptr���Vfront */
      front = front->next;    /* �R����1�Ӹ`�I */
      temp = ptr->data;       /* ���o��� */
      free(ptr);              /* ���^�O���� */
      return temp;            /* �Ǧ^���X����� */
   }
   else return -1;            /* ��C�O�Ū� */
}

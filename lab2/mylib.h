int parse(char *s);
#define STKDPTH 32 /* ������� ����� */

 /* ��������, ������������ �������� parse */
#define VAL  0  /* � ���� �������� ����� �������� */
#define ADD  1  /* �������� */
#define SUB  2  /* ��������� */
#define MUL  3  /* ��������� */
#define DIV  4  /* ������� */
#define SOF -1  /* ������������ ����� */
#define SUF -2  /* � ����� ������������ ��������� */
#define UNK -3  /* ������������ �������� */

/* ���������� ���������� */
int scount;
double stack[STKDPTH];


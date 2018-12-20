int parse(char *s);
#define STKDPTH 32 /* Глубина стека */

 /* Значения, возвращаемые функцией parse */
#define VAL  0  /* В стек занесено новое значение */
#define ADD  1  /* Сложение */
#define SUB  2  /* Вычитание */
#define MUL  3  /* Умножение */
#define DIV  4  /* Деление */
#define SOF -1  /* Переполнение стека */
#define SUF -2  /* В стеке недостаточно операндов */
#define UNK -3  /* Неопознанное значение */

/* Глобальные переменные */
int scount;
double stack[STKDPTH];


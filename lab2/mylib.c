#include "mylib.h"
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

int parse(char *s)
{
	double tval = 0;
	char * endptr;

	/* Распознаем знаки арифметических операций */
	switch (*s) {
	case '-':
		/* Если минус является первым и не последним символом аргумента,
		 * значит пользователь ввел отрицательное число и опознавать его
		 * как операцию вычитания не нужно */
		if (*(s + 1) != '\0') break;
		if (scount >= 2) {
			scount -= 1;
			return(SUB);
		}
		else return(SUF);

	case '+':
		if (scount >= 2) {
			scount -= 1;
			return(ADD);
		}
		else return(SUF);

	case 'x':
		if (scount >= 2) {
			scount -= 1;
			return(MUL);
		}
		else return(SUF);

	case '/':
		if (scount >= 2) {
			scount -= 1;
			return(DIV);
		}
		else return(SUF);
	}

	errno = 0;

	/* Пытаемся сконвертировать строковый аргумент в число */
	tval = strtod(s, &endptr);

	/* Вернуть ошибку `неопознанный аргумент' в случае неудачи */
	if (errno != 0 || *endptr != '\0') return(UNK);

	/* Проверяем, есть ли свободное место в стеке
	 * и сохраняем в нем операнд, иначе возвращаем ошибку переполнения */
	if (scount < STKDPTH) stack[scount++] = tval;
	else return(SOF);

	return(VAL);
}
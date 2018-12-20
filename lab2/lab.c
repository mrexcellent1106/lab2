#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"


int parse(char *);



int main(int argc, char **argv)
{
	
	while (*++argv) {

		
		switch (parse(*argv)) {
		case VAL: continue;

			
		case ADD:
			stack[scount - 1] += stack[scount];
			break;

		case SUB:
			stack[scount - 1] -= stack[scount];
			break;

		case MUL:
			stack[scount - 1] *= stack[scount];
			break;

		case DIV:
			if (stack[scount] != 0) {
				stack[scount - 1] /= stack[scount];
				break;
			}
			else {
				fprintf(stderr, "Деление на ноль!\n");
				return(1);
			}

			
		case SUF:
			fprintf(stderr, "Недостаточно операндов!\n");
			return(1);

		case SOF:
			fprintf(stderr, "Переполнение стека!\n");
			return(1);

		case UNK:
			fprintf(stderr, "Неопознанный аргумент!\n");
			return(1);
		}
	}

	
	auto int i;
	for (i = 0; i < scount; i++) printf("%0.3f\n", stack[i]);

	return(0);
}


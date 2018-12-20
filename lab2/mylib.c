#include "mylib.h"
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

int parse(char *s)
{
	double tval = 0;
	char * endptr;

	/* ���������� ����� �������������� �������� */
	switch (*s) {
	case '-':
		/* ���� ����� �������� ������ � �� ��������� �������� ���������,
		 * ������ ������������ ���� ������������� ����� � ���������� ���
		 * ��� �������� ��������� �� ����� */
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

	/* �������� ��������������� ��������� �������� � ����� */
	tval = strtod(s, &endptr);

	/* ������� ������ `������������ ��������' � ������ ������� */
	if (errno != 0 || *endptr != '\0') return(UNK);

	/* ���������, ���� �� ��������� ����� � �����
	 * � ��������� � ��� �������, ����� ���������� ������ ������������ */
	if (scount < STKDPTH) stack[scount++] = tval;
	else return(SOF);

	return(VAL);
}
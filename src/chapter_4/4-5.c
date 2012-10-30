#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXOP 	100
#define NUMBER 	'0'
#define PI 		3.14159265358979323846264338327
#define PRINT 	't'
#define DUP 	'd'
#define SWAP 	's'
#define CLR 	'c'
#define SIN 	'S'
#define COS 	'C'
#define TAN 	'T'
#define POW 	'P'
#define EXP 	'E'

int getop(char []);
void push(double);
double pop(void);
int is_int(double);
double peek(void);
void swap(void);
void clear(void);
void print(double);

main()
{
	int type;
	double op1;
	double op2;
	char s[MAXOP];
	
	printf("Command list:\n");
	printf("Arithmetic:\t + - * / %\n");
	printf("S:\ttake sin of value in degree form.\n");
	printf("C:\ttake cos of value in degree form.\n");
	printf("T:\ttake tan of value in degree form.\n");
	printf("P:\traise x to y.\n");
	printf("E:\texponentation.\n");
	printf("t:\tprint element on top of stack.\n");
	printf("d:\tduplicate top of stack.\n");
	printf("s:\tswap the top two elements.\n");
	printf("c:\tclear the stack.\n\n");

	while ((type =  getop(s)) != EOF) {
		switch(type) {
		case NUMBER: 
			push(atof(s));
			break;
		case '+':
			push(pop() + pop());
			print(pop());
			break;
		case '*':
			push(pop() * pop());
			print(pop());
			break;
		case '-':
			op2 = pop();
			push(pop() - op2);
			print(pop());
			break;
		case '/':
			op2 = pop();
			if (op2 != 0.0) {
				push(pop() / op2);
				print(pop());
			}
			else
				printf("error: division by zero\n");
			break;
		case '%':
			op2 = pop();
			op1 = pop();
			if (is_int(op1) && is_int(op2)) {
				if (op2 != 0.0) {
					push((int)op1 % (int)op2);
					print(pop());
				}
				else
					printf("error: division by zero\n");
			}
			else
				printf("a \% b, both a and b must be integers.\n");
			break;
		case PRINT:
			op1 = peek();
			print(op1);
			break;
		case DUP:
			op1 = peek();
			push(op1);
			break;
		case SWAP:
			swap();
			break;
		case CLR:
			clear();
			break;
		case SIN:
			op1 = pop();
			push(sin(op1 * PI/180));
			print(pop());
			break;
		case COS:
			op1 = pop();
			push(cos(op1 * PI/180));
			print(pop());
			break;
		case TAN:
			op1 = pop();
			push(tan(op1 * PI/180));
			print(pop());
			break;
		case POW:
			op2 = pop();
			op1 = pop();
			push(pow(op1, op2));
			print(pop());
			break;
		case EXP:
			op1 = pop();
			push(exp(op1));
			print(pop());
			break;
		case '\n':
			//printf("\t%.8g\n", pop());
			break;
		default:
			printf("error: unknown operator\n");
			break;
		}
	}
	return 0;
}

int is_int(double val)
{
	int n = (int) val;
	if ((val - n) == 0.0)
		return 1;
	else
		return 0;
}

void print(double val)
{
	printf("\t%.8g\n", val);
}

#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

void push(double f)
{
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full\n");
}

double pop(void)
{
	if (sp > 0)
		return val[--sp];
	else {
		printf("error: stack empty\n");
		return 0.0;
	}
}

double peek()
{
	double val = pop();
	push(val);
	return val;
}

void swap(void)
{
	double first  = pop();
	double second = pop();
	push(first);
	push(second);
}

void clear(void)
{
	sp = 0;
}

#include <ctype.h>

int getch(void);
void ungetch(int);

int getop(char s[])
{
	int i, c;
	
	while ((s[0] = c = getch()) == ' ' || c == '\t');

	s[1] = '\0';
	if (!isdigit(c) && c != '.')
		return c;
	i = 0;
	if (isdigit(c))
		while (isdigit(s[++i] = c = getch()));
	if (c == '.')
		while (isdigit(s[++i] = c = getch()));
	s[i] = '\0';
	if (c != EOF)
		ungetch(c);
	return NUMBER;
}

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}

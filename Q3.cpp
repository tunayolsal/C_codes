#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include"queue_int.h"
#include"stack_int (2).h"
void carWash(stack_t *s, queue_t *q, int num, char ch)
{
	stack_t stemp;
	initializeS(&stemp);
	int temp;
	if (ch == 'A')
	{
		insert(q, num);
	}
	else
	{
		while (!isEmptyS(s))
		{
			temp = pop(s);
			if (num != temp)
				push(&stemp, temp);
		}
		while (!isEmptyS(&stemp))
			push(s, pop(&stemp));
		push(s, remove(q));
		
	}
}
void display(stack_t s, queue_t q)
{
	printf("\n The washing lanes:");
	while (!isEmptyS(&s))
		printf("\n %d", pop(&s));
	printf("\nThe car Queue:");
	while (!isEmptyQ(&q))
		printf("%d ", remove(&q));
}
int main(void)
{
	FILE* inp = fopen("carWash.txt", "r");
	if (inp == NULL)
		printf("error");
	else
	{
		stack_t lane;
		initializeS(&lane);
		queue_t lot;
		initializeQ(&lot);
		push(&lane, 1);
		push(&lane, 2);
		push(&lane, 3);
		int num;
		char ch;
		while (fscanf(inp, "%c %d ", &ch, &num) != EOF)
		{
			carWash(&lane, &lot, num, ch);
			display(lane, lot);
		}

	}
}
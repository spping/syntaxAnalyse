#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Rule{
	char tag;
	char *each[5];
	int count;
	char first[10];
	char follow[20];
}Rule;

Rule Rarray[10];

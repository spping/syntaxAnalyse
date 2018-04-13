#include "syntaxAnalyse.h"

void FirstSet(Rule *r);
void FollowSet(Rule r);

int main(int argc, char *argv[])
{
	FILE *fp = fopen("Src", "r");
	char s[30];
	char delim[3] = ":|";
	Rule *rp = Rarray;
	while(fgets(s, 30, fp) != NULL){
		int end = strlen(s) - 1;
		if (s[end] == '\n')
		{
			s[end] = 0;
		}
		char *tag = strtok(s, delim);
		rp->tag = *tag;
		int i = 0;
		char *cc;
		while((cc = strtok(NULL, delim)) != NULL){
			rp->each[i] = malloc(strlen(cc));
			strcpy(rp->each[i ++], cc);
			rp->count ++;
		}
		rp ++;
	}
	for(int i = 0; i < 10; i ++){
		if(Rarray[i].tag == 0)
			break;
		FirstSet(&Rarray[i]);
		printf ("%s\n", Rarray[i].first);
	}
	for(int i = 0; i < 5; i ++){
		FollowSet(Rarray[i]);
		printf ("%s\n", Rarray[i].follow);
	}
	return 0;
}
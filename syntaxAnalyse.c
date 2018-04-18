#include "syntaxAnalyse.h"

void FirstSet(Rule *r);
void FollowSet(Rule r, char *);

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

	char whTags[10] = {0};
	for(int i = 0; i < 5; i ++){
		FollowSet(Rarray[i], whTags);
	}


	printf ("whTags = %s\n", whTags);
	for (char *p = whTags; *p != 0; ++ p) {
		char delim[2] = {'@', *p} ;
		for (int i = 0; i < 10; ++i) {
			char cfollow[10];
			strcpy(cfollow, Rarray[i].follow);
			Rarray[i].follow[0] = 0;
			char *c = strtok(cfollow, delim);
			while (strcpy(Rarray[i].follow, c) && (c = strtok(NULL, delim) != NULL) )
				;
		}

	}
	for(int i = 0; i < 5; i ++){
		printf ("%s\n", Rarray[i].follow);
	}


	return 0;
}

#include "syntaxAnalyse.h"

Rule *getRuleByTag(char cc){
	for (int i = 0; i < 10; ++i)
	{
		if (Rarray[i].tag == cc)
		{
			return &Rarray[i];
		}
	}
	return NULL;
}

void FirstSet(Rule *r){
	for (int i = 0; i < r->count; ++i)
	{
		char *cc = r->each[i];
		while(1){
			Rule *t = getRuleByTag(*cc);

			if (t == NULL){
				if(strchr(r->first, *cc) == NULL)
					*(r->first + strlen(r->first)) = *cc;
				break;
			} else{
				if (*(t->first) == 0)
				{
					FirstSet(t);
				}
				if(strstr(r->first, t->first) == NULL)
					strcpy(r->first + strlen(r->first), t->first);
				if (strchr(t->first, '@') == NULL)
					break;
			}
			cc ++;
		}
	}
}

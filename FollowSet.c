#include "syntaxAnalyse.h"

void FirstSet(Rule *r);
Rule *getRuleByTag(char tag);

void FollowSet(Rule r){
	for (int i = 0; i < r.count; ++i)
	{
		char *cc = r.each[i];
		while(*(cc + 1) != 0){
			Rule *t = getRuleByTag(*cc);
			if (t == NULL){
				cc ++;
				continue;
			}
			Rule x;
			x.tag = 'X';
			x.each[0] = cc + 1;
			x.count = 1;
			x.first[0] = 0;
			x.follow[0] = 0;
			FirstSet(&x);
			if (strchr(x.first, '@') != NULL)
			{
				if(*(r.follow) == 0){
					if(strchr(t->follow, r.tag) == NULL)
						t->follow[strlen(t->follow)] = r.tag;
				}
				else{
					for(char *p = r.follow; *p != 0; p ++)
						if(strchr(t->follow, *p) == NULL)
							t->follow[strlen(t->follow)] = *p;
				}
			}
			for(char *p = x.first; *p != 0; p ++)
				if(strchr(t->follow, *p) == NULL)
					t->follow[strlen(t->follow)] = *p;

			cc ++;
		}
		Rule *t = getRuleByTag(*cc);
		if(t != NULL){
			if(*(r.follow) == 0)
				t->follow[strlen(t->follow)] = r.tag;
			else{
				for(char *p = r.follow; *p != 0; p ++)
					if(strchr(t->follow, *p) == NULL)
						t->follow[strlen(t->follow)] = *p;
			}
		}
	}
}

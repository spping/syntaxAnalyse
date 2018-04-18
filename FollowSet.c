#include "syntaxAnalyse.h"

#define MY_STRCPY(des, src)\
	for (char *p = src; *p != 0; p ++)\
		if (strchr(des, *p) == NULL)\
			des[strlen(des)] = *p;

void FirstSet(Rule *r);
Rule *getRuleByTag(char tag);

void FollowSet(Rule r, char *whTags){
	char *pwt;
	pwt = whTags + strlen(whTags);
	for (int i = 0; i < r.count; ++i) {
		char *cc = r.each[i];
		while (*(cc + 1) != 0) {
			Rule *t = getRuleByTag(*cc);
			if (t == NULL) {
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

			if (strchr(x.first, '@') != NULL) {
				if (*(r.follow) == 0) {
					if (strchr(t->follow, r.tag) == NULL) {
						t->follow[strlen(t->follow)] = r.tag;
						if (strchr(whTags, r.tag) == NULL) {
							*(pwt ++) = r.tag;
						}
					}
				} else {
					MY_STRCPY(t->follow, r.follow);
				}
			}
			MY_STRCPY(t->follow, x.first);

			cc ++;
		}
		Rule *t = getRuleByTag(*cc);
		if (t != NULL) {
			if (*(r.follow) == 0) {
				t->follow[strlen(t->follow)] = r.tag;
				if (strchr(whTags, r.tag) == NULL) {
					*(pwt ++) = r.tag;
				}
			} else {
				MY_STRCPY(t->follow, r.follow);
			}
		}
	}

}


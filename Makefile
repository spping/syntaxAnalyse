objects = FollowSet.o FirstSet.o syntaxAnalyse.o

%.o:%.c
	gcc $(CFLAGS) -g -c $< -o $@

syntaxAnalyse:$(objects)
	gcc -g -o syntaxAnalyse $(objects)
$(objects):syntaxAnalyse.h
TAGS:*.[chCH]
	find . -name "*.[chCH]" -print | ctags -

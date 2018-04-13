objects = FollowSet.o FirstSet.o syntaxAnalyse.o

%.o:%.c
	$(CC) $(CFLAGS) -g -c $< -o $@

syntaxAnalyse:$(objects)
	cc -g -o syntaxAnalyse $(objects)
$(objects):syntaxAnalyse.h
TAGS:*.[chCH]
	find . -name "*.[chCH]" -print | etags -
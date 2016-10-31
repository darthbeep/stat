stat: stat.c
	gcc stat.c
run: stat
	./stat
clean:
	rm *~
	rm a.out

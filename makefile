.PHONY:clean
main : seqstack.c
	gcc $^ -o $@
clean:
	rm -f main

main.out: node.o linked_list.o main.c
	clang $^ -o $@

node.o: node.c node.h
	clang -c $^

linked_list.o: linked_list.c linked_list.h
	clang -c $^

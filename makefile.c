linkedlist_test: test_list.o linkedlist.o
	gcc -o linkedlist_test test_list.o linkedlist.o
	
test_list.o: test_list.c linkedlist.h
	gcc -c test_list.c

linkedlist.o: linkedlist.c linkedlist.h
	gcc -c linkedlist.c



test_hash:hash.o test_hash.o
	@gcc -o test_hash hash.o test_hash.o
	@echo doing compile test_hash

test_hash.o:test_hash.c
	@gcc -o test_hash.o -c test_hash.c
	@echo doing compile test_hash.o
	
hash.o:../utils/hash.c
	@gcc -o hash.o -c ../utils/hash.c
	@echo doing compile hash.o

clean:
	@rm -rf test_hash test_hash.o hash.o
	@echo remove files !

Remcache:server.o
	@gcc -o Remcache server.o
	@echo doing compile server

server.o:server.c
	@gcc -o server.o -c server.c
	@echo doing compile server.o

clean:
	@rm Remcache server.o
	@echo doing clean files
	@echo clean finished !

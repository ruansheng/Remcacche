Remcache:list.o queue.o server.o server_socket.o
	@gcc -o Remcache list.o queue.o server.o server_socket.o
	@echo doing compile server

queue.o:list.c
	@gcc -o list.o -c list.c
	@echo doing compile list.o

queue.o:queue.c
	@gcc -o queue.o -c queue.c
	@echo doing compile queue.o

server.o:server.c
	@gcc -o server.o -c server.c
	@echo doing compile server.o

server_socket.o:server_socket.c
	@gcc -o server_socket.o -c server_socket.c
	@echo ding compile server_socket.o

install:
	@echo copy files to target dir !

clean:
	@rm -rf Remcache queue.o list.o server.o server_socket.o
	@echo doing clean files
	@echo clean finished !

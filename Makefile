Remcache:server.o server_socket.o
	@gcc -o Remcache server.o server_socket.o
	@echo doing compile server

server_socket.o:./socket/server_socket.c
	@gcc -o server_socket.o -c ./socket/server_socket.c
	@echo ding compile server_socket.o 

server.o:server.c
	@gcc -o server.o -c server.c
	@echo doing compile server.o

install:
	@echo copy files to target dir !

clean:
	@rm -rf Remcache server.o server_socket.o
	@echo doing clean files
	@echo clean finished !

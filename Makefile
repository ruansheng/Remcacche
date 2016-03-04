Remcache:server.o server_socket.o log.o
	@gcc -o Remcache server.o server_socket.o log.o
	@echo doing compile server

server.o:server.c
	@gcc -o server.o -c server.c
	@echo doing compile server.o

server_socket.o:./server/server_socket.c
	@gcc -o server_socket.o -c ./server/server_socket.c
	@echo ding compile server_socket.o 

log.o:./utils/log.c
	@gcc -o log.o -c ./utils/log.c
	@echo ding compile log.o 

install:
	@echo copy files to target dir !

clean:
	@rm -rf Remcache server.o log.o server_socket.o
	@echo doing clean files
	@echo clean finished !

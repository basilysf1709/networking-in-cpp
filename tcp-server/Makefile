CC=g++
CFLAGS=-g
TARGET:main.exe
LIBS=-lpthread
OBJS=TCPClientDbManager.o				\
		 TCPClientServiceManager.o 	\
		 TCPNewConnectionAcceptor.o	\
		 TCPServerController.o			\
		 network_utils.o

main.exe:main.o ${OBJS}
	${CC} ${CFLAGS} ${OBJS} main.o -o main.exe ${LIBS}

main.o:main.cpp
	${CC} ${CFLAGS} -c main.cpp -o main.o

TCPClientDbManager.o:TCPClientDbManager.cpp
	${CC} ${CFLAGS} -c TCPClientDbManager.cpp -o TCPClientDbManager.o

TCPClientServiceManager.o:TCPClientServiceManager.cpp
	${CC} ${CFLAGS} -c TCPClientServiceManager.cpp -o TCPClientServiceManager.o

TCPNewConnectionAcceptor.o:TCPNewConnectionAcceptor.cpp
	${CC} ${CFLAGS} -c TCPNewConnectionAcceptor.cpp -o TCPNewConnectionAcceptor.o

TCPServerController.o:TCPServerController.cpp
	${CC} ${CFLAGS} -c TCPServerController.cpp -o TCPServerController.o

network_utils.o:network_utils.cpp
	${CC} ${CFLAGS} -c network_utils.cpp -o network_utils.o

clean:
	rm -f *.o
	rm -f *exe
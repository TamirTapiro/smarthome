CC=g++
CFLAGS= -l sqlite3 -lfcgi++ -lfcgi
all: Database.o Home.o main.o RequestManager.o Socket.o User.o
	$(CC) Database.o Home.o main.o RequestManager.o Socket.o User.o -o smart $(CFLAGS) 

Database.o: Database.cpp Database.h
	$(CC) $(CFLAGS) -c Database.cpp

Home.o: Home.cpp Home.h
	$(CC) $(CFLAGS) -c Home.cpp

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

RequestManager.o: RequestManager.cpp RequestManager.h
	$(CC) $(CFLAGS) -c RequestManager.cpp

Socket.o: Socket.cpp Socket.h
	$(CC) $(CFLAGS) -c Socket.cpp 

User.o: User.cpp User.h
	$(CC) $(CFLAGS) -c User.cpp

clean:
	rm -rf *o smart

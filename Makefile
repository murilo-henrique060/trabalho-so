CC = cc

nall: clean all


all: helloworld forks


helloworld: helloworld.c
	$(CC) -o helloworld helloworld.c

forks: forks.c
	$(CC) -o forks forks.c

clean:
	rm -f helloworld forks
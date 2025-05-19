CC = cc

nall: clean all


all: helloworld forks untilbreak


helloworld: helloworld.c
	$(CC) -o helloworld helloworld.c

forks: forks.c
	$(CC) -o forks forks.c

untilbreak: untilbreak.c
	$(CC) -o untilbreak untilbreak.c

clean:
	rm -f helloworld forks untilbreak
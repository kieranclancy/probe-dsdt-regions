all: probe

probe: probe.c regions.c
	gcc -o probe -Wall -pedantic -std=gnu99 probe.c

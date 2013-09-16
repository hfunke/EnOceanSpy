prog: EnOceanSpy.o
	gcc -o EnOcean EnOceanSpy.o

EnOceanSpy.o: EnOceanSpy.c
	gcc -c EnOceanSpy.c

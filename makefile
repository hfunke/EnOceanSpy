prog: EnOceanSpy.o
	gcc -o EnOceanSpy EnOceanSpy.o

EnOceanSpy.o: EnOceanSpy.c
	gcc -c EnOceanSpy.c

clean: 
	rm EnOceanSpy.o
	rm EnOceanSpy


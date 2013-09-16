prog: EnOceanSpy.o
	gcc -o EnOceanSpy EnOceanSpy.o

EnOceanSpy.o: EnOceanSpy.c
	gcc -c EnOceanSpy.c

clean: 
	rm EnOceanSpy.o EnOceanSpy

dist:
	tar -cf enoceanspy_raspi.tar EnOceanSpy EnOceanSpy.c LICENSE README.md
	gzip enoceanspy_raspi.tar
 

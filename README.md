EnOceanSpy
==========
[![Build Status](https://travis-ci.org/hfunke/EnOceanSpy.png?branch=master)](https://travis-ci.org/hfunke/EnOceanSpy)

Use your Raspberry Pi to log all incoming EnOcean telegrams with an USB300 stick.

Requirements (hardware):
* Raspberry Pi
* EnOcean USB300 (Alternative: EnOcean Pi SoC-Gateway TRX 8051)


Compile EnOceanSpy with the following command

gcc -o EnOceanSpy EnOceanSpy.c

or use makefile with the following command

make


You can start spying with

./EnOceanSpy /dev/ttyUSB0    (using EnOcean USB300)
or     
./EnOceanSpy /dev/ttyAMA0    (using EnOcean Pi)

to log all imcoming telegrams at console or start it with

./EnOceanSpy <portname> > log.txt

to log all incoming telegrams in file 'log.txt'.


Have fun to seek your environment after EnOcean devices.

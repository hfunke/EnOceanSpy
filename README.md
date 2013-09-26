EnOceanSpy
==========
[![Build Status](https://travis-ci.org/hfunke/EnOceanSpy.png?branch=master)](https://travis-ci.org/hfunke/EnOceanSpy)

Use your Raspberry Pi to log all incoming EnOcean telegrams with an USB300 stick.

Requirements (hardware):
* Raspberry Pi
* EnOcean USB300 (Alternative to be tested: EnOcean Pi SoC-Gateway TRX 8051)


Compile EnOceanSpy with the following command

gcc -o EnOceanSpy EnOceanSpy.c

of use makefile with the following command

make


You can start spying with

./EnOceanSpy 

to log all imcoming telegrams at console or start it with

./EnOceanSpy > log.txt

to log all incoming telegrams in file 'log.txt'.


Have fun to seek your environment after EnOcean devices.

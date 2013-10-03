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

To use the EnOcean Pi you need to disable Linux using the serial port for debugging. As default the serial port of the GPIO interface is used for console debug outputs. To use this port for your EnOcean Pi, this feature has to be disabled. There is a script available at GitHub to adapt boot up settings:
https://github.com/lurch/rpi-serial-console 


You can start spying with

./EnOceanSpy /dev/ttyUSB0    (using EnOcean USB300)
or     
./EnOceanSpy /dev/ttyAMA0    (using EnOcean Pi)

to log all imcoming telegrams at console or start it with

./EnOceanSpy <portname> > log.txt

to log all incoming telegrams in file 'log.txt'.


Have fun to seek your environment after EnOcean devices.

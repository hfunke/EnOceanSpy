/*
 * EnOceanSpy.c
 * Use this tool to spy for EnOcean telegrams
 *
 *  Created on: 13.09.2013
 *      Author: hfunke
 *
 */

#include <stdio.h>
#include <unistd.h>	// Used for UART
#include <fcntl.h>	// Used for UART
#include <termios.h>	// Used for UART
#include "time.h"

//#define USB300 "/dev/ttyAMA0"  // default EnOcean device


static void print_hexbytes(const unsigned char *bytes, int nbytes)
{

	int i;
	for (i = 0; i < nbytes; i++)
		printf("%02X ", bytes[i]);
	printf("\n");
}

static void printDate()
{
	time_t tm;
	struct tm *ltime;

	time( &tm );
	ltime = localtime( &tm );
	ltime->tm_mon++;
	ltime->tm_year += 1900;

	printf( "%04i-%02i-%02i %02i:%02i:%02i: ", ltime->tm_year,
    		ltime->tm_mon, ltime->tm_mday, ltime->tm_hour, ltime->tm_min, ltime->tm_sec );
}



main( int argc, char *argv[] )
{
	printf("Starting EnOceanSpy...\n");

	// Check number of args
	if (argc > 2 || argc <=1 ) 
	{
		printf("Usage: EnOceanSpy <port_name>\n");
		printf("       e.g. EnOceanSpy /dev/ttyUSB0 \n");
		return -1;
	}	


	// Check content of args	
	if ((strcmp(argv[1], "/dev/ttyUSB0") != 0) 
		&& (strcmp(argv[1], "/dev/ttyAMA0") !=0) )
	{
		printf("Error: %s is not a valid port name!\n", argv[1]);
		return -1;
	}


	// If pipe is used to write output in file set buffer to null
	setbuf(stdout, NULL);

	int uart0_filestream = -1;

	uart0_filestream = open(argv[1], O_RDWR | O_NDELAY);
	if (uart0_filestream == -1)
	{
		printf("Error! Unable to open UART. Maybe UART in use by another application or device is not ready.\n");
		return -1;
	}

	struct termios options;
	tcgetattr(uart0_filestream, &options);
	options.c_cflag = B57600 | CS8 | CLOCAL | CREAD;
	options.c_iflag = IGNPAR | ICRNL | PARENB;
	options.c_oflag = 0;
	options.c_lflag = 0;
	tcflush(uart0_filestream, TCIFLUSH);
	tcsetattr(uart0_filestream, TCSANOW, &options);

	while (1)
	{
		// Check for incoming bytes
		if (uart0_filestream != -1)
		{
			// Give Raspberry a chance and wait before read :)
	        	sleep(1);

	        	// Read up to 255 characters from comport if they are there
	        	unsigned char rx_buffer[256];
	        	int rx_length = read(uart0_filestream, (void*)rx_buffer, 255);
	        	if (rx_length < 0)
	        	{
	        		// An error occurs if there are no bytes
	        		//printf("No bytes received");
			}
	        	else if (rx_length == 0)
	        	{
	            		// If there are no data then ignore and wait
	        	}
	        	else
	        	{
	        		// Some bytes received
	            		rx_buffer[rx_length] = '\0';
		    		printDate();
	            		print_hexbytes(rx_buffer, rx_length);
	        	}
		}
	}
}


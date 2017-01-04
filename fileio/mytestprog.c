#include <stdio.h>
#include <stdlib.h>
#include "vhlvdatafile.h"

int main(int argc, char **argv) {

	vhlvheaderfile *myheader;

	char myfilename[] = "/Users/vanhoosr/Desktop/2013-02-01/t00001/vhlvanaloginput.vlh";

	myheader = readvhlvheaderfile(myfilename);

	printvhlvheaderfile(myheader,stdout);

	free((void*)myheader);

	return 1;
}

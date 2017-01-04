#ifndef VHLVDATAFILE_H_INCLUDED
#define VHLVDATAFILE_H_INCLUDED

#include <stdio.h>

typedef struct {
	char ChannelString[1000];
	int NumChans;
	double SamplingRate;
	long int SamplesPerChunk;
	int Multiplexed;
	char precision[1000];
} vhlvheaderfile;

/* function prototypes */

vhlvheaderfile *readvhlvheaderfile(char *filename);

void printvhlvheaderfile(vhlvheaderfile *header, FILE *stream);

int readvhlvdatafile(char *filename, double t0, double t1, 
	vhlvheaderfile header, int channels, double *data, double *t);

int readvhlvdatafile_int(double t0, double t1, vhlvheaderfile header,
	int channels, int *data, double *t);


#endif

#include "vhlvdatafile.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


vhlvheaderfile *readvhlvheaderfile(char *filename) {

	vhlvheaderfile *header;
	FILE *fid;
	char buffer[1001],fieldname[1001],value[1001];
	int i, colon;

	header = (vhlvheaderfile*)malloc(sizeof(vhlvheaderfile));

	/* step 1: assign defaults */

	strcpy(header->ChannelString,"");
	header->NumChans = 0;
	header->SamplingRate = 0.0;
	header->SamplesPerChunk = 0;
	header->Multiplexed = 0;
	strcpy(header->precision,"double");

	/* step 2: open the file */

	fid = fopen(filename, "r");  /* open a text file */
	if (fid==NULL) {
		printf("Error opening file %s\n", filename);
		exit(1);
	}

	/* step 3: process the file line by line */

	while (!feof(fid)) {
		fgets(buffer,1000,fid);
		for (i=0;i<1001;i++) { 
			fieldname[i] = '\0';
			value[i] = '\0';
		}
		/*printf("%s",buffer);*/
		colon = -1;
		for (i=0; i<strlen(buffer); i++ ) {
			if (buffer[i]  == ':') {
				colon = i;
				break;
			}
		}
		if (colon==-1) { 
		} else {
			strncpy(fieldname,buffer,colon);
			strncpy(value,(buffer+colon+2),strlen(buffer)-colon-2-1);
	
	/*		printf("Fieldname: %s\n", fieldname);
			printf("value: %s\n", value);	*/
	
			if (strcmp(fieldname,"ChannelString")==0) {
				strcpy(header->ChannelString, value);
			} else if (strcmp(fieldname,"NumChans")==0) {
				header->NumChans = atoi(value);
			} else if (strcmp(fieldname,"SamplingRate")==0) {
				header->SamplingRate = atof(value);
			} else if (strcmp(fieldname,"SamplesPerChunk")==0) {
				header->SamplesPerChunk = atol(value);
			} else if (strcmp(fieldname,"Multiplexed")==0) {
				header->Multiplexed = atoi(value);
			} else if (strcmp(fieldname,"precision")==0) {
				strcpy(header->precision,value);
			} else {
				printf("Unknown field name %s\n", fieldname);
			}
		}
	}

	fclose(fid);

	return header;
}

void printvhlvheaderfile(vhlvheaderfile *header, FILE *stream) {
	fprintf(stream,"ChannelString:\t%s\n",header->ChannelString);
	fprintf(stream,"NumChans:\t%d\n",header->NumChans);
	fprintf(stream,"SamplingRate:\t%f\n",header->SamplingRate);
	fprintf(stream,"SamplesPerChunk:\t%ld\n",header->SamplesPerChunk);
	fprintf(stream,"Multiplexed:\t%d\n",header->Multiplexed);
	fprintf(stream,"precision:\t%s\n",header->precision);
}


int readvhlvdatafile(char *filename, double t0, double t1, vhlvheaderfile header, int channels, double *data, double *t) {
	printf("I do nothing but print this.\n");
}

int readvhlvdatafile_int(double t0, double t1, vhlvheaderfile header, int channels, int *data, double *t) {
	printf("I do nothing but print this.\n");
}


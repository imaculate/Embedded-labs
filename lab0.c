/*
 ============================================================================
 Name        : lab0.c
 Author      : Amir Patel
 Version     :
 Copyright   : Your copyright notice
 Description : First lab for EEE3074W
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/* Include files */
#include "lab0.h"
   
/* Any MACROS you want to define go here */
#define ARRAYLENGTH(x) (sizeof (x) / sizeof *(x)) // Only use this on statically define arrays !!!
#define sampleT 1 /* sample time of data set in seconds */

/* This is the Main function */
int main(void)
{
	float fFirst;
	float fMinAlt;
	fFirst = fpTestData[0];

	/* Print some stuff */
	printf("Welcome to EEE3074W - Lab0 \n"); /* prints EEE3074W: Lab0 */

	/* Determine the runway altitude */
	fMinAlt = minVal( fpTestData, ARRAYLENGTH(fpTestData));

	/* Print Minimum Altitude */
	printf("The runway altitude of the test data is = %f m\n", fMinAlt);


	//Insert your function calls and related code here...
	float* datapointer;
	int points = readData("FlightData.bin", &datapointer);
	printf("Printing array values");
	int i = 0;
	for ( i = 0; i < points; i++ ){
		printf("%.6f",*(datapointer+i));
	}
	free(datapointer);
	/* End of Main */
	return 0;
}

/**
 * Function determines and returns the minimum value in an array.
 * @param data - data array
 * @param sizeData - size of the data array
 */
float minVal(float* fpData, int iSizeData)
{
	/* Initialise Variables */
	int i = 0;
	float fMinVal;

	/* Do a for loop to search for the min value */
	for ( i = 0; i < iSizeData; i++ )
	{
		/* If it is the first element */
		if ( i == 0 )
		{
			/* Set to first value */
			fMinVal = fpData[i];
		}
		else
		{
			/* If current min value is smaller than current element */
			if ( fpData[i] < fMinVal )
			{
				/* Found a new min value */
				fMinVal = fpData[i];
			}
		}
	}

	/* Return the minimum value */
	return fMinVal;
}

int readData(char *cpFilename, float **fpFlightData){
	int totalNumber = -1;
	FILE* pFile  = fopen(cpFilename, "rb");
	if(pFile == NULL) return totalNumber;
	
	fseek (pFile , 0 , SEEK_END);
	//fseek(pFile, SEEK_SET, sizeof(int))
  	long lSize = ftell (pFile);
  	rewind (pFile);

	
	float* buffer = (float*)malloc(sizeof(float)*lSize);
	
  	// copy the file into the buffer:
  	totalNumber = fread (buffer,sizeof(float),lSize,pFile);
   
   fpFlightData = &buffer;
  	if (totalNumber != lSize) {fputs ("Reading error",stderr); return -1;}

  	 fclose (pFile);
  
	
	return totalNumber;
	
}


/**
 *  - Write a function determine the take-off time
 *  - Write a function that determines the maximum height
 *  - Write a function that determines the maximum climb rate (hint, use the derivative )
 *
 */

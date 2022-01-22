/*
GenSpheresProc.cpp

A relatively simple example of a RiProcedural. For info see,
https://rmanwiki.pixar.com/display/REN22/Procedural+Primitives
Also refer to,
http://fundza.com/rfm/procedural/starter/index.html

M.A.Kesson
22 March 2020
*/

#include <ri.h>
#include <RixInterfaces.h>
#include <RiTypesHelper.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEFAULT_RAD 1
#define DEFAULT_NUM 1

// A RiProcedural must implement these functions.
extern "C"
{
	PRMANEXPORT RtPointer ConvertParameters ( RtString paramStr              );
	PRMANEXPORT RtVoid    Subdivide         ( RtPointer data, RtFloat detail );
	PRMANEXPORT RtVoid    Free              ( RtPointer data                 );
}

// A custom data structure for defining an arbitrary number of spheres
typedef struct {
	RtFloat radius;
	RtInt	num;
	} SpheresData;

// Declare our utility functions...	
RtFloat randBetween(RtFloat min, RtFloat max);

// ----------------------------------------------------
// A RiProcedural required function
// ----------------------------------------------------
//
RtPointer ConvertParameters(RtString paramStr) {
	// Allocate a block of memory to store one instance of our custom data structure.
	SpheresData *dataPtr = (SpheresData*)malloc(sizeof(SpheresData));
	
	// The user has forgotten to specify the number and size of the spheres in the
	// RenderManProcedural's data text field - so we use our default values.	
	if(paramStr == NULL || strlen(paramStr) == 0) {
		dataPtr->radius = DEFAULT_RAD;
		dataPtr->num = DEFAULT_NUM;
		}
	else
		{
		// We assume the input string consists of a float and an integer.
		// For example, "0.2 200".
		// The sscanf function reads the data from the parameter string, converts
		// each item to the appropriate datatype and assigns their values to the 
		// appropriate "field" of our custom data structure.
		sscanf(paramStr, "%f %d", &dataPtr->radius, &dataPtr->num);
		}
	return (RtPointer)dataPtr;
}

// ----------------------------------------------------
// A RiProcedural required function
// ----------------------------------------------------
RtVoid Subdivide(RtPointer data, RtFloat detail) {
    RtFloat radius = ((SpheresData*)data)->radius;
	RtInt 	num = ((SpheresData*)data)->num;
	srand(1);
	RtFloat value = 0.1;
	RiAttribute("displacementbound", "float sphere", &value, RI_NULL);
	
    // Output randomly located spheres
	for(int n = 0; n < num; n++) {
		RtFloat x = randBetween(-5,5);
		RtFloat y = randBetween(-5,5);
		RtFloat z = randBetween(-5,5);
		RiTransformBegin();
			RiTranslate(x,y,z);
			
			// To assign a color to each sphere un-comment the next two lines
			// and comment line 86
			// RtColor cs[1] = { {randBetween(0,1),randBetween(0,1),randBetween(0,1) } } ;
    		// RiSphere(radius, -radius, radius, 360, "constant color Cs", (RtPointer)cs, RI_NULL);
    		RiSphere(radius, -radius, radius, 360, RI_NULL);
		RiTransformEnd();
		}
	}
// ----------------------------------------------------
// A RiProcedural required function
// ----------------------------------------------------
RtVoid Free(RtPointer data) {
    free(data);
	}
	
// ----------------------------------------------------
// Our utility functions begin here 
// ----------------------------------------------------
RtFloat randBetween(RtFloat min, RtFloat max) {
    return ((RtFloat)rand()/RAND_MAX) * (max - min) + min;
    }

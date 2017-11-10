//============================================================================
// Name        : assign22.cpp
// Author      : Andrew Nash (201609492)
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include "assign1.h"
#include <iostream>
#include <cmath>

/*
using namespace std;

Point path[3];


int main()
{
	path[0].x = 2;
	path[0].y = 2;

	path[1].x = 1;
	path[1].y = 1;

	path[2].x = 2;
	path[2].y = 2;

	cout << pathLength(path, 3) << endl;
	return 0;
}
*/

Spatial pathLength(Point path[], int numPoints)
{
	//Define variables to make calculations easier to understand
	Spatial d = 0; //Total Distance
	Spatial x;
	Spatial y;

	for(int i=1; i < numPoints; i++)   //Starts at i=1 because we are always comparing the the point before the current i
	{
		x = path[i].x - path[i-1].x;   //Delta x distance between current point and last
		y = path[i].y - path[i-1].y;   //Delta y distance between current point and last
		d += sqrt( x*x + y*y );        //find distance between points using a^2 + b^2 = c^2
	}

	return d; //Return final distance
}

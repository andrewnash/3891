// Use the type 'Spatial' in your code whenever you need
// to specify a length or distance.
typedef double Spatial;

// The Point struct should represent 2D coordinates in
// a Cartesian plane.
struct Point
{
    Spatial x;
    Spatial y;
};


/**********************************************************
* pathLength - Calculates length of path defined by a
* a sequence of points in a 2D plane.  The length is the
* sum of the distance from element 0 to element 1, element
* 1 to element 2, ..., element numPoints-2 to element
* numPoints-1.  If there is only 1 element, the length
* of the path is 0.
*
* @params path[] - an array of Points of length numPoints
*         numPoints - length of array path
*                     @pre numPoints > 0
*
* @returns the length of the path specified by the
*          sequence of points in the path array
**********************************************************/
Spatial pathLength(Point path[], int numPoints);

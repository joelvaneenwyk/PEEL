///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 *	Contains code for box-box distance
 *	\file		CTC_OBBOBBDistance.h
 *	\author		Pierre Terdiman
 *	\date		January, 13, 2000
 */
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Include Guard
#ifndef CTCOBBOBBDISTANCE_H
#define CTCOBBOBBDISTANCE_H

	CONTACT_API float BoxBoxDist(const Matrix3x3& rot, const Point& trans, const Point& centerp, const Point& extentsp, const Point& centerq, const Point& extentsq);

#endif // CTCOBBOBBDISTANCE_H

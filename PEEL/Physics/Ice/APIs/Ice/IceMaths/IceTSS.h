///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 *	Contains code for triangle-swept spheres.
 *	\file		IceTSS.h
 *	\author		Pierre Terdiman
 *	\date		April, 4, 2000
 */
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Include Guard
#ifndef ICETSS_H
#define ICETSS_H

	class ICEMATHS_API TSS : public Triangle
	{
		public:
		//! Constructor
		inline_			TSS()		{}
		//! Destructor
		inline_			~TSS()		{}

				float	mRadius;	//!< Sphere radius
	};

#endif // ICETSS_H
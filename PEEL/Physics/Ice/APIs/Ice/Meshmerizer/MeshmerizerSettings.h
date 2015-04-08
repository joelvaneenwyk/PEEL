///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 *	Compilation flags for Meshmerizer.
 *	\file		MeshmerizerSettings.h
 *	\author		Pierre Terdiman
 *	\date		October, 19, 2002
 */
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Include Guard
#ifndef MESHMERIZERSETTINGS_H
#define MESHMERIZERSETTINGS_H

	//! Supports convex hull usage for eigen analysis
	#define MMZ_SUPPORT_HULL_EIGEN

	//! Supports second mapping channel in MeshBuilder
//	#define MMZ_SUPPORT_SECOND_MAPPING_CHANNEL

	#define MSH_NEW_EDGE_LIST

	//! If defined, the adjacency structures include a redundant copy of topologies
//	#define MSH_ADJACENCIES_INCLUDE_TOPOLOGY

	//! If defined, the adjacency structures include convex edge flags
	#define MSH_ADJACENCIES_INCLUDE_CONVEX_BITS

//	#define COMPILE_MESHLIB
//	#define SUPPORT_ROOM
//	#define SUPPORT_SEPARATE_ACTIVE_EDGES

	#define MSH_SUPPORT_AERO_MAP
	#define MSH_SUPPORT_PROJ_MAP

#endif // MESHMERIZERSETTINGS_H
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 *	Contains the IceCore API and related structures.
 *	\file		IceCoreAPI.h
 *	\author		Pierre Terdiman
 *	\date		April, 18, 2003
 */
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Include Guard
#ifndef ICECOREAPI_H
#define ICECOREAPI_H

	class ICECORE_API ICECORECREATE : public APICREATE
	{
					DECLARE_CREATOR(ICECORECREATE, APICREATE)

		bool		mLogFile;
		bool		mSetupFPU;
	};

	class IceCoreAPI : public IceAPI
	{
		public:
		// Constructor/Destructor
											IceCoreAPI();
		virtual								~IceCoreAPI();

		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/**
		 *	Initializes the API. Must be called first, else the API behaviour is undefined.
		 *	\param		create	[in] creation parameters
		 *	\return		true if the API is initialized for the first time
		 */
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		override(IceAPI)	bool			Init(const APICREATE* create);

		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/**
		 *	Closes the API.
		 *	\param		force_release	[in] true to force the lib to be released, else use refcounting
		 *	\return		false if the API is still beeing referenced
		 */
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		override(IceAPI)	bool			Close(bool force_release);

		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/**
		 *	Gets the API's name.
		 *	\return		the API name
		 */
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		override(IceAPI)	const char*		GetAPIName()			const;

		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/**
		 *	Gets the compile-time string. This can be used to check which DLL is the most recent.
		 *	\return		compile-time string
		 */
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		override(IceAPI)	const char*		GetCompileTimeString()	const;

		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/**
		 *	Class factory.
		 *	\param		class_name	[in] name of desired class
		 *	\return		new class instance, or null
		 */
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		override(IceAPI)	void*			CreateClass(const char* class_name);

		override(IceAPI)	void			NewInterface(IceInterface* it);
	};

	FUNCTION ICECORE_API bool InitIceCore(const ICECORECREATE* api=null);
	FUNCTION ICECORE_API bool CloseIceCore(bool force_release=false);

#endif // ICECOREAPI_H

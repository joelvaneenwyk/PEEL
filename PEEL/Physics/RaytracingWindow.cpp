///////////////////////////////////////////////////////////////////////////////
/*
 *	PEEL - Physics Engine Evaluation Lab
 *	Copyright (C) 2012 Pierre Terdiman
 *	Homepage: http://www.codercorner.com/blog.htm
 */
///////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "RaytracingWindow.h"

#define	BORDER_SIZE				8
#define	GROUP_BOX_BORDER_SIZE	16

RaytracingWindow::RaytracingWindow(const WindowDesc& desc) : IceWindow(desc)
{
	mRGBWindow = null;
	mRGBGroup = null;
	mFlags |= WF_MOVABLE_CLIENT_AREA;

	mPic.Init(RAYTRACING_DISPLAY_WIDTH, RAYTRACING_DISPLAY_HEIGHT);
	mPic.Clear();

	CreatePic();
}

RaytracingWindow::~RaytracingWindow()
{
}

void RaytracingWindow::CreatePic()
{
#define XX RAYTRACING_DISPLAY_WIDTH
#define YY RAYTRACING_DISPLAY_HEIGHT
	mPic.Init(XX, YY);
	RGBAPixel* Pixels = mPic.GetPixels();
//	FractalBrownianMotion FBM(0.5f, 1.5f, 4.0f);
//	RidgedFractal FBM(0.5f, 1.5f, 4.0f, 1.0f, 1.0f);
	PerlinNoise FBM;
	Point Vector(1.0f, 0.0f, 100.0f);
	static float z = 0.0f;
	z+=0.01f;
	Vector.z = z;
	float Coeff = 0.005f;
	for(udword y=0;y<YY;y++)
	{
		for(udword x=0;x<XX;x++)
		{
			Vector.x = float(x)*Coeff;
			Vector.y = float(y)*Coeff;
			float fR = 128.0f + 128.0f * FBM.Compute(Vector);
			float fG = 128.0f + 128.0f * FBM.Compute(Vector+Point(0.0f, 0.0f, -1.0f));
			float fB = 128.0f + 128.0f * FBM.Compute(Vector+Point(0.0f, 0.0f, 1.0f));
			Pixels->R = ubyte(fR);
			Pixels->G = ubyte(fG);
			Pixels->B = ubyte(fB);
			Pixels->A = 255;
			Pixels++;
/*
			udword fR =  (udword)(200.0f - FBM.Turbulence(Vector, 32.0f) * 250.0f);
			udword fG =  (udword)(200.0f - FBM.Turbulence(Vector+Point(0.0f, 0.0f, -1.0f), 32.0f) * 250.0f);
			udword fB =  (udword)(200.0f - FBM.Turbulence(Vector+Point(0.0f, 0.0f, 1.0f), 32.0f) * 250.0f);
			Pixels->R = ubyte(fR);
			Pixels->G = ubyte(fG);
			Pixels->B = ubyte(fB);
			Pixels->A = 255;
			Pixels++;*/
		}
	}
}

void RaytracingWindow::redraw()
{
//	CreatePic();
	mRGBWindow->redraw();
//	printf("Redraw\n");
}

BitmapWindow::BitmapWindow(const WindowDesc& desc) : IceWindow(desc)
{
	mMainW = null;
}

BitmapWindow::~BitmapWindow()
{
}

void BitmapWindow::redraw()
{
	CopyPictureToWindow(GetHandle(), mMainW->mPic, false);
}

static void CreateBitmapWindow(Container& owner, BitmapWindow*& bitmap, IceGroupBox*& group, RaytracingWindow* parent, sdword x, sdword y, udword width, udword height, const char* label)
{
	const udword OffsetY = 4;	// ### not sure why this is needed

	// Create bitmap window
	WindowDesc WD;
	WD.mParent	= parent;
	WD.mX		= x + GROUP_BOX_BORDER_SIZE;
	WD.mY		= y + GROUP_BOX_BORDER_SIZE + OffsetY;
	WD.mWidth	= width;
	WD.mHeight	= height;
	WD.mLabel	= "BitmapWindow";
	WD.mType	= WINDOW_POPUP;
	WD.mStyle	= WSTYLE_NORMAL;
// ### the better style works but not all pixels get displayed
//	WD.mStyle	= WSTYLE_CLIENT_EDGES|WSTYLE_STATIC_EDGES;
	bitmap = ICE_NEW(BitmapWindow)(WD);
	bitmap->SetVisible(true);
	bitmap->mMainW = parent;
	owner.Add(udword(bitmap));

	if(0)
	{
		GroupBoxDesc GBD;
		GBD.mParent	= parent;
		GBD.mX		= x;
		GBD.mY		= y;
		GBD.mWidth	= width + GROUP_BOX_BORDER_SIZE*2;
		GBD.mHeight	= height + GROUP_BOX_BORDER_SIZE*2 + OffsetY;
		GBD.mLabel	= label;
		group = ICE_NEW(IceGroupBox)(GBD);
		owner.Add(udword(group));
	}
	else
	{
		EditBoxDesc EBD;
		EBD.mParent		= parent;
		EBD.mX			= x;
		EBD.mY			= y;
		EBD.mWidth		= width + GROUP_BOX_BORDER_SIZE*2;
		EBD.mHeight		= height + GROUP_BOX_BORDER_SIZE*2 + OffsetY;
		EBD.mLabel		= label;
		EBD.mFilter		= EDITBOX_TEXT;
		EBD.mType		= EDITBOX_READ_ONLY;
		IceEditBox* EB = ICE_NEW(IceEditBox)(EBD);
		EB->SetVisible(true);
		owner.Add(udword(EB));
	}
}

RaytracingWindow* CreateRaytracingWindow(Container& owner, IceWidget* parent, sdword x, sdword y, sdword width, sdword height)
{
	// Texture size
	const udword TextureWidth = RAYTRACING_DISPLAY_WIDTH;
	const udword TextureHeight = RAYTRACING_DISPLAY_HEIGHT;

	// Create main window
	RaytracingWindow* TTWindow = null;
	if(1)
	{
		WindowDesc WD;
		WD.mParent	= parent;
		WD.mX		= x;
		WD.mY		= y;
		WD.mWidth	= width;
		WD.mHeight	= height;
		WD.mLabel	= "Raytracing window";
		WD.mType	= WINDOW_NORMAL;
//		WD.mType	= WINDOW_POPUP;
//		WD.mStyle	= WSTYLE_CLIENT_EDGES;
		WD.mStyle	= WSTYLE_NORMAL;
		TTWindow = ICE_NEW(RaytracingWindow)(WD);
		TTWindow->SetVisible(true);
		owner.Add(udword(TTWindow));
	}

	CreateBitmapWindow(owner, TTWindow->mRGBWindow, TTWindow->mRGBGroup, TTWindow, BORDER_SIZE, BORDER_SIZE, TextureWidth, TextureHeight, "================ Raytraced view =================");

	return TTWindow;
}

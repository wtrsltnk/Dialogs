// ColorDialog.cpp: implementation of the ColorDialog class.
//
//////////////////////////////////////////////////////////////////////

#include "ColorDialog.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

ColorDialog::ColorDialog()
{
}

ColorDialog::~ColorDialog()
{
}

UINT ColorDialog::Show(HWND hOwner, COLORREF& color)
{
	CHOOSECOLOR cc;

	COLORREF acrCustClr[16];

	ZeroMemory(&cc, sizeof(CHOOSECOLOR));
	cc.lStructSize = sizeof(CHOOSECOLOR);
	cc.hwndOwner = hOwner;
	cc.lpCustColors = (LPDWORD) acrCustClr;
	cc.rgbResult = color;
	cc.Flags = CC_FULLOPEN | CC_RGBINIT;
 
	if (ChooseColor(&cc) != NULL)
	{
		color = cc.rgbResult;
		return TRUE;
	}

	return FALSE;
}
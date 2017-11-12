// FontDialog.cpp: implementation of the FontDialog class.
//
//////////////////////////////////////////////////////////////////////

#include "FontDialog.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

FontDialog::FontDialog()
{
}

FontDialog::~FontDialog()
{
}

UINT FontDialog::Show(HWND hOwner, LOGFONT& lf)
{
	CHOOSEFONT cf;

	ZeroMemory(&cf, sizeof(CHOOSEFONT));
	cf.lStructSize = sizeof (CHOOSEFONT);
	cf.hwndOwner = hOwner;
	cf.lpLogFont = &lf;
	cf.Flags = CF_SCREENFONTS | CF_EFFECTS;

	if (ChooseFont(&cf) != NULL)
	{
		return TRUE;
	}
	return FALSE;
}

// OpenDialog.cpp: implementation of the OpenDialog class.
//
//////////////////////////////////////////////////////////////////////

#include "OpenDialog.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

OpenDialog::OpenDialog()
{
}

OpenDialog::~OpenDialog()
{
}

UINT OpenDialog::Show(HWND hOwner, LPTSTR strFilter, INT &nFilterIndex, LPTSTR strFile)
{
	OPENFILENAME ofn = {0};
	
	ofn.Flags             = OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT;
	ofn.hwndOwner         = hOwner;
	ofn.lpstrCustomFilter = 0;
	ofn.lpstrFile         = strFile;
	ofn.lpstrFileTitle    = 0;
	ofn.lpstrFilter       = strFilter;
	ofn.nFilterIndex	  = nFilterIndex;
	ofn.lpstrDefExt		  = "";
	ofn.lpstrInitialDir   = 0;
	ofn.lpstrTitle        = "Open";
	ofn.lStructSize       = sizeof(OPENFILENAME);
	ofn.nMaxFile          = MAX_PATH;

	if (GetOpenFileName(&ofn) != NULL)
	{
		nFilterIndex = ofn.nFilterIndex;
		return TRUE;
	}

	return FALSE;
}

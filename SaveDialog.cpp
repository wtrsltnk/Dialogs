// SaveDialog.cpp: implementation of the SaveDialog class.
//
//////////////////////////////////////////////////////////////////////

#include "SaveDialog.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

SaveDialog::SaveDialog()
{
}

SaveDialog::~SaveDialog()
{
}

UINT SaveDialog::Show(HWND hOwner, LPTSTR strFilter, INT &nFilterIndex, LPTSTR strFile)
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
	ofn.lpstrTitle        = "Save";
	ofn.lStructSize       = sizeof(OPENFILENAME);
	ofn.nMaxFile          = MAX_PATH;

	if (GetSaveFileName(&ofn) != NULL)
	{
		nFilterIndex = ofn.nFilterIndex;
		return TRUE;
	}

	return FALSE;
}

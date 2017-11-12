// FolderDialog.cpp: implementation of the FolderDialog class.
//
//////////////////////////////////////////////////////////////////////

#include "FolderDialog.h"
#include <shlobj.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

FolderDialog::FolderDialog()
{
}

FolderDialog::~FolderDialog()
{
}


UINT FolderDialog::Show(HWND hOwner, LPTSTR strTitle, LPTSTR strDirectory)
{
	BROWSEINFO bi;
    ITEMIDLIST *pidl;

    bi.hwndOwner = hOwner;
    bi.pidlRoot = 0;
    bi.pszDisplayName = strDirectory;
    bi.lpszTitle = strTitle;
    bi.ulFlags = BIF_RETURNONLYFSDIRS;
    bi.lpfn = 0;
    bi.lParam = 0;

    pidl = SHBrowseForFolder(&bi);

    if (SHGetPathFromIDList(pidl, strDirectory))
	{
		return TRUE;
	}
	
	return FALSE;
}
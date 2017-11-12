// FolderDialog.h: interface for the FolderDialog class.
//
//////////////////////////////////////////////////////////////////////

#ifndef FOLDERDIALOG_H
#define FOLDERDIALOG_H

#include <windows.h>
#include "Dialogs.h"

class DIALOGSDLL_API FolderDialog  
{
public:
	FolderDialog();
	virtual ~FolderDialog();

	UINT Show(HWND hOwner, LPTSTR strTitle, LPTSTR strDirectory);

};

#endif

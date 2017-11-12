// SaveDialog.h: interface for the SaveDialog class.
//
//////////////////////////////////////////////////////////////////////

#ifndef SAVEDIALOG_H
#define SAVEDIALOG_H

#include <windows.h>
#include "Dialogs.h"

class DIALOGSDLL_API SaveDialog  
{
private:

public:
	SaveDialog();
	virtual ~SaveDialog();

	UINT Show(HWND hOwner, LPTSTR strFilter, INT &nFilterIndex, LPTSTR strFile);
	
};

#endif

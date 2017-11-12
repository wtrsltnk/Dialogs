// OpenDialog.h: interface for the OpenDialog class.
//
//////////////////////////////////////////////////////////////////////

#ifndef OPENDIALOG_H
#define OPENDIALOG_H

#include <windows.h>
#include "Dialogs.h"

class DIALOGSDLL_API OpenDialog  
{
private:
	
public:
	OpenDialog();
	virtual ~OpenDialog();

	UINT Show(HWND hOwner, LPTSTR strFilter, INT &nFilterIndex, LPTSTR strFile);

};

#endif

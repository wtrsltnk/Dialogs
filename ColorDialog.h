// ColorDialog.h: interface for the ColorDialog class.
//
//////////////////////////////////////////////////////////////////////

#ifndef COLORDIALOG_H
#define COLORDIALOG_H

#include <windows.h>
#include "Dialogs.h"

class DIALOGSDLL_API ColorDialog  
{
public:
	ColorDialog();
	virtual ~ColorDialog();

	static UINT Show(HWND hOwner, COLORREF& color);

};

#endif

// FontDialog.h: interface for the FontDialog class.
//
//////////////////////////////////////////////////////////////////////

#ifndef FONTDIALOG_H
#define FONTDIALOG_H

#include <windows.h>
#include "Dialogs.h"

class DIALOGSDLL_API FontDialog  
{
public:
	FontDialog();
	virtual ~FontDialog();

	static UINT Show(HWND hOwner, LOGFONT& lf);
	
};

#endif

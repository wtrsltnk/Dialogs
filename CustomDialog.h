// CustomDialog.h: interface for the CustomDialog class.
//
//////////////////////////////////////////////////////////////////////

#ifndef CUSTOMDIALOG_H
#define CUSTOMDIALOG_H

#include "Dialogs.h"
#include "CustomDialog.h"

class DIALOGSDLL_API CustomDialog
{
protected:
	static LRESULT StaticProc(HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam);

protected:
	HWND hDlg;
	HWND hParent;
	HINSTANCE hInstance;
	DWORD dwResourceDlg;
	
protected:
	virtual VOID DlgProc(UINT uMsg, WPARAM wParam, LPARAM lParam);
	
public:
	CustomDialog();
	virtual ~CustomDialog();

	UINT ShowModal(HINSTANCE hInst, HWND hParent);
	UINT ShowModalless(HINSTANCE hInst, HWND hParent);
	
	VOID Resize(UINT x, UINT y, UINT width, UINT height);

	HWND GetDlgItemHandle(DWORD dwDlgItem);

	UINT Height();
	UINT Width();

};

#endif

// CustomDialog.cpp: implementation of the CustomDialog class.
//
//////////////////////////////////////////////////////////////////////

#include "CustomDialog.h"

//////////////////////////////////////////////////////////////////////
// Statics
//////////////////////////////////////////////////////////////////////

LRESULT CustomDialog::StaticProc(HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	CustomDialog *pDlg = NULL;

	if (uMsg == WM_INITDIALOG)
	{
		pDlg = reinterpret_cast <CustomDialog*> (lParam);
		pDlg->hDlg = hDlg;

		::SetWindowLong(pDlg->hDlg, GWL_USERDATA, reinterpret_cast <long> (pDlg));
	}
	else
	{
		pDlg = reinterpret_cast <CustomDialog*> (::GetWindowLong(hDlg, GWL_USERDATA)); 
	}

	if (pDlg != NULL)
		pDlg->DlgProc(uMsg, wParam, lParam);

	return FALSE;
}

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CustomDialog::CustomDialog()
{
	this->hDlg = 0;
	this->hParent = 0;
	this->hInstance = 0;
	this->dwResourceDlg = 0;
}

CustomDialog::~CustomDialog()
{
}

UINT CustomDialog::ShowModal(HINSTANCE hInst, HWND hParent)
{
	this->hInstance = hInst;
	this->hParent = hParent;

	return ::DialogBoxParam(this->hInstance, MAKEINTRESOURCE(this->dwResourceDlg), this->hParent, (DLGPROC)CustomDialog::StaticProc, (LPARAM)this);
}

UINT CustomDialog::ShowModalless(HINSTANCE hInst, HWND hParent)
{
	this->hInstance = hInst;
	this->hParent = hParent;

	this->hDlg = CreateDialogParam(this->hInstance, MAKEINTRESOURCE(this->dwResourceDlg), this->hParent, (DLGPROC)CustomDialog::StaticProc, (LPARAM)this);
	::ShowWindow(this->hDlg, SW_SHOW);
	
	if (hDlg != NULL)
		return IDOK;
	
	return IDCANCEL;
}

VOID CustomDialog::Resize(UINT x, UINT y, UINT width, UINT height)
{
	::MoveWindow(this->hDlg, x, y, width, height, TRUE);
}

HWND CustomDialog::GetDlgItemHandle(DWORD dwDlgItem)
{
	return ::GetDlgItem(this->hDlg, dwDlgItem);
}

VOID CustomDialog::DlgProc(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_COMMAND:
		{
			switch (wParam)
			{
			case IDCANCEL:
				{
					EndDialog(this->hDlg, IDCANCEL);
					break;
				}
			case IDOK:
				{
					EndDialog(this->hDlg, IDOK);
					break;
				}
			}
			break;
		}

	case WM_CLOSE:
		{
			EndDialog(this->hDlg, IDOK);
			break;
		}
	}
}

UINT CustomDialog::Height()
{
	RECT rc;

	::GetWindowRect(this->hDlg, &rc);

	return rc.bottom;
}

UINT CustomDialog::Width()
{
	RECT rc;

	::GetWindowRect(this->hDlg, &rc);

	return rc.right;
}
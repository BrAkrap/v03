#include <windows.h>
#include "nwpdlg.h"
#include "resource.h"

class MyDialog : public Dialog 
{
protected:
	int IDD()
	{ 
		return IDD_DIALOG1; 
	}
	bool OnInitDialog()
	{
		SetInt(IDC_EDIT1, p.x);
		SetInt(IDC_EDIT2, p.y);
		return true;
	}
	bool OnOK()
	{
		try {
			GetInt(IDC_EDIT1);
			GetInt(IDC_EDIT2);
		}
		catch (XCtrl&) {
			return false;
		}
		return true;
	}
	void OnCancel()	{ }
	bool OnCommand(int id, int code) { return false; }
public:
	POINT p;
};

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hp, LPSTR cmdLine, int nShow)
{
	MyDialog dlg;
	GetCursorPos(&dlg.p);
	if(dlg.DoModal(hInstance, NULL) == IDOK)
	{
		SetCursorPos(dlg.p.x, dlg.p.y);
	}
	return 0;
}

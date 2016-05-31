#ifndef _TRAYICON_H__
#define _TRAYICON_H__

class CTrayIcon
{
// Construction/destruction
public:
	CTrayIcon();
	CTrayIcon(CWnd* pWnd, UINT uCallbackMessage, LPCTSTR szTip, HICON icon, UINT uID);
	virtual ~CTrayIcon();

	//Create the tray icon
	Create(CWnd* pWnd, UINT uCallbackMessage, LPCTSTR szTip, HICON icon, UINT uID);

	//Change or retrieve the Tooltip text
	BOOL    SetTooltipText(LPCTSTR pszTooltipText);
	BOOL    SetTooltipText(UINT nID);
	CString GetTooltipText() const;

	//Change or retrieve the icon displayed
	BOOL  SetIcon(HICON hIcon);
	BOOL  SetIcon(LPCTSTR lpIconName);
	BOOL  SetIcon(UINT nIDResource);
	BOOL  SetStandardIcon(LPCTSTR lpIconName);
	BOOL  SetStandardIcon(UINT nIDResource);
	HICON GetIcon() const;
	void  RemoveIcon();

	//Change or retrieve the window to send notification messages to
	BOOL  SetNotificationWnd(CWnd* pNotifyWnd);
	CWnd* GetNotificationWnd() const;

// Implementation
protected:
	NOTIFYICONDATA	m_tnd;
};

#endif
; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CDlgConfig
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "jola.h"

ClassCount=6
Class1=CJolaApp
Class2=CJolaDlg
Class3=CAboutDlg

ResourceCount=8
Resource1=IDD_DLG_CONFIG
Resource2=IDR_MAINFRAME
Resource3=IDR_MENU
Resource4=IDD_DLG_ACCURACY
Class4=CDlgConfig
Resource5=IDD_DLG_TYPE_TOGGLE
Class5=CDlgAccuracy
Resource6=IDD_ABOUTBOX
Class6=DlgToggle
Resource7=IDD_DLG_TOGGLE
Resource8=IDD_JOLA_DIALOG

[CLS:CJolaApp]
Type=0
HeaderFile=jola.h
ImplementationFile=jola.cpp
Filter=N
LastObject=CJolaApp
BaseClass=CWinApp
VirtualFilter=AC

[CLS:CJolaDlg]
Type=0
HeaderFile=jolaDlg.h
ImplementationFile=jolaDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CJolaDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=jolaDlg.h
ImplementationFile=jolaDlg.cpp
Filter=D
LastObject=CAboutDlg
BaseClass=CDialog
VirtualFilter=dWC

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=10
Control1=IDC_STATIC,static,1342308480
Control2=IDC_STATIC,static,1342308352
Control3=IDOK,button,1342373889
Control4=IDC_STATIC,static,1342177283
Control5=IDC_STATIC,button,1342177287
Control6=IDC_STATIC,button,1342177287
Control7=IDC_STATIC,static,1342308864
Control8=IDC_STATIC,static,1342308864
Control9=IDC_STATIC,static,1342308864
Control10=IDC_STATIC,static,1342308864

[DLG:IDD_JOLA_DIALOG]
Type=1
Class=CJolaDlg
ControlCount=8
Control1=IDC_BN_HIDE,button,1342242816
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1350570510
Control4=IDC_LABEL,static,1342308865
Control5=IDC_STATIC,static,1350701708
Control6=IDC_STATIC,static,1342308865
Control7=IDC_BN_CONFIG,button,1342242816
Control8=IDC_BN_HELP,button,1342242816

[MNU:IDR_MENU]
Type=1
Class=?
Command1=IDC_VIEW_WINDOW
Command2=IDC_TRAY_EXIT
CommandCount=2

[DLG:IDD_DLG_CONFIG]
Type=1
Class=CDlgConfig
ControlCount=33
Control1=IDC_CHK_SWITCH_TOGGLE,button,1342242819
Control2=IDC_EDT_AREA,edit,1350641793
Control3=IDC_SPIN_TOGGLE,msctls_updown32,1342177334
Control4=IDOK,button,1342242817
Control5=IDCANCEL,button,1342242816
Control6=IDC_CMB_STARTKEY,combobox,1344339971
Control7=IDC_CMB_ENDKEY,combobox,1344339971
Control8=IDC_SCRSPEED,scrollbar,1342177280
Control9=IDC_CMB_TOGGLEKEY,combobox,1344339971
Control10=IDC_STATIC,static,1342308865
Control11=IDC_STATIC,static,1342308865
Control12=IDC_LBL_KEY_START,static,1342308865
Control13=IDC_LBL_KEY_END,static,1342308865
Control14=IDC_STATIC,button,1342177287
Control15=IDC_LBL_TOGGLERANGE,static,1342308865
Control16=IDC_LBL_TOGGLEKEY,static,1342308865
Control17=IDC_STATIC,button,1342177287
Control18=IDC_CHK_SWITCH_AUTO,button,1342242819
Control19=IDC_EDT_LOOP,edit,1350641793
Control20=IDC_SPIN_LOOP,msctls_updown32,1342177334
Control21=IDC_LBL_TOGGLECOUNT,static,1342308865
Control22=IDC_STATIC,button,1342177287
Control23=IDC_RAD_KEY,button,1342308361
Control24=IDC_RAD_MOUSE,button,1342177289
Control25=IDC_CHK_TOGGLE_MOUSECLICK,button,1342242819
Control26=IDC_STATIC,button,1342177287
Control27=IDC_TXT_SPEED,static,1342308865
Control28=IDC_TXT_THETA,static,1342308865
Control29=IDC_CHK_F12,button,1073811459
Control30=IDC_BN_ACCURACY,button,1342242816
Control31=IDC_BN_TOGGLESTART,button,1476460544
Control32=IDC_TXT_TOGGLESTART,static,1342308865
Control33=IDC_CMB_TYPE,combobox,1344339971

[CLS:CDlgConfig]
Type=0
HeaderFile=DlgConfig.h
ImplementationFile=DlgConfig.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_CMB_TYPE
VirtualFilter=dWC

[DLG:IDD_DLG_ACCURACY]
Type=1
Class=CDlgAccuracy
ControlCount=6
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_RAD_ACCURACY,button,1342308361
Control4=IDC_RAD_ACCURACY_NORMAL,button,1342177289
Control5=IDC_RAD_ACCURACY_LOW,button,1342177289
Control6=IDC_STATIC,button,1342177287

[CLS:CDlgAccuracy]
Type=0
HeaderFile=DlgAccuracy.h
ImplementationFile=DlgAccuracy.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_RAD_ACCURACY
VirtualFilter=dWC

[DLG:IDD_DLG_TOGGLE]
Type=1
Class=DlgToggle
ControlCount=10
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_CMB_TOGGLEKEY,combobox,1344339971
Control4=IDC_LBL_TOGGLEKEY,static,1342308865
Control5=IDC_STATIC,button,1342177287
Control6=IDC_RAD_KEY,button,1342308361
Control7=IDC_RAD_MOUSE,button,1342177289
Control8=IDC_CHK_TOGGLE_MOUSECLICK,button,1342246915
Control9=IDC_STATIC,button,1342177287
Control10=IDC_STATIC,button,1342177287

[CLS:DlgToggle]
Type=0
HeaderFile=DlgToggle.h
ImplementationFile=DlgToggle.cpp
BaseClass=CDialog
Filter=D

[DLG:IDD_DLG_TYPE_TOGGLE]
Type=1
Class=?
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,button,1342177287


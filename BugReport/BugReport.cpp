// BugReport.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "StdAfx.h"
#include "CBugReportWnd.h"
#include "vld.h"

CBugReportWnd::CBugReportWnd(void)
{

}

CBugReportWnd::~CBugReportWnd(void)
{

}

LPCTSTR CBugReportWnd::GetWindowClassName() const
{
    return (LPCTSTR)"test";
}

void CBugReportWnd::Notify(TNotifyUI& msg)
{
    if(msg.sType == _T("click"))
    {
        if(msg.pSender->GetName() == _T("btnClose")
            || msg.pSender->GetName() == _T("btnOk"))
        {
            Close();
        }
    }
}

LRESULT CBugReportWnd::HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    LRESULT lRes = 0;
    BOOL bHandled = TRUE;

    if(uMsg == WM_CREATE)
    {
        m_pm.Init(m_hWnd);
        CDialogBuilder builder;
        CControlUI *pRoot = builder.Create(_T("UISkin1.xml"), (UINT)0, NULL, &m_pm); //加载的XML文件的名称
        ASSERT(pRoot && "Failed to parse XML");
        m_pm.AttachDialog(pRoot);
        m_pm.AddNotifier(this);

        return 0;
    }
    else if( uMsg == WM_DESTROY )
    {
        ::PostQuitMessage(0);
    }

    if( m_pm.MessageHandler(uMsg, wParam, lParam, lRes) )
    {
        return lRes;
    }

    return CWindowWnd::HandleMessage(uMsg, wParam, lParam);
}



int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE /*hPrevInstance*/, LPSTR /*lpCmdLine*/, int nCmdShow)
{
    CPaintManagerUI::SetInstance(hInstance);
    CPaintManagerUI::SetResourcePath(CPaintManagerUI::GetInstancePath() + _T("skin\\BugReport"));

    HRESULT Hr = ::CoInitialize(NULL);
    if( FAILED(Hr) ) return 0;

    CBugReportWnd* pFrame = new CBugReportWnd();

    if( pFrame == NULL )
    {
        return 0;
    }

    pFrame->Create(NULL, _T("BugReport"), /*UI_WNDSTYLE_FRAME*/UI_WNDSTYLE_DIALOG & (~( WS_BORDER | WS_CAPTION )), 0L, 0, 0, 800, 572);
    pFrame->CenterWindow();
    ::ShowWindow(*pFrame, SW_SHOW);

    CPaintManagerUI::MessageLoop();

    ::CoUninitialize();
    return 0;
}


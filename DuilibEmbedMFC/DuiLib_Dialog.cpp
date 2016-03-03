#include "StdAfx.h"
#include "DuiLib_Dialog.h"

DuiLib_Dialog::DuiLib_Dialog(void)
{

}

DuiLib_Dialog::~DuiLib_Dialog(void)
{

}

LPCTSTR DuiLib_Dialog::GetWindowClassName() const
{
    return (LPCTSTR)"test";
}

void DuiLib_Dialog::Notify(TNotifyUI& msg)
{
    if(msg.sType == _T("click"))
    {
        if(msg.pSender->GetName() == _T("btnClose")
            || msg.pSender->GetName() == _T("btnOk"))
        {
            ShowWindow(false);
        }
    }
}

LRESULT DuiLib_Dialog::HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    LRESULT lRes = 0;
    BOOL bHandled = TRUE;

    if(uMsg == WM_CREATE)
    {
        CPaintManagerUI::SetInstance(AfxGetInstanceHandle());//����XML��ʱ����Ҫʹ�øþ��ȥ��λEXE��·�������ܼ���XML��·��
        CPaintManagerUI::SetResourcePath(CPaintManagerUI::GetInstancePath() + _T("skin\\DuilibEmbedMFC"));//��λͼƬ����Դ��λ��
        //CPaintManagerUI::SetResourceZip(_T("DuilibEmbedMFC.zip"));

        m_pm.Init(m_hWnd);
        CDialogBuilder builder;
        CControlUI *pRoot = builder.Create(_T("UISkin1.xml"), (UINT)0, NULL, &m_pm); //���ص�XML�ļ�������
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

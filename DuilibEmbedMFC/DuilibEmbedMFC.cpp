// DuilibEmbedMFC.cpp : ����Ӧ�ó��������Ϊ��
//

#include "stdafx.h"
#include "DuilibEmbedMFC.h"
#include "DuilibEmbedMFCDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDuilibEmbedMFCApp
BEGIN_MESSAGE_MAP(CDuilibEmbedMFCApp, CWinApp)
    ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CDuilibEmbedMFCApp ����
CDuilibEmbedMFCApp::CDuilibEmbedMFCApp()
{
    // TODO: �ڴ˴���ӹ�����룬
    // ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CDuilibEmbedMFCApp ����
CDuilibEmbedMFCApp theApp;


// CDuilibEmbedMFCApp ��ʼ��
BOOL CDuilibEmbedMFCApp::InitInstance()
{
    // ���һ�������� Windows XP �ϵ�Ӧ�ó����嵥ָ��Ҫ
    // ʹ�� ComCtl32.dll �汾 6 ����߰汾�����ÿ��ӻ���ʽ��
    //����Ҫ InitCommonControlsEx()�����򣬽��޷��������ڡ�
    INITCOMMONCONTROLSEX InitCtrls;
    InitCtrls.dwSize = sizeof(InitCtrls);
    // ��������Ϊ��������Ҫ��Ӧ�ó�����ʹ�õ�
    // �����ؼ��ࡣ
    InitCtrls.dwICC = ICC_WIN95_CLASSES;
    InitCommonControlsEx(&InitCtrls);

    CWinApp::InitInstance();

    AfxEnableControlContainer();

    // ��׼��ʼ��
    // ���δʹ����Щ���ܲ�ϣ����С
    // ���տ�ִ���ļ��Ĵ�С����Ӧ�Ƴ�����
    // ����Ҫ���ض���ʼ������
    // �������ڴ洢���õ�ע�����
    // TODO: Ӧ�ʵ��޸ĸ��ַ�����
    // �����޸�Ϊ��˾����֯
    SetRegistryKey(_T("Ӧ�ó��������ɵı���Ӧ�ó���"));

    //DuiLib::CPaintManagerUI::SetInstance(this->m_hInstance);
    //DuiLib::CPaintManagerUI::SetResourcePath(DuiLib::CPaintManagerUI::GetInstancePath() + _T("skin"));
    //CPaintManagerUI::SetResourceZip(_T("DuilibEmbedMFC.zip"));

    CDuilibEmbedMFCDlg dlg;
    m_pMainWnd = &dlg;
    INT_PTR nResponse = dlg.DoModal();
    if (nResponse == IDOK)
    {
        // TODO: �ڴ˷��ô����ʱ��
        //  ��ȷ�������رնԻ���Ĵ���
    }
    else if (nResponse == IDCANCEL)
    {
        // TODO: �ڴ˷��ô����ʱ��
        //  ��ȡ�������رնԻ���Ĵ���
    }

    // ���ڶԻ����ѹر�,���Խ����� FALSE �Ա��˳�Ӧ�ó���,
    // ����������Ӧ�ó������Ϣ�á�
    return FALSE;
}

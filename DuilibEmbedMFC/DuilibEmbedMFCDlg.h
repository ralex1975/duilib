// DuilibEmbedMFCDlg.h : ͷ�ļ�
//

#pragma once

#include "DuiLib_Dialog.h"

// CDuilibEmbedMFCDlg �Ի���
class CDuilibEmbedMFCDlg : public CDialog
{
// ����
public:
	CDuilibEmbedMFCDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_DUILIBEMBEDMFC_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;
	DuiLib_Dialog  m_dlgDuilib;
	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

		
public:
	afx_msg void OnBnClickedOk();
};

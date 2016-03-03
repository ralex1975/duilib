#pragma once

class CBugReportWnd : public CWindowWnd, INotifyUI
{
public:
    CBugReportWnd(void);
    ~CBugReportWnd(void);

public:  
    LPCTSTR GetWindowClassName() const;
    void    Notify(TNotifyUI& msg);
    LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);
    LRESULT OnCreate(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);

private:
    CPaintManagerUI m_pm;
};

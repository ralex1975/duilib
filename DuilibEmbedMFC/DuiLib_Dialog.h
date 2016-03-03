#pragma once

class DuiLib_Dialog : public CWindowWnd, INotifyUI
{
public:
    DuiLib_Dialog(void);
    ~DuiLib_Dialog(void);

public:  
    LPCTSTR GetWindowClassName() const;
    void    Notify(TNotifyUI& msg);
    LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);
    LRESULT OnCreate(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);

private:
    CPaintManagerUI m_pm;
};


// FDMView.h : CFDMView ��Ľӿ�
//

#pragma once


class CFDMView : public CView
{
protected: // �������л�����
	CFDMView();
	DECLARE_DYNCREATE(CFDMView)

// ����
public:
	CFDMDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CFDMView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // FDMView.cpp �еĵ��԰汾
inline CFDMDoc* CFDMView::GetDocument() const
   { return reinterpret_cast<CFDMDoc*>(m_pDocument); }
#endif


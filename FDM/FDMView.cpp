
// FDMView.cpp : CFDMView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "FDM.h"
#endif

#include "FDMDoc.h"
#include "FDMView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CFDMView

IMPLEMENT_DYNCREATE(CFDMView, CView)

BEGIN_MESSAGE_MAP(CFDMView, CView)
END_MESSAGE_MAP()

// CFDMView ����/����

CFDMView::CFDMView()
{
	// TODO:  �ڴ˴���ӹ������

}

CFDMView::~CFDMView()
{
}

BOOL CFDMView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CFDMView ����

void CFDMView::OnDraw(CDC* /*pDC*/)
{
	CFDMDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CFDMView ���

#ifdef _DEBUG
void CFDMView::AssertValid() const
{
	CView::AssertValid();
}

void CFDMView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CFDMDoc* CFDMView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CFDMDoc)));
	return (CFDMDoc*)m_pDocument;
}
#endif //_DEBUG


// CFDMView ��Ϣ�������

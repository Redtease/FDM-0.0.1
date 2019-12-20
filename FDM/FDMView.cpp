
// FDMView.cpp : CFDMView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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

// CFDMView 构造/析构

CFDMView::CFDMView()
{
	// TODO:  在此处添加构造代码

}

CFDMView::~CFDMView()
{
}

BOOL CFDMView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CFDMView 绘制

void CFDMView::OnDraw(CDC* /*pDC*/)
{
	CFDMDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  在此处为本机数据添加绘制代码
}


// CFDMView 诊断

#ifdef _DEBUG
void CFDMView::AssertValid() const
{
	CView::AssertValid();
}

void CFDMView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CFDMDoc* CFDMView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CFDMDoc)));
	return (CFDMDoc*)m_pDocument;
}
#endif //_DEBUG


// CFDMView 消息处理程序

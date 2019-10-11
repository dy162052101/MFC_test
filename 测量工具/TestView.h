
// TestView.h : interface of the CTestView class
//

#pragma once
#include"P2.h"

class CTestView : public CView
{
protected: // create from serialization only
	CTestView();
	DECLARE_DYNCREATE(CTestView)

// Attributes
public:
	CTestDoc* GetDocument() const;

// Operations
public:
	void DrawNurbsCurve(CDC* pDC);//����NURBS����
	void DrawControlPolygon(CP2 p[],CDC* pDC);//���ƿ��Ƶ�
	void GetKnotVector();//��ȡ�ڵ�ʸ��
	double GetBasisFunctionValue(double t, int i, int k);//����B����������
	void DoubleBuffer(CDC*pDC);
	void Draw(CDC*pDC);
// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CTestView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	BOOL	m_AbleToLeftBtn;//new
	BOOL	m_AbleToMove;//new
	int		m_i;//new

	CRect rect;
	CBitmap NewBitmap, *pOldBitmap;
	int gk;

	CP2 P[20];//���Ƶ�
	double W[20];//Ȩ����
	double knot[20];//�ڵ�����
	int n;//���Ƶ���-1
    int k;//����
// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // debug version in TestView.cpp
inline CTestDoc* CTestView::GetDocument() const
   { return reinterpret_cast<CTestDoc*>(m_pDocument); }
#endif


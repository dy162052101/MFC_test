
// TestView.cpp : implementation of the CTestView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Test.h"
#endif
#include<math.h>
#define ROUND(d) int(d+0.5)//四舍五入宏定义
#include "TestDoc.h"
#include "TestView.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTestView

IMPLEMENT_DYNCREATE(CTestView, CView)

BEGIN_MESSAGE_MAP(CTestView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CTestView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CTestView construction/destruction

CTestView::CTestView()
{
	// TODO: add construction code here
	m_AbleToLeftBtn=FALSE;
	m_AbleToMove=FALSE;
	m_i=-1;

	n=9,k=3;

	P[0].x=681;   P[0].y=317;//控制点
	P[1].x=200+681; 
	P[1].y=100+317;

	P[2].x=300+681;  
	P[2].y=100+317;

	P[3].x=300+681; 
	P[3].y=200+317;

	P[4].x=160+681; 
	P[4].y=-60+317;

	P[5].x=320+681;  
	P[5].y=-10+317;

	P[6].x=80+681;  
	P[6].y=20+317;

	P[7].x=-80+681; 
	P[7].y=-20+317;

	P[8].x=100+681;  
	P[8].y=80+317;

	P[9].x=120+681; 
	P[9].y=100+317;

	W[0]=1.0,W[1]=2.0,W[2]=2.0,W[3]=2.0,W[4]=2.0,W[5]=2.0,W[6]=2.0,W[7]=2.0;
	W[8]=2.0,W[9]=1.0;//权因子
}

CTestView::~CTestView()
{
}
BOOL CTestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CTestView drawing

void CTestView::OnDraw(CDC* pDC)
{
	CTestDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CRect rect;//定义 客户区矩形
	GetClientRect(&rect);//获得客户区的大小
	CDC memDC;//内存DC
	memDC.CreateCompatibleDC(pDC);//创建一个与显示pDC兼容的内存memDC
	CBitmap NewBitmap,*pOldBitmap;//内存中承载的临时位图 
	NewBitmap.CreateCompatibleBitmap(pDC,rect.Width(),rect.Height());//创建兼容位图 
	pOldBitmap=memDC.SelectObject(&NewBitmap);//将兼容位图选入memDC 
	/*memDC.FillSolidRect(rect,pDC->GetBkColor());*///按原来背景填充客户区，否则是黑色
	//memDC.SetMapMode(MM_ANISOTROPIC);//memDC自定义坐标系
	//memDC.SetWindowExt(rect.Width(),rect.Height());
	//memDC.SetViewportExt(rect.Width(),-rect.Height());
	//memDC.SetViewportOrg(rect.Width(),-rect.Height());
	//rect.OffsetRect(-rect.Width()/2,-rect.Height()/2);
	double x=5;

	memDC.TextOut(P[0].x,P[0].y,_T("first"));
	memDC.TextOut(P[1].x,P[1].y,_T("second"));
	memDC.TextOut(P[2].x,P[2].y,_T("third"));
	memDC.TextOut(P[3].x,P[3].y,_T("forth"));
	memDC.TextOut(P[4].x,P[4].y,_T("fifth"));
	memDC.TextOut(P[5].x,P[5].y,_T("sixth"));
	memDC.TextOut(P[6].x,P[6].y,_T("seventh"));
	memDC.TextOut(P[7].x,P[7].y,_T("eighth"));
	memDC.TextOut(P[8].x,P[8].y,_T("ninth"));
	memDC.TextOut(P[9].x,P[9].y,_T("tenth"));
	memDC.TextOut(P[10].x,P[10].y,_T("eleventh"));
	memDC.TextOut(P[11].x,P[11].y,_T("twelveth"));
	memDC.TextOut(P[12].x,P[12].y,_T("threeteenth"));
	memDC.TextOut(P[13].x,P[13].y,_T("forteenth"));

	Draw(&memDC);

	pDC->BitBlt(0,0,rect.Width(),rect.Height(),&memDC,0,0,SRCCOPY);//将内存memDC中的位图拷贝到显示pDC中
	memDC.SelectObject(pOldBitmap);//恢复位图
	NewBitmap.DeleteObject();//删除位图
}


// CTestView printing


void CTestView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CTestView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CTestView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CTestView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CTestView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CTestView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CTestView diagnostics

#ifdef _DEBUG
void CTestView::AssertValid() const
{
	CView::AssertValid();
}

void CTestView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTestDoc* CTestView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTestDoc)));
	return (CTestDoc*)m_pDocument;
}
#endif //_DEBUG


// CTestView message handlers
void CTestView::DrawNurbsCurve(CDC* pDC)//绘制NURBS曲线
{
	CPen NewPen,*pOldPen;
	NewPen.CreatePen(PS_SOLID,5,RGB(255,100,50));//曲线颜色
	pOldPen=pDC->SelectObject(&NewPen);	
	double tStep=0.01;
    for(double t=0.0;t<=1.0;t+=tStep)
	{	
		CP2 p(0.0,0.0);
		double denominator=0.0;
		for(int i=0;i<=n;i++)
		{	
			double BValue=GetBasisFunctionValue(t,i,k);			
			p+=P[i]*BValue*W[i];
			denominator+=BValue*W[i];
		}
		p/=denominator;//NURBS曲线定义
		if(0.0==t)
			pDC->MoveTo(ROUND(p.x),ROUND(p.y));
		else
			pDC->LineTo(ROUND(p.x),ROUND(p.y));
	}  
	pDC->SelectObject(pOldPen);
	NewPen.DeleteObject();
}

void CTestView::DrawControlPolygon(CP2 p[],CDC* pDC)//绘制控制多边形
{
	CPen NewPen,*pOldPen;
	NewPen.CreatePen(PS_SOLID,1,RGB(0,0,255));
	pOldPen=pDC->SelectObject(&NewPen);
	CBrush NewBrush,*pOldBrush;
	NewBrush.CreateSolidBrush(RGB(0,0,255));
	pOldBrush=pDC->SelectObject(&NewBrush);
	for(int i=0;i<=n;i++)
	{
		if(0==i)
		{
			pDC->MoveTo(ROUND(p[i].x),ROUND(p[i].y));
			pDC->Ellipse(ROUND(p[i].x)-5,ROUND(p[i].y)-5,ROUND(p[i].x)+5,ROUND(p[i].y)+5);
		}
		else
		{
			pDC->LineTo(ROUND(p[i].x),ROUND(p[i].y));
			pDC->Ellipse(ROUND(p[i].x)-5,ROUND(p[i].y)-5,ROUND(p[i].x)+5,ROUND(p[i].y)+5);
		}
	}
	pDC->SelectObject(pOldBrush);
	pDC->SelectObject(pOldPen);
}

void CTestView::GetKnotVector()//哈德利-贾德方法获取节点值
{
   for(int i=0;i<=k;i++) //小于次数k的节点值为0
      knot[i]=0.0;
   for(int i=n+1;i<=n+k+1;i++)//大于n的节点值为1
       knot[i]=1.0;
   //计算n-k个内节点
   for(int i=k+1;i<=n;i++)
   {
	   double sum=0.0;
	   for(int j=k+1;j<=i;j++)//公式（5-24）
	   { 
		   double numerator=0.0;//计算分子
		   for(int loop=j-k;loop<=j-1;loop++)
		   {
			   numerator+=sqrt((P[loop].x-P[loop-1].x)*(P[loop].x-P[loop-1].x)+(P[loop].y-P[loop-1].y)*(P[loop].y-P[loop-1].y));//计算两个点之间的距离
		   }
		   double denominator=0.0;//计算分母
		   for(int loop1=k+1;loop1<=n+1;loop1++)
		   {
			   for(int loop2=loop1-k;loop2<=loop1-1;loop2++)
			   {
				   denominator+=sqrt((P[loop2].x-P[loop2-1].x)*(P[loop2].x-P[loop2-1].x)+(P[loop2].y-P[loop2-1].y)*(P[loop2].y-P[loop2-1].y));//计算两个点之间的距离
				}
		   }	
		   sum+=numerator/denominator;//计算节点值
	   } 
       knot[i]=sum;
   }
}

double CTestView::GetBasisFunctionValue(double t, int i, int k)//根据参数t值和次数k与节点矢量knot，计算第i个k次的B样条基函数
{
	double value1,value2,value;
	if(k==0)
	{
		if(t>=knot[i] && t<knot[i+1])
			return 1.0;
		else
			return 0.0;
	}
	if(k>0)
	{
		if(t<knot[i]||t>knot[i+k+1])
			return 0.0;
		else
		{
			double coffcient1,coffcient2;//凸组合系数1，凸组合系数2
			double denominator=0.0;//分母
			denominator=knot[i+k]-knot[i];//递推公式第一项分母
			if(denominator==0.0)//约定0/0
				coffcient1=0.0;
			else
				coffcient1=(t-knot[i])/denominator;
			denominator=knot[i+k+1]-knot[i+1];//递推公式第二项分母
			if(0.0==denominator)//约定0/0
				coffcient2=0.0;
			else
				coffcient2=(knot[i+k+1]-t)/denominator;
			value1=coffcient1*GetBasisFunctionValue(t,i,k-1);//递推公式第一项的值
			value2=coffcient2*GetBasisFunctionValue(t,i+1,k-1);//递推公式第二项的值
			value=value1+value2;//基函数的值
		}
	}
	return value;
}
void CTestView::DoubleBuffer(CDC*pDC)
{
	CRect rect;//定义客户区矩形
	GetClientRect(&rect);//获得客户区的大小
	pDC->SetMapMode(MM_ANISOTROPIC);//pDC自定义坐标系
	pDC->SetWindowExt(rect.Width(),rect.Height());//设置窗口范围
	pDC->SetViewportExt(rect.Width(),-rect.Height());//设置视区范围,x轴水平向右，y轴垂直向上
	pDC->SetViewportOrg(rect.Width()/2,rect.Height()/2);//客户区中心为原点
	CDC memDC;//内存DC
	memDC.CreateCompatibleDC(pDC);//创建一个与显示pDC兼容的内存memDC
	CBitmap NewBitmap,*pOldBitmap;//内存中承载的临时位图 
	NewBitmap.CreateCompatibleBitmap(pDC,rect.Width(),rect.Height());//创建兼容位图 
	pOldBitmap=memDC.SelectObject(&NewBitmap);//将兼容位图选入memDC 
	memDC.FillSolidRect(rect,RGB(255,0,0));//按原来背景填充客户区，否则是黑色
	memDC.SetMapMode(MM_ANISOTROPIC);//memDC自定义坐标系
	memDC.SetWindowExt(rect.Width(),rect.Height());
	memDC.SetViewportExt(rect.Width(),-rect.Height());
	memDC.SetViewportOrg(rect.Width()/2,rect.Height()/2);
	rect.OffsetRect(-rect.Width()/2,-rect.Height()/2);
	Draw(&memDC);//向memDC绘制图形
	pDC->BitBlt(rect.left,rect.top,rect.Width(),rect.Height(),&memDC,-rect.Width()/2,-rect.Height()/2,SRCCOPY);//将内存memDC中的位图拷贝到显示pDC中
	memDC.SelectObject(pOldBitmap);//恢复位图
	NewBitmap.DeleteObject();//删除位图
}
void CTestView::Draw(CDC*pDC)
{
	//CDC memDC;//内存DC
	//memDC.CreateCompatibleDC(pDC);//创建一个与显示pDC兼容的内存memDC
	CRect rect;//定义客户区矩形
	GetClientRect(&rect);//获得客户区的大小
	double x,y;
	x=5;
	y=5;
	CPen NewPen,*pOldPen;
	NewPen.CreatePen(PS_SOLID,3,RGB(255,255,0));
	pOldPen=pDC->SelectObject(&NewPen);
	pDC->MoveTo(rect.Width()/2,rect.Height()/2);
	pDC->Ellipse(P[0].x+x,P[0].y-x,P[0].x-x,P[0].y+x);
	for(int i=0;i<n+1;i++)
	{
		pDC->MoveTo(P[i].x,P[i].y);
		pDC->Ellipse(P[i].x+x,P[i].y-x,P[i].x-x,P[i].y+x);
	}

	GetKnotVector();
	DrawNurbsCurve(pDC);
	DrawControlPolygon(P,pDC);

	pDC->SelectObject(&pOldPen);

	
		if(m_i!=-1)
	{
		CString	str;
		str.Format(_T("x=%f y=%f"),P[m_i].x-rect.Width()/2,-(P[m_i].y-rect.Height()/2));
		pDC->TextOut(P[m_i].x,P[m_i].y,str);
	}

	double a=rect.Width()/2;
	double b=rect.Height()/2;
	pDC->MoveTo(a,b);
	pDC->LineTo(a,2*b);
	pDC->MoveTo(a,b);
	pDC->LineTo(a,0);
	pDC->MoveTo(a,b);
	pDC->LineTo(0,b);
	pDC->MoveTo(a,b);
	pDC->LineTo(2*a,b);

}

void CTestView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if(TRUE==m_AbleToLeftBtn)
	{
		m_AbleToMove=TRUE;
	}
	CView::OnLButtonDown(nFlags, point);
}


void CTestView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	m_AbleToLeftBtn=false;
	m_AbleToMove=false;
	m_i=0;
	CView::OnLButtonUp(nFlags, point);
}


void CTestView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	int px;
	px=point.x;
	int py;
	py=point.y;
	if(m_AbleToMove==TRUE)
	{
		P[m_i].x=px;
		P[m_i].y=py;
	}
	int i;
	m_i=-1;
	for( i=0;i<n+1;i++)
	{
		if((px-P[i].x)*(px-P[i].x)
			+(py-P[i].y)*(py-P[i].y)<100)
		{
			m_i=i;
			m_AbleToLeftBtn=TRUE;
			SetCursor(LoadCursor(NULL,IDC_SIZEALL));
			break;
		}

	}
	
	if(10==i)
	{
		m_i=-1;
	}
	Invalidate(false);	
	CView::OnMouseMove(nFlags, point);
}

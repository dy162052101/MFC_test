
// TestView.cpp : implementation of the CTestView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Test.h"
#endif
#include<math.h>
#define ROUND(d) int(d+0.5)//��������궨��
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

	P[0].x=681;   P[0].y=317;//���Ƶ�
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
	W[8]=2.0,W[9]=1.0;//Ȩ����
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
	CRect rect;//���� �ͻ�������
	GetClientRect(&rect);//��ÿͻ����Ĵ�С
	CDC memDC;//�ڴ�DC
	memDC.CreateCompatibleDC(pDC);//����һ������ʾpDC���ݵ��ڴ�memDC
	CBitmap NewBitmap,*pOldBitmap;//�ڴ��г��ص���ʱλͼ 
	NewBitmap.CreateCompatibleBitmap(pDC,rect.Width(),rect.Height());//��������λͼ 
	pOldBitmap=memDC.SelectObject(&NewBitmap);//������λͼѡ��memDC 
	/*memDC.FillSolidRect(rect,pDC->GetBkColor());*///��ԭ���������ͻ����������Ǻ�ɫ
	//memDC.SetMapMode(MM_ANISOTROPIC);//memDC�Զ�������ϵ
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

	pDC->BitBlt(0,0,rect.Width(),rect.Height(),&memDC,0,0,SRCCOPY);//���ڴ�memDC�е�λͼ��������ʾpDC��
	memDC.SelectObject(pOldBitmap);//�ָ�λͼ
	NewBitmap.DeleteObject();//ɾ��λͼ
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
void CTestView::DrawNurbsCurve(CDC* pDC)//����NURBS����
{
	CPen NewPen,*pOldPen;
	NewPen.CreatePen(PS_SOLID,5,RGB(255,100,50));//������ɫ
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
		p/=denominator;//NURBS���߶���
		if(0.0==t)
			pDC->MoveTo(ROUND(p.x),ROUND(p.y));
		else
			pDC->LineTo(ROUND(p.x),ROUND(p.y));
	}  
	pDC->SelectObject(pOldPen);
	NewPen.DeleteObject();
}

void CTestView::DrawControlPolygon(CP2 p[],CDC* pDC)//���ƿ��ƶ����
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

void CTestView::GetKnotVector()//������-�ֵ·�����ȡ�ڵ�ֵ
{
   for(int i=0;i<=k;i++) //С�ڴ���k�Ľڵ�ֵΪ0
      knot[i]=0.0;
   for(int i=n+1;i<=n+k+1;i++)//����n�Ľڵ�ֵΪ1
       knot[i]=1.0;
   //����n-k���ڽڵ�
   for(int i=k+1;i<=n;i++)
   {
	   double sum=0.0;
	   for(int j=k+1;j<=i;j++)//��ʽ��5-24��
	   { 
		   double numerator=0.0;//�������
		   for(int loop=j-k;loop<=j-1;loop++)
		   {
			   numerator+=sqrt((P[loop].x-P[loop-1].x)*(P[loop].x-P[loop-1].x)+(P[loop].y-P[loop-1].y)*(P[loop].y-P[loop-1].y));//����������֮��ľ���
		   }
		   double denominator=0.0;//�����ĸ
		   for(int loop1=k+1;loop1<=n+1;loop1++)
		   {
			   for(int loop2=loop1-k;loop2<=loop1-1;loop2++)
			   {
				   denominator+=sqrt((P[loop2].x-P[loop2-1].x)*(P[loop2].x-P[loop2-1].x)+(P[loop2].y-P[loop2-1].y)*(P[loop2].y-P[loop2-1].y));//����������֮��ľ���
				}
		   }	
		   sum+=numerator/denominator;//����ڵ�ֵ
	   } 
       knot[i]=sum;
   }
}

double CTestView::GetBasisFunctionValue(double t, int i, int k)//���ݲ���tֵ�ʹ���k��ڵ�ʸ��knot�������i��k�ε�B����������
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
			double coffcient1,coffcient2;//͹���ϵ��1��͹���ϵ��2
			double denominator=0.0;//��ĸ
			denominator=knot[i+k]-knot[i];//���ƹ�ʽ��һ���ĸ
			if(denominator==0.0)//Լ��0/0
				coffcient1=0.0;
			else
				coffcient1=(t-knot[i])/denominator;
			denominator=knot[i+k+1]-knot[i+1];//���ƹ�ʽ�ڶ����ĸ
			if(0.0==denominator)//Լ��0/0
				coffcient2=0.0;
			else
				coffcient2=(knot[i+k+1]-t)/denominator;
			value1=coffcient1*GetBasisFunctionValue(t,i,k-1);//���ƹ�ʽ��һ���ֵ
			value2=coffcient2*GetBasisFunctionValue(t,i+1,k-1);//���ƹ�ʽ�ڶ����ֵ
			value=value1+value2;//��������ֵ
		}
	}
	return value;
}
void CTestView::DoubleBuffer(CDC*pDC)
{
	CRect rect;//����ͻ�������
	GetClientRect(&rect);//��ÿͻ����Ĵ�С
	pDC->SetMapMode(MM_ANISOTROPIC);//pDC�Զ�������ϵ
	pDC->SetWindowExt(rect.Width(),rect.Height());//���ô��ڷ�Χ
	pDC->SetViewportExt(rect.Width(),-rect.Height());//����������Χ,x��ˮƽ���ң�y�ᴹֱ����
	pDC->SetViewportOrg(rect.Width()/2,rect.Height()/2);//�ͻ�������Ϊԭ��
	CDC memDC;//�ڴ�DC
	memDC.CreateCompatibleDC(pDC);//����һ������ʾpDC���ݵ��ڴ�memDC
	CBitmap NewBitmap,*pOldBitmap;//�ڴ��г��ص���ʱλͼ 
	NewBitmap.CreateCompatibleBitmap(pDC,rect.Width(),rect.Height());//��������λͼ 
	pOldBitmap=memDC.SelectObject(&NewBitmap);//������λͼѡ��memDC 
	memDC.FillSolidRect(rect,RGB(255,0,0));//��ԭ���������ͻ����������Ǻ�ɫ
	memDC.SetMapMode(MM_ANISOTROPIC);//memDC�Զ�������ϵ
	memDC.SetWindowExt(rect.Width(),rect.Height());
	memDC.SetViewportExt(rect.Width(),-rect.Height());
	memDC.SetViewportOrg(rect.Width()/2,rect.Height()/2);
	rect.OffsetRect(-rect.Width()/2,-rect.Height()/2);
	Draw(&memDC);//��memDC����ͼ��
	pDC->BitBlt(rect.left,rect.top,rect.Width(),rect.Height(),&memDC,-rect.Width()/2,-rect.Height()/2,SRCCOPY);//���ڴ�memDC�е�λͼ��������ʾpDC��
	memDC.SelectObject(pOldBitmap);//�ָ�λͼ
	NewBitmap.DeleteObject();//ɾ��λͼ
}
void CTestView::Draw(CDC*pDC)
{
	//CDC memDC;//�ڴ�DC
	//memDC.CreateCompatibleDC(pDC);//����һ������ʾpDC���ݵ��ڴ�memDC
	CRect rect;//����ͻ�������
	GetClientRect(&rect);//��ÿͻ����Ĵ�С
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
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if(TRUE==m_AbleToLeftBtn)
	{
		m_AbleToMove=TRUE;
	}
	CView::OnLButtonDown(nFlags, point);
}


void CTestView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	m_AbleToLeftBtn=false;
	m_AbleToMove=false;
	m_i=0;
	CView::OnLButtonUp(nFlags, point);
}


void CTestView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
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

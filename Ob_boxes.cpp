
#include "header.h"

#include "templates.h"
#include "BaseEngine.h"
#include "Ob_boxes.h"
#include "DemoAClass.h"
#include "DisplayableObject.h"


Ob_boxes::Ob_boxes(DemoAClass* pEngine, int iMapX, int iMapY)
	:DisplayableObject(pEngine)
	,main_engine(pEngine)
	,m_iMapX(iMapX)
	,m_iMapY(iMapY)
	,m_iDir(0)
	, m_dX(iMapX)
	, m_dY(iMapY)
	, m_dSX(0)
	, m_dSY(0)
{
	m_iCurrentScreenX = m_iPreviousScreenX = 580;
	m_iCurrentScreenY = m_iPreviousScreenY = 530;

	m_iStartDrawPosX = 509;
	m_iStartDrawPosY = 336;
	m_iDrawWidth = 30;
	m_iDrawHeight = 30;
	SetVisible(true);

}


Ob_boxes::~Ob_boxes()
{
}
void Ob_boxes::Draw(void)
{
	GetEngine()->DrawScreenRectangle(m_iCurrentScreenX, m_iCurrentScreenY,
		m_iCurrentScreenX + m_iDrawWidth -1,
		m_iCurrentScreenY + m_iDrawHeight - 1,
		0x1a1a1a);
	StoreLastScreenPositionForUndraw();
}



void Ob_boxes::SetMovement(int iStartTime, int iEndTime, int iCurrentTime, int iStartX, int iStartY, int iEndX, int iEndY)
{
	m_oMovement.Setup(iStartX, iStartY, iEndX, iEndY, iStartTime, iEndTime);
	m_oMovement.Calculate(iCurrentTime);
	m_iCurrentScreenX = m_oMovement.GetX();
	m_iCurrentScreenY = m_oMovement.GetY();
}
void Ob_boxes::SetPosition(double dX, double dY)
{
	//m_dX = dX;
	//m_dY = dY;
}
void Ob_boxes::SetSpeed(double dSX, double dSY)

{
	m_dSX = dSX;
	m_dSY = dSY;
}
void Ob_boxes::DoUpdate(int iCurrentTime)
{/*
	m_oMovement.Calculate(iCurrentTime);
	m_iCurrentScreenX = m_oMovement.GetX();
	m_iCurrentScreenY = m_oMovement.GetY();
	
	/*if (m_oMovement.HasMovementFinished(iCurrentTime))
	{
		//m_oMovement.Reverse();
	
			if (m_iDrawHeight <= 100 && m_iDrawWidth <= 150) {
		m_iDrawHeight += 5;
		m_iDrawWidth += 5;
	}

	if (m_iDrawHeight == 100 && m_iDrawWidth == 150) {
		m_iDrawHeight = 30;
		m_iDrawWidth = 80;
	}


		m_oMovement.Calculate(iCurrentTime);
		m_iCurrentScreenX = m_oMovement.GetX();
		m_iCurrentScreenY = m_oMovement.GetY();
	//}
		*/
//	RedrawObjects();
	
}
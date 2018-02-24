#include "GreenBallObject.h"
#include "header.h"
#include "templates.h"
#include "BaseEngine.h"
#include "DemoAClass.h"
#include "DisplayableObject.h"

GreenBallObject::GreenBallObject(DemoAClass * pEngine, int iXLabelOffset, int iYLabelOffset)
	:DisplayableObject(pEngine), mengine_green(pEngine)
{
	m_iCurrentScreenX = m_iPreviousScreenX = 650;
	m_iCurrentScreenY = m_iPreviousScreenY = 500;
	m_iStartDrawPosX = 55;
	m_iStartDrawPosY = 55;
	m_iDrawWidth = 30;
	m_iDrawHeight = 30;
	SetVisible(true);
}

GreenBallObject::~GreenBallObject(void)
{
}

void GreenBallObject::Draw()
{
	/*int iTick = mengine_green->GetModifiedTime() / 35; // 1 per 50ms
	int iFrame = iTick % 35;
	int iSize = 0 + iFrame;
	if (iFrame > 35)
	iSize = 60 + (35 - iFrame);
	*/
	/*	if (iFrame == 0) {
	DisplayableObject*pj;
	pj = mengine_green->GetDisplayableObject(0);

	//NOTE TO SELF YOU CAN MAKE THIS MORE COMPLEX USING THE IDEA OF HAVING 3 BOXES ALWAYS AROUND THE CHAR AND REST RANDOM
	m_iCurrentScreenX = m_iPreviousScreenX = rand() % pj->GetXCentre() + 20;
	m_iCurrentScreenY = m_iPreviousScreenY = rand() % pj->GetYCentre() + 5;
	}*/

	/*if (!(m_iCurrentScreenX < 260) && !(m_iCurrentScreenX >= 1010) && !(m_iCurrentScreenY<53) && !(m_iCurrentScreenY >= 690)) {
	mengine_green->DrawScreenRectangle(m_iCurrentScreenX - m_iDrawWidth, m_iCurrentScreenY - m_iDrawHeight,
	m_iCurrentScreenX + m_iDrawWidth - 1,
	m_iCurrentScreenY + m_iDrawHeight - 1,
	0xffffff);
	}*/

	if (!IsVisible()) {
		return;
	}
	mengine_green->DrawScreenOval(m_iCurrentScreenX, m_iCurrentScreenY,
		m_iCurrentScreenX + m_iDrawWidth - 1,
		m_iCurrentScreenY + m_iDrawHeight - 1,
		0xffffff);
	StoreLastScreenPositionForUndraw();

}

void GreenBallObject::DoUpdate(int iCurrentTime)
{
	RedrawObjects();
}

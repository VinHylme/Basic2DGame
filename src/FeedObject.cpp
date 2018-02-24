#include "header.h"
#include "templates.h"
#include "BaseEngine.h"
#include "FeedObject.h"
#include "PlayerObject.h"
#include "EngineController.h"
#include "DisplayableObject.h"

FeedObject::FeedObject(EngineController *pEngine)
	:DisplayableObject(pEngine)
	, mengine_g(pEngine){


	m_iStartDrawPosX = -25;
	m_iStartDrawPosY = -25;
	m_iDrawWidth = 15;
	m_iDrawHeight = 15;
	SetVisible(true);
}

FeedObject::~FeedObject(void){}

void FeedObject::Draw()
{
	int tickint = mengine_g->GetModifiedTime() / 35; // 1 per 50ms
	int iFrame = tickint % 28;
	int iR = 5 + iFrame;
	if (iFrame > 28)
		iR = 10 + (28 - iFrame);

	if (iFrame == 0) {
		DisplayableObject*pj,*pj2;
		pj = mengine_g->GetDisplayableObject(0);
		for (int i = 1; i < 3;i++)
			pj2 = mengine_g->GetDisplayableObject(i);

		//if (m_iCurrentScreenX >= pj2->GetXCentre()) 
			//NOTE TO SELF YOU CAN MAKE THIS MORE COMPLEX USING THE IDEA OF HAVING 3 BOXES ALWAYS AROUND THE CHAR AND REST RANDOM
			m_iCurrentScreenX = m_iPreviousScreenX =  pj->GetXCentre();
		
	//	if(m_iCurrentScreenY>=pj2->GetYCentre())
			m_iCurrentScreenY = m_iPreviousScreenY = rand() % pj->GetYCentre();
	}

	if (!(m_iCurrentScreenX < 260) && !(m_iCurrentScreenX >= 1010) && !(m_iCurrentScreenY<53) && !(m_iCurrentScreenY >= 690)) {
		mengine_g->DrawScreenOval(m_iCurrentScreenX - iFrame, m_iCurrentScreenY - iFrame,
			m_iCurrentScreenX + iFrame - 1,
			m_iCurrentScreenY + iFrame - 1,
			0x33e87b);
	}

	StoreLastScreenPositionForUndraw();
}

void FeedObject::DoUpdate(int iCurrentTime){
	RedrawObjects();
}
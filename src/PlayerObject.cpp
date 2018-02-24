#include "header.h"
#include "templates.h"
#include "BaseEngine.h"
#include "PlayerObject.h"
#include "EngineController.h"
#include "DisplayableObject.h"
int getstamina = 500;
PlayerObject::PlayerObject(EngineController* pEngine, int iX,int iY)
	:DisplayableObject(pEngine), 
	m_engine(pEngine),
	m_iX(iX),
	m_iY(iY),
	m_cur(0)
{
	m_iStartDrawPosX = 55;
	m_iStartDrawPosY = 55;
	m_iDrawWidth = 60;
	m_iDrawHeight = 60;
	m_iPreviousScreenX = m_iCurrentScreenX = iX * 50+50;
	m_iPreviousScreenY = m_iCurrentScreenY = iY * 50+65;

	SetVisible(true);
}


PlayerObject::~PlayerObject(void)
{
}


void PlayerObject::Draw(void)
{
	if (!IsVisible()) {
		return;
	}
		m_engine->DrawScreenOval(m_iCurrentScreenX, m_iCurrentScreenY,
		m_iCurrentScreenX + m_iDrawWidth-1,
		m_iCurrentScreenY + m_iDrawHeight -1,
		0xe06969);
	StoreLastScreenPositionForUndraw();
}



void PlayerObject::DoUpdate(int iCurrentTime)
{
	m_iPreviousScreenX = m_iCurrentScreenX;
	m_iPreviousScreenY = m_iCurrentScreenY;


	DisplayableObject * pjcol;
	for (int boxesId = 0; (pjcol = m_engine->GetDisplayableObject(boxesId)) != NULL; boxesId++) {
		if (pjcol == this)
			continue;


		int iXD = pjcol->GetXCentre() - m_iCurrentScreenX;
		int iYD = pjcol->GetYCentre() - m_iCurrentScreenY;

		int tick = iCurrentTime / m_engine->gamelvl;
		int iFrame = tick % 40;
		int theSize = 15 + iFrame;
		if (iFrame > 55)
			theSize = 80 + (40 - iFrame);
		int previousSize = theSize;

		int tickInt = iCurrentTime / 28;
		int iFrame2 = tickInt % 28;
		int iR = 5 + iFrame2;
		if (iFrame2 > 28)
			iR = 10 + (28 - iFrame2);
		int iR2 = iR;
		if (boxesId == 4) {
			if (((iXD*iXD) + (iYD*iYD)) < ((iR2 + iR)*(iR2 + iR))) {
				m_iDrawWidth +=1;
				m_iDrawHeight +=1;
				break;
				printf("Collision detected/n");
			}

		}
		else {
			if (((iXD*iXD) + (iYD*iYD)) < ((previousSize + theSize)*(previousSize + theSize)) && iFrame>17) {
				gameoverstate = 1;
				printf("Collision detected/n");
			}
		}
	}

	if (m_ver.HasMovementFinished(iCurrentTime)) {

		TTileManager &tile = m_engine->GetTileManager();
		int playerSpeed = 4;
		if (GetEngine()->IsKeyPressed(SDLK_w)) {
			m_iCurrentScreenY -= playerSpeed;

		}
		if (GetEngine()->IsKeyPressed(SDLK_s)) {
			m_iCurrentScreenY += playerSpeed;
		}
		if (GetEngine()->IsKeyPressed(SDLK_d)) {
			m_iCurrentScreenX += playerSpeed;
		}
		if (GetEngine()->IsKeyPressed(SDLK_a)) {
			m_iCurrentScreenX -= playerSpeed;
		}

		if (m_engine->stamina != 0) {
			if (m_engine->IsKeyPressed(SDLK_LSHIFT)) {
				m_engine->stamina--;
				switch (m_engine->stamina) {
				case 0:

					break;
				}

				if (GetEngine()->IsKeyPressed(SDLK_w)) {
					m_iCurrentScreenY -= playerSpeed * 2;

				}
				if (GetEngine()->IsKeyPressed(SDLK_s)) {
					m_iCurrentScreenY += playerSpeed * 2;
				}
				if (GetEngine()->IsKeyPressed(SDLK_d)) {
					m_iCurrentScreenX += playerSpeed * 2;
				}
				if (GetEngine()->IsKeyPressed(SDLK_a)) {
					m_iCurrentScreenX -= playerSpeed * 2;
				}
			}
		}
		if (!m_engine->IsKeyPressed(SDLK_LSHIFT) && m_engine->stamina < 500) {
			m_engine->stamina++;
			switch (m_engine->stamina)
			case 500:
				break;
		}

		if (m_iCurrentScreenY < 53) {
			m_iCurrentScreenY = 53;
		}
		printf("height: %d", m_engine->GetScreenHeight());
		if (m_iCurrentScreenY >= m_engine->GetScreenHeight()-59 - m_iDrawHeight){
			m_iCurrentScreenY = m_engine->GetScreenHeight()-59 - m_iDrawHeight;
		}
		if (m_iCurrentScreenX < 260) {
			m_iCurrentScreenX = 260;
		}
		if (m_iCurrentScreenX >= m_engine->GetScreenWidth()-210 - m_iDrawWidth) {
			m_iCurrentScreenX = m_engine->GetScreenWidth()-210 - m_iDrawWidth;
		}



	}
	
	RedrawObjects();
}




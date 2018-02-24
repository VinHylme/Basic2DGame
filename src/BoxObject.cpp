#include "header.h"
#include "templates.h"
#include "BaseEngine.h"
#include "BoxObject.h"
#include "PlayerObject.h"
#include <windows.h>
BoxObject::BoxObject(EngineController *pEngine)
	:DisplayableObject(pEngine)
	, mengine(pEngine)
	, i_dSX(0)
	, i_dSY(0)
{

	m_iStartDrawPosX = -25;
	m_iStartDrawPosY = -25;
	m_iDrawWidth = 15;
	m_iDrawHeight = 15;
	SetVisible(true);
	char* data[] = {
			"bbbbbbbbbbbbbbbbbbbbbbbbbbbbbb",
			"bbcaaaaccccccccccccccaaaacccbb",
			"bbcaaaaccccccccccccccaaaacccbb",
			"bbccccccccccccccccccccccccccbb",
			"bbccccccccccccccccccccccccccbb",
			"bbccccccccccaaacccccccccccccbb",
			"bbccccccccccaaacccccccccccccbb",
			"bbccccccccccccccccccccccccccbb",
			"bbccccccccccccccccccccccccccbb",
			"bbccccaaaaaaaaaaaaaaacccccccbb",
			"bbccccaaaaaaaaaaaaaaacccccccbb",
			"bbccccccccccccccccccccccccccbb",
			"bbbbbbbbbbbbbbbbbbbbbbbbbbbbbb" };
}

BoxObject::~BoxObject(void)
{
}

void BoxObject::Draw()
{
	char* data[] = {
		"bbbbbbbbbbbbbbbbbbbbbbbbbbbbbb",
		"bbcaaaaccccccccccccccaaaacccbb",
		"bbcaaaaccccccccccccccaaaacccbb",
		"bbccccccccccccccccccccccccccbb",
		"bbccccccccccccccccccccccccccbb",
		"bbccccccccccaaacccccccccccccbb",
		"bbccccccccccaaacccccccccccccbb",
		"bbccccccccccccccccccccccccccbb",
		"bbccccccccccccccccccccccccccbb",
		"bbccccaaaaaaaaaaaaaaacccccccbb",
		"bbccccaaaaaaaaaaaaaaacccccccbb",
		"bbccccccccccccccccccccccccccbb",
		"bbbbbbbbbbbbbbbbbbbbbbbbbbbbbb" };

	int iTick = mengine->GetModifiedTime() / mengine->gamelvl; 
	int iFrame = iTick % 40;
	int iSize = 15 + iFrame;
	if (iFrame > 55)
		iSize = 80 + (40 - iFrame);

		
	if (iFrame == 0) {
		DisplayableObject*pj;
		pj = mengine->GetDisplayableObject(0);

		//NOTE TO SELF YOU CAN MAKE THIS MORE COMPLEX USING THE IDEA OF HAVING 3 BOXES ALWAYS AROUND THE CHAR AND REST RANDOM
		m_iCurrentScreenX = m_iPreviousScreenX = rand() % pj->GetXCentre();
		m_iCurrentScreenY = m_iPreviousScreenY = rand() % pj->GetYCentre();
	}
	if ((mengine->score / 10) ==130) {
		mengine->gamelvl = 33;;

		for (int x = 0; x < 30; x++) {
			for (int y = 0; y < 13; y++) {
				mengine->GetTileManager().SetValue(x, y, data[y][x]- 'a');
			}
		}
		mengine->GetTileManager().DrawAllTiles(mengine, mengine->GetBackground(), 0, 0, 29, 12);
	}
	if ((mengine->score / 10) == 250) {
		mengine->gamelvl = 25;
		for (int x = 0; x < 30; x++) {
			for (int y = 0; y < 13; y++) {
				if (y >= 1 && y<=11) {
					data[y] = "bbcccdddddddddddddddddddccccbb";
				}
				mengine->GetTileManager().SetValue(x, y, data[y][x] - 'a');
			}
		}
		mengine->GetTileManager().DrawAllTiles(mengine, mengine->GetBackground(), 0, 0, 29, 12);
	}


	if (!(m_iCurrentScreenX < 260) && !(m_iCurrentScreenX >= 1010) && !(m_iCurrentScreenY<53) && !(m_iCurrentScreenY >= 690)) {
		mengine->DrawScreenRectangle(m_iCurrentScreenX - iFrame, m_iCurrentScreenY - iFrame,
			m_iCurrentScreenX + iFrame - 1,
			m_iCurrentScreenY + iFrame - 1,
			0x333333);
	}
	
		StoreLastScreenPositionForUndraw();
}

void BoxObject::DoUpdate(int iCurrentTime)
{
	RedrawObjects();
}
/*
void BoxObject::SetPosition(double dX, double dY)
{
	i_dX = dX;
	i_dY = dY;
}

void BoxObject::SetSpeed(double sX, double sY)
{
	i_dSX = sX;
	i_dSY = sY;
}

void BoxObject::SetMove(int iStart, int iEnd, int iCurrentTime, int iStartX, int iStartY, int iEndX, int iEndY)
{
	m_ve.Setup(iStartX, iStartY, iEndX, iEndY, iStart, iEnd);
	m_ve.Calculate(iCurrentTime);
	m_iCurrentScreenX = m_ve.GetX();
	m_iCurrentScreenY = m_ve.GetY();
}*/

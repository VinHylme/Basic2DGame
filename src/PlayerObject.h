#pragma once
#include "DisplayableObject.h"
#include "EngineController.h"
#include "MovementPosition.h"
class BaseEngine;

class PlayerObject:
	public DisplayableObject
{
public:
	PlayerObject(EngineController* pEngine, int iX, int iY);
	virtual ~PlayerObject(void);
	void Draw();
	void DoUpdate(int iCurrentTime);
	int gameoverstate=0;
	

private:
	EngineController* m_engine;
	MovementPosition m_ver;
	int m_iX;
	int m_iY;
	int m_cur;
	double m_sX;
	double m_sY;
	double xD;
	double yD;
};


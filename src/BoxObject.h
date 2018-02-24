#pragma once
#include "DisplayableObject.h"
#include "EngineController.h"
#include "MovementPosition.h"
class BaseEngine;
class BoxObject :
	public DisplayableObject
{
public:
	BoxObject(EngineController*pEngine);
	virtual ~BoxObject(void);
	void Draw();
	void DoUpdate(int iCurrentTime);
	/*
	void SetPosition(double dX, double dY);
	void SetSpeed(double sX, double sY);
	void SetMove(int iStart, int iEnd, int iCurrentTime, int iStartX, int iStartY, int iEndX, int iEndY);
	*/
private:
	EngineController* mengine;
	MovementPosition m_ve;
	double i_dX;
	double i_dY;
	double i_dSX;
	double i_dSY;
	int counter = 0;
};


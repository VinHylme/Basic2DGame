#pragma once
#include "DisplayableObject.h"
#include "DemoAClass.h"
#include "MovementPosition.h"
class BaseEngine;
class GreenBallObject :
	public DisplayableObject
{
public:
	GreenBallObject(DemoAClass*pEngine, int iXLabelOffset, int iYLabelOffset);
	virtual ~GreenBallObject(void);
	void Draw();
	void DoUpdate(int iCurrentTime);
	/*
	void SetPosition(double dX, double dY);
	void SetSpeed(double sX, double sY);
	void SetMove(int iStart, int iEnd, int iCurrentTime, int iStartX, int iStartY, int iEndX, int iEndY);*/
private:
	DemoAClass* mengine_green;
	MovementPosition m_ve;
	double i_dX;
	double i_dY;
	double i_dSX;
	double i_dSY;
};


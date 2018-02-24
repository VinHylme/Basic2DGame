#pragma once
#include "DisplayableObject.h"
#include "MovementPosition.h"
#include "DemoAClass.h"
class BaseEngine;
class Ob_boxes :
	public DisplayableObject
{
public:
	Ob_boxes(DemoAClass * pEngine, int iMapX, int iMapY);

	~Ob_boxes(void);
	void Draw();
	void DoUpdate(int iCurrentTime);
	int GetXDiffForDirection(int iDir)
	{
		switch (iDir % 4)
		{
		case 0: return 0; // Up
		case 1: return 1; // Right
		case 2: return 0; // Down
		case 3: return -1; // Left
		default: return 0; // Can never happen
		}
	}

	int GetYDiffForDirection(int iDir)
	{
		switch (iDir % 4)
		{
		case 0: return -1; // Up
		case 1: return 0; // Right
		case 2: return 1; // Down
		case 3: return 0; // Left
		default: return 0; // Can never happen
		}
	}
	void SetMovement(int iStartTime, int iEndTime, int iCurrentTime, int iStartX, int iStartY, int iEndX, int iEndY);
	void SetPosition(double dX, double dY);
	void SetSpeed(double dSX, double dSY);
protected:
	DemoAClass* main_engine;
	MovementPosition m_oMovement;
	int m_iMapX;
	int m_iMapY;
	int m_iDir;
	double m_dX;
	double m_dY;
	double m_dSX;
	double m_dSY;
};


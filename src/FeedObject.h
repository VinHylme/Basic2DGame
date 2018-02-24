#pragma once
#include "DisplayableObject.h"
#include "EngineController.h"

class BaseEngine;
class FeedObject :
	public DisplayableObject
{
public:
	FeedObject(EngineController*pEngine);
	~FeedObject(void);
	void Draw();
	void DoUpdate(int iCurrentTime);
	int gamelevel = 40;

private:
	EngineController* mengine_g;
	int counter = 0;
};


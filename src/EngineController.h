#pragma once
#include "BaseEngine.h"
#include "TileManager.h"
#include "TTileManager.h"
class PlayerObject;
class FeedObject;
class BoxObject;

class EngineController :
	public BaseEngine
{
public:
	EngineController(void);
	~EngineController(void);
	virtual void SetupBackgroundBuffer();
	void MouseDown(int iButton, int iX, int iY);
	void MouseMoved(int iX, int iY);
	void KeyDown(int iKeyCode);
	int stamina = 500;
	int gamelvl = 40;
	int InitialiseObjects();
	TTileManager& GetTileManager() { return m_tiles; }
	FeedObject* green_ob;
protected:

	PlayerObject* m_ob;
	BoxObject* m_box;
	TTileManager m_tiles;

public: 
	enum State {stateinit,state1, stateMain,gameOver,stateHelp,stateScore};
	int gamepas;
	int score = 0;
private: 
	State state_case;

	void DrawStrings();
	void GameAction();
	void Save();
	void Load();
	void UndrawObjects();
	void DrawObjects();
};


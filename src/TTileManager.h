#pragma once
#include "TileManager.h"
class TTileManager :
	public TileManager
{
public:
	TTileManager();
	~TTileManager();

	virtual void DrawTileAt(
		BaseEngine* pEngine,
		SDL_Surface* pSurface,
		int iMapX, int iMapY,
		int iStartPositionScreenX, int iStartPositionScreenY) const;
};


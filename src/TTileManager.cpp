#include "header.h"
#include "TTileManager.h"
#include "JPGImage.h"


TTileManager::TTileManager()
	:TileManager(55,31)
{
}


TTileManager::~TTileManager()
{
}
 void  TTileManager::DrawTileAt(
	BaseEngine* pEngine,
	SDL_Surface* pSurface,
	int iMapX, int iMapY,
	int iStartPositionScreenX, int iStartPositionScreenY) const
{
	//ImageData im;
	//im.LoadImage("brick.png");
	switch (GetValue(iMapX, iMapY)) {
	case 0:	
		pEngine->DrawRectangle(
		iStartPositionScreenX,
		iStartPositionScreenY,
		iStartPositionScreenX + GetTileWidth() - 1,
		iStartPositionScreenY + GetTileHeight() - 1,
		0x0099cc,
		pSurface);
		break;
	case 1:
		//im.ShrinkFrom(&im, 2);
		//im.RenderImage(pEngine->GetBackground(), iStartPositionScreenX, iStartPositionScreenY, iStartPositionScreenX + GetTileWidth() -4, iStartPositionScreenY + GetTileHeight()-5 , im.GetWidth(), im.GetHeight());
		pEngine->DrawRectangle(
			iStartPositionScreenX,
			iStartPositionScreenY,
			iStartPositionScreenX + GetTileWidth() - 1,
			iStartPositionScreenY + GetTileHeight() - 1,
			0x4e4e4e,
			pSurface);
		break;
	case 2:
		pEngine->DrawRectangle(
			iStartPositionScreenX,
			iStartPositionScreenY,
			iStartPositionScreenX + GetTileWidth() - 1,
			iStartPositionScreenY + GetTileHeight() - 1,
			0x003366,
			pSurface);
		break;
	case 3:
		pEngine->DrawRectangle(
			iStartPositionScreenX,
			iStartPositionScreenY,
			iStartPositionScreenX + GetTileWidth() - 1,
			iStartPositionScreenY + GetTileHeight() - 1,
			0x262626,
			pSurface);
		break;

	}
		

	
}
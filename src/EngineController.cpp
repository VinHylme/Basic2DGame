#include "header.h"
#include "templates.h"
#include "EngineController.h"
#include "PlayerObject.h"
#include "BoxObject.h"
#include "FeedObject.h"
#include "JPGImage.h"
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>


using namespace std;
ImageData im;
int iMenuStates = 0; //0 = start 1 = help me 2 =about
ifstream readScores;
string savedScores;
string showSaved[4];
int highScore[4];
int highestScore;
const char* playerName = "JohnStar";
int i = 0;
EngineController::EngineController(void):
	  BaseEngine(6) // Pass 6 to superclass constructor
	, m_ob(NULL)  // Initialise pointers to NULL
	, m_box(NULL)
	, green_ob(NULL)
	, state_case(stateinit){
	Load();

}


EngineController::~EngineController(void)
{
}


void EngineController::SetupBackgroundBuffer()
{

	
	ImageData im2,im3;
	switch (state_case) {
	case stateinit:

		im.LoadImage("menubuton.png");
		im2.LoadImage("background.png");
		
		im2.RenderImageWithMask(this->GetBackground(), 0, 0, 0, 0, im2.GetWidth(), im2.GetHeight());
		int nda;
		for (int i = 1; i <= 3; i++) {
			switch (i) {
			case 1: nda = 280;
				break;
			case 2: nda = 385;
				break;
			case 3: nda = 485;
				break;
			}
				im.RenderImageWithMask(this->GetBackground(), 0, 0,  430, nda, im.GetWidth(), im.GetHeight());
			}
		{
			char* data[] = {
				"bbbbbbbbbbbbbbbbbbbbbbbbbbbbbb",
				"bbaaaaaaaaaaaaaaaaaaaaaaaaaabb",
				"bbaaaaaaaaaaaaaaaaaaaaaaaaaabb",
				"bbaaaaaaaaaaaaaaaaaaaaaaaaaabb",
				"bbaaaaaaaaaaaaaaaaaaaaaaaaaabb",
				"bbaaaaaaaaaaaaaaaaaaaaaaaaaabb",
				"bbaaaaaaaaaaaaaaaaaaaaaaaaaabb",
				"bbaaaaaaaaaaaaaaaaaaaaaaaaaabb",
				"bbaaaaaaaaaaaaaaaaaaaaaaaaaabb",
				"bbaaaaaaaaaaaaaaaaaaaaaaaaaabb",
				"bbaaaaaaaaaaaaaaaaaaaaaaaaaabb",
				"bbaaaaaaaaaaaaaaaaaaaaaaaaaabb",
				"bbbbbbbbbbbbbbbbbbbbbbbbbbbbbb" };


			m_tiles.SetSize(30, 13);
			for (int x = 0; x < 30; x++) {
				for (int y = 0; y < 13; y++) {
					m_tiles.SetValue(x, y, data[y][x] - 'a');
				}
			}
			m_tiles.SetBaseTilesPositionOnScreen(200, 0);
			
		}
		return;

	case stateMain:
		
		im3.LoadImage("ingameback.png");
		im3.RenderImage(this->GetBackground(), 0, 0, 0, 0, im3.GetWidth(), im3.GetHeight());
		
		m_tiles.DrawAllTiles(this, this->GetBackground(), 0, 0, 29, 12);
		break;
	case state1:
		im3.LoadImage("gameoverbackground.png");
		im3.RenderImage(this->GetBackground(), 0, 0, 0, 0, im3.GetWidth(), im3.GetHeight());
		m_tiles.DrawAllTiles(this, this->GetBackground(), 0, 0, 29, 12);
		
		break;
	case stateScore:
		im3.LoadImage("score_background.png");
		im3.RenderImage(this->GetBackground(), 0, 0, 0, 0, im3.GetWidth(), im3.GetHeight());
		DestroyOldObjects();
		break;
	case gameOver:
		im3.LoadImage("gameoverbackground.png");
		im3.RenderImage(this->GetBackground(), 0, 0, 0, 0, im3.GetWidth(), im3.GetHeight());
		DestroyOldObjects();
		break;
	case stateHelp:
		im3.LoadImage("helpme_background.png");
		im.LoadImage("backbuton.png");
		im3.RenderImage(this->GetBackground(), 0, 0, 0, 0, im3.GetWidth(), im3.GetHeight());
		im.RenderImageWithMask(this->GetBackground(), 0, 0, 455, 580, im.GetWidth(), im.GetHeight());
		DestroyOldObjects();
		break;
	}
}


void EngineController::MouseDown(int iButton, int iX, int iY)
{
	
	switch (state_case) {
	case stateinit:
		if (iButton == SDL_BUTTON_LEFT) {
			if ((iX > 430 && iX <= 843) && (iY > 280 && iY <= 334)) {
				state_case = stateMain;
				InitialiseObjects();
				SetupBackgroundBuffer();
				Redraw(true);

			}

			if ((iX > 430 && iX <= 843) && (iY > 385 && iY <= 440)) {
				state_case = stateHelp;
				InitialiseObjects();
				SetupBackgroundBuffer();
				Redraw(true);
			}
			if ((iX > 430 && iX <= 843) && (iY > 485 && iY <= 542)) {
				state_case = stateScore;
				SetupBackgroundBuffer();
				Redraw(true);
			}
		}
		break;
	case stateHelp: 
		if (iButton == SDL_BUTTON_LEFT) {
			if ((iX > 455 && iX <= 793) && (iY > 575 && iY <= 645)) {
				state_case = stateinit;
				SetupBackgroundBuffer();
				Redraw(true);
			}
		}
	}
	
}

void EngineController::MouseMoved(int iX, int iY)
{
	//printf("x: %d y: %d\n", iX, iY);
	switch (state_case) {
	case stateinit:
		if ((iX > 430 && iX <= 843) && (iY > 280 && iY <= 334)) {
			iMenuStates = 0;
			im.LoadImage("menubuton.png");
			im.RenderImageWithMask(this->GetBackground(), 0, 0, 430, 385, im.GetWidth(), im.GetHeight());
			im.RenderImageWithMask(this->GetBackground(), 0, 0, 430, 485, im.GetWidth(), im.GetHeight());

			im.LoadImage("menubuton_hover.png");
			im.RenderImageWithMask(this->GetBackground(), 0, 0, 430, 280, im.GetWidth(), im.GetHeight());
			Redraw(true);

		}

		if ((iX > 430 && iX <= 843) && (iY > 385 && iY <= 440)) {
			iMenuStates = 1;
			im.LoadImage("menubuton.png");
			im.RenderImageWithMask(this->GetBackground(), 0, 0, 430, 280, im.GetWidth(), im.GetHeight());
			im.RenderImageWithMask(this->GetBackground(), 0, 0, 430, 485, im.GetWidth(), im.GetHeight());

			im.LoadImage("menubuton_hover.png");
			im.RenderImageWithMask(this->GetBackground(), 0, 0, 430, 385, im.GetWidth(), im.GetHeight());
			Redraw(true);
		}
		if ((iX > 430 && iX <= 843) && (iY > 485 && iY <= 542)) {
			iMenuStates = 2;
			im.LoadImage("menubuton.png");
			im.RenderImageWithMask(this->GetBackground(), 0, 0, 430, 385, im.GetWidth(), im.GetHeight());
			im.RenderImageWithMask(this->GetBackground(), 0, 0, 430, 280, im.GetWidth(), im.GetHeight());

			im.LoadImage("menubuton_hover.png");
			im.RenderImageWithMask(this->GetBackground(), 0, 0, 430, 485, im.GetWidth(), im.GetHeight());
			Redraw(true);
		}
		break;
	case stateHelp:
		if ((iX > 455 && iX <= 793) && (iY > 575 && iY <= 645)) {
			im.LoadImage("backbuton_hover.png");
			im.RenderImageWithMask(this->GetBackground(), 0, 0, 455, 575, im.GetWidth(), im.GetHeight());
			Redraw(true);
		}
		else {
			im.LoadImage("backbuton.png");
			im.RenderImageWithMask(this->GetBackground(), 0, 0, 455, 575, im.GetWidth(), im.GetHeight());
			Redraw(true);
		}
		break;
	}
}


void EngineController::KeyDown(int iKeyCode)
{
	int nda;
	switch (iKeyCode) {
	case SDLK_SPACE:
		switch (state_case) {
		case stateinit:
			state_case = stateMain;
			SetupBackgroundBuffer();
			Redraw(true);
			break;
		case stateMain:
			state_case = state1;
			gamepas = GetTime();
			SetupBackgroundBuffer();
			Redraw(true);
			break;
		case state1:
			state_case = stateMain;
			IncreaseTimeOffset(gamepas - GetTime());
			SetupBackgroundBuffer();
			Redraw(true);
			break;
		case gameOver:
			m_ob->gameoverstate = 0;
			score = 0;
			InitialiseObjects();
			state_case = stateinit;
			SetupBackgroundBuffer();
			Redraw(true);
			break;
		case stateScore:
			InitialiseObjects();
			state_case = stateinit;
			SetupBackgroundBuffer();
			Redraw(true);
			break;
		}

	}
}


int EngineController::InitialiseObjects(void)
{
	
	DrawableObjectsChanged();
	DestroyOldObjects();
	CreateObjectArray(8);
	m_ob = new PlayerObject(this,12,5);
	StoreObjectInArray(0, m_ob);

	StoreObjectInArray(1, new BoxObject(this));
	StoreObjectInArray(2, new BoxObject(this));
	StoreObjectInArray(3, new BoxObject(this));
	StoreObjectInArray(4, new FeedObject(this));
	StoreObjectInArray(5, new BoxObject(this));
	StoreObjectInArray(6, new BoxObject(this));
	StoreObjectInArray(7, new BoxObject(this));
	StoreObjectInArray(8, new BoxObject(this));
	/*StoreObjectInArray(8, new BoxObject(this, 6, 3));
	StoreObjectInArray(9, new BoxObject(this, 4, 1));
	StoreObjectInArray(10, new BoxObject(this, 11, 4));
	StoreObjectInArray(11, new BoxObject(this, 6, 3));*/
	StoreObjectInArray(8, NULL);
	
	
	return 0;
}
void EngineController::DrawStrings() {
	char buffer[30];
	char buffer2[30];
	char buffer3[30];
	int dif;
	int addspace = 25;
	const char* check = itoa(score/10, buffer, 10);
	const char* highestscoreconv = itoa(highestScore, buffer2, 10);
	const char* staminaconv = itoa(stamina/5, buffer3, 10);
	switch (state_case) 
	{
	case stateinit: 
		CopyBackgroundPixels(0, 280, GetScreenWidth(), 40);
		DrawScreenString(460, 295, "PRESS SPACE TO START", 0xf14343, NULL);
		DrawScreenString(565, 400, "HELP ME", 0xf14343, NULL);
		DrawScreenString(580, 500, "SCORE", 0xf14343, NULL);
		break;
	case stateMain: 
			DrawScreenString(925, 675, "Score: ", 0xffffff, NULL);
			DrawScreenString(260, 675, "Stamina: ", 0xffffff, NULL);
			DrawScreenString(385, 675, staminaconv, 0Xffffff, NULL);
			DrawScreenString(1015, 675, check, 0xffffff, NULL);
			Redraw(true);
			break;
	case state1: 
			CopyBackgroundPixels(300, 280, GetScreenWidth(), 40);
			DrawScreenString(550, 400, "PAUSED", 0xc12727, NULL);
			DrawScreenString(925, 675, "Score: ", 0xffffff, NULL);
			DrawScreenString(1015, 675, check, 0xffffff, NULL);
			DrawScreenString(260, 675, "Stamina: ", 0xffffff, NULL);
			DrawScreenString(385, 675, staminaconv, 0Xffffff, NULL);
			break;
	case stateHelp:
		CopyBackgroundPixels(585, 600, GetScreenWidth(), 40);
		DrawScreenString(585, 600, "Back", 0xffffff, NULL);
		break;
	case stateScore:
		Load();
		for (i = 0; !showSaved[i].empty(); i++) {
			const char *converted=showSaved[i].c_str();
			DrawScreenString(765, 250+(i*addspace), "Score:", 0xffffff, NULL);
			DrawScreenString(385, 250 + (i*addspace), "Player Name:", 0xffffff, NULL);
			DrawScreenString(575, 250 + (i*addspace), playerName, 0xffffff, NULL);
			DrawScreenString(855, 250+(i*addspace), converted, 0xffffff, NULL);
			DrawScreenString(550, 400, "Highest Score", 0x49bd64, NULL);
			DrawScreenString(385, 430, "Player Name:", 0xffffff, NULL);
			DrawScreenString(575, 430, playerName, 0xffffff, NULL);
			DrawScreenString(765, 430, "Score:", 0xffffff, NULL);
			DrawScreenString(855, 430, highestscoreconv, 0xf4f4f4, NULL);
			
		}
			DrawScreenString(335, 635, "Press 'Space' to go back to the main menu", 0xffffff, NULL);
			Redraw(true);
		break;
	case gameOver: 
		CopyBackgroundPixels(540, 300, GetScreenWidth(), 40);
		DrawScreenString(535, 250, "GAME OVER", 0xc92424, NULL);
		DrawScreenString(480, 355, "YOUR SCORE WAS: ", 0xffffff, NULL);
		DrawScreenString(760, 355, check, 0xffffff, NULL);
		DrawScreenString(310, 675, "Press 'SPACE' to go back to the main menu", 0xfef3f3);
		break;
	}
}

void EngineController::GameAction() {
	ofstream filename;
	
	if (!IsTimeToAct())
		return;
	SetTimeToAct(10);

	if (m_ob->gameoverstate==1){
		state_case = gameOver;
	}

	switch (state_case) {
	case stateinit:
	case state1:
		break;
	case stateMain:
		score++;
		UpdateAllObjects(GetModifiedTime());
		break;
	case gameOver:
		Save();
		SetupBackgroundBuffer();
		break;
	case stateHelp:
		SetupBackgroundBuffer();
		break;
	case stateScore:
		SetupBackgroundBuffer();
		break;
	}
}



void EngineController::Save() {
	ofstream saveScores;
	saveScores.open("store2.txt", ofstream::trunc);
	cout << showSaved[0];

	for (i = 0; !showSaved[i].empty() && i<=3; i++) {
		saveScores << showSaved[i] <<endl;
		
	}
	saveScores << (score / 10) <<endl;
	saveScores.close();
}



void EngineController::Load() {
	ifstream loadAllScores;
	loadAllScores.open("store2.txt", ofstream::in);
	i = 0;

	while (!loadAllScores.eof() && i<=4) {
		getline(loadAllScores, savedScores);
		showSaved[i] = savedScores;
		highScore[i] = atoi(showSaved[i].c_str());
		i++;
	}
	for (int x = 0; x <= 4; x++) {
		//cout << showSaved[x]<<endl;
		//cout << highScore[x] << endl;
		if (highScore[x] > highestScore) {
			highestScore = highScore[x];
		}
	}

	loadAllScores.close();
}

void EngineController::UndrawObjects() {
	if (state_case != stateinit) {
		BaseEngine::UndrawObjects();
	}
}
void EngineController::DrawObjects() {
	if (state_case != stateinit) {
		BaseEngine::DrawObjects();
	}
}
//çÏê¨ÅF0G02029íπà‰ê˘ó¢

#include "DxLib.h"
#include "SceneMgr.h"
#include "Keyboard.h"

bool Process(){
	char Key[256];
	if(ScreenFlip()!=0)return false; 
	if(ProcessMessage()!=0)return false;
	if(ClearDrawScreen()!=0)return false;
	if(GetHitKeyStateAll(Key)!=0)return false;
	return true; 
}

int SE=50;
int BGM=30; 

int WINAPI WinMain(HINSTANCE,HINSTANCE,LPSTR,int){
	ChangeWindowMode(TRUE);
	SetGraphMode(1280,720,16);
        DxLib_Init();    
	SetMainWindowText("marubatu");
	SetDrawScreen( DX_SCREEN_BACK );
	ChangeFont("ÇlÇr ÇoÉSÉVÉbÉN");

	while( Process() ){

		SceneMgr_Update();
		Keyboard_Update();  
	        SceneMgr_Draw(); 
		   
	}
	
	DxLib_End();
	InitSoundMem();
        return 0;
}
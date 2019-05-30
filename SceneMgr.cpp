//çÏê¨ÅF0G02029íπà‰ê˘ó¢

#include "DxLib.h"
#include "Title.h"
#include "Game.h"
#include "Nico.h"
#include "Staff.h"
#include "Config.h"
#include "SceneMgr.h"


static eScene Scene = eScene_Title;

void SceneMgr_Update(){
	switch(Scene){       
		case eScene_Title: 
        		Title_Update();
        		break;
		case eScene_Nico:
		case eScene_GameNico:
		case eScene_GameN:
		case eScene_GameCPUA:
		case eScene_GameCPUTf:
		case eScene_GameCPUF:
		case eScene_GameCPUTF:
		case eScene_GameCPUTs:
		case eScene_GameCPUS:
		case eScene_GameCPUTS:
		case eScene_GameHUMAN:		
        		Game_Update();
        		break;
    		case eScene_Staff:
        		Staff_Update();
        		break;
		case eScene_Config:
			Config_Update();
			break;
		
    	}
}

void SceneMgr_Draw(){
    	switch(Scene){      
    		case eScene_Title:
        		Title_Draw();
        		break;
		case eScene_GameNico:
			Game_Nico();
			break;
		case eScene_Nico:
                        Nico_Draw();
			break;
		case eScene_GameN:
			Game_Ninzu();
			break;
		case eScene_GameCPUA:
			Game_Atosaki();
    			break;
		case eScene_GameCPUTf:
			Game_Timef();
			break;
    		case eScene_GameCPUF:
			Game_DrawCF();
    			break;
		case eScene_GameCPUTF:
			Game_DrawCTF();
    			break;
		case eScene_GameCPUTs:
			Game_Times();
			break;
		case eScene_GameCPUS:
			Game_DrawCS();
    			break;
		case eScene_GameCPUTS:
			Game_DrawCTS();
    			break;
		case eScene_GameHUMAN:
			Game_DrawH();
			break;
   		case eScene_Staff:
   		 	Staff_Draw();
        	 	break;
		case eScene_Config:
			Config_Draw();
			break;
    	}
}

void SceneMgr_ChangeScene(eScene NextScene){
	Scene = NextScene;
}
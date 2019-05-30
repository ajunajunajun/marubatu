//çÏê¨ÅF0G02029íπà‰ê˘ó¢

#include "Dxlib.h"
#include "Title.h"
#include "SceneMgr.h"
#include "Keyboard.h"

extern int SE;
extern int BGM; 

extern int HandleBGM;

typedef enum{
	e_1,
	e_2,
	e_3,
}e;
              
static int NowSelect = e_1;

static Cr = GetColor(255,255,255);

void Config_Update(){
	static HandleS1,HandleS2;
	
	ChangeVolumeSoundMem( 255 * SE / 100, HandleS1 ) ;
	ChangeVolumeSoundMem( 255 * BGM / 100, HandleBGM ) ;
	
	if(Keyboard_Get(KEY_INPUT_DOWN)==1){
        	NowSelect = (NowSelect+1)%3;
		HandleS1 = LoadSoundMem("titlemove.mp3");
		PlaySoundMem(HandleS1,DX_PLAYTYPE_BACK);
	}
	if(Keyboard_Get(KEY_INPUT_UP)==1){
		NowSelect = (NowSelect+2)%3;
		HandleS1 = LoadSoundMem("titlemove.mp3");
		PlaySoundMem(HandleS1,DX_PLAYTYPE_BACK);
	}
	if(Keyboard_Get(KEY_INPUT_LEFT)==1){
		switch(NowSelect){
        		case e_1:
				if(BGM>0){
					BGM-=10;
					InitSoundMem();
					if(CheckSoundMem(HandleBGM) != 1){
					       	HandleBGM = LoadSoundMem("titlebgm.mp3");
						PlaySoundMem(HandleBGM,DX_PLAYTYPE_BACK);
	                                }
			        }
				break;
			case e_2:
				if(SE>0){
					SE-=10;
					HandleS1 = LoadSoundMem("titlemove.mp3");
					PlaySoundMem(HandleS1,DX_PLAYTYPE_BACK);
			        }
				break;
		}
	}
	if(Keyboard_Get(KEY_INPUT_RIGHT)==1){
	        switch(NowSelect){
        		case e_1:
				if(BGM<100){
					BGM+=10;
					InitSoundMem();
					if(CheckSoundMem(HandleBGM) != 1){
					       	HandleBGM = LoadSoundMem("titlebgm.mp3");
						PlaySoundMem(HandleBGM,DX_PLAYTYPE_BACK);
	                                }
			        }
				break;
			case e_2:
				
				if(SE<100){
					SE+=10;
					HandleS1 = LoadSoundMem("titlemove.mp3");
					PlaySoundMem(HandleS1,DX_PLAYTYPE_BACK);
			        }
				break;
		}
	}
       	if(Keyboard_Get(KEY_INPUT_RETURN)==1){
        	switch(NowSelect){
        		case e_3:
				HandleS2 = LoadSoundMem("titleselect.mp3");
				PlaySoundMem(HandleS2,DX_PLAYTYPE_BACK);
				ChangeVolumeSoundMem( 255 * SE / 100, HandleS2 ) ;
				Title_Delete();
				InitSoundMem();
				Title_Create();
				SceneMgr_ChangeScene(eScene_Title);
		}
	}					
}

void Config_Draw(){
	Title_Frame();
       	int x=0;
	int y=0;
	int w,z;
	switch(NowSelect){
		case e_1:
			y=445;
        		break;
		case e_2:
			y=555;
        		break;
		case e_3:
			y=665;
        		break;
	}
	
	DrawString(545,445,"BGM",Cr);
	DrawString(545,555,"SE",Cr);
	DrawString(545,665,"BACK",Cr);
	
	for(z=0;100>z;z+=10){
		DrawString(630+(z),445,".",Cr);
	}
	for(w=0;100>w;w+=10){
		DrawString(630+(w),555,".",Cr);
	}
	for(z=0;BGM>z;z+=10){
		DrawString(630+(z),445,"|",Cr);
	}
	for(w=0;SE>w;w+=10){
		DrawString(630+(w),555,"|",Cr);
	}
	DrawString(730,445,"o",Cr);
	DrawString(614,445,"o",Cr);
	
	DrawString(730,555,"o",Cr);
	DrawString(614,555,"o",Cr);
	
	DrawString(545,555,"SE",Cr);
	DrawString(545,665,"BACK",Cr);
	
	DrawString(505, y, "Åü", GetColor(255,0,0));
}
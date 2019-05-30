//作成：0G02029鳥井旋里

#include "DxLib.h"
#include "Main.h"
#include "Title.h"
#include "Game.h"
#include "Nico.h"
#include "Staff.h"
#include "SceneMgr.h"
#include "Keyboard.h"

extern int SE;
extern int BGM; 

int HandleBGM;

int count=0;
static Cr = GetColor(255,255,255);

static const GAME_Y = 445;
static const STAFF_Y = 555;
static const CONFIG_Y = 665;

typedef enum{
	eTitle_Game,
	eTitle_Staff,
	eTitle_Config,
	eTitle_Num,
}eTitle;

static NowSelect = eTitle_Game;

void Title_Update(){
	static c=0,d=0;
 	
        static HandleS1,HandleS2,HandleS3;
	
	ChangeVolumeSoundMem( 255 * SE / 100, HandleS1 ) ;
		
	if(Keyboard_Get(KEY_INPUT_DOWN)==1){
        	NowSelect = (NowSelect+1)%eTitle_Num;
		HandleS1 = LoadSoundMem("titlemove.mp3");
		PlaySoundMem(HandleS1,DX_PLAYTYPE_BACK);
	}
	if(Keyboard_Get(KEY_INPUT_UP)==1){
        	NowSelect = (NowSelect+(eTitle_Num-1))%eTitle_Num;
		HandleS1 = LoadSoundMem("titlemove.mp3");
		PlaySoundMem(HandleS1,DX_PLAYTYPE_BACK);
	}
	if(Keyboard_Get(KEY_INPUT_SPACE)==1){
		HandleS3 = LoadSoundMem("select3.mp3");
		PlaySoundMem(HandleS3,DX_PLAYTYPE_BACK);
		ChangeVolumeSoundMem( 255 * SE / 100, HandleS3 ) ;                              
		Title_Delete();
		InitSoundMem();
  		SceneMgr_ChangeScene(eScene_GameNico);
		Nico_Finalize();  

	}
	if(Keyboard_Get(KEY_INPUT_RETURN)==1){
		HandleS2 = LoadSoundMem("titleselect.mp3");
		PlaySoundMem(HandleS2,DX_PLAYTYPE_BACK);
        	ChangeVolumeSoundMem( 255 * SE / 100, HandleS2 ) ;
		switch(NowSelect){
        		case eTitle_Game:
				Title_Delete();
				InitSoundMem();
				Title_Create();
        			SceneMgr_ChangeScene(eScene_GameN);
        			break;
        		case eTitle_Staff:
				Title_Delete();
				if(d!=0){
					Staff_Create();
				}
				d++;
        			SceneMgr_ChangeScene(eScene_Staff);
        			break;
			case eTitle_Config:
				Title_Delete();
				Title_Create();
        			SceneMgr_ChangeScene(eScene_Config);
				break;
        	}
        }
}
	
void Title_Draw(){

	static a=0,c=0;
	static HandleT;
	
	SetFontSize(30);
	
	if(count==0){
		Title_Create();
		count++;
	}	
	
        if(CheckSoundMem(HandleBGM) != 1){
	       	HandleBGM = LoadSoundMem("titlebgm.mp3");
		PlaySoundMem(HandleBGM,DX_PLAYTYPE_BACK);
	}
		ChangeVolumeSoundMem( 255 * BGM / 100, HandleBGM ) ;
	

	Title_Frame();                                                  
	
	DrawString(545,GAME_Y,"GAME START",Cr);
	DrawString(545,STAFF_Y,"CREDIT",Cr);
	DrawString(545,CONFIG_Y,"OPTION",Cr); 	 // 他CONFIGだけど直すの面倒
	
	Title_Weapon1();
	if(a<=1415){
		a++;
	}
	if(a>=1415){
		Title_Weapon2();
	}
	
	if(c==0){
		HandleT=LoadGraph("Title.png",TRUE);
		c++;
	}
	DrawGraph(400,50,HandleT,TRUE);
	
	int y=0;
	switch(NowSelect){
		case eTitle_Game:
			y=GAME_Y;
        		break;
		case eTitle_Staff:
        		y=STAFF_Y;    
        		break;
		case eTitle_Config:
			y=CONFIG_Y;
			break;
	}
       
	DrawString(505, y, "◆", GetColor(255,0,0));

	SetFontSize(16);
	
	DrawString(820,665,"十字キー",Cr);
	DrawString(820,685,"Enterキーで操作",Cr);

	
}

void Title_Create(){
	static a,b;
	
	for(a=0;Process() && (a <=165);a+=3){
		DrawLine(640-a,535,640+a,535,Cr,TRUE);	// 横線一本目
	}

	for(a=0,b=0;Process() && (a <=165);a+=3,b++){
		DrawLine(475,535-a,475,535+a,Cr,5);  // 縦線一本目
		DrawLine(805,535-a,805,535+a,Cr,5);	// 縦線四本目
		
		DrawLine(475,535+a,805,535+a,Cr,5);  // 横線一本目
		DrawLine(475,535+b,805,535+b,Cr,5);  // 横線二本目
		DrawLine(475,535-b,805,535-b,Cr,5);  // 横線三本目
		DrawLine(475,535-a,805,535-a,Cr,5);  // 横線四本目
	}
}

void Title_Delete(){
	static a,b;
	
	for(a=0,b=0;Process() && (a <=165);a+=3,b++){
		DrawLine(475,370+a,475,700-a,Cr,5);  // 縦線一本目
		DrawLine(805,370+a,805,700-a,Cr,5);	// 縦線四本目
		
		DrawLine(475,700-a,805,700-a,Cr,5);  // 横線一本目
		DrawLine(475,590-b,805,590-b,Cr,5);  // 横線二本目
		DrawLine(475,480+b,805,480+b,Cr,5);  // 横線三本目
		DrawLine(475,370+a,805,370+a,Cr,5);  // 横線四本目
	}	
	for(a=0;Process() && (a <=165);a+=3){
		DrawLine(475+a,535,805-a,535,Cr,TRUE);	// 横線一本目
	}
	SetFontSize(17);
}

void Title_Frame(){
        
	DrawLine(475,370,475,700,Cr,5);	// 縦線一本目
	DrawLine(805,370,805,700,Cr,5);	// 縦線四本目

	DrawLine(475,700,805,700,Cr,5);	// 横線一本目
	DrawLine(475,590,805,590,Cr,5); // 横線二本目
	DrawLine(475,480,805,480,Cr,5);	// 横線三本目
	DrawLine(475,370,805,370,Cr,5);	// 横線四本目  
}

void Title_Create2(){
	static a,b;
	
	for(a=0,b=0;Process() && (a <=165);a+=6,b+=2){
		DrawLine(475,535-a,475,535+a,Cr,5);  // 縦線一本目
		DrawLine(805,535-a,805,535+a,Cr,5);	// 縦線四本目
		
		DrawLine(475,535+a,805,535+a,Cr,5);  // 横線一本目
		DrawLine(475,535+b,805,535+b,Cr,5);  // 横線二本目
		DrawLine(475,535-b,805,535-b,Cr,5);  // 横線三本目
		DrawLine(475,535-a,805,535-a,Cr,5);  // 横線四本目
	}
}

void Title_Delete2(){
	static a,b;
	
	for(a=0,b=0;Process() && (a <=165);a+=6,b+=2){
		DrawLine(475,370+a,475,700-a,Cr,5);  // 縦線一本目
		DrawLine(805,370+a,805,700-a,Cr,5);	// 縦線四本目
		
		DrawLine(475,700-a,805,700-a,Cr,5);  // 横線一本目
		DrawLine(475,590-b,805,590-b,Cr,5);  // 横線二本目
		DrawLine(475,480+b,805,480+b,Cr,5);  // 横線三本目
		DrawLine(475,370+a,805,370+a,Cr,5);  // 横線四本目
	}	
	
	SetFontSize(17);
}

void Title_Weapon1(){
	static a=0,c=0;
	static Handletw;
	
	if(c==0){
		Handletw=LoadGraph("titlew.png",TRUE);
        	c++;
	}
	DrawExtendGraph( 1280-a, 0, 2600-a, 380, Handletw, TRUE ) ;
	
	a++;
	if(a>=2900){
		a=0;
	}
}

void Title_Weapon2(){
	static a=0,c=0;
	static Handletw;
	
	if(c==0){
		Handletw=LoadGraph("titlew.png",TRUE);
        	c++;
	}
	DrawExtendGraph( 1280-a, 0, 2600-a, 380, Handletw, TRUE ) ;
	
	a++;
	if(a>=2900){
		a=0;
	}
}
		

		

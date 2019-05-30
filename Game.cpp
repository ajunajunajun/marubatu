//çÏê¨ÅF0G02029íπà‰ê˘ó¢

#include "DxLib.h"
#include "Main.h"
#include "Title.h"
#include "Game.h"
#include "Marubatu.h"
#include "Sentaku.h"
#include "SceneMgr.h"
#include "Keyboard.h"

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define PI    3.1415926535897932384626433832795f

extern char d[9];
extern int j;
extern int junb;

extern int ikkai;
extern int kakunin;

extern int count;
int one;
     
static Cr = GetColor(255,255,255);

extern int SE;
extern int BGM;

int ninzuu=0;

extern int kati;

extern int jikan;
extern int jikaku;

extern int next;
extern int ju;

static HandleBGM;

static int HandleVSCPU,HandleVSHUMAN,
	HandleCPUF,HandleCPUFT,HandleCPUS,HandleCPUST;
	

void Game_Update(){
	if(Keyboard_Get(KEY_INPUT_ESCAPE)==1){
		Game_Delete();
		InitSoundMem();
		SceneMgr_ChangeScene(eScene_Title);
	}
}

void Game_DrawCTF(){
	ChangeVolumeSoundMem( 255 * BGM / 100, HandleBGM ) ;

	if(one==0){
		Maru_EntryET();
		jikan=GetNowCount();
		jikaku++;
		one++;
	}
	
	if(CheckSoundMem(HandleBGM) != 1){
		HandleBGM = LoadSoundMem("gamebgm1.mp3");
		PlaySoundMem(HandleBGM,DX_PLAYTYPE_BACK);
	}
	marubatu(1,0);
	if(kati==3){
		Sentaku_Draw();  	
	}
}

void Game_DrawCF(){
	ChangeVolumeSoundMem( 255 * BGM / 100, HandleBGM ) ;

	if(one==0){
        	Game_EntryE1();
		one++;
	}
	
	if(CheckSoundMem(HandleBGM) != 1){
		HandleBGM = LoadSoundMem("gamebgm1.mp3");
		PlaySoundMem(HandleBGM,DX_PLAYTYPE_BACK);
	}
	marubatu(1,0);
	if(kati==3){
		Sentaku_Draw();  	
	}
}

void Game_DrawCTS(){

	if(one==0){
        	Maru_EntryET();
		jikan=GetNowCount();
		jikaku++;
		one++;
	}
	ChangeVolumeSoundMem( 255 * BGM / 100, HandleBGM ) ;	
	if(CheckSoundMem(HandleBGM) != 1){
		HandleBGM = LoadSoundMem("gamebgm1.mp3");
		PlaySoundMem(HandleBGM,DX_PLAYTYPE_BACK);
	}
	
	ChangeVolumeSoundMem( 255 * BGM / 100, HandleBGM ) ;
	marubatu(1,1);
	if(kati==3){
		Sentaku_Draw();  	
	}
}

void Game_DrawCS(){
	ChangeVolumeSoundMem( 255 * BGM / 100, HandleBGM ) ;

	if(one==0){
        	Game_EntryE1();
		one++;
	}

	if(CheckSoundMem(HandleBGM) != 1){
		HandleBGM = LoadSoundMem("gamebgm1.mp3");
		PlaySoundMem(HandleBGM,DX_PLAYTYPE_BACK);
	}
	ChangeVolumeSoundMem( 255 * BGM / 100, HandleBGM ) ;
	marubatu(1,1);
	if(kati==3){
		Sentaku_Draw();  
	}
}

void Game_DrawH(){	
	ChangeVolumeSoundMem( 255 * BGM / 100, HandleBGM ) ;

	if(CheckSoundMem(HandleBGM) != 1){
		HandleBGM = LoadSoundMem("gamebgm1.mp3");
		PlaySoundMem(HandleBGM,DX_PLAYTYPE_BACK);
	}
	marubatu(2,0);
	if(kati==3){
		Sentaku_Draw();  
	}
}

void Game_Create(){
	static a,b;

        for(a=0;Process() && (a <=165);a+=3){
		DrawLine(640-a,535,640+a,535,Cr,TRUE);	// â°ê¸àÍñ{ñ⁄
		}
		for(a=0,b=0;Process() && (a <=165);a+=3,b++){
			DrawLine(475,535-a,475,535+a,Cr,5);  // ècê¸àÍñ{ñ⁄
			DrawLine(585,535-a,585,535+a,Cr,5);  // ècê¸ìÒñ{ñ⁄
			DrawLine(695,535-a,695,535+a,Cr,5);  // ècê¸éOñ{ñ⁄
			DrawLine(805,535-a,805,535+a,Cr,5);  // ècê¸élñ{ñ⁄
			
			DrawLine(475,535+a,805,535+a,Cr,5);  // â°ê¸àÍñ{ñ⁄
			DrawLine(475,535+b,805,535+b,Cr,5);  // â°ê¸ìÒñ{ñ⁄
			DrawLine(475,535-b,805,535-b,Cr,5);  // â°ê¸éOñ{ñ⁄
			DrawLine(475,535-a,805,535-a,Cr,5);  // â°ê¸élñ{ñ⁄
		}
}

void Game_Delete(){
	static a,b;

	for(a=0,b=0;Process() && (a <=165);a+=3,b++){
		DrawLine(475,370+a,475,700-a,Cr,5);  // ècê¸àÍñ{ñ⁄
               	DrawLine(585,370+a,585,700-a,Cr,5);  // ècê¸ìÒñ{ñ⁄
		DrawLine(695,370+a,695,700-a,Cr,5);  // ècê¸éOñ{ñ⁄
		DrawLine(805,370+a,805,700-a,Cr,5);  // ècê¸élñ{ñ⁄
		
		DrawLine(475,700-a,805,700-a,Cr,5);  // â°ê¸àÍñ{ñ⁄
		DrawLine(475,590-b,805,590-b,Cr,5);  // â°ê¸ìÒñ{ñ⁄
		DrawLine(475,480+b,805,480+b,Cr,5);  // â°ê¸éOñ{ñ⁄
		DrawLine(475,370+a,805,370+a,Cr,5);  // â°ê¸élñ{ñ⁄
	}
	for(a=0;Process() && (a <=165);a+=3){
		DrawLine(475+a,535,805-a,535,Cr,TRUE);	// â°ê¸àÍñ{ñ⁄
	}
}

void Game_Frame(){
		
	DrawLine(475,370,475,700,Cr,5);	// ècê¸àÍñ{ñ⁄
	DrawLine(585,370,585,700,Cr,5); // ècê¸ìÒñ{ñ⁄
	DrawLine(695,370,695,700,Cr,5);	// ècê¸éOñ{ñ⁄
	DrawLine(805,370,805,700,Cr,5);	// ècê¸élñ{ñ⁄
		        
	DrawLine(475,700,805,700,Cr,5);	// â°ê¸àÍñ{ñ⁄
	DrawLine(475,590,805,590,Cr,5);	// â°ê¸ìÒñ{ñ⁄
	DrawLine(475,480,805,480,Cr,5);	// â°ê¸éOñ{ñ⁄
	DrawLine(475,370,805,370,Cr,5);	// â°ê¸élñ{ñ⁄
}

void Game_Nico(){
	static HandleNICO,HandleS2;
	static c=0;
	if(Keyboard_Get(KEY_INPUT_RETURN)==1){
		HandleS2 = LoadSoundMem("titleselect.mp3");
		PlaySoundMem(HandleS2,DX_PLAYTYPE_BACK);
		ChangeVolumeSoundMem( 255 * SE / 100, HandleS2 ) ;
		SceneMgr_ChangeScene(eScene_Nico);
        }
			
	
	if(c==0){
		HandleNICO=LoadGraph("nico.png",TRUE);
		c++;
	}
	DrawGraph(170,50,HandleNICO,TRUE);
	
	DrawString(505, 665, "Åü", GetColor(255,0,0));
	DrawString(545, 665, "ENTRY", Cr);
	
}



void Game_Ninzu(){
	static MODE_Y = 445;
	static VSCPU_Y = 555;
	static VSHUMAN_Y = 665;

	typedef enum{
		eNinzu_Vscpu,
		eNinzu_Vshuman,
		eNinzu_Num,
	}eNinzu;

	static NowSelect = eNinzu_Vscpu;
	static HandleS1,HandleS2;
	
	ChangeVolumeSoundMem( 255 * SE / 100, HandleS1 ) ;
	
	if(Keyboard_Get(KEY_INPUT_DOWN)==1){
      	 	NowSelect = (NowSelect+1)%eNinzu_Num;
		HandleS1 = LoadSoundMem("titlemove.mp3");
		PlaySoundMem(HandleS1,DX_PLAYTYPE_BACK);
	}
	if(Keyboard_Get(KEY_INPUT_UP)==1){
      	 	NowSelect = (NowSelect+(eNinzu_Num-1))%eNinzu_Num;
		HandleS1 = LoadSoundMem("titlemove.mp3");
		PlaySoundMem(HandleS1,DX_PLAYTYPE_BACK);
	}
	if(Keyboard_Get(KEY_INPUT_RETURN)==1){
		Game_Finalize();
		HandleS2 = LoadSoundMem("titleselect.mp3");
		PlaySoundMem(HandleS2,DX_PLAYTYPE_BACK);
		ChangeVolumeSoundMem( 255 * SE / 100, HandleS2 ) ;
		switch(NowSelect){
      	 		case eNinzu_Vscpu:
				SceneMgr_ChangeScene(eScene_GameCPUA);
				Title_Delete2();
				Title_Create2();
				ninzuu=1;
				break;
			case eNinzu_Vshuman:
				SceneMgr_ChangeScene(eScene_GameHUMAN);
				Title_Delete();
				Game_Create();
				j=0;
				ninzuu=0;
				break;
     			}
     		}
	
	Title_Frame();                                                  
	
	DrawString(500,MODE_Y,"GAME MODE SELECT",Cr);
	DrawString(545,VSCPU_Y,"VS CPU",Cr);
	DrawString(545,VSHUMAN_Y,"VS HUMAN",Cr);
	
	int y=0;
	static c=0,d=0;
	switch(NowSelect){
		case eNinzu_Vscpu:
			if(c==0){
				HandleVSCPU=LoadGraph("vscpu.png",TRUE);
				c++;
			}
			DrawGraph(400,50,HandleVSCPU,TRUE);
			y=VSCPU_Y;    
      	 		break;
		case eNinzu_Vshuman:
			if(d==0){
				HandleVSHUMAN=LoadGraph("vshuman.png",TRUE);
				d++;
			}
			DrawGraph(400,50,HandleVSHUMAN,TRUE);
			y=VSHUMAN_Y;
			break;
	}
	DrawString(505, y, "Åü", GetColor(255,0,0));
	
}

void Game_Atosaki(){
	static HandleS1,HandleS2;
	
	ChangeVolumeSoundMem( 255 * SE / 100, HandleS1 ) ;
		
	static MODE_Y = 445;
	static FIRST_Y = 555;
	static SECOND_Y = 665;

	typedef enum{
		eAtosaki_First,
		eAtosaki_Second,
		eAtosaki_Num,
	}eAtosaki;

	static NowSelect = eAtosaki_First;


	if(Keyboard_Get(KEY_INPUT_DOWN)==1){
      	 	NowSelect = (NowSelect+1)%eAtosaki_Num;
		HandleS1 = LoadSoundMem("titlemove.mp3");
		PlaySoundMem(HandleS1,DX_PLAYTYPE_BACK);
	}
	if(Keyboard_Get(KEY_INPUT_UP)==1){
      	 	NowSelect = (NowSelect+(eAtosaki_Num-1))%eAtosaki_Num;
		HandleS1 = LoadSoundMem("titlemove.mp3");
		PlaySoundMem(HandleS1,DX_PLAYTYPE_BACK);
	}	
	if(Keyboard_Get(KEY_INPUT_RETURN)==1){
		HandleS2 = LoadSoundMem("titleselect.mp3");
		PlaySoundMem(HandleS2,DX_PLAYTYPE_BACK);
		ChangeVolumeSoundMem( 255 * SE / 100, HandleS2 ) ;
		switch(NowSelect){
      	 		case eAtosaki_First:                           
				SceneMgr_ChangeScene(eScene_GameCPUTf);
				Title_Delete2();
				Title_Create2();
				j=0;
				break;
			case eAtosaki_Second:
				SceneMgr_ChangeScene(eScene_GameCPUTs);
				Title_Delete2();
				Title_Create2();
				j=0;
				break;
     			}
     		}
	
	Title_Frame();                                                  
	
	DrawString(500,MODE_Y,"ATTACK TIME SELECT",Cr);
	DrawString(545,FIRST_Y,"FIRST ATTACK",Cr);
	DrawString(545,SECOND_Y,"SECOND ATTACK",Cr);
	
	int y=0;
	static c=0,d=0;
	switch(NowSelect){
		case eAtosaki_First:
			if(c==0){
				HandleCPUF=LoadGraph("cpuf.png",TRUE);
				c++;
			}
			DrawGraph(400,50,HandleCPUF,TRUE);
      	 		y=FIRST_Y;    
      	 		break;
		case eAtosaki_Second:
			if(d==0){
				HandleCPUS=LoadGraph("cpus.png",TRUE);
				d++;
			}
			DrawGraph(400,50,HandleCPUS,TRUE);
			y=SECOND_Y;
			break;
	}
	DrawString(505, y, "Åü", GetColor(255,0,0));
	
}

void Game_Timef(){	
	static HandleS1,HandleS2;
	
	ChangeVolumeSoundMem( 255 * SE / 100, HandleS1 ) ;
        	
	static MODE_Y = 445;
	static FIRST_Y = 555;
	static SECOND_Y = 665;

	typedef enum{
		eAtosaki_First,
		eAtosaki_Second,
		eAtosaki_Num,
	}eAtosaki;

	static NowSelect = eAtosaki_First;


	if(Keyboard_Get(KEY_INPUT_DOWN)==1){
      	 	NowSelect = (NowSelect+1)%eAtosaki_Num;
		HandleS1 = LoadSoundMem("titlemove.mp3");
		PlaySoundMem(HandleS1,DX_PLAYTYPE_BACK);
	}
	if(Keyboard_Get(KEY_INPUT_UP)==1){
      	 	NowSelect = (NowSelect+(eAtosaki_Num-1))%eAtosaki_Num;
		HandleS1 = LoadSoundMem("titlemove.mp3");
		PlaySoundMem(HandleS1,DX_PLAYTYPE_BACK);
	}	
	if(Keyboard_Get(KEY_INPUT_RETURN)==1){
		HandleS2 = LoadSoundMem("titleselect.mp3");
		PlaySoundMem(HandleS2,DX_PLAYTYPE_BACK);
		ChangeVolumeSoundMem( 255 * SE / 100, HandleS2 ) ;
		switch(NowSelect){
      	 		case eAtosaki_First:                           
				SceneMgr_ChangeScene(eScene_GameCPUTF);
				Title_Delete();
				Game_Create();
				break;
			case eAtosaki_Second:
				SceneMgr_ChangeScene(eScene_GameCPUF);
				Title_Delete();
				Game_Create();
				break;
     			}
     		}
	
	Title_Frame();                                                  
	
	DrawString(500,MODE_Y,"TIME MODE SELECT",Cr);
	DrawString(545,FIRST_Y, "TIMELIMIT ON",Cr);
	DrawString(545,SECOND_Y,"TIMELIMIT OFF",Cr);
	
	int y=0;
	static c=0,d=0;
	switch(NowSelect){
		case eAtosaki_First:
			if(c==0){
				HandleCPUFT=LoadGraph("cpuft.png",TRUE);
				c++;
			}
			DrawGraph(400,50,HandleCPUFT,TRUE);
      	 		y=FIRST_Y;    
      	 		break;
		case eAtosaki_Second:
			if(d==0){
				HandleCPUF=LoadGraph("cpuf.png",TRUE);
				d++;
			}
			DrawGraph(400,50,HandleCPUF,TRUE);
			y=SECOND_Y;
			break;
	}
	DrawString(505, y, "Åü", GetColor(255,0,0));
}

void Game_Times(){
	static HandleS1,HandleS2;
	
	ChangeVolumeSoundMem( 255 * SE / 100, HandleS1 ) ;
        	
	static MODE_Y = 445;
	static FIRST_Y = 555;
	static SECOND_Y = 665;

	typedef enum{
		eAtosaki_First,
		eAtosaki_Second,
		eAtosaki_Num,
	}eAtosaki;

	static NowSelect = eAtosaki_First;


	if(Keyboard_Get(KEY_INPUT_DOWN)==1){
      	 	NowSelect = (NowSelect+1)%eAtosaki_Num;
		HandleS1 = LoadSoundMem("titlemove.mp3");
		PlaySoundMem(HandleS1,DX_PLAYTYPE_BACK);
	}
	if(Keyboard_Get(KEY_INPUT_UP)==1){
      	 	NowSelect = (NowSelect+(eAtosaki_Num-1))%eAtosaki_Num;
		HandleS1 = LoadSoundMem("titlemove.mp3");
		PlaySoundMem(HandleS1,DX_PLAYTYPE_BACK);
	}	
	if(Keyboard_Get(KEY_INPUT_RETURN)==1){
		HandleS2 = LoadSoundMem("titleselect.mp3");
		PlaySoundMem(HandleS2,DX_PLAYTYPE_BACK);
		ChangeVolumeSoundMem( 255 * SE / 100, HandleS2 ) ;
		switch(NowSelect){
      	 		case eAtosaki_First:                           
				SceneMgr_ChangeScene(eScene_GameCPUTS);
				Title_Delete();
				Game_Create();
				break;
			case eAtosaki_Second:
				SceneMgr_ChangeScene(eScene_GameCPUS);
				Title_Delete();
				Game_Create();
				break;
     			}
     		}
	
	Title_Frame();                                                  
	
	DrawString(500,MODE_Y,"TIME MODE SELECT",Cr);
	DrawString(545,FIRST_Y, "TIMELIMIT ON",Cr);
	DrawString(545,SECOND_Y,"TIMELIMIT OFF",Cr);
	
	int y=0;
	static c=0,d=0;
	switch(NowSelect){
		case eAtosaki_First:
			if(c==0){
				HandleCPUST=LoadGraph("cpust.png",TRUE);
				c++;
			}
			DrawGraph(400,50,HandleCPUST,TRUE);
      	 		y=FIRST_Y;    
      	 		break;
		case eAtosaki_Second:
			if(d==0){
				HandleCPUS=LoadGraph("cpus.png",TRUE);
				d++;
			}
			DrawGraph(400,50,HandleCPUS,TRUE);
			y=SECOND_Y;
			break;
	}
	DrawString(505, y, "Åü", GetColor(255,0,0));
}


void Game_EntryE1(){                        	
	static a,b;
	static Handle1,Handle1w;
		
		
	Handle1=LoadGraph("enemy1.png",TRUE);
	for(a=0;Process() && a<=360;a+=10){
		DrawGraph(460,-360+a,Handle1,TRUE);     // ìG1
		Game_Frame();
	}
	WaitTimer(1000);
	
	Handle1w=LoadGraph("weapon1.png",TRUE);
	for(a=0;Process() && a<=360;a+=30){
		DrawGraph(460,0,Handle1,TRUE);	// ìG1
		DrawRotaGraph2( 530, -240+a, 100, 450, 1.0, PI*11/16, Handle1w, TRUE);	// ìG1ïêäÌ
		Game_Frame();
	}
}

void Game_ExitE1(){                        	
	static a=0;
	static Handle1;
			
	Handle1=LoadGraph("enemy1.png",TRUE);
	
	if(a<=360&&ninzuu==1){
		DrawGraph(460,0-a,Handle1,TRUE);     // ìG1
		if(a==0){
			WaitTimer(500);		
		}
		a+=10;
	}
}	

void Game_ExitE1N(){                        	
	static a=0;
	static Handle1;
			
	Handle1=LoadGraph("enemy1.png",TRUE);
	
	if(a<=400){
		DrawGraph(460,0-a,Handle1,TRUE);     // ìG1
		if(a==0){
			WaitTimer(500);		
		}
		a+=10;
	}
}


void Game_E1(){
	static Handle1,Handle1w;
	
	Handle1=LoadGraph("enemy1.png",TRUE);
	Handle1w=LoadGraph("weapon1.png",TRUE);
	DrawGraph(460,0,Handle1,TRUE);	// ìG1
	DrawRotaGraph2( 530, 120, 100, 450, 1.0, PI*11/16, Handle1w, TRUE);	// ìG1ïêäÌ
}

void Game_E1NW(){
	static Handle1;
	
	Handle1=LoadGraph("enemy1.png",TRUE);
	DrawGraph(460,0,Handle1,TRUE);	// ìG1
}

void Game_E1A1(){
	static a;
	static Handle1,Handlee1a1,Handlee1a1m,Handle1w,HandleF1;
	static HandleATT;
   	
	Handle1=LoadGraph("enemy1.png",TRUE);
	Handlee1a1=LoadGraph("e1a1.png",TRUE);
	Handlee1a1m=LoadGraph("e1a1m.png",TRUE);
	Handle1w=LoadGraph("weapon1.png",TRUE);
	HandleF1=LoadGraph("frame2.png",TRUE);
	HandleATT = LoadSoundMem("attack.mp3");
	
	ChangeVolumeSoundMem( 255 * SE / 100, HandleATT ) ;
	
	for(a=0;Process() && a<=10;a++){
		DrawGraph(460,0,Handle1,TRUE);
		DrawRotaGraph2( 530, 120, 100, 450, 1.0, PI*11/16, Handle1w, TRUE);
		DrawGraph(475,370,HandleF1,TRUE);
	}
	for(a=0;Process() && a<=50;a++){
		DrawGraph(460,0,Handlee1a1,TRUE);
		DrawRotaGraph2( 580, 200, 100, 450, 1.0, PI*15/8, Handle1w, TRUE);
		DrawGraph(475,370,HandleF1,TRUE);
	}                          
	PlaySoundMem(HandleATT,DX_PLAYTYPE_BACK);                          
	for(a=0;Process() && a<=4;a++){
		DrawGraph(460,0,Handle1,TRUE);
		DrawGraph(340,0,Handlee1a1m,TRUE);
		DrawGraph(475,370,HandleF1,TRUE);
	}
	for(a=0;Process() && a<=10;a++){
		DrawTurnGraph(460,0,Handlee1a1,TRUE);
	        DrawRotaGraph2( 680, 200, 100, 450, 1.0, -PI*15/8, Handle1w, TRUE);
		DrawGraph(475,370,HandleF1,TRUE);
	}
	PlaySoundMem(HandleATT,DX_PLAYTYPE_BACK);                          
	for(a=0;Process() && a<=4;a++){
		DrawGraph(460,0,Handle1,TRUE);
		DrawGraph(340,0,Handlee1a1m,TRUE);
		DrawGraph(475,370,HandleF1,TRUE);
	}
	for(a=0;Process() && a<=50;a++){
		DrawGraph(460,0,Handlee1a1,TRUE);
		DrawRotaGraph2( 580, 200, 100, 450, 1.0, PI*15/8, Handle1w, TRUE);
		DrawGraph(475,370,HandleF1,TRUE);
	}
	for(a=0;Process() && a<=10;a++){
		DrawGraph(460,0,Handle1,TRUE);
		DrawRotaGraph2( 530, 120, 100, 450, 1.0, PI*11/16, Handle1w, TRUE);
		DrawGraph(475,370,HandleF1,TRUE);
	}
}

void Game_E1A2(){
	static a,b;
	static Handle1,Handlee1a201,Handlee1a202,Handle1w,Handle2w,Handle3w,HandleF1;
   	static HandleATT;
	
	
	Handle1=LoadGraph("enemy1.png",TRUE);
	Handlee1a201=LoadGraph("e1a201.png",TRUE);
	Handlee1a202=LoadGraph("e1a202.png",TRUE);
	Handle1w=LoadGraph("weapon1.png",TRUE);
	Handle2w=LoadGraph("weapon5.png",TRUE);
	Handle3w=LoadGraph("weapon2.png",TRUE);
	HandleF1=LoadGraph("frame2.png",TRUE);
	HandleATT = LoadSoundMem("attack.mp3");
	
	ChangeVolumeSoundMem( 255 * SE / 100, HandleATT ) ;
	
	for(a=0;Process() && a<=10;a++){
		DrawGraph(475,370,HandleF1,TRUE);
		DrawGraph(75,370,HandleF1,TRUE);
		DrawGraph(875,370,HandleF1,TRUE);
		DrawGraph(470,0,Handle1,TRUE);
		DrawRotaGraph2( 530, 120, 100, 450, 1.0, PI*11/16, Handle1w, TRUE);
	}
	for(a=0;Process() && a<=50;a++){
		DrawGraph(475,370,HandleF1,TRUE);
		DrawGraph(75,370,HandleF1,TRUE);
		DrawGraph(875,370,HandleF1,TRUE);
		DrawGraph(460,0,Handlee1a201,TRUE);
		DrawRotaGraph2( 535, 50, 100, 450, 1.0, PI*37/32, Handle3w, TRUE);
		DrawRotaGraph2( 535, 50, 100, 450, 1.0, PI*6/8, Handle2w, TRUE);
		DrawRotaGraph2( 535, 50, 100, 450, 1.0, PI*15/16, Handle1w, TRUE);
	}
	PlaySoundMem(HandleATT,DX_PLAYTYPE_BACK);                          
	for(a=0,b=0;Process() && a<=720;a+=40,b+=30){
		DrawGraph(475,370,HandleF1,TRUE);
		DrawGraph(75,370,HandleF1,TRUE);
		DrawGraph(875,370,HandleF1,TRUE);
		DrawGraph(460,0,Handlee1a202,TRUE);
		DrawRotaGraph2( 535-(b*4/5), a+50, 100, 450, 1.0, PI*37/32, Handle3w, TRUE);
		DrawRotaGraph2( 535+(b*7/5), a+50, 100, 450, 1.0, PI*6/8, Handle2w, TRUE);
        	DrawRotaGraph2( 535+(b/3), a+50, 100, 450, 1.0, PI*15/16, Handle1w, TRUE);
	}
	for(a=0;Process() && a<=10;a++){
		DrawGraph(475,370,HandleF1,TRUE);
		DrawGraph(75,370,HandleF1,TRUE);
		DrawGraph(875,370,HandleF1,TRUE);
		DrawGraph(460,0,Handle1,TRUE);
		DrawRotaGraph2( 530, 120, 100, 450, 1.0, PI*11/16, Handle1w, TRUE);
	}
}


void Game_Finalize(){
	int x;
	for(x=0;x<9;x++){
		d[x]=0;
	}
	junb=0;
	ikkai=0;
	kakunin=0;
	one=0;
	count=0;
	jikan=0;
	kati=3;
	InitSoundMem();
}
//作成：0G02029鳥井旋里

#include "DxLib.h"
#include "Keyboard.h"
#include "Game.h"
#include "Marubatu.h"
#include "Bord1.h"
#include "SceneMgr.h"

static int Bselect;

extern char a[9];
extern char b[9];
extern char c[9];
extern char d[9];


extern int j;
extern int junb;
extern int ju;
extern int one;
extern char jun[];

int next=0;
int next0=0;
int next1=0;
int next2=0;
int onazi=10;

extern int kati;

extern int jikaku;

extern int SE;
extern int BGM; 

static e1_X = 475;		// 上左
static e1_Y = 370;              
static e2_X = 585;               // 上中
static e2_Y = 370;
static e3_X = 695;               // 上右
static e3_Y = 370;
static e4_X = 475;               // 中左
static e4_Y = 480;
static e5_X = 585;               // 中央
static e5_Y = 480;
static e6_X = 695;               // 中右
static e6_Y = 480;
static e7_X = 475;               // 下左
static e7_Y = 590;
static e8_X = 585;               // 下中
static e8_Y = 590;
static e9_X = 695;               // 下右      
static e9_Y = 590;

typedef enum{
	e_1,
	e_2,
	e_3,
	e_4,
	e_5,
	e_6,
	e_7,
	e_8,
	e_9
}e;
              
int NowSelect = e_1;
int selectC=0;

int Sentaku_Update(){
        static HandleS1,HandleS2;
	
	ChangeVolumeSoundMem( 255 * SE / 100, HandleS1 ) ;
	
	if(Keyboard_Get(KEY_INPUT_DOWN)==1){
		if(kati==3){
	
        		NowSelect = (NowSelect+3)%9;
			HandleS1 = LoadSoundMem("titlemove.mp3");
			PlaySoundMem(HandleS1,DX_PLAYTYPE_BACK);
		}
	}
	if(Keyboard_Get(KEY_INPUT_UP)==1){
		if(kati==3){
	
			if((NowSelect==0)||(NowSelect==1)||(NowSelect==2)){
				NowSelect += 9;
			}
        		NowSelect = (NowSelect-3)%9;
			HandleS1 = LoadSoundMem("titlemove.mp3");
			PlaySoundMem(HandleS1,DX_PLAYTYPE_BACK);
        	}	
	}
	if(Keyboard_Get(KEY_INPUT_LEFT)==1){
		if(kati==3){
		
        		if(NowSelect%3==0 ){
				NowSelect += 3;
			}
			NowSelect = (NowSelect-1)%9;
			HandleS1 = LoadSoundMem("titlemove.mp3");
			PlaySoundMem(HandleS1,DX_PLAYTYPE_BACK);
		}
	}
	if(Keyboard_Get(KEY_INPUT_RIGHT)==1){
        	if(kati==3){
	
			if(NowSelect%3==2){
				NowSelect -= 3;
			}
			NowSelect = (NowSelect+1)%9;
			HandleS1 = LoadSoundMem("titlemove.mp3");
			PlaySoundMem(HandleS1,DX_PLAYTYPE_BACK);
		}
	}
	if(Keyboard_Get(KEY_INPUT_RETURN)==1){
		if(d[NowSelect]==0){
			HandleS2 = LoadSoundMem("titleselect.mp3");
			PlaySoundMem(HandleS2,DX_PLAYTYPE_BACK);
			ChangeVolumeSoundMem( 255 * SE / 100, HandleS2 ) ;
			d[NowSelect] = jun[junb];
			junb++;
		}	
        }
}

	
void Sentaku_Draw(){

	Game_Frame();
	
	if(one!=0){
		if(jikaku==0){
			Game_E1();
		}
		else{
			Game_E1NW();
		}
	}                                         
	static HandleS;
	int x=0;
	int y=0;
	switch(NowSelect){
		case e_1:
			x=e1_X;
			y=e1_Y;
        		break;
		case e_2:
			x=e2_X;
			y=e2_Y;
        		break;
		case e_3:
			x=e3_X;
			y=e3_Y;
        		break;
		case e_4:
			x=e4_X;
			y=e4_Y;
        		break;
		case e_5:
			x=e5_X;
			y=e5_Y;
        		break;
		case e_6:
			x=e6_X;
			y=e6_Y;
        		break;
		case e_7:
			x=e7_X;
			y=e7_Y;
        		break;
		case e_8:
			x=e8_X;
			y=e8_Y;
        		break;
		case e_9:
			x=e9_X;
			y=e9_Y;
        		break;
	}
       
        HandleS=LoadGraph("sentaku.png",TRUE);
	DrawGraph(x, y, HandleS, TRUE);
	
}


void SentakuN1_Update(){
        static HandleS1,HandleS2,HandleBubu;

	HandleS1 = LoadSoundMem("titlemove.mp3");
	HandleS2 = LoadSoundMem("titleselect.mp3");
	HandleBubu=LoadSoundMem("bubu.mp3");
	
	ChangeVolumeSoundMem( 255 * SE / 100, HandleS1 ) ;
	
	if(Keyboard_Get(KEY_INPUT_LEFT)==1){
        	if(NowSelect%3==0 ){
			NowSelect += 3;
		}
		NowSelect = (NowSelect-1)%9;
		PlaySoundMem(HandleS1,DX_PLAYTYPE_BACK);
	}
	if(Keyboard_Get(KEY_INPUT_RIGHT)==1){
    		if(NowSelect%3==2){
			NowSelect -= 3;
		}
		NowSelect = (NowSelect+1)%9;
		PlaySoundMem(HandleS1,DX_PLAYTYPE_BACK);
	
	}
	if(Keyboard_Get(KEY_INPUT_RETURN)==1){
		if(onazi!=Bselect){
			PlaySoundMem(HandleS2,DX_PLAYTYPE_BACK);
			ChangeVolumeSoundMem( 255 * SE / 100, HandleS2 ) ;
			selectC=1;
		}
		else{
			PlaySoundMem(HandleBubu,DX_PLAYTYPE_BACK);
			ChangeVolumeSoundMem( 255 * SE / 100, HandleBubu ) ;
		}
	}		
}


void SentakuN1_Draw(){
	Game_E1();

	static HandleS;
	int x=0;
	int y=370;
	switch(NowSelect){
		case e_1:
		case e_4:
		case e_7:
			x=75;
			Bselect=1;
			break;
		case e_2:
		case e_5:
		case e_8:
			x=475;
			Bselect=2;
			break;
		case e_3:
		case e_6:
		case e_9:
			x=875;
			Bselect=3;
			break;
	}
       
        HandleS=LoadGraph("sentaku2.png",TRUE);
	DrawGraph(x, y, HandleS, TRUE);
}


void SentakuN2_Update(){
	int k;
        static HandleS1,HandleS2,HandleBubu,HandleN;
	
	ChangeVolumeSoundMem( 255 * SE / 100, HandleS1 ) ;
	
	if(Keyboard_Get(KEY_INPUT_DOWN)==1){
        		NowSelect = (NowSelect+3)%9;
			HandleS1 = LoadSoundMem("titlemove.mp3");
			PlaySoundMem(HandleS1,DX_PLAYTYPE_BACK);
	}
	if(Keyboard_Get(KEY_INPUT_UP)==1){
		if((NowSelect==0)||(NowSelect==1)||(NowSelect==2)){
			NowSelect += 9;
		}
       		NowSelect = (NowSelect-3)%9;
		HandleS1 = LoadSoundMem("titlemove.mp3");
		PlaySoundMem(HandleS1,DX_PLAYTYPE_BACK);
	}
	if(Keyboard_Get(KEY_INPUT_LEFT)==1){
       		if(NowSelect%3==0 ){
			NowSelect += 3;
		}
		NowSelect = (NowSelect-1)%9;
		HandleS1 = LoadSoundMem("titlemove.mp3");
		PlaySoundMem(HandleS1,DX_PLAYTYPE_BACK);
	}
	if(Keyboard_Get(KEY_INPUT_RIGHT)==1){
		if(NowSelect%3==2){
			NowSelect -= 3;
		}
		NowSelect = (NowSelect+1)%9;
		HandleS1 = LoadSoundMem("titlemove.mp3");
		PlaySoundMem(HandleS1,DX_PLAYTYPE_BACK);
	}
	if(Keyboard_Get(KEY_INPUT_RETURN)==1){
		if(next==0){
			if(Bselect==1){
				if(a[NowSelect]==1&&(onazi==10||onazi!=1)&&b[NowSelect]!=3&&c[NowSelect]!=3){
					HandleN = LoadSoundMem("nico.wav");
					PlaySoundMem(HandleN,DX_PLAYTYPE_BACK);
					ChangeVolumeSoundMem( 255 * SE / 100, HandleN ) ;
					a[NowSelect] = 3;
					next=1;
					next0=1;
					onazi=1;
				}
				else{
				HandleBubu = LoadSoundMem("bubu.mp3");
				PlaySoundMem(HandleBubu,DX_PLAYTYPE_BACK);
				ChangeVolumeSoundMem( 255 * SE / 100, HandleBubu ) ;
				selectC=0;
				}
		        }
		        if(Bselect==2){
				if(b[NowSelect]==1&&(onazi==10||onazi!=2)&&a[NowSelect]!=3&&c[NowSelect]!=3){
					HandleN = LoadSoundMem("nico.wav");
					PlaySoundMem(HandleN,DX_PLAYTYPE_BACK);
					ChangeVolumeSoundMem( 255 * SE / 100, HandleN ) ;
					b[NowSelect] = 3;
					next=1;
					next0=1;
					onazi=2;
				}
				else{
				HandleBubu = LoadSoundMem("bubu.mp3");
				PlaySoundMem(HandleBubu,DX_PLAYTYPE_BACK);
				ChangeVolumeSoundMem( 255 * SE / 100, HandleBubu ) ;
				selectC=0;
				}
		        				
		        }
			if(Bselect==3){
				if(c[NowSelect]==1&&(onazi==10||onazi!=3)&&a[NowSelect]!=3&&b[NowSelect]!=3){
					HandleN = LoadSoundMem("nico.wav");
					PlaySoundMem(HandleN,DX_PLAYTYPE_BACK);
					ChangeVolumeSoundMem( 255 * SE / 100, HandleN ) ;
					c[NowSelect] = 3;
					next=1;
					next0=1;
					onazi=3;
				}
				else{
				HandleBubu = LoadSoundMem("bubu.mp3");
				PlaySoundMem(HandleBubu,DX_PLAYTYPE_BACK);
				ChangeVolumeSoundMem( 255 * SE / 100, HandleBubu ) ;
				selectC=0;
				}
		        		
	       		}
		}
		else if(next==1){
			if(Bselect==1){
				for(k=0;k<9&&a[k]!=0;k++){
					if(k==8){
						selectC=0;
					}	
				}
				if(a[NowSelect]==0){
					HandleS2 = LoadSoundMem("titleselect.mp3");
					PlaySoundMem(HandleS2,DX_PLAYTYPE_BACK);
					ChangeVolumeSoundMem( 255 * SE / 100, HandleS2 ) ;
					a[NowSelect] = 2;
					next=2;
					next1=1;
				}
				else{
				HandleBubu = LoadSoundMem("bubu.mp3");
				PlaySoundMem(HandleBubu,DX_PLAYTYPE_BACK);
				ChangeVolumeSoundMem( 255 * SE / 100, HandleBubu ) ;
				}
		        		
		        }
		        if(Bselect==2){
				for(k=0;k<9&&b[k]!=0;k++){
					if(k==8){
						selectC=0;
					}	
				}
				if(b[NowSelect]==0){
					HandleS2 = LoadSoundMem("titleselect.mp3");
					PlaySoundMem(HandleS2,DX_PLAYTYPE_BACK);
					ChangeVolumeSoundMem( 255 * SE / 100, HandleS2 ) ;
					b[NowSelect] = 2;
					next=2;
					next1=1;
				}
				else{
				HandleBubu = LoadSoundMem("bubu.mp3");
				PlaySoundMem(HandleBubu,DX_PLAYTYPE_BACK);
				ChangeVolumeSoundMem( 255 * SE / 100, HandleBubu ) ;
				}
		        		
		        }
			if(Bselect==3){
				for(k=0;k<9&&c[k]!=0;k++){
					if(k==8){
						selectC=0;
					}	
				}
				if(c[NowSelect]==0){
					HandleS2 = LoadSoundMem("titleselect.mp3");
					PlaySoundMem(HandleS2,DX_PLAYTYPE_BACK);
					ChangeVolumeSoundMem( 255 * SE / 100, HandleS2 ) ;
					c[NowSelect] = 2;
					next=2;
					next1=1;
				}
				else{
				HandleBubu = LoadSoundMem("bubu.mp3");
				PlaySoundMem(HandleBubu,DX_PLAYTYPE_BACK);
				ChangeVolumeSoundMem( 255 * SE / 100, HandleBubu ) ;
				}
		        		
	       		}
		}
		else if(next==2){
			if(Bselect==1){
				for(k=0;k<9&&a[k]!=0;k++){
					if(k==8){
						selectC=0;
						next=3;
						next2=1;
						ju++;
					}	
				}
				if(a[NowSelect]==0){
					HandleS2 = LoadSoundMem("titleselect.mp3");
					PlaySoundMem(HandleS2,DX_PLAYTYPE_BACK);
					ChangeVolumeSoundMem( 255 * SE / 100, HandleS2 ) ;
					a[NowSelect] = 2;
					next=3;
					next2=1;
					ju++;
				}
				else{
				HandleBubu = LoadSoundMem("bubu.mp3");
				PlaySoundMem(HandleBubu,DX_PLAYTYPE_BACK);
				ChangeVolumeSoundMem( 255 * SE / 100, HandleBubu ) ;
				}
		        		
		        }
		        if(Bselect==2){
				for(k=0;k<9&&b[k]!=0;k++){
					if(k==8){
						selectC=0;
						next=3;
						next2=1;
						ju++;
					}	
				}
				if(b[NowSelect]==0){
					HandleS2 = LoadSoundMem("titleselect.mp3");
					PlaySoundMem(HandleS2,DX_PLAYTYPE_BACK);
					ChangeVolumeSoundMem( 255 * SE / 100, HandleS2 ) ;
					b[NowSelect] = 2;
					next=3;
					next2=1;
					ju++;
				}
				else{
				HandleBubu = LoadSoundMem("bubu.mp3");
				PlaySoundMem(HandleBubu,DX_PLAYTYPE_BACK);
				ChangeVolumeSoundMem( 255 * SE / 100, HandleBubu ) ;
				}
		        		
		        }
			if(Bselect==3){
				for(k=0;k<9&&c[k]!=0;k++){
					if(k==8){
						selectC=0;
						next=3;
						next2=1;
						ju++;
					}	
				}
				if(c[NowSelect]==0){
					HandleS2 = LoadSoundMem("titleselect.mp3");
					PlaySoundMem(HandleS2,DX_PLAYTYPE_BACK);
					ChangeVolumeSoundMem( 255 * SE / 100, HandleS2 ) ;
					c[NowSelect] = 2;
					next=3;
					next2=1;
					ju++;
				}	
				else{
				HandleBubu = LoadSoundMem("bubu.mp3");
				PlaySoundMem(HandleBubu,DX_PLAYTYPE_BACK);
				ChangeVolumeSoundMem( 255 * SE / 100, HandleBubu ) ;
				}
		        	
	       		}
		}
		
		if(next0==1||next1==1||next2==1){
			switch(Bselect){
				case 1:
					Bselect=2;
					if(next0==1){
						next0++;
					}
					if(next1==1){
						next1++;
					}
					if(next2==1){
						next2++;
					}
					
					break;
				case 2:
					Bselect=3;
					if(next1==1){
						next1++;
					}
					if(next2==1){
						next2++;
					}
					if(next0==1){
						next0++;
					}
					break;
				case 3:
					Bselect=1;
					if(next1==1){
						next1++;
					}
					if(next2==1){
						next2++;
					}
					if(next0==1){
						next0++;
					}
					break;					
			}
		}

	 }

}

void SentakuN2_Draw(){
	Game_E1();

	static HandleS;
	int x=0;
	int y=0;
	int a=0,c=0;
	if(Bselect==1){
		a-=400;
	}
	if(Bselect==2){
		a=0;
		c=0;
	}
	if(Bselect==3){
		c+=400;
	}
	switch(NowSelect){
		case e_1:
			x=e1_X+a+c;
			y=e1_Y;
        		break;
		case e_2:
			x=e2_X+a+c;
			y=e2_Y;
        		break;
		case e_3:
			x=e3_X+a+c;
			y=e3_Y;
        		break;
		case e_4:
			x=e4_X+a+c;
			y=e4_Y;
        		break;
		case e_5:
			x=e5_X+a+c;
			y=e5_Y;
        		break;
		case e_6:
			x=e6_X+a+c;
			y=e6_Y;
        		break;
		case e_7:
			x=e7_X+a+c;
			y=e7_Y;
        		break;
		case e_8:
			x=e8_X+a+c;
			y=e8_Y;
        		break;
		case e_9:
			x=e9_X+a+c;
			y=e9_Y;
        		break;
	}
       
        HandleS=LoadGraph("sentaku.png",TRUE);
	DrawGraph(x, y, HandleS, TRUE);
}


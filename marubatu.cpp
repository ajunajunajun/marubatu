//作成：0G02029鳥井旋里

//ヘッダファイル
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "Main.h"
#include "Dxlib.h"
#include "Game.h"
#include "Marubatu.h"
#include "Sentaku.h"
#include "Keyboard.h"
#include "SceneMgr.h"


//グローバル変数
char d[9]={0,0,0,0,0,0,0,0,0};	//〇×の場所

int ikkai=0;
int kakunin=0;
int junb=0;
int jikaku=0;
char jun[]={1,2,1,2,1,2,1,2,1,2};
int jikan=0;
int nyuuryoku;	//入力
char kati;
extern int ninzuu;

static Cr = GetColor(255,255,255);
static CrR = GetColor(255,0,0); 
	
//〇×ゲーム
//x=人数（１OR２）ｙ＝先攻後攻（０＝先行１＝後行２＝二人）
int marubatu(int x,int y){
	static HandleW,HandleL;

	int i=0;
	
	if(jikan!=0){
		Maru_TimeDraw();
        }
	
	if(x==2||junb%2==y){
		Sentaku_Update();
		if(kati==3&&jikan!=0){	
			if(GetNowCount() - jikan > 6000){
				kati=4;
			}
		} 	                	
	}
      	
	else{
		if(kati==3){
			if(jikaku==0){
				Game_E1A1();
			}
			d[com(jun[junb],jun[junb+1])]=jun[junb];
			junb++;
			ikkai++;
			kakunin++;
		}
	}
      	
	static HandleF,HandleM,HandleB;
	int e,f,g;
	HandleF=LoadGraph("frame.png",TRUE);
	HandleM=LoadGraph("maru.png",TRUE);
	HandleB=LoadGraph("batu.png",TRUE);
   	DrawGraph( 475, 370, HandleF, TRUE );
      	
	g=0;
	for(f=0;f<3;f++){
		for(e=0;e<3;e++,g++){
			if(d[g]==1){
				DrawGraph( 475+e*110, 370+f*110, HandleM, TRUE );
			}
			if(d[g]==2){
				DrawGraph( 475+e*110, 370+f*110, HandleB, TRUE );
			}
		}
	}
        if(kati==3){
		kati=syouhai();
	}

	static HandleRH,HandleRM,HandleRB,HandleRT;
	int t;
	if(kati==0){                        	
		HandleRH=LoadGraph("hiki.png",TRUE);
		Game_ExitE1();
        	DrawGraph( 475, 370, HandleRH, TRUE );		
	}
	else if(kati==1){                        	
		HandleRM=LoadGraph("winm.png",TRUE);
		Game_ExitE1();
		DrawGraph( 475, 370, HandleRM, TRUE );
	}
	else if(kati==2){                   	
		HandleRB=LoadGraph("winb.png",TRUE);
       		Game_ExitE1();
		DrawGraph( 475, 370, HandleRB, TRUE );
	}
	else if(kati==4){                   	
		HandleRT=LoadGraph("time.png",TRUE);     //時間切れ
       		Maru_TimeDraw();
		Game_ExitE1();
		DrawGraph( 475, 370, HandleRT, TRUE );
	}

}

//勝敗判定
//勝敗判定
char syouhai(void){

	int k;
	char j=3;

	for(k=0;k<9&&d[k]!=0;k++){
		;
	}
	if(k==9)
		j=0;

	for(k=0;k<8;k+=3){
		if(d[k]==d[k+1]&&d[k]==d[k+2]&&d[k]!=0)
			j=d[k];
	}				//横
	for(k=0;k<3;k++){
		if(d[k]==d[k+3]&&d[k]==d[k+6]&d[k]!=0)
			j=d[k];
	}
	if(d[0]==d[4]&&d[0]==d[8]&&d[0]!=0)
		j=d[0];
	if(d[2]==d[4]&&d[2]==d[6]&&d[2]!=0)
		j=d[2];		//ななめ

	return j;
}

//コンピューター（一人時）
int com(char x,char y){

	int k,r=4;

	
	if((d[1]==d[2])&&(d[2]==d[3])&&(d[3]==d[4])&&(d[4]==d[5])&&(d[5]==d[6])&&(d[6]==d[7])&&(d[7]==d[8])&&d[2]==0&&d[4]==0&&d[6]==0&&d[8]==0){
		if(d[0]==1){
			return 8;
		}
	}
        if((d[0]==0&&d[1]==0)&&(d[2]==1&&d[3]==0)&&(d[4]==0&&d[5]==0)&&(d[6]==0&&d[7]==0)&&d[8]==0){
		if(d[2]==1){
			return 6;
		}
	}
	if((d[0]==d[1])&&(d[1]==d[2])&&(d[2]==d[3])&&(d[3]==d[4])&&(d[4]==d[5])&&(d[5]==d[7])&&(d[7]==d[8])&&d[1]==0&&d[3]==0&&d[5]==0&&d[8]==0){
		if(d[6]==1){
			return 2;
		}
	}
	if((d[0]==d[1])&&(d[1]==d[2])&&(d[2]==d[3])&&(d[3]==d[4])&&(d[4]==d[5])&&(d[5]==d[6])&&(d[6]==d[7])&&d[0]==0&&d[2]==0&&d[4]==0&&d[6]==0){
		if(d[8]==1){
			return 0;
		}
	}


//自分リーチ

	for(k=0;k<8;k+=3){
		if((d[k]==d[k+1]&&d[k]==x)||(d[k]==d[k+2]&&d[k]==x)||(d[k+1]==d[k+2]&&d[k+1]==x)){
			if(d[k+2]==0)
				return k+2;
			else if(d[k+1]==0)
				return k+1;
			else if(d[k]==0)
				return k;
			else
				;
		}				//横
	}

	for(k=0;k<3;k++){
		if((d[k]==d[k+3]&&d[k]==x)||(d[k]==d[k+6]&&d[k]==x)||(d[k+3]==d[k+6]&&d[k+3]==x)){
			if(d[k+6]==0)
				return k+6;
			else if(d[k+3]==0)
				return k+3;
			else if(d[k]==0)
				return k;
			else
				;
		}					//縦
	}

	if((d[0]==d[4]&&d[0]==x)||(d[0]==d[8]&&d[0]==x)||(d[4]==d[8]&&d[4]==x)){
		if(d[0]==0)
			return 0;
		else if(d[4]==0)
			return 4;
		else if(d[8]==0)
			return 8;
		else
			;
		}


	if((d[2]==d[4]&&d[2]==x)||(d[0]==d[6]&&d[2]==x)||(d[4]==d[6]&&d[4]==x)){
		if(d[2]==0)
			return 2;
		else if(d[4]==0)
			return 4;
		else if(d[6]==0)
			return 6;
		else
			;
		}				//ななめ
//自分リーチ




//相手リーチ
	for(k=0;k<8;k+=3){
		if((d[k]==d[k+1]&&d[k]==y)||(d[k]==d[k+2]&&d[k]==y)||(d[k+1]==d[k+2]&&d[k+1]==y)){
			if(d[k+2]==0)
				return k+2;
			else if(d[k+1]==0)
				return k+1;
			else if(d[k]==0)
				return k;
			else
				;
		}				//横
	}

	for(k=0;k<3;k++){
		if((d[k]==d[k+3]&&d[k]==y)||(d[k]==d[k+6]&&d[k]==y)||(d[k+3]==d[k+6]&&d[k+3]==y)){
			if(d[k+6]==0)
				return k+6;
			else if(d[k+3]==0)
				return k+3;
			else if(d[k]==0)
				return k;
			else
				;
		}
	}					//縦


	if((d[0]==d[4]&&d[0]==y)||(d[0]==d[8]&&d[0]==y)||(d[4]==d[8]&&d[4]==y)){
		if(d[0]==0)
			return 0;
		else if(d[4]==0)
			return 4;
		else if(d[8]==0)
			return 8;
			else
				;
		}


	if((d[2]==d[4]&&d[2]==y)||(d[0]==d[6]&&d[2]==y)||(d[4]==d[6]&&d[4]==y)){
		if(d[2]==0)
			return 2;
		else if(d[4]==0)
			return 4;
		else if(d[6]==0)
			return 6;
			else
				;
		}			//ななめ
//相手リーチ



//先撃ち
	if((d[0]==d[2])&&(d[1]==2)&&(d[4]==1)&&(d[2]==d[3])&&(d[3]==d[5])&&(d[5]==d[6])&&(d[6]==d[7])&&(d[7]==d[8])&&d[2]==0&&d[5]==0&&d[7]==0){
		if(d[3]==0){
			return 3;
		}
	}
	if((d[0]==d[1])&&(d[3]==2)&&(d[4]==1)&&(d[1]==d[2])&&(d[2]==d[5])&&(d[5]==d[6])&&(d[6]==d[7])&&(d[7]==d[8])&&d[1]==0&&d[5]==0&&d[7]==0){
		if(d[7]==0){
			return 7;
		}
	}
	if((d[0]==d[1])&&(d[5]==2)&&(d[4]==1)&&(d[1]==d[2])&&(d[2]==d[3])&&(d[3]==d[6])&&(d[6]==d[7])&&(d[7]==d[8])&&d[1]==0&&d[3]==0&&d[7]==0){
		if(d[1]==0){
			return 1;
		}
	}
	if((d[0]==d[1])&&(d[7]==2)&&(d[4]==1)&&(d[1]==d[2])&&(d[2]==d[3])&&(d[3]==d[5])&&(d[5]==d[6])&&(d[6]==d[8])&&d[1]==0&&d[3]==0&&d[6]==0){
		if(d[5]==0){
			return 5;
		}
	}
	
	if(kakunin==2&&(d[1]==d[3]&&d[1]==y)&&d[8]==0){
		return 8;
	}
	if(kakunin==2&&(d[1]==d[5]&&d[1]==y)&&d[6]==0){
		return 6;
	}
	if(kakunin==2&&(d[3]==d[7]&&d[3]==y)&&d[2]==0){
		return 2;
	}
	if(kakunin==2&&(d[5]==d[7]&&d[5]==y)&&d[0]==0){
		return 0;
	}
//先撃ち
//後撃ち初手角
	if((d[0]==d[1])&&(d[2]==d[3])&&(d[4]!=0)&&(d[5]==d[6])&&(d[7]==d[8])&&d[0]==0&&d[2]==0&&d[5]==0&&d[7]==0){
		if(d[0]==0){
			return 0;
		}
	}
	if(ikkai==1&&d[8]!=0){
		return 6;
	}
		
//後撃ち初手角
//後撃ち角つぶし
	if((d[1]==d[3]&&d[1]==y)&&d[0]==0){
		return 0;
	}
	if((d[1]==d[5]&&d[1]==y)&&d[2]==0){
		return 2;
	}
	if((d[3]==d[7]&&d[3]==y)&&d[6]==0){
		return 6;
	}
	if((d[5]==d[7]&&d[5]==y)&&d[8]==0){
		return 8;
	}
//後撃ち角つぶし
//後撃ち辺つぶし		
	if(d[0]==d[5]&&d[0]==y){
		if(d[2]==0)
			return 2;
	}	
	if(d[0]==d[7]&&d[0]==y){
		if(d[6]==0)
			return 6;
	}
	if(d[2]==d[3]&&d[2]==y){
		if(d[0]==0)
			return 0;
	}
	if(d[2]==d[7]&&d[2]==y){
		if(d[8]==0)
			return 8;
	}
	if(d[6]==d[5]&&d[6]==y){
		if(d[8]==0)
			return 8;
	}
	if(d[6]==d[1]&&d[6]==y){
		if(d[0]==0)
			return 0;
	}
	if(d[8]==d[1]&&d[8]==y){
		if(d[5]==0)
			return 5;
	}
	if(d[8]==d[3]&&d[8]==y){
		if(d[6]==0)
			return 6;
	}
//後撃ち辺つぶし





/*先撃ちvsAI //もろいaiには勝てるが乱数で負ける可能性あり
	if((d[0]==d[1])&&(d[2]==d[3])&&(d[4]==d[5])&&(d[6]==d[7])&&(d[8]==d[0])&&d[0]==0&&d[2]==0&&d[4]==0&&d[6]==0&&d[8]==0){
		if(d[0]==0)
			return 0;
	}
	if((d[1]==d[2])&&(d[3]==d[5])&&(d[6]==d[7])&&(d[8]==d[9])&&d[1]==0&&d[3]==0&&d[6]==0&&d[8]==0){
		if(d[5]==0)
			return 5;
	}
	if((d[1]==d[2])&&(d[2]==d[8])&&d[1]==0&&d[2]==0){
		if(d[2]==0)
			return 2;
	}
先撃ちvsAI*/	
	
	
	srand((unsigned)time(NULL));

	while(d[r]!=0)
		r=rand()%9;



	return r;
	
}

void Maru_TimeDraw(){
	int t=1;
	
	int HandleM;
	static int a[4];
	if(kati==3){
		t=(6000 - (GetNowCount() - jikan));
		a[0] = (t % 100);
		t /= 100;
		a[1] = (t % 10);
		t /= 10;
		a[2] = (t % 10);
		t /= 10;
		a[3] = 0;
	}
	else if(kati==4){
		a[0]=0;
		a[1]=0;
		a[2]=0;
		a[3]=0;
		
	}
	SetFontSize(470);                
	DrawFormatString(0,-70,CrR,"%d%d.%d%d%.d",a[3],a[2],a[1],a[0],a[0]) ;
		
}

void Maru_EntryET(){                        	
	static a;
	static Handle1,HandleT,HandleT6;
		
	Handle1=LoadGraph("enemy1.png",TRUE);
	for(a=0;Process() && a<=360;a+=10){
		DrawGraph(460,-360+a,Handle1,TRUE);     
		Game_Frame();
	}
	WaitTimer(1000);
	
	HandleT=LoadGraph("timer.png",TRUE);
	for(a=0;Process() && a<=360;a+=30){
		DrawGraph(0,-360+a,HandleT,TRUE);
		DrawGraph(460,0,Handle1,TRUE);	
		Game_Frame();
	}
	WaitTimer(1000);
	
	HandleT6=LoadGraph("timer6.png",TRUE);
	for(a=0;Process() && a<=360;a+=30){
		DrawGraph(0,0,HandleT,TRUE);	
		DrawGraph(460,0,Handle1,TRUE);	
		DrawGraph(240,-365+a,HandleT6,TRUE);	
		Game_Frame();
	}
	WaitTimer(1000);
}

			
//作成：0G02029鳥井旋里

#include<stdio.h>
#include<stdlib.h>

#include "Dxlib.h"
#include "Game.h"
#include "Nico.h"
#include "Sentaku.h"
#include "Keyboard.h"
#include "SceneMgr.h"

char a[9]={0,0,0,0,0,0,0,0,0};	
char b[9]={0,0,0,0,0,0,0,0,0};
char c[9]={0,0,0,0,0,0,0,0,0};	//〇×の場所

int j=0;
int ju=0;

int owari=0;

extern int one;

extern int SE;
extern int BGM;

static HandleBGM;
		
static int HandleMARU,HandleBATU,HandleNICO,HandleFrame;
	       
int kati1,kati2,kati3;
	                      
extern int selectC;
extern int next;
extern int next0;
extern int next1;
extern int next2;
extern int onazi;

extern int next;

void Nico_Update(){
	if(Keyboard_Get(KEY_INPUT_ESCAPE)==1){
		Game_Delete();
		InitSoundMem();
		SceneMgr_ChangeScene(eScene_Title);
		selectC=0;
	}	
}
		


void Nico_Draw(){
	static HandleFrame;
        static HandleNBGM;

                                                      
/*	if(one==0){
        	Game_EntryE1();
		one++;
	}
*/	
	if(CheckSoundMem(HandleNBGM) != 1){
		HandleNBGM = LoadSoundMem("nicobgm.mp3");
		PlaySoundMem(HandleNBGM,DX_PLAYTYPE_BACK);
	}
	ChangeVolumeSoundMem( 255 * BGM / 100, HandleNBGM ) ;

	HandleFrame=LoadGraph("frame.png",TRUE);

	DrawGraph(75,370,HandleFrame,TRUE);
	DrawGraph(475,370,HandleFrame,TRUE);
	DrawGraph(875,370,HandleFrame,TRUE);

	Nico();
	
	if(owari==0){
		if(selectC==0){
			SentakuN1_Draw();
		}
		else if(selectC==1){ 
			SentakuN2_Draw();
		}
	}	
	

}


void Nico(void){
	static HandleRH,HandleRM,HandleRB,HandleRT;

	int nyuuryoku;	//入力
	int nyuuryoku2=0;
	static int i=0,k=0,n=0;
	char kati1=5,kati2=5,kati3=5;

	HandleMARU=LoadGraph("maru.png",TRUE);
	HandleBATU=LoadGraph("batu.png",TRUE);
	HandleNICO=LoadGraph("nicochan.png",TRUE);
	HandleFrame=LoadGraph("frame.png",TRUE);

	if(j==0){
		a[4]=1;
		b[4]=1;
		c[4]=1;
		Game_E1A2();
        	j++;
	}
	if(owari==0){
		if(ju%2==0){
		
			if(selectC==0){
				SentakuN1_Update();
			}
			else if(selectC==1){
				SentakuN2_Update();
			}
		}
	        else{
			Game_E1A2();	
			selectC=0;
			next=0;
			next0=0;
			next1=0;
			next2=0;
			srand((unsigned)time(NULL));

			kati1=syouhai(1);
			kati2=syouhai(2);
			kati3=syouhai(3);
	
			if(kati1!=0){
				do{
					i=com(1,2,j,1);
					if(a[i]!=0){
						i=rand()%9;
						k++;
					}
				}while(a[i]!=0||k==8);
			k=0;
			a[i]=1;
			}
			if(kati2!=0){
				do{
					i=com(1,2,j,2);
					if(b[i]!=0){
						i=rand()%9;
						i=rand()%9;
						k++;
					}
				}while(b[i]!=0||k==8);
			k=0;				
			b[i]=1;
	   		}       	
			if(kati3!=0){
				do{
					i=com(1,2,j,3);
					if(c[i]!=0){
						i=rand()%9;
						i=rand()%9;
						i=rand()%9;
						k++;
					}
				}while(c[i]!=0||k==8);
			k=0;
			c[i]=1;
			}
		ju++;
		}	
	}
	static HandleM,HandleB,HandleN;
	int e,f,g;
	HandleM=LoadGraph("maru.png",TRUE);
	HandleB=LoadGraph("batu.png",TRUE);
	HandleN=LoadGraph("nicochan.png",TRUE);

   	if(next==0){
		DrawGraph( 100, 100, HandleN, TRUE );
        }
	if(next==1){
		DrawGraph( 100, 100, HandleB, TRUE );
        }
	if(next==2){
		DrawGraph( 100, 100, HandleB, TRUE );
        }
	
	
	g=0;
	for(f=0;f<3;f++){
		for(e=0;e<3;e++,g++){
			if(a[g]==1){
				DrawGraph( 75+e*110, 370+f*110, HandleM, TRUE );
			}
			if(a[g]==2){
				DrawGraph( 75+e*110, 370+f*110, HandleB, TRUE );
			}
			if(a[g]==3){
				DrawGraph( 75+e*110, 370+f*110, HandleN, TRUE );
			}
		}
	}
	g=0;
	for(f=0;f<3;f++){
		for(e=0;e<3;e++,g++){
			if(b[g]==1){
				DrawGraph( 475+e*110, 370+f*110, HandleM, TRUE );
			}
			if(b[g]==2){
				DrawGraph( 475+e*110, 370+f*110, HandleB, TRUE );
			}
			if(b[g]==3){
				DrawGraph( 475+e*110, 370+f*110, HandleN, TRUE );
			}
		}
	}
	g=0;
	for(f=0;f<3;f++){
		for(e=0;e<3;e++,g++){
			if(c[g]==1){
				DrawGraph( 875+e*110, 370+f*110, HandleM, TRUE );
			}
			if(c[g]==2){
				DrawGraph( 875+e*110, 370+f*110, HandleB, TRUE );
			}
			if(c[g]==3){
				DrawGraph( 875+e*110, 370+f*110, HandleN, TRUE );
			}
		}
	}
        	
	
	i=0;	

	kati1=syouhai(1);
	kati2=syouhai(2);
	kati3=syouhai(3);

	if(kati1==0&&kati2==0&&kati3==0){                        	
		HandleRH=LoadGraph("hikin.png",TRUE);
		DrawGraph( 75, 370, HandleRH, TRUE );		
		InitSoundMem();
		owari=1;
	}
	else if(kati1==1||kati2==1||kati3==1){
		HandleRM=LoadGraph("winmn.png",TRUE);
		DrawGraph( 75, 370, HandleRM, TRUE );
		InitSoundMem();
		owari=1;
	}
	else if(kati1==2||kati2==2||kati3==2){
		HandleRB=LoadGraph("winbn.png",TRUE);
       		DrawGraph( 75, 370, HandleRB, TRUE );
		InitSoundMem();
		owari=1;
	}
	else if(kati1==3||kati2==3||kati3==3){
		HandleRT=LoadGraph("nicon.png",TRUE);     //時間切れ
		DrawGraph( 75, 370, HandleRT, TRUE );
		InitSoundMem();
		owari=1;
	}

/*	if(kati1==0&&kati2==0&&kati3==0){
		printf("にこちゃん失敗");
	}

	if(kati1=='3'||kati2=='3'||kati3=='3')
		printf("にこちゃん成功");
	else if(kati1=='O'||kati2=='O'||kati3=='O')
		printf("負け");
	else
		printf("不具合？");
*/
}

char syouhai(int x){

	int k;
	char j=5;

	if(x==1){

		for(k=0;k<9&&a[k]!=0;k++){
			;
		}
		if(k==9)
			j=0;



		for(k=0;k<8;k+=3){
			if(a[k]==a[k+1]&&a[k]==a[k+2]&&a[k]!=0)
				j=a[k];
		}				//横

		for(k=0;k<3;k++){
			if(a[k]==a[k+3]&&a[k]==a[k+6]&a[k]!=0)
				j=a[k];
		}				//縦

			if(a[0]==a[4]&&a[0]==a[8]&&a[0]!=0)
				j=a[0];

			if(a[2]==a[4]&&a[2]==a[6]&&a[2]!=0)
				j=a[2];		//ななめ
	}

	else if(x==2){

		for(k=0;k<9&&b[k]!=0;k++){
			;
		}
		if(k==9)
			j=0;



		for(k=0;k<8;k+=3){
			if(b[k]==b[k+1]&&b[k]==b[k+2]&&b[k]!=0)
				j=b[k];
		}				//横

		for(k=0;k<3;k++){
			if(b[k]==b[k+3]&&b[k]==b[k+6]&b[k]!=0)
				j=b[k];
		}				//縦

			if(b[0]==b[4]&&b[0]==b[8]&&b[0]!=0)
				j=b[0];

			if(b[2]==b[4]&&b[2]==b[6]&&b[2]!=0)
				j=b[2];		//ななめ
	}

	else if(x==3){

		for(k=0;k<9&&c[k]!=0;k++){
			;
		}
		if(k==9)
			j=0;



		for(k=0;k<8;k+=3){
			if(c[k]==c[k+1]&&c[k]==c[k+2]&&c[k]!=0)
				j=c[k];
		}				//横

		for(k=0;k<3;k++){
			if(c[k]==c[k+3]&&c[k]==c[k+6]&c[k]!=0)
				j=c[k];
		}				//縦

			if(a[0]==c[4]&&c[0]==c[8]&&c[0]!=0)
				j=c[0];

			if(c[2]==c[4]&&c[2]==c[6]&&c[2]!=0)
				j=c[2];		//ななめ
	}	

	return j;
}



//コンピューター（一人時）
int com(char x,char y,int z,int s){

	int k,r=4;
	static int d1=0,d2=0,d3=0,e1=0,e2=0,e3=0;

//自分リーチ

	if(s==1){
	for(k=0;k<8;k+=3){
		if((a[k]==a[k+1]&&a[k]==x)||(a[k]==a[k+2]&&a[k]==x)||(a[k+1]==a[k+2]&&a[k+1]==x)){
			if(a[k+2]==0)
				return k+2;
			else if(a[k+1]==0)
				return k+1;
			else if(a[k]==0)
				return k;
			else
				;
		}				//横
	}

	for(k=0;k<3;k++){
		if((a[k]==a[k+3]&&a[k]==x)||(a[k]==a[k+6]&&a[k]==x)||(a[k+3]==a[k+6]&&a[k+3]==x)){
			if(a[k+6]==0)
				return k+6;
			else if(a[k+3]==0)
				return k+3;
			else if(a[k]==0)
				return k;
			else
				;
		}					//縦
	}

	if((a[0]==a[4]&&a[0]==x)||(a[0]==a[8]&&a[0]==x)||(a[4]==a[8]&&a[4]==x)){
		if(a[0]==0)
			return 0;
		else if(a[4]==0)
			return 4;
		else if(a[8]==0)
			return 8;
		else
			;
		}


	if((a[2]==a[4]&&a[2]==x)||(a[0]==a[6]&&a[2]==x)||(a[4]==a[6]&&a[4]==x)){
		if(a[2]==0)
			return 2;
		else if(a[4]==0)
			return 4;
		else if(a[6]==0)
			return 6;
		else
			;
		}				//ななめ
//自分リーチ




//相手リーチ
	for(k=0;k<8;k+=3){
		if((a[k]==a[k+1]&&a[k]==y)||(a[k]==a[k+2]&&a[k]==y)||(a[k+1]==a[k+2]&&a[k+1]==y)){
			if(a[k+2]==0)
				return k+2;
			else if(a[k+1]==0)
				return k+1;
			else if(a[k]==0)
				return k;
			else
				;
		}				//横
	}

	for(k=0;k<3;k++){
		if((a[k]==a[k+3]&&a[k]==y)||(a[k]==a[k+6]&&a[k]==y)||(a[k+3]==a[k+6]&&a[k+3]==y)){
			if(a[k+6]==0)
				return k+6;
			else if(a[k+3]==0)
				return k+3;
			else if(a[k]==0)
				return k;
			else
				;
		}
	}					//縦


	if((a[0]==a[4]&&a[0]==y)||(a[0]==a[8]&&a[0]==y)||(a[4]==a[8]&&a[4]==y)){
		if(a[0]==0)
			return 0;
		else if(a[4]==0)
			return 4;
		else if(a[8]==0)
			return 8;
			else
				;
		}


	if((a[2]==a[4]&&a[2]==y)||(a[0]==a[6]&&a[2]==y)||(a[4]==a[6]&&a[4]==y)){
		if(a[2]==0)
			return 2;
		else if(a[4]==0)
			return 4;
		else if(a[6]==0)
			return 6;
			else
				;
		}			//ななめ
//相手リーチ

}
//自分リーチ

	if(s==2){
	for(k=0;k<8;k+=3){
		if((b[k]==b[k+1]&&b[k]==x)||(b[k]==b[k+2]&&b[k]==x)||(b[k+1]==b[k+2]&&b[k+1]==x)){
			if(b[k+2]==0)
				return k+2;
			else if(b[k+1]==0)
				return k+1;
			else if(b[k]==0)
				return k;
			else
				;
		}				//横
	}

	for(k=0;k<3;k++){
		if((b[k]==b[k+3]&&b[k]==x)||(b[k]==b[k+6]&&b[k]==x)||(b[k+3]==b[k+6]&&b[k+3]==x)){
			if(b[k+6]==0)
				return k+6;
			else if(b[k+3]==0)
				return k+3;
			else if(b[k]==0)
				return k;
			else
				;
		}					//縦
	}

	if((b[0]==b[4]&&b[0]==x)||(b[0]==b[8]&&b[0]==x)||(b[4]==b[8]&&b[4]==x)){
		if(b[0]==0)
			return 0;
		else if(b[4]==0)
			return 4;
		else if(b[8]==0)
			return 8;
		else
			;
		}


	if((b[2]==b[4]&&b[2]==x)||(b[0]==b[6]&&b[2]==x)||(b[4]==b[6]&&b[4]==x)){
		if(b[2]==0)
			return 2;
		else if(b[4]==0)
			return 4;
		else if(b[6]==0)
			return 6;
		else
			;
		}				//ななめ
//自分リーチ




//相手リーチ
	for(k=0;k<8;k+=3){
		if((b[k]==b[k+1]&&b[k]==y)||(b[k]==b[k+2]&&b[k]==y)||(b[k+1]==b[k+2]&&b[k+1]==y)){
			if(b[k+2]==0)
				return k+2;
			else if(b[k+1]==0)
				return k+1;
			else if(b[k]==0)
				return k;
			else
				;
		}				//横
	}

	for(k=0;k<3;k++){
		if((b[k]==b[k+3]&&b[k]==y)||(b[k]==b[k+6]&&b[k]==y)||(b[k+3]==b[k+6]&&b[k+3]==y)){
			if(b[k+6]==0)
				return k+6;
			else if(b[k+3]==0)
				return k+3;
			else if(b[k]==0)
				return k;
			else
				;
		}
	}					//縦


	if((b[0]==b[4]&&b[0]==y)||(b[0]==b[8]&&b[0]==y)||(b[4]==b[8]&&b[4]==y)){
		if(b[0]==0)
			return 0;
		else if(b[4]==0)
			return 4;
		else if(b[8]==0)
			return 8;
			else
				;
		}


	if((b[2]==b[4]&&b[2]==y)||(b[0]==b[6]&&b[2]==y)||(b[4]==b[6]&&b[4]==y)){
		if(b[2]==0)
			return 2;
		else if(b[4]==0)
			return 4;
		else if(b[6]==0)
			return 6;
		else
				;
		}			//ななめ
//相手リーチ

}

//自分リーチ

	if(s==3){

	for(k=0;k<8;k+=3){
		if((c[k]==c[k+1]&&c[k]==x)||(c[k]==c[k+2]&&c[k]==x)||(c[k+1]==c[k+2]&&c[k+1]==x)){
			if(c[k+2]==0)
				return k+2;
			else if(c[k+1]==0)
				return k+1;
			else if(c[k]==0)
				return k;
			else
				;
		}				//横
	}

	for(k=0;k<3;k++){
		if((c[k]==c[k+3]&&c[k]==x)||(c[k]==c[k+6]&&c[k]==x)||(c[k+3]==c[k+6]&&c[k+3]==x)){
			if(c[k+6]==0)
				return k+6;
			else if(c[k+3]==0)
				return k+3;
			else if(c[k]==0)
				return k;
			else
				;
		}					//縦
	}

	if((c[0]==c[4]&&c[0]==x)||(c[0]==c[8]&&c[0]==x)||(c[4]==c[8]&&c[4]==x)){
		if(c[0]==0)
			return 0;
		else if(c[4]==0)
			return 4;
		else if(c[8]==0)
			return 8;
		else
			;
		}


	if((c[2]==c[4]&&c[2]==x)||(c[0]==c[6]&&c[2]==x)||(c[4]==c[6]&&c[4]==x)){
		if(c[2]==0)
			return 2;
		else if(c[4]==0)
			return 4;
		else if(c[6]==0)
			return 6;
		else
			;
		}				//ななめ
//自分リーチ

}


//相手リーチ
	for(k=0;k<8;k+=3){
		if((c[k]==c[k+1]&&c[k]==y)||(c[k]==c[k+2]&&c[k]==y)||(c[k+1]==c[k+2]&&c[k+1]==y)){
			if(c[k+2]==0)
				return k+2;
			else if(c[k+1]==0)
				return k+1;
			else if(c[k]==0)
				return k;
			else
				;
		}				//横
	}

	for(k=0;k<3;k++){
		if((c[k]==c[k+3]&&c[k]==y)||(c[k]==c[k+6]&&c[k]==y)||(c[k+3]==c[k+6]&&c[k+3]==y)){
			if(c[k+6]==0)
				return k+6;
			else if(c[k+3]==0)
				return k+3;
			else if(c[k]==0)
				return k;
			else
				;
		}
	}					//縦


	if((c[0]==c[4]&&c[0]==y)||(c[0]==c[8]&&c[0]==y)||(c[4]==c[8]&&c[4]==y)){
		if(c[0]==0)
			return 0;
		else if(c[4]==0)
			return 4;
		else if(c[8]==0)
			return 8;
			else
				;
		}


	if((c[2]==c[4]&&c[2]==y)||(c[0]==c[6]&&c[2]==y)||(c[4]==c[6]&&c[4]==y)){
		if(c[2]==0)
			return 2;
		else if(c[4]==0)
			return 4;
		else if(c[6]==0)
			return 6;
			else
				;
		}			//ななめ
//相手リーチ


	srand((unsigned)time(NULL));


	if(z==1&&a[4]==1){
		r=rand()%4;
		switch(r){
			case 0:
				if(a[r]==0){
				e1=0;
				d1++;
				return 0;}
			case 1:
				if(a[r]==0){
				e1=2;
				d1++;
				return 2;}
			case 2:
				if(a[r]==0){
				e1=6;
				d1++;
				return 6;}
			case 3:
				if(a[r]==0){
				e1=8;
				d1++;
				return 8;}
		}
	}

	if(z==3&&d1&&((e1==0&&a[8]==1)||(e1==2&&a[6]==1)||(e1==6&&a[2]==1)||(e1==8&&a[0]==1))){
		r=rand()%2;
			if(e1==0){
				if(r&&a[r]==0)
					return 2;
				else if(a[4]==0)
					return 4;
			}
			if(e1==2){
				if(r&&a[r]==0)
					return 0;
				else if(a[8]==0)
					return 8;
			}
			if(e1==6){
				if(r&&a[r]==0)
					return 0;
				else if(a[8]==0)
					return 8;
			}
			if(e1==8){
				if(r&&a[r]==0)
					return 2;
				else if(a[6]==0)
					return 6;
			}
	}
				//a


	if(z==1&&b[4]==1){
		r=rand()%4;
		switch(r){
			case 0:
				if(b[r]==0){
				e2=0;
				d2++;
				return 0;}
			case 1:
				if(b[r]==0){
				e2=2;
				d2++;
				return 2;}
			case 2:
				if(b[r]==0){
				e2=6;
				d2++;
				return 6;}
			case 3:
				if(b[r]==0){
				e2=8;
				d2++;
				return 8;}
		}

	}

	if(z==3&&d2&&((e2==0&&b[8]==1)||(e2==2&&b[6]==1)||(e2==6&&b[2]==1)||(e2==8&&b[0]==1))){
		r=rand()%2;
			if(e2==0){
				if(r&&b[r]==0)
					return 2;
				else if(b[4]==0)
					return 4;
			}
			if(e2==2){
				if(r&&b[r]==0)
					return 0;
				else if(b[8]==0)
					return 8;
			}
			if(e2==6){
				if(r&&b[r]==0)
					return 0;
				else if(b[8]==0)
					return 8;
			}
			if(e2==8){
				if(r&&b[r]==0)
					return 2;
				else if(b[6]==0)
					return 6;
			}
	}

	if(z==1&&c[4]==1){
		r=rand()%4;
		switch(r){
			case 0:
				if(c[r]==0){
				e3=0;
				d3++;
				return 0;}
			case 1:
				if(c[r]==0){
				e3=2;
				d3++;
				return 2;}
			case 2:
				if(c[r]==0){
				e3=6;
				d3++;
				return 6;}
			case 3:
				if(c[r]==0){
				e3=8;
				d3++;
				return 8;}
		}
	}

	if(z==3&&d3&&((e3==0&&c[8]==1)||(e3==2&&c[6]==1)||(e3==6&&c[2]==1)||(e3==8&&c[0]==1))){
		r=rand()%2;
			if(e3==0){
				if(r&&c[r]==0)
					return 2;
				else if(c[4]==0)
					return 4;
			}
			if(e3==2){
				if(r&&c[r]==0)
					return 0;
				else if(c[8]==0)
					return 8;
			}
			if(e3==6){
				if(r&&c[r]==0)
					return 0;
				else if(c[8]==0)
					return 8;
			}
			if(e3==8){
				if(r&&c[r]==0)
					return 2;
				else if(c[6]==0)
					return 6;
			}
	}


					//c
	while(a[r]!=0&&s==1){
		r=rand()%9;
	;}

	while(b[r]!=0&&s==2){
		r=rand()%9;
		r=rand()%9;
	}

	while(c[r]!=0&&s==3){
		r=rand()%9;
		r=rand()%9;
		r=rand()%9;
	}


	return r;
}


void Nico_Finalize(){
	int x;
	for(x=0;x<9;x++){
		a[x]=0;
	}
	for(x=0;x<9;x++){
		b[x]=0;
	}
	for(x=0;x<9;x++){
		c[x]=0;
	}
	
	j=0;
	selectC=0;
	next=0;
	next0=0;
	next1=0;
	next2=0;
	kati1=5;
	kati2=5;
	kati3=5;
	onazi=10;
	owari=0;
	InitSoundMem();
}
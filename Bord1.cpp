#include "DxLib.h"
#include "Sentaku.h"

static int HandleF,HandleM,HandleB;
	
void Bord1_Update(){  
}

void Bord1_Draw(){

	char a[9]={0,0,0,0,0,0,0,0,0};	//ÅZÅ~ÇÃèÍèä
	int e,f,g;
	HandleF=LoadGraph("frame.png",TRUE);
	HandleM=LoadGraph("maru.png",TRUE);
	HandleB=LoadGraph("batu.png",TRUE);
        DrawGraph( 475, 370, HandleF, TRUE );

	g=0;
	for(f=0;f<3;f++){
		for(e=0;e<3;e++,g++){
			if(a[g]==1){
				DrawGraph( 475+e*110, 370+f*110, HandleM, TRUE );
			}
			if(a[g]==2){
				DrawGraph( 475+e*110, 370+f*110, HandleB, TRUE );
			}
		}
	}
}

void Bord1_Finalize(){
        DeleteGraph( HandleF );
	DeleteGraph( HandleM );
	DeleteGraph( HandleB );
}
/*--------------------------------------------------------*/
/*ファイル名：marubatu.c----------------------------------*/
/*作成者:0G02028 水流湧也---------------------------------*/
/*--------------------------------------------------------*/

//ヘッダファイル
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//プロトタイプ宣言
int marubatu(int x,int y,int z);
char syouhai(int x);
int com(char x,char y,int z,int s);
int atosaki(void);
int ta(void);
int gamemode(void);
int nikochan(void);

//グローバル変数
char a[9]={0,0,0,0,0,0,0,0,0};
char b[9]={0,0,0,0,0,0,0,0,0};
char c[9]={0,0,0,0,0,0,0,0,0};	//〇×の場所
int ninnzuu=0;
int jikan=0;
int owari=0;
int kaisuu=0;



//メイン(人数入力)
int main(void)
{



	if(gamemode()){
		nikochan();}
	else{
			int a;


		while(ninnzuu!=1&&ninnzuu!=2){
		printf("人数");
		scanf("%d",&ninnzuu);}
	
	
		if(ninnzuu==1){
			a=atosaki();
			marubatu(ninnzuu,a,ta());
		}
		else
			marubatu(ninnzuu,2,0);
	}

	return 0;

}






//〇×ゲーム
//x=人数（１OR２）ｙ＝先攻後攻（０＝先行１＝後行２＝二人）
int marubatu(int x,int y,int z){




	int nyuuryoku;	//入力
	int i=0,j=0;
	char jun[]={"OXOXOXOXOX"};
	char kati=3;

	do{

	while(j<9 && kati==3&&owari==0){

	if(x==2||j%2==y){

		while(i==0){


			printf("入力");
			scanf("%d",&nyuuryoku);


			if(nyuuryoku<0||nyuuryoku>8)
				printf("範囲外");
			else if(a[nyuuryoku]==0){
					i++;
					a[nyuuryoku]=jun[j];
					j++;}
			else
					printf("埋まってる");

		
		}

	i=0;

	}
	else{
		a[com(jun[j],jun[j+1],j,1)]=jun[j];
		j++;
	}



	printf("%c|%c|%c\n",a[0],a[1],a[2]);
	printf("--------\n");
	printf("%c|%c|%c\n",a[3],a[4],a[5]);
	printf("--------\n");
	printf("%c|%c|%c\n",a[6],a[7],a[8]);
	printf("--------\n");				//現在の状況

	kati=syouhai(1);

	}


	if(owari==1){
		printf("回数＝%d",kaisuu);
		return 0;
	}

	if(kati==0){
		printf("引き分け\n");

		for(j=0;j<9;j++){
			a[j]=0;
		}
		j=0;
		kaisuu++;
		jikan=time(NULL);
	}
	else{
		printf("%cの勝ち\n",kati);
		if(kaisuu)
			printf("回数＝%d",kaisuu);
		return 0;
	}

	}while(z);

	return 0;

}


int nikochan(void){

	int nyuuryoku;	//入力
	int nyuuryoku2=0;
	int i=0,j=1,k=0,n=0;
	char jun[]={"OXOXOXOXOX"};
	char kati1=3,kati2=3,kati3=3;

	a[4]='O';
	b[4]='O';
	c[4]='O';

	printf("1      2      3\n");
	printf("%c|%c|%c  %c|%c|%c  %c|%c|%c\n",a[0],a[1],a[2],b[0],b[1],b[2],c[0],c[1],a[2]);
	printf("-----  -----  -----\n");
	printf("%c|%c|%c  %c|%c|%c  %c|%c|%c\n",a[3],a[4],a[5],b[3],b[4],b[5],c[3],c[4],c[5]);
	printf("-----  -----  -----\n");
	printf("%c|%c|%c  %c|%c|%c  %c|%c|%c\n",a[6],a[7],a[8],b[6],b[7],b[8],c[6],c[7],c[8]);
	printf("-----  -----  -----\n");				//現在の状況


	while((kati1==3||kati1==0)&&(kati2==3||kati2==0)&&(kati3==3||kati3==0)){

		while(i==0){

			while(k==nyuuryoku2||n==0){
				printf("にこちゃん入力");
				scanf("%1d%1d",&nyuuryoku2,&nyuuryoku);

				if(nyuuryoku2<1||nyuuryoku2>3)
					printf("範囲外");
				else if(k==nyuuryoku2)
					printf("%dに入力不可",nyuuryoku2);
				else
				n++;
			}

	if(nyuuryoku2==1){


			if(nyuuryoku<0||nyuuryoku>8){
				printf("範囲外");
				n=0;}
			else if(b[nyuuryoku]=='3'||c[nyuuryoku]=='3'){
				printf("%dに入力不可",nyuuryoku);
				n=0;}
			else if(a[nyuuryoku]=='O'){
					i++;
					a[nyuuryoku]='3';
					k=nyuuryoku2;}
			else{
				printf("Oじゃない");
				n=0;}

		
		}



	if(nyuuryoku2==2){


			if(nyuuryoku<0||nyuuryoku>8){
				printf("範囲外");
				n=0;}
			else if(a[nyuuryoku]=='3'||c[nyuuryoku]=='3'){
				printf("%dに入力不可",nyuuryoku);
				n=0;}
			else if(b[nyuuryoku]=='O'){
					i++;
					b[nyuuryoku]='3';
					k=nyuuryoku2;}
			else{
				printf("Oじゃない");
				n=0;}
		
		}



	if(nyuuryoku2==3){


			if(nyuuryoku<0||nyuuryoku>8){
				printf("範囲外");
				n=0;}
			else if(a[nyuuryoku]=='3'||b[nyuuryoku]=='3'){
				printf("%dに入力不可",nyuuryoku);
				n=0;}
			else if(c[nyuuryoku]=='O'){
					i++;
					c[nyuuryoku]='3';
					k=nyuuryoku2;}
			else{
				printf("Oじゃない");
				n=0;}
		
		}

	}

	i=0;

	kati1=syouhai(1);

	if(kati1==0&&kati2==0&&kati3==0){
		printf("にこちゃん失敗");
		return 0;
	}

	while(i==0&&nyuuryoku2!=1&&kati1==3){
		printf("1に×入力");
		scanf("%d",&nyuuryoku);


			if(nyuuryoku<0||nyuuryoku>8)
				printf("範囲外");
			else if(a[nyuuryoku]==0){
					i++;
					a[nyuuryoku]='X';
			}
			else
					printf("埋まってる");


	}
	i=0;


	kati1=syouhai(1);

	if(kati1==0&&kati2==0&&kati3==0){
		printf("にこちゃん失敗");
		return 0;
	}

	kati2=syouhai(2);

	if(kati1==0&&kati2==0&&kati3==0){
		printf("にこちゃん失敗");
		return 0;
	}


	while(i==0&&nyuuryoku2!=2&&kati2==3){
		printf("2に×入力");
		scanf("%d",&nyuuryoku);


			if(nyuuryoku<0||nyuuryoku>8)
				printf("範囲外");
			else if(b[nyuuryoku]==0){
					i++;
					b[nyuuryoku]='X';
			}
			else
					printf("埋まってる");


	}
	i=0;

	kati2=syouhai(2);

	if(kati1==0&&kati2==0&&kati3==0){
		printf("にこちゃん失敗");
		return 0;
	}

	kati3=syouhai(3);

	if(kati1==0&&kati2==0&&kati3==0){
		printf("にこちゃん失敗");
		return 0;
	}


	while(i==0&&nyuuryoku2!=3&&kati3==3){
		printf("3に×入力");
		scanf("%d",&nyuuryoku);


			if(nyuuryoku<0||nyuuryoku>8)
				printf("範囲外");
			else if(c[nyuuryoku]==0){
					i++;
					c[nyuuryoku]='X';
			}
			else
					printf("埋まってる");


	}

	j++;


	srand((unsigned)time(NULL));

if(kati1!=0){
	do{
	i=com(jun[0],jun[1],j,1);
	if(a[i]!=0){
		i=rand()%9;}}
	while(a[i]!=0);
	a[i]='O';
	}



if(kati2!=0){
	do{
	i=com(jun[0],jun[1],j,2);
	if(b[i]!=0){
		i=rand()%9;
		i=rand()%9;}}
	while(b[i]!=0);
	b[i]='O';

	}



if(kati3!=0){
	do{
	i=com(jun[0],jun[1],j,3);
	if(c[i]!=0){
		i=rand()%9;
		i=rand()%9;
		i=rand()%9;}}
	while(c[i]!=0);
	c[i]='O';
	}


	i=0;
	j++;

	printf("1      2      3\n");
	printf("%c|%c|%c  %c|%c|%c  %c|%c|%c\n",a[0],a[1],a[2],b[0],b[1],b[2],c[0],c[1],c[2]);
	printf("-----  -----  -----\n");
	printf("%c|%c|%c  %c|%c|%c  %c|%c|%c\n",a[3],a[4],a[5],b[3],b[4],b[5],c[3],c[4],c[5]);
	printf("-----  -----  -----\n");
	printf("%c|%c|%c  %c|%c|%c  %c|%c|%c\n",a[6],a[7],a[8],b[6],b[7],b[8],c[6],c[7],c[8]);
	printf("-----  -----  -----\n");				//現在の状況


	kati1=syouhai(1);


	kati2=syouhai(2);


	kati3=syouhai(3);

	if(kati1==0&&kati2==0&&kati3==0){
		printf("にこちゃん失敗");
		return 0;
	}

	}

	if(kati1=='3'||kati2=='3'||kati3=='3')
		printf("にこちゃん成功");
	else if(kati1=='O'||kati2=='O'||kati3=='O')
		printf("負け");
	else
		printf("不具合？");


	return 0;
}

//勝敗判定
char syouhai(int x){


	int k;
	char j=3;

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

	if(jikan){
		if(difftime(time(NULL),jikan)>20){
			printf("時間切れ\n");
			owari=1;
		}
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


	if(z==1&&a[4]=='O'){
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

	if(z==3&&d1&&((e1==0&&a[8]=='O')||(e1==2&&a[6]=='O')||(e1==6&&a[2]=='O')||(e1==8&&a[0]=='O'))){
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


	if(z==1&&b[4]=='O'){
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

	if(z==3&&d2&&((e2==0&&b[8]=='O')||(e2==2&&b[6]=='O')||(e2==6&&b[2]=='O')||(e2==8&&b[0]=='O'))){
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

	if(z==1&&c[4]=='O'){
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

	if(z==3&&d3&&((e3==0&&c[8]=='O')||(e3==2&&c[6]=='O')||(e3==6&&c[2]=='O')||(e3==8&&c[0]=='O'))){
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

//先攻後攻設定（一人時）
int atosaki(void){

	int s=2;

	while(s!=0&&s!=1){
	printf("先攻(0)後攻(1)");
	scanf("%d",&s);}

	return s;
}



int ta(void){


	int s=2;

	while(s!=0&&s!=1){
	printf("普通(0)TA(1)");
	scanf("%d",&s);}

	if(s==1)
			jikan=time(NULL);

	
	return s;

}


int gamemode(void)
{
	int s=2;

	while(s!=0&&s!=1){
	printf("普通(0)にこちゃん(1)");
	scanf("%d",&s);}



	return s;
}
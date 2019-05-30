//作成：0G02029鳥井旋里

#pragma once

typedef enum {                // 定義
	eScene_Staff,
	eScene_GameNico,
	eScene_Nico,   
	eScene_GameN,
	eScene_GameCPUA,  
	eScene_GameCPUTf,
	eScene_GameCPUF,
	eScene_GameCPUTF,  
	eScene_GameCPUTs,
	eScene_GameCPUS,
	eScene_GameCPUTS,
	eScene_GameHUMAN,    
	eScene_Title, 
	eScene_Config
}eScene;

void SceneMgr_Update();	// 更新

void SceneMgr_Draw();	// 描写

void SceneMgr_ChangeScene(eScene nextScene);	// シーン変更

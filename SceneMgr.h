//�쐬�F0G02029�������

#pragma once

typedef enum {                // ��`
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

void SceneMgr_Update();	// �X�V

void SceneMgr_Draw();	// �`��

void SceneMgr_ChangeScene(eScene nextScene);	// �V�[���ύX

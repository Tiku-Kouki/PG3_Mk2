#pragma once
#include <memory>
#include "IScene.h"
#include "StageScene.h"
#include "TitlScene.h"
#include "ClearScene.h"
#include "Input.h"

class GameManager {
private:
	//シーンを保持するメンバ関数
	std::unique_ptr<IScene> sceneArr_[3];

	//
	int currenSceneNo_;	//現在のシーン
	int prevSceneNO_;	//過去のシーン

	Input inputManager;

	public:
	GameManager();
	~GameManager();

	int Run();

	private:
	char keys_[256], preKeys_[256];

};

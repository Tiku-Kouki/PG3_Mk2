#include "GameManager.h"

GameManager::GameManager() {
//各シーンの配列
	sceneArr_[TITLE] = std::make_unique<TitlScene>();
	sceneArr_[STAGE] = std::make_unique<StageScene>();
	sceneArr_[CLEAR] = std::make_unique<ClearScene();

	currenSceneNo_ = TITLE;
}

GameManager::~GameManager() {}

int GameManager::Run() { 
	while (Novice::ProcessMessage() == 0) {
		Novice::BeginFrame();

		//シーンのチェック
		prevSceneNO_ = currenSceneNo_;
		currenSceneNo_ = sceneArr_[currenSceneNo_]->GetSceneNo();

		// シーン変更チェック
		if (prevSceneNO_ != currenSceneNo_) {
			sceneArr_[currenSceneNo_]->Init();
		}
		 //更新処理
		sceneArr_[currenSceneNo_]->Update();
		//描画処理
		sceneArr_[currenSceneNo_]->Draw();

		Novice::EndFrame();//フレームの終了

		if (inputManager->GetPreKeys()[DIK_ESCAPE]==0&&
		    inputManager->GetPreKeys()[DIK_ESCAPE] != 0) {
			break;
		}
	}
	return 0; }

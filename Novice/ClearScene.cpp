#include "ClearScene.h"

void ClearScene::Init(char* keys, char* preKeys) {


		keys_ = keys;

		preKeys_ = preKeys;
	
	//grHandle = Novice::LoadTexture("title.png");
}

void ClearScene::Update() {

	if (preKeys_[DIK_SPACE] == 0 && keys_[DIK_SPACE]) {
	
		sceneNo = TITLE;

	}

}

void ClearScene::Draw() {

	
	//Novice::DrawSprite(0, 0, grHandle, 1.0f, 1.0f, 0.0f, 0xFFFFFFFF);
	Novice::ScreenPrintf(0, 0, "Clear");
}

#include "ClearScene.h"

void ClearScene::Init(const char keys[], const char preKeys[]) {

	for (int i = 0; i < 256; i++) {

		keys_[i] = keys[i];

		preKeys_[i] = preKeys[i];
	}
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

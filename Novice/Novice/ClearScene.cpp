#include "ClearScene.h"

void ClearScene::Init(char keys[256], char preKeys[256]) {

	for (int i = 0; i < 256; i++) {

		keys_[i] = keys[i];

		preKeys_[i] = preKeys[i];
	}
}

void ClearScene::Update() {

	if (preKeys_[DIK_SPACE] == 0 && keys_[DIK_SPACE]) {
	
		sceneNo = TITLE;

	}

}

void ClearScene::Draw() {

	Novice::ScreenPrintf(0, 0, "Clear");


}

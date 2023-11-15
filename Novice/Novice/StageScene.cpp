#include "StageScene.h"

void StageScene::Init(char keys[256], char preKeys[256]) {

	for (int i = 0; i < 256; i++) {

		keys_[i] = keys[i];

		preKeys_[i] = preKeys[i];
	}

}

void StageScene::Update() {}

void StageScene::Draw() {}

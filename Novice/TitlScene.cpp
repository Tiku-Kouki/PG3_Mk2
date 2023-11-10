#include "TitlScene.h"

void TitlScene::Init(char keys[256], char preKeys[256]) {

	for (int i = 0; i < 256; i++) {

		keys_[i] = keys[i];

		preKeys_[i] = preKeys[i];
	}

}

void TitlScene::Update() {}

void TitlScene::Draw() {}

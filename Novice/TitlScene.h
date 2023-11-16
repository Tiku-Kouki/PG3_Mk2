#pragma once
#include "IScene.h"
#include <Novice.h>
class TitlScene : public IScene {
public:
	void Init(char keys[256], char preKeys[256]) override;

	void Update() override;

	void Draw() override;

	private:
	char keys_[256], preKeys_[256];

};

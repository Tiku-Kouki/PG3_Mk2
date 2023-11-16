#pragma once
#include "IScene.h"
#include <Novice.h>
#include "Input.h"
class TitlScene : public IScene {
public:
	void Init(char keys[], char preKeys[]) override;

	void Update() override;

	void Draw() override;

	private:
	char keys_[256], preKeys_[256];

	int grHandle;

	Input*input_= nullptr;
};

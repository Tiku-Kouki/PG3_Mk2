#pragma once
#include "IScene.h"
#include <Novice.h>
class ClearScene : public IScene {
public:
	void Init(const char keys[], const char preKeys[]) override;

	void Update() override;

	void Draw() override;

	private:

char keys_[256] = {}, preKeys_[256] = {};

//int grHandle;

};

#pragma once
#include "IScene.h"
#include <Novice.h>
class ClearScene : public IScene {
public:
	void Init(char* keys, char* preKeys) override;

	void Update() override;

	void Draw() override;

	private:

char *keys_, *preKeys_;

//int grHandle;

};

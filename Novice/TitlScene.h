#pragma once
#include "IScene.h"
#include <Novice.h>
class TitlScene : public IScene {
public:
	void Init() override;

	void Update() override;

	void Draw() override;

};

#pragma once
#include "IScene.h"
#include <Novice.h>
class StageScene : public IScene{
public:
	void Init() override;

	void Update() override;

	void Draw() override;


};

#pragma once
#include <memory>
#include "IScene.h"
#include "StageScene.h"
#include "TitlScene.h"
#include "ClearScene.h"
#include "Input.h"

class GameManager {
private:
	//�V�[����ێ����郁���o�֐�
	std::unique_ptr<IScene> sceneArr_[3];

	//
	int currenSceneNo_;	//���݂̃V�[��
	int prevSceneNO_;	//�ߋ��̃V�[��

	

	public:
	GameManager();
	~GameManager();

	int Run();
};

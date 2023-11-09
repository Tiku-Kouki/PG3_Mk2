#include "GameManager.h"

GameManager::GameManager() {
//�e�V�[���̔z��
	sceneArr_[TITLE] = std::make_unique<TitlScene>();
	sceneArr_[STAGE] = std::make_unique<StageScene>();
	sceneArr_[CLEAR] = std::make_unique<ClearScene();

	currenSceneNo_ = TITLE;
}

GameManager::~GameManager() {}

int GameManager::Run() { 
	while (Novice::ProcessMessage() == 0) {
		Novice::BeginFrame();

		//�V�[���̃`�F�b�N
		prevSceneNO_ = currenSceneNo_;
		currenSceneNo_ = sceneArr_[currenSceneNo_]->GetSceneNo();

		// �V�[���ύX�`�F�b�N
		if (prevSceneNO_ != currenSceneNo_) {
			sceneArr_[currenSceneNo_]->Init();
		}
		 //�X�V����
		sceneArr_[currenSceneNo_]->Update();
		//�`�揈��
		sceneArr_[currenSceneNo_]->Draw();

		Novice::EndFrame();//�t���[���̏I��

		if (inputManager->GetPreKeys()[DIK_ESCAPE]==0&&
		    inputManager->GetPreKeys()[DIK_ESCAPE] != 0) {
			break;
		}
	}
	return 0; }

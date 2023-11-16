#pragma once
enum Scene {TITLE,STAGE,CLEAR};

class IScene {
protected:
	//シーン番号を管理する変数
	static int sceneNo;

public:
	//
	//
	virtual void Init(char keys[], char preKeys[]) = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;

	//
	virtual ~IScene();
	//
	int GetSceneNo();
};

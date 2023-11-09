#pragma once
enum Scene {TITLE,STAGE,CLEAR};

class IScene {
protected:
	//ƒV[ƒ“”Ô†‚ğŠÇ—‚·‚é•Ï”
	static int sceneNo;

public:
	//
	//
	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;

	//
	virtual ~IScene();
	//
	int GetSceneNo();
};

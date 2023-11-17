#pragma once
#include "IScene.h"
#include <Novice.h>
class StageScene : public IScene{
public:
	void Init(char* keys, char* preKeys) override;

	void Update() override;

	void Draw() override;

	private:
	char* keys_, *preKeys_;

	// プレイヤー
	float playerPosX ; // プレイヤーの座標X
	float playerPosY ; // プレイヤー座標Y
	int playerSpeed ;       // 速さ
	int playerSize ;       // プレイヤーの幅、高さ

	// 弾
	float bulletPosX ; // 弾のX座標
	float bulletPosY ; // 弾のY座標
	int bulletSpeed ;    // 弾の速さ
	int isBulletShot ;    // 弾を発射しているかフラグ
	int bulletRadius ;   // 円の半径

	float enemyPosX ;
	float enemyPosY ;
	int enemySpeed ;
	int enemyRadius ;
	int isEnemyAlive ; // 敵が生存しているか 0:生存していない　1:生存している
	int respawnTimer ;

	    // 当たり判定を計算する
	float dx; // X2-X1
	float dy ; // Y2-Y1

	// ||=または
	// 円の中心の距離を計算する(右辺)
	int d ;
	// 敵の半径と弾の半径を足して2乗する(左辺)
	float ds ;

};

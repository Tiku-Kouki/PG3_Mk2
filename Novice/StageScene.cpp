﻿#include "StageScene.h"

void StageScene::Init(const char keys[], const char preKeys[]) {

	for (int i = 0; i < 256; i++) {

		keys_[i] = keys[i];

		preKeys_[i] = preKeys[i];
	}

	// プレイヤー
	 playerPosX = 640.0f; // プレイヤーの座標X
	 playerPosY = 360.0f; // プレイヤー座標Y
	 playerSpeed = 5;       // 速さ
	 playerSize = 40;       // プレイヤーの幅、高さ

	// 弾
	 bulletPosX = 0.0f; // 弾のX座標
	 bulletPosY = 0.0f; // 弾のY座標
	 bulletSpeed = 10;    // 弾の速さ
	 isBulletShot = 0;    // 弾を発射しているかフラグ
	 bulletRadius = 10;   // 円の半径

	 enemyPosX = 640;
	 enemyPosY = 32;
	 enemySpeed = 3;
	 enemyRadius = 20;
	 isEnemyAlive = 1; // 敵が生存しているか 0:生存していない　1:生存している
	 respawnTimer = 120;

	

}

void StageScene::Update() {

	if (!preKeys_[DIK_SPACE] && keys_[DIK_SPACE]) {

		sceneNo = CLEAR;
	 }


	  if (keys_[DIK_W] || keys_[DIK_UP]) {
		playerPosY -= playerSpeed;
	 }
	 if (keys_[DIK_S] || keys_[DIK_DOWN]) {
		playerPosY += playerSpeed;
	 }
	 if (keys_[DIK_A] || keys_[DIK_LEFT]) {
		playerPosX -= playerSpeed;
	 }
	 if (keys_[DIK_D] || keys_[DIK_RIGHT]) {
		playerPosX += playerSpeed;
	 }


	 // 弾が発射されていなかったら
	 if (isBulletShot == 0) {

		// スペースキーを押した瞬間
		if (keys_[DIK_SPACE] && preKeys_[DIK_SPACE] == 0) {
			// 弾を発射する
			isBulletShot = 1;

			// 弾の座標とプレイヤーの座標が一緒になる
			bulletPosX = playerPosX;
			bulletPosY = playerPosY;
		}
	 }
	 if (isBulletShot == 1) {
		// 弾を上に発射
		bulletPosY = bulletPosY - bulletSpeed;

		// もし弾が画面の外に出たら
		if (bulletPosY <= 0) {
			// 弾を発射しているかフラグをfalse(0)にして
			// 発射できるようにする
			isBulletShot = 0;
			bulletPosY = -4;
		}
	 }

	 // 当たり判定を計算する
	  dx = enemyPosX - bulletPosX; // X2-X1
	  dy = enemyPosY - bulletPosY; // Y2-Y1

	 // ||=または
	 // 円の中心の距離を計算する(右辺)
	  d = (int)dx * (int)dx + (int)dy * (int)dy;
	 // 敵の半径と弾の半径を足して2乗する(左辺)
	  ds = (float)(enemyRadius + bulletRadius) * (float)(enemyRadius + bulletRadius);
	 // 左辺 == 右辺 または{ || } 左辺 > 右辺 か　
	 if (ds == d || ds > d) {
		// 当たっている
		isBulletShot = 0;
		bulletPosY = -4;
		// 敵を消す(フラグを用意する)
		isEnemyAlive = 0;
	 }
	 if (isEnemyAlive == 0) {
		// 復活用タイマーを1減らす
		respawnTimer--;
		// 復活用タイマーが0になったら
		if (respawnTimer == 0) {
			isEnemyAlive = 1;
			respawnTimer = 120;
		}
	 }

	 if (isEnemyAlive == 1) {
		enemyPosX += enemySpeed;

		if (enemyPosX >= 1260) {

			enemySpeed *= -1;
		}
		// 左端に戻ったら
		if (enemyPosX <= 20) {

			enemySpeed *= -1;
		}
	 }



}

void StageScene::Draw() {
	 if (isBulletShot == 1) {

		// 弾を描画
		Novice::DrawTriangle(
		    (int)bulletPosX,           // 上X
		    (int)bulletPosY - 10, // 下Y
		    (int)bulletPosX - 10, // 左下X
		    (int)bulletPosY + 20 - 10, // 左下Y
		    (int)bulletPosX + 10,      // 右下X
		    (int)bulletPosY + 20 - 10, // 右下Y

		    RED, kFillModeSolid);
	 }
	 // 当たり判定の円を描画
	 if (isEnemyAlive == 1) {

		Novice::DrawEllipse(
		    (int)enemyPosX, (int)enemyPosY, enemyRadius, enemyRadius, 0.0f, WHITE, kFillModeSolid);

		Novice::DrawEllipse(
		    (int)enemyPosX, (int)enemyPosY, enemyRadius + 2, enemyRadius + 2, 0.0f, WHITE,
		    kFillModeSolid);
	 }

	

	 // プレイヤーを描画
	 Novice::DrawBox(
	     (int)playerPosX - playerSize / 2, (int)playerPosY - playerSize / 2, playerSize, playerSize,
	     0.0f,
	     WHITE, kFillModeSolid);

	

	 Novice::ScreenPrintf(0, 50, "%c", keys_[DIK_SPACE]);

	Novice::ScreenPrintf(0, 0, "Game");

}

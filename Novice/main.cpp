#include <Novice.h>
#include "GameManager.h"

const char kWindowTitle[] = "LE2C_17_チク_コウキ";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	GameManager gameManager;
	gameManager.Int(keys, preKeys);


	gameManager.Run();

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}

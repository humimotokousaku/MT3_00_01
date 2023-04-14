#include <Novice.h>
#include <VectorCalculation.h>

const char kWindowTitle[] = "LC1A_22_フミモトコウサク";

const int kWindowWidth = 1280;
const int kWindowHeight = 720;

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, kWindowWidth, kWindowHeight);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	// 宣言
	Vector3 v1;
	v1 = { 1.0f, 3.0f, -5.0f };
	Vector3 v2;
	v2 = { 4.0f, -1.0f, 2.0f };
	float k;
	k = 4.0f;

	// 計算結果
	Vector3 resultAdd;
	Vector3 resultSubtract;
	Vector3 resultMultiply;
	float resultDot;
	float resultLength;
	Vector3 resultNormalize;

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///
		// 計算結果
		resultAdd = Add(v1, v2);
		resultSubtract = Subtract(v1, v2);
		resultMultiply = Multiply(k, v1);
		resultDot = Dot(v1, v2);
		resultLength = Length(v1);
		resultNormalize = Normalize(v2);

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		// 計算結果表示
		vectorScreenPrintf(0, 0, resultAdd, "  : Add");
		vectorScreenPrintf(0, kRowHeight, resultSubtract, "  : Subtract");
		vectorScreenPrintf(0, kRowHeight * 2, resultMultiply, "  : Multiply");
		Novice::ScreenPrintf(0, kRowHeight * 3, "%.02f  : Dot", resultDot);
		Novice::ScreenPrintf(0, kRowHeight * 4, "%.02f  : Length", resultLength);
		vectorScreenPrintf(0, kRowHeight * 5, resultNormalize, "  : Normalize");


		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}

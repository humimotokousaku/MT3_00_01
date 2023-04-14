#pragma once

// 構造体
typedef struct Vector3 {
	float x;
	float y;
	float z;
};

// 関数

// 加算
Vector3 Add(const Vector3& v1, const Vector3& v2);

// 減算
Vector3 Subtract(const Vector3& v1, const Vector3& v2);

// スカラー倍
Vector3 Multiply(float scalar, const Vector3& v);

// 内積
float Dot(const Vector3& v1, const Vector3& v2);

// 長さ(ノルム)
float Length(const Vector3& v);

// 正規化
Vector3 Normalize(const Vector3& v);

// 三次元ベクトルの数値表示
static const int kRowHeight = 20;
static const int kColumnWidth = 60;
void vectorScreenPrintf(int x, int y, const Vector3& vector, const char* label);

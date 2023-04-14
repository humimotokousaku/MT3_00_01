#pragma once

// �\����
typedef struct Vector3 {
	float x;
	float y;
	float z;
};

// �֐�

// ���Z
Vector3 Add(const Vector3& v1, const Vector3& v2);

// ���Z
Vector3 Subtract(const Vector3& v1, const Vector3& v2);

// �X�J���[�{
Vector3 Multiply(float scalar, const Vector3& v);

// ����
float Dot(const Vector3& v1, const Vector3& v2);

// ����(�m����)
float Length(const Vector3& v);

// ���K��
Vector3 Normalize(const Vector3& v);

// �O�����x�N�g���̐��l�\��
static const int kRowHeight = 20;
static const int kColumnWidth = 60;
void vectorScreenPrintf(int x, int y, const Vector3& vector, const char* label);

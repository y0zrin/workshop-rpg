#pragma once
#include <string>

// 日本語を表示・入力できるようにする（Windows のコンソール）
void setupConsole();

// 1 行読む（日本語も読める）
std::string readLine();

// Enter が押されるまで待つ
void waitEnter();

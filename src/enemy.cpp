#include "enemy.h"

// 課題 4: 敵を増やす（いまはスライムだけ。ゴブリンなどを足して、ランダムに選ぶ）
Enemy makeEnemy()
{
    return Enemy{ "スライム", 20, 20, 4 };
}

#include "status.h"

#include <iostream>

// 課題 2: HP がマイナスで表示される（敵を倒したあとに「HP -3 / 20」のようになる）
void showStatus(const Hero& hero, const Enemy& enemy)
{
    std::cout << "--------------------------------\n";
    std::cout << " " << hero.name << "  HP " << hero.hp << " / " << hero.maxHp << "\n";
    std::cout << " " << enemy.name << "  HP " << enemy.hp << " / " << enemy.maxHp << "\n";
    std::cout << "--------------------------------\n";
}

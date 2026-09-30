#include "message.h"

#include <iostream>

// 課題 5: 勝ったとき・負けたときの言葉を変える（もっと盛り上がるように）
void showResult(bool won, const Hero& hero, const Enemy& enemy)
{
    if (won)
    {
        std::cout << enemy.name << " をたおした。\n";
    }
    else
    {
        std::cout << hero.name << " はたおれた。\n";
    }
}

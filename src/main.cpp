#include "battle.h"
#include "console.h"
#include "enemy.h"
#include "message.h"

#include <iostream>

// タイトル（おまけの課題 6: 2 人が同じ行を直すと、競合の練習になる）
void showTitle()
{
    std::cout << "================================\n";
    std::cout << "        ちいさな RPG\n";
    std::cout << "================================\n\n";
}

int main()
{
    setupConsole();
    showTitle();

    // 課題 1: 勇者の名前を入れられるようにする（いまは「ゆうしゃ」で決まっている）
    Hero hero{ "ゆうしゃ", 30, 30, 8 };

    Enemy enemy = makeEnemy();
    bool won = battle(hero, enemy);
    showResult(won, hero, enemy);
    waitEnter();
    return 0;
}

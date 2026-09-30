#include "battle.h"

#include "console.h"
#include "random.h"
#include "status.h"

#include <iostream>
#include <string>

// 課題 3: 「やくそう」で HP を回復できるようにする（コマンドの 2 番に足す）
bool battle(Hero& hero, Enemy& enemy)
{
    std::cout << enemy.name << " があらわれた！\n";
    while (hero.hp > 0 && enemy.hp > 0)
    {
        showStatus(hero, enemy);
        std::cout << "どうする？  1: たたかう\n> ";
        std::string command = readLine();
        if (command == "1")
        {
            int damage = hero.attack + randomInt(-2, 2);
            enemy.hp -= damage;
            std::cout << hero.name << " のこうげき！ " << enemy.name << " に " << damage << " のダメージ！\n";
        }
        else
        {
            std::cout << "1 を入れてください\n";
            continue;
        }

        if (enemy.hp <= 0)
        {
            break;
        }

        int damage = enemy.attack + randomInt(-1, 1);
        hero.hp -= damage;
        std::cout << enemy.name << " のこうげき！ " << hero.name << " は " << damage << " のダメージをうけた！\n";
    }
    showStatus(hero, enemy);
    return hero.hp > 0;
}

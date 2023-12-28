// TextRpg.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "Player.h"
#include "Monster.h"
#include "FightZone.h"

// 데미지가 Random Damage가 되게 해라.

// 선공 후공이 랜덤이 되게 만들어라.

// set name만들기

int main()
{
    Player NewPlayer = Player();

    NewPlayer.SetName("Player");

    FightZone NewZone;

    NewZone.Fight(NewPlayer);

}
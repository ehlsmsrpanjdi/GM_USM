#include "MonsterManager.h"
#include "Monster.h"
#include <ConsoleEngine/ConsoleObject.h>
#include "list"
#include <ConsoleEngine/EngineCore.h>
#include "GlobalValue.h"
#include "MonsterManager.h"

Monster* MonsterManager::CurMonster = nullptr;
std::vector<Monster*> MonsterManager::MonsterList = std::vector<Monster*>();

void MonsterManager::Spawn_Monster()
{

	{
		++CoolTime;
		if (CoolTime >= 20) {
			CoolTime = 0;


			std::list<ConsoleObject*> AllList = GetCore()->GetUpdateGroup();

			int ScreenX = GetCore()->Screen.GetScreenX();
			int ScreenY = GetCore()->Screen.GetScreenY();

			// 화면 전체공간을 리스트 안에 담는다.
			std::list<int2> AllRange;
			// 00, 01, 10, 11
			{
				for (int y = 0; y < ScreenY; y++)
				{
					for (int x = 0; x < ScreenX; x++)
					{
						AllRange.push_back({ x, y });
					}
				}
			}

			{
				std::list<ConsoleObject*>::iterator StartIter = AllList.begin();
				std::list<ConsoleObject*>::iterator EndIter = AllList.end();
				for (; StartIter != EndIter; ++StartIter)
				{
					ConsoleObject* Object = *StartIter;

					if (nullptr == Object)
					{
						MsgBoxAssert("오브젝트가 nullptr인 녀석이 있습니다.");
					}

					AllRange.remove(Object->GetPos());
				}
			}

			AllRange;
			// 00, 10, 11
			//     ^

			{
				int RandomValue = rand() % AllRange.size();

				std::list<int2>::iterator StartIter = AllRange.begin();

				int2 CreateBodyPos = { 0, 0 };
				for (size_t i = 0; i < RandomValue; i++)
				{
					++StartIter;
				}
				CreateBodyPos = *StartIter;

				//랜덤한 위치가 지정됐으므로
				CurMonster = GetCore()->CreateObject<Monster>(Update::Monster, Render::Monster);
				CurMonster->SetRenderChar('&');
				CurMonster->SetPos(CreateBodyPos);
				MonsterList.push_back(CurMonster);
				MonsterManager::ResetBody();

			}
		}
	}
}

void MonsterManager::Update()
{

	/*std::vector<Monster*>::iterator StartIter = MonsterManager::GetVec()->begin();
	std::vector<Monster*>::iterator EndIter = MonsterManager::GetVec()->end();
	for (; StartIter != EndIter; ++StartIter)
	{
		Monster* Object = *StartIter;

		if (nullptr == Object)
		{
			MsgBoxAssert("오브젝트가 nullptr인 녀석이 있습니다.");
		}
		Object->SetPos(Object->GetPos() + int2(0, 1));

	}*/

	Spawn_Monster();

}


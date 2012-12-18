#include "AppTest.h"
#include "WorldManager.h"

AppTest::AppTest(void)
{
	Game::WorldManager::Instance()->Init();
}

AppTest::~AppTest(void)
{
	Game::WorldManager::ClearUp();
}

bool AppTest::applicationDidFinishLaunching()
{
	return true;
}

void AppTest::applicationDidEnterBackground()
{

}

void AppTest::applicationWillEnterForeground()
{

}

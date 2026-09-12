#include "Application/GameApplication.h"
#include "Config/GameConfig.h"
#include "Config/UserSettings.h"
#include <DxLib.h>

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    UserSettings startupSettings;

    SetGraphMode(GameConfig::ScreenWidth,GameConfig::ScreenHeight,GameConfig::ColorDepth);

    ChangeWindowMode(startupSettings.displayMode == DisplayMode::Windowed? TRUE: FALSE);

    if (DxLib_Init() == -1)
    {
        return -1;
    }

    GameApplication application;
    const int result = application.Run();

    DxLib_End();
    return result;
}

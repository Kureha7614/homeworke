#include "GameApplication.h"
#include "../Config/GameConfig.h"
#include <DxLib.h>

int GameApplication::Run()
{
    input_.ApplyBindings(settings_.inputBindings);
    SetDrawScreen(DX_SCREEN_BACK);

    constexpr float FixedDeltaSeconds =1.0f / static_cast<float>(GameConfig::TargetFps);
    constexpr int FrameBudgetMilliseconds =1000 / GameConfig::TargetFps;

    while (ProcessMessage() == 0 && !sceneManager_.IsExitRequested())
    {
        const int frameStartTime = GetNowCount();

        input_.Update();
        sceneManager_.Update(input_, FixedDeltaSeconds);

        ClearDrawScreen();
        sceneManager_.Draw();
        ScreenFlip();

        const int elapsedMilliseconds = GetNowCount() - frameStartTime;
        if (elapsedMilliseconds < FrameBudgetMilliseconds)
        {
            WaitTimer(FrameBudgetMilliseconds - elapsedMilliseconds);
        }
    }
    return 0;
}

#pragma once

class Gameplay;

class WorldRenderer
{
public:
    void Draw(const Gameplay& gameplay) const;

private:
    void DrawField(const Gameplay& gameplay) const;
    void DrawItems(const Gameplay& gameplay) const;
    void DrawBombs(const Gameplay& gameplay) const;
    void DrawEnemies(const Gameplay& gameplay) const;
    void DrawPlayer(const Gameplay& gameplay) const;
};

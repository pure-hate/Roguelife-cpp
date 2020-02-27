#pragma once

static class Human
{
public:
    int x, y, hp, energy;
    Sprite sprite;
    void draw()
    {
        sprite.setPosition(x * 16, y * 16);
        window.draw(sprite);
    }
};
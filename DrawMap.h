#pragma once
template <int row, int col>
void draw_map(int(&arr)[row][col])
{
    for (int i = 0; i < SIZEX; i++) //������������ �� �������
    {
        for (int j = 0; j < SIZEY; j++)// ������������ �� ��������
        {
            if (arr[i][j] == 1)
            {
                wallSprite.setPosition(i * 16.f, j * 16.f);
                window.draw(wallSprite);
            }
            if (arr[i][j] == 0)
            {
                grassSprite.setPosition(i * 16.f, j * 16.f);
                window.draw(grassSprite);
            }

        }
    }

}


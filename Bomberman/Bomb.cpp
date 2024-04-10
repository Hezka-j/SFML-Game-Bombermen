#include "Bomb.h"

Bomb::Bomb(string file) {
    SetFile(file);
    SetImage(file);
    SetTexture(GetImage());
    SetSprite(GetTexture());
    timer.restart();
}

Bomb::Bomb() : Bomb("bomb.png") {}

void Bomb::SetSprite(Texture& texture) {
    sprite.setTexture(texture);
    sprite.setTextureRect(IntRect(0, 0, 32, 32));
}

void Bomb::SetY(int y) {
    this->y = y;
}

int Bomb::GetY() const {
    return y;
}

void Bomb::SetX(int x) {
    this->x = x;
}

int Bomb::GetX() const {
    return x;
}

Sprite& Bomb::GetSprite() {
    return sprite;
}

void Bomb::SetTexture(Image& image) {
    this->texture.loadFromImage(image);
}

Texture& Bomb::GetTexture() {
    return this->texture;
}

void Bomb::SetImage(string filename) {
    image.loadFromFile("D:\\Проекты\\Bomberman\\" + filename);
}

Image& Bomb::GetImage() {
    return image;
}

void Bomb::SetFile(string filename) {
    this->file = filename;
}

string Bomb::GetFile() const {
    return file;
}

void Bomb::PlantBomb(Player& player, int x, int y, String* main_map) {
    player.SetBombScore(player.GetBombScore() - 1);
    this->x = (x - 100) / 32 + 1;
    this->y = (y - 130) / 32 + 1;  
    if (main_map[this->y][this->x] != 'w')
        main_map[this->y][this->x] = 'b';
    else
    {
        if (player.GetDirection() == 0)
            main_map[this->y][this->x - 1] = 'b';
        else if (player.GetDirection() == 1)
            main_map[this->y][this->x + 1] = 'b';
        else if (player.GetDirection() == 3)
            main_map[this->y + 1][this->x] = 'b';
        else
            main_map[this->y - 1][this->x] = 'b';
    }
}

void Bomb::Explosion(Player& player, Sound& sound_bomb2, Sound& sound_damage, String* main_map, int height_map, int width_map)
{
    if (main_map[y + 1][x] != 'l' || main_map[y][x + 1] != 'l')
    {
        if (x >= 0 && x < width_map && y >= 0 && y < height_map)
        {

            if (main_map[y + 1][x] != '0' && main_map[y][x + 1] != '0' && main_map[y][x - 1] != '0' && main_map[y - 1][x] != '0')
            {
                main_map[y][x] = ' ';
                main_map[y + 1][x] = ' ';
                main_map[y][x + 1] = ' ';
                main_map[y - 1][x] = ' ';
                main_map[y][x - 1] = ' ';

            }
            else if (main_map[y + 1][x] != '0' || main_map[y][x + 1] != '0' || main_map[y][x - 1] != '0' || main_map[y - 1][x] != '0')
            {
                if (main_map[y + 1][x] == '0' && main_map[y][x + 1] != '0' && main_map[y][x - 1] != '0' && main_map[y - 1][x] != '0')
                {

                    main_map[y][x] = ' ';
                    main_map[y][x + 1] = ' ';
                    main_map[y - 1][x] = ' ';
                    main_map[y][x - 1] = ' ';

                }
                else if (main_map[y + 1][x] != '0' && main_map[y][x + 1] == '0' && main_map[y][x - 1] != '0' && main_map[y - 1][x] != '0')
                {

                    main_map[y][x] = ' ';
                    main_map[y + 1][x] = ' ';
                    main_map[y - 1][x] = ' ';
                    main_map[y][x - 1] = ' ';

                }
                else if (main_map[y + 1][x] != '0' && main_map[y][x + 1] != '0' && main_map[y][x - 1] == '0' && main_map[y - 1][x] != '0')
                {

                    main_map[y][x] = ' ';
                    main_map[y + 1][x] = ' ';
                    main_map[y][x + 1] = ' ';
                    main_map[y - 1][x] = ' ';

                }
                else if (main_map[y + 1][x] != '0' && main_map[y][x + 1] != '0' && main_map[y][x - 1] != '0' && main_map[y - 1][x] == '0')
                {

                    main_map[y][x] = ' ';
                    main_map[y + 1][x] = ' ';
                    main_map[y][x + 1] = ' ';
                    main_map[y][x - 1] = ' ';

                }
                else if (main_map[y + 1][x] == '0' && main_map[y][x + 1] == '0' || main_map[y + 1][x] == '0' && main_map[y][x - 1] == '0' && main_map[y - 1][x] != '0')
                {

                    if (main_map[y + 1][x] == '0' && main_map[y][x + 1] == '0')
                    {
                        main_map[y][x] = ' ';
                        main_map[y - 1][x] = ' ';
                        main_map[y][x - 1] = ' ';
                    }
                    else if (main_map[y + 1][x] == '0' && main_map[y][x - 1] == '0')
                    {
                        main_map[y][x] = ' ';
                        main_map[y - 1][x] = ' ';
                        main_map[y][x + 1] = ' ';
                    }

                }
                else if (main_map[y - 1][x] == '0' && main_map[y][x + 1] == '0' || main_map[y - 1][x] == '0' && main_map[y][x - 1] == '0' && main_map[y + 1][x] != '0')
                {

                    if (main_map[y - 1][x] == '0' && main_map[y][x + 1] == '0')
                    {
                        main_map[y][x] = ' ';
                        main_map[y + 1][x] = ' ';
                        main_map[y][x - 1] = ' ';
                    }
                    else if (main_map[y - 1][x] == '0' && main_map[y][x - 1] == '0')
                    {
                        main_map[y][x] = ' ';
                        main_map[y + 1][x] = ' ';
                        main_map[y][x + 1] = ' ';
                    }

                }
            }
        }
    }
    else
        sound_bomb2.play();
    Damage(player, sound_damage);
}

void Bomb::Prise(Player& player, Sound& sound_bomb2, Sound& sound_explosion, Sound& sound_damage, String* main_map, int height_map, int width_map) {
    static int counts = 10;
    int random_number_right = rand() % 6;
    int random_number_left = rand() % 6;
    int random_number_up = rand() % 6;
    int random_number_down = rand() % 6;
    bool key = false;
    if (x >= 0 || x < width_map || y >= 0 || y < height_map)
    {
        if (main_map[y + 1][x] != 'l' || main_map[y][x + 1] != 'l')
        {
            if (main_map[y + 1][x] == 'w' || main_map[y - 1][x] == 'w' || main_map[y][x + 1] == 'w' || main_map[y][x - 1] == 'w') {

                if (main_map[y + 1][x] == 'w' && main_map[y + 1][x] != '0') {
                    if (random_number_down == 4 && !key) {
                        random_number_down = rand() % counts;
                        if (counts <= 1)
                            random_number_down = 0;
                        if (random_number_down == 0 && player.GetKeyScore() != 0)
                        {
                            main_map[y + 1][x] = 'k';
                            key = true;

                        }
                        else
                        {
                            main_map[y + 1][x] = ' ';
                        }
                    }
                    else if (random_number_down == 0 || random_number_down == 2) {
                        main_map[y + 1][x] = 'h';
                    }
                    else if (random_number_down == 1 || random_number_down == 5) {
                        main_map[y + 1][x] = 'c';
                    }
                    else if (random_number_down == 3)
                        main_map[y + 1][x] = ' ';
                    counts--;
                }


                if (main_map[y - 1][x] == 'w' && main_map[y - 1][x] != '0') {
                    if (random_number_up == 4 && !key) {
                        random_number_up = rand() % counts;
                        if (counts <= 1)
                            random_number_up = 0;
                        if (random_number_up == 0 && player.GetKeyScore() != 0)
                        {
                            main_map[y - 1][x] = 'k';
                            key = true;
                        }
                        else
                        {
                            main_map[y - 1][x] = ' ';
                        }

                    }
                    else if (random_number_up == 0 || random_number_up == 2) {
                        main_map[y - 1][x] = 'h';
                    }
                    else if (random_number_up == 1 || random_number_up == 5) {
                        main_map[y - 1][x] = 'c';
                    }
                    else
                        main_map[y - 1][x] = ' ';
                    counts--;
                }

                if (main_map[y][x + 1] == 'w' && main_map[y][x + 1] != '0') {
                    if (random_number_right == 4 && !key) {
                        random_number_right = rand() % counts;
                        if (counts <= 1)
                            random_number_right = 0;
                        if (random_number_right == 0 && player.GetKeyScore() != 0)
                        {
                            main_map[y][x + 1] = 'k';
                            key = true;
                        }
                        else
                            main_map[y][x + 1] = ' ';

                    }
                    else if (random_number_right == 0 || random_number_right == 2) {
                        main_map[y][x + 1] = 'h';
                    }
                    else if (random_number_right == 1 || random_number_right == 5) {
                        main_map[y][x + 1] = 'c';
                    }
                    else
                        main_map[y][x + 1] = ' ';
                    counts--;
                }


                if (main_map[y][x - 1] == 'w' && main_map[y][x - 1] != '0') {
                    if (random_number_left == 4 && !key) {
                        random_number_left = rand() % counts;
                        if (counts <= 1)
                            random_number_left = 0;
                        if (random_number_left == 0 && player.GetKeyScore() != 0)
                        {
                            main_map[y][x - 1] = 'k';
                            key = true;
                        }
                        else
                            main_map[y][x - 1] = ' ';
                    }
                    else if (random_number_left == 0 || random_number_left == 2) {
                        main_map[y][x - 1] = 'h';
                    }
                    else if (random_number_left == 1 || random_number_left == 5) {
                        main_map[y][x - 1] = 'c';
                    }
                    else
                        main_map[y][x - 1] = ' ';
                    counts--;
                }

                Damage(player, sound_damage);
                main_map[y][x] = ' ';
            }
            else
                Explosion(player, sound_bomb2, sound_damage, main_map, height_map, width_map);
            sound_explosion.play();
        }
    }
    else
        sound_bomb2.play();

}

void Bomb::Damage(Player& player, Sound& sound_damage)
{
    int temp_x = (player.GetX() - 100) / 32 + 1;
    int temp_y = (player.GetY() - 130) / 32 + 1;
    /*cout << "Bomb X " << x << " ";
    cout << "Bomb Y " << y << "\n";
    cout << "X " << temp_x << " ";
    cout << "Y " << temp_y << "\n";*/
    if (temp_x == x && temp_y == y || temp_x == x + 1 && temp_y == y || temp_x == x - 1 && temp_y == y || temp_x == x && temp_y == y + 1 || temp_x == x && temp_y == y - 1 || temp_x == x + 1 && temp_y == y + 1 || temp_x == x - 1 && temp_y == y + 1 || temp_x == x + 1 && temp_y == y - 1 || temp_x == x - 1 && temp_y == y - 1)
    {
        player.SetHealthScore(player.GetHealthScore() - 1);
        sound_damage.play();
    }
}
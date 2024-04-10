#include "Player.h"

Player::Player(string filename, float x, float y, float width, float height) {
    speed = 0;
    is_alive = true;
    direction = 0;
    dx = 0;
    dy = 0;
    health_score = 3;
    bomb_score = 3;
    key_score = 1;
    SetWidth(width);
    SetHeight(height);
    SetFile(filename);
    SetImage(filename);
    SetTexture(image);
    SetSprite(texture);
    SetX(x);
    SetY(y);
    sprite.setTextureRect(IntRect(0, 0, width, height));
}

void Player::SetHealthScore(int health_score) {
    this->health_score = health_score;
}

int Player::GetHealthScore() const {
    return health_score;
}

void Player::SetIsAlive(bool is_life) {
    this->is_alive = is_life;
}

bool Player::GetIsAlive() const {
    return is_alive;
}
void Player::SetBombScore(int bomb_score) {
    this->bomb_score = bomb_score;
}

int Player::GetBombScore() const {
    return bomb_score;
}

void Player::SetKeyScore(int key_score) {
    this->key_score = key_score;
}

int Player::GetKeyScore() const {
    return key_score;
}

void Player::SetDirection(int direction) {
    this->direction = direction;
}

int Player::GetDirection() const {
    return direction;
}

void Player::SetSpeed(float speed) {
    this->speed = speed;
}

float Player::GetSpeed() const {
    return speed;
}

void Player::SetSprite(Texture& texture) {
    sprite.setTexture(texture);
}

Sprite& Player::GetSprite() {
    return sprite;
}

void Player::SetHeight(float height) {
    this->height = height;
}

float Player::GetHeight() const {
    return height;
}

void Player::SetWidth(float width) {
    this->width = width;
}

float Player::GetWidth() const {
    return width;
}

void Player::SetX(float x) {
    this->x = x;
}

float Player::GetX() const {
    return x;
}

void Player::SetY(float y) {
    this->y = y;
}

float Player::GetY() const {
    return y;
}

void Player::SetDx(float dx) {
    this->dx = dx;
}

float Player::GetDx() const {
    return dx;
}

void Player::SetDy(float dy) {
    this->dy = dy;
}

float Player::GetDy() const {
    return dy;
}

void Player::SetTexture(Image& image) {
    this->texture.loadFromImage(image);
}

Texture& Player::GetTexture() {
    return this->texture;
}

void Player::SetImage(string filename) {
    image.loadFromFile("D:\\ѕроекты\\Bomberman\\" + filename);
}

Image& Player::GetImage() {
    return image;
}

void Player::SetFile(string filename) {
    this->file = filename;
}

string Player::GetFile() const {
    return this->file;
}

void Player::Move(float time, Sound& sound_walk1, Sound& sound_walk2, Sound& sound_heal, Sound& sound_collide, String* main_map, int height_map, int width_map) {
    if (is_alive)
    {
        switch (direction)
        {
        case 0:
        {
            dx = speed;
            dy = 0;
            break;
        }
        case 1:
        {
            dx = -speed;
            dy = 0;
            break;
        }
        case 2:
        {
            dx = 0;
            dy = speed;
            break;
        }
        case 3:
        {
            dy = -speed;
            dx = 0;
            break;
        }
        }
        x += dx * time;
        y += dy * time;
        speed = 0;
        sprite.setPosition(x, y);
        InteractionWithMap(sound_heal, sound_collide, main_map, height_map, width_map);
    }
    if (health_score <= 0) is_alive = false;
}

void Player::Animation(Player& player, float& current_frame, float& time, Sound& sound_walk1, Sound& sound_walk2) {
    static int current_step = 0;
    float timer = timer_step1.getElapsedTime().asMilliseconds();
    if (is_alive)
    {
        if (Keyboard::isKeyPressed(Keyboard::Right))
        {           
            if (current_step == 0 && timer <= 50)
            {
                sound_walk2.play();                
            }
            if (timer >= 400)
            {
                if (current_step == 1)
                {
                    sound_walk1.play();                    
                }
                current_step = (current_step + 1) % 2;
                timer_step1.restart();
            }                                                               
            player.SetDirection(0);
            player.SetSpeed(0.1);
            current_frame += 0.005 * time;
            if (current_frame > 4)
                current_frame -= 4;
            player.GetSprite().setTextureRect(IntRect(64 * int(current_frame), 128, 64, 64));
        }

        if (Keyboard::isKeyPressed(Keyboard::Left))
        {
            if (current_step == 0 && timer <= 50)
            {
                sound_walk2.play();               
            }
            if (timer >= 400)
            {
                if (current_step == 1)
                {
                    sound_walk1.play();                  
                }
                current_step = (current_step + 1) % 2;
                timer_step1.restart();
            }
            player.SetDirection(1);
            player.SetSpeed(0.1);
            current_frame += 0.005 * time;
            if (current_frame > 4)
                current_frame -= 4;
            player.GetSprite().setTextureRect(IntRect(64 * int(current_frame), 64, 64, 64));
        }
        if (Keyboard::isKeyPressed(Keyboard::Up))
        {
            if (current_step == 0 && timer <= 50)
            {
                sound_walk2.play();               
            }
            if (timer >= 400)
            {
                if (current_step == 1)
                {
                    sound_walk1.play();                   
                }
                current_step = (current_step + 1) % 2;
                timer_step1.restart();
            }
            player.SetDirection(3);
            player.SetSpeed(0.1);
            current_frame += 0.005 * time;
            if (current_frame > 4)
                current_frame -= 4;
            player.GetSprite().setTextureRect(IntRect(64 * int(current_frame), 192, 64, 64));
        }
        if (Keyboard::isKeyPressed(Keyboard::Down))
        {
            if (current_step == 0 && timer <= 50)
            {
                sound_walk2.play();               
            }
            if (timer >= 400)
            {
                if (current_step == 1)
                {
                    sound_walk1.play();                   
                }
                current_step = (current_step + 1) % 2;
                timer_step1.restart();
            }
            player.SetDirection(2);
            player.SetSpeed(0.1);
            current_frame += 0.005 * time;
            if (current_frame > 4)
                current_frame -= 4;
            player.GetSprite().setTextureRect(IntRect(64 * int(current_frame), 0, 64, 64));
        }       
    }
}

/// <summary>
/// ѕозвол€ет не выходить персонажу за стенки пол€
/// </summary>
void Player::InteractionWithMap(Sound& sound_heal, Sound& sound_collide, String* main_map, int height_map, int width_map)
{
    if (x / 32 - 3 < width_map && y / 32 - 3 < height_map)
    {
        int temp_x = (x - 100) / 32 + 1;
        int temp_y = (y - 130) / 32 + 1;
        if (temp_x < 0 || temp_y < 0 || temp_y < 0 && temp_x < 0)
        {
            temp_x = 0;
            temp_x = 0;
        }
        if (main_map[temp_y][temp_x] == 'h')
        {
            if (health_score == 3)
                health_score = 3;
            else
            {
                sound_heal.play();
                health_score++;
                main_map[temp_y][temp_x] = ' ';
            }
        }

        else if (main_map[temp_y][temp_x] == 'k')
        {
            key_score = 0;
            main_map[temp_y][temp_x] = ' ';
        }

        else if (main_map[temp_y][temp_x] == 'c')
        {
            if (bomb_score != 3)
            {
                bomb_score++;
                main_map[temp_y][temp_x] = ' ';
            }
        }
        else if (main_map[temp_y][temp_x] == '0' || main_map[temp_y][temp_x] == 'w')
        {            
            sound_collide.play();
            if (dy > 0)// движение вниз до стенки
            {                
                y -= 15;
            }
            else if (dy < 0)// движение вверх до стенки
            {
                y += 15;
            }
            else if (dx > 0) // движение вправо до стенки
            {
                x -= 15;               
            }
            else// движение вниз до стенки
            {
                x += 15;
            }
        }

    }
}

/// <summary>
/// ”станавливает гор€чие клавиши на которые можно мен€ть вид
/// </summary>
/// <returns>¬озвращает копию камеры</returns>
View Player::ChangeView() {
    if (Keyboard::isKeyPressed(Keyboard::Z)) // zoom out view
    {
        view.zoom(1.0006f);
    }
    else if (Keyboard::isKeyPressed(Keyboard::N)) // normal view
    {
        view.setSize(1000, 700);
    }
    
    return view;
}
View Player::GetView() const {
    return view;
}
#pragma once
#include<SFML/Audio.hpp>
using namespace sf;
SoundBuffer buffer_walk1;
SoundBuffer buffer_explosion;
SoundBuffer buffer_tab;
SoundBuffer buffer_walk2;
SoundBuffer buffer_bomb;
SoundBuffer buffer_bomb2;
SoundBuffer buffer_collide;
SoundBuffer buffer_victory;
SoundBuffer buffer_defeat;
SoundBuffer buffer_heal;
SoundBuffer buffer_damage;
SoundBuffer buffer_button;

Sound sound_button(buffer_button);
Sound sound_heal(buffer_heal);
Sound sound_collide(buffer_collide);
Sound sound_explosion(buffer_explosion);
Sound sound_bomb2(buffer_bomb2);
Sound sound_tab(buffer_tab);
Sound sound_bomb(buffer_bomb);
Sound sound_walk1(buffer_walk1);
Sound sound_walk2(buffer_walk2);
Sound sound_victory(buffer_victory);
Sound sound_defeat(buffer_defeat);
Sound sound_damage(buffer_damage);
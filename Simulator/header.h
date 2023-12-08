#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include <iostream>
using namespace std;
using namespace sf;

class Game {
private:
    int WIDTH, HEIGHT;

    int fps = 60;
    float EARTH_GRAVITY = 9.81 / 8;
    float bouce_fac = 0.8;
    float time = 0.0;
    int i = 0;
    int k = 0;
    int j = 0;
    int l = 0;
    int z = 0;
    int q = 0;
    int w = 0;
    float up = 0;
    bool ground = false;
    bool top = false;
    int c = 0;

    Vector2f* ballSpeed;

    ContextSettings settings;

    Texture texture;
    Texture bgtexture;
    SoundBuffer buffer;

    Sound sound;

    RenderWindow* window;
    Event e;

    RectangleShape background;
    CircleShape ball;

public:
    Game(int W, int H, string title);

    void event();
    void update();
    void render();

    void run();

    

    void object_intialize();
    void Buffer();
    void check_boundries();
    void check_pressed();
    void speed_control();
    ~Game();
};
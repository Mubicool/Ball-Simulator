#include "Header.h"

Game::Game(int W, int H, string title) {

    //window>............
    WIDTH = W;
    HEIGHT = H;
    window = new RenderWindow(VideoMode(800, 800), "GANDU");

    //load textures & sounds
    Buffer();

    //objects
    object_intialize();

    // speeed.......
    ballSpeed = new Vector2f(0, 0);
}

void Game::event() {
    while (window->pollEvent(e))
    {
        if (e.type == Event::Closed)
            window->close();
    }

}

void Game::update()
{

    speed_control(); ///speed limits and .......

    if (i == 0)
        ballSpeed->x = 0;

    check_pressed(); /// key pressed..........................

    if (up > 0) {
        ballSpeed->y = up;
        ball.setPosition(ball.getPosition().x, ball.getPosition().y - ballSpeed->y);

    }

    else {
        if (ground != true)
            ball.setPosition(ball.getPosition().x, ball.getPosition().y + ballSpeed->y);
        top = false;
    }


    if (ballSpeed->x < 1 && ballSpeed->x > -1)
    {
        ballSpeed->x = 0;
        c = 0;
    }

    ball.setPosition(ball.getPosition().x + ballSpeed->x + c, ball.getPosition().y);


    up = up - EARTH_GRAVITY;

    check_boundries(); // boundriesssssssssssssss .............

    //cout << "Iteration = " << i << " ; Ball speed = " << ballSpeed.y << endl;

    i++;
}

void Game::render() {
    window->draw(background);
    window->draw(ball);
}

void Game::run() {
    while (window->isOpen()) {
        event();

        update();

        window->setFramerateLimit(fps);
        window->clear();
        render();
        window->display();
    }

}

Game::~Game() {
    delete window;
    delete ballSpeed;
}


void Game::Buffer() {
    //texture load......
    if (!texture.loadFromFile("image.png"))
    {
        cout << "could not" << endl;
    }
    if (!bgtexture.loadFromFile("bg.jpg"))
    {
        cout << "could not" << endl;
    }

    //sound buffer.......
    if (!buffer.loadFromFile("sound.wav"))
    {
        cout << "couldnt" << endl;
    }
    sound.setBuffer(buffer);

}

void Game::object_intialize() {

    //rectangle............
    background.setSize(sf::Vector2f(800, 800));
    bgtexture.setSmooth(true);
    background.setTexture(&bgtexture);

    //circle.................
    ball.setRadius(20);
    ball.setTexture(&texture);
    texture.setSmooth(true);
    ball.setFillColor(sf::Color(0, 0, 0));
    ball.setPosition(WIDTH / 2 - ball.getRadius(), HEIGHT / 2 - ball.getRadius());
    texture.setRepeated(true);
}

void Game::speed_control() {
    if (ballSpeed->y > 50 || ballSpeed->y < -50) {

        ballSpeed->y = 50;

    }
    ballSpeed->x = ballSpeed->x + ballSpeed->x * (-0.010);

    if (ballSpeed->y < 50 && ground != true) {

        ballSpeed->y += EARTH_GRAVITY;

    }
}

void Game::check_pressed() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
    {

        if (ball.getPosition().y > 20 && i - l > 30)
        {
            ground = false;
            ballSpeed->y = -30;

            l = i;
        }


    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
    {
        if (ball.getPosition().x <= WIDTH - ball.getRadius() * 2 - 20 && i - q > 30)
        {
            ballSpeed->x = 20;
            q = i;
        }

    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
    {
        if (ball.getPosition().x >= 0 + 20 && i - w > 30)
        {
            ballSpeed->x = -20;
            w = i;
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
    {
        ballSpeed->x = 0;
        ballSpeed->y = 0;
        int i = 0;
        int k = 0;
        int j = 0;
        int l = 0;
        int z = 0;
        float up = 0;
        bool ground = false;
        bool top = false;
        int c = 0;
        ball.setPosition(WIDTH / 2 - ball.getRadius(), HEIGHT / 2 - ball.getRadius());

    }
}

void Game::check_boundries() {
    if (ball.getPosition().x >= WIDTH - ball.getRadius() * 2 || ball.getPosition().x <= 0) {

        ballSpeed->x = -ballSpeed->x;
        if (ball.getPosition().x >= WIDTH - ball.getRadius() * 2)
            ball.setPosition(WIDTH - ball.getRadius() * 2, ball.getPosition().y);
        if (ball.getPosition().x <= 0)
            ball.setPosition(0, ball.getPosition().y);
        ballSpeed->x = ballSpeed->x + ballSpeed->x * (-0.10);
        sound.play();
    }
    if (ball.getPosition().y <= 0)
    {
        if (i - j != 1) {
            top = true;

            ballSpeed->y = up + ballSpeed->y;
            up = 0;
            ballSpeed->y = ballSpeed->y + ballSpeed->y * bouce_fac;
            int j = i;
            ball.setPosition(ball.getPosition().x, 0);
            //std::cout << "top !!" << std::endl;
            sound.play();
        }
    }
    if (ball.getPosition().y >= HEIGHT - (ball.getRadius() * 2)) {
        if (ground != true) {

            if (i - k - 1 != 0) {

                time = (ballSpeed->y * 2.83) / (EARTH_GRAVITY * 8);
                //std::cout << "Ball speed = " << ballSpeed.y * 2.83 << " ; time = " << time << std::endl;
                ballSpeed->y = -ballSpeed->y * bouce_fac;
                /*ballSpeed.x = ballSpeed.x + ballSpeed.x * (-0.10);*/
                ground = false;
                //std::cout << "Bounce Speed  " << ballSpeed.y << std::endl;
                k = i;
                sound.play();
            }
        }
        if (ballSpeed->y > -3)
        {
            ground = true;
            ball.setPosition(ball.getPosition().x, HEIGHT - ball.getRadius() * 2);
            ballSpeed->y = 0;
        }
    }
}


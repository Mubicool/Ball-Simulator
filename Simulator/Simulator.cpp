#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cmath>



int main() {
    int WIDTH = 800;
    int HEIGHT = 800;
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
    sf::ContextSettings settings;
    
    sf::Texture texture;
    sf::Texture bgtexture;
    if (!texture.loadFromFile("image.png"))
    {
        std::cout << "could not" << std::endl;
        return -1;
    }
    if (!bgtexture.loadFromFile("bg.jpg"))
    {
        std::cout << "could not" << std::endl;
        return -1;
    }
    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile("sound.wav"))
    {
        std::cout << "couldnt" << std::endl;
        return -1;
    }
    sf::Sound sound;
    sound.setBuffer(buffer);
    sf::CircleShape triangle(100, 3);
    triangle.setPosition(700, 700);
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Bouncing Ball", sf::Style::Default, settings);
    window.setFramerateLimit(60);
    sf::RectangleShape background(sf::Vector2f(800, 800));
    bgtexture.setSmooth(true);
    background.setTexture(&bgtexture);
    sf::CircleShape ball(20);
    ball.setTexture(&texture);
    texture.setSmooth(true);
    ball.setFillColor(sf::Color(0, 0, 0));
    ball.setPosition(WIDTH / 2 - ball.getRadius(), HEIGHT / 2 - ball.getRadius());
    texture.setRepeated(true);
    sf::Vector2f ballSpeed(0, 0);
    settings.antialiasingLevel = 8;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if (ballSpeed.y > 50 || ballSpeed.y < -50) {
            
            ballSpeed.y = 50;
           


        }
        ballSpeed.x = ballSpeed.x + ballSpeed.x * (-0.010);
       
        if (ballSpeed.y < 50 && ground != true) {

            ballSpeed.y += EARTH_GRAVITY;

        }
        if (i == 0)
            ballSpeed.x = 0;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
        {
            
             
                if (ball.getPosition().y > 20 && i - l > 30)
                {
                    ground = false;
                    ballSpeed.y = -30;
                    
                    l = i;
                }
            

        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
        {
            if (ball.getPosition().x <= WIDTH - ball.getRadius() * 2 - 20 && i - q > 30)
            {
                ballSpeed.x = 20;
                q = i;
            }

        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
        {
            if (ball.getPosition().x >= 0 + 20 && i - w > 30)
            {
                ballSpeed.x = -20;
                w = i;
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
        {
            ballSpeed.x = 0;
            ballSpeed.y = 0;
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
            continue;

        }
        if (up > 0) {
            ballSpeed.y = up;
            ball.setPosition(ball.getPosition().x, ball.getPosition().y - ballSpeed.y);
            
        }

        else {
            if (ground != true)
                ball.setPosition(ball.getPosition().x, ball.getPosition().y + ballSpeed.y);
            top = false;
        }
       

        if (ballSpeed.x < 2 && ballSpeed.x > -2)
        {
            ballSpeed.x = 0;
            c = 0;
        }
        ball.setPosition(ball.getPosition().x + ballSpeed.x + c, ball.getPosition().y);
       

        up = up - EARTH_GRAVITY;

        if (ball.getPosition().x >= WIDTH - ball.getRadius() * 2 || ball.getPosition().x <= 0) {

            
            ballSpeed.x = -ballSpeed.x;
            if (ball.getPosition().x >= WIDTH - ball.getRadius() * 2)
            ball.setPosition(WIDTH - ball.getRadius() * 2, ball.getPosition().y);
            if (ball.getPosition().x <= 0)
                ball.setPosition(0, ball.getPosition().y);
            ballSpeed.x = ballSpeed.x + ballSpeed.x * (-0.10);
            sound.play();
        }
        if (ball.getPosition().y <= 0)
        {
            if (i - j == 1)
                continue;
            top = true;

            ballSpeed.y = up + ballSpeed.y;
            up = 0;
            ballSpeed.y = ballSpeed.y + ballSpeed.y * bouce_fac;
            int j = i;
            ball.setPosition(ball.getPosition().x, 0);
            //std::cout << "top !!" << std::endl;
            sound.play();

        }
        if (ball.getPosition().y >= HEIGHT - (ball.getRadius() * 2)) {
            if (ground != true) {
                if (i - k - 1 == 0)
                    continue;
                time = (ballSpeed.y * 2.83) / (EARTH_GRAVITY * 8);

                //std::cout << "Ball speed = " << ballSpeed.y * 2.83 << " ; time = " << time << std::endl;
                ballSpeed.y = -ballSpeed.y * bouce_fac;
                /*ballSpeed.x = ballSpeed.x + ballSpeed.x * (-0.10);*/
                ground = false;
                //std::cout << "Bounce Speed  " << ballSpeed.y << std::endl;
                k = i;
                sound.play();
            }
            if (ballSpeed.y > -3)
            {
                ground = true;
                ball.setPosition(ball.getPosition().x, HEIGHT - ball.getRadius() * 2);
                ballSpeed.y = 0;



            }
        }
 //       std::cout << "Iteration = " << i << " ; Ball speed = " << ballSpeed.y << std::endl;
        
        i++;
        window.clear();
        window.draw(background);
        window.draw(ball);
        window.display();

    }

    return 0;
}
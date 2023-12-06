#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>



int main() {
    int WIDTH = 800;
    int HEIGHT = 800;
    float EARTH_GRAVITY = 9.81 / 8; 
    float BOUNCE_FACTOR_RUBBER = 0.7;
    float time = 0.0;
    int i = 0;
    float up = 0;
    bool ground = false;

    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Bouncing Ball");
    window.setFramerateLimit(60);

    sf::CircleShape ball(20);
    ball.setFillColor(sf::Color::Red);
    ball.setPosition(WIDTH / 2 - ball.getRadius(), -100);

    sf::Vector2f ballSpeed(0, 0);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if (ballSpeed.y < 30) {
            
            ballSpeed.y += EARTH_GRAVITY;
            
        }
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
        {
            
            ground = false;
                up = 20;
                
                
            
        }
        if (up > 0) {
            ballSpeed.y = 0;
            ball.setPosition(ball.getPosition().x, ball.getPosition().y - up);
        }

        else {
            if(ground != true)
            ball.setPosition(ball.getPosition() + ballSpeed);
        }
        
        up = up - EARTH_GRAVITY;
        
        if (ball.getPosition().x >= WIDTH - ball.getRadius() * 2 || ball.getPosition().x <= 0) {
            
            ballSpeed.x = -ballSpeed.x * BOUNCE_FACTOR_RUBBER;
        }
        
        if (ball.getPosition().y >= HEIGHT - ball.getRadius()) {
            
            time = (ballSpeed.y * 2.83 ) / (EARTH_GRAVITY * 8);
            std::cout << "Ball speed = " << ballSpeed.y *2.83 <<  " ; time = " << time << std::endl;
            ballSpeed.y = -ballSpeed.y * BOUNCE_FACTOR_RUBBER;
            if (ballSpeed.y > 0)
            {
                ground = true;
                ball.setPosition(ball.getPosition().x,ball.getPosition().y - ball.getRadius());
            
            }
        }
        
        i++;
        window.clear();
        window.draw(ball);
        window.display();
        
    }

    return 0;
}

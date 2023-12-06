#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>



int main() {
    int WIDTH = 800;
    int HEIGHT = 800;
    float EARTH_GRAVITY = 9.81; 
    float BOUNCE_FACTOR_RUBBER = 0.7;
    float time = 0.0;
    int i = 0;
    float up = 0;

    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Bouncing Ball");
    window.setFramerateLimit(60);

    sf::CircleShape ball(20);
    ball.setFillColor(sf::Color::Red);
    ball.setPosition(WIDTH / 2 - ball.getRadius(), ball.getRadius());

    sf::Vector2f ballSpeed(0, 0);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        window.clear();
        ballSpeed.y += EARTH_GRAVITY; 
        window.clear();
        
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
        {
            window.clear();
            
                up = 50;
                
                
            
        }
        if (up > 0) {
            window.clear();
            ball.setPosition(ball.getPosition().x, ball.getPosition().y - up);
        }

        else {
            window.clear();
            ball.setPosition(ball.getPosition() + ballSpeed);
        }
        window.clear();
        up = up - EARTH_GRAVITY;
        window.clear();
        if (ball.getPosition().x >= WIDTH - ball.getRadius() * 2 || ball.getPosition().x <= 0) {
            window.clear();
            ballSpeed.x = -ballSpeed.x * BOUNCE_FACTOR_RUBBER;
        }
        window.clear();
        if (ball.getPosition().y >= HEIGHT - ball.getRadius()) {
            window.clear();
            time = ballSpeed.y / EARTH_GRAVITY;
            std::cout << "Ball speed = " << ballSpeed.y <<  " ; time = " << time << std::endl;
            ballSpeed.y = -ballSpeed.y * BOUNCE_FACTOR_RUBBER;
        }
        window.clear();
        i++;
        window.clear();
        window.draw(ball);
        window.display();
    }

    return 0;
}

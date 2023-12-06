#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cmath>



int main() {
    int WIDTH = 800;
    int HEIGHT = 800;
    float Gravity = 9.81 / 8; 
    float bouce_fac =0.7;
    float time = 0.0;
    int i = 0;
    int k = 0;
    int j = 0;
    int l = 0;
    int z = 0;
    float up = 0;
    bool ground = false;
    bool top = false;
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::Texture texture;
    if (!texture.loadFromFile("image.png"))
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
    
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Bouncing Ball", sf::Style::Default, settings);
    window.setFramerateLimit(60);

    sf::CircleShape ball(40);
    ball.setFillColor(sf::Color(255, 130, 130));
    ball.setPosition(WIDTH / 2 - ball.getRadius(), HEIGHT / 2 - ball.getRadius());

    sf::Vector2f ballSpeed(10, 5);
    
    ball.setTexture(&texture);
    
    texture.setSmooth(true);
    
    

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if (ballSpeed.y > 10 || ballSpeed.y < -10) {
            /*if (ballSpeed.y > 100)*/
            ballSpeed.y = 10;
           /* if (ballSpeed.y < -100)
                ballSpeed.y = -100;*/


        }
        //if (ballSpeed.y < 30 && ground != true) {
        //    
        //    ballSpeed.y += Gravity;
        //    
        //}
        //if(i ==0)
        //ballSpeed.x = 0;
        //if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
        //{
        //    if (top == true)
        //        continue;
        //    ground = false;
        //    
        //        up = 20;
        //        l = i;
        //        
        //    
        //}
        //if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
        //{

        //    ballSpeed.x = 5;
        //   



        //}
        //if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
        //{

        //    ballSpeed.x = -5;
        //   



        //}
        //if (up > 0) {
        //    ballSpeed.y = up;
        //    ball.setPosition(ball.getPosition().x, ball.getPosition().y - ballSpeed.y);
        //   // std::cout << "up speed = " << up << std::endl;
        //}

        //else {

        //    if(ground != true)
        //    ball.setPosition(ball.getPosition().x,ball.getPosition().y + ballSpeed.y);
        //    top = false;
        //}
        //ball.setPosition(ball.getPosition().x + ballSpeed.x, ball.getPosition().y);
        //up = up - Gravity;
        ball.setPosition(ball.getPosition().x + ballSpeed.x, ball.getPosition().y + ballSpeed.y);
        if (ball.getPosition().x >= WIDTH - ball.getRadius() * 2 || ball.getPosition().x <= 0 ) {

            ballSpeed.x = -ballSpeed.x;// * bouce_fac;
            sound.play();
        }
        if (ball.getPosition().y <= 0)
        {
            if (i - j == 1)
                continue;
            top = true;
            
           // ballSpeed.y = up + ballSpeed.y;
            //up = 0;
            ballSpeed.y = ballSpeed.y * 2 * bouce_fac ;
            //int j = i;
            ball.setPosition(ball.getPosition().x,0);
            //std::cout << "top !!" << std::endl;
            sound.play();
         
        }
        if (ball.getPosition().y >= HEIGHT - (ball.getRadius()*2)) {
            if (ground != true) {
                if (i - k - 1 == 0)
                    continue;
                //time = (ballSpeed.y * 2.83) / (Gravity * 8);
                
                //std::cout << "Ball speed = " << ballSpeed.y * 2.83 << " ; time = " << time << std::endl;
                ballSpeed.y = -ballSpeed.y;// *bouce_fac;
                ground = false;
                //std::cout << "Bounce Speed  " << ballSpeed.y << std::endl;
                k = i;
                sound.play();
            }
            if (ballSpeed.y > -3)
            {
                ground = true;
                ball.setPosition(ball.getPosition().x,HEIGHT - ball.getRadius()*2);
                //ballSpeed.y = 0;
                
            
            }
        }
        //std::cout << "Iteration = " << i << " ; Ball speed = " << ballSpeed.y << std::endl;
        i++;
        window.clear();
        window.draw(ball);
        
        window.display();
        
    }

    return 0;
}

#ifdef _DEBUG 
#pragma comment(lib,"sfml-graphics-d.lib") 
#pragma comment(lib,"sfml-audio-d.lib") 
#pragma comment(lib,"sfml-system-d.lib") 
#pragma comment(lib,"sfml-window-d.lib") 
#pragma comment(lib,"sfml-network-d.lib") 
//#pragma comment(lib,"thor-d.lib") 
#else 
#pragma comment(lib,"sfml-graphics.lib") 
#pragma comment(lib,"sfml-audio.lib") 
#pragma comment(lib,"sfml-system.lib") 
#pragma comment(lib,"sfml-window.lib") 
#pragma comment(lib,"sfml-network.lib") 
//#pragma comment(lib,"thor.lib") 
#endif 
#pragma comment(lib,"opengl32.lib") 
#pragma comment(lib,"glu32.lib") 
//#pragma comment(lib,"libyaml-cppmdd") 

#include <SFML/Graphics.hpp>
#include <iostream>
#include <Windows.h>

#include <SFML/Graphics.hpp>


class CircleTarget  {
private:
    sf::CircleShape circle;
    int radius;

public:
    CircleTarget(float radius, sf::Color color, int x, int y) : circle() {
    	circle.setFillColor(color);
		circle.setRadius(radius);
		circle.setPosition(x, y);
    }

    void draw(sf::RenderWindow& window){
        window.draw(circle);
    }

    bool isPointInside(sf::Vector2i point) {
        return circle.getGlobalBounds().contains(point.x, point.y);
    }

};

class SquareTarget {
private:
    sf::RectangleShape square;


public:
    SquareTarget(float width, sf::Color color, int x, int y) {
        square.setFillColor(color);
        square.setSize(sf::Vector2f(width, width));
        square.setPosition(x, y);
    }

    void draw(sf::RenderWindow& window) {
        window.draw(square);
    }

    bool isPointInside(sf::Vector2i point) {
        return square.getGlobalBounds().contains(point.x, point.y);
    }

};

class CarTarget {
private:
    sf::RectangleShape body;
    sf::RectangleShape top;
    sf::CircleShape frontWheel;
    sf::CircleShape backWheel;

public:
    CarTarget(sf::Color color, int x, int y) {

        top.setFillColor(color);
        top.setSize(sf::Vector2f(50, 20));
        top.setPosition(x+50, y);

        body.setFillColor(color);
        body.setSize(sf::Vector2f(100, 20));
        body.setPosition(x, y+20);

        frontWheel.setFillColor(sf::Color::Black);
        frontWheel.setRadius(10);
        frontWheel.setPosition(x+10, y+40);

        backWheel.setFillColor(sf::Color::Black);
        backWheel.setRadius(10);
        backWheel.setPosition(x+70, y+40);


      }

    void draw(sf::RenderWindow& window) {
        window.draw(body);
        window.draw(top);
        window.draw(frontWheel);
        window.draw(backWheel);
    }

    bool isPointInside(sf::Vector2i point) {
        return 
            body.getGlobalBounds().contains(point.x, point.y) || 
            top.getGlobalBounds().contains(point.x, point.y) || 
            frontWheel.getGlobalBounds().contains(point.x, point.y) || 
            backWheel.getGlobalBounds().contains(point.x, point.y);
    }

};

class Game {
    int screenWidth = 1200;
    int screenHeight = 800;
    sf::RenderWindow window;
    std::vector<sf::Color> colors = { sf::Color::Red, sf::Color::Green, sf::Color::Blue, sf::Color::Yellow, sf::Color::Magenta, sf::Color::Cyan, sf::Color::White };

    sf::Color randomColor() {
		return colors[rand() % colors.size()];
	}

    std::vector<CircleTarget*> targets;

public:
    Game() : window(sf::VideoMode(screenWidth, screenHeight), "SFML Application") {}

    void run() {
        
        for (int i = 0; i < 10; i++) {
            targets.push_back(new CircleTarget(50, randomColor(), rand() % screenWidth, rand() % screenHeight));
		}   
        //
        SquareTarget square(50, randomColor(), rand() % screenWidth, rand() % screenHeight);
        CarTarget car(randomColor(), rand() % screenWidth, rand() % screenHeight);

        sf::RenderWindow ;
        window.setFramerateLimit(25);

        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                for (auto shape : targets) {
                    if(shape->isPointInside(mousePos))
						targets.erase(std::remove(targets.begin(), targets.end(), shape), targets.end());   
                }
            }
            
            window.clear(sf::Color::Color(200, 200, 220));
            for (auto shape : targets) {
                shape->draw(window);
			}

            square.draw(window);
            car.draw(window);
            window.display();
  

        }
    }
};
int main() {


    Game game;
    game.run();

    return 0;
}
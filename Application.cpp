#include "Application.h"

#include <SFML/System/Clock.hpp>

#include "Display.h"
#include "World/Floor.h"
#include "World/Flock.h"

Application::Application()
{

}

void Application::runMainGameLoop()
{
    sf::Clock clock;
    Vector3 lightPos = Vector3(0.0, 10.0, 0.0);
    Floor floor = Floor(50.0, 50.0, {0.0, -2.0, 0.0});
    Flock flock = Flock("boid", 0.1, 100, {0.0, 0.0, 0.0}, 50.0, -2.0, 50.0);
    while (Display::isOpen())
    {
        auto dt = clock.restart().asSeconds();

        flock.update(dt);

        m_renderer.clear();

        //Player input not affecting camera

        m_camera.update();
        m_camera.input(dt);

        //Draw objects
        m_renderer.draw(floor);
        m_renderer.draw(flock.m_multiModels);

        m_renderer.update(m_camera, lightPos);

        Display::checkForClose();
    }
}

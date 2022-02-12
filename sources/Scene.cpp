#include <pch.hpp>
#include <Scene.hpp>
#include <Actor/AActor.hpp>

::rts::Scene::Scene(::rts::Window& window)
    : window(window)
{
}

::rts::Scene::~Scene() = default;

void ::rts::Scene::update()
{
    // for (auto& actor : m_actors)
    //     actor->update();
    // for (auto& elem : m_ui)
    //    elem->update();
    // todo implement actors and ui
}

void ::rts::Scene::draw() const
{
    // for (auto& actor : m_actors)
    //     actor->draw();
    // for (auto& elem : m_ui)
    //    elem->draw();
    // todo implement actors and ui
}

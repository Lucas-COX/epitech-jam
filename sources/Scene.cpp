#include <pch.hpp>
#include <Scene.hpp>
#include <Window.hpp>
#include <Actor/AActor.hpp>
#include <Object/Background.hpp>
#include <Object/MainCharacter.hpp>
#include <Object/Pickup/Food.hpp>
#include <Object/Pickup/Book.hpp>
#include <Object/Bar/Evolution.hpp>
#include <Object/Bar/Energy.hpp>



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// *structors
//
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
::rts::Scene::Scene(
    ::rts::Window& window
)
    : m_window(window)
    , m_music("music.wav")
{
    m_uis.push_back(::std::make_shared<::rts::object::Background>("background.png"));
    m_uis.push_back(::std::make_shared<::rts::object::bar::Evolution>());
    m_uis.push_back(::std::make_shared<::rts::object::bar::Energy>());
    m_actors.push_back(::std::make_shared<::rts::object::MainCharacter>());
    m_actors.push_back(::std::make_shared<::rts::object::pickup::Book>(0));
    m_actors.push_back(::std::make_shared<::rts::object::pickup::Food>(1));
    m_actors.push_back(::std::make_shared<::rts::object::pickup::Food>(2));
    m_music.play();
}

///////////////////////////////////////////////////////////////////////////
::rts::Scene::~Scene() = default;



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// Actions
//
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
void ::rts::Scene::update()
{
    m_window.handleEvents(*this);
    ::std::ranges::for_each(m_actors, [this](auto& actor){ actor->update(m_clock.getElapsed(), *actor); });
    ::std::ranges::for_each(m_uis, [this](auto& actor){ actor->update(m_clock.getElapsed(), *actor); });
    ::std::ranges::for_each(m_actors, [this](auto& actor){ actor->update(m_clock.getElapsed(), *actor); });
    for (auto& actor : m_actors | std::views::drop(1)) {
        if (m_actors[0]->doesCollide(actor)) {
            auto pickupActor{ static_pointer_cast<::rts::actor::APickupActor>(actor) };
            switch (pickupActor->getPickupType()) {
            case ::rts::actor::APickup::Type::eChanger: {
                static_pointer_cast<::rts::actor::ABar>(m_uis[1])->addValue(pickupActor->getPickupValue());
                static_pointer_cast<::rts::actor::ABar>(m_uis[2])->subValue(pickupActor->getPickupValue());
                break;
            } case ::rts::actor::APickup::Type::fChanger: {
                static_pointer_cast<::rts::actor::ABar>(m_uis[1])->subValue(
                    static_pointer_cast<::rts::actor::ABar>(m_uis[2])->addValue(
                        pickupActor->getPickupValue()
                    ) / 5
                );
            }}
            ::rts::actor::APickup::playSound(pickupActor);
            ::std::erase(m_actors, actor);
            break;
        }
    }
}

///////////////////////////////////////////////////////////////////////////
void ::rts::Scene::draw() const
{
    m_window.clear();
    ::std::ranges::for_each(m_uis, [this](auto& actor){ actor->draw(m_window); });
    ::std::ranges::for_each(m_actors, [this](auto& actor) { actor->draw(m_window); });
    m_window.display();
}

///////////////////////////////////////////////////////////////////////////
[[ nodiscard ]] auto ::rts::Scene::isOver() const
    -> bool
{
    return !m_window.isOpen() || m_isOver;
}

///////////////////////////////////////////////////////////////////////////
auto ::rts::Scene::handleEvent(
    sf::Event& event
) -> bool
{
    switch (event.type) {
    case ::sf::Event::Closed: m_window.close(); return false;
    case ::sf::Event::KeyPressed:
        switch (event.key.code) {
        case sf::Keyboard::Key::Escape: m_window.close(); return false;
        case sf::Keyboard::Key::Left:
            static_pointer_cast<::rts::object::MainCharacter>(m_actors[0])->goToLeftSideRoad(); return false;
        case sf::Keyboard::Key::Right:
            static_pointer_cast<::rts::object::MainCharacter>(m_actors[0])->goToRightSideRoad(); return false;
        default: return true;
        }
    default: return true;
    }
}

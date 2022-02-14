#include <pch.hpp>
#include <Scene.hpp>
#include <Window.hpp>
#include <Actor/AActor.hpp>
#include <Object/Background.hpp>
#include <Object/MainCharacter.hpp>
#include <Object/Pickup/Food.hpp>
#include <Object/Pickup/Book.hpp>
#include <Object/Pickup/Wave.hpp>
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
    , m_lastEnergyLoss{ m_clock.getElapsed() }
    , m_lastPickup{ m_clock.getElapsed() }
    , m_numberOfConsecutiveBook{ 3 }
{
    // initialize random seed
    ::std::srand(::std::time(nullptr));

    m_music.play();

    m_uis.push_back(::std::make_shared<::rts::object::Background>("background.png"));
    m_uis.push_back(::std::make_shared<::rts::object::bar::Evolution>());
    m_uis.push_back(::std::make_shared<::rts::object::bar::Energy>());
    m_actors.push_back(::std::make_shared<::rts::object::MainCharacter>());
    m_actors.push_back(::std::make_shared<::rts::object::pickup::Book>(1));
    m_actors.push_back(::std::make_shared<::rts::object::pickup::Book>(2));
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
auto ::rts::Scene::update()
    -> bool
{
    m_window.handleEvents(*this);

    if (m_clock.getElapsed() - m_lastWave >= 500) {
        int maxValue{ static_cast<int>(2000 - (m_clock.getElapsed() - m_lastWave)) };
        if (maxValue <= 0 || !(::std::rand() % maxValue)) {
            m_actors.push_back(::std::make_shared<::rts::object::pickup::Wave>(::std::rand() % 3 + 4));
            m_lastWave = m_clock.getElapsed();
        }
    }

    // book spawn
    if (m_clock.getElapsed() - m_lastPickup >= 2000) {
        int maxValue{ static_cast<int>(4000 - (m_clock.getElapsed() - m_lastPickup)) };
        if (maxValue <= 0 || !(::std::rand() % maxValue)) {
            if (m_numberOfConsecutiveBook == 3 || !(::std::rand() % 2)) {
                m_numberOfConsecutiveBook = 0;
                m_actors.push_back(::std::make_shared<::rts::object::pickup::Food>(::std::rand() % 3));
            } else {
                m_numberOfConsecutiveBook++;
                m_actors.push_back(::std::make_shared<::rts::object::pickup::Book>(::std::rand() % 3));
            }
            m_lastPickup = m_clock.getElapsed();
        }
    }

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

    // energy loss
    if (m_clock.getElapsed() - m_lastEnergyLoss >= 10) {
        m_lastEnergyLoss = m_clock.getElapsed();
        static_pointer_cast<::rts::actor::ABar>(m_uis[2])->subValue(0.05);
    }

    if (static_pointer_cast<::rts::actor::ABar>(m_uis[1])->getValue() <= 40) {
        static_pointer_cast<::rts::object::MainCharacter>(m_actors[0])->becomeGorilla();
    } else if (static_pointer_cast<::rts::actor::ABar>(m_uis[1])->getValue() >= 80) {
        static_pointer_cast<::rts::object::MainCharacter>(m_actors[0])->becomeMech();
    } else {
        static_pointer_cast<::rts::object::MainCharacter>(m_actors[0])->becomeMan();
    }

    // die
    if (
        static_pointer_cast<::rts::actor::ABar>(m_uis[1])->getValue() <= 0 ||
        static_pointer_cast<::rts::actor::ABar>(m_uis[2])->getValue() <= 0
    ) {
        ::std::cout << "you died, lmao, you nub" << ::std::endl;
        return false;
    }

    // win
    if (static_pointer_cast<::rts::actor::ABar>(m_uis[1])->getValue() >= 100) {
        return false;
    }
    return true;
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
auto ::rts::Scene::hasWon()
    -> bool
{
    if (static_pointer_cast<::rts::actor::ABar>(m_uis[1])->getValue() >= 100) {
        ::std::cout << "fk, this dogshit player won, SHIEEEET" << ::std::endl;
        return true;
    }
    return false;
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

auto ::rts::Scene::getEvolution() const
    -> int
{
    return static_pointer_cast<::rts::actor::ABar>(m_uis[1])->getValue();
}

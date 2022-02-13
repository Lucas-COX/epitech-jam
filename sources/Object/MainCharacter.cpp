#include <pch.hpp>
#include <Object/MainCharacter.hpp>



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// *structors
//
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
::rts::object::MainCharacter::MainCharacter()
    : ::rts::actor::AActor{ "gorilla.png", 6 }
    , m_state(::rts::object::MainCharacter::State::MONKE)
{
    this->setRefreshRate(75);
    this->setScale(4);
    this->moveDown(750);
    this->moveRight(1920 / 2 - 135);
}

///////////////////////////////////////////////////////////////////////////
::rts::object::MainCharacter::~MainCharacter() = default;

///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
/// \brief Move left if possible
///
///////////////////////////////////////////////////////////////////////////
void ::rts::object::MainCharacter::goToLeftSideRoad()
{
    if (pos != 0) {
        pos--;
        this->moveLeft(400);
    }
}

///////////////////////////////////////////////////////////////////////////
/// \brief Move right if possible
///
///////////////////////////////////////////////////////////////////////////
void ::rts::object::MainCharacter::goToRightSideRoad()
{
    if (pos != 2) {
        pos++;
        this->moveRight(400);
    }
}

void ::rts::object::MainCharacter::becomeGorilla()
{
    if (m_state == State::MONKE) return;
    if (!this->m_texture.loadFromFile("./data/sprites/gorilla.png")) {
        throw ::std::runtime_error{ "texture failed to load" };
    }
    this->m_sprite.setTexture(this->m_texture);
    this->m_sprite.setTextureRect(sf::IntRect {
        0,
        0,
        static_cast<int>(this->m_texture.getSize().x),
        static_cast<int>(this->m_texture.getSize().y)
    });
    this->m_nmemb = 6;
    this->m_offset = this->computeOffset("gorilla.png", 6);
    this->m_sprite.setTextureRect(::sf::IntRect{
        0,
        0,
        static_cast<int>(this->m_offset),
        static_cast<int>(this->m_sprite.getLocalBounds().height)
    });
    this->m_state = State::MONKE;
}

void ::rts::object::MainCharacter::becomeMan()
{
    if (m_state == State::MAN) return;
    if (!this->m_texture.loadFromFile("./data/sprites/main.png")) {
        throw ::std::runtime_error{ "texture failed to load" };
    }
    this->m_sprite.setTexture(this->m_texture);
    this->m_sprite.setTextureRect(sf::IntRect {
        0,
        0,
        static_cast<int>(this->m_texture.getSize().x),
        static_cast<int>(this->m_texture.getSize().y) });
    this->m_nmemb = 6;
    this->m_offset = this->computeOffset("main.png", 6);
    this->m_sprite.setTextureRect(::sf::IntRect{
            0,
            0,
            static_cast<int>(this->m_offset),
            static_cast<int>(this->m_sprite.getLocalBounds().height)
    });
    this->m_state = State::MAN;
}

void ::rts::object::MainCharacter::becomeMech()
{
    if (m_state == State::MECH) return;
    if (!this->m_texture.loadFromFile("./data/sprites/robot.png")) {
        throw ::std::runtime_error{ "texture failed to load" };
    }
    this->m_sprite.setTexture(this->m_texture);
    this->m_sprite.setTextureRect(sf::IntRect {
        0,
        0,
        static_cast<int>(this->m_texture.getSize().x),
        static_cast<int>(this->m_texture.getSize().y) });
    this->m_nmemb = 4;
    this->m_offset = this->computeOffset("robot.png", this->m_nmemb);
    this->m_sprite.setTextureRect(::sf::IntRect{
            0,
            0,
            static_cast<int>(this->m_offset),
            static_cast<int>(this->m_sprite.getLocalBounds().height)
    });
    this->m_state = State::MECH;
}

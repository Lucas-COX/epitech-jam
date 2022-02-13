#include <pch.hpp>
#include <Actor/APickupActor.hpp>

::rts::actor::APickupActor::APickupActor(
    const ::std::string& filenameSprite,
    const ::std::string& filenameSound,
    ::rts::actor::APickup::Type type,
    ::std::uint8_t nmemb,
    ::std::uint8_t lane
)
    : AActor(filenameSprite, nmemb)
    , APickup(filenameSound, type)
    , m_lastCall(0)
{
    m_lane = lane;
    this->setScale(0.85);
    if (lane == 0) {
        this->moveRight(575);
    } else if (lane == 1) {
        this->moveRight(880);
    } else {
        this->moveRight(1175);
    }
}

::rts::actor::APickupActor::~APickupActor() = default;

void ::rts::actor::APickupActor::update(
    ::rts::Time deltaTime,
    const ::rts::actor::Movable &movable
)
{
    ::rts::actor::Drawable::update(deltaTime, movable);

    if (deltaTime - m_lastCall >= 50) {
        this->moveDown(5);
        if (m_lane == 0) {
            this->moveLeft(0.8);
        } else if (m_lane == 2) {
            this->moveRight(0.8);
        }
        this->setScale(this->getScale() + 0.0025);
        m_lastCall = deltaTime;
    }
}

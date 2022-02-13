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
    this->setScale(0.75);
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

    if (deltaTime - m_lastCall >= 10) {
        this->moveDown(3);
        if (m_lane == 0) {
            this->moveLeft(0.5);
        } else if (m_lane == 1) {
            this->moveLeft(0.025);
        } else {
            this->moveRight(0.4);
        }
        this->setScale(this->getScale() + 0.0025);
        m_lastCall = deltaTime;
    }
}

auto ::rts::actor::APickupActor::getLane() const
    -> uint8_t
{
    return m_lane;
}

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
    , m_lane{ lane }
{
    this->setScale(0.75);
    if (lane == 0) {
        this->moveRight(575);
    } else if (lane == 1) {
        this->moveRight(880);
    } else if (lane == 2) {
        this->moveRight(1175);
    } else if (lane == 3) {
        this->moveRight(100);
    } else if (lane == 4) {
        this->moveRight(200);
    } else if (lane == 5) {
        this->moveRight(1400);
    } else if (lane == 6) {
        this->moveRight(1500);
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
            this->moveLeft(0.65);
        } else if (m_lane == 1) {
            this->moveLeft(0.025);
        } else if (m_lane == 2) {
            this->moveRight(0.4);
        } else if (m_lane == 3) {
            this->moveLeft(0.9);
        } else if (m_lane == 4) {
            this->moveLeft(1.0);
        } else if (m_lane == 5) {
            this->moveRight(0.6);
        } else if (m_lane == 6) {
            this->moveRight(0.7);
        }
        this->setScale(this->getScale() + 0.001);
        m_lastCall = deltaTime;
    }
}

auto ::rts::actor::APickupActor::getLane() const
    -> uint8_t
{
    return m_lane;
}

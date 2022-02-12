#include <pch.hpp>
#include <Actor/APickupActor.hpp>

::rts::actor::APickupActor::APickupActor(
    const ::std::string& filenameSprite,
    const ::std::string& filenameSound,
    ::rts::actor::APickup::Type type,
    ::std::uint8_t nmemb
)
    : AActor(filenameSprite, nmemb)
    , APickup(filenameSound, type)
{
}

::rts::actor::APickupActor::~APickupActor() = default;

void ::rts::actor::APickupActor::update(
    ::rts::Time deltaTime,
    const ::rts::actor::Movable &movable
)
{

}
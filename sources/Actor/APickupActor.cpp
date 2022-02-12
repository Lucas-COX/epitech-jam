#include <pch.hpp>
#include <Actor/APickupActor.hpp>

::rts::actor::APickupActor::APickupActor(
    const ::std::string& filenameSprite,
    const ::std::string& filenameSound,
    ::rts::actor::APickup::Type type,
    ::std::uint8_t value
)
    : AActor(filenameSprite, value)
    , APickup(filenameSound, type)
{
}

::rts::actor::APickupActor::~APickupActor() = default;
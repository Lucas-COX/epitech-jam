#include <pch.hpp>
#include <Actor/APickup.hpp>

::rts::actor::APickup::APickup(const std::string& filenameSound, ::rts::actor::APickup::Type type)
    : m_type(type)
    , m_value(0)
    , m_sound(filenameSound)
{
}

::rts::actor::APickup::~APickup() = default;

auto ::rts::actor::APickup::getPickupType()
    -> ::rts::actor::APickup::Type
{
    return m_type;
}

void ::rts::actor::APickup::setPickupType(::rts::actor::APickup::Type type)
{
    m_type = type;
}

auto ::rts::actor::APickup::getPickupValue()
    -> ::std::uint8_t
{
    return m_value;
}

void ::rts::actor::APickup::setPickupValue(::std::uint8_t pickup)
{
    m_value = pickup;
}

void ::rts::actor::APickup::playSound() const
{
    m_sound.play();
}

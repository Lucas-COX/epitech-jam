#include <pch.hpp>
#include <Object/Pickup/Book.hpp>

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// *structors
//
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
::rts::object::pickup::Book::Book(uint8_t lane)
    : ::rts::actor::APickupActor { "book.png", "burgerman.wav", rts::actor::APickup::eChanger, 1, lane }
{
    this->setPickupValue(5);
}

///////////////////////////////////////////////////////////////////////////
::rts::object::pickup::Book::~Book() = default;

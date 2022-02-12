#include <pch.hpp>
#include <Actor/ABar.hpp>



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// *structors
//
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
::rts::actor::ABar::ABar(
    const ::std::string& filename
)
    : ::rts::actor::AUi{ filename }
{}

///////////////////////////////////////////////////////////////////////////
::rts::actor::ABar::~ABar() = default;



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// Actions
//
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
void ::rts::actor::ABar::update(
    ::rts::Time deltaTime,
    const ::rts::actor::Movable& movable
)
{
    ::rts::actor::Drawable::update(deltaTime, movable);
}

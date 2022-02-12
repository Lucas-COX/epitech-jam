#include <pch.hpp>
#include <Actor/Bar.hpp>



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// *structors
//
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
::rts::actor::Bar::Bar(
    const ::std::string& filename
)
    : ::rts::actor::AUi{ filename }
{}

///////////////////////////////////////////////////////////////////////////
::rts::actor::Bar::~Bar() = default;
#include <pch.hpp>
#include <Object/Background.hpp>



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// *structors
//
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
::rts::object::Background::Background(
    const ::std::string& filename
)
    : ::rts::actor::AUi{ filename }
{}

///////////////////////////////////////////////////////////////////////////
::rts::object::Background::~Background() = default;

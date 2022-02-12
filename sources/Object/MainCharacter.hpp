#pragma once

#include <Actor/AActor.hpp>



namespace rts::object {



class MainCharacter
    : public ::rts::actor::AActor
{

public:

    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////
    // *structors
    //
    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Constructor
    ///
    ///////////////////////////////////////////////////////////////////////////
    explicit MainCharacter(
        const ::std::string& filename,
        uint8_t nmemb
    );

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Destructor
    ///
    ///////////////////////////////////////////////////////////////////////////
    ~MainCharacter();



private:

};



} // namespace rts::object

#pragma once

#include <Actor/AUi.hpp>



namespace rts::actor {



class ABar
    : public ::rts::actor::AUi
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
    explicit ABar(
        const ::std::string& filename
    );

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Destructor
    ///
    ///////////////////////////////////////////////////////////////////////////
    virtual ~ABar() = 0;



    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////
    // Actions
    //
    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Constructor
    ///
    ///////////////////////////////////////////////////////////////////////////
    void update(
        ::rts::Time deltaTime,
        const ::rts::actor::Movable& movable
    ) override;



private:

    ::std::uint8_t value; // value as percentage

};



} // namespace rts::actor

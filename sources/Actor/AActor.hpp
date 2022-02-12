#pragma once

#include <Actor/Movable.hpp>
#include <Actor/Drawable.hpp>



namespace rts::actor {



class AActor
    : public ::rts::actor::Movable
    , public ::rts::actor::Drawable
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
    explicit AActor(
        const ::std::string& filename,
        uint8_t nmemb
    );

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Destructor
    ///
    ///////////////////////////////////////////////////////////////////////////
    virtual ~AActor() = 0;



    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////
    // Actions
    //
    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Draws the actor
    ///
    ///////////////////////////////////////////////////////////////////////////
    [[ nodiscard ]] auto onCollides(
        ::std::shared_ptr<::rts::actor::AActor> other
    ) -> bool;



private:

};



} // namespace rts::actor

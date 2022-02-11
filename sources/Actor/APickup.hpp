#pragma once

#include <Actor/AActor.hpp>



namespace rts {



class APickup {

public:

    enum Type : ::std::uint8_t {
        eChanger = 1,
        fChanger
    }



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
    explicit APickup();

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Destructor
    ///
    ///////////////////////////////////////////////////////////////////////////
    virtual ~APickup();



    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////
    // Getters
    //
    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Gets the pickup type
    ///
    ///////////////////////////////////////////////////////////////////////////
    auto getPickupType()
        -> APickup::Type

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Sets the pickup type
    //
    ///////////////////////////////////////////////////////////////////////////
    void setPickupType(
        APickup::Type pickup
    )

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Sets the pickup value
    ///
    /// Value describes how much it impacts the bars as percentage.
    ///
    ///////////////////////////////////////////////////////////////////////////
    auto getPickupValue()
        -> ::std::uint8_t

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Sets the pickup value
    ///
    /// Value describes how much it impacts the bars as percentage.
    ///
    ///////////////////////////////////////////////////////////////////////////
    void setPickupValue(
        ::std::uint8_t pickup
    )



private:

    APickup::Type m_type;
    ::std::uint8_t m_value;

};



} // namespace rts

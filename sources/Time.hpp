#pragma once

namespace rts {


///////////////////////////////////////////////////////////////////////////
/// \brief Representation of the time in the xrn Project.
/// \ingroup ecs
///
/// \include Time.hpp <Ecs/Time.hpp>
///
/// ::rts::Time structure's purpuse is to represent time and uniform
/// time manipulations accross the xrn Project.
/// Its usage is straight forward as it just contains a Time value, gettable
/// as seconds or milliseconds. By default, xrn projects manipulates
/// milliseconds.
/// This class is mostly used by ::rts::Clock
///
/// \see ::rts::Clock
///
///////////////////////////////////////////////////////////////////////////
class Time {

public:

    using Type = float;



public:

    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////
    // *structors
    //
    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Constructor from a Time::Type.
    ///
    /// Constructs a ::rts::Time containing a point in time.
    ///
    /// \param time Time in milliseconds
    ///
    ///////////////////////////////////////////////////////////////////////////
    Time(
        Time::Type time
    );

    ///////////////////////////////////////////////////////////////////////////
    /// \brief default destructor.
    ///
    ///////////////////////////////////////////////////////////////////////////
    ~Time();



    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////
    // Get
    //
    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Convertion to the type internally stored.
    ///
    /// Same as get().
    ///
    /// \see ::rts::Time::get()
    ///
    ///////////////////////////////////////////////////////////////////////////
    [[ nodiscard ]] operator Time::Type();

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Get the value as it's internally stored.
    ///
    /// \return Time in milliseconds
    ///
    ///////////////////////////////////////////////////////////////////////////
    [[ nodiscard ]] auto get() const
        -> Time::Type;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Get the value as seconds.
    ///
    /// \return Value as second as the internally stored type.
    ///
    ///////////////////////////////////////////////////////////////////////////
    [[ nodiscard ]] auto getAsSeconds() const
        -> Time::Type;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Get the value as milliseconds.
    ///
    /// \return Value as second as the internally stored type.
    ///
    ///////////////////////////////////////////////////////////////////////////
    [[ nodiscard ]] auto getAsMilliseconds() const
        -> Time::Type;



    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////
    // Modificartions
    //
    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Adds time given as parameter.
    ///
    ///////////////////////////////////////////////////////////////////////////
    [[ nodiscard ]] auto operator+=(
        const ::rts::Time& rhs
    ) -> ::rts::Time&;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Adds time given as parameter.
    ///
    /// \param rhs Time in milliseconds
    ///
    ///////////////////////////////////////////////////////////////////////////
    [[ nodiscard ]] auto operator+=(
        const Time::Type& rhs
    ) -> Time&;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Convertion to the type internally stored.
    ///
    ///////////////////////////////////////////////////////////////////////////
    void set(
        const ::rts::Time& time
    );

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Convertion to the type internally stored.
    ///
    ///////////////////////////////////////////////////////////////////////////
    void set(
        const Time::Type& time
    );

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Convertion to the type internally stored.
    ///
    ///////////////////////////////////////////////////////////////////////////
    [[ nodiscard ]] auto operator+(
        const ::rts::Time& rhs
    ) const
        -> ::rts::Time&;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Convertion to the type internally stored.
    ///
    ///////////////////////////////////////////////////////////////////////////
    [[ nodiscard ]] auto operator+(
        const Time::Type& rhs
    ) const
        -> Time&;


private:

    Time::Type m_time;

};



} // namespace rts

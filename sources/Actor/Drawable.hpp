#pragma once

#include <Time.hpp>

namespace rts::actor { class Movable; }
namespace rts { class Window; }



namespace rts::actor {



class Drawable {

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
    explicit Drawable(
        const ::std::string& filename,
        uint8_t nmemb = 0,
        uint16_t rate = 300
    );

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Destructor
    ///
    ///////////////////////////////////////////////////////////////////////////
    ~Drawable();



    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////
    // Move sementics
    //
    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Constructor
    ///
    ///////////////////////////////////////////////////////////////////////////
    Drawable(
        ::rts::actor::Drawable&& other
    ) noexcept;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Destructor
    ///
    ///////////////////////////////////////////////////////////////////////////
    auto operator=(
        ::rts::actor::Drawable&& other
    ) noexcept
        -> ::rts::actor::Drawable&;



    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////
    // Getters/Setters
    //
    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Updates the sprite size, rotation, scale and animation relative
    ///  and position
    ///
    ///////////////////////////////////////////////////////////////////////////
    virtual void update(
        ::rts::Time deltaTime,
        const ::rts::actor::Movable& movable
    );

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Draws the sprite
    ///
    ///////////////////////////////////////////////////////////////////////////
    virtual void draw(
        ::rts::Window& window
    ) const;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Sets the texture rect
    ///
    ///////////////////////////////////////////////////////////////////////////
    void setTextureRect(
        const sf::Rect<int>& rect
    );

    ///////////////////////////////////////////////////////////////////////////
    /// \brief computes animation offset depending of file size
    ///
    ///////////////////////////////////////////////////////////////////////////
    unsigned int computeOffset(const std::string &filename, uint8_t nmemb);

    ///////////////////////////////////////////////////////////////////////////
    /// \brief sets animation refresh rate
    ///
    ///////////////////////////////////////////////////////////////////////////
    void setRefreshRate(uint16_t rate);

    ///////////////////////////////////////////////////////////////////////////
    /// \brief sets image scale
    ///
    ///////////////////////////////////////////////////////////////////////////
    [[ nodiscard ]] auto getScale() const
        -> float;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief sets image scale
    ///
    ///////////////////////////////////////////////////////////////////////////
    void setScale(float scale);

    ///////////////////////////////////////////////////////////////////////////
    /// \brief sets image scale
    ///
    ///////////////////////////////////////////////////////////////////////////
    [[ nodiscard ]] auto getSprite()
        -> ::sf::Sprite&;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief sets image rotation angle
    ///
    ///////////////////////////////////////////////////////////////////////////
    [[nodiscard]] auto getRotation() const
        -> float;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief sets image rotation angle
    ///
    ///////////////////////////////////////////////////////////////////////////
    void setRotation(float angle);

protected:

    ::sf::Sprite m_sprite;
    ::sf::Texture m_texture;
    unsigned int m_offset;
    ::std::uint8_t m_nmemb;
    ::std::uint8_t m_index;
    ::std::uint16_t m_rate;
    float m_lastCall;
};



} // namespace rts::actor

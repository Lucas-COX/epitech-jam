#pragma once

namespace rts::actor { class Movable; }



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
    explicit Drawable();

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Destructor
    ///
    ///////////////////////////////////////////////////////////////////////////
    ~Drawable();



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
    void update(
        ::rts::Time deltaTime,
    );

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Updates the sprite size, rotation and scale and position
    ///
    ///////////////////////////////////////////////////////////////////////////
    void updateSprite(
        ::rts::Time deltaTime,
        ::rts::actor::Movable movable
    );

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Updates the sprite animation relative to the time
    ///
    ///////////////////////////////////////////////////////////////////////////
    void updateAnimation(
        ::rts::Time deltaTime
    );

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Draws the sprite
    ///
    ///////////////////////////////////////////////////////////////////////////
    void draw() const;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Sets the texture rect
    ///
    ///////////////////////////////////////////////////////////////////////////
    void setTextureRect(
        const sf::Rect<int>& rect
    );




private:

    ::sf::Sprite m_sprite;
    ::sf::Texture m_texture;

};



} // namespace rts::actor
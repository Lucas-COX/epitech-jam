#include <pch.hpp>
#include <Window.hpp>
#include <Actor/Drawable.hpp>
#include <Actor/Movable.hpp>



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// *structors
//
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
::rts::actor::Drawable::Drawable(
    const ::std::string& filename
)
{
    if (!m_texture.loadFromFile("./data/sprites/" + filename)) {
        throw ::std::runtime_error{ "texture failed to load" };
    }
    m_sprite.setTexture(m_texture);
}

///////////////////////////////////////////////////////////////////////////
::rts::actor::Drawable::~Drawable() = default;



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// Move sementics
//
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
::rts::actor::Drawable::Drawable(
    ::rts::actor::Drawable&& other
) noexcept
{
    m_texture = ::std::move(other.m_texture);
    m_sprite = ::std::move(other.m_sprite);
    m_sprite.setTexture(m_texture);
}

///////////////////////////////////////////////////////////////////////////
auto ::rts::actor::Drawable::operator=(
    ::rts::actor::Drawable&& other
) noexcept -> ::rts::actor::Drawable&
{
    m_texture = ::std::move(other.m_texture);
    m_sprite = ::std::move(other.m_sprite);
    m_sprite.setTexture(m_texture);
    return *this;
}



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// Getters/setters
//
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
void ::rts::actor::Drawable::update(
    ::rts::Time deltaTime,
    const ::rts::actor::Movable& movable
)
{
    // sprite
    m_sprite.setPosition(movable.getPosition());
    // m_sprite.setScale(movable.getScale()); // TODO scane

    // animation
}

///////////////////////////////////////////////////////////////////////////
void ::rts::actor::Drawable::draw(
    ::rts::Window& window
) const
{
    window.draw(m_sprite);
}

///////////////////////////////////////////////////////////////////////////
void ::rts::actor::Drawable::setTextureRect(
    const sf::Rect<int>& rect
)
{

}

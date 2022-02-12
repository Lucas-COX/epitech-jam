#include <pch.hpp>
#include <Window.hpp>
#include <Actor/Drawable.hpp>
#include <Actor/Movable.hpp>
#include <arpa/inet.h>
#include <Scene.hpp>


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// *structors
//
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
::rts::actor::Drawable::Drawable(
    const ::std::string& filename,
    uint8_t nmemb,
    uint16_t rate
)
{
    if (!m_texture.loadFromFile("./data/sprites/" + filename)) {
        throw ::std::runtime_error{ "texture failed to load" };
    }
    m_sprite.setTexture(m_texture);
    m_nmemb = nmemb;
    m_rate = rate;
    m_lastCall = 0.0f;
    if (nmemb > 0) {
        m_offset = this->computeOffset(filename, nmemb);
        m_sprite.setTextureRect(::sf::IntRect{
                0,
                0,
                static_cast<int>(m_offset),
                static_cast<int>(m_sprite.getLocalBounds().height)
            });
    }
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
    ::rts::Time elapsed = (deltaTime - m_lastCall);
    // sprite
    m_sprite.setPosition(movable.getPosition());

    if (elapsed >= m_rate && m_nmemb > 1) {
        unsigned int tmp = m_sprite.getTextureRect().left + m_offset;
        unsigned int left = tmp >= m_texture.getSize().x ? 0 : tmp;
        m_sprite.setTextureRect({
            static_cast<int>(left),
            0,
            static_cast<int>(m_offset),
            static_cast<int>(m_sprite.getLocalBounds().height)
        });
        m_lastCall = deltaTime;
    }
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
    m_sprite.setTextureRect(rect);
}

unsigned int ::rts::actor::Drawable::computeOffset(const std::string& filename, const uint8_t nmemb)
{
    auto width{ m_sprite.getLocalBounds().width };
    return nmemb == 0 ? width : width / nmemb;
}

void ::rts::actor::Drawable::setRefreshRate(uint16_t rate)
{
    m_rate = rate;
}

auto ::rts::actor::Drawable::getScale() const
    -> float
{
    return m_sprite.getScale().x;
}

void ::rts::actor::Drawable::setScale(float scale)
{
    m_sprite.setScale(scale, scale);
}

auto ::rts::actor::Drawable::getSprite()
    -> ::sf::Sprite&
{
    return m_sprite;
}

auto ::rts::actor::Drawable::getRotation() const
    -> float
{
    return m_sprite.getRotation();
}

void ::rts::actor::Drawable::setRotation(float angle)
{
    m_sprite.setRotation(angle);
}

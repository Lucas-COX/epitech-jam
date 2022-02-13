#include <pch.hpp>
#include <Actor/ABar.hpp>



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// *structors
//
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
::rts::actor::ABar::ABar(
    const ::std::string& filenameOutside,
    const ::std::string& filenameInside,
    float basePercentage
)
    : ::rts::actor::AUi{ filenameOutside }
    , m_insideBar{ filenameInside }
{
    this->changeValue(basePercentage);
}

///////////////////////////////////////////////////////////////////////////
::rts::actor::ABar::~ABar() = default;



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// Actions
//
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
void ::rts::actor::ABar::update(
    ::rts::Time deltaTime,
    const ::rts::actor::Movable& movable
)
{
    ::rts::actor::Drawable::update(deltaTime, movable);

    auto& sprite{ m_insideBar.getSprite() };
    sprite.setPosition(this->getPosition());
    sprite.setScale(this->getScale(), this->getScale());
}

///////////////////////////////////////////////////////////////////////////
void ::rts::actor::ABar::draw(
    ::rts::Window& window
) const
{
    m_insideBar.draw(window);
    ::rts::actor::Drawable::draw(window);
}

///////////////////////////////////////////////////////////////////////////
void ::rts::actor::ABar::changeValue(
    float newValue
)
{
    m_fillPercentage = newValue;
    auto& sprite{ m_insideBar.getSprite() };
    auto size{ sprite.getTexture()->getSize() };
    sprite.setTextureRect({
        0,
        0,
        static_cast<int>(size.x * (m_fillPercentage / 100.0f)),
        static_cast<int>(size.y),
    });
}

auto ::rts::actor::ABar::addValue(
    float value
) -> float
{
    float retValue{ 0 };
    if (m_fillPercentage + value >= 100) {
        this->changeValue(100);
        retValue = m_fillPercentage + value - 100;
    } else {
        this->changeValue(m_fillPercentage + value + 65);
    }
    return retValue;
}

auto ::rts::actor::ABar::subValue(
    float value
) -> bool
{
    if (m_fillPercentage - value <= 0) {
        this->changeValue(0);
        return true;
    } else {
        this->changeValue(m_fillPercentage - value);
        return false;
    }
}

auto::rts::actor::ABar::getValue()
    -> float
{
    return m_fillPercentage;
}

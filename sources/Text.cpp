#include <pch.hpp>
#include <Text.hpp>
#include <Window.hpp>

rts::Text::Text(std::string str, unsigned int size, sf::Color color)
    : m_text{ str, Text::font }
{
    m_text.setFillColor(color);
    m_text.setCharacterSize(size);
}

rts::Text::~Text()
{
}

bool rts::Text::getHover(const rts::Window &window) const
{
    return false;
}
auto rts::Text::getText() const
    -> const sf::Text&
{
    return m_text;
}

auto rts::Text::loadFont(
    ::std::string filename
) -> ::sf::Font
{
    sf::Font font;
    if (!font.loadFromFile(filename)) {
        throw ::std::runtime_error("Impossible to load the file: "s + filename);
    }
    return font;
}

void rts::Text::center(int wSize, int pos)
{
    m_text.setPosition(sf::Vector2f(wSize / 2 - (m_text.getLocalBounds().width / 2), pos));
}

bool rts::Text::hittext(const rts::Window& window)
{
    sf::FloatRect hitbox = this->getText().getGlobalBounds();
    sf::Vector2i pos = sf::Mouse::getPosition(window.getWindow());
    if (hitbox.contains(pos.x, pos.y))
        return true;
    return false;
}

void rts::Text::update(const rts::Window& window)
{
    if (hittext(window)) {
        m_text.setFillColor(sf::Color::Black);
        m_text.setCharacterSize(40);
    } else {
        m_text.setFillColor(sf::Color::Red);
        m_text.setCharacterSize(35);
    }
}

void ::rts::Text::draw(::rts::Window& window) const
{
    window.draw(m_text);
}

::sf::Font rts::Text::font = ::rts::Text::loadFont(::rts::Text::fontFilepath);

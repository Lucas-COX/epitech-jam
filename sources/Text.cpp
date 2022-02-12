#include <pch.hpp>
#include <Text.hpp>

rts::Text::Text(std::string str, unsigned int size, sf::Color color)
{
    m_text.setString(str);
    m_text.setFillColor(color);
    m_text.setCharacterSize(size);
    // start.setPosition(sf::Vector2f(size.x / 2 - (start.getLocalBounds().width / 2), 200));
    // todo center method that does the above computing
}

rts::Text::~Text()
{
}

bool rts::Text::getHover(const sf::RenderWindow &window) const
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
    if (font.loadFromFile(filename)) {
        throw ::std::runtime_error("Impossible to load the file: "s + filename);
    }
    return font;
}

::sf::Font rts::Text::font = ::rts::Text::loadFont(::rts::Text::fontFilepath);

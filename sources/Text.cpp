/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** Text
*/

#include "Text.hpp"

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

void rts::Text::loadFont(::std::string filename)
{
    rts::Text::font.loadFromFile("data/hotpizza.ttf");
}
#include <pch.hpp>
#include <Text.hpp>
#include <Window.hpp>

rts::Text::Text(std::string str, unsigned int size, sf::Color color)
{
    m_text.setString(str);
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

bool rts::Text::hittext(const sf::RenderWindow& window, sf::Text& text)
{
    sf::FloatRect hitbox = text.getGlobalBounds();
    sf::Vector2i pos = sf::Mouse::getPosition(window);
    if (hitbox.contains(pos.x, pos.y)) {
        printf("pos.x = %d, pos.y = %d\n", pos.x, pos.y);
        printf("float Rect = %f, %f, %f, %f\n", hitbox.width, hitbox.height, hitbox.left, hitbox.top);
        printf("size text = %f, %f\n", text.getLocalBounds().width, text.getLocalBounds().height);
        printf("position text = %f, %f\n", text.getPosition().x, text.getPosition().y);
        return true;
    }
    return false;
}

void rts::Text::update(const rts::Window& window) const
{
    sf::FloatRect hitbox = this->getText().getGlobalBounds();
    sf::Vector2i pos = sf::Mouse::getPosition(window.getWindow());
    if (hitbox.contains(pos.x, pos.y)) {
        printf("pos.x = %d, pos.y = %d\n", pos.x, pos.y);
        printf("float Rect = %f, %f, %f, %f\n", hitbox.width, hitbox.height, hitbox.left, hitbox.top);
        printf("size text = %f, %f\n", m_text.getLocalBounds().width, m_text.getLocalBounds().height);
        printf("position text = %f, %f\n", m_text.getPosition().x, m_text.getPosition().y);
    }
}

::sf::Font ::rts::Text::font = ::rts::Text::loadFont(::rts::Text::fontFilepath);

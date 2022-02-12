#include <pch.hpp>
#include <Menu/Menu.hpp>

rts::Menu::Menu(::rts::Window& window)
    : m_window(window)
{
    m_background_T.loadFromFile("../../data/Background.jpg");
    m_background.setTexture(m_background_T);
    m_texts.emplace_back("Mon texte", 5, sf::Color::Red);
    m_texts.emplace_back("Mon texte", 5, sf::Color::Red);
    m_texts.emplace_back("Mon texte", 5, sf::Color::Red);
}

rts::Menu::~Menu()
{}

void rts::Menu::draw() const
{
}

void rts::Menu::update()
{
}

bool rts::Menu::run()
{
    return true;
}

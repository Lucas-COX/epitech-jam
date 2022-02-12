#include <pch.hpp>
#include <Menu/Menu.hpp>

rts::Menu::Menu(::rts::Window& window)
    : m_window(window)
{
    m_background_T.loadFromFile("./data/Background.jpg");
    m_background.setTexture(m_background_T);
    m_background.scale(3, 3);
    m_texts.emplace_back("Start", 35, sf::Color::Red);
    m_texts.back().center(window.getSize().x, 200);
    m_texts.emplace_back("Quit", 35, sf::Color::Red);
    m_texts.back().center(window.getSize().x, 400);
    m_texts.emplace_back("The purpose of learning is growth, and our minds, unlike our bodies, can continue growing as long as we live", 35, sf::Color::Red);
    m_texts.back().center(window.getSize().x, 600);
}

rts::Menu::~Menu()
{}

void rts::Menu::draw() const
{
    m_window.clear();
    m_window.draw(m_background);
    for (auto item : m_texts) {
        m_window.draw(item.getText());
    }
}

void rts::Menu::update()
{
    for (auto item : m_texts)
        item.update(m_window);
}

bool rts::Menu::run()
{
    while (m_window.isOpen()) {
        update();
        //handleEvent();
        draw();
        m_window.display();
    }
    return true;
}
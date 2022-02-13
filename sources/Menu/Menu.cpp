#include <pch.hpp>
#include <Menu/Menu.hpp>

rts::Menu::Menu(::rts::Window& window)
    : m_window(window)
{
    m_background_T.loadFromFile("./data/Background.jpg");
    m_background.setTexture(m_background_T);
    m_oogway_T.loadFromFile("./data/oogway.png");
    m_oogway.setTexture(m_oogway_T);
    m_oogway.setPosition(sf::Vector2f(window.getSize().x / 2 - (m_oogway.getLocalBounds().width / 2), 800));
    m_background.scale(3, 3);
    m_texts.emplace_back("Start", 35, sf::Color::Red);
    m_texts.back().center(window.getSize().x, 200);
    m_texts.emplace_back("Quit", 35, sf::Color::Red);
    m_texts.back().center(window.getSize().x, 400);
    const char* quotes[5] = { "Education is what survives when what has been learned has been forgotten.",
        "Education enables humans to achieve their fullest mental and physical potential in both personal and social life.",
        "Be a student as long as you still have something to learn, and this will mean all your life.",
        "Acquiring knowledge is the most fruitful effort.",
        "The purpose of learning is growth, and our minds, unlike our bodies, can continue growing as long as we live" };
    m_texts.emplace_back(quotes[rand() % 5], 35, sf::Color::Red);
    m_texts.back().center(window.getSize().x, 600);
}

rts::Menu::~Menu()
{}

void rts::Menu::draw() const
{
    m_window.clear();
    m_window.draw(m_background);
    m_window.draw(m_oogway);
    for (auto& item : m_texts) {
        item.draw(m_window);
    }
    m_window.display();
}

void rts::Menu::update()
{
    int i = 0;
    for (auto& item : m_texts) {
        if (i == 2)
            return;
        item.update(m_window);
        i++;
    }
}

rts::Menu::triState rts::Menu::handleEvent()
{
    sf::Event event;
    while (m_window.getWindow().pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            m_window.close();
        }

        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Escape)
                m_window.close();
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            if (m_texts[0].hittext(m_window))
                return TRUE;
            if (m_texts[1].hittext(m_window))
                return FALSE;
        }
    }
    return UNDIFINED;
}

bool rts::Menu::run()
{
    triState event;
    while (m_window.isOpen()) {
        update();
        event = handleEvent();
        if (event == FALSE)
            return false;
        if (event == TRUE)
            return true;
        draw();
    }
    return true;
}
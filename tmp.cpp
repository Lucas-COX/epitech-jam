/*
** EPITECH PROJECT, 2022
** epitech-jam
** File description:
** main
*/

#include <Menu/Menu.hpp>
#include <Text.hpp>

sf::Text Text::textCreate(std::string str, unsigned int size, sf::Color color)
{
    sf::Text text(str, font, size);
    text.setCharacterSize(size);
    text.setFillColor(color);
    return text;
}

bool hittext(sf::RenderWindow& window, sf::Text& text)
{
    sf::FloatRect hitbox = text.getGlobalBounds();
    sf::Vector2i pos = sf::Mouse::getPosition(window);
    if (hitbox.contains(pos.x, pos.y))
    {
        printf ("pos.x = %d, pos.y = %d\n", pos.x, pos.y);
        printf ("float Rect = %f, %f, %f, %f\n", hitbox.width, hitbox.height, hitbox.left, hitbox.top);
        printf ("size text = %f, %f\n", text.getLocalBounds().width, text.getLocalBounds().height);
        printf ("position text = %f, %f\n", text.getPosition().x, text.getPosition().y);
        return true;
    }
    return false;
}

rts::Menu::Menu(sf::RenderWindow& window)
    : m_window(window)
{
    m_texts.emplace_back("Mon texte", 5, sf::Color::Red);
}

rts::Menu::~Menu()
{
}

bool mouseClickInteract(Menu& menu, sf::Text& quit)
{
    if (hittext(menu.window, quit) == true) {
        menu.window.close();
        return true;
    }
    return false;
}

void mouseOver(Menu& menu)
{
    if (hittext(menu.window, menu.text.start) == true)
    {
        menu.text.start.setFillColor(sf::Color::Black);
    }
    else
        menu.text.start.setFillColor(sf::Color::Red);
    if (hittext(menu.window, menu.text.quit) == true)
    {
        menu.text.quit.setFillColor(sf::Color::Black);
    }
    else
        menu.text.quit.setFillColor(sf::Color::Red);
}

int main()
{
    Menu menu;

    while (menu.window.isOpen())
    {
        sf::Event event;
        while (menu.window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                printf("menu.window closed\n");
                menu.window.close();
            }

            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape)
                    menu.window.close();
            }

            mouseOver(menu);

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                if (mouseClickInteract(menu, menu.text.quit))
                    return 0;
            }
        }
        menu.window.draw(menu.background);
        menu.window.draw(menu.text.start);
        menu.window.draw(menu.text.quit);
        menu.window.draw(menu.text.quote);
        menu.window.display();
    }
    return EXIT_SUCCESS;
}
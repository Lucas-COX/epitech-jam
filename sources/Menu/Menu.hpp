/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** menu
*/

#ifndef MENU_HPP_
#define MENU_HPP_

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Text.hpp"

namespace rts {
    class Menu
    {
    public:
        Menu(sf::RenderWindow& window);
        ~Menu();

        void draw() const;
        void update();
        bool run();

    private:
        sf::RenderWindow &m_window;
        sf::Texture m_background_T;
        sf::Sprite m_background;
        ::std::vector<Text> m_texts;
    };
}

#endif /* !MENU_HPP_ */

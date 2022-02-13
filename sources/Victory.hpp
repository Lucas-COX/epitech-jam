/*
** EPITECH PROJECT, 2022
** epitech-jam
** File description:
** Victory
*/

#ifndef VICTORY_HPP_
#define VICTORY_HPP_

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Actor/Drawable.hpp"
#include <Text.hpp>
#include <Window.hpp>

namespace rts {
    class Henric : public ::rts::actor::Drawable {
        Henric()
            : ::rts::actor::Drawable("./data/sprites/henric.png")
        {
        }
        ~Henric();
    };

    class Victory {
        public:
            Victory(::rts::Window& window);
            ~Victory();

            void draw() const;
            void update();
            bool run();

        private:
            ::rts::Window& v_window;
            ::sf::Texture v_background_T;
            ::sf::Sprite v_background;
            ::std::vector<Text> v_texts;
            bool handleEvent();
            Henric henric;
    };
}
#endif /* !VICTORY_HPP_ */

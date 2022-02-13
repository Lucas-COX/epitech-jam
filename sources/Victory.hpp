/*
** EPITECH PROJECT, 2022
** epitech-jam
** File description:
** Victory
*/

#ifndef VICTORY_HPP_
#define VICTORY_HPP_

#include <Clock.hpp>
#include <Actor/Drawable.hpp>
#include <Actor/Movable.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <Sound/Music.hpp>
#include <Sound/Sound.hpp>
#include <Text.hpp>
#include <Window.hpp>

namespace rts {
    class Henric : public ::rts::actor::Drawable, public ::rts::actor::Movable {
        public:
            Henric()
                : ::rts::actor::Drawable("henric.png", 3, 75),
                ::rts::actor::Movable()
            {
            }
            ~Henric() {};
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
            ::rts::Clock v_clock;
            ::rts::sound::Music aura;
            ::rts::sound::Sound auraStart;
    };
}
#endif /* !VICTORY_HPP_ */

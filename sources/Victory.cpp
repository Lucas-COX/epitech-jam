/*
** EPITECH PROJECT, 2022
** epitech-jam
** File description:
** Victory
*/

#include <pch.hpp>
#include "Victory.hpp"

rts::Victory::Victory(::rts::Window& window)
    : v_window(window), henric(), aura("auraLoop.wav"), auraStart("auraStart.wav")
{
    v_background_T.loadFromFile("./data/epitech.jpg");
    v_background.setTexture(v_background_T);
    v_background.scale(0.6, 0.5);
    v_texts.emplace_back("Victory Royale", 69, sf::Color::Red);
    v_texts.back().center(window.getSize().x + 800, 400);
    v_texts.emplace_back("Thanks for playing!", 35, sf::Color::Red);
    v_texts.back().center(window.getSize().x + 800, 600);
    v_texts.emplace_back("Press space to go back to the menu", 35, sf::Color::Red);
    v_texts.back().center(window.getSize().x + 800, 800);
}

rts::Victory::~Victory()
{
}

void rts::Victory::draw() const
{
    v_window.clear();
    v_window.draw(v_background);
    for (auto& item : v_texts) {
        item.draw(v_window);
    }
    henric.draw(v_window);
    v_window.display();
}

void rts::Victory::update()
{
    henric.update(v_clock.getElapsed(), henric);
}

bool rts::Victory::handleEvent()
{
    sf::Event event;
    while (v_window.getWindow().pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            v_window.close();
            return false;
        }

        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Escape) {
                v_window.close();
                return false;
            }
            if (event.key.code == sf::Keyboard::Space)
                return true;
        }
    }
    return false;
}

bool rts::Victory::run()
{
    aura.play();
    auraStart.play();
    while (v_window.isOpen()) {
        update();
        if (handleEvent())
            return true;
        draw();
    }
    return false;
}
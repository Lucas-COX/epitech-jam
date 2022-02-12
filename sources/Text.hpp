/*
** EPITECH PROJECT, 2022
** epitech-jam
** File description:
** Text
*/

#ifndef TEXT_HPP_
#define TEXT_HPP_

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

namespace rts {
class Text {
    public:
        Text(std::string str, unsigned int size, sf::Color color);
        ~Text();

        bool getHover(const sf::RenderWindow &window) const;

        [[ nodiscard ]] auto getText() const
            -> const sf::Text&;

        static auto loadFont(
            ::std::string filename
        ) -> sf::Font;

    public:
        static inline ::std::string fontFilepath{ "data/hotpizza.ttf" };

    private:
        static sf::Font font;
        sf::Text m_text;
};
} // namespace rts
#endif /* !TEXT_HPP_ */

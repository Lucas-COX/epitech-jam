/*
** EPITECH PROJECT, 2022
** epitech-jam
** File description:
** Text
*/

#ifndef TEXT_HPP_
#define TEXT_HPP_

#include <Window.hpp>

namespace rts {
class Text {
    public:
        ///////////////////////////////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////////////////////////////
        // *structors
        //
        ///////////////////////////////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////////////////////////////

        ///////////////////////////////////////////////////////////////////////////
        /// \brief Constructor
        ///
        ///////////////////////////////////////////////////////////////////////////
        Text(std::string str, unsigned int size, sf::Color color);

        ///////////////////////////////////////////////////////////////////////////
        /// \brief Destructor
        ///
        ///////////////////////////////////////////////////////////////////////////
        ~Text();

        ///////////////////////////////////////////////////////////////////////////
        /// \brief tells if text is hovered or not
        ///
        ///////////////////////////////////////////////////////////////////////////
        bool getHover(const rts::Window &window) const;

        ///////////////////////////////////////////////////////////////////////////
        /// \brief returns text
        ///
        ///////////////////////////////////////////////////////////////////////////
        [[ nodiscard ]] auto getText() const
            -> const sf::Text&;

        ///////////////////////////////////////////////////////////////////////////
        /// \brief loads global font
        ///
        ///////////////////////////////////////////////////////////////////////////
        static auto loadFont(
            ::std::string filename
        ) -> sf::Font;

        void center(int wSize, int pos);

        void update(const rts::Window& window);

        void draw(::rts::Window& window) const;

        bool hittext(const rts::Window& window);

        public : static inline ::std::string fontFilepath { "./data/hotpizza.ttf" };

    private:
        static sf::Font font;
        sf::Text m_text;
};
} // namespace rts
#endif /* !TEXT_HPP_ */

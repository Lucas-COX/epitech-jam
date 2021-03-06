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
#include <Sound/Music.hpp>
#include <Text.hpp>
#include <Window.hpp>

namespace rts {
    class Menu
    {
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
        Menu(::rts::Window & window);

        ///////////////////////////////////////////////////////////////////////////
        /// \brief Destructor
        ///
        ///////////////////////////////////////////////////////////////////////////
        ~Menu();

        ///////////////////////////////////////////////////////////////////////////
        /// \brief Draws buttons and background
        ///
        ///////////////////////////////////////////////////////////////////////////
        void draw() const;

        ///////////////////////////////////////////////////////////////////////////
        /// \brief Calls update method of each element
        ///
        ///////////////////////////////////////////////////////////////////////////
        void update();

        ///////////////////////////////////////////////////////////////////////////
        /// \brief Runs loop
        /// @return true if play, false if quit
        ///
        ///////////////////////////////////////////////////////////////////////////
        bool run();

    private:
        ::rts::Window &m_window;
        ::sf::Texture m_background_T;
        ::sf::Sprite m_background;
        ::sf::Texture m_oogway_T;
        ::sf::Sprite m_oogway;
        ::std::vector<Text> m_texts;
        ::rts::sound::Music monkeMusic;

        enum triState {
            UNDIFINED = -1,
            FALSE,
            TRUE
        };

        triState handleEvent();
    };
}

#endif /* !MENU_HPP_ */

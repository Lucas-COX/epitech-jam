#include <pch.hpp>
#include <Window.hpp>



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
::rts::Window::Window()
    : m_window{ ::sf::VideoMode::getDesktopMode(), "RoadToSuccess" }
{}

///////////////////////////////////////////////////////////////////////////
/// \brief Destructor
///
///////////////////////////////////////////////////////////////////////////
::rts::Window::~Window() = default;


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// Actions
//
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
/// \brief Draws the window buffer
///
///////////////////////////////////////////////////////////////////////////
void ::rts::Window::display()
{
    m_window.display();
}

///////////////////////////////////////////////////////////////////////////
/// \brief Clears the window buffer
//
///////////////////////////////////////////////////////////////////////////
void ::rts::Window::clear()
{
    m_window.clear();
}

///////////////////////////////////////////////////////////////////////////
/// \brief If the window should close
//
///////////////////////////////////////////////////////////////////////////
[[ nodiscard ]] auto ::rts::Window::isOpen()
    -> bool
{
    return m_window.isOpen();
}

///////////////////////////////////////////////////////////////////////////
/// \brief Handles the events
//
///////////////////////////////////////////////////////////////////////////
void ::rts::Window::handleEvents(
    ::rts::Scene scene
)
{
    sf::Event event;
    while (m_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
    }
}

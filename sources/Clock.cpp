#include <pch.hpp>
#include <Clock.hpp>


// ------------------------------------------------------------------ *structors

::rts::Clock::Clock()
    : m_lastCallTime{ ::std::chrono::high_resolution_clock::now() }
{}

::rts::Clock::~Clock() = default;



// ------------------------------------------------------------------ Get

auto ::rts::Clock::getElapsed()
    -> Clock::Type
{
    return static_cast<Clock::Type::Type>(::std::chrono::duration<float>(
        ::std::chrono::high_resolution_clock::now() - m_lastCallTime
    ).count() * 1000.0f);
}

auto ::rts::Clock::getRestart()
    -> Clock::Type
{
    auto saveLastCallTime{ ::std::chrono::high_resolution_clock::now() };
    m_lastCallTime = ::std::chrono::high_resolution_clock::now();
    return static_cast<Clock::Type::Type>(::std::chrono::duration<float>(
        m_lastCallTime - saveLastCallTime
    ).count() * 1000.0f);
}

void ::rts::Clock::restart()
{
    m_lastCallTime = ::std::chrono::high_resolution_clock::now();
}

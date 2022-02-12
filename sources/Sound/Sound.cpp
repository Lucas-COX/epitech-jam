#include <pch.hpp>
#include <Sound/Sound.hpp>

rts::sound::Sound::Sound(const ::std::string &filepath)
    : ASound(createSound(filepath))
{
}

::std::unique_ptr<sf::Sound> rts::sound::Sound::createSound(::std::string filepath)
{
    if (!s_buffer.loadFromFile(filepath)) {
        throw ::std::runtime_error("Unable to open file");
    }
    auto sound = std::make_unique<sf::Sound>();
    sound->setBuffer(s_buffer);
    return sound;
}

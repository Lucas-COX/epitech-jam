#include <pch.hpp>
#include <Sound/Sound.hpp>

rts::sound::Sound::Sound(const ::std::string& filepath)
    : ASound(std::make_shared<sf::Sound>())
{
    if (!s_buffer.loadFromFile("./data/sounds/" + filepath)) {
        throw ::std::runtime_error("Unable to open file");
    }
    static_pointer_cast<sf::Sound>(s_source)->setBuffer(s_buffer);
    s_source->setVolume(100);
}

#include <pch.hpp>
#include <Sound/Music.hpp>

rts::sound::Music::Music(const ::std::string &filepath, bool loop)
    : ASound(createMusic(filepath, loop))
    , s_isLoop(loop)
{
}

::std::shared_ptr<sf::Music> rts::sound::Music::createMusic(::std::string filepath, bool isLoop)
{
    auto music = std::make_shared<sf::Music>();
    if (!music->openFromFile(filepath)) {
        throw ::std::runtime_error("Unable to open file");
    }
    music->setLoop(isLoop);
    return music;
}

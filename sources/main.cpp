#include <pch.hpp>
#include <Scene.hpp>
#include <Window.hpp>


int main(int argc, char **argv)
{
    try {
        ::rts::Window window;
        ::rts::scene::Game scene{ window };

        while (!scene.isOver()) {
            scene.update();
            scene.draw();
        }

        return EXIT_SUCCESS;
    } catch (const ::std::exception& e) {
        ::std::cerr << "ERROR: " << e.what() <<::std::endl;
        return EXIT_FAILURE;

    } catch (...) {
        ::std::cerr << "ERROR: unknown" <<::std::endl;
        return EXIT_FAILURE;

    }
}

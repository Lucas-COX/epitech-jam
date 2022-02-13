#include <pch.hpp>
#include <Scene.hpp>
#include <Window.hpp>
#include <Menu/Menu.hpp>


int main(int argc, char **argv)
{
    try {
        ::rts::Window window;

        if (!::rts::Menu{ window }.run()) {
            return EXIT_SUCCESS;
        }

        ::rts::Scene scene { window };

        while (!scene.isOver()) {
            if (!scene.update()) {
                // TODO: die screen
                break;
            }
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

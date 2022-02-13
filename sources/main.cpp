#include <pch.hpp>
#include <Scene.hpp>
#include <Window.hpp>
#include <Menu/Menu.hpp>
#include <Victory.hpp>


int main(int argc, char **argv)
{
    try {
        ::rts::Window window;

        if (!::rts::Menu{ window }.run()) {
            return EXIT_SUCCESS;
        }

        if (::rts::Victory{window}.run()) {
            return EXIT_SUCCESS;
        }

        ::rts::Scene scene { window };

        while (!scene.isOver()) {
            if (!scene.update()) {
                break;
            } else if (scene.hasWon()) {
                break;
            }

            ::rts::Scene scene { window };

            while (!scene.isOver()) {
                if (!scene.update()) {
                    break;
                }
                scene.draw();
            }

            if (scene.getEvolution() >= 100 && !::rts::Victory{window}.run()) {
                return EXIT_SUCCESS;
            }
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

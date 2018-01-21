//
// Created by chennetier on 14/01/18.
//

#ifndef R_TYPE_SFMLWINDOW_HPP
#define R_TYPE_SFMLWINDOW_HPP

#include <SFML/Graphics/RenderWindow.hpp>
#include <memory>

#include "../IWindow/IWindow.hpp"

namespace TacosEngine {

    class SfmlWindow : public IWindow {

    private:
        sf::RenderWindow *_window;
        VIDEO_MODE  _mode;

    public:
        SfmlWindow() {_mode = VIDEO_MODE::FULLSCREEN;
                        _window = nullptr;}
        ~SfmlWindow() override = default;

        void    InitWindow(std::string name, VIDEO_MODE mode) override;

        void    ScreenMode(VIDEO_MODE mode) override;

        void    Refresh() const override;

        void    DeleteWindow() const override;

    //getters and setters
    public:
        VIDEO_MODE get_mode() const;
        void set_mode(VIDEO_MODE _mode);
        sf::RenderWindow *get_window() const;
        void set_window(sf::RenderWindow *_window);


    };
}

#endif //R_TYPE_SFMLWINDOW_HPP

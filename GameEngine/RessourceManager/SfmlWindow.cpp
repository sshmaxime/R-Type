//
// Created by chennetier on 14/01/18.
//

#include "SfmlWindow.hpp"

void TacosEngine::SfmlWindow::InitWindow(std::string name, VIDEO_MODE mode) {

    // Problème de video mode avec fullscreen
    if (mode == VIDEO_MODE::FULLSCREEN)
        this->_window =
                new sf::RenderWindow(sf::VideoMode(800, 400), name, sf::Style::Fullscreen);
    else
        this->_window = new sf::RenderWindow(sf::VideoMode(800, 400), name);
}

void TacosEngine::SfmlWindow::ScreenMode(VIDEO_MODE mode) {
    this->_mode = mode;
}

void TacosEngine::SfmlWindow::Refresh() const {
    this->_window->clear();
}

void TacosEngine::SfmlWindow::DeleteWindow() const {
    _window->close();
}

TacosEngine::VIDEO_MODE TacosEngine::SfmlWindow::get_mode() const {
    return _mode;
}

void TacosEngine::SfmlWindow::set_mode(TacosEngine::VIDEO_MODE _mode) {
    SfmlWindow::_mode = _mode;
}

sf::RenderWindow *TacosEngine::SfmlWindow::get_window() const {
    return _window;
}

void TacosEngine::SfmlWindow::set_window(sf::RenderWindow *_window) {
    SfmlWindow::_window = _window;
}

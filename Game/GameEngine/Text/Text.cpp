//
// Created by Corentin on 24/01/2018.
//

#include "Text.hpp"


TacosEngine::Text::Text(const std::string &name, std::shared_ptr<TacosEngine::Scene> scene, TacosEngine::Layout layout,
                        TacosEngine::Tag tag, const std::string &text, Color color)
    : GameObject(name, scene, layout, tag), _text(text), _color(color)
{
}


TacosEngine::Vector2 &TacosEngine::Text::getSize() {
    return _size;
}

void TacosEngine::Text::setSize(const TacosEngine::Vector2 &size) {
    _size = size;
}

TacosEngine::IFont *TacosEngine::Text::getFont() const {
    return _font;
}

void TacosEngine::Text::setFont(TacosEngine::IFont *font) {
    _font = font;
}

const std::string &TacosEngine::Text::getText() const {
    return _text;
}

void TacosEngine::Text::setText(const std::string &text) {
    _text = text;
}

void TacosEngine::Text::setColor(TacosEngine::Color color) {
    _color = color;
}

const TacosEngine::Color &TacosEngine::Text::getColor() const {
    return _color;
}

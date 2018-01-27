//
// Created by Corentin on 24/01/2018.
//

#ifndef GAME_TEXT_HPP
#define GAME_TEXT_HPP


#include "../Scene/Scene.hpp"

namespace TacosEngine
{
    enum class Color : int
    {
        BLACK = 0,
        WHITE ,
        RED,
        GREEN,
        BLUE,
        YELLOW,
        MAGENTA,
        CYAN
    };

    class Text : public GameObject
    {
    public:
        Text(const std::string &name, std::shared_ptr<Scene> scene, Layout layout, Tag tag = Tag::UNKNOWN, const std::string &text = "", Color color = Color::BLACK);
        ~Text() override = default;
        Vector2     &getSize();
        void        setSize(const Vector2 &);
        IFont       *getFont() const;
        void        setFont(IFont *);
        const std::string &getText() const;
        void                setText(const std::string &);
        void                setColor(Color color);
        const Color         &getColor() const;

    private:
        Vector2                     _size;
        IFont					    *_font;
        std::string                 _text;
        Color                       _color;
    };

}

#endif //GAME_TEXT_HPP

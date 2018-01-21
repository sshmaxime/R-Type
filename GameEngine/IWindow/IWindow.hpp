//
// Created by chennetier on 14/01/18.
//

#ifndef R_TYPE_IWINDOW_HPP
#define R_TYPE_IWINDOW_HPP

#include<iostream>

namespace TacosEngine {

    enum class VIDEO_MODE {
        PARTIAL,
        FULLSCREEN,
    };

    class IWindow {

    public:
        virtual ~IWindow() = default;;

        virtual void InitWindow(std::string name, VIDEO_MODE mode) = 0;

        virtual void ScreenMode(VIDEO_MODE mode) = 0;

        virtual void Refresh() const = 0;

        virtual void DeleteWindow() const = 0;
    };
}

#endif //R_TYPE_IWINDOW_HPP

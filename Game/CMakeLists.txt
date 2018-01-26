cmake_minimum_required(VERSION 3.9)
project(Game)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)

# Set version information in a config.h file
set(myproject_VERSION_MAJOR 1)
set(myproject_VERSION_MINOR 0)

configure_file(
        "${PROJECT_SOURCE_DIR}/config.h.in"
        "${PROJECT_BINARY_DIR}/config.h"
)

include_directories("${PROJECT_BINARY_DIR}")

add_executable(Game
        GameEngine/Animation/Animation.cpp
        GameEngine/Animation/Animation.hpp
        GameEngine/AudioComponent/AudioComponent.cpp
        GameEngine/AudioComponent/AudioComponent.hpp
        GameEngine/Behaviour/Behaviour.cpp
        GameEngine/Behaviour/Behaviour.h
        GameEngine/cmake-build-debug/config.h
        GameEngine/Collider/Collider.cpp
        GameEngine/Collider/Collider.hpp
        GameEngine/Component/Component.cpp
        GameEngine/Entity/Entity.hpp
        GameEngine/GameObject/GameObject.cpp
        GameEngine/IEvent/IEvent.hpp
        GameEngine/Input/Input.cpp
        GameEngine/Input/Input.h
        GameEngine/InputManager/InputManager.h
        GameEngine/InputManagerSFML/InputManagerSFML.cpp
        GameEngine/InputManagerSFML/InputManagerSFML.h
        GameEngine/IRenderer/IRenderer.hpp
        GameEngine/IWindow/IWindow.hpp
        GameEngine/PhysicsEngine/PhysicsEngine.cpp
        GameEngine/PhysicsEngine/PhysicsEngine.h
        GameEngine/RessourceManager/IAudio.hpp
        GameEngine/RessourceManager/IFont.hpp
        GameEngine/RessourceManager/ITexture.hpp
        GameEngine/RessourceManager/RessourceManager.cpp
        GameEngine/RessourceManager/RessourceManager.hpp
        GameEngine/RessourceManager/sfmlAudio.cpp
        GameEngine/RessourceManager/sfmlAudio.hpp
        GameEngine/RessourceManager/sfmlFont.cpp
        GameEngine/RessourceManager/sfmlFont.hpp
        GameEngine/RessourceManager/sfmlTexture.cpp
        GameEngine/RessourceManager/sfmlTexture.hpp
        GameEngine/RessourceManager/SfmlWindow.cpp
        GameEngine/RessourceManager/SfmlWindow.hpp
        GameEngine/Rigidbody/Rigidbody.cpp
        GameEngine/Rigidbody/Rigidbody.hpp
        GameEngine/Scene/Scene.cpp
        GameEngine/Scene/Scene.hpp
        GameEngine/SfmlRenderer/SfmlRenderer.cpp
        GameEngine/SfmlRenderer/SfmlRenderer.hpp
        GameEngine/Sprite/Sprite.cpp
        GameEngine/Sprite/Sprite.hpp
        GameEngine/Transform/Transform.cpp
        GameEngine/Transform/Transform.h
        GameEngine/Vector2/Vector2.cpp
        GameEngine/Vector2/Vector2.hpp
        GameEngine/TacosEngine.cpp
        GameEngine/TacosEngine.h
        GameEngine/TestInput.h
        GameEngine/EventManager/EventManager.cpp
        GameEngine/EventManager/EventManager.hpp
        GameEngine/Text/Text.cpp
        GameEngine/Text/Text.hpp
        Level/Level.cpp
        Level/Level.hpp
        Core/Core.cpp
        Core/Core.hpp
        Entity/Entity.cpp
        Entity/Entity.hpp
        main.cpp)

# Detect and add SFML
if(NOT DEFINED     SFML_ROOT  AND
        NOT DEFINED ENV{SFML_ROOT})
    if(WIN32)
        set(SFML_ROOT "C:/dev/libs/SFML")
    endif()
endif()
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
#Find any version 2.X of SFML
#See the FindSFML.cmake file for additional details and instructions
find_package(SFML 2 REQUIRED audio graphics window system)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif()
    cmake_minimum_required(VERSION 3.9)
    project(GameEngine)

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

    add_executable(GameEngine
      Behaviour/Behaviour.cpp
      Behaviour/Behaviour.h
      Collider/Collider.cpp
      Collider/Collider.hpp
      Component/Component.cpp
            Entity/Entity.hpp
      Input/Input.cpp
      Input/Input.h
      InputManager/InputManager.h
      InputManagerSFML/InputManagerSFML.cpp
      InputManagerSFML/InputManagerSFML.h
      IRenderer/IRenderer.hpp
      IWindow/IWindow.hpp
      PhysicsEngine/PhysicsEngine.cpp
      PhysicsEngine/PhysicsEngine.h
      RessourceManager/IAudio.hpp
      RessourceManager/IFont.hpp
      RessourceManager/ITexture.hpp
      RessourceManager/RessourceManager.cpp
      RessourceManager/RessourceManager.hpp
      RessourceManager/sfmlAudio.cpp
      RessourceManager/sfmlAudio.hpp
      RessourceManager/sfmlFont.cpp
      RessourceManager/sfmlFont.hpp
      RessourceManager/SfmlRenderer.cpp
      RessourceManager/SfmlRenderer.hpp
      RessourceManager/sfmlTexture.cpp
      RessourceManager/sfmlTexture.hpp
      RessourceManager/SfmlWindow.cpp
      RessourceManager/SfmlWindow.hpp
      Scene/Scene.cpp
      Scene/Scene.hpp
      Sprite/Sprite.cpp
            Transform/Transform.cpp
      Transform/Transform.h
      Vector2/Vector2.cpp
      Vector2/Vector2.hpp
      r_type.cpp
      TacosEngine.cpp
      TacosEngine.h
      TestInput.h Animation/Animation.cpp Animation/Animation.hpp Rigidbody/Rigidbody.cpp Rigidbody/Rigidbody.hpp)

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

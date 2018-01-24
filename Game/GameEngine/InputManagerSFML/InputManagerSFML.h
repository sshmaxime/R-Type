#pragma once

#include <GameEngine/InputManager/InputManager.h>
#include <GameEngine/Input/Input.h>

namespace TacosEngine
{
  class InputManagerSFML : public InputManager
  {
   public:
    InputManagerSFML();
    ~InputManagerSFML() override;
    virtual void setProcessInput(Input &input);
  };
}
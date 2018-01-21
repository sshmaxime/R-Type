#pragma once

#include "../InputManager/InputManager.h"
#include "../Input/Input.h"

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
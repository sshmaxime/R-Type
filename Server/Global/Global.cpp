//
// Created by sshsupreme on 20/01/18.
//

#include "Global.h"

Global Global::m_instance = Global();

Global& Global::Instance()
{
    return m_instance;
}

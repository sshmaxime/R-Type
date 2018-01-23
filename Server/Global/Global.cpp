//
// Created by sshsupreme on 20/01/18.
//

#include "Global.h"

Global Global::m_instance = Global();

Global* Global::Instance()
{
    static Global instance;

    return &instance;
}

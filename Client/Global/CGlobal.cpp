//
// Created by sshsupreme on 27/01/18.
//

#include "CGlobal.h"

CGlobal CGlobal::m_instance = CGlobal();

CGlobal* CGlobal::Instance()
{
    static CGlobal instance;

    return &instance;
}

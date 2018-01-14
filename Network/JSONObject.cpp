//
// Created by sshsupreme on 13/01/18.
//

#include "JSONObject.h"

void                                JSONObject::BeautifulPrint()
{
    std::cout << _JSON.dump(2) << std::endl;
}
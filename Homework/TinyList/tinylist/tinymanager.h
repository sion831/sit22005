//
// Created by Changbeom Choi on 2017. 5. 9..
//

#ifndef SIT22005_TINYMANAGER_H
#define SIT22005_TINYMANAGER_H

#include "tinynode.h"

class tinymanager
{
public:
    tinymanager();
    virtual ~tinymanager();
private:
    tinynode* m_pHead;
};


#endif //SIT22005_TINYMANAGER_H

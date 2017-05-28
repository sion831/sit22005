//
// Created by Changbeom Choi on 2017. 5. 9..
//

#ifndef SIT22005_TINYNODE_H
#define SIT22005_TINYNODE_H

#include "tinylist_def.h"

class tinynode
{
public:
    tinynode();

private:
    int data;
    tinynode* m_pNext;
};


#endif //SIT22005_TINYNODE_H

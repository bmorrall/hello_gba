#ifndef HELLO_SCENE_H
#define HELLO_SCENE_H

#include "bn_optional.h"

namespace hello
{

    class scene
    {

    public:
        virtual ~scene() = default;

        virtual void update() = 0;

    protected:
        scene() = default;
    };

}

#endif

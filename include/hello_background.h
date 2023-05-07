/*
 * Copyright (c) 2020-2023 Gustavo Valiente gustavo.valiente@protonmail.com
 * zlib License, see LICENSE file.
 */

#ifndef HELLO_BACKGROUND_H
#define HELLO_BACKGROUND_H

#include "bn_sprite_actions.h"
#include "bn_regular_bg_actions.h"
#include "bn_bg_palette_color_hbe_ptr.h"

namespace hello
{

class background
{

public:
    background()
    {
        _set_visible();
    }

    void put_under_all();

    void update();

private:
    bn::optional<bn::regular_bg_move_by_action> _move_action;
    bn::optional<bn::bg_palette_color_hbe_ptr> _palette_hbe;

    void _set_visible();
};

}

#endif

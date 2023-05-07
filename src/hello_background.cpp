/*
 * Copyright (c) 2020-2023 Gustavo Valiente gustavo.valiente@protonmail.com
 * zlib License, see LICENSE file.
 */

#include "hello_background.h"

#include "bn_color.h"
#include "bn_window.h"
#include "bn_display.h"
#include "bn_sprite_builder.h"
#include "bn_regular_bg_items_butano_background.h"

namespace hello
{

namespace
{
    constexpr int show_hide_frames = 10;

    constexpr bn::array<bn::color, bn::display::height()> palette_hbe_colors = []{
        bn::array<bn::color, bn::display::height()> result;
        bn::color color(0, 0, 14);
        int redInc = 16;
        int greenInc = 16;
        int blueInc = 8;

        for(int index = 0; index < bn::display::height(); ++index)
        {
            result[index] = color;
            --redInc;
            --greenInc;
            --blueInc;

            if(! redInc)
            {
                color.set_red(color.red() + (index <= 80 ? 1 : -1));
                redInc = 16;
            }

            if(! greenInc)
            {
                color.set_green(bn::max(color.green() + (index <= 80 ? 1 : -1), 0));
                greenInc = 16;
            }

            if(! blueInc)
            {
                color.set_blue(bn::max(color.blue() + (index <= 80 ? 1 : -1), 0));
                blueInc = 16;
            }
        }

        return result;
    }();
}

void background::put_under_all()
{
    _set_visible();

    bn::regular_bg_ptr bg = _move_action->bg();
    bg.set_priority(3);
}

void background::update()
{
    if(_move_action)
    {
        _move_action->update();
    }
}

void background::_set_visible()
{
    if(! _move_action)
    {
        bn::regular_bg_ptr bg = bn::regular_bg_items::butano_background.create_bg(0, 0);
        _palette_hbe = bn::bg_palette_color_hbe_ptr::create(bg.palette(), 1, palette_hbe_colors);
        _move_action.emplace(bn::move(bg), 1, -1);
    }
}

}

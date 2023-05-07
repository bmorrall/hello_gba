#ifndef HELLO_INTRO_H
#define HELLO_INTRO_H

#include "bn_vector.h"
#include "bn_sprite_ptr.h"
#include "bn_blending_actions.h"
#include "bn_bg_palettes_actions.h"
#include "bn_sprite_palettes_actions.h"
#include "bn_sprite_text_generator.h"

#include "hello_scene.h"
#include "hello_background.h"

namespace bn
{
    class sprite_text_generator;
}

namespace hello
{

    class butano_background;

    class intro : public scene
    {

    public:
        intro(bn::sprite_text_generator &text_generator, hello::background &hello_background);

        void update() final;

    private:
        bn::bg_palettes_fade_to_action _bg_fade_action;
        bn::vector<bn::sprite_ptr, 32> _text_sprites;
    };

}

#endif

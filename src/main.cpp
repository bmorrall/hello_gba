#include "bn_core.h"
#include "bn_math.h"
#include "bn_keypad.h"
#include "bn_display.h"
#include "bn_sprite_ptr.h"
#include "bn_bg_palettes.h"
#include "bn_music_actions.h"
#include "bn_sprite_text_generator.h"

#include "bn_music_items.h"

#include "bn_sprite_items_variable_8x16_font_red.h"
#include "bn_sprite_items_variable_8x16_font_blue.h"
#include "bn_sprite_items_variable_8x16_font_yellow.h"

#include "common_variable_8x16_sprite_font.h"

#include "hello_background.h"

namespace
{
    constexpr bn::fixed text_y_inc = 14;
    constexpr bn::fixed text_y_limit = (bn::display::height() / 2) - text_y_inc;

    void text_hello_world()
    {
        hello::background hello_background;

        bn::sprite_text_generator text_generator(common::variable_8x16_sprite_font);
        text_generator.set_center_alignment();

        bn::vector<bn::sprite_ptr, 32> text_sprites;
        text_generator.generate(0, -text_y_limit, "Hello World!!!", text_sprites);
        text_generator.generate(0, text_y_limit, "github.com/bmorrall", text_sprites);

        hello_background.put_under_all();

        while(! bn::keypad::start_pressed())
        {
            hello_background.update();
            bn::core::update();
        }
    }
}

int main()
{
    bn::core::init();

    bn::bg_palettes::set_transparent_color(bn::color(16, 16, 16));

    if(! bn::music::playing())
    {
        bn::music_items::crushing_enemies.play(0.6);
    }

    while(true)
    {
        text_hello_world();
        bn::core::update();
    }
}

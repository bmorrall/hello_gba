#include "bn_core.h"
#include "bn_unique_ptr.h"
#include "bn_math.h"
#include "bn_keypad.h"
#include "bn_color.h"
#include "bn_sprite_ptr.h"
#include "bn_bg_palettes.h"
#include "bn_music_actions.h"

#include "bn_music_items.h"
#include "bn_sprite_text_generator.h"

#include "bn_sprite_items_variable_8x16_font_red.h"
#include "bn_sprite_items_variable_8x16_font_blue.h"
#include "bn_sprite_items_variable_8x16_font_yellow.h"

#include "common_variable_8x16_sprite_font.h"

#include "hello_background.h"
#include "hello_intro.h"

namespace
{

	void text_hello_world(hello::background &hello_background)
	{
		bn::sprite_text_generator text_generator(common::variable_8x16_sprite_font);

		bn::unique_ptr<hello::scene> scene(new hello::intro(text_generator, hello_background));

		while (!bn::keypad::start_pressed())
		{
			scene->update();
			hello_background.update();
			bn::core::update();
		}

		scene.reset();
	}

}

int main()
{
	bn::core::init();

	hello::background hello_background;

	if (!bn::music::playing())
	{
		bn::music_items::crushing_enemies.play(0.6);
	}

	while (true)
	{
		text_hello_world(hello_background);
		hello_background.update();
		bn::core::update();
	}
}

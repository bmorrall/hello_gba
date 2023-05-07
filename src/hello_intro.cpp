#include "hello_intro.h"

#include "bn_display.h"
#include "bn_color.h"
#include "bn_colors.h"

namespace hello
{

	namespace
	{
		constexpr bn::fixed text_y_inc = 14;
		constexpr bn::fixed text_y_limit = (bn::display::height() / 2) - text_y_inc;

		[[nodiscard]] bn::bg_palettes_fade_to_action _create_bg_fade_action()
		{
			bn::bg_palettes::set_fade(bn::colors::black, 1);
			return bn::bg_palettes_fade_to_action(60, 0);
		}
	}

	intro::intro(bn::sprite_text_generator &text_generator, hello::background &hello_background) : _bg_fade_action(_create_bg_fade_action())
	{
		bn::bg_palettes::set_transparent_color(bn::color(16, 16, 16));

		// Display Hello World!!!
		text_generator.set_center_alignment();
		text_generator.generate(0, -text_y_limit, "Hello World!!!", _text_sprites);
		text_generator.generate(0, text_y_limit, "github.com/bmorrall/hello_gba", _text_sprites);

		// Move the background to the buttom of the render pile
		hello_background.put_under_all();
	}

	void intro::update()
	{
		if (!_bg_fade_action.done())
		{
			// Fade the screen in
			_bg_fade_action.update();
		}
	}

}

/*
** mrb_ssd1306.c - Ssd1306 class
**
** Copyright (c) Jun Takeda 2016
**
** See Copyright Notice in LICENSE
*/

#include "mruby.h"
#include "mruby/data.h"
#include "mruby/string.h"
#include "mrb_ssd1306.h"

#include "Wire.h"
#include "Adafruit-GFX-Library/Adafruit_GFX.h"
#include "Adafruit-GFX-Library/Fonts/acknow7pt.h"
#include "Adafruit-GFX-Library/Fonts/pixel_dingbats.h"
#include "Adafruit_SSD1306/Adafruit_SSD1306.h"

#define RB_PIN18	18
#define RB_PIN19	19

// OLED
#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

#define DONE mrb_gc_arena_restore(mrb, 0);

mrb_value mrb_gfx_begin(mrb_state *mrb, mrb_value self)
{
	int i2c_addr;

	mrb_get_args(mrb, "i", &i2c_addr);
	pinMode(RB_PIN18, OUTPUT);
	pinMode(RB_PIN19, OUTPUT);
	display.begin(SSD1306_SWITCHCAPVCC, i2c_addr);
	display.setTextColor(WHITE);
	display.setFont(&acknowtt7pt7b);

	return mrb_nil_value();
}

mrb_value mrb_gfx_display(mrb_state *mrb, mrb_value self)
{
	display.display();
	return mrb_nil_value();
}

mrb_value mrb_gfx_clearDisplay(mrb_state *mrb, mrb_value self)
{
	display.clearDisplay();
	return mrb_nil_value();
}

mrb_value mrb_gfx_setCursor(mrb_state *mrb, mrb_value self)
{
	int x, y;
	mrb_get_args(mrb, "ii", &x, &y);

	display.setCursor(x, y);
	return mrb_nil_value();
}

mrb_value mrb_gfx_drawLine(mrb_state *mrb, mrb_value self)
{
	int x1, y1, x2, y2;
	mrb_get_args(mrb, "iiii", &x1, &y1, &x2, &y2);

	display.drawLine(x1, y1, x2 , y2, WHITE);
	return mrb_nil_value();
}

mrb_value mrb_gfx_setTextSize(mrb_state *mrb, mrb_value self)
{
	int size;
	mrb_get_args(mrb, "i", &size);

	display.setTextSize(size);
	return mrb_nil_value();
}

mrb_value mrb_gfx_println(mrb_state *mrb, mrb_value self)
{
	mrb_value text;
	int n = mrb_get_args(mrb, "|S", &text);

	if(n > 0){
	  display.println(RSTRING_PTR(text));
	}
	return mrb_nil_value();
}

mrb_value mrb_gfx_print(mrb_state *mrb, mrb_value self)
{
	mrb_value text;
	int n = mrb_get_args(mrb, "|S", &text);

	if(n > 0){
	  display.print(RSTRING_PTR(text));
	}
	return mrb_nil_value();
}

mrb_value mrb_gfx_drawText(mrb_state *mrb, mrb_value self)
{
	int x, y;
	mrb_value text;
	int n = mrb_get_args(mrb, "iiS", &x, &y, &text);

	display.setCursor(x, y);
  display.print(RSTRING_PTR(text));

	return mrb_nil_value();
}

mrb_value mrb_gfx_setTextWrap(mrb_state *mrb, mrb_value self)
{
	mrb_bool flag;
	mrb_get_args(mrb, "b", &flag);

	display.setTextWrap(flag);

	return mrb_nil_value();
}

mrb_value mrb_gfx_resetFont(mrb_state *mrb, mrb_value self)
{
	display.setFont(&acknowtt7pt7b);
	return mrb_nil_value();
}

mrb_value mrb_gfx_useDingbatsFont(mrb_state *mrb, mrb_value self)
{
	display.setFont(&pixel_dingbats_78pt8b);
	return mrb_nil_value();
}

mrb_value mrb_gfx_drawRect(mrb_state *mrb, mrb_value self)
{
	int x, y, w, h;
	mrb_get_args(mrb, "iiii", &x, &y, &w, &h);

	display.drawRect(x, y, w , h, WHITE);
	return mrb_nil_value();
}

mrb_value mrb_gfx_fillRect(mrb_state *mrb, mrb_value self)
{
	int x, y, w, h;
	mrb_get_args(mrb, "iiii", &x, &y, &w, &h);

	display.fillRect(x, y, w , h, WHITE);
	return mrb_nil_value();
}

void mrb_mruby_gr_ssd1306_gem_init(mrb_state *mrb)
{
  struct RClass *ssd1306;
  ssd1306 = mrb_define_class(mrb, "Ssd1306", mrb->object_class);

  mrb_define_module_function(mrb, ssd1306, "begin", mrb_gfx_begin, MRB_ARGS_REQ(1));
	mrb_define_module_function(mrb, ssd1306, "clear_display", mrb_gfx_clearDisplay, MRB_ARGS_NONE());
	mrb_define_module_function(mrb, ssd1306, "display", mrb_gfx_display, MRB_ARGS_NONE());
	mrb_define_module_function(mrb, ssd1306, "set_cursor", mrb_gfx_setCursor, MRB_ARGS_REQ(2));
	mrb_define_module_function(mrb, ssd1306, "draw_line", mrb_gfx_drawLine, MRB_ARGS_REQ(4));
	mrb_define_module_function(mrb, ssd1306, "set_text_size", mrb_gfx_setTextSize, MRB_ARGS_REQ(1));
	mrb_define_module_function(mrb, ssd1306, "print", mrb_gfx_print, MRB_ARGS_OPT(1));
	mrb_define_module_function(mrb, ssd1306, "println", mrb_gfx_println, MRB_ARGS_OPT(1));
	mrb_define_module_function(mrb, ssd1306, "draw_text", mrb_gfx_drawText, MRB_ARGS_REQ(3));
	mrb_define_module_function(mrb, ssd1306, "set_text_wrap", mrb_gfx_setTextWrap, MRB_ARGS_REQ(1));
	mrb_define_module_function(mrb, ssd1306, "reset_font", mrb_gfx_resetFont, MRB_ARGS_NONE());
	mrb_define_module_function(mrb, ssd1306, "use_dingbats_font", mrb_gfx_useDingbatsFont, MRB_ARGS_NONE());
	mrb_define_module_function(mrb, ssd1306, "draw_rect", mrb_gfx_drawRect, MRB_ARGS_REQ(4));
	mrb_define_module_function(mrb, ssd1306, "fill_rect", mrb_gfx_fillRect, MRB_ARGS_REQ(4));

  DONE;
}

void mrb_mruby_gr_ssd1306_gem_final(mrb_state *mrb)
{
}

/*
** mrb_ssd1306.c - Ssd1306 class
**
** Copyright (c) Jun Takeda 2016
**
** See Copyright Notice in LICENSE
*/

#include "mruby.h"
#include "mruby/data.h"
#include "mrb_ssd1306.h"

#define DONE mrb_gc_arena_restore(mrb, 0);

typedef struct {
  char *str;
  int len;
} mrb_ssd1306_data;

static const struct mrb_data_type mrb_ssd1306_data_type = {
  "mrb_ssd1306_data", mrb_free,
};

static mrb_value mrb_ssd1306_init(mrb_state *mrb, mrb_value self)
{
  mrb_ssd1306_data *data;
  char *str;
  int len;

  data = (mrb_ssd1306_data *)DATA_PTR(self);
  if (data) {
    mrb_free(mrb, data);
  }
  DATA_TYPE(self) = &mrb_ssd1306_data_type;
  DATA_PTR(self) = NULL;

  mrb_get_args(mrb, "s", &str, &len);
  data = (mrb_ssd1306_data *)mrb_malloc(mrb, sizeof(mrb_ssd1306_data));
  data->str = str;
  data->len = len;
  DATA_PTR(self) = data;

  return self;
}

static mrb_value mrb_ssd1306_hello(mrb_state *mrb, mrb_value self)
{
  mrb_ssd1306_data *data = DATA_PTR(self);

  return mrb_str_new(mrb, data->str, data->len);
}

static mrb_value mrb_ssd1306_hi(mrb_state *mrb, mrb_value self)
{
  return mrb_str_new_cstr(mrb, "hi!!");
}

void mrb_mruby_gr_ssd1306_gem_init(mrb_state *mrb)
{
  struct RClass *ssd1306;
  ssd1306 = mrb_define_class(mrb, "Ssd1306", mrb->object_class);
  mrb_define_method(mrb, ssd1306, "initialize", mrb_ssd1306_init, MRB_ARGS_REQ(1));
  mrb_define_method(mrb, ssd1306, "hello", mrb_ssd1306_hello, MRB_ARGS_NONE());
  mrb_define_class_method(mrb, ssd1306, "hi", mrb_ssd1306_hi, MRB_ARGS_NONE());
  DONE;
}

void mrb_mruby_gr_ssd1306_gem_final(mrb_state *mrb)
{
}


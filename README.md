# mruby-arduino-ssd1306
SSD1306 library for mruby-arduino environment.
This library is a wrapper library for [Adafruit_SSD1306](https://github.com/adafruit/Adafruit_SSD1306) and [Adafruit GFX Library](https://github.com/adafruit/Adafruit-GFX-Library).

> Adafruit invests time and resources providing this open source code, please support Adafruit and open-source hardware by purchasing products from Adafruit!

Currentry, only I2C and 128×64 pixels are supported.

## install by mrbgems
- add conf.gem line to `build_config.rb`

```ruby
MRuby::Build.new do |conf|

    # ... (snip) ...

    # additional configrations for Arduino API
    conf.cc.flags << " -DGRSAKURA -DARDUINO=100 "
    conf.cc.include_paths << ["../gr_common/lib/", "../gr_common", "../gr_common/core", "../gr_common/lib/SPI", "../gr_common/lib/Wire", "../gr_common/lib/Servo" ]
    conf.cxx.flags = conf.cc.flags.dup
    conf.cxx.include_paths = conf.cc.include_paths.dup
    
    # Arduino API
    conf.gem :github => "takjn/mruby-arduino", :branch => "master"

    # SSD1306 library for mruby-arduino environment.
    conf.gem :github => "takjn/mruby-arduino-ssd1306", :branch => "master"

end
```

## example
```ruby
SSD1306.begin(0x3C)
SSD1306.clear_display
SSD1306.draw_line(0, 0, 127, 63);
SSD1306.display
```

## License
[Adafruit_SSD1306](https://github.com/adafruit/Adafruit_SSD1306) is under the BSD License:
- see src/Adafruit_SSD1306/license.txt

[Adafruit GFX Library](https://github.com/adafruit/Adafruit-GFX-Library) is under the BSD License:
- see src/Adafruit-GFX-Library/license.txt

mrb_arduino_ssd1306 is under the MIT License:
- see LICENSE file

## See also
- [mruby-arduino for Gadget Renesas](https://github.com/takjn/mruby-arduino)
- [mirb for Gadget Renesas](https://github.com/takjn/mirb4gr)
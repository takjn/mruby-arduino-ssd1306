# mruby-gr-ssd1306
SSD1306(OLED) library for mruby-arduino environments.
This library is a wrapper library for [Adafruit_SSD1306](https://github.com/adafruit/Adafruit_SSD1306) and [Adafruit GFX Library](https://github.com/adafruit/Adafruit-GFX-Library).

> Adafruit invests time and resources providing this open source code, please support Adafruit and open-source hardware by purchasing products from Adafruit!

## install by mrbgems
- add conf.gem line to `build_config.rb`

```ruby
MRuby::Build.new do |conf|

    # ... (snip) ...

    GR_MRUBY_FIRMWARE_PATH = '/#{PATH_TO}/wrbb-v2lib-firm/firmware_develop'
    conf.gem :github => 'takjn/mruby-gr-ssd1306'
      g.cxx.flags << " -x c++ -DGRSAKURA -DARDUINO=100 "
      g.cxx.include_paths << ["#{GR_MRUBY_FIRMWARE_PATH}/gr_common/lib/SPI/", "#{GR_MRUBY_FIRMWARE_PATH}/gr_common/lib/Wire/", "#{GR_MRUBY_FIRMWARE_PATH}/gr_common", "#{GR_MRUBY_FIRMWARE_PATH}/gr_common/core" ]
    end

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
- see Adafruit_SSD1306/license.txt

[Adafruit GFX Library](https://github.com/adafruit/Adafruit-GFX-Library) is under the BSD License:
- see Adafruit-GFX-Library/license.txt

mrb_arduino_ssd1306 is under the MIT License:
- see LICENSE file

## See also
- [mruby-arduino for Gadget Renesas](https://github.com/takjn/mruby-arduino)
- [mirb for Gadget Renesas](https://github.com/takjn/mirb4gr)
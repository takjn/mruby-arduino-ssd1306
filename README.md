# mruby-gr-ssd1306   [![Build Status](https://travis-ci.org/takjn/mruby-gr-ssd1306.svg?branch=master)](https://travis-ci.org/takjn/mruby-gr-ssd1306)
SSD1306(OLED) for GR-CITRUS.

まだ動いていないです。。。

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
T.B.D.
```

## License
under the MIT License:
- see LICENSE file

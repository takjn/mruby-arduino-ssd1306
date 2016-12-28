# mruby-gr-ssd1306   [![Build Status](https://travis-ci.org/takjn/mruby-gr-ssd1306.svg?branch=master)](https://travis-ci.org/takjn/mruby-gr-ssd1306)
Ssd1306 class
## install by mrbgems
- add conf.gem line to `build_config.rb`

```ruby
MRuby::Build.new do |conf|

    # ... (snip) ...

    conf.gem :github => 'takjn/mruby-gr-ssd1306'
end
```
## example
```ruby
p Ssd1306.hi
#=> "hi!!"
t = Ssd1306.new "hello"
p t.hello
#=> "hello"
p t.bye
#=> "hello bye"
```

## License
under the MIT License:
- see LICENSE file

##
## Ssd1306 Test
##

assert("Ssd1306#hello") do
  t = Ssd1306.new "hello"
  assert_equal("hello", t.hello)
end

assert("Ssd1306#bye") do
  t = Ssd1306.new "hello"
  assert_equal("hello bye", t.bye)
end

assert("Ssd1306.hi") do
  assert_equal("hi!!", Ssd1306.hi)
end

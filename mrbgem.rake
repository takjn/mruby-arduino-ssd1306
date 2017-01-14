MRuby::Gem::Specification.new('mruby-gr-ssd1306') do |spec|
  spec.license = 'MIT'
  spec.authors = 'Jun Takeda'

  # Add compile flags
  # spec.cc.flags << '-g'
  spec.cc.include_paths << ["#{dir}/src/Adafruit_SSD1306", "#{dir}/src/Adafruit-GFX-Library"]
  spec.cxx.include_paths << spec.cc.include_paths.dup

  # Add cflags to all
  # spec.mruby.cc.flags << '-g'

  # Add libraries
  # spec.linker.libraries << 'external_lib'

  # Default build files
  # spec.rbfiles = Dir.glob("#{dir}/mrblib/*.rb")
  # spec.objs = Dir.glob("#{dir}/src/*.{c,cpp,m,asm,S}").map { |f| objfile(f.relative_path_from(dir).pathmap("#{build_dir}/%X")) }
  spec.objs << Dir.glob("#{dir}/src/Adafruit-GFX-Library/*.{c,cpp,m,asm,S}").map { |f| objfile(f.relative_path_from(dir).pathmap("#{build_dir}/%X")) }
  spec.objs << Dir.glob("#{dir}/src/Adafruit_SSD1306/*.{c,cpp,m,asm,S}").map { |f| objfile(f.relative_path_from(dir).pathmap("#{build_dir}/%X")) }
  
  # spec.test_rbfiles = Dir.glob("#{dir}/test/*.rb")
  # spec.test_objs = Dir.glob("#{dir}/test/*.{c,cpp,m,asm,S}").map { |f| objfile(f.relative_path_from(dir).pathmap("#{build_dir}/%X")) }
  # spec.test_preload = 'test/assert.rb'

  # Values accessible as TEST_ARGS inside test scripts
  # spec.test_args = {'tmp_dir' => Dir::tmpdir}
end


project('test', 'cpp')

deps = []
deps += dependency('fmt')
deps += dependency('glfw3')
deps += dependency('gl')

subdir('src')

executable('main', sources, dependencies : deps)

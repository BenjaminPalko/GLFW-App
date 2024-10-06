project('test', 'cpp')

deps = []
deps += dependency('fmt')
deps += dependency('glfw3')
deps += dependency('gl')
deps += dependency('glew')

directories = include_directories('libs')

subdir('src')

executable('main', sources, dependencies: deps, include_directories: directories)

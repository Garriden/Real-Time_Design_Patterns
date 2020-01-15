src = [
'main.cpp', 
'Event.cpp',
'Display.cpp',
'Generator.cpp',
'LowPass.cpp',
'Pipe.cpp']

incdir = include_directories('.')

thread_dep = dependency('threads')

executable('exercies-9', [src] , include_directories : [incdir], dependencies : thread_dep)

doctest_inc = include_directories('../../doctest/doctest/')
e = executable('test-ex9', [src] , include_directories : [incdir, doctest_inc], cpp_args : '-DTDD', dependencies : thread_dep)
test('test exercise 9', e)
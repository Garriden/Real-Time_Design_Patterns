src = [
'main.cpp', 
'Event.cpp',
'Display.cpp',
'Generator.cpp',
'LowPass.cpp',
'Pipe.cpp']

incdir = include_directories('.')

executable('exercies-3', [src] , include_directories : [incdir])

doctest_inc = include_directories('../../doctest/doctest/')
e = executable('test-ex3', [src] , include_directories : [incdir, doctest_inc], cpp_args : '-DTDD')
test('test exercise 3', e)
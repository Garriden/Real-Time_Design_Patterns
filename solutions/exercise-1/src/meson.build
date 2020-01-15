src = ['main.cpp', 'Event.cpp']
incdir = include_directories('.')

executable('app', [src] , include_directories : [incdir])

doctest_inc = include_directories('../../doctest/doctest/')
e = executable('test-app', [src] , include_directories : [incdir, doctest_inc], cpp_args : '-DTDD')
test('test Event', e)
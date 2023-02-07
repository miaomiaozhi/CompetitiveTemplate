@echo off

g++ std.cpp -o std -static
g++ bf.cpp -o bf -static

set /a i=0
set /a T=100

:loop
    python gen.py > 1.in
    std.exe < 1.in > std.out
    bf.exe < 1.in > bf.out
    fc std.out bf.out
    set /a i+=1
    echo Running on test %i%

if %i% == %T% goto end

if not errorlevel 1 goto loop

echo WA on test %i%

:end
pause
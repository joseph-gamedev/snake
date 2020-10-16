if not exist build mkdir build

cmake build -S %cd% -B %cd%\build -A x64

mkdir "build/arcade/Debug"

python scripts/CopyFiles.py "extern/libsdl2/lib/x64/dll" "build/arcade/debug"
python scripts/CopyFiles.py "extern/sdl2ttf/lib/x64/dll" "build/arcade/debug"

xcopy /e /v %cd%\res %cd%\build\arcade\debug
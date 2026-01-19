Hello
Notki:
- Czy w mainie jest wrzucony test? - main był źle zrobiony
- Na którym gcc chcemy robić? - CPP17 +
- Fajnie jest sobie pobrać add-ony do cmake'a
- Czy trzeba dodać gmock do Cmake'a? - Nie, bo hmock jest rozszerzeniem testów googlowskich

Do zmiany w json file:
{
    "configurations": [
        {
            "name": "Win32",
            "includePath": [
                "${workspaceFolder}/include",
                "${workspaceFolder}/src",
                "${workspaceFolder}/test",
                "${workspaceFolder}"
            ],
            "browse": {
                "path": [
                    "${workspaceFolder}/include",
                    "${workspaceFolder}/src",
                    "${workspaceFolder}/test",
                    "${workspaceFolder}"
                ],
                "limitSymbolsToIncludedHeaders": true
            },
            "defines": [],
            "compilerPath": "C:\\MinGW\\bin\\gcc.exe",
            "cStandard": "c11",
            "cppStandard": "gnu++17",
            "intelliSenseMode": "windows-gcc-x64",
            "configurationProvider": "ms-vscode.cmake-tools"
        }
    ],
    "version": 4
}
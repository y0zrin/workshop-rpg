# Visual Studio の「フォルダーを開く」や、コマンドの cmake でもビルドできるように
cmake_minimum_required(VERSION 3.16)
project(workshop_rpg CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(workshop-rpg
    src/main.cpp
    src/battle.cpp
    src/console.cpp
    src/enemy.cpp
    src/message.cpp
    src/random.cpp
    src/status.cpp
)

if(MSVC)
    # ソースは UTF-8（日本語の文字列を正しく扱うため）
    target_compile_options(workshop-rpg PRIVATE /utf-8 /W3)
endif()

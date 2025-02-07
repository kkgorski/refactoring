# Wersja CMake - zostawić jak jest
cmake_minimum_required(VERSION 3.5)

# Nazwa projektu
project(GtestTemplate)

# Wersja C++ 14
set(CMAKE_CXX_STANDARD 14)

# Miejsca w których kompilator ma szukać plików nagłówkowych .h i .hpp
include_directories(include                     #nasz folder include
        googletest-master/googlemock/include    #foldery google test
        googletest-master/googletest/include)

# Tu będą wszystkie pliki .cpp projektu (na razie nie mamy żadnych)
set(SOURCE_FILES
        include/Die.h src/Player.cpp include/Player.h src/Board.cpp include/Board.h src/Field.cpp include/Field.h include/MonopolyGame.h src/MonopolyGame.cpp)

# Tu będą pliki .cpp używane tylko podczas testów jednostkowych
set(TEST_SOURCES
        test/main_test.cpp) #plik z funkcją main() do testów

#dodaje bibliotekę Google Test, kompiluje ją z użyciem CMakeLists.txt z folderu googletest-master
add_subdirectory(googletest-master)
link_libraries(gmock)

#Tworzy konfigurację o nazwie konfig_run (nazwę możemy dowolnie zmienić)
# do której dołącza plik main.cpp z funkcją main()
add_executable(config_run ${SOURCE_FILES} main.cpp)

#Tworzy konfigurację o nazwie konfig_test służącą do uruchamiania testów jednostkowych
add_executable(config_test ${SOURCE_FILES} ${TEST_SOURCES})

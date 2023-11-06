#include "gtest/gtest.h"
#include "system/files/file.h"
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>

//class FileTest : public ::testing::Test {
//protected:
//
//
//    void SetUp() override {
//
//    }
//
//    void TearDown() override {
//
//    }
//
//};

TEST(FileTest, FileExistsTest) {
    std::string absoluteExistentFilePath = std::string("/Users/felixberge/Projects/ C++/212-cpp-game-FelixAtForsberg/tests/resources/test_file.txt");
    std::string absoluteNonExistentFilePath = std::string("/Users/felixberge/Projects/ C++/212-cpp-game-FelixAtForsberg/tests/some/bogus/path.txt");
    SDLGame::System::File fileExists(absoluteExistentFilePath);
    SDLGame::System::File fileDoesNotExist(absoluteNonExistentFilePath);

    EXPECT_TRUE(fileExists.exists);
    EXPECT_FALSE(fileDoesNotExist.exists);
}
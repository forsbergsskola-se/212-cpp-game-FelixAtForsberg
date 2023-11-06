#include "file.h"
#include "file_image.h"
#include <array>
#include <iostream>

using SDLGame::System::IMAGE_TYPE,
      SDLGame::System::Image,
      std::string,
      std::array,
      std::byte;


SDLGame::System::Image::Image(string& imagePath) : SDLGame::System::File(imagePath) {

    array<unsigned char, 8> sigBuffer = {};
    fileStream.read(reinterpret_cast<char*>(sigBuffer.data()), sigBuffer.size());

    if (sigBuffer == PNG_SIGNATURE) {
        imageType = IMAGE_TYPE::PNG;

        std::cout << "IMAGE TYPE: PNG" << std::endl;

//        fileStream.seekg(0);
    fileStream.seekg(PNG_OFFSET_WIDTH); // Height is stored at offset 22
    fileStream.read(reinterpret_cast<char*>(&width), 4);

//    std::cout << std::endl << reinterpret_cast<unsigned char*>(width);

    fileStream.seekg(PNG_OFFSET_HEIGHT); // Height is stored at offset 22
    fileStream.read(reinterpret_cast<char*>(&height), 4);

    std::cout << "height, width: " << height << " , " << width  << " " << std::endl ;

//    rect.h = ntohl(height);
//    rect.w = ntohl(width);
    }

}

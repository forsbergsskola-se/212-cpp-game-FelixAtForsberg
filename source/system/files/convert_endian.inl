#pragma once

//#define LOG_ENDIAN_CONVERSION

#include <iostream>

namespace {
    template<std::size_t N, typename T = char>
    void ConvertEndian(std::array<T, N>& buffer) {
        const size_t half = buffer.size() / 2;

    #ifdef LOG_ENDIAN_CONVERSION
        std::cout << "bytes: ";
        for (auto const &x : buffer) {
            std::cout << std::setw(2) << std::setfill('0') << std::hex << +x << " ";
        }
        std::cout << std::endl;
    #endif

        for (size_t i = 0; i < half; i++) {
            const size_t swapTailIndex = buffer.size() - (i + 1);
    #ifdef LOG_ENDIAN_CONVERSION
            std::cout << "swapping indexes: " <<
            i << " <-> " << swapTailIndex <<
            " (values: " <<
             +buffer[i]  << " <-> "  << +buffer[swapTailIndex]<<
             ", hex: "   << std::hex <<
             +buffer[i]  << " <-> "  << +buffer[swapTailIndex]<<
             ")" << std::endl;
    #endif
            std::swap(buffer[i], buffer[swapTailIndex]);
        }
    #ifdef LOG_ENDIAN_CONVERSION
        std::cout << std::endl;
    #endif
    }


}

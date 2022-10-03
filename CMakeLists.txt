cmake_minimum_required(VERSION 3.16)
project(bookstore)

set(CMAKE_CXX_STANDARD 20)

Include(FetchContent)

FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG        v3.0.1 # or a later release
)

FetchContent_MakeAvailable(Catch2)

add_executable(test_bookstore src/AbstractItem.cpp src/AbstractItem.h src/Cart.cpp src/Cart.h src/CartAble.h src/AbstractItemOnOffer.cpp src/AbstractItemOnOffer.h src/Book.cpp src/Book.h src/DiscountVoucher.cpp src/DiscountVoucher.h src/GiftWrapping.cpp src/GiftWrapping.h src/PromotedBook.cpp src/PromotedBook.h test_main.cpp)
target_link_libraries(test_bookstore PRIVATE Catch2::Catch2WithMain)


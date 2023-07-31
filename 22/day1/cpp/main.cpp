#include <iostream>
#include <fstream>
#include <numeric>
#include <memory>

namespace myns {
    template<typename T, std::size_t N>
    class trunc_array {
    protected:
        std::size_t len;
        std::array<T, N> inner;
    public:
        trunc_array() {
            len = 0;
        }

        void push_back(T v) {
            if (len == N) throw std::out_of_range("out of storage");
            inner[len] = std::move(v);
            len++;
        }

        /// inserts at specified index
        /// if container is full discards last element
        void insert_discard(std::size_t at, T v) {
            if (at >= len) throw std::out_of_range("index out of bounds");
            if (len != N && len != 0) {
                push_back(std::move(inner[len - 1]));
            }
            for (int i = len - 1; i > at; i--) {
                inner[i] = std::move(inner[i - 1]);
            }
            inner[at] = std::move(v);
        }

        constexpr std::size_t size() {
            return len;
        }

        const T &operator[](std::size_t i) {
            if (i >= len) throw std::out_of_range("index out of bounds");
            return inner[i];
        }

        constexpr auto begin() {
            return std::begin(inner);
        }

        constexpr auto end() {
            return std::begin(inner) + len;
        }
    };

    template<typename T, std::size_t N, class Compare>
    class top : private trunc_array<T, N> {
    public:
        using trunc_array<T, N>::operator[];
        using trunc_array<T, N>::size;
        using trunc_array<T, N>::begin;
        using trunc_array<T, N>::end;

        void insert(T v) {
            for (int i = 0; i < size(); i++) {
                if (Compare{}(v, this->operator[](i))) {
                    this->insert_discard(i, std::move(v));
                    return;
                }
            }
            if (N != size()) {
                this->push_back(std::move(v));
            }
        }
    };
}


int main() {
    std::ifstream input("../input.txt");
    myns::top<int, 3, std::greater<>> top;
    auto curBag = 0;
    for (std::string line{}; std::getline(input, line);) {
        if (!line.empty()) {
            curBag += std::stoi(line);
        } else {
            top.insert(curBag);
            curBag = 0;
        }
    }
    std::cout << "Part 1: " << top[0] << std::endl;
    int top3 = std::accumulate(std::begin(top), std::end(top), 0);
    std::cout << "Part 2: " << top3 << std::endl;
    return 0;
}

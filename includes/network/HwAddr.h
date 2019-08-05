#pragma once

#include <cstdint>
#include <ostream>
#include <string>

using byte=uint8_t;

namespace network {
    class HwAddr {
    public:
        static const int size{6};
        byte addr[size]{};
    public:
        HwAddr() = default;
        HwAddr(const HwAddr &mac) = default;
        explicit HwAddr(const byte mac[size]);
        explicit HwAddr(const std::string &mac) noexcept(false);
    public:
        std::string to_string() const;
        void parse_string(const std::string &mac) noexcept(false);
    public:
        HwAddr &operator=(const std::string &mac);
    };

    static const HwAddr& broadcast_mac = HwAddr("FF:FF:FF:FF:FF:FF");
}

std::ostream &operator<<(std::ostream &o, const network::HwAddr &addr) {
    o << addr.to_string();
    return o;
}
#ifndef ARP_SENDER_ARP_H
#define ARP_SENDER_ARP_H

#include <cstdint>
#include "../HwAddr.h"
#include "../IpAddr.h"

using byte=uint8_t;
using u_short=uint16_t;

namespace network {
    class Arp {
    public:
        u_short hw_type;
        u_short protocol_type;
        byte hw_size;
        byte protocol_size;
        u_short opcode;
        HwAddr sender_mac;
        IpAddr sender_ip;
        HwAddr target_mac;
        IpAddr target_ip;
    public:
        Arp() = default;
        explicit Arp(const byte arp[]);
        explicit Arp(u_short ht, u_short pt, byte hs, byte ps, u_short oc,
                const HwAddr& smac, const IpAddr& sip, const HwAddr& tmac, const IpAddr& tip);
    };
}

#endif //ARP_SENDER_ARP_H

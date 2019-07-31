#include "Arp.h"

using namespace network;

Arp::Arp(const byte *arp) {
    hw_type = arp[0] << 8 | arp[1];
    protocol_type = arp[2] << 8 | arp[3];
    hw_size = arp[4];
    protocol_size = arp[5];
    opcode = arp[6] << 8 | arp[7];
    sender_mac = HwAddr(arp + 8);
    sender_ip = IpAddr(arp + 14);
    target_mac = HwAddr(arp + 18);
    target_ip = IpAddr(arp + 24);
}

Arp::Arp(u_short ht, u_short pt, byte hs, byte ps, u_short oc,
        const HwAddr &smac, const IpAddr &sip, const HwAddr &tmac, const IpAddr &tip) {
    hw_type = ht;
    protocol_type = pt;
    hw_size = hs;
    protocol_size = ps;
    opcode = oc;
    sender_mac = smac;
    sender_ip = sip;
    target_mac = tmac;
    target_ip = tip;
}

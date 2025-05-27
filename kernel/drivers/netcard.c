// netcard.c — fake AF NIC driver that might become real one day

#include "../include/screen.h"
#include "../include/ports.h"
#include <string.h>

#define NIC_BUFFER_SIZE 1024

static char net_buffer[NIC_BUFFER_SIZE];

void nic_init() {
    memset(net_buffer, 0, NIC_BUFFER_SIZE);

    // eventually you'll probe PCI here or init a real chip
    print("[net] NIC init — placeholder driver online\n");
}

void nic_send(const char* msg) {
    strncpy(net_buffer, msg, NIC_BUFFER_SIZE - 1);
    net_buffer[NIC_BUFFER_SIZE - 1] = '\0';

    // here you’d write to NIC I/O ports — not yet tho
    print("[net] packet 'sent': ");
    print(net_buffer);
    print("\n");
}

const char* nic_receive() {
    print("[net] packet 'received': ");
    print(net_buffer);
    print("\n");
    return net_buffer;
}

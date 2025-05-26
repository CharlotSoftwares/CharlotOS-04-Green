// netcard.c — pretend NIC that buffers "sent" packets

#include <drivers/screen.h>
#include <string.h>

char net_buffer[1024];

void nic_init() {
    memset(net_buffer, 0, sizeof(net_buffer));
    print("[net] fake NIC online lol\n");
}

void nic_send(const char* msg) {
    strncpy(net_buffer, msg, sizeof(net_buffer)-1);
    print("[net] packet 'sent': ");
    print(msg);
    print("\n");
}

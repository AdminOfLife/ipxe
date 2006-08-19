#include <stdint.h>
#include <byteswap.h>
#include <errno.h>
#include <string.h>
#include <gpxe/icmp6.h>
#include <gpxe/ip6.h>
#include <gpxe/in.h>
#include <gpxe/netdevice.h>
#include <gpxe/pkbuff.h>
#include <gpxe/tcpip.h>

#define NDP_STATE_INVALID 0
#define NDP_STATE_INCOMPLETE 1
#define NDP_STATE_REACHABLE 2
#define NDP_STATE_DELAY 3
#define NDP_STATE_PROBE 4
#define NDP_STATE_STALE 5

static struct ndp_entry * ndp_find_entry ( struct in6_addr *in6 );
int ndp_resolve ( struct net_device *netdev, struct in6_addr *src,
		  struct in6_addr *dest, void *dest_ll_addr );
int ndp_process_advert ( struct pk_buff *pkb, struct sockaddr_tcpip *st_src,
			 struct sockaddr_tcpip *st_dest );

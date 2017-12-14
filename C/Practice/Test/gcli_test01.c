#include <stdio.h>
#include <string.h>

#define PDATA_TX_PORT_LIST_BUF_SIZE 10
#define PDATA_RX_PORT_LIST_BUF_SIZE 10

typedef struct pdata {
    int enable;
    int tx_dest;
    int rx_dest;
    char tx_port_list[PDATA_TX_PORT_LIST_BUF_SIZE];
    char rx_port_list[PDATA_RX_PORT_LIST_BUF_SIZE];
}PDATA_T,*PDATA_P;

struct objEthPhyIf {
    unsigned int gid;           // (Not Configurable, No flash content) GID of this entry;

    char name[16];              // GE0, GEx
    unsigned int type;          // bit 0: real device(0) / switch device(1)
    // bit 1-2: lan(0) / wan(1) / dmz(2)
    int enable;                 // 0: disable, 1: enable
    int mode;                   // 0: access mode, 1 trunk mode.
    int pvid;
    int logicalIndex;           // It's the index of GEx. GE0 is 0, GE1 is 1, and GEx is x
    int switchIndex;            // Used in swtich device.
    char phyIf[16];             // eth0, eth1, eth2, eth5 etc...
    int vlanNum;
    unsigned int vlanId[64];    // vlan ID
    char mac[20];
    
    int speed;  // 0: Auto, 10: 10M, 100: 100M, 1000: 1000M
    int duplex; // 0: Duplex, 1: Half
    int flowCtl;    // 0: Disable, 1: enable
    
    //Port mirror
    int mirrorTX;       // Enable is 1, Disable is 0
    int mirrorRX;       // Enable is 1, Disable is 0
    
    //CDP
    int isEnableCDP;    // Enable is 1, Disable is 0
    
    // IEEE802.1x
    int ieee8021xMode;          // Enable is 1, Disable is 0
    int ieee8021xPortState;     // Auth is 1, unauth is 0, needed auth is 2
    int ieee8021xGuestVlan;     // Enable is 1, Disable is 0
    int preVid;         // previous valn
                                                                                               int preIeee8021xMode;       // previous 802.1x Mode. Enable is 1, Disable is 0
    unsigned int guestVlanId;   //  guest vlan gid
                                                                                               unsigned int authLanIfId;   //  auth vlan gid
    // Hardware Related Parameters
    };
int main()
{
 PDATA_P p;

strcpy(p->tx_port_list,"0111111110");
strcpy(p->rx_port_list,"0111111110");

struct objEthPhyIf ethphyif;
int i;
memset(&ethphyif, 0, sizeof(ethphyif));
    for(i=0;i<=9;i++)
    {
    printf("i = %d\n",i+1);
        ethphyif.logicalIndex=i+1;
      ethphyif.mirrorTX=p->tx_port_list[i]-'0';
            ethphyif.mirrorRX=p->rx_port_list[i]-'0';
          printf("p->tx_port_list[%d]=%c\n", i, p->tx_port_list[i]);
              printf("p->rx_port_list[%d]=%c\n", i, p->rx_port_list[i]);
                  printf("ethphyif.logicalindex=%d\n", ethphyif.logicalIndex);
                    printf("ethphyif.mirrorTX=%d\n", ethphyif.mirrorTX);
                    printf("ethphyif.mirrorRX=%d\n", ethphyif.mirrorRX);

    }
}//end main

//void test(char);

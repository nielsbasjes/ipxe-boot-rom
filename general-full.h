#define	CRYPTO_80211_WEP	/* WEP encryption (deprecated and insecure!) */
#define	CRYPTO_80211_WPA	/* WPA Personal, authenticating with passphrase */
#define	CRYPTO_80211_WPA2	/* Add support for stronger WPA cryptography */
 
#define	IWMGMT_CMD		/* Wireless interface management commands */
#define FCMGMT_CMD		/* Fibre Channel management commands */

#define	NET_PROTO_IPV4		/* IPv4 protocol */
#undef	NET_PROTO_IPV6		/* IPv6 protocol */
#define	NET_PROTO_FCOE		/* Fibre Channel over Ethernet protocol */

/*
 * Image types
 *
 * Etherboot supports various image formats.  Select whichever ones
 * you want to use.
 *
 */
//#define	IMAGE_NBI		/* NBI image support */
//#define	IMAGE_ELF		/* ELF image support */
#define	IMAGE_MULTIBOOT		/* MultiBoot image support */
#define	IMAGE_PXE		/* PXE image support */
#define	IMAGE_SCRIPT		/* iPXE script image support */
//#define	IMAGE_BZIMAGE		/* Linux bzImage image support */
//#define	IMAGE_COMBOOT		/* SYSLINUX COMBOOT image support */
//#define	IMAGE_EFI		/* EFI image support */
//#define	IMAGE_SDI		/* SDI image support */
//#define	IMAGE_PNM		/* PNM image support */
#define	IMAGE_PNG		/* PNG image support */

//
/*
 * Download protocols
 *
 */

#define  PXE_STACK               /* PXE stack in iPXE - you want this! */

#define	DOWNLOAD_PROTO_TFTP	/* Trivial File Transfer Protocol */
#define	DOWNLOAD_PROTO_HTTP	/* Hypertext Transfer Protocol */
#define	DOWNLOAD_PROTO_HTTPS	/* Secure Hypertext Transfer Protocol */
#define	DOWNLOAD_PROTO_FTP	/* File Transfer Protocol */
#undef	DOWNLOAD_PROTO_SLAM	/* Scalable Local Area Multicast */
#undef	DOWNLOAD_PROTO_NFS	/* Network File System Protocol */

#define	SANBOOT_PROTO_ISCSI	/* iSCSI protocol */
#define	SANBOOT_PROTO_AOE	/* AoE protocol */
#define	SANBOOT_PROTO_IB_SRP	/* Infiniband SCSI RDMA protocol */
#define	SANBOOT_PROTO_FCP	/* Fibre Channel protocol */

#define	AUTOBOOT_CMD		/* Automatic booting */
#define	NVO_CMD			/* Non-volatile option storage commands */
#define	CONFIG_CMD		/* Option configuration console */
#define	IFMGMT_CMD		/* Interface management commands */
#define	IWMGMT_CMD		/* Wireless interface management commands */
#define FCMGMT_CMD		/* Fibre Channel management commands */
#define	ROUTE_CMD		/* Routing table management commands */
#define IMAGE_CMD		/* Image management commands */
#define DHCP_CMD		/* DHCP management commands */
#define SANBOOT_CMD		/* SAN boot commands */
#define MENU_CMD		/* Menu commands */
#define LOGIN_CMD		/* Login command */
#define SYNC_CMD		/* Sync command */
#define NSLOOKUP_CMD		/* DNS resolving command */
#define TIME_CMD		/* Time commands */
#define DIGEST_CMD		/* Image crypto digest commands */
#define LOTEST_CMD		/* Loopback testing commands */
#define VLAN_CMD		/* VLAN commands */
#define PXE_CMD		/* PXE commands */
#define REBOOT_CMD		/* Reboot command */
#define POWEROFF_CMD		/* Power off command */
#define IMAGE_TRUST_CMD	/* Image trust management commands */
#define PCI_CMD		/* PCI commands */
#define PARAM_CMD		/* Form parameter commands */
#define NEIGHBOUR_CMD		/* Neighbour management commands */
#define PING_CMD		/* Ping command */
#define CONSOLE_CMD		/* Console command */
#define IPSTAT_CMD		/* IP statistics commands */
#define PROFSTAT_CMD		/* Profiling commands */

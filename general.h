#undef	CRYPTO_80211_WEP	/* WEP encryption (deprecated and insecure!) */
#undef	CRYPTO_80211_WPA	/* WPA Personal, authenticating with passphrase */
#undef	CRYPTO_80211_WPA2	/* Add support for stronger WPA cryptography */
 
#undef	IWMGMT_CMD		/* Wireless interface management commands */
#undef FCMGMT_CMD		/* Fibre Channel management commands */

#define	NET_PROTO_IPV4		/* IPv4 protocol */
#undef	NET_PROTO_IPV6		/* IPv6 protocol */
#undef	NET_PROTO_FCOE		/* Fibre Channel over Ethernet protocol */

#undef  IMAGE_MULTIBOOT         /* MultiBoot image support */

/*
 * Download protocols
 *
 */

#undef  PXE_STACK               /* PXE stack in iPXE - you want this! */

#undef	DOWNLOAD_PROTO_TFTP	/* Trivial File Transfer Protocol */
#define	DOWNLOAD_PROTO_HTTP	/* Hypertext Transfer Protocol */
#undef	DOWNLOAD_PROTO_HTTPS	/* Secure Hypertext Transfer Protocol */
#undef	DOWNLOAD_PROTO_FTP	/* File Transfer Protocol */
#undef	DOWNLOAD_PROTO_SLAM	/* Scalable Local Area Multicast */
#undef	DOWNLOAD_PROTO_NFS	/* Network File System Protocol */

#undef	SANBOOT_PROTO_ISCSI	/* iSCSI protocol */
#undef	SANBOOT_PROTO_AOE	/* AoE protocol */
#undef	SANBOOT_PROTO_IB_SRP	/* Infiniband SCSI RDMA protocol */
#undef	SANBOOT_PROTO_FCP	/* Fibre Channel protocol */

#define	AUTOBOOT_CMD		/* Automatic booting */
#define	NVO_CMD			/* Non-volatile option storage commands */
#undef	CONFIG_CMD		/* Option configuration console */
#undef	IFMGMT_CMD		/* Interface management commands */
#undef	IWMGMT_CMD		/* Wireless interface management commands */
#undef FCMGMT_CMD		/* Fibre Channel management commands */
#undef	ROUTE_CMD		/* Routing table management commands */
#define IMAGE_CMD		/* Image management commands */
#define DHCP_CMD		/* DHCP management commands */
#define SANBOOT_CMD		/* SAN boot commands */
#undef MENU_CMD		/* Menu commands */
#define LOGIN_CMD		/* Login command */
#undef SYNC_CMD		/* Sync command */
#undef NSLOOKUP_CMD		/* DNS resolving command */
#define TIME_CMD		/* Time commands */
#undef DIGEST_CMD		/* Image crypto digest commands */
#undef LOTEST_CMD		/* Loopback testing commands */
#undef VLAN_CMD		/* VLAN commands */
#undef PXE_CMD		/* PXE commands */
#undef REBOOT_CMD		/* Reboot command */
#undef POWEROFF_CMD		/* Power off command */
#undef IMAGE_TRUST_CMD	/* Image trust management commands */
#undef PCI_CMD		/* PCI commands */
#undef PARAM_CMD		/* Form parameter commands */
#undef NEIGHBOUR_CMD		/* Neighbour management commands */
#undef PING_CMD		/* Ping command */
#undef CONSOLE_CMD		/* Console command */
#undef IPSTAT_CMD		/* IP statistics commands */
#undef PROFSTAT_CMD		/* Profiling commands */

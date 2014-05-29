#ifndef _REGIONS_C
#define _REGIONS_C

#define ABSOFF ""
#define Offset(o) {ABSOFF, o}

typedef struct {
    const char *name;
    int bits;
} fieldlist_t;

typedef struct {
    const char *name;
    off_t target;
    size_t length;
    fieldlist_t *fields;
} region_t;

fieldlist_t GNVS_fields[] = {
    {"OSYS",   16},
    {"SMIF",   8},
    {"PRM0",   8},
    {"PRM1",   8},
    {"SCIF",   8},
    {"PRM2",   8},
    {"PRM3",   8},
    {"LCKF",   8},
    {"PRM4",   8},
    {"PRM5",   8},
    {"P80D",   32},
    {"PWRS",   8},
    {"DBGS",   8},
    {"THOF",   8},
    {"ACT1",   8},
    {"ACTT",   8},
    {"PSVT",   8},
    {"TC1V",   8},
    {"TC2V",   8},
    {"TSPV",   8},
    {"CRTT",   8},
    {"DTSE",   8},
    {"DTS1",   8},
    {"DTS2",   8},
    {"DTSF",   8},
    Offset (0x1E),
    Offset (0x25),
    {"REVN",   8},
    Offset (0x28),
    {"APIC",   8},
    {"TCNT",   8},
    {"PCP0",   8},
    {"PCP1",   8},
    {"PPCM",   8},
    {"PPMF",   32},
    {"C67L",   8},
    {"NATP",   8},
    {"CMAP",   8},
    {"CMBP",   8},
    {"LPTP",   8},
    {"FDCP",   8},
    {"CMCP",   8},
    {"CIRP",   8},
    {"SMSC",   8},
    {"W381",   8},
    {"SMC1",   8},
    {"EMAE",   8},
    {"EMAP",   16},
    {"EMAL",   16},
    Offset (0x42),
    {"MEFE",   8},
    {"DSTS",   8},
    Offset (0x48),
    {"MORD",   8},
    {"TCGP",   8},
    {"PPRP",   32},
    {"PPRQ",   8},
    {"LPPR",   8},
    {"GTF0",   56},
    {"GTF2",   56},
    {"IDEM",   8},
    {"GTF1",   56},
    {"BID",    16},
    {"PLID",   8},
    {"ECTG",   8},
    Offset (0x70),
    {"OSCC",   8},
    {"NEXP",   8},
    {"SBV1",   8},
    {"SBV2",   8},
    Offset (0x7A),
    {"DSEN",   8},
    {"ECON",   8},
    {"GPIC",   8},
    {"CTYP",   8},
    {"L01C",   8},
    {"VFN0",   8},
    {"VFN1",   8},
    {"VFN2",   8},
    {"VFN3",   8},
    {"VFN4",   8},
    {"VFN5",   8},
    {"VFN6",   8},
    {"VFN7",   8},
    {"VFN8",   8},
    {"VFN9",   8},
    Offset (0x8F),
    {"ATMC",   8},
    {"PTMC",   8},
    {"ATRA",   8},
    {"PTRA",   8},
    {"PNHM",   32},
    {"TBAB",   32},
    {"TBAH",   32},
    {"RTIP",   8},
    {"TSOD",   8},
    {"ATPC",   8},
    {"PTPC",   8},
    {"PFLV",   8},
    {"BREV",   8},
    {"PDTS",   8},
    {"PKGA",   8},
    {"PAMT",   8},
    {"AC0F",   8},
    {"AC1F",   8},
    {"DTS3",   8},
    {"DTS4",   8},
    Offset (0xB0),
    {"LTR1",   8},
    {"LTR2",   8},
    {"LTR3",   8},
    {"LTR4",   8},
    {"LTR5",   8},
    {"LTR6",   8},
    {"LTR7",   8},
    {"LTR8",   8},
    {"OBF1",   8},
    {"OBF2",   8},
    {"OBF3",   8},
    {"OBF4",   8},
    {"OBF5",   8},
    {"OBF6",   8},
    {"OBF7",   8},
    {"OBF8",   8},
    {"XHCI",   8},
    {"XTUB",   32},
    {"XTUS",   32},
    {"XMPB",   32},
    {"DDRF",   8},
    {"RTD3",   8},
    {"PEP0",   8},
    {"PEP3",   8},
    {"DPTF",   8},
    {"SADE",   8},
    {"SACR",   8},
    {"SAHT",   8},
    {"PCHD",   8},
    {"PCHC",   8},
    {"PCHH",   8},
    {"CTDP",   8},
    {"LPMP",   8},
    {"LPMV",   8},
    {"ECEU",   8},
    {"TGFG",   16},
    {"MEMD",   8},
    {"MEMC",   8},
    {"MEMH",   8},
    {"FND1",   8},
    {"FND2",   8},
    {"AMBD",   8},
    {"AMAT",   8},
    {"AMPT",   8},
    {"AMCT",   8},
    {"AMHT",   8},
    {"SKDE",   8},
    {"SKAT",   8},
    {"SKPT",   8},
    {"SKCT",   8},
    {"SKHT",   8},
    {"EFDE",   8},
    {"EFAT",   8},
    {"EFPT",   8},
    {"EFCT",   8},
    {"EFHT",   8},
    {"VRDE",   8},
    {"VRAT",   8},
    {"VRPT",   8},
    {"VRCT",   8},
    {"VRHT",   8},
    {"DPAP",   8},
    {"DPPP",   8},
    {"DPCP",   8},
    {"DCMP",   8},
    {"TRTV",   8},
    {"LPOE",   8},
    {"LPOP",   8},
    {"LPOS",   8},
    {"LPOW",   8},
    {"LPER",   8},
    {"PPSZ",   32},
    {"DISE",   8},
    {"PFMA",   64},
    {"PFMS",   8},
    {"PFIA",   16},
    {"ICNF",   8},
    {"DSP0",   32},
    {"DSP1",   32},
    {"NFCE",   8},
    {"CODS",   8},
    {"SNHE",   8},
    {"S0ID",   8},
    {"CTDB",   8},
    Offset (0x207),
    {"PWRE",   8},
    {"PWRP",   8},
    {"XHPR",   8},
    {"SDS0",   8},
    {"SDS1",   16},
    {"SDS2",   8},
    {"SDS3",   8},
    {"SDS4",   8},
    {"SDS5",   8},
    Offset (0x212),
    {"RIC0",   8},
    {"PEPY",   8},
    {"DVS0",   8},
    {"DVS1",   8},
    {"DVS2",   8},
    {"DVS3",   8},
    {"GBSX",   8},
    {"IUBE",   8},
    {"IUCE",   8},
    {"IUDE",   8},
    {"ECNO",   8},
    {"AUDD",   16},
    {"DSPD",   16},
    {"IC0D",   16},
    {"IC1D",   16},
    {"IC1S",   16},
    {"VRRD",   16},
    {"PSCP",   8},
    {"RWAG",   8},
    {"I20D",   16},
    {"I21D",   16},
    Offset (0x231),
    {"RCG0",   8},
    {"ECDB",   8},
    {"P2ME",   8},
    {"SSH0",   16},
    {"SSL0",   16},
    {"SSD0",   16},
    {"FMH0",   16},
    {"FML0",   16},
    {"FMD0",   16},
    {"FPH0",   16},
    {"FPL0",   16},
    {"FPD0",   16},
    {"SSH1",   16},
    {"SSL1",   16},
    {"SSD1",   16},
    {"FMH1",   16},
    {"FML1",   16},
    {"FMD1",   16},
    {"FPH1",   16},
    {"FPL1",   16},
    {"FPD1",   16},
    {"M0C0",   16},
    {"M1C0",   16},
    {"M2C0",   16},
    {"M0C1",   16},
    {"M1C1",   16},
    {"M2C1",   16},
    {"M0C2",   16},
    {"M1C2",   16},
    {"M0C3",   16},
    {"M1C3",   16},
    {"M0C4",   16},
    {"M1C4",   16},
    {"M0C5",   16},
    {"M1C5",   16},
    {"TBSF",   8},
    {"GIRQ",   32},
    {"DMTP",   8},
    {"DMTD",   8},
    {"DMSH",   8},
    {"LANP",   8},
    Offset (0x27E),
    {"SHSB",   8},
    {"PLCS",   8},
    {"PLVL",   16},
    {"GN1E",   8},
    {"G1AT",   8},
    {"G1PT",   8},
    {"G1CT",   8},
    {"G1HT",   8},
    {"GN2E",   8},
    {"G2AT",   8},
    {"G2PT",   8},
    {"G2CT",   8},
    {"G2HT",   8},
    {"WWSD",   8},
    {"CVSD",   8},
    {"SSDD",   8},
    {"INLD",   8},
    {"IFAT",   8},
    {"IFPT",   8},
    {"IFCT",   8},
    {"IFHT",   8},
    {"DOSD",   8},
    {"USBH",   8},
    {"BCV4",   8},
    {"WTV0",   8},
    {"WTV1",   8},
    {"APFU",   8},
    {"SOHP",   8},
    {"NOHP",   8},
    {"TBSE",   8},
    {"WKFN",   8},
    {"PEPC",   16},
    {"VRSD",   16},
    {"PB1E",   8},
    {"WAND",   8},
    {"WWAT",   8},
    {"WWPT",   8},
    {"WWCT",   8},
    {"WWHT",   8},
    Offset (0x2AD),
    {"MPLT",   16},
    {"GR13",   8},
    {"SPST",   8},
    {"ECLP",   8},
    {NULL}
};

fieldlist_t SANV_fields[] = {
    {"SARV",   32},
    {"ASLB",   32},
    {"IMON",   8},
    {"IGDS",   8},
    {"CADL",   8},
    {"PADL",   8},
    {"CSTE",   16},
    {"NSTE",   16},
    {"DID9",   32},
    {"DIDA",   32},
    {"DIDB",   32},
    {"IBTT",   8},
    {"IPAT",   8},
    {"IPSC",   8},
    {"IBLC",   8},
    {"IBIA",   8},
    {"ISSC",   8},
    {"IPCF",   8},
    {"IDMS",   8},
    {"IF1E",   8},
    {"HVCO",   8},
    {"NXD1",   32},
    {"NXD2",   32},
    {"NXD3",   32},
    {"NXD4",   32},
    {"NXD5",   32},
    {"NXD6",   32},
    {"NXD7",   32},
    {"NXD8",   32},
    {"GSMI",   8},
    {"PAVP",   8},
    {"LIDS",   8},
    {"KSV0",   32},
    {"KSV1",   8},
    {"BBAR",   32},
    {"BLCS",   8},
    {"BRTL",   8},
    {"ALSE",   8},
    {"ALAF",   8},
    {"LLOW",   8},
    {"LHIH",   8},
    {"ALFP",   8},
    {"AUDA",   32},
    {"AUDB",   32},
    {"AUDC",   32},
    {"DIDC",   32},
    {"DIDD",   32},
    {"DIDE",   32},
    {"DIDF",   32},
    {"CCSA",   32},
    {"CCNT",   32},
    Offset (0xC8),
    {"SGMD",   8},
    {"SGFL",   8},
    {"PWOK",   8},
    {"HLRS",   8},
    {"PWEN",   8},
    {"PRST",   8},
    {"CPSP",   32},
    {"EECP",   8},
    {"EVCP",   16},
    {"XBAS",   32},
    {"GBAS",   16},
    {"SGGP",   8},
    {"NVGA",   32},
    {"NVHA",   32},
    {"AMDA",   32},
    {"NDID",   8},
    {"DID1",   32},
    {"DID2",   32},
    {"DID3",   32},
    {"DID4",   32},
    {"DID5",   32},
    {"DID6",   32},
    {"DID7",   32},
    {"DID8",   32},
    {"OBS1",   32},
    {"OBS2",   32},
    {"OBS3",   32},
    {"OBS4",   32},
    {"OBS5",   32},
    {"OBS6",   32},
    {"OBS7",   32},
    {"OBS8",   32},
    {"LTRA",   8},
    {"OBFA",   8},
    {"LTRB",   8},
    {"OBFB",   8},
    {"LTRC",   8},
    {"OBFC",   8},
    {"SMSL",   16},
    {"SNSL",   16},
    {"P0UB",   8},
    {"P1UB",   8},
    {"P2UB",   8},
    {"EDPV",   8},
    {"NXDX",   32},
    {"DIDX",   32},
    {"PCSL",   8},
    {"SC7A",   8},
    {"DSEL",   8},
    {"ESEL",   8},
    {"PSEL",   8},
    {"MXD1",   32},
    {"MXD2",   32},
    {"MXD3",   32},
    {"MXD4",   32},
    {"MXD5",   32},
    {"MXD6",   32},
    {"MXD7",   32},
    {"MXD8",   32},
    {"PXFD",   8},
    {"EBAS",   32},
    {"HYSS",   32},
    {NULL}
};

fieldlist_t SNVS_fields[] = {
    {"OSTP",   16},
    {"SMIS",   8},
    {"DB00",   8},
    {"DW00",   16},
    {"SLID",   8},
    {"SPWR",   8},
    {"SPBF",   8},
    {"LFLG",   8},
    {"CXMD",   8},
    {"USBW",   8},
    {"PVFN",   8},
    {"MISC",   8},
    {"RTYP",   8},
    {"RELT",   8},
    {"CPTY",   8},
    {"PPCS",   8},
    {"DIAG",   8},
    {"NIST",   8},
    {"RIST",   8},
    {"GSSR",   8},
    {"RCST",   8},
    {"CCST",   8},
    {"RCNT",   8},
    Offset (0x1A),
    {"BFCC",   16},
    {"TZON",   8},
    {"SDCK",   8},
    {"DKCM",   8},
    Offset (0x20),
    {"IVGV",   8},
    {"EVGV",   8},
    {"BSUP",   8},
    {"BRTV",   8},
    {"BNOT",   8},
    {"BCNT",   8},
    {"SBLC",   8},
    Offset (0x30),
    {"VGTY",   8},
    {"IGFX",   8},
    {"DTLS",   8},
    {"CDLS",   8},
    {"PALS",   8},
    {"CDSS",   16},
    {"NDSS",   16},
    {"SDSS",   16},
    Offset (0x40),
    {"CRTP",   8},
    {"PTTP",   8},
    {"PTC1",   8},
    {"PTC2",   8},
    {"PTSP",   8},
    {"CPUT",   8},
    {"COLP",   8},
    {"NVPL",   8},
    {"NVGF",   8},
    Offset (0x50),
    {"TPDF",   8},
    {"TPTY",   8},
    Offset (0x53),
    Offset (0x54),
    Offset (0x55),
    Offset (0x58),
    {"KBCL",   8},
    {"ABCS",   8},
    Offset (0x60),
    {"SNFC",   8},
    {"SICE",   8},
    {NULL}
};

fieldlist_t SSDB_fields[] = {
    {"SMPT",   8},
    {"SSSN",   8},
    {"SMIN",   8},
    {"PARM",   80},
    {NULL}
};

region_t regions[] = {
    {"GNVS", 0xDB8CDC18, 0x02B2, GNVS_fields},
    {"SANV", 0xDB8CCE18, 0x016D, SANV_fields},
    {"SNVS", 0xDB8CDF18, 0x0080, SNVS_fields},
    {"SSDB", 0xDB3C4838, 0x0040, SSDB_fields},
    {NULL}
};

#endif /* _REGIONS_C */

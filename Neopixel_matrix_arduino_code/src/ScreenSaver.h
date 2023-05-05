#ifndef SCRSAVER_H_
#define SCRSAVER_H_

// 'TGIFG', 12x8px
#define TGIFGWIDTH 12
#define TGIFGHEIGHT 8
const uint16_t Scr_SVrTGIFG[] PROGMEM = {
    0xffdf, 0xffff, 0xffff, 0xffff, 0xf79e, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffdf, 0x0020, 0x0000, 0x0000,
    0xffff, 0xf79e, 0x0861, 0x2965, 0xffff, 0xf79e, 0x10a2, 0xf7be, 0xffff, 0xffdf, 0x1082, 0xffdf, 0xffdf, 0x2104, 0xf7be, 0xf79e,
    0x18e3, 0xf79e, 0x0841, 0xffdf, 0xffff, 0xffff, 0x0020, 0xffff, 0xffff, 0x0020, 0xffff, 0xffff, 0xffdf, 0xffff, 0x0841, 0xffdf,
    0xffff, 0xffff, 0x0020, 0xffdf, 0xffdf, 0x0000, 0xffdf, 0x0020, 0x0020, 0xf7be, 0x0841, 0xffdf, 0xffff, 0xffff, 0x0020, 0xffff,
    0xffff, 0x0000, 0xffdf, 0xffff, 0x1082, 0xf7be, 0x0020, 0xffdf, 0xffff, 0xffff, 0x0000, 0xffff, 0xffff, 0xffdf, 0x0000, 0x0000,
    0xef5d, 0xffff, 0x10a2, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff};
// 'TGIBG', 29x16px
#define TGIBGWIDTH 29
#define TGIBGHEIGHT 16

// 'bg2', 29x16px
const uint16_t Scr_SVrTGIBG[] PROGMEM = {
    0xe9c7, 0xe904, 0xe925, 0xff7d, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xea28, 0xe882, 0xe904, 0xe904, 0xe8c3, 0xe800,
    0xff3c, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xff5d, 0xe861, 0xe904, 0xe986, 0xe924, 0xe904, 0xe965, 0xe904, 0xe8c3,
    0xe800, 0xff1c, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xe9a6, 0xe882, 0xe925, 0xe904, 0xe904, 0xe862, 0xff3c, 0xffff,
    0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xff7d, 0xe800, 0xe882, 0xe904, 0xe904, 0xe8e3, 0xe925, 0xe904, 0xe904, 0xe841, 0xff3c,
    0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xe986, 0xe800, 0xe904, 0xe904, 0xe8c3, 0xe820, 0xff9e, 0xffff, 0xffff, 0xffff,
    0xffff, 0xffff, 0xffff, 0xfefb, 0xe800, 0xe882, 0xe925, 0xe9c7, 0xe800, 0xe904, 0xe904, 0xe8c3, 0xe841, 0xfdf7, 0xffff, 0xffff,
    0xffff, 0xffff, 0xffff, 0xff5d, 0xe924, 0xe882, 0xe925, 0xe924, 0xe8c3, 0xe800, 0xff3c, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff,
    0xffff, 0xffbe, 0xe986, 0xe800, 0xff5d, 0xe924, 0xe882, 0xe925, 0xe924, 0xe8c3, 0xe841, 0xff5d, 0xffff, 0xffff, 0xffff, 0xffff,
    0xffff, 0xff7d, 0xe966, 0xe800, 0xe924, 0xe925, 0xe904, 0xe882, 0xff9e, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xff9e,
    0xe924, 0xffff, 0xff7d, 0xe966, 0xe800, 0xe924, 0xe925, 0xe904, 0xe8a2, 0xff1c, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xff5d,
    0xe924, 0xe800, 0xe925, 0xe904, 0xe8c3, 0xe800, 0xff3c, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff,
    0xff5d, 0xe924, 0xe800, 0xe925, 0xe904, 0xe8c3, 0xe841, 0xff3c, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xff7d, 0xe966, 0xe8c3,
    0xe925, 0xe924, 0xe8c3, 0xe861, 0xff3c, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xff7d, 0xe966,
    0xe8c3, 0xe925, 0xe924, 0xe8c3, 0xe841, 0xfebb, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xff1c, 0xe9a6, 0xe800, 0xe924, 0xe925,
    0xe904, 0xe882, 0xff9e, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xff9e, 0xe9a6, 0xe800, 0xe924,
    0xe925, 0xe904, 0xe8a2, 0xff7d, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xff5d, 0xe924, 0xe800, 0xe925, 0xe904, 0xe8c3, 0xe8c3,
    0xff9e, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xff5d, 0xe924, 0xe800, 0xe925, 0xe904, 0xe8c3,
    0xe800, 0xfe9a, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xff7d, 0xe966, 0xe8c3, 0xe925, 0xe924, 0xe8c3, 0xe800, 0xff9e, 0xffff,
    0xffff, 0xffff, 0xfe79, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xff7d, 0xe966, 0xe8c3, 0xe925, 0xe924, 0xe8c3, 0xe800, 0xfebb,
    0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xff1c, 0xe9a6, 0xe800, 0xe924, 0xe925, 0xe904, 0xe882, 0xfeba, 0xffff, 0xffff, 0xe861,
    0xfefb, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xff9e, 0xe9a6, 0xe800, 0xe924, 0xe925, 0xe904, 0xe882, 0xff1c, 0xffff, 0xffff,
    0xffff, 0xffff, 0xffff, 0xff5d, 0xe924, 0xe800, 0xe904, 0xe904, 0xe8c3, 0xe800, 0xff3c, 0xffff, 0xe8e4, 0xe800, 0xfe18, 0xffff,
    0xffff, 0xffff, 0xffff, 0xffff, 0xff9e, 0xe924, 0xe800, 0xe904, 0xe904, 0xe8c3, 0xe800, 0xff7e, 0xffff, 0xffff, 0xffff, 0xffff,
    0xffff, 0xff7d, 0xe966, 0xe882, 0xe925, 0xe924, 0xe8c3, 0xe841, 0xfe59, 0xe986, 0xe882, 0xe800, 0xfedb, 0xffff, 0xffff, 0xffff,
    0xffff, 0xffff, 0xff7d, 0xe966, 0xe882, 0xe925, 0xe924, 0xe8c3, 0xe800, 0xfefb, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xff1c,
    0xe986, 0xe800, 0xe924, 0xe904, 0xe904, 0xe841, 0xe965, 0xe924, 0xe8a2, 0xe800, 0xfe59, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff,
    0xff9e, 0xe986, 0xe800, 0xe924, 0xe904, 0xe904, 0xe862, 0xfe79, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xff5d, 0xe924, 0xe800,
    0xe904, 0xe904, 0xe8c3, 0xe9c7, 0xe904, 0xe966, 0xe904, 0xe861, 0xfedb, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xff5d, 0xe924,
    0xe800, 0xe904, 0xe904, 0xe8c3, 0xe800, 0xfeba, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xff7d, 0xe966, 0xe882, 0xe925, 0xe924};

#endif
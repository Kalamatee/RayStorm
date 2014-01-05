#include <stdio.h>

#define XSIZE 64
#define YSIZE 64

unsigned int palData[] =
{
	0xf9f9f9f9,0xf9f9f9f9,0xf9f9f9f9,0xf3f3f3f3,0xf3f3f3f3,
	0xf3f3f3f3,0xcccccccc,0xffffffff,0xffffffff,0xffffffff,0xcccccccc,
	0xffffffff,0xffffffff,0xffffffff,0xcccccccc,0xe8e8e8e8,0xe8e8e8e8,
	0xe8e8e8e8,0xffffffff,0x99999999,0xffffffff,0xffffffff,0xffffffff,
	0x99999999,0xe2e2e2e2,0xe2e2e2e2,0xe2e2e2e2,0xcccccccc,0xcccccccc,
	0xffffffff,0xcccccccc,0xffffffff,0xcccccccc,0xffffffff,0xcccccccc,
	0xcccccccc,0xffffffff,0x66666666,0xffffffff,0xffffffff,0xffffffff,
	0x66666666,0xd7d7d7d7,0xd7d7d7d7,0xd7d7d7d7,0xffffffff,0x33333333,
	0xffffffff,0xffffffff,0xffffffff,0x33333333,0xd1d1d1d1,0xd1d1d1d1,
	0xd1d1d1d1,0xcccccccc,0x99999999,0xffffffff,0xcccccccc,0xffffffff,
	0x99999999,0xffffffff,0x99999999,0xcccccccc,0xffffffff,0xcccccccc,
	0x99999999,0xc6c6c6c6,0xc6c6c6c6,0xc6c6c6c6,0xcccccccc,0x66666666,
	0xffffffff,0xcccccccc,0xffffffff,0x66666666,0xffffffff,0x66666666,
	0xcccccccc,0xffffffff,0xcccccccc,0x66666666,0xffffffff,0x99999999,
	0x99999999,0xc0c0c0c0,0xc0c0c0c0,0xc0c0c0c0,0xcccccccc,0x33333333,
	0xffffffff,0xcccccccc,0xffffffff,0x33333333,0xffffffff,0x33333333,
	0xcccccccc,0xffffffff,0xcccccccc,0x33333333,0xcccccccc,0x99999999,
	0xcccccccc,0xcccccccc,0xcccccccc,0x99999999,0xcccccccc,0xffffffff,
	0x00000000,0xffffffff,0x00000000,0xcccccccc,0xffffffff,0xcccccccc,
	0x00000000,0x84848484,0x94949494,0xffffffff,0x7b7b7b7b,0x8c8c8c8c,
	0xffffffff,0xffffffff,0x66666666,0x99999999,0xffffffff,0x99999999,
	0x66666666,0xb5b5b5b5,0xb5b5b5b5,0xb5b5b5b5,0x73737373,0x8c8c8c8c,
	0xffffffff,0x73737373,0x84848484,0xffffffff,0x6b6b6b6b,0x84848484,
	0xffffffff,0xcccccccc,0x66666666,0xcccccccc,0xcccccccc,0xcccccccc,
	0x66666666,0xafafafaf,0xafafafaf,0xafafafaf,0x6b6b6b6b,0x7b7b7b7b,
	0xffffffff,0xffffffff,0x33333333,0x99999999,0xffffffff,0x99999999,
	0x33333333,0x63636363,0x7b7b7b7b,0xffffffff,0xcccccccc,0x99999999,
	0x99999999,0xffffffff,0x00000000,0x99999999,0xffffffff,0x99999999,
	0x00000000,0x63636363,0x73737373,0xffffffff,0x5a5a5a5a,0x73737373,
	0xffffffff,0xffffffff,0x66666666,0x66666666,0x5a5a5a5a,0x6b6b6b6b,
	0xffffffff,0xcccccccc,0xcccccccc,0x00000000,0x52525252,0x6b6b6b6b,
	0xffffffff,0xa4a4a4a4,0xa4a4a4a4,0xa4a4a4a4,0x4a4a4a4a,0x63636363,
	0xffffffff,0xffffffff,0x33333333,0x66666666,0xffffffff,0x66666666,
	0x33333333,0x42424242,0x5a5a5a5a,0xffffffff,0x6b6b6b6b,0x7b7b7b7b,
	0xdededede,0xcccccccc,0x66666666,0x99999999,0xcccccccc,0x99999999,
	0x66666666,0xffffffff,0x00000000,0x66666666,0xffffffff,0x66666666,
	0x00000000,0x39393939,0x52525252,0xffffffff,0x9e9e9e9e,0x9e9e9e9e,
	0x9e9e9e9e,0x31313131,0x4a4a4a4a,0xffffffff,0x6b6b6b6b,0x7b7b7b7b,
	0xd6d6d6d6,0x63636363,0x73737373,0xdededede,0x29292929,0x4a4a4a4a,
	0xffffffff,0x29292929,0x42424242,0xffffffff,0x4a4a4a4a,0x5a5a5a5a,
	0xefefefef,0xffffffff,0x33333333,0x33333333,0x31313131,0x4a4a4a4a,
	0xf7f7f7f7,0x63636363,0x73737373,0xd6d6d6d6,0xbdbdbdbd,0xa5a5a5a5,
	0x4a4a4a4a,0xcccccccc,0x33333333,0x99999999,0xcccccccc,0x99999999,
	0x33333333,0xffffffff,0x00000000,0x33333333,0xffffffff,0x33333333,
	0x00000000,0x29292929,0x42424242,0xf7f7f7f7,0x21212121,0x42424242,
	0xf7f7f7f7,0x63636363,0x73737373,0xcececece,0x21212121,0x39393939,
	0xf7f7f7f7,0xcccccccc,0x99999999,0x00000000,0x31313131,0x4a4a4a4a,
	0xefefefef,0x93939393,0x93939393,0x93939393,0x18181818,0x31313131,
	0xf7f7f7f7,0x63636363,0x6b6b6b6b,0xcececece,0xb5b5b5b5,0x9c9c9c9c,
	0x4a4a4a4a,0xcccccccc,0x66666666,0x66666666,0x5a5a5a5a,0x6b6b6b6b,
	0xcececece,0x21212121,0x39393939,0xefefefef,0x18181818,0x39393939,
	0xefefefef,0x18181818,0x31313131,0xefefefef,0x8d8d8d8d,0x8d8d8d8d,
	0x8d8d8d8d,0xadadadad,0x9c9c9c9c,0x42424242,0x18181818,0x39393939,
	0xe7e7e7e7,0x18181818,0x31313131,0xe7e7e7e7,0xcccccccc,0x33333333,
	0x66666666,0xcccccccc,0x66666666,0x33333333,0xa5a5a5a5,0x94949494,
	0x4a4a4a4a,0xa5a5a5a5,0x94949494,0x42424242,0x18181818,0x31313131,
	0xdededede,0xcccccccc,0x66666666,0x00000000,0x82828282,0x82828282,
	0x82828282,0x9c9c9c9c,0x94949494,0x42424242,0x52525252,0x5a5a5a5a,
	0xbdbdbdbd,0x21212121,0x39393939,0xd6d6d6d6,0x4a4a4a4a,0x5a5a5a5a,
	0xbdbdbdbd,0x21212121,0x31313131,0xd6d6d6d6,0x18181818,0x31313131,
	0xd6d6d6d6,0x9c9c9c9c,0x8c8c8c8c,0x42424242,0x4a4a4a4a,0x52525252,
	0xbdbdbdbd,0x10101010,0x29292929,0xd6d6d6d6,0x4a4a4a4a,0x5a5a5a5a,
	0xb5b5b5b5,0x7c7c7c7c,0x7c7c7c7c,0x7c7c7c7c,0x18181818,0x31313131,
	0xcececece,0x10101010,0x29292929,0xcececece,0xcccccccc,0x33333333,
	0x00000000,0x94949494,0x84848484,0x42424242,0x94949494,0x84848484,
	0x39393939,0x18181818,0x29292929,0xc6c6c6c6,0x10101010,0x29292929,
	0xc6c6c6c6,0x42424242,0x52525252,0xadadadad,0x73737373,0x73737373,
	0x73737373,0x21212121,0x31313131,0xbdbdbdbd,0x71717171,0x71717171,
	0x71717171,0x8c8c8c8c,0x7b7b7b7b,0x39393939,0x10101010,0x29292929,
	0xbdbdbdbd,0x18181818,0x31313131,0xb5b5b5b5,0x18181818,0x29292929,
	0xb5b5b5b5,0x39393939,0x42424242,0xa5a5a5a5,0x10101010,0x29292929,
	0xb5b5b5b5,0x6b6b6b6b,0x6b6b6b6b,0x6b6b6b6b,0x6b6b6b6b,0x6b6b6b6b,
	0x6b6b6b6b,0x10101010,0x21212121,0xb5b5b5b5,0x31313131,0x42424242,
	0xa5a5a5a5,0x10101010,0x29292929,0xadadadad,0x10101010,0x21212121,
	0xadadadad,0x31313131,0x42424242,0x9c9c9c9c,0x7b7b7b7b,0x6b6b6b6b,
	0x39393939,0x63636363,0x63636363,0x63636363,0x10101010,0x21212121,
	0xa5a5a5a5,0x73737373,0x6b6b6b6b,0x39393939,0x5a5a5a5a,0x5a5a5a5a,
	0x6b6b6b6b,0x60606060,0x60606060,0x60606060,0x29292929,0x39393939,
	0x94949494,0x18181818,0x29292929,0x9c9c9c9c,0x73737373,0x63636363,
	0x39393939,0x63636363,0x5a5a5a5a,0x5a5a5a5a,0x29292929,0x31313131,
	0x94949494,0x73737373,0x63636363,0x31313131,0x6b6b6b6b,0x63636363,
	0x39393939,0x5a5a5a5a,0x5a5a5a5a,0x5a5a5a5a,0x5a5a5a5a,0x5a5a5a5a,
	0x5a5a5a5a,0x6b6b6b6b,0x63636363,0x31313131,0x10101010,0x21212121,
	0x94949494,0x21212121,0x31313131,0x8c8c8c8c,0x6b6b6b6b,0x63636363,
	0x29292929,0x21212121,0x29292929,0x8c8c8c8c,0x52525252,0x52525252,
	0x5a5a5a5a,0x6b6b6b6b,0x5a5a5a5a,0x29292929,0x10101010,0x21212121,
	0x8c8c8c8c,0x63636363,0x5a5a5a5a,0x31313131,0x52525252,0x52525252,
	0x52525252,0x63636363,0x5a5a5a5a,0x29292929,0x31313131,0x39393939,
	0x73737373,0x10101010,0x21212121,0x84848484,0x4f4f4f4f,0x4f4f4f4f,
	0x4f4f4f4f,0x10101010,0x18181818,0x84848484,0x5a5a5a5a,0x52525252,
	0x39393939,0x08080808,0x18181818,0x84848484,0x31313131,0x39393939,
	0x6b6b6b6b,0x18181818,0x21212121,0x7b7b7b7b,0x52525252,0x4a4a4a4a,
	0x42424242,0x10101010,0x21212121,0x7b7b7b7b,0x4a4a4a4a,0x4a4a4a4a,
	0x4a4a4a4a,0x49494949,0x49494949,0x49494949,0x10101010,0x18181818,
	0x7b7b7b7b,0x08080808,0x18181818,0x7b7b7b7b,0x31313131,0x39393939,
	0x63636363,0x31313131,0x31313131,0x63636363,0x4a4a4a4a,0x4a4a4a4a,
	0x39393939,0x42424242,0x42424242,0x4a4a4a4a,0x10101010,0x18181818,
	0x73737373,0x29292929,0x31313131,0x63636363,0x52525252,0x4a4a4a4a,
	0x29292929,0x08080808,0x18181818,0x73737373,0x42424242,0x42424242,
	0x42424242,0x21212121,0x29292929,0x63636363,0x08080808,0x18181818,
	0x6b6b6b6b,0x3e3e3e3e,0x3e3e3e3e,0x3e3e3e3e,0x4a4a4a4a,0x42424242,
	0x21212121,0x21212121,0x29292929,0x5a5a5a5a,0x39393939,0x39393939,
	0x39393939,0x38383838,0x38383838,0x38383838,0x10101010,0x18181818,
	0x5a5a5a5a,0x39393939,0x39393939,0x31313131,0x08080808,0x10101010,
	0x5a5a5a5a,0x18181818,0x21212121,0x52525252,0x42424242,0x39393939,
	0x10101010,0x31313131,0x31313131,0x31313131,0x08080808,0x10101010,
	0x52525252,0x39393939,0x31313131,0x21212121,0x10101010,0x18181818,
	0x4a4a4a4a,0x39393939,0x31313131,0x18181818,0x2d2d2d2d,0x2d2d2d2d,
	0x2d2d2d2d,0x39393939,0x31313131,0x10101010,0x08080808,0x10101010,
	0x4a4a4a4a,0x29292929,0x29292929,0x29292929,0x10101010,0x10101010,
	0x42424242,0x08080808,0x10101010,0x42424242,0x31313131,0x29292929,
	0x18181818,0x27272727,0x27272727,0x27272727,0x31313131,0x29292929,
	0x10101010,0x29292929,0x29292929,0x18181818,0x29292929,0x21212121,
	0x21212121,0x08080808,0x10101010,0x39393939,0x22222222,0x22222222,
	0x22222222,0x08080808,0x08080808,0x39393939,0x29292929,0x21212121,
	0x18181818,0x00000000,0x08080808,0x39393939,0x21212121,0x21212121,
	0x21212121,0x29292929,0x21212121,0x10101010,0x21212121,0x21212121,
	0x18181818,0x21212121,0x21212121,0x10101010,0x1c1c1c1c,0x1c1c1c1c,
	0x1c1c1c1c,0x21212121,0x21212121,0x08080808,0x21212121,0x18181818,
	0x10101010,0x21212121,0x18181818,0x08080808,0x18181818,0x18181818,
	0x18181818,0x16161616,0x16161616,0x16161616,0x18181818,0x18181818,
	0x10101010,0x18181818,0x18181818,0x08080808,0x00000000,0x08080808,
	0x21212121,0x00000000,0x00000000,0x21212121,0x18181818,0x10101010,
	0x08080808,0x11111111,0x11111111,0x11111111,0x10101010,0x10101010,
	0x10101010,0x10101010,0x10101010,0x08080808,0x00000000,0x00000000,
	0x18181818,0x0b0b0b0b,0x0b0b0b0b,0x0b0b0b0b,0x00000000,0x00000000,
	0x10101010,0x08080808,0x08080808,0x08080808,0x05050505,0x05050505,
	0x05050505,0x00000000,0x00000000,0x08080808,0x00000000,0x00000000,
	0x00000000,0x00000000,
};

unsigned char myData[] =
{
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xef,0xef,
	0xef,0xef,0xef,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xf7,0xc5,0xcb,0xff,0xff,0xff,0xf7,0xf7,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xda,0xb9,0xb9,0xad,0xad,0xcb,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf7,0xa2,0xad,0xad,
	0xc5,0xf7,0xff,0xda,0xa2,0xef,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xda,0xb9,0xc5,0xcb,0xa2,0xad,0xda,0xef,0xc5,0xb9,0xcb,0xf7,0xf7,0xda,
	0xf7,0xf7,0xda,0xef,0xad,0xa2,0xd2,0xc5,0xad,0xf7,0xd2,0xad,0xa2,0xd2,
	0xff,0xda,0xc5,0xa2,0xda,0xff,0xf7,0xda,0xda,0xe7,0xf7,0xda,0xd2,0xcb,
	0xc5,0xda,0xad,0xcb,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xc5,0xb9,0xc5,0xcb,0xad,0xa2,
	0xd2,0xa2,0xb9,0xad,0xad,0xda,0xda,0xad,0xda,0xd2,0xad,0xef,0x96,0xad,
	0x96,0xad,0xf7,0xff,0x8e,0xa2,0x9e,0xd2,0xe7,0xa2,0xa2,0xa2,0xad,0xef,
	0xda,0xa2,0xa2,0xda,0xda,0xa2,0x96,0xad,0xa2,0xa2,0xad,0xad,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xb9,0xb9,0xad,0xad,0xa2,0xf7,0xda,0xa2,0x96,0xad,0xad,0xcb,
	0xff,0xa2,0xcb,0xad,0xda,0xff,0xc5,0xa2,0xa2,0xa2,0xa2,0xff,0xb9,0xa2,
	0xc5,0xef,0xb9,0xa2,0xd2,0xda,0xa2,0xd2,0xda,0xa2,0xb9,0xf7,0xd2,0xa2,
	0xd2,0xa2,0x96,0xa2,0x96,0xad,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xef,0xa2,0xad,0xb9,0xad,
	0xa2,0xff,0xc5,0xad,0xc5,0x96,0xad,0xd2,0xff,0xa2,0xa2,0x96,0xf7,0xda,
	0xa2,0xda,0xb9,0xa2,0x96,0xff,0xda,0xa2,0xd2,0xff,0x96,0x8e,0xff,0x8e,
	0x8e,0xff,0x96,0xa2,0xef,0xff,0xda,0xa2,0xd2,0xad,0x96,0xe7,0xad,0xcb,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xda,0xad,0xad,0xf7,0xa2,0xa2,0xef,0xad,0xad,0xa2,0xa2,
	0xa2,0xff,0xff,0xc5,0xad,0xda,0xff,0xe7,0xa2,0xa2,0xa2,0xa2,0xe7,0xff,
	0xda,0xa2,0x96,0xcb,0xd2,0x96,0x96,0xa2,0xda,0xff,0x85,0x96,0xff,0xff,
	0xad,0x96,0xe7,0x96,0xa2,0xd2,0xa2,0xda,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xef,0xda,0xda,
	0xff,0xd2,0xda,0xfc,0xf7,0xa2,0xb9,0xd2,0xd2,0xef,0xda,0xc5,0xb9,0xef,
	0xff,0xff,0xda,0xda,0xda,0xd2,0xff,0xff,0xf7,0x96,0xb9,0xff,0xf7,0xb9,
	0xb9,0xe7,0xff,0xf7,0xd2,0xd2,0xff,0xff,0xda,0xd2,0xfc,0xda,0xef,0xef,
	0xda,0xf7,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xda,0xad,0xa9,0xd2,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf7,0xe7,0xfc,
	0xff,0xff,0xf7,0xe7,0xef,0xda,0xc5,0xcb,0xcb,0xcb,0xcb,0xc5,0xda,0xef,
	0xe7,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xe7,0xd2,0xcb,0xcb,0xcb,0xcb,
	0xcb,0xcb,0xcb,0xcb,0xcb,0xcb,0xcb,0xcb,0xcb,0xcb,0xef,0xf7,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xfc,0xd2,0xcb,0xcb,0xcb,0xd2,0xe7,0xef,0xef,0xf7,0xf7,0xf7,0xf7,0xef,
	0xef,0xda,0xcb,0xcb,0xcb,0xcb,0xda,0xf7,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xf7,0xd2,0xcb,0xcb,0xcb,0xe7,0xf7,0xfc,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfc,0xf7,0xd2,0xcb,
	0xcb,0xcb,0xe7,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf7,
	0xda,0xcb,0xcb,0xe7,0xfc,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xfc,0xf7,0xd2,0xcb,0xcb,0xd2,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xfc,0xcb,0xcb,0xd2,0xef,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xfc,0xe7,0xcb,0xcb,0xda,0xf7,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfc,
	0xcb,0xcb,0xd2,0xfc,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xef,0xcb,
	0xcb,0xda,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xf7,0xda,0xcb,0xd2,0xfc,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xef,0xcb,0xcb,0xd2,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xd2,0xd2,0xd2,0xfc,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xe7,0xcb,0xcb,0xe7,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xe7,0xd2,0xd2,0xef,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xda,0xc5,0xc5,
	0xf7,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xf7,0xcb,0xd2,0xe7,0xff,0xff,0xff,0xff,0xe2,0xf9,0xff,0xff,0xff,0xff,
	0xff,0xff,0xf8,0xfc,0xff,0xf5,0xe9,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xc2,0xc2,0xff,0xff,0xff,0xfc,0xcb,0xc5,0xd2,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xe7,0xd2,0xd2,0xfc,0xff,0xff,
	0xff,0xc1,0x8b,0xff,0xff,0xff,0xff,0xff,0xff,0xe0,0xe0,0xdd,0xf5,0x98,
	0xa1,0xc3,0xf1,0xff,0xff,0xff,0xff,0xff,0xc2,0x2c,0xc2,0xff,0xff,0xff,
	0xef,0xc5,0xc5,0xf7,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xcb,0xd2,0xef,0xff,0xff,0xff,0xff,0x8b,0xd3,0xff,0xff,0xff,
	0xff,0xfc,0xe0,0xff,0xff,0xff,0xea,0xae,0xac,0x98,0x98,0xe9,0xff,0xff,
	0xff,0xff,0xff,0x52,0x60,0xff,0xc2,0xff,0xfc,0xcb,0xc5,0xe7,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xe7,0xd2,0xd2,0xfc,0xff,
	0xe6,0x69,0xc1,0x64,0xf9,0xff,0xff,0xff,0xff,0xe0,0xf2,0xff,0xff,0xff,
	0xa0,0x78,0xa0,0xae,0xac,0x98,0xf1,0xff,0xff,0xff,0xff,0x52,0x27,0x52,
	0x27,0xff,0xff,0xf7,0xc5,0xc5,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xef,0xd2,0xe7,0xff,0xff,0x92,0x69,0x64,0x7d,0xff,0xff,
	0xff,0xff,0xff,0xf5,0xff,0xff,0xff,0xc9,0x78,0x72,0x72,0x72,0xa0,0x95,
	0xd4,0xff,0xff,0xff,0xff,0xaf,0x27,0x27,0x27,0x63,0xff,0xfc,0xc5,0xc5,
	0xe7,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xc5,0xd2,0xf7,
	0xff,0xff,0xe6,0x92,0x64,0xa5,0xff,0xff,0xff,0xff,0xfc,0xf7,0xff,0xff,
	0xff,0xec,0x68,0x53,0x61,0x6e,0x78,0x80,0xe5,0xf8,0xff,0xff,0xff,0xfe,
	0x26,0x27,0x5a,0xff,0xff,0xff,0xda,0xc5,0xe7,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xf7,0xd2,0xd2,0xf7,0xff,0xff,0xff,0xff,0x8b,0xa5,
	0xff,0xff,0xff,0xff,0xf1,0xce,0xff,0xff,0xff,0xff,0xd8,0xd1,0x81,0x68,
	0x6e,0xa7,0xf5,0xff,0xff,0xff,0xff,0xfe,0x26,0x4b,0xff,0xff,0xff,0xff,
	0xe7,0xc5,0xd2,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xe7,0xd2,
	0xd2,0xff,0xe6,0xc4,0xfb,0xff,0xc1,0x7d,0xff,0xff,0xff,0xff,0xf1,0xb3,
	0x9d,0xf2,0xff,0xff,0xff,0xff,0xe8,0x61,0x6e,0xc9,0xff,0xff,0xff,0xff,
	0xff,0x43,0x26,0x4b,0xff,0xbe,0xc2,0xff,0xef,0xc5,0xc5,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xef,0xd2,0xd2,0xff,0xc4,0x6a,0x82,0xc4,
	0xc1,0x64,0xf9,0xff,0xff,0xff,0xfc,0xb7,0xa4,0xd6,0xff,0xff,0xff,0xff,
	0xe8,0x6e,0x6d,0xae,0xff,0xff,0xff,0xff,0xff,0x43,0x26,0x27,0x4c,0x27,
	0x2c,0xff,0xf7,0xc5,0xc5,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xef,0xd2,0xd2,0xff,0xc4,0x6a,0x6a,0x65,0x64,0x64,0xb8,0xff,0xff,0xff,
	0xff,0xe1,0xbf,0xff,0xff,0xff,0xff,0xff,0xdf,0x6e,0x88,0xc9,0xff,0xff,
	0xff,0xff,0xff,0x26,0x27,0x27,0x27,0x2b,0x2c,0xff,0xf7,0xc5,0xc5,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xef,0xd2,0xd2,0xff,0xff,0xe6,
	0xc4,0x92,0x64,0x64,0x7d,0xf9,0xff,0xff,0xff,0xfc,0xe9,0xff,0xff,0xff,
	0xe8,0xff,0xff,0xaa,0xd6,0xf5,0xff,0xff,0xff,0xff,0xaf,0x27,0x27,0x27,
	0x27,0x63,0xc2,0xff,0xf7,0xc5,0xc5,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xef,0xd2,0xd2,0xff,0xff,0xff,0xff,0xff,0xe4,0x64,0x59,0xb8,
	0xff,0xff,0xff,0xff,0xfc,0xff,0xff,0xff,0xed,0xff,0xff,0xee,0xff,0xff,
	0xff,0xff,0xff,0xff,0x27,0x27,0x27,0xbd,0xff,0xff,0xff,0xff,0xf7,0xcb,
	0xc5,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xe7,0xd2,0xd2,0xff,
	0xff,0xc4,0xd9,0xff,0xff,0xc1,0x5b,0x76,0xf9,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xb5,0x27,0x27,
	0xbe,0xff,0xfe,0x73,0xca,0xff,0xef,0xcb,0xc5,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xda,0xd2,0xd2,0xfc,0xff,0xc4,0x6a,0x6a,0x65,0xb0,
	0x64,0x58,0x86,0xff,0xff,0xff,0xff,0xff,0xff,0xfc,0xf8,0xe9,0xf8,0xff,
	0xff,0xff,0xff,0xff,0xc2,0x2c,0x2c,0x2c,0x2c,0x2c,0x2d,0x31,0xca,0xff,
	0xef,0xcb,0xd2,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xcb,
	0xd2,0xef,0xff,0xe6,0x6a,0x6a,0x69,0x64,0x64,0x59,0x58,0xcf,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x2d,0x2c,
	0x2c,0x2c,0x2d,0x31,0x31,0x31,0xff,0xff,0xe7,0xcb,0xef,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xd2,0xd2,0xe7,0xff,0xff,0x93,0xc4,
	0xc4,0xc1,0xc1,0x8a,0x58,0x74,0xb6,0xdc,0xff,0xff,0xf9,0xdc,0xb2,0xc1,
	0xd3,0xff,0xff,0xff,0xc6,0x79,0x31,0x31,0x31,0x75,0x7b,0x7b,0x34,0x84,
	0xff,0xfc,0xd2,0xcb,0xe7,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xe7,0xd2,0xd2,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xbb,0x59,0x58,
	0x4d,0x4a,0x9c,0xcd,0xb4,0x89,0x77,0x6f,0x83,0xbc,0x8c,0x3b,0x38,0x38,
	0x34,0x34,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf7,0xcb,0xcb,0xf7,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf7,0xcb,0xd2,0xef,0xff,
	0xff,0xff,0xff,0xff,0xdc,0x64,0x5b,0x8a,0x4e,0x4a,0x4a,0x8b,0x93,0x7e,
	0x66,0x5f,0x6a,0x7a,0x3f,0x3b,0x3b,0x3b,0x39,0x39,0x39,0xd0,0xff,0xff,
	0xff,0xff,0xff,0xe7,0xcb,0xda,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xd2,0xd2,0xda,0xff,0xff,0xff,0xe6,0x92,0x65,0x64,
	0x64,0xe2,0xff,0xb8,0x4a,0xbc,0x89,0x7a,0x4a,0x3f,0x5f,0x6f,0x48,0x3d,
	0x94,0xff,0x91,0x3b,0x3b,0x3b,0x94,0xff,0xff,0xff,0xfc,0xcb,0xcb,0xe7,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf7,0xd2,
	0xd2,0xef,0xff,0xff,0xe6,0x92,0x6a,0x64,0xab,0xff,0xff,0x58,0x4d,0xb4,
	0x8d,0x7e,0x4a,0x42,0x66,0x7a,0x51,0x3f,0x9b,0xff,0xfe,0x3d,0x3d,0x3d,
	0x4f,0xff,0xff,0xff,0xe7,0xcb,0xda,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xd2,0xd2,0xd2,0xfc,0xff,0xff,0xff,
	0x92,0x69,0xe4,0xff,0xff,0x58,0x58,0xbb,0x97,0x83,0x66,0x6f,0x6f,0x89,
	0x5d,0x42,0x9f,0xff,0xff,0x9b,0x3f,0xd5,0xff,0xff,0xff,0xf7,0xcb,0xcb,
	0xfc,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xf7,0xcb,0xd2,0xda,0xfc,0xff,0xff,0xff,0xc4,0xff,0xff,0xff,0x5b,
	0x58,0x8b,0xbb,0x97,0x90,0x7a,0x89,0x97,0x5d,0x42,0xa6,0xff,0xff,0xd5,
	0xd5,0xff,0xff,0xff,0xfc,0xd2,0xcb,0xda,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfc,0xd2,0xd2,0xe7,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xc1,0xb8,0xe2,0xe6,0xc7,0xb0,0xb2,
	0xbc,0xf3,0xdb,0xa8,0xdb,0xff,0xff,0xff,0xff,0xff,0xff,0xfc,0xd2,0xcb,
	0xda,0xf7,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xe7,0xd2,0xd2,0xe7,0xfc,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xfb,0xf4,0xf4,0xfe,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xfc,0xd2,0xcb,0xcb,0xf7,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xcb,0xd2,0xd2,0xda,0xfc,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf7,0xd2,0xcb,
	0xcb,0xfc,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xe7,0xd2,0xd2,0xd2,0xef,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xfc,0xe7,0xcb,0xcb,0xda,0xfc,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xfc,0xcb,0xd2,0xd2,0xda,0xef,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfc,0xef,0xd2,0xcb,0xcb,
	0xda,0xf7,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf7,
	0xd2,0xcb,0xd2,0xd2,0xd2,0xe7,0xef,0xfc,0xff,0xff,0xff,0xff,0xff,0xff,
	0xf7,0xf7,0xe7,0xd2,0xcb,0xcb,0xcb,0xe7,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf7,0xd2,0xcb,0xcb,0xd2,
	0xcb,0xcb,0xd2,0xd2,0xd2,0xd2,0xd2,0xd2,0xcb,0xcb,0xcb,0xcb,0xcb,0xe7,
	0xf7,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xf7,0xe7,0xd2,0xcb,0xcb,0xcb,0xcb,0xcb,0xcb,
	0xcb,0xcb,0xcb,0xc5,0xef,0xe7,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xe7,0xd2,0xf7,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xda,0xe7,0xef,0xef,0xef,0xe7,0xe7,0xf7,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf7,0xad,0xa2,0xda,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfc,0xe7,0xd2,0xff,0xff,0xff,
	0xff,0xef,0xe7,0xef,0xff,0xff,0xff,0xf7,0xe7,0xf7,0xff,0xff,0xd2,0xd2,
	0xda,0xd2,0xef,0xff,0xff,0xff,0xda,0xd2,0xef,0xff,0xff,0xd2,0xd2,0xda,
	0xda,0xda,0x8e,0xa2,0xf7,0xff,0xfc,0xe7,0xd2,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xf7,0xb9,0xb9,0xad,0xc5,0xff,0xf7,0xcb,0xad,0xad,0x96,0xf7,0xff,
	0xd2,0xad,0xa2,0xa9,0xf7,0xff,0xad,0xa9,0xad,0xad,0xa2,0xfc,0xf7,0xcb,
	0x99,0xad,0xad,0xd2,0xff,0xad,0xad,0xad,0xc0,0xe7,0x96,0x96,0xff,0xb9,
	0xad,0xad,0xad,0xcb,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfc,0xb9,0xad,0xb9,0xa2,0xb9,
	0xff,0xc5,0xad,0xcb,0xad,0xad,0xd2,0xe7,0xad,0xad,0xad,0xad,0xb9,0xef,
	0xad,0xa2,0xa2,0xa2,0xad,0xd2,0xad,0x96,0xad,0xad,0xad,0xda,0xf7,0x96,
	0xad,0xad,0xda,0xda,0xad,0xc5,0xfc,0xb9,0xad,0xb9,0xb9,0xad,0xda,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xef,0xad,0xb9,0xad,0xad,0xb9,0xda,0xad,0xad,0xff,0xef,0xd2,
	0xef,0xad,0xad,0xa2,0xa2,0xad,0xc5,0xda,0xad,0xa2,0xf7,0xad,0x96,0xf7,
	0xc5,0x96,0x85,0xa2,0xad,0xcb,0xe7,0xad,0xad,0xc5,0xf7,0xc5,0xad,0xd2,
	0xd2,0xad,0xad,0xda,0xc5,0xad,0xda,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xda,0xad,0xb9,0xad,
	0xb9,0xad,0xcb,0xad,0xad,0xd2,0xc5,0xb9,0xe7,0x96,0xa2,0xad,0xc5,0x96,
	0xd2,0xda,0xad,0xda,0xda,0xad,0xa2,0xd2,0xa2,0xb9,0xa2,0xad,0xad,0xda,
	0xd2,0xad,0xad,0xff,0xff,0xb9,0xad,0xd2,0xda,0xad,0xcb,0xda,0xa2,0xad,
	0xe7,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xb9,0xb9,0xad,0xad,0xb9,0x96,0xda,0xad,0xad,0xb9,
	0xad,0xc5,0xf7,0xad,0xad,0xb9,0xb9,0xc5,0xf7,0xda,0xad,0xda,0xda,0xad,
	0xda,0xda,0xad,0xa2,0xcb,0xad,0xa2,0xf7,0xda,0xad,0xcb,0xff,0xf7,0xa2,
	0xad,0xda,0xe7,0xad,0xad,0x96,0xad,0xc5,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xda,0xc5,
	0xb9,0xb9,0xcb,0xda,0xfc,0xcb,0xad,0xad,0xc5,0xf7,0xff,0xd2,0xad,0xad,
	0xad,0xef,0xff,0xad,0xad,0xd2,0xcb,0xad,0xd2,0xe7,0xad,0xad,0x96,0xad,
	0x8e,0xff,0xcb,0xad,0xd2,0xff,0xda,0xa2,0xa2,0xf7,0xf7,0xd2,0xad,0xad,
	0xcb,0xf7,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfc,0xef,0xfc,0xff,0xff,0xff,0xff,
	0xef,0xfc,0xff,0xff,0xff,0xff,0xfc,0xef,0xfc,0xff,0xff,0xff,0xe7,0xf7,
	0xff,0xf7,0xf7,0xff,0xf7,0xe7,0xfc,0xe7,0xff,0xff,0xff,0xf7,0xf7,0xff,
	0xff,0xf7,0xda,0xff,0xff,0xff,0xe7,0xf7,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
};

void main(void)
{
	int x,y;
	int index;

	for(y=0; y<XSIZE; y++)
	{
		for(x=0; x<YSIZE; x++)
		{
			index = myData[y*XSIZE + x];
			printf("0x%02x,0x%02x,0x%02x, ", palData[index*3] & 0xff, palData[index*3+1] & 0xff, palData[index*3+2] & 0xff);
			if(((y*XSIZE + x) % 4) == 3)
				printf("\n	");
		}
	}
}
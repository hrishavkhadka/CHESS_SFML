#ifndef EVAL_H
#define EVAL_H

extern const int mg_table_white[6][8][8];
extern const int mg_table_black[6][8][8];
extern const int eg_table_white[6][8][8];
extern const int eg_table_black[6][8][8];
/*
extern const int mg_table_white[6][8][8] =    //in order of p n b r q k
{
{

{82,    82,     82,     82,     82,     82,     82,     82      },

{71,    116,    208,    150,    177,    143,    216,    180     },

{62,    107,    138,    147,    113,    108,    89,     76      },

{59,    99,     94,     105,    103,    88,     95,     68      },

{57,    92,     88,     99,     94,     77,     80,     55      },

{70,    115,    85,     85,     72,     78,     78,     56      },

{60,    120,    106,    67,     59,     62,     81,     47      },

{82,    82,     82,     82,     82,     82,     82,     82      }

},
{

{230,   322,    240,    398,    288,    303,    248,    170     },

{320,   344,    399,    360,    373,    409,    296,    264     },

{381,   410,    466,    421,    402,    374,    397,    290     },

{359,   355,    406,    374,    390,    356,    354,    328     },

{329,   358,    356,    365,    350,    353,    341,    324     },

{321,   362,    354,    356,    347,    349,    328,    314     },

{318,   323,    355,    336,    334,    325,    284,    308     },

{314,   318,    309,    320,    304,    279,    316,    232     }

},
{

{357,   372,    323,    340,    328,    283,    369,    336     },

{318,   383,    424,    395,    352,    347,    381,    339     },

{363,   402,    415,    400,    405,    408,    402,    349     },

{363,   372,    402,    402,    415,    384,    370,    361     },

{369,   375,    377,    399,    391,    378,    378,    359     },

{375,   383,    392,    379,    380,    380,    380,    365     },

{366,   398,    386,    372,    365,    381,    380,    369     },

{344,   326,    353,    352,    344,    351,    362,    332     }

},
{

{520,   508,    486,    540,    528,    509,    519,    509     },

{521,   503,    544,    557,    539,    535,    509,    504     },

{493,   538,    522,    494,    513,    503,    496,    472     },

{457,   469,    512,    501,    503,    484,    466,    453     },

{454,   483,    470,    486,    476,    465,    451,    441     },

{444,   472,    477,    480,    460,    461,    452,    432     },

{406,   471,    488,    476,    468,    457,    461,    433     },

{451,   440,    484,    493,    494,    478,    464,    458     }

},
{

{1070,  1068,   1069,   1084,   1037,   1054,   1025,   997     },

{1079,  1053,   1082,   1009,   1026,   1020,   986,    1001    },

{1082,  1072,   1081,   1054,   1033,   1032,   1008,   1012    },

{1026,  1023,   1042,   1024,   1009,   1009,   998,    998     },

{1022,  1028,   1021,   1023,   1015,   1016,   999,    1016    },

{1030,  1039,   1027,   1020,   1023,   1014,   1027,   1011    },

{1026,  1022,   1040,   1033,   1027,   1036,   1017,   990     },

{975,   994,    1000,   1010,   1035,   1016,   1007,   1024    }

},
{

{20013, 20002,  19966,  19944,  19985,  20016,  20023,  19935   },

{19971, 19962,  19996,  19992,  19993,  19980,  19999,  20029   },

{19978, 20022,  20006,  19980,  19984,  20002,  20024,  19991   },

{19964, 19986,  19975,  19970,  19973,  19988,  19980,  19983   },

{19949, 19967,  19956,  19954,  19961,  19973,  19999,  19951   },

{19973, 19985,  19970,  19956,  19954,  19978,  19986,  19986   },

{20008, 20009,  19984,  19957,  19936,  19992,  20007,  20001   },

{20014, 20024,  19972,  20008,  19946,  20012,  20036,  19985   }

}
};


extern const int mg_table_black[6][8][8] =
{
{

{82,    47,     56,     55,     68,     76,     180,    82      },

{82,    81,     78,     80,     95,     89,     216,    82      },

{82,    62,     78,     77,     88,     108,    143,    82      },

{82,    59,     72,     94,     103,    113,    177,    82      },

{82,    67,     85,     99,     105,    147,    150,    82      },

{82,    106,    85,     88,     94,     138,    208,    82      },

{82,    120,    115,    92,     99,     107,    116,    82      },

{82,    60,     70,     57,     59,     62,     71,     82      }

},
{

{232,   308,    314,    324,    328,    290,    264,    170     },

{316,   284,    328,    341,    354,    397,    296,    248     },

{279,   325,    349,    353,    356,    374,    409,    303     },

{304,   334,    347,    350,    390,    402,    373,    288     },

{320,   336,    356,    365,    374,    421,    360,    398     },

{309,   355,    354,    356,    406,    466,    399,    240     },

{318,   323,    362,    358,    355,    410,    344,    322     },

{314,   318,    321,    329,    359,    381,    320,    230     }

},
{

{332,   369,    365,    359,    361,    349,    339,    336     },

{362,   380,    380,    378,    370,    402,    381,    369     },

{351,   381,    380,    378,    384,    408,    347,    283     },

{344,   365,    380,    391,    415,    405,    352,    328     },

{352,   372,    379,    399,    402,    400,    395,    340     },

{353,   386,    392,    377,    402,    415,    424,    323     },

{326,   398,    383,    375,    372,    402,    383,    372     },

{344,   366,    375,    369,    363,    363,    318,    357     }

},
{

{458,   433,    432,    441,    453,    472,    504,    509     },

{464,   461,    452,    451,    466,    496,    509,    519     },

{478,   457,    461,    465,    484,    503,    535,    509     },

{494,   468,    460,    476,    503,    513,    539,    528     },

{493,   476,    480,    486,    501,    494,    557,    540     },

{484,   488,    477,    470,    512,    522,    544,    486     },

{440,   471,    472,    483,    469,    538,    503,    508     },

{451,   406,    444,    454,    457,    493,    521,    520     }

},
{

{1024,  990,    1011,   1016,   998,    1012,   1001,   997     },

{1007,  1017,   1027,   999,    998,    1008,   986,    1025    },

{1016,  1036,   1014,   1016,   1009,   1032,   1020,   1054    },

{1035,  1027,   1023,   1015,   1009,   1033,   1026,   1037    },

{1010,  1033,   1020,   1023,   1024,   1054,   1009,   1084    },

{1000,  1040,   1027,   1021,   1042,   1081,   1082,   1069    },

{994,   1022,   1039,   1028,   1023,   1072,   1053,   1068    },

{975,   1026,   1030,   1022,   1026,   1082,   1079,   1070    }

},
{

{19985, 20001,  19986,  19951,  19983,  19991,  20029,  19935   },

{20036, 20007,  19986,  19999,  19980,  20024,  19999,  20023   },

{20012, 19992,  19978,  19973,  19988,  20002,  19980,  20016   },

{19946, 19936,  19954,  19961,  19973,  19984,  19993,  19985   },

{20008, 19957,  19956,  19954,  19970,  19980,  19992,  19944   },

{19972, 19984,  19970,  19956,  19975,  20006,  19996,  19966   },

{20024, 20009,  19985,  19967,  19986,  20022,  19962,  20002   },

{20014, 20008,  19973,  19949,  19964,  19978,  19971,  20013   }

}

};

extern const int eg_table_white[6][8][8] =
{
{

{94,    94,     94,     94,     94,     94,     94,     94      },

{281,   259,    226,    241,    228,    252,    267,    272     },

{178,   176,    147,    150,    161,    179,    194,    188     },

{111,   111,    98,     92,     99,     107,    118,    126     },

{93,    97,     86,     87,     87,     91,     103,    107     },

{86,    93,     89,     94,     95,     88,     101,    98      },

{87,    96,     94,     107,    104,    102,    102,    107     },

{94,    94,     94,     94,     94,     94,     94,     94      }

},
{

{182,   218,    254,    250,    253,    268,    243,    223     },

{229,   257,    256,    272,    279,    256,    273,    256     },

{240,   262,    272,    280,    290,    291,    261,    257     },

{263,   289,    292,    303,    303,    303,    284,    264     },

{263,   285,    298,    297,    306,    297,    275,    263     },

{259,   261,    278,    291,    296,    280,    278,    258     },

{237,   258,    261,    279,    276,    271,    261,    239     },

{217,   231,    263,    259,    266,    258,    230,    252     }

},
{

{273,   280,    288,    290,    289,    286,    276,    283     },

{283,   293,    284,    294,    285,    304,    293,    289     },

{301,   297,    303,    295,    296,    297,    289,    299     },

{299,   300,    307,    311,    306,    309,    306,    294     },

{288,   294,    307,    304,    316,    310,    300,    291     },

{282,   290,    300,    310,    307,    305,    294,    285     },

{270,   282,    288,    301,    296,    290,    279,    283     },

{280,   292,    281,    288,    292,    274,    288,    274     }

},
{

{517,   520,    524,    524,    527,    530,    522,    525     },

{515,   520,    515,    509,    523,    525,    525,    523     },

{509,   507,    509,    516,    517,    519,    519,    519     },

{514,   511,    513,    514,    513,    525,    515,    516     },

{501,   504,    506,    507,    516,    520,    517,    515     },

{496,   504,    500,    505,    511,    507,    512,    508     },

{509,   501,    503,    503,    514,    512,    506,    506     },

{492,   516,    499,    507,    511,    515,    514,    503     }

},
{

{956,   946,    955,    963,    963,    958,    958,    927     },

{936,   966,    961,    994,    977,    968,    956,    919     },

{945,   955,    971,    983,    985,    945,    942,    916     },

{972,   993,    976,    993,    981,    960,    958,    939     },

{959,   975,    970,    967,    983,    955,    964,    918     },

{941,   946,    953,    945,    942,    951,    909,    920     },

{904,   900,    913,    920,    920,    906,    913,    914     },

{895,   916,    904,    931,    893,    914,    908,    903     }

},
{

{19983, 20004,  20015,  19989,  19982,  19982,  19965,  19926   },

{20011, 20023,  20038,  20017,  20017,  20014,  20017,  19988   },

{20013, 20044,  20045,  20020,  20015,  20023,  20017,  20010   },

{20003, 20026,  20033,  20026,  20027,  20024,  20022,  19992   },

{19989, 20009,  20023,  20027,  20024,  20021,  19996,  19982   },

{19991, 20007,  20016,  20023,  20021,  20011,  19997,  19981   },

{19983, 19995,  20004,  20014,  20013,  20004,  19989,  19973   },

{19957, 19976,  19986,  19972,  19989,  19979,  19966,  19947   }

}
};

extern const int eg_table_black[6][8][8] =
{
{

{94,    107,    98,     107,    126,    188,    272,    94      },

{94,    102,    101,    103,    118,    194,    267,    94      },

{94,    102,    88,     91,     107,    179,    252,    94      },

{94,    104,    95,     87,     99,     161,    228,    94      },

{94,    107,    94,     87,     92,     150,    241,    94      },

{94,    94,     89,     86,     98,     147,    226,    94      },

{94,    96,     93,     97,     111,    176,    259,    94      },

{94,    87,     86,     93,     111,    178,    281,    94      }

},
{

{252,   239,    258,    263,    264,    257,    256,    223     },

{230,   261,    278,    275,    284,    261,    273,    243     },

{258,   271,    280,    297,    303,    291,    256,    268     },

{266,   276,    296,    306,    303,    290,    279,    253     },

{259,   279,    291,    297,    303,    280,    272,    250     },

{263,   261,    278,    298,    292,    272,    256,    254     },

{231,   258,    261,    285,    289,    262,    257,    218     },

{217,   237,    259,    263,    263,    240,    229,    182     }

},
{

{274,   283,    285,    291,    294,    299,    289,    283     },

{288,   279,    294,    300,    306,    289,    293,    276     },

{274,   290,    305,    310,    309,    297,    304,    286     },

{292,   296,    307,    316,    306,    296,    285,    289     },

{288,   301,    310,    304,    311,    295,    294,    290     },

{281,   288,    300,    307,    307,    303,    284,    288     },

{292,   282,    290,    294,    300,    297,    293,    280     },

{280,   270,    282,    288,    299,    301,    283,    273     }

},
{

{503,   506,    508,    515,    516,    519,    523,    525     },

{514,   506,    512,    517,    515,    519,    525,    522     },

{515,   512,    507,    520,    525,    519,    525,    530     },

{511,   514,    511,    516,    513,    517,    523,    527     },

{507,   503,    505,    507,    514,    516,    509,    524     },

{499,   503,    500,    506,    513,    509,    515,    524     },

{516,   501,    504,    504,    511,    507,    520,    520     },

{492,   509,    496,    501,    514,    509,    515,    517     }

},
{

{903,   914,    920,    918,    939,    916,    919,    927     },

{908,   913,    909,    964,    958,    942,    956,    958     },

{914,   906,    951,    955,    960,    945,    968,    958     },

{893,   920,    942,    983,    981,    985,    977,    963     },

{931,   920,    945,    967,    993,    983,    994,    963     },

{904,   913,    953,    970,    976,    971,    961,    955     },

{916,   900,    946,    975,    993,    955,    966,    946     },

{895,   904,    941,    959,    972,    945,    936,    956     }

},
{

{19947, 19973,  19981,  19982,  19992,  20010,  19988,  19926   },

{19966, 19989,  19997,  19996,  20022,  20017,  20017,  19965   },

{19979, 20004,  20011,  20021,  20024,  20023,  20014,  19982   },

{19989, 20013,  20021,  20024,  20027,  20015,  20017,  19982   },

{19972, 20014,  20023,  20027,  20026,  20020,  20017,  19989   },

{19986, 20004,  20016,  20023,  20033,  20045,  20038,  20015   },

{19976, 19995,  20007,  20009,  20026,  20044,  20023,  20004   },

{19957, 19983,  19991,  19989,  20003,  20013,  20011,  19983   }

}
};*/

#endif

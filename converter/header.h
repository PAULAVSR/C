#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef STARS_SPACES
#define STARS_SPACES "* * * * * * * * * * * * * "
#endif

#ifndef SUB_FIRST_PLUS
#define SUB_FIRST_PLUS "               "
#endif

#ifndef SUB_FIRST
#define SUB_FIRST "                "
#endif

#ifndef SUB_SECOND
#define SUB_SECOND "                          "
#endif

#ifndef SUB_THIRD_PLUS
#define SUB_THIRD_PLUS "                                       "
#endif

#ifndef SUB_THIRD
#define SUB_THIRD "                                        "
#endif

#ifndef SUB_FOURTH_PLUS
#define SUB_FOURTH_PLUS "                                                                "
#endif

#ifndef SUB_FOURTH
#define SUB_FOURTH "                                                  "
#endif

#ifndef SUB_FIFTH
#define SUB_FIFTH "                                                                 "
#endif

#ifndef SUB_SIX
#define SUB_SIX "                                                                             "
#endif

extern void menuChoice (void);
extern void distanceMeasure (void);
extern void weightMeasure (void);
extern void convertInch (void);
extern void convertFeet (void);
extern void convertYard (void);
extern void convertMiles (void);
extern void convertOunce (void);
extern void convertPound (void);
extern void converterOutput (int direction, float constant, char brit [], char germ []);


extern int askUser (char spaces_plus [], char spaces [], int choices);
extern int askConvertDirection (char space [], char names [],char menu_point []);
extern float converter (float constant, float input);

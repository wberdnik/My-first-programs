#if defined(__TINY__) || defined(__SMALL__) || defined(__MEDIUM__)
#error Эта программа работает только в моделя LARGE  и HUGE 
#endif

#ifndef __cplusplus
#error Эта программа требует C++
#endif

#ifndef SLAVE
#define SLAVE

typedef unsigned int  word;
typedef unsigned char byte;

enum{
	sizeX	=	639,
	sizeY	=	479,
	sizeDy	=	16,

	};

enum{   modeSimple	=	0, // просто площадка
	modeBox,		// обведенная площадка
	modeNameBox,            // modeBox c именем
	modeDialog,             // modeNameBox c экраном
	modeOnlyDialog,	        // только экран
	modeGroup,               // в как элемент группы

	};


enum{ kbHelp=0x3b00,
      kbEnter=0x1c0d,
      kbQuit=0x2d00,
      kbESC=0x011b,
      kbNoKey=0x0000,
      scLeft=75,
      scRight=77,
      scClear=0xff,
      scDel=0x53,
      scHome=0x47,
      scEnd=0x4f,
      };
//Event flag

enum{No=0,Yes=1,
	eSys,
	eMouse,
	eKeyboard,
	eComand
	};
enum{ 	stNo,
	stPress,
	stSelect,
        stFocus,
        stDraft,
        stDelete,

	};



//Event press	
enum{
	cmCopyright,
	cmGo,
	cmOk,
	cmCansel,
	cmWait,
	cmShowsubmenu,
	cmQuit,
	cmLoad,
	cmSaveas,
	cmBorder,
	cmShell,
	cmEji,
	cmSum,
	cmCentre,
	cmDraft,
	cmNew,
	cmChDir,
	cmLine,
	cmNowork,
	cmNo,
	cmError,
	cmUp,
	cmDown,
	cmFile,
	cmStationa,
	cmStationb,
	cmDOSshell,
	cmHome,
	cmEnd,
	cmChar,
	cmBios,
	cmB1,
        cmB2,
        cmB3,
	cmB4,
        cmB5,
        cmB6,
	cmB7,
	cmB8,
	cmB9,
	cmB10,
	cmB11,
	cmB12,
	cmOpros,
	cmStop,
	cmView,
	cmTetris,
	cmStepweb,
	cmPoint,
	cmGetInfo,
	cmModeCoor,
	cmShowLine,
	cmSort,
	cmFreeDraft,
	cmGreen,
	cmCalc,
	cmAuto,
	cmEndWork,
	cmBreak,
	cmBuildm,
	cmLineDeskTop,
	cmSound,
	cmLineBar,
	cmEditNet,
	cmInfo,
	cmBaseConc,
	cmBaseCabel,
	cmAbout,
	cmHelp,
	cmHelp1,
	cmIis,
	cmUpButton,
	cmAdd,
	cmSub,
	cmSignal,
	cmSaveSlaid,
	cmLoadSlaid,
	cmStopSlaid,
	cmRezult,
	};
enum {
	rasNo,
	rasMathReal,
	rasMathPixel,
	rasCooPixel,
	rasCooReal,
	rasCooNo
		    };

#ifndef __COLORS
#define __COLORS

enum COLORS {
    BLACK,          /* dark colors */
    BLUE,
    GREEN,
    CYAN,
    RED,
    MAGENTA,
    BROWN,
    LIGHTGRAY,
    DARKGRAY,       /* light colors */
    LIGHTBLUE,
    LIGHTGREEN,
    LIGHTCYAN,
    LIGHTRED,
    LIGHTMAGENTA,
    YELLOW,
    WHITE
};
#endif


#define NULL 0L

#endif

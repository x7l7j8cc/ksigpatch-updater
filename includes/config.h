
// Default Config
#define ORIG_AUTHOR             "ITotalJustice"
#define MODK_AUTHOR             "x7l7j8cc"

#define ROOT                    "/"
#define APP_PATH                "/switch/ksigpatch-updater/"
#define APP_OUTPUT              "/switch/ksigpatch-updater/ksigpatch-updater.nro"
#define OLD_APP_PATH            "/switch/ksigpatch-updater.nro"

#define APP_NAME                "Kosmos Sigpatch-Updater"
#define APP_VERSION             "0.1.5 Mod"
#define CURSOR_LIST_MAX         2 //On-SCREEN OPTION LIST -1

//#define UP_MSIG       0
//#define UP_FSIG       1
#define UP_HSIG       0
//#define UP_RMNL       3
#define UP_RMPT       1
#define UP_APP        2


//Link to DL will AutoUpdate files from Server side.
//#define SIG_MINI_URL    "https://github.com/x7l7j8cc/ksigpatch-updater/releases/download/v0.1.4-mod/latest-Kosmos-Patches_v15.5_byJoonie86-MINI.zip"
//#define SIG_FULL_URL    "https://github.com/x7l7j8cc/ksigpatch-updater/releases/download/v0.1.4-mod/latest-Kosmos-Patches_v15.5_byJoonie86-FULL.zip"
#define SIG_HARK1_URL   "https://github.com/HarukoNX/Atmosphere/releases/latest/download/loader.kip"
#define SIG_HARK2_URL   "https://github.com/HarukoNX/Atmosphere/releases/latest/download/patches.ini"
#define AMS_MITM_PATCH  "https://github.com/x7l7j8cc/ksigpatch-updater/releases/download/v0.1.4-mod/ams_mitm.kip"
#define SIG_HEKATE_PTC  "https://github.com/x7l7j8cc/ksigpatch-updater/releases/download/v0.1.4-mod/sigpatch_hekate_ipl.ini"
#define SIG_REMOVE_URL  "https://github.com/x7l7j8cc/ksigpatch-updater/releases/latest/download/default_kosmos_config.zip"
#define APP_URL         "https://github.com/x7l7j8cc/ksigpatch-updater/releases/latest/download/ksigpatch-updater.nro"

//Temp File to remove, and patch file for tinfoil (if found)
#define DIR_TINFOIL_PATCH  "/atmosphere/kips/ams_mitm.kip"
#define DIR_FILE_LKIP      "/atmosphere/kips/loader.kip"
#define DIR_FILE_HEKATE    "/bootloader/hekate_ipl.ini"
#define DIR_FILE_PATCHES   "/bootloader/patches.ini"
#define DIR_NICHOLELOGO    "/atmosphere/exefs_patches/nichole_logo"
#define DIR_RMV_ESPATCH    "/atmosphere/exefs_patches/es_patches"
#define DIR_RMV_KIPS       "/atmosphere/kips"
#define TEMP_FILE          "/switch/ksigpatch-updater/temp"

//Menu Options
//#define LOPTION_1       "Install Kosmos (Mini) Sigpatches (ES/FS Only)"
//#define LOPTION_2       "Install Kosmos (Full) Sigpatches (for Tinfoil Support)"
#define LOPTION_1       "Install Sigpatches by HarukoNX (with Tinfoil Patch)"
//#define LOPTION_4       "Remove Nichole-Logo from Kosmos Boot"
#define LOPTION_2       "Remove SigPatches from Kosmos"
#define LOPTION_3       "Update this App"
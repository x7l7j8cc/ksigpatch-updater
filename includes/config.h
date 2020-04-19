
// Default Config
#define ORIG_AUTHOR             "ITotalJustice"
#define MODK_AUTHOR             "x7l7j8cc"

#define ROOT                    "/"
#define APP_PATH                "/switch/ksigpatch-updater/"
#define APP_OUTPUT              "/switch/ksigpatch-updater/ksigpatch-updater.nro"
#define OLD_APP_PATH            "/switch/ksigpatch-updater.nro"

#define APP_NAME                "Kosmos Sigpatch-Updater"
#define APP_VERSION             "0.1.4 Mod"
#define CURSOR_LIST_MAX         4 //On-SCREEN OPTION LIST -1

#define UP_MSIG       0
#define UP_FSIG       1
#define UP_HSIG       2
#define UP_RMNL       3
#define UP_APP        4


//Link to DL will AutoUpdate files from Server side.
#define SIG_MINI_URL    "http://teamx7l7j8cc.altervista.org/n3sw_lastupd/SigPatchKosmos_MINI.zip"
#define SIG_FULL_URL    "http://teamx7l7j8cc.altervista.org/n3sw_lastupd/SigPatchKosmos_FULL.zip"
#define SIG_HARK1_URL    "https://github.com/HarukoNX/Atmosphere/releases/latest/download/loader.kip"
#define SIG_HARK2_URL    "https://github.com/HarukoNX/Atmosphere/releases/latest/download/patches.ini"
#define APP_URL         "https://github.com/x7l7j8cc/ksigpatch-updater/releases/latest/download/ksigpatch-updater.nro"

//Temp File to remove, and patch file for tinfoil (if found)
#define DIR_TINFOIL_PATCH  "/atmosphere/kips/ams_mitm.kip"
#define DIR_FILE_KIP       "/atmosphere/kips/loader.kip"
#define DIR_FILE_PATCHES   "/bootloader/patches.ini"
#define DIR_NICHOLELOGO    "/atmosphere/exefs_patches/nichole_logo"
#define TEMP_FILE          "/switch/ksigpatch-updater/temp"

#define LOPTION_1       "Update Kosmos (Mini) Sigpatches (ES/FS Only)"
#define LIOPTION_1       "Install Kosmos (Mini) Sigpatches (ES/FS Only)"
#define LOPTION_2       "Update Kosmos (Full) Sigpatches (+ACID for Tinfoil Support)"
#define LIOPTION_2       "Install Kosmos (Full) Sigpatches (+ACID for Tinfoil Support)"
#define LOPTION_3       "Update Sigpatches by HarukoNX"
#define LIOPTION_3       "Install Sigpatches by HarukoNX (Install Kosmos Full Patches first.)"
#define LOPTION_4       "Remove Nichole-Logo from Kosmos Boot"
#define LOPTION_5       "Update this App"
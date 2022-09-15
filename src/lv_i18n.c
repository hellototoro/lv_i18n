#include "./lv_i18n.h"


////////////////////////////////////////////////////////////////////////////////
// Define plural operands
// http://unicode.org/reports/tr35/tr35-numbers.html#Operands

// Integer version, simplified

#define UNUSED(x) (void)(x)

static inline uint32_t op_n(int32_t val) { return (uint32_t)(val < 0 ? -val : val); }
static inline uint32_t op_i(uint32_t val) { return val; }
// always zero, when decimal part not exists.
static inline uint32_t op_v(uint32_t val) { UNUSED(val); return 0;}
static inline uint32_t op_w(uint32_t val) { UNUSED(val); return 0; }
static inline uint32_t op_f(uint32_t val) { UNUSED(val); return 0; }
static inline uint32_t op_t(uint32_t val) { UNUSED(val); return 0; }

static lv_i18n_phrase_t en_gb_singulars[] = {
    {"setting_p_picture_setting", "Video Setting"},
    {"setting_p_picture_mode", "Picture Mode"},
    {"setting_p_picture_mode_type_standard", "Medium"},
    {"setting_p_picture_scale", "Aspect Ratio"},
    {"setting_p_picture_color_temp", "Color Temperature"},
    {"setting_p_picture_color_temp_type_standard", "Medium"},
    {"setting_p_picture_rate", "Reduce Display Size"},
    {"setting_p_picture_rate_100", "100%"},
    {"setting_p_picture_power_bank_mode", "Portable Power Mode"},
    {"setting_p_picture_power_bank_mode_low", "Low"},
    {"setting_p_picture_mode_contrast", "Contrast"},
    {"setting_p_picture_mode_brightness", "Brightness"},
    {"setting_p_picture_mode_colour", "Color"},
    {"setting_p_picture_mode_sharpness", "Sharpness"},
    {"setting_p_picture_color_temp_red", "Red"},
    {"setting_p_picture_color_temp_green", "Green"},
    {"setting_p_picture_color_temp_blue", "Blue"},
    {"setting_p_picture_mode_type_standard_soft", "Soft"},
    {"setting_p_picture_mode_type_standard_user", "User"},
    {"setting_p_picture_mode_type_standard_dynamic", "Vivid"},
    {"setting_p_picture_color_temp_type_warm", "Warm"},
    {"setting_p_picture_color_temp_type_user", "User"},
    {"setting_p_picture_color_temp_type_cool", "Cool"},
    {"setting_p_picture_scale_auto", "Auto"},
    {"setting_p_picture_power_bank_mode_middle", "Middle"},
    {"setting_p_picture_power_bank_mode_high", "High"},
    {"setting_p_sound_setting", "Sound Setting"},
    {"setting_p_sound_mode", "Sound Mode"},
    {"setting_p_sound_mode_type_standard", "Standard"},
    {"setting_p_sound_surround", "Surround Sound"},
    {"setting_p_sound_surround_off", "Off"},
    {"setting_p_sound_auto_volume", "Auto Volume"},
    {"setting_p_sound_auto_volume_off", "Off"},
    {"setting_p_sound_mode_treble", "Treble"},
    {"setting_p_sound_mode_bass", "Bass"},
    {"setting_p_sound_mode_type_music", "Music"},
    {"setting_p_sound_mode_type_movie", "Movie"},
    {"setting_p_sound_mode_type_sport", "Sport"},
    {"setting_p_sound_mode_type_user", "User"},
    {"setting_p_system_setting", "System Setting"},
    {"setting_p_system_language", "OSD Language"},
    {"setting_p_system_osd_time", "OSD Duration"},
    {"setting_p_system_osd_time_off", "Off"},
    {"setting_p_system_restore_factory_mode", "Restore Factory Default"},
    {"setting_p_system_osd_time_5", "5S"},
    {"setting_p_system_osd_time_10", "10S"},
    {"setting_p_system_osd_time_15", "15S"},
    {"setting_p_system_osd_time_20", "20S"},
    {"setting_p_system_osd_time_25", "25S"},
    {"setting_p_system_osd_time_30", "30S"},
    {"media_category_p_all", "All Files"},
    {"media_category_p_video", "Video Files"},
    {"media_category_p_music", "Music Files"},
    {"media_category_p_photo", "Photo Files"},
    {"media_category_p_text", "Text Files"},
    {"media_file_p_return", "Return"},
    {"media_file_p_path", "path:"},
    {"media_no_lyric", "No lyrics"},
    {"media_no_device", "No Device"},
    {"media_udisk_removed", "UDisk Removed"},
    {"home_movie", "Movie"},
    {"home_music", "Music"},
    {"home_picture", "Picture"},
    {"home_mirroring", "Mirroring"},
    {"home_udisk", "Udisk"},
    {"home_hdmi", "HDMI"},
    {"home_setting", "Setting"},
    {"language_espaol", "Español"},
    {"language_deutsch", "Deutsch"},
    {"language_english", "English"},
    {"language_italiano", "Italiano"},
    {"language_france", "Français"},
    {"language_chinese", "简体中文"},
    {"setting_p_net_work", "Net Work"},
    {"setting_p_projector", "Projector"},
    {"setting_p_picture", "Video"},
    {"setting_p_sound", "Sound"},
    {"setting_p_system", "System"},
    {"setting_p_upgrade", "Upgrade"},
    {"setting_p_usb_upgrade", "Software Update(USB)"},
    {"setting_p_ota_upgrade", "Software Update(OTA)"},
    {"setting_p_projector_info", "Info"},
    {"setting_p_sound_surround_srs", "SRS TruSurround XT"},
    {"setting_p_sound_auto_volume_on", "On"},
    {"setting_p_wifi", "Wifi"},
    {"setting_p_bluetooth", "Bluetooth"},
    {"setting_p_refresh", "Refresh"},
    {"setting_p_wifi_connected", "Connected"},
    {"setting_p_wifi_available", "Available"},
    {"setting_p_code", "Code"},
    {"setting_p_show_code", "Show Code"},
    {"setting_p_connect", "Connect"},
    {"setting_p_ok", "OK"},
    {"setting_p_cancel", "Cancel"},
    {"setting_p_waiting", "Waiting..."},
    {"setting_p_be_sure", "Are you Sure?"},
    {"hdmi_no_single", "NO SIGNAL"},
    {"cast_mira", "Android Screen"},
    {"cast_airplay", "iOS Screen"},
    {"cast_wait_for_connect", "Waiting for connection..."},
    {"cast_connecting", "Connecting..."},
    {"cast_password", "password"},
    {"cast_mira_str1", "1. Turn on the Multi-screen or Screen Mirroring function\n    on your Android device.\n2. Waiting, and choosing:  "},
    {"cast_mira_str2", "Note : 1.Your device may pop up 'turn on the WLAN' during the search,then choose 'Yes'.\n2.If there is no popup or no devices could be found to connect,please turn on the WLAN manually.Scan QR code through the URL to get the video of connection:https://bit.ly/3OdJ311"},
    {"cast_airplay_str1", "1. On your iOS device,turn on WI-FI and connect:  "},
    {"cast_airplay_str2", "2. Open Control Center and Screen Mirroring.\n3. Select and Connect:  "},
    {"cast_airplay_str3", "Note :   1. The router WIFI needs to turn on DHCP to avoid connection failure.\n            2. Scan QR code/Through the URL to get the video of connection: \n                  https://bit.ly/3OdJ311"},
    {NULL, NULL} // End mark
};

static lv_i18n_phrase_t en_gb_plurals_other[] = {
    {"songs", "(%d songs)"},
    {NULL, NULL} // End mark
};

static uint8_t en_gb_plural_fn(int32_t num)
{
    uint32_t n = op_n(num); UNUSED(n);
    uint32_t i = op_i(n); UNUSED(i);
    uint32_t v = op_v(n); UNUSED(v);

    if ((i == 1 && v == 0)) return LV_I18N_PLURAL_TYPE_ONE;
    return LV_I18N_PLURAL_TYPE_OTHER;
}

static const lv_i18n_lang_t en_gb_lang = {
    .locale_name = "en-GB",
    .singulars = en_gb_singulars,
    .plurals[LV_I18N_PLURAL_TYPE_OTHER] = en_gb_plurals_other,
    .locale_plural_fn = en_gb_plural_fn
};

static lv_i18n_phrase_t de_singulars[] = {
    {"setting_p_picture_setting", "Video-Einstellungen"},
    {"setting_p_picture_mode", "Bildmodus"},
    {"setting_p_picture_mode_type_standard", "Mittel"},
    {"setting_p_picture_scale", "Seitenformat"},
    {"setting_p_picture_color_temp", "Farbtemperatur"},
    {"setting_p_picture_color_temp_type_standard", "Mittel"},
    {"setting_p_picture_rate", "Reduce Display Size"},
    {"setting_p_picture_rate_100", "100%"},
    {"setting_p_picture_power_bank_mode", "Powerbank-Modus"},
    {"setting_p_picture_power_bank_mode_low", "Niedrig"},
    {"setting_p_picture_mode_contrast", "Kontrast"},
    {"setting_p_picture_mode_brightness", "Helligkeit"},
    {"setting_p_picture_mode_colour", "Farbe"},
    {"setting_p_picture_mode_sharpness", "Schärfe"},
    {"setting_p_picture_color_temp_red", "Rot"},
    {"setting_p_picture_color_temp_green", "Grün"},
    {"setting_p_picture_color_temp_blue", "Blau"},
    {"setting_p_picture_mode_type_standard_soft", "Sanft"},
    {"setting_p_picture_mode_type_standard_user", "Nutzer"},
    {"setting_p_picture_mode_type_standard_dynamic", "Vivid"},
    {"setting_p_picture_color_temp_type_warm", "Warm"},
    {"setting_p_picture_color_temp_type_user", "Nutzer"},
    {"setting_p_picture_color_temp_type_cool", "Cool"},
    {"setting_p_picture_scale_auto", "Auto"},
    {"setting_p_picture_power_bank_mode_middle", "Middle"},
    {"setting_p_picture_power_bank_mode_high", "Hoch"},
    {"setting_p_sound_setting", "Toneinstellung"},
    {"setting_p_sound_mode", "Effekt"},
    {"setting_p_sound_mode_type_standard", "Standard"},
    {"setting_p_sound_surround", "Surround Sound"},
    {"setting_p_sound_surround_off", "Aus"},
    {"setting_p_sound_auto_volume", "Auto Volume"},
    {"setting_p_sound_auto_volume_off", "Aus"},
    {"setting_p_sound_mode_treble", "Dreifach"},
    {"setting_p_sound_mode_bass", "Bass"},
    {"setting_p_sound_mode_type_music", "Musik"},
    {"setting_p_sound_mode_type_movie", "Film"},
    {"setting_p_sound_mode_type_sport", "Sport"},
    {"setting_p_sound_mode_type_user", "Nutzer"},
    {"setting_p_system_setting", "Systemeinstellung"},
    {"setting_p_system_language", "OSD Sprache"},
    {"setting_p_system_osd_time", "OSD Duration"},
    {"setting_p_system_osd_time_off", "Aus"},
    {"setting_p_system_restore_factory_mode", "Wiederherstellen"},
    {"setting_p_system_osd_time_5", "5S"},
    {"setting_p_system_osd_time_10", "10S"},
    {"setting_p_system_osd_time_15", "15S"},
    {"setting_p_system_osd_time_20", "20S"},
    {"setting_p_system_osd_time_25", "25S"},
    {"setting_p_system_osd_time_30", "30S"},
    {"media_category_p_all", "Alle Dateien"},
    {"media_category_p_video", "Videodateien"},
    {"media_category_p_music", "Musikdateien"},
    {"media_category_p_photo", "Fotodateien"},
    {"media_category_p_text", "Textdateien"},
    {"media_file_p_return", "Zurückkehren"},
    {"media_file_p_path", "Weg:"},
    {"media_no_lyric", "Keine Texte"},
    {"media_no_device", "Keine Geräte"},
    {"home_movie", "Film"},
    {"home_music", "Musik"},
    {"home_picture", "Foto"},
    {"home_mirroring", "Mirroring"},
    {"home_udisk", "U-Disk"},
    {"home_hdmi", "HDMI"},
    {"home_setting", "Set"},
    {"language_espaol", "Español"},
    {"language_deutsch", "Deutsch"},
    {"language_english", "English"},
    {"language_italiano", "Italiano"},
    {"language_france", "Français"},
    {"language_chinese", "简体中文"},
    {"setting_p_net_work", "Netzwerkarbeit"},
    {"setting_p_projector", "Beamer"},
    {"setting_p_picture", "Video"},
    {"setting_p_sound", "Klang"},
    {"setting_p_system", "System"},
    {"setting_p_upgrade", "Aktualisierung"},
    {"setting_p_usb_upgrade", "Software Update(USB)"},
    {"setting_p_ota_upgrade", "Software Update(OTA)"},
    {"setting_p_projector_info", "Info"},
    {"setting_p_sound_surround_srs", "SRS TruSurround XT"},
    {"setting_p_sound_auto_volume_on", "Ein"},
    {"setting_p_wifi", "Wifi"},
    {"setting_p_bluetooth", "Bluetooth"},
    {"setting_p_refresh", "Aktualisierung"},
    {"setting_p_wifi_connected", "Verbinden"},
    {"setting_p_wifi_available", "Verfügbar"},
    {"setting_p_code", "Code"},
    {"setting_p_show_code", "Code anzeigen"},
    {"setting_p_connect", "Verbinden"},
    {"setting_p_ok", "OK"},
    {"setting_p_cancel", "Absagen"},
    {"setting_p_waiting", "Warten..."},
    {"setting_p_be_sure", "Bist du sicher?"},
    {"hdmi_no_single", "KEIN SIGNAL"},
    {"cast_mira", "Android-Bildschirm"},
    {"cast_airplay", "iOS-Bildschirm"},
    {"cast_wait_for_connect", "Auf Verbindung warten..."},
    {"cast_connecting", "Verbinden..."},
    {"cast_password", "Passwort"},
    {"cast_mira_str1", "1. Schalten Sie die Multi-Screen oder Screen Mirroring auf Ihrem Android-Gerät ein.\n2. Warten und auswählen "},
    {"cast_mira_str2", "Hinweis : 1.Ihr Gerät zeigt möglicherweise 'WLAN aktivieren' an und wählen dann 'Ja'. \n2.Falls kein Popup-Fenster erscheint oder kein Gerät gefunden werden konnte,aktivieren Sie WLAN bitte manuell.QR-Code scannen/über URL verbinden:https://bit.ly/3OdJ311"},
    {"cast_airplay_str1", "1. Schalten Sie auf Ihrem iOS-Gerät WI-FI ein und verbinden Sie "},
    {"cast_airplay_str2", "2. Aktivieren Sie die Bildschirmspiegelung. \n3. Auswählen und verbinden "},
    {"cast_airplay_str3", "Hinweis : 1. WLAN-Router muss DHCP aktivieren,um Verbindungsfehler zu vermeiden. \n2. Scannen Sie den QR-Code/über die URL,um das Video zu erhalten: https://bit.ly/3OdJ311"},
    {NULL, NULL} // End mark
};

static lv_i18n_phrase_t de_plurals_other[] = {
    {"songs", "(%d Lieder)"},
    {NULL, NULL} // End mark
};

static uint8_t de_plural_fn(int32_t num)
{
    uint32_t n = op_n(num); UNUSED(n);
    uint32_t i = op_i(n); UNUSED(i);
    uint32_t v = op_v(n); UNUSED(v);

    if ((i == 1 && v == 0)) return LV_I18N_PLURAL_TYPE_ONE;
    return LV_I18N_PLURAL_TYPE_OTHER;
}

static const lv_i18n_lang_t de_lang = {
    .locale_name = "de",
    .singulars = de_singulars,
    .plurals[LV_I18N_PLURAL_TYPE_OTHER] = de_plurals_other,
    .locale_plural_fn = de_plural_fn
};

static lv_i18n_phrase_t es_singulars[] = {
    {"setting_p_picture_setting", "Ajuste de vídeo"},
    {"setting_p_picture_mode", "Modo Imagen"},
    {"setting_p_picture_mode_type_standard", "Med"},
    {"setting_p_picture_scale", "Relación de aspecto"},
    {"setting_p_picture_color_temp", "Temp.del Color"},
    {"setting_p_picture_color_temp_type_standard", "Med"},
    {"setting_p_picture_rate", "Reduce Display Size"},
    {"setting_p_picture_rate_100", "100%"},
    {"setting_p_picture_power_bank_mode", "Modo Powerbank"},
    {"setting_p_picture_power_bank_mode_low", "Bajo"},
    {"setting_p_picture_mode_contrast", "Contraste"},
    {"setting_p_picture_mode_brightness", "Brillo"},
    {"setting_p_picture_mode_colour", "Color"},
    {"setting_p_picture_mode_sharpness", "Nitidez"},
    {"setting_p_picture_color_temp_red", "Rojo"},
    {"setting_p_picture_color_temp_green", "Verde"},
    {"setting_p_picture_color_temp_blue", "Azul"},
    {"setting_p_picture_mode_type_standard_soft", "Blando"},
    {"setting_p_picture_mode_type_standard_user", "Usuario"},
    {"setting_p_picture_mode_type_standard_dynamic", "Vívido"},
    {"setting_p_picture_color_temp_type_warm", "Cálido"},
    {"setting_p_picture_color_temp_type_user", "Usuario"},
    {"setting_p_picture_color_temp_type_cool", "Frio"},
    {"setting_p_picture_scale_auto", "Auto"},
    {"setting_p_picture_power_bank_mode_middle", "Middle"},
    {"setting_p_picture_power_bank_mode_high", "Alto"},
    {"setting_p_sound_setting", "Ajuste de sonido"},
    {"setting_p_sound_mode", "Modo De So"},
    {"setting_p_sound_mode_type_standard", "Estandar"},
    {"setting_p_sound_surround", "Surround Sound"},
    {"setting_p_sound_surround_off", "Apagado"},
    {"setting_p_sound_auto_volume", "Auto Volume"},
    {"setting_p_sound_auto_volume_off", "Apagado"},
    {"setting_p_sound_mode_treble", "Triplicar"},
    {"setting_p_sound_mode_bass", "Bajo"},
    {"setting_p_sound_mode_type_music", "Musica"},
    {"setting_p_sound_mode_type_movie", "Cine"},
    {"setting_p_sound_mode_type_sport", "Deporte"},
    {"setting_p_sound_mode_type_user", "Usuario"},
    {"setting_p_system_setting", "Ajuste del sistema"},
    {"setting_p_system_language", "Lengua de OSD"},
    {"setting_p_system_osd_time", "OSD Duration"},
    {"setting_p_system_osd_time_off", "Apagado"},
    {"setting_p_system_restore_factory_mode", "Restablecer"},
    {"setting_p_system_osd_time_5", "5S"},
    {"setting_p_system_osd_time_10", "10S"},
    {"setting_p_system_osd_time_15", "15S"},
    {"setting_p_system_osd_time_20", "20S"},
    {"setting_p_system_osd_time_25", "25S"},
    {"setting_p_system_osd_time_30", "30S"},
    {"media_category_p_all", "Todos los archivos"},
    {"media_category_p_video", "Archivos de video"},
    {"media_category_p_music", "Archivos de música"},
    {"media_category_p_photo", "Archivos de fotos"},
    {"media_category_p_text", "Archivos de texto"},
    {"media_file_p_return", "Devolver"},
    {"media_file_p_path", "sendero:"},
    {"media_no_lyric", "sin letra"},
    {"media_no_device", "Sin dispositivos"},
    {"home_movie", "Cine"},
    {"home_music", "Musica"},
    {"home_picture", "Foto"},
    {"home_mirroring", "Mirroring"},
    {"home_udisk", "U disco"},
    {"home_hdmi", "HDMI"},
    {"home_setting", "Ajustes"},
    {"language_espaol", "Español"},
    {"language_deutsch", "Deutsch"},
    {"language_english", "English"},
    {"language_italiano", "Italiano"},
    {"language_france", "Français"},
    {"language_chinese", "简体中文"},
    {"setting_p_net_work", "La red"},
    {"setting_p_projector", "Proyector"},
    {"setting_p_picture", "Vídeo"},
    {"setting_p_sound", "Sonar"},
    {"setting_p_system", "Sistema"},
    {"setting_p_upgrade", "Mejora"},
    {"setting_p_usb_upgrade", "Actualizando el software(USB)"},
    {"setting_p_ota_upgrade", "Actualizando el software(OTA)"},
    {"setting_p_projector_info", "Info"},
    {"setting_p_sound_surround_srs", "SRS TruSurround XT"},
    {"setting_p_sound_auto_volume_on", "Encendido"},
    {"setting_p_wifi", "Wifi"},
    {"setting_p_bluetooth", "Bluetooth"},
    {"setting_p_refresh", "Actualizar"},
    {"setting_p_wifi_connected", "Conectar"},
    {"setting_p_wifi_available", "Disponible"},
    {"setting_p_code", "Código"},
    {"setting_p_show_code", "Mostrar código"},
    {"setting_p_connect", "Conectar"},
    {"setting_p_ok", "OK"},
    {"setting_p_cancel", "Cancelar"},
    {"setting_p_waiting", "Esperando..."},
    {"setting_p_be_sure", "¿Estas segura?"},
    {"hdmi_no_single", "SIN SEÑAL"},
    {"cast_mira", "Pantalla de Android"},
    {"cast_airplay", "Pantalla de iOS"},
    {"cast_wait_for_connect", "Esperando la conexión..."},
    {"cast_connecting", "Conectando..."},
    {"cast_password", "Contraseña"},
    {"cast_mira_str1", "1. Active la función Multipantalla o Screen Mirroring en su dispositivo Android.\n2. Esperando y eligiendo "},
    {"cast_mira_str2", "Note : 1.Your device may pop up 'turn on the WLAN' during the search,then choose 'Yes'. \n2.If there is no popup or no devices could be found to connect,please turn on the WLAN manually.Scan QR code/Through the URL to get the video of connection:https://bit.ly/3OdJ311"},
    {"cast_airplay_str1", "        1. Encienda el Wi-Fi y conecte "},
    {"cast_airplay_str2", "   2. Abra el Centro de Control y la Duplicación de Pantalla. \n3. Seleccionar y conectar "},
    {"cast_airplay_str3", "  Nota : 1. El enrutador WiFi requiere la activación del DHCP para evitar fallos de conexión. \n2. Escanee el código QR/a través de la URL para el vídeo de conexión: https://bit.ly/3OdJ311"},
    {NULL, NULL} // End mark
};

static lv_i18n_phrase_t es_plurals_other[] = {
    {"songs", "(%d canciones)"},
    {NULL, NULL} // End mark
};

static uint8_t es_plural_fn(int32_t num)
{
    uint32_t n = op_n(num); UNUSED(n);


    if ((n == 1)) return LV_I18N_PLURAL_TYPE_ONE;
    return LV_I18N_PLURAL_TYPE_OTHER;
}

static const lv_i18n_lang_t es_lang = {
    .locale_name = "es",
    .singulars = es_singulars,
    .plurals[LV_I18N_PLURAL_TYPE_OTHER] = es_plurals_other,
    .locale_plural_fn = es_plural_fn
};

static lv_i18n_phrase_t fr_singulars[] = {
    {"setting_p_picture_setting", "Réglage vidéo"},
    {"setting_p_picture_mode", "Mode image"},
    {"setting_p_picture_mode_type_standard", "Med"},
    {"setting_p_picture_scale", "Ratio d'aspect"},
    {"setting_p_picture_color_temp", "Temp.de Couleur"},
    {"setting_p_picture_color_temp_type_standard", "Med"},
    {"setting_p_picture_rate", "Reduce Display Size"},
    {"setting_p_picture_rate_100", "100%"},
    {"setting_p_picture_power_bank_mode", "Mode Powerbank"},
    {"setting_p_picture_power_bank_mode_low", "Basse"},
    {"setting_p_picture_mode_contrast", "Contraste"},
    {"setting_p_picture_mode_brightness", "Luminosité"},
    {"setting_p_picture_mode_colour", "Couleur"},
    {"setting_p_picture_mode_sharpness", "Acuité"},
    {"setting_p_picture_color_temp_red", "Rouge"},
    {"setting_p_picture_color_temp_green", "Vert"},
    {"setting_p_picture_color_temp_blue", "Bleu"},
    {"setting_p_picture_mode_type_standard_soft", "Doux"},
    {"setting_p_picture_mode_type_standard_user", "Utilisateur"},
    {"setting_p_picture_mode_type_standard_dynamic", "Vif"},
    {"setting_p_picture_color_temp_type_warm", "Chaud"},
    {"setting_p_picture_color_temp_type_user", "Utilisateur"},
    {"setting_p_picture_color_temp_type_cool", "Cool"},
    {"setting_p_picture_scale_auto", "Auto"},
    {"setting_p_picture_power_bank_mode_middle", "Middle"},
    {"setting_p_picture_power_bank_mode_high", "Haut"},
    {"setting_p_sound_setting", "Réglage du son"},
    {"setting_p_sound_mode", "Mode De Son"},
    {"setting_p_sound_mode_type_standard", "Standard"},
    {"setting_p_sound_surround", "Surround Sound"},
    {"setting_p_sound_surround_off", "Arret"},
    {"setting_p_sound_auto_volume", "Auto Volume"},
    {"setting_p_sound_auto_volume_off", "Arret"},
    {"setting_p_sound_mode_treble", "Tripler"},
    {"setting_p_sound_mode_bass", "Basse"},
    {"setting_p_sound_mode_type_music", "Musique"},
    {"setting_p_sound_mode_type_movie", "Cinema"},
    {"setting_p_sound_mode_type_sport", "Sport"},
    {"setting_p_sound_mode_type_user", "Utilisateur"},
    {"setting_p_system_setting", "Réglage du système"},
    {"setting_p_system_language", "Langue OSD"},
    {"setting_p_system_osd_time", "OSD Duration"},
    {"setting_p_system_osd_time_off", "Arret"},
    {"setting_p_system_restore_factory_mode", "Restaurer"},
    {"setting_p_system_osd_time_5", "5S"},
    {"setting_p_system_osd_time_10", "10S"},
    {"setting_p_system_osd_time_15", "15S"},
    {"setting_p_system_osd_time_20", "20S"},
    {"setting_p_system_osd_time_25", "25S"},
    {"setting_p_system_osd_time_30", "30S"},
    {"media_category_p_all", "Tous les fichiers"},
    {"media_category_p_video", "Fichiers vidéo"},
    {"media_category_p_music", "Fichiers musicaux"},
    {"media_category_p_photo", "Fichiers photos"},
    {"media_category_p_text", "Fichiers texte"},
    {"media_file_p_return", "Revenir"},
    {"media_file_p_path", "chemin:"},
    {"media_no_lyric", "Pas de paroles"},
    {"media_no_device", "Aucun appareil"},
    {"home_movie", "Cinema"},
    {"home_music", "Musique"},
    {"home_picture", "Photo"},
    {"home_mirroring", "Mirroring"},
    {"home_udisk", "Disque U"},
    {"home_hdmi", "HDMI"},
    {"home_setting", "Réglage"},
    {"language_espaol", "Español"},
    {"language_deutsch", "Deutsch"},
    {"language_english", "English"},
    {"language_italiano", "Italiano"},
    {"language_france", "Français"},
    {"language_chinese", "简体中文"},
    {"setting_p_net_work", "Réseau"},
    {"setting_p_projector", "Projecteur"},
    {"setting_p_picture", "Vidéo"},
    {"setting_p_sound", "Son"},
    {"setting_p_system", "Système"},
    {"setting_p_upgrade", "Mise à niveau"},
    {"setting_p_usb_upgrade", "Mise a jour logiciel(USB)"},
    {"setting_p_ota_upgrade", "Mise a jour logiciel(OTA)"},
    {"setting_p_projector_info", "Info"},
    {"setting_p_sound_surround_srs", "SRS TruSurround XT"},
    {"setting_p_sound_auto_volume_on", "Marche"},
    {"setting_p_wifi", "Wifi"},
    {"setting_p_bluetooth", "Bluetooth"},
    {"setting_p_refresh", "Rafraîchir"},
    {"setting_p_wifi_connected", "Relier"},
    {"setting_p_wifi_available", "Disponible"},
    {"setting_p_code", "Code"},
    {"setting_p_show_code", "Afficher le code"},
    {"setting_p_connect", "Relier"},
    {"setting_p_ok", "OK"},
    {"setting_p_cancel", "Annuler"},
    {"setting_p_waiting", "Attendre..."},
    {"setting_p_be_sure", "Êtes-vous sûr?"},
    {"hdmi_no_single", "PAS DE SIGNAL"},
    {"cast_mira", "Écran Android"},
    {"cast_airplay", "Écran iOS"},
    {"cast_wait_for_connect", "En attente de connexion..."},
    {"cast_connecting", "Connexion..."},
    {"cast_password", "Mot de passe"},
    {"cast_mira_str1", "1. Activez le multi-écran ou la mise en miroir d'écran sur votre appareil Android.\n2. Attendez et sélectionnez "},
    {"cast_mira_str2", "Note : 1.Votre appareil peut afficher 'activer le WLAN',puis choisissez « Oui ». \n2.Si une fenêtre contextuelle ou un appareil n'est pas trouvé,activez le WLAN manuel.Scannez le code QR/URL pour vous connecter:https://bit.ly/3OdJ311"},
    {"cast_airplay_str1", "      1. Sur votre appareil iOS,activez le WI-FI et connectez "},
    {"cast_airplay_str2", "2. Ouvrez centre de contrôle et mise en miroir d'écran. \n3. Sélectionnez et connectez "},
    {"cast_airplay_str3", "Note : 1. Le routeur WIFI doit activer DHCP pour éviter les échecs de connexion. \n2. Scannez le code QR/Via l'URL pour obtenir la vidéo de connexion: https://bit.ly/3OdJ311"},
    {NULL, NULL} // End mark
};

static lv_i18n_phrase_t fr_plurals_other[] = {
    {"songs", "(%d Chansons)"},
    {NULL, NULL} // End mark
};

static uint8_t fr_plural_fn(int32_t num)
{
    uint32_t n = op_n(num); UNUSED(n);
    uint32_t i = op_i(n); UNUSED(i);

    if ((((i == 0) || (i == 1)))) return LV_I18N_PLURAL_TYPE_ONE;
    return LV_I18N_PLURAL_TYPE_OTHER;
}

static const lv_i18n_lang_t fr_lang = {
    .locale_name = "fr",
    .singulars = fr_singulars,
    .plurals[LV_I18N_PLURAL_TYPE_OTHER] = fr_plurals_other,
    .locale_plural_fn = fr_plural_fn
};

static lv_i18n_phrase_t it_singulars[] = {
    {"setting_p_picture_setting", "Impostazioni video"},
    {"setting_p_picture_mode", "Modalita immagine"},
    {"setting_p_picture_mode_type_standard", "Medio"},
    {"setting_p_picture_scale", "Rapporto d'aspetto"},
    {"setting_p_picture_color_temp", "Temp.del Colore"},
    {"setting_p_picture_color_temp_type_standard", "Medio"},
    {"setting_p_picture_rate", "Reduce Display Size"},
    {"setting_p_picture_rate_100", "100%"},
    {"setting_p_picture_power_bank_mode", "Modalità Powerbank"},
    {"setting_p_picture_power_bank_mode_low", "Basso"},
    {"setting_p_picture_mode_contrast", "Contrasto"},
    {"setting_p_picture_mode_brightness", "Luminosità"},
    {"setting_p_picture_mode_colour", "Colore"},
    {"setting_p_picture_mode_sharpness", "Nitidezza"},
    {"setting_p_picture_color_temp_red", "Rosso"},
    {"setting_p_picture_color_temp_green", "Verde"},
    {"setting_p_picture_color_temp_blue", "Blu"},
    {"setting_p_picture_mode_type_standard_soft", "Morbido"},
    {"setting_p_picture_mode_type_standard_user", "Utente"},
    {"setting_p_picture_mode_type_standard_dynamic", "Vivido"},
    {"setting_p_picture_color_temp_type_warm", "Caldo"},
    {"setting_p_picture_color_temp_type_user", "Utente"},
    {"setting_p_picture_color_temp_type_cool", "Fresco"},
    {"setting_p_picture_scale_auto", "Auto"},
    {"setting_p_picture_power_bank_mode_middle", "Middle"},
    {"setting_p_picture_power_bank_mode_high", "Alto"},
    {"setting_p_sound_setting", "Impostazioni audio"},
    {"setting_p_sound_mode", "Mode audio"},
    {"setting_p_sound_mode_type_standard", "Standard"},
    {"setting_p_sound_surround", "Surround Sound"},
    {"setting_p_sound_surround_off", "Off"},
    {"setting_p_sound_auto_volume", "Auto Volume"},
    {"setting_p_sound_auto_volume_off", "Off"},
    {"setting_p_sound_mode_treble", "Alti"},
    {"setting_p_sound_mode_bass", "Basso"},
    {"setting_p_sound_mode_type_music", "Musica"},
    {"setting_p_sound_mode_type_movie", "Cinema"},
    {"setting_p_sound_mode_type_sport", "Sport"},
    {"setting_p_sound_mode_type_user", "Utente"},
    {"setting_p_system_setting", "Impostazioni di sistema"},
    {"setting_p_system_language", "Lingua OSD"},
    {"setting_p_system_osd_time", "OSD Duration"},
    {"setting_p_system_osd_time_off", "Off"},
    {"setting_p_system_restore_factory_mode", "Ripristina"},
    {"setting_p_system_osd_time_5", "5S"},
    {"setting_p_system_osd_time_10", "10S"},
    {"setting_p_system_osd_time_15", "15S"},
    {"setting_p_system_osd_time_20", "20S"},
    {"setting_p_system_osd_time_25", "25S"},
    {"setting_p_system_osd_time_30", "30S"},
    {"media_category_p_all", "Tutti i files"},
    {"media_category_p_video", "File video"},
    {"media_category_p_music", "File musicali"},
    {"media_category_p_photo", "File di foto"},
    {"media_category_p_text", "File di testo"},
    {"media_file_p_return", "Ritorno"},
    {"media_file_p_path", "sentiero:"},
    {"media_no_lyric", "Nessun testo"},
    {"media_no_device", "Nessun dispositivo"},
    {"home_movie", "Cinema"},
    {"home_music", "Musica"},
    {"home_picture", "Foto"},
    {"home_mirroring", "Mirroring"},
    {"home_udisk", "Disco U"},
    {"home_hdmi", "HDMI"},
    {"home_setting", "Set"},
    {"language_espaol", "Español"},
    {"language_deutsch", "Deutsch"},
    {"language_english", "English"},
    {"language_italiano", "Italiano"},
    {"language_france", "Français"},
    {"language_chinese", "简体中文"},
    {"setting_p_net_work", "Rete"},
    {"setting_p_projector", "Proiettore"},
    {"setting_p_picture", "Video"},
    {"setting_p_sound", "Suo"},
    {"setting_p_system", "Sistema"},
    {"setting_p_upgrade", "Aggiornamento"},
    {"setting_p_usb_upgrade", "Aggiornamento software(USB)"},
    {"setting_p_ota_upgrade", "Aggiornamento software(OTA)"},
    {"setting_p_projector_info", "Info"},
    {"setting_p_sound_surround_srs", "SRS TruSurround XT"},
    {"setting_p_sound_auto_volume_on", "On"},
    {"setting_p_wifi", "Wifi"},
    {"setting_p_bluetooth", "Bluetooth"},
    {"setting_p_refresh", "Ricaricare"},
    {"setting_p_wifi_connected", "Collegare"},
    {"setting_p_wifi_available", "A disposizione"},
    {"setting_p_code", "Codice"},
    {"setting_p_show_code", "Mostra codice"},
    {"setting_p_connect", "Collegare"},
    {"setting_p_ok", "OK"},
    {"setting_p_cancel", "Annulla"},
    {"setting_p_waiting", "Attesa..."},
    {"setting_p_be_sure", "Sei sicuro?"},
    {"hdmi_no_single", "NESSUN SEGNALE"},
    {"cast_mira", "Schermo Android"},
    {"cast_airplay", "Schermo iOS"},
    {"cast_wait_for_connect", "In attesa di connessione..."},
    {"cast_connecting", "Connessione in corso..."},
    {"cast_password", "password"},
    {"cast_mira_str1", "1. Attiva la funzione Multi-schermo o Screen Mirroring sul tuo dispositivo Android.\n2. In attesa e scegliendo "},
    {"cast_mira_str2", "Note : 1.Your device may pop up 'turn on the WLAN' during the search,then choose 'Yes'. \n2.If there is no popup or no devices could be found to connect,please turn on the WLAN manually.Scan QR code/Through the URL to get the video of connection:https://bit.ly/3OdJ311"},
    {"cast_airplay_str1", "      1. Sul tuo dispositivo iOS,attiva il WI-FI e connetti "},
    {"cast_airplay_str2", "      2. Aprire Centro di controllo e Screen Mirroring. \n3. Seleziona e Connetti "},
    {"cast_airplay_str3", "Nota : 1. il router WIFI deve attivare il DHCP per evitare errori di connessione. \n2. Scansionare il codice QR/Attraverso l'URL per la connessione del video: https://bit.ly/3OdJ311"},
    {NULL, NULL} // End mark
};

static lv_i18n_phrase_t it_plurals_other[] = {
    {"songs", "(%d canzoni)"},
    {NULL, NULL} // End mark
};

static uint8_t it_plural_fn(int32_t num)
{
    uint32_t n = op_n(num); UNUSED(n);
    uint32_t i = op_i(n); UNUSED(i);
    uint32_t v = op_v(n); UNUSED(v);

    if ((i == 1 && v == 0)) return LV_I18N_PLURAL_TYPE_ONE;
    return LV_I18N_PLURAL_TYPE_OTHER;
}

static const lv_i18n_lang_t it_lang = {
    .locale_name = "it",
    .singulars = it_singulars,
    .plurals[LV_I18N_PLURAL_TYPE_OTHER] = it_plurals_other,
    .locale_plural_fn = it_plural_fn
};

static lv_i18n_phrase_t zh_cn_singulars[] = {
    {"setting_p_picture_setting", "图像设置"},
    {"setting_p_picture_mode", "图像模式"},
    {"setting_p_picture_mode_type_standard", "标准"},
    {"setting_p_picture_scale", "缩放模式"},
    {"setting_p_picture_color_temp", "色温"},
    {"setting_p_picture_color_temp_type_standard", "标准"},
    {"setting_p_picture_rate", "投影缩放"},
    {"setting_p_picture_rate_100", "100%"},
    {"setting_p_picture_power_bank_mode", "充电宝亮度模式"},
    {"setting_p_picture_power_bank_mode_low", "低"},
    {"setting_p_picture_mode_contrast", "对比度"},
    {"setting_p_picture_mode_brightness", "亮度"},
    {"setting_p_picture_mode_colour", "色彩"},
    {"setting_p_picture_mode_sharpness", "锐度"},
    {"setting_p_picture_color_temp_red", "红"},
    {"setting_p_picture_color_temp_green", "绿"},
    {"setting_p_picture_color_temp_blue", "蓝"},
    {"setting_p_picture_mode_type_standard_soft", "柔和"},
    {"setting_p_picture_mode_type_standard_user", "用户"},
    {"setting_p_picture_mode_type_standard_dynamic", "动态"},
    {"setting_p_picture_color_temp_type_warm", "暖色"},
    {"setting_p_picture_color_temp_type_user", "用户"},
    {"setting_p_picture_color_temp_type_cool", "冷色"},
    {"setting_p_picture_scale_auto", "低"},
    {"setting_p_picture_power_bank_mode_middle", "中"},
    {"setting_p_picture_power_bank_mode_high", "高"},
    {"setting_p_sound_setting", "声音设置"},
    {"setting_p_sound_mode", "声音模式"},
    {"setting_p_sound_mode_type_standard", "标准"},
    {"setting_p_sound_surround", "环绕声"},
    {"setting_p_sound_surround_off", "关"},
    {"setting_p_sound_auto_volume", "自动音量"},
    {"setting_p_sound_auto_volume_off", "关"},
    {"setting_p_sound_mode_treble", "低音"},
    {"setting_p_sound_mode_bass", "高音"},
    {"setting_p_sound_mode_type_music", "音乐"},
    {"setting_p_sound_mode_type_movie", "电影"},
    {"setting_p_sound_mode_type_sport", "运动"},
    {"setting_p_sound_mode_type_user", "用户"},
    {"setting_p_system_setting", "系统设置"},
    {"setting_p_system_language", "菜单语言"},
    {"setting_p_system_osd_time", "菜单显示时间"},
    {"setting_p_system_osd_time_off", "关"},
    {"setting_p_system_restore_factory_mode", "恢复出厂设置"},
    {"setting_p_system_osd_time_5", "5秒"},
    {"setting_p_system_osd_time_10", "10秒"},
    {"setting_p_system_osd_time_15", "15秒"},
    {"setting_p_system_osd_time_20", "20秒"},
    {"setting_p_system_osd_time_25", "25秒"},
    {"setting_p_system_osd_time_30", "30秒"},
    {"media_category_p_all", "全部文件"},
    {"media_category_p_video", "视频文件"},
    {"media_category_p_music", "音乐文件"},
    {"media_category_p_photo", "图片文件"},
    {"media_category_p_text", "文本文件"},
    {"media_file_p_return", "返回上一层"},
    {"media_file_p_path", "路径："},
    {"media_no_lyric", "暂无歌词"},
    {"media_no_device", "无设备"},
    {"media_udisk_removed", "U盘已移除"},
    {"home_movie", "视频"},
    {"home_music", "音乐"},
    {"home_picture", "图片"},
    {"home_mirroring", "手机同屏"},
    {"home_udisk", "U盘"},
    {"home_hdmi", "高清"},
    {"home_setting", "设置"},
    {"language_espaol", "Español"},
    {"language_deutsch", "Deutsch"},
    {"language_english", "English"},
    {"language_italiano", "Italiano"},
    {"language_france", "Français"},
    {"language_chinese", "简体中文"},
    {"setting_p_net_work", "网络设置"},
    {"setting_p_projector", "投影设置"},
    {"setting_p_picture", "图像设置"},
    {"setting_p_sound", "声音设置"},
    {"setting_p_system", "系统设置"},
    {"setting_p_upgrade", "系统升级"},
    {"setting_p_usb_upgrade", "软件升级(USB)"},
    {"setting_p_ota_upgrade", "软件升级(OTA)"},
    {"setting_p_projector_info", "关于投影"},
    {"setting_p_sound_surround_srs", "SRS 环绕"},
    {"setting_p_sound_auto_volume_on", "开"},
    {"setting_p_wifi", "Wifi"},
    {"setting_p_bluetooth", "蓝牙"},
    {"setting_p_refresh", "刷新"},
    {"setting_p_wifi_connected", "已连接WLAN"},
    {"setting_p_wifi_available", "可用WLAN"},
    {"setting_p_code", "密码"},
    {"setting_p_show_code", "显示密码"},
    {"setting_p_connect", "连接"},
    {"setting_p_ok", "确认"},
    {"setting_p_cancel", "取消"},
    {"setting_p_waiting", "等待中..."},
    {"setting_p_be_sure", "确定?"},
    {"hdmi_no_single", "无信号"},
    {"cast_mira", "安卓同屏"},
    {"cast_airplay", "苹果同屏"},
    {"cast_wait_for_connect", "等待连接..."},
    {"cast_connecting", "连接中..."},
    {"cast_password", "密码"},
    {"cast_mira_str1", "1. 在安卓手机端打开多屏互动或同屏应用功能.\n2. 选择搜索结果列表里面的投屏设备:  "},
    {"cast_mira_str2", "        注意 : 1.如果搜索过程中弹出打开 WLAN 的提示框,请根据提示操作选择“是”打开WLAN. \n                 2.如果没有搜索到投屏设备,也没弹出提示框,请手动打开 WLAN.\n                 3.扫描二维码/通过网址获取连接视频:https://bit.ly/3OdJ311"},
    {"cast_airplay_str1", "1. 在你的iOS设备上,打开WiFi,搜索和连接"},
    {"cast_airplay_str2", "2. 打开控制中心和屏幕镜像,寻找可以镜像的设备.\n3. 选择并连接"},
    {"cast_airplay_str3", "\n         注意 : 1. 有些路由器会关闭DHCP,可能导致同屏器连不上路由器的WIFI. \n                  2. 扫描二维码/通过网址获取连接视频:https://bit.ly/3OdJ311"},
    {NULL, NULL} // End mark
};

static lv_i18n_phrase_t zh_cn_plurals_other[] = {
    {"songs", "(%d 首)"},
    {NULL, NULL} // End mark
};

static uint8_t zh_cn_plural_fn(int32_t num)
{



    return LV_I18N_PLURAL_TYPE_OTHER;
}

static const lv_i18n_lang_t zh_cn_lang = {
    .locale_name = "zh-CN",
    .singulars = zh_cn_singulars,
    .plurals[LV_I18N_PLURAL_TYPE_OTHER] = zh_cn_plurals_other,
    .locale_plural_fn = zh_cn_plural_fn
};

const lv_i18n_language_pack_t lv_i18n_language_pack[] = {
    &en_gb_lang,
    &de_lang,
    &es_lang,
    &fr_lang,
    &it_lang,
    &zh_cn_lang,
    NULL // End mark
};

////////////////////////////////////////////////////////////////////////////////


// Internal state
static const lv_i18n_language_pack_t * current_lang_pack;
static const lv_i18n_lang_t * current_lang;


/**
 * Reset internal state. For testing.
 */
void __lv_i18n_reset(void)
{
    current_lang_pack = NULL;
    current_lang = NULL;
}

/**
 * Set the languages for internationalization
 * @param langs pointer to the array of languages. (Last element has to be `NULL`)
 */
int lv_i18n_init(const lv_i18n_language_pack_t * langs)
{
    if(langs == NULL) return -1;
    if(langs[0] == NULL) return -1;

    current_lang_pack = langs;
    current_lang = langs[0];     /*Automatically select the first language*/
    return 0;
}

/**
 * Change the localization (language)
 * @param l_name name of the translation locale to use. E.g. "en-GB"
 */
int lv_i18n_set_locale(const char * l_name)
{
    if(current_lang_pack == NULL) return -1;

    uint16_t i;

    for(i = 0; current_lang_pack[i] != NULL; i++) {
        // Found -> finish
        if(strcmp(current_lang_pack[i]->locale_name, l_name) == 0) {
            current_lang = current_lang_pack[i];
            return 0;
        }
    }

    return -1;
}


static const char * __lv_i18n_get_text_core(lv_i18n_phrase_t * trans, const char * msg_id)
{
    uint16_t i;
    for(i = 0; trans[i].msg_id != NULL; i++) {
        if(strcmp(trans[i].msg_id, msg_id) == 0) {
            /*The msg_id has found. Check the translation*/
            if(trans[i].translation) return trans[i].translation;
        }
    }

    return NULL;
}


/**
 * Get the translation from a message ID
 * @param msg_id message ID
 * @return the translation of `msg_id` on the set local
 */
const char * lv_i18n_get_text(const char * msg_id)
{
    if(current_lang == NULL) return msg_id;

    const lv_i18n_lang_t * lang = current_lang;
    const void * txt;

    // Search in current locale
    if(lang->singulars != NULL) {
        txt = __lv_i18n_get_text_core(lang->singulars, msg_id);
        if (txt != NULL) return txt;
    }

    // Try to fallback
    if(lang == current_lang_pack[0]) return msg_id;
    lang = current_lang_pack[0];

    // Repeat search for default locale
    if(lang->singulars != NULL) {
        txt = __lv_i18n_get_text_core(lang->singulars, msg_id);
        if (txt != NULL) return txt;
    }

    return msg_id;
}

/**
 * Get the translation from a message ID and apply the language's plural rule to get correct form
 * @param msg_id message ID
 * @param num an integer to select the correct plural form
 * @return the translation of `msg_id` on the set local
 */
const char * lv_i18n_get_text_plural(const char * msg_id, int32_t num)
{
    if(current_lang == NULL) return msg_id;

    const lv_i18n_lang_t * lang = current_lang;
    const void * txt;
    lv_i18n_plural_type_t ptype;

    // Search in current locale
    if(lang->locale_plural_fn != NULL) {
        ptype = lang->locale_plural_fn(num);

        if(lang->plurals[ptype] != NULL) {
            txt = __lv_i18n_get_text_core(lang->plurals[ptype], msg_id);
            if (txt != NULL) return txt;
        }
    }

    // Try to fallback
    if(lang == current_lang_pack[0]) return msg_id;
    lang = current_lang_pack[0];

    // Repeat search for default locale
    if(lang->locale_plural_fn != NULL) {
        ptype = lang->locale_plural_fn(num);

        if(lang->plurals[ptype] != NULL) {
            txt = __lv_i18n_get_text_core(lang->plurals[ptype], msg_id);
            if (txt != NULL) return txt;
        }
    }

    return msg_id;
}

/**
 * Get the name of the currently used locale.
 * @return name of the currently used locale. E.g. "en-GB"
 */
const char * lv_i18n_get_current_locale(void)
{
    if(!current_lang) return NULL;
    return current_lang->locale_name;
}

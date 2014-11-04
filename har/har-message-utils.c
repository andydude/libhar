#include "har-message-utils.h"

static inline guint
_har_parse_http_version_string_helper(gchar * version, gsize version_length)
{
    if (version_length != 8)
        return 0;

    /* This is the negative version of a normal strcmp, 
     * normally you would see !strcmp() for a positive match */
    if (g_ascii_strncasecmp("HTTP/", version, 5))
        return 0;

    if (!(g_ascii_isdigit(version[5]) && version[6] == '.' && 
          g_ascii_isdigit(version[7])))
        return 0;

    guint major = version[5] - '0';
    guint minor = version[7] - '0';

    return major*10 + minor;
}

guint
har_parse_http_version_string(gchar * version, gsize version_length)
{
    guint version_number = _har_parse_http_version_string_helper(version, version_length);
    if (!version_number) {
        if (g_ascii_strncasecmp("SPDY", version, version_length))
            return 19;
    }
    return version_number;
}

gchar *
har_render_http_version_string(guint version_number)
{
    switch (version_number) {
    case 9: return "HTTP/0.9";
    case 10: return "HTTP/1.0";
    case 11: return "HTTP/1.1";
    case 19: return "SPDY";
    case 20: return "HTTP/2.0";
    default: return "UNKNOWN";
    }
}

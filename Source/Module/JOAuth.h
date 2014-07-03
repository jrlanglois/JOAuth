#ifndef JOAUTH_MODULE_H
#define JOAUTH_MODULE_H

/**
    Turn this flag on to avoid including the standard JUCE library header here.

    This could be useful for designing your own master header files or modules,
    where you want to reduce knowingly redundant inclusions.
*/
#if ! JOAUTH_DONT_INCLUDE_JUCE_HEADER
 #include "JuceHeader.h"
#endif

namespace joauth
{
   #ifndef JOAUTH_OAUTH_1_CLIENT_H
    #include "Client/OAuth1Client.h"
   #endif //JOAUTH_OAUTH_1_CLIENT_H

   #ifndef JOAUTH_OAUTH_1A_CLIENT_H
    #include "Client/OAuth1aClient.h"
   #endif //JOAUTH_OAUTH_1A_CLIENT_H

   #ifndef JOAUTH_OAUTH_2_CLIENT_H
    #include "Client/OAuth2Client.h"
   #endif //JOAUTH_OAUTH_2_CLIENT_H
}

/**
    If your code uses the JOAuth classes often, then switching this flag on
    will obviously save you a lot of typing.
*/
#if JOAUTH_SET_USING_NAMESPACE
 using namespace joauth;
#endif

#endif //JOAUTH_MODULE_H
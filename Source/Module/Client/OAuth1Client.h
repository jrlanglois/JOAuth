#ifndef JOAUTH_OAUTH_1_H
#define JOAUTH_OAUTH_1_H

#include "../Source/OAuthSource.h"

/**
    An OAuth 1.0 client implementation.

    @see OAuth1aClient, OAuth2Client
*/
class OAuth1Client
{
public:
    /** Constructor */
    OAuth1Client();

    /** Destructor */
    ~OAuth1Client();

private:
    //==============================================================================

    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (OAuth1Client)
};

#endif //JOAUTH_OAUTH_1_H
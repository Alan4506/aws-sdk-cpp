﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/cognito-idp/CognitoIdentityProvider_EXPORTS.h>
#include <aws/cognito-idp/model/ChallengeNameType.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <aws/core/utils/memory/stl/AWSMap.h>
#include <aws/cognito-idp/model/AuthenticationResultType.h>
#include <aws/core/utils/memory/stl/AWSVector.h>
#include <utility>

namespace Aws
{
template<typename RESULT_TYPE>
class AmazonWebServiceResult;

namespace Utils
{
namespace Json
{
  class JsonValue;
} // namespace Json
} // namespace Utils
namespace CognitoIdentityProvider
{
namespace Model
{
  /**
   * <p>Initiates the authentication response, as an administrator.</p><p><h3>See
   * Also:</h3>   <a
   * href="http://docs.aws.amazon.com/goto/WebAPI/cognito-idp-2016-04-18/AdminInitiateAuthResponse">AWS
   * API Reference</a></p>
   */
  class AdminInitiateAuthResult
  {
  public:
    AWS_COGNITOIDENTITYPROVIDER_API AdminInitiateAuthResult();
    AWS_COGNITOIDENTITYPROVIDER_API AdminInitiateAuthResult(const Aws::AmazonWebServiceResult<Aws::Utils::Json::JsonValue>& result);
    AWS_COGNITOIDENTITYPROVIDER_API AdminInitiateAuthResult& operator=(const Aws::AmazonWebServiceResult<Aws::Utils::Json::JsonValue>& result);


    ///@{
    /**
     * <p>The name of the challenge that you're responding to with this call. This is
     * returned in the <code>AdminInitiateAuth</code> response if you must pass another
     * challenge.</p> <p>Possible challenges include the following:</p>  <p>All
     * of the following challenges require <code>USERNAME</code> and, when the app
     * client has a client secret, <code>SECRET_HASH</code> in the parameters.</p>
     *  <ul> <li> <p> <code>WEB_AUTHN</code>: Respond to the challenge with the
     * results of a successful authentication with a WebAuthn authenticator, or
     * passkey. Examples of WebAuthn authenticators include biometric devices and
     * security keys.</p> </li> <li> <p> <code>PASSWORD</code>: Respond with
     * <code>USER_PASSWORD_AUTH</code> parameters: <code>USERNAME</code> (required),
     * <code>PASSWORD</code> (required), <code>SECRET_HASH</code> (required if the app
     * client is configured with a client secret), <code>DEVICE_KEY</code>.</p> </li>
     * <li> <p> <code>PASSWORD_SRP</code>: Respond with <code>USER_SRP_AUTH</code>
     * parameters: <code>USERNAME</code> (required), <code>SRP_A</code> (required),
     * <code>SECRET_HASH</code> (required if the app client is configured with a client
     * secret), <code>DEVICE_KEY</code>.</p> </li> <li> <p>
     * <code>SELECT_CHALLENGE</code>: Respond to the challenge with
     * <code>USERNAME</code> and an <code>ANSWER</code> that matches one of the
     * challenge types in the <code>AvailableChallenges</code> response parameter.</p>
     * </li> <li> <p> <code>SMS_MFA</code>: Respond with an <code>SMS_MFA_CODE</code>
     * that your user pool delivered in an SMS message.</p> </li> <li> <p>
     * <code>EMAIL_OTP</code>: Respond with an <code>EMAIL_OTP_CODE</code> that your
     * user pool delivered in an email message.</p> </li> <li> <p>
     * <code>PASSWORD_VERIFIER</code>: Respond with
     * <code>PASSWORD_CLAIM_SIGNATURE</code>, <code>PASSWORD_CLAIM_SECRET_BLOCK</code>,
     * and <code>TIMESTAMP</code> after client-side SRP calculations.</p> </li> <li>
     * <p> <code>CUSTOM_CHALLENGE</code>: This is returned if your custom
     * authentication flow determines that the user should pass another challenge
     * before tokens are issued. The parameters of the challenge are determined by your
     * Lambda function.</p> </li> <li> <p> <code>DEVICE_SRP_AUTH</code>: Respond with
     * the initial parameters of device SRP authentication. For more information, see
     * <a
     * href="https://docs.aws.amazon.com/cognito/latest/developerguide/amazon-cognito-user-pools-device-tracking.html#user-pools-remembered-devices-signing-in-with-a-device">Signing
     * in with a device</a>.</p> </li> <li> <p> <code>DEVICE_PASSWORD_VERIFIER</code>:
     * Respond with <code>PASSWORD_CLAIM_SIGNATURE</code>,
     * <code>PASSWORD_CLAIM_SECRET_BLOCK</code>, and <code>TIMESTAMP</code> after
     * client-side SRP calculations. For more information, see <a
     * href="https://docs.aws.amazon.com/cognito/latest/developerguide/amazon-cognito-user-pools-device-tracking.html#user-pools-remembered-devices-signing-in-with-a-device">Signing
     * in with a device</a>.</p> </li> <li> <p> <code>NEW_PASSWORD_REQUIRED</code>: For
     * users who are required to change their passwords after successful first login.
     * Respond to this challenge with <code>NEW_PASSWORD</code> and any required
     * attributes that Amazon Cognito returned in the <code>requiredAttributes</code>
     * parameter. You can also set values for attributes that aren't required by your
     * user pool and that your app client can write.</p> <p>Amazon Cognito only returns
     * this challenge for users who have temporary passwords. When you create
     * passwordless users, you must provide values for all required attributes.</p>
     *  <p>In a <code>NEW_PASSWORD_REQUIRED</code> challenge response, you can't
     * modify a required attribute that already has a value. In
     * <code>AdminRespondToAuthChallenge</code> or <code>RespondToAuthChallenge</code>,
     * set a value for any keys that Amazon Cognito returned in the
     * <code>requiredAttributes</code> parameter, then use the
     * <code>AdminUpdateUserAttributes</code> or <code>UpdateUserAttributes</code> API
     * operation to modify the value of any additional attributes.</p>  </li>
     * <li> <p> <code>MFA_SETUP</code>: For users who are required to setup an MFA
     * factor before they can sign in. The MFA types activated for the user pool will
     * be listed in the challenge parameters <code>MFAS_CAN_SETUP</code> value. </p>
     * <p>To set up time-based one-time password (TOTP) MFA, use the session returned
     * in this challenge from <code>InitiateAuth</code> or
     * <code>AdminInitiateAuth</code> as an input to
     * <code>AssociateSoftwareToken</code>. Then, use the session returned by
     * <code>VerifySoftwareToken</code> as an input to
     * <code>RespondToAuthChallenge</code> or <code>AdminRespondToAuthChallenge</code>
     * with challenge name <code>MFA_SETUP</code> to complete sign-in. </p> <p>To set
     * up SMS or email MFA, collect a <code>phone_number</code> or <code>email</code>
     * attribute for the user. Then restart the authentication flow with an
     * <code>InitiateAuth</code> or <code>AdminInitiateAuth</code> request. </p> </li>
     * </ul>
     */
    inline const ChallengeNameType& GetChallengeName() const{ return m_challengeName; }
    inline void SetChallengeName(const ChallengeNameType& value) { m_challengeName = value; }
    inline void SetChallengeName(ChallengeNameType&& value) { m_challengeName = std::move(value); }
    inline AdminInitiateAuthResult& WithChallengeName(const ChallengeNameType& value) { SetChallengeName(value); return *this;}
    inline AdminInitiateAuthResult& WithChallengeName(ChallengeNameType&& value) { SetChallengeName(std::move(value)); return *this;}
    ///@}

    ///@{
    /**
     * <p>The session that must be passed to challenge-response requests. If an
     * <code>AdminInitiateAuth</code> or <code>AdminRespondToAuthChallenge</code> API
     * request results in another authentication challenge, Amazon Cognito returns a
     * session ID and the parameters of the next challenge. Pass this session ID in the
     * <code>Session</code> parameter of <code>AdminRespondToAuthChallenge</code>.</p>
     */
    inline const Aws::String& GetSession() const{ return m_session; }
    inline void SetSession(const Aws::String& value) { m_session = value; }
    inline void SetSession(Aws::String&& value) { m_session = std::move(value); }
    inline void SetSession(const char* value) { m_session.assign(value); }
    inline AdminInitiateAuthResult& WithSession(const Aws::String& value) { SetSession(value); return *this;}
    inline AdminInitiateAuthResult& WithSession(Aws::String&& value) { SetSession(std::move(value)); return *this;}
    inline AdminInitiateAuthResult& WithSession(const char* value) { SetSession(value); return *this;}
    ///@}

    ///@{
    /**
     * <p>The parameters of an authentication challenge. Amazon Cognito returns
     * challenge parameters as a guide to the responses your user or application must
     * provide for the returned <code>ChallengeName</code>. Calculate responses to the
     * challenge parameters and pass them in the <code>ChallengeParameters</code> of
     * <code>AdminRespondToAuthChallenge</code>.</p> <p>All challenges require
     * <code>USERNAME</code> and, when the app client has a client secret,
     * <code>SECRET_HASH</code>.</p> <p>In SRP challenges, Amazon Cognito returns the
     * <code>username</code> attribute in <code>USER_ID_FOR_SRP</code> instead of any
     * email address, preferred username, or phone number alias that you might have
     * specified in your <code>AdminInitiateAuth</code> request. You must use the
     * username and not an alias in the <code>ChallengeResponses</code> of your
     * challenge response.</p>
     */
    inline const Aws::Map<Aws::String, Aws::String>& GetChallengeParameters() const{ return m_challengeParameters; }
    inline void SetChallengeParameters(const Aws::Map<Aws::String, Aws::String>& value) { m_challengeParameters = value; }
    inline void SetChallengeParameters(Aws::Map<Aws::String, Aws::String>&& value) { m_challengeParameters = std::move(value); }
    inline AdminInitiateAuthResult& WithChallengeParameters(const Aws::Map<Aws::String, Aws::String>& value) { SetChallengeParameters(value); return *this;}
    inline AdminInitiateAuthResult& WithChallengeParameters(Aws::Map<Aws::String, Aws::String>&& value) { SetChallengeParameters(std::move(value)); return *this;}
    inline AdminInitiateAuthResult& AddChallengeParameters(const Aws::String& key, const Aws::String& value) { m_challengeParameters.emplace(key, value); return *this; }
    inline AdminInitiateAuthResult& AddChallengeParameters(Aws::String&& key, const Aws::String& value) { m_challengeParameters.emplace(std::move(key), value); return *this; }
    inline AdminInitiateAuthResult& AddChallengeParameters(const Aws::String& key, Aws::String&& value) { m_challengeParameters.emplace(key, std::move(value)); return *this; }
    inline AdminInitiateAuthResult& AddChallengeParameters(Aws::String&& key, Aws::String&& value) { m_challengeParameters.emplace(std::move(key), std::move(value)); return *this; }
    inline AdminInitiateAuthResult& AddChallengeParameters(const char* key, Aws::String&& value) { m_challengeParameters.emplace(key, std::move(value)); return *this; }
    inline AdminInitiateAuthResult& AddChallengeParameters(Aws::String&& key, const char* value) { m_challengeParameters.emplace(std::move(key), value); return *this; }
    inline AdminInitiateAuthResult& AddChallengeParameters(const char* key, const char* value) { m_challengeParameters.emplace(key, value); return *this; }
    ///@}

    ///@{
    /**
     * <p>The outcome of successful authentication. This is only returned if the user
     * pool has no additional challenges to return. If Amazon Cognito returns another
     * challenge, the response includes <code>ChallengeName</code>,
     * <code>ChallengeParameters</code>, and <code>Session</code> so that your user can
     * answer the challenge.</p>
     */
    inline const AuthenticationResultType& GetAuthenticationResult() const{ return m_authenticationResult; }
    inline void SetAuthenticationResult(const AuthenticationResultType& value) { m_authenticationResult = value; }
    inline void SetAuthenticationResult(AuthenticationResultType&& value) { m_authenticationResult = std::move(value); }
    inline AdminInitiateAuthResult& WithAuthenticationResult(const AuthenticationResultType& value) { SetAuthenticationResult(value); return *this;}
    inline AdminInitiateAuthResult& WithAuthenticationResult(AuthenticationResultType&& value) { SetAuthenticationResult(std::move(value)); return *this;}
    ///@}

    ///@{
    /**
     * <p>This response parameter lists the available authentication challenges that
     * users can select from in <a
     * href="https://docs.aws.amazon.com/cognito/latest/developerguide/authentication-flows-selection-sdk.html#authentication-flows-selection-choice">choice-based
     * authentication</a>. For example, they might be able to choose between passkey
     * authentication, a one-time password from an SMS message, and a traditional
     * password.</p>
     */
    inline const Aws::Vector<ChallengeNameType>& GetAvailableChallenges() const{ return m_availableChallenges; }
    inline void SetAvailableChallenges(const Aws::Vector<ChallengeNameType>& value) { m_availableChallenges = value; }
    inline void SetAvailableChallenges(Aws::Vector<ChallengeNameType>&& value) { m_availableChallenges = std::move(value); }
    inline AdminInitiateAuthResult& WithAvailableChallenges(const Aws::Vector<ChallengeNameType>& value) { SetAvailableChallenges(value); return *this;}
    inline AdminInitiateAuthResult& WithAvailableChallenges(Aws::Vector<ChallengeNameType>&& value) { SetAvailableChallenges(std::move(value)); return *this;}
    inline AdminInitiateAuthResult& AddAvailableChallenges(const ChallengeNameType& value) { m_availableChallenges.push_back(value); return *this; }
    inline AdminInitiateAuthResult& AddAvailableChallenges(ChallengeNameType&& value) { m_availableChallenges.push_back(std::move(value)); return *this; }
    ///@}

    ///@{
    
    inline const Aws::String& GetRequestId() const{ return m_requestId; }
    inline void SetRequestId(const Aws::String& value) { m_requestId = value; }
    inline void SetRequestId(Aws::String&& value) { m_requestId = std::move(value); }
    inline void SetRequestId(const char* value) { m_requestId.assign(value); }
    inline AdminInitiateAuthResult& WithRequestId(const Aws::String& value) { SetRequestId(value); return *this;}
    inline AdminInitiateAuthResult& WithRequestId(Aws::String&& value) { SetRequestId(std::move(value)); return *this;}
    inline AdminInitiateAuthResult& WithRequestId(const char* value) { SetRequestId(value); return *this;}
    ///@}
  private:

    ChallengeNameType m_challengeName;

    Aws::String m_session;

    Aws::Map<Aws::String, Aws::String> m_challengeParameters;

    AuthenticationResultType m_authenticationResult;

    Aws::Vector<ChallengeNameType> m_availableChallenges;

    Aws::String m_requestId;
  };

} // namespace Model
} // namespace CognitoIdentityProvider
} // namespace Aws

/** @file
  SPDM IO Protocol definition

  Copyright (c) 2020, Intel Corporation. All rights reserved.<BR>
  SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#ifndef __EDKII_SPDM_IO_PROTOCOL_H__
#define __EDKII_SPDM_IO_PROTOCOL_H__

#include <Base.h>
#include <IndustryStandard/Spdm.h>

typedef struct _EDKII_SPDM_IO_PROTOCOL EDKII_SPDM_IO_PROTOCOL;

/**
  Send a SPDM request command to a device.

  @param  This                         Indicates a pointer to the calling context.
  @param  RequestSize                  Size in bytes of the request data buffer.
  @param  Request                      A pointer to a destination buffer to store the request.
                                       The caller is responsible for having
                                       either implicit or explicit ownership of the buffer.
  @param  Timeout                      The timeout, in 100ns units, to use for the execution
                                       of the request. A Timeout value of 0
                                       means that this function will wait indefinitely for the
                                       request to execute. If Timeout is greater
                                       than zero, then this function will return RETURN_TIMEOUT if the
                                       time required to execute the request is greater
                                       than Timeout.
                                       
  @retval RETURN_SUCCESS                  The SPDM request is sent successfully.
  @retval RETURN_DEVICE_ERROR             A device error occurs when the SPDM request is sent to the device.
  @retval RETURN_INVALID_PARAMETER        The Request is NULL or the RequestSize is zero.
  @retval RETURN_TIMEOUT                  A timeout occurred while waiting for the SPDM request
                                       to execute.
**/
typedef
RETURN_STATUS
(EFIAPI *EDKII_SPDM_IO_SEND_REQUEST) (
  IN     EDKII_SPDM_IO_PROTOCOL  *This,
  IN     UINTN                   RequestSize,
  IN     VOID                    *Request,
  IN     UINT64                  Timeout
  );

/**
  Receive a SPDM response from a device.

  @param  This                         Indicates a pointer to the calling context.
  @param  ResponseSize                 Size in bytes of the response data buffer.
  @param  Response                     A pointer to a destination buffer to store the response.
                                       The caller is responsible for having
                                       either implicit or explicit ownership of the buffer.
  @param  Timeout                      The timeout, in 100ns units, to use for the execution
                                       of the response. A Timeout value of 0
                                       means that this function will wait indefinitely for the
                                       response to execute. If Timeout is greater
                                       than zero, then this function will return RETURN_TIMEOUT if the
                                       time required to execute the response is greater
                                       than Timeout.
                                       
  @retval RETURN_SUCCESS                  The SPDM response is received successfully.
  @retval RETURN_DEVICE_ERROR             A device error occurs when the SPDM response is received from the device.
  @retval RETURN_INVALID_PARAMETER        The Reponse is NULL, ResponseSize is NULL or
                                       the *RequestSize is zero.
  @retval RETURN_TIMEOUT                  A timeout occurred while waiting for the SPDM response
                                       to execute.
**/
typedef
RETURN_STATUS
(EFIAPI *EDKII_SPDM_IO_RECEIVE_RESPONSE) (
  IN     EDKII_SPDM_IO_PROTOCOL  *This,
  IN OUT UINTN                   *ResponseSize,
  IN OUT VOID                    *Response,
  IN     UINT64                  Timeout
  );

typedef enum {
  EdkiiSpdmIoSecureMessagingTypeDmtfMtcp,
  EdkiiSpdmIoSecureMessagingTypePciSigDoe,
  EdkiiSpdmIoSecureMessagingTypeMax,
} EDKII_SPDM_IO_SECURE_MESSAGING_TYPE;

/**
  Return Secure Messaging type.

  @param  This                         Indicates a pointer to the calling context.
  @param  SecureMessagingType          Secure messaging type.
                                       
  @retval RETURN_SUCCESS                  The secure messaging type is returned successfully.
  @retval RETURN_INVALID_PARAMETER        The SecureMessagingType is NULL.
**/
typedef
RETURN_STATUS
(EFIAPI *EDKII_SPDM_IO_GET_SECURE_MESSAGING_TYPE) (
  IN     EDKII_SPDM_IO_PROTOCOL              *This,
     OUT UINTN                               *SecureMessagingTypeCount,
     OUT EDKII_SPDM_IO_SECURE_MESSAGING_TYPE **SecureMessagingType
  );

/**
  Send a SPDM request command to a device.

  The request is a data blob to send to the messaging device directly,
  including session ID, length, encrypted message and MAC.
  The caller need use GetSecureMessagingType() to decide the format of the message.

  @param  This                         Indicates a pointer to the calling context.
  @param  RequestSize                  Size in bytes of the request data buffer.
  @param  Request                      A pointer to a destination buffer to store the request.
                                       The caller is responsible for having
                                       either implicit or explicit ownership of the buffer.
  @param  Timeout                      The timeout, in 100ns units, to use for the execution
                                       of the request. A Timeout value of 0
                                       means that this function will wait indefinitely for the
                                       request to execute. If Timeout is greater
                                       than zero, then this function will return RETURN_TIMEOUT if the
                                       time required to execute the request is greater
                                       than Timeout.
                                       
  @retval RETURN_SUCCESS                  The SPDM request is sent successfully.
  @retval RETURN_DEVICE_ERROR             A device error occurs when the SPDM request is sent to the device.
  @retval RETURN_INVALID_PARAMETER        The Request is NULL or the RequestSize is zero.
  @retval RETURN_TIMEOUT                  A timeout occurred while waiting for the SPDM request
                                       to execute.
**/
typedef
RETURN_STATUS
(EFIAPI *EDKII_SPDM_IO_SECURE_SEND_REQUEST) (
  IN     EDKII_SPDM_IO_PROTOCOL                 *This,
  IN     EDKII_SPDM_IO_SECURE_MESSAGING_TYPE    SecureMessagingType,
  IN     UINT8                                  SessionId,
  IN     UINTN                                  RequestSize,
  IN     VOID                                   *Request,
  IN     UINT64                                 Timeout
  );

/**
  Receive a SPDM response from a device.

  The response is a data blob received from the messaging device directly,
  including session ID, length, encrypted message and MAC.
  The caller need use GetSecureMessagingType() to decide the format of the message.

  @param  This                         Indicates a pointer to the calling context.
  @param  ResponseSize                 Size in bytes of the response data buffer.
  @param  Response                     A pointer to a destination buffer to store the response.
                                       The caller is responsible for having
                                       either implicit or explicit ownership of the buffer.
  @param  Timeout                      The timeout, in 100ns units, to use for the execution
                                       of the response. A Timeout value of 0
                                       means that this function will wait indefinitely for the
                                       response to execute. If Timeout is greater
                                       than zero, then this function will return RETURN_TIMEOUT if the
                                       time required to execute the response is greater
                                       than Timeout.
                                       
  @retval RETURN_SUCCESS                  The SPDM response is received successfully.
  @retval RETURN_DEVICE_ERROR             A device error occurs when the SPDM response is received from the device.
  @retval RETURN_INVALID_PARAMETER        The Reponse is NULL, ResponseSize is NULL or
                                       the *RequestSize is zero.
  @retval RETURN_TIMEOUT                  A timeout occurred while waiting for the SPDM response
                                       to execute.
**/
typedef
RETURN_STATUS
(EFIAPI *EDKII_SPDM_IO_SECURE_RECEIVE_RESPONSE) (
  IN     EDKII_SPDM_IO_PROTOCOL                 *This,
  IN     EDKII_SPDM_IO_SECURE_MESSAGING_TYPE    SecureMessagingType,
  IN     UINT8                                  SessionId,
  IN OUT UINTN                                  *ResponseSize,
  IN OUT VOID                                   *Response,
  IN     UINT64                                 Timeout
  );

struct _EDKII_SPDM_IO_PROTOCOL {
  EDKII_SPDM_IO_SEND_REQUEST               SendRequest;
  EDKII_SPDM_IO_RECEIVE_RESPONSE           ReceiveResponse;
  EDKII_SPDM_IO_GET_SECURE_MESSAGING_TYPE  GetSecureMessagingType;
  EDKII_SPDM_IO_SECURE_SEND_REQUEST        SecureSendRequest;
  EDKII_SPDM_IO_SECURE_RECEIVE_RESPONSE    SecureReceiveResponse;
};

#endif
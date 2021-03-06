cmake_minimum_required(VERSION 2.6)

INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/UnitTest/TestSpdmResponder
                    ${PROJECT_SOURCE_DIR}/Include
                    ${PROJECT_SOURCE_DIR}/Include/Hal 
                    ${PROJECT_SOURCE_DIR}/Include/Hal/${ARCH} 
                    ${PROJECT_SOURCE_DIR}/UnitTest/Include                      
                    ${PROJECT_SOURCE_DIR}/Library/SpdmCommonLib
                    ${PROJECT_SOURCE_DIR}/Library/SpdmResponderLib
                    ${PROJECT_SOURCE_DIR}/UnitTest/CmockaLib/cmocka/include
                    ${PROJECT_SOURCE_DIR}/UnitTest/CmockaLib/cmocka/include/cmockery
                    ${PROJECT_SOURCE_DIR}/UnitTest/SpdmUnitTestCommon            
)

SET(src_TestSpdmResponder
    TestSpdmResponder.c
    TestSpdmResponderVersion.c
    TestSpdmResponderCapability.c
    TestSpdmResponderAlgorithm.c
    TestSpdmResponderDigest.c
    TestSpdmResponderCertificate.c
    TestSpdmResponderChallengeAuth.c
    TestSpdmResponderMeasurement.c
    ${PROJECT_SOURCE_DIR}/UnitTest/SpdmUnitTestCommon/SpdmUnitTestCommon.c
    ${PROJECT_SOURCE_DIR}/UnitTest/SpdmUnitTestCommon/SpdmTestKey.c
    ${PROJECT_SOURCE_DIR}/UnitTest/SpdmUnitTestCommon/SpdmTestSupport.c
)

SET(TestSpdmResponder_LIBRARY
    BaseMemoryLib
    DebugLib  
    SpdmResponderLib 
    SpdmCommonLib
    ${CRYPTO}Lib
    RngLib
    BaseCryptLib${CRYPTO}  
    MemoryAllocationLib
    SpdmSecuredMessageLib
    SpdmTransportTestLib
    CmockaLib
)

ADD_EXECUTABLE(TestSpdmResponder ${src_TestSpdmResponder})

TARGET_LINK_LIBRARIES(TestSpdmResponder ${TestSpdmResponder_LIBRARY})



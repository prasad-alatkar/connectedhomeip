/*
 *
 *    Copyright (c) 2020 Project CHIP Authors
 *    All rights reserved.
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */

// Enable cryptographic functions needed by CHIP which can't be enabled via Kconfig
#define MBEDTLS_ECP_C
#define MBEDTLS_ECDH_C
#define MBEDTLS_HKDF_C
#define MBEDTLS_BIGNUM_C

// Define mbedtls_error()
#define MBEDTLS_ERROR_C

// Use hardware entropy generator
#define MBEDTLS_ENTROPY_HARDWARE_ALT
#undef MBEDTLS_NO_DEFAULT_ENTROPY_SOURCES

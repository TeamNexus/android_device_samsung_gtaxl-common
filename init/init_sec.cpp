/*
   Copyright (c) 2015, The Dokdo Project. All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the following
      disclaimer in the documentation and/or other materials provided
      with the distribution.
    * Neither the name of The Linux Foundation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
   WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
   ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
   BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
   BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
   OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
   IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

   File Name : init_sec.c
   Create Date : 2015.11.03
   Author : Sunghun Ra
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <android-base/properties.h>

#include "log.h"
#include "property_service.h"
#include "util.h"
#include "vendor_init.h"

enum device_variant {
    UNKNOWN = -1,
    T585,

};

namespace android {
namespace init {

void vendor_load_properties()
{	
    std::string platform = android::base::GetProperty("ro.board.platform", "");
    std::string bootloader = android::base::GetProperty("ro.bootloader", "");
	device_variant variant = UNKNOWN;

    if (platform != ANDROID_TARGET) {
        return;
    }

    if (bootloader.find("T585") != std::string::npos) {
        variant = T585;
    } else {
		return;
    }

    switch (variant) {
        case T585:
            /* gtaxllte */
            android::base::SetProperty("ro.build.fingerprint", "samsung/gtaxlltexx/gtaxllte:7.0/NRD90M/T585XXU2BQI9:user/test-keys");
            android::base::SetProperty("ro.build.description", "gtaxlltexx-user 7.0 NRD90M T585XXU2BQI9 release-keys");
            android::base::SetProperty("ro.product.model", "SM-T585");
            android::base::SetProperty("ro.product.device", "gtaxlltexx");
            break;
    std::string device = android::base::GetProperty("ro.product.device", "");
}

}
}

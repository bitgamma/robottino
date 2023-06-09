/****************************************************************************
Copyright 2023 Michele Balistreri

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
****************************************************************************/

#ifndef UNI_PLATFORM_ROBOTTINO_H
#define UNI_PLATFORM_ROBOTTINO_H

#include "uni_platform.h"

float robottino_get_left();
float robottino_get_right();

struct uni_platform* uni_platform_robottino_create(void);

#endif  // UNI_PLATFORM_ROBOTTINO_H

#ifndef TESTS_H
#define TESTS_H

#include "registry.h"
#include "constants.h"

static_assert(registry::isValidChannelId(constants::ch1Id));
static_assert(registry::isValidChannelId(constants::ch2Id));
static_assert(registry::isValidChannelId(constants::ch3Id));
static_assert(registry::isValidChannelId(constants::ch4Id));
static_assert(!registry::isValidChannelId(0));
static_assert(!registry::isValidChannelId(5));

#endif
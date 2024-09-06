#pragma once
#include<iostream>
#include "clsUser.h"

static enum enMode {Login = 1, Register = 2, Logout = 3};
static clsUser CurrentUser = clsUser::Find("", "");
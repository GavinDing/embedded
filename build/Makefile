#******************************************************************************
#*                                                                            *
#* This program is distributed in the hope that it will be useful, but        *
#* WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY *
#* or FITNESS FOR A PARTICULAR PURPOSE. This file and program are licensed    *
#* under the GNU Lesser General Public License Version 3, 29 June 2007.       *
#* The complete license can be accessed from the following location:          *
#* http://opensource.org/licenses/lgpl-3.0.html                               *
#*                                                                            *
#* Author: Yun Li             (yunli.open@gmail.com)                          *
#*   Date: 05/22/2010                                                         *
#*                                                                            *
#* Author: Gavin Ding         (fanfan.ding.ict@gmail.com)                     *
#*   Date: 03/17/2013                                                         *
#*                                                                            *
#******************************************************************************

#******************************************************************************
# REVISION HISTORY
# ================
# 
# Date         Version       Name              Description
# ----------   ------------  ----------------  --------------------------------
# 03/17/2013   V001.000.000  Gavin Ding        rewrite this file
# ----------   ------------  ----------------  --------------------------------
#
#******************************************************************************

### build path ###
ROOT  = $(realpath ..)
BUILD = $(realpath .)

### build targets and directories ###
RELEASE = release
DEBUG   = debug
UNITEST = unitest
TEST    = test
CREPORT = creport
SCHECK  = scheck
CLEAN   = clean
TOUCH   = touch
FORCE   = force

DIR_RELEASE  = release
DIR_DEBUG    = debug
DIR_UNITEST  = unitest
DIR_COVERAGE = coverage
DIR_SCHECK   = scheck

### prerequisite directories ###
COMMON_DIRS += $(ROOT)/code/src/common

NONUT_DIRS  += 
# NONUT_DIRS  += $(ROOT)/code/src/cii

UT_DIRS     += $(ROOT)/tests/src/common
# UT_DIRS     += $(ROOT)/tests/src/cii

MAKE_DIRS   := $(COMMON_DIRS)

### commands and flags ###
RM      = rm
RMFLAGS = -fr
RMS     = $(DIR_RELEASE) $(DIR_DEBUG) $(DIR_UNITEST) $(DIR_COVERAGE) $(DIR_SCHECK)
MKDIR   = mkdir

### MAKECMDGOALS ###
ifeq ("$(MAKECMDGOALS)", "")
    MAKECMDGOALS = $(RELEASE)
endif

ifeq ("$(MAKECMDGOALS)", "$(RELEASE)")
    MAKE_DIRS += $(NONUT_DIRS)
endif
ifeq ("$(MAKECMDGOALS)", "$(DEBUG)")
    MAKE_DIRS += $(NONUT_DIRS)
endif
ifeq ("$(MAKECMDGOALS)", "$(UNITEST)")
    MAKE_DIRS += $(UT_DIRS)
endif
ifeq ("$(MAKECMDGOALS)", "$(CREPORT)")
    MAKE_DIRS += $(UT_DIRS)
endif
ifeq ("$(MAKECMDGOALS)", "$(SCHECK)")
    MAKE_DIRS += $(NONUT_DIRS)
endif
ifeq ("$(MAKECMDGOALS)", "$(CLEAN)")
    MAKE_DIRS += $(NONUT_DIRS) $(UT_DIRS)
endif

### Makefile body ###
.PHONY: $(RELEASE) $(DEBUG) $(CLEAN) $(TOUCH) $(UNITEST) $(TEST) $(FORCE) $(CREPORT) $(SCHECK)

$(RELEASE) $(DEBUG) $(CLEAN) $(UNITEST) $(SCHECK):
	@set -e; \
	for DIR in $(MAKE_DIRS); \
	do \
		cd $$DIR && $(MAKE) -r ROOT=$(ROOT) BUILD=$(BUILD) $@;\
	done
	@set -e; \
	if [ "$(MAKECMDGOALS)" = "$(CLEAN)" ] ; then $(RM) $(RMFLAGS) $(RMS) ; fi; \
	if [ "$(MAKECMDGOALS)" = "$(UNITEST)" ] ; then touch $(DIR_UNITEST)/unitested; fi
	@echo ""
	@echo ":-) Completed"
	@echo ""

## make test $(target) ##
ifeq ("$(target)", "")
    UTS = $(wildcard $(DIR_UNITEST)/unitest_*.exe)
else
    UTS = $(wildcard $(DIR_UNITEST)/unitest_$(target).exe)
endif

ifeq ("$(MAKECMDGOALS)", "$(TEST)")
    ifeq ("$(wildcard $(DIR_UNITEST)/unitested)", "")
        $(error Did you forget to run 'make unitest'?)
    endif
endif

$(DIR_UNITEST)/unitest_%: $(FORCE) 
	./$@
$(TEST): $(UTS)
	@touch $(DIR_UNITEST)/tested

$(FORCE):


$(TOUCH):
	@echo "Processing ..."
	@find $(ROOT) -exec touch {} \;
	@echo ""
	@echo ":-) Completed"
	@echo ""

# coverage 
REPORT = unitest.report
TEMP   = temp.report

ifeq ("$(MAKECMDGOALS)", "$(CREPORT)")
    ifeq ("$(wildcard $(DIR_UNITEST)/tested)","")
        $(error Did you forget to run 'make unitest' and 'make test'?)
    endif
endif

$(DIR_COVERAGE):
	$(MKDIR) $@

$(CREPORT): $(DIR_COVERAGE)
	@set -e; \
	cd $(DIR_COVERAGE); \
	$(RM) $(RMFLAGS) *; \
	for DIR in $(MAKE_DIRS); \
	do \
	    if ls $$DIR/uobjs/*.gcda > /dev/null 2>&1; then \
		lcov -c -d $$DIR/uobjs -b $$DIR >> $(TEMP); \
	    fi; \
	done; \
	lcov -r $(TEMP) /usr/include/* tests/* tools/* unitest.h -o $(REPORT); \
	genhtml $(REPORT); \
	$(RM) $(RMFLAGS) $(TEMP) $(REPORT);
	@echo ""
	@echo ":-) Completed"
	@echo ""

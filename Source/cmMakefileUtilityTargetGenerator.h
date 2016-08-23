/*============================================================================
  CMake - Cross Platform Makefile Generator
  Copyright 2000-2009 Kitware, Inc., Insight Software Consortium

  Distributed under the OSI-approved BSD License (the "License");
  see accompanying file Copyright.txt for details.

  This software is distributed WITHOUT ANY WARRANTY; without even the
  implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the License for more information.
============================================================================*/
#ifndef cmMakefileUtilityTargetGenerator_h
#define cmMakefileUtilityTargetGenerator_h

#include <cmConfigure.h>

#include "cmMakefileTargetGenerator.h"

class cmGeneratorTarget;

class cmMakefileUtilityTargetGenerator : public cmMakefileTargetGenerator
{
public:
  cmMakefileUtilityTargetGenerator(cmGeneratorTarget* target);
  ~cmMakefileUtilityTargetGenerator() CM_OVERRIDE;

  /* the main entry point for this class. Writes the Makefiles associated
     with this target */
  void WriteRuleFiles() CM_OVERRIDE;

protected:
};

#endif

/*============================================================================
  CMake - Cross Platform Makefile Generator
  Copyright 2000-2009 Kitware, Inc., Insight Software Consortium

  Distributed under the OSI-approved BSD License (the "License");
  see accompanying file Copyright.txt for details.

  This software is distributed WITHOUT ANY WARRANTY; without even the
  implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the License for more information.
============================================================================*/
#ifndef cmMakefileLibraryTargetGenerator_h
#define cmMakefileLibraryTargetGenerator_h

#include <cmConfigure.h>

#include "cmMakefileTargetGenerator.h"

#include <string>

class cmGeneratorTarget;

class cmMakefileLibraryTargetGenerator : public cmMakefileTargetGenerator
{
public:
  cmMakefileLibraryTargetGenerator(cmGeneratorTarget* target);
  ~cmMakefileLibraryTargetGenerator() CM_OVERRIDE;

  /* the main entry point for this class. Writes the Makefiles associated
     with this target */
  void WriteRuleFiles() CM_OVERRIDE;

protected:
  void WriteObjectLibraryRules();
  void WriteStaticLibraryRules();
  void WriteSharedLibraryRules(bool relink);
  void WriteModuleLibraryRules(bool relink);
  void WriteLibraryRules(const std::string& linkRule,
                         const std::string& extraFlags, bool relink);
  // MacOSX Framework support methods
  void WriteFrameworkRules(bool relink);

  // Store the computd framework version for OS X Frameworks.
  std::string FrameworkVersion;
};

#endif

/*============================================================================
  CMake - Cross Platform Makefile Generator
  Copyright 2000-2009 Kitware, Inc., Insight Software Consortium

  Distributed under the OSI-approved BSD License (the "License");
  see accompanying file Copyright.txt for details.

  This software is distributed WITHOUT ANY WARRANTY; without even the
  implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the License for more information.
============================================================================*/
#ifndef cmInstallScriptGenerator_h
#define cmInstallScriptGenerator_h

#include <cmConfigure.h>

#include "cmInstallGenerator.h"

#include <iosfwd>
#include <string>

/** \class cmInstallScriptGenerator
 * \brief Generate target installation rules.
 */
class cmInstallScriptGenerator : public cmInstallGenerator
{
public:
  cmInstallScriptGenerator(const char* script, bool code,
                           const char* component, bool exclude_from_all);
  ~cmInstallScriptGenerator() CM_OVERRIDE;

protected:
  void GenerateScript(std::ostream& os) CM_OVERRIDE;
  std::string Script;
  bool Code;
};

#endif

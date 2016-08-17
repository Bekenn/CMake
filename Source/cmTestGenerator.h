/*============================================================================
  CMake - Cross Platform Makefile Generator
  Copyright 2000-2009 Kitware, Inc., Insight Software Consortium

  Distributed under the OSI-approved BSD License (the "License");
  see accompanying file Copyright.txt for details.

  This software is distributed WITHOUT ANY WARRANTY; without even the
  implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the License for more information.
============================================================================*/
#ifndef cmTestGenerator_h
#define cmTestGenerator_h

#include <cmConfigure.h> // IWYU pragma: keep

#include "cmScriptGenerator.h"

#include <iosfwd>
#include <string>
#include <vector>

class cmLocalGenerator;
class cmTest;

/** \class cmTestGenerator
 * \brief Support class for generating install scripts.
 *
 */
class cmTestGenerator : public cmScriptGenerator
{
public:
  cmTestGenerator(cmTest* test,
                  std::vector<std::string> const& configurations =
                    std::vector<std::string>());
  ~cmTestGenerator() CM_OVERRIDE;

  void Compute(cmLocalGenerator* lg);

protected:
  void GenerateScriptConfigs(std::ostream& os,
                             Indent const& indent) CM_OVERRIDE;
  void GenerateScriptActions(std::ostream& os,
                             Indent const& indent) CM_OVERRIDE;
  void GenerateScriptForConfig(std::ostream& os, const std::string& config,
                               Indent const& indent) CM_OVERRIDE;
  void GenerateScriptNoConfig(std::ostream& os,
                              Indent const& indent) CM_OVERRIDE;
  bool NeedsScriptNoConfig() const CM_OVERRIDE;
  void GenerateOldStyle(std::ostream& os, Indent const& indent);

  cmLocalGenerator* LG;
  cmTest* Test;
  bool TestGenerated;
};

#endif

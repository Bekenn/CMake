/*============================================================================
  CMake - Cross Platform Makefile Generator
  Copyright 2014 Kitware, Inc., Insight Software Consortium

  Distributed under the OSI-approved BSD License (the "License");
  see accompanying file Copyright.txt for details.

  This software is distributed WITHOUT ANY WARRANTY; without even the
  implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the License for more information.
============================================================================*/
#ifndef cmCPackPropertiesGenerator_h
#define cmCPackPropertiesGenerator_h

#include <cmConfigure.h> // IWYU pragma: keep

#include "cmScriptGenerator.h"

#include <iosfwd>
#include <string>
#include <vector>

class cmInstalledFile;
class cmLocalGenerator;

/** \class cmCPackPropertiesGenerator
 * \brief Support class for generating CPackProperties.cmake.
 *
 */
class cmCPackPropertiesGenerator : public cmScriptGenerator
{
public:
  cmCPackPropertiesGenerator(cmLocalGenerator* lg,
                             cmInstalledFile const& installedFile,
                             std::vector<std::string> const& configurations);

protected:
  void GenerateScriptForConfig(std::ostream& os, const std::string& config,
                               Indent const& indent) CM_OVERRIDE;

  cmLocalGenerator* LG;
  cmInstalledFile const& InstalledFile;
};

#endif

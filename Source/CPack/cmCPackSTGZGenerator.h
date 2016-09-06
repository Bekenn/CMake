/*============================================================================
  CMake - Cross Platform Makefile Generator
  Copyright 2000-2009 Kitware, Inc.

  Distributed under the OSI-approved BSD License (the "License");
  see accompanying file Copyright.txt for details.

  This software is distributed WITHOUT ANY WARRANTY; without even the
  implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the License for more information.
============================================================================*/

#ifndef cmCPackSTGZGenerator_h
#define cmCPackSTGZGenerator_h

#include <cmConfigure.h>

#include "cmCPackGenerator.h"
#include "cmCPackTGZGenerator.h"
#include "cmTypeMacro.h"

#include <iosfwd>

/** \class cmCPackSTGZGenerator
 * \brief A generator for Self extractable TGZ files
 *
 */
class cmCPackSTGZGenerator : public cmCPackTGZGenerator
{
public:
  cmCPackTypeMacro(cmCPackSTGZGenerator, cmCPackTGZGenerator);

  /**
   * Construct generator
   */
  cmCPackSTGZGenerator();
  ~cmCPackSTGZGenerator() CM_OVERRIDE;

protected:
  int PackageFiles() CM_OVERRIDE;
  int InitializeInternal() CM_OVERRIDE;
  int GenerateHeader(std::ostream* os) CM_OVERRIDE;
  const char* GetOutputExtension() CM_OVERRIDE { return ".sh"; }
};

#endif

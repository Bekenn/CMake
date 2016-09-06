/*============================================================================
  CMake - Cross Platform Makefile Generator
  Copyright 2000-2009 Kitware, Inc.

  Distributed under the OSI-approved BSD License (the "License");
  see accompanying file Copyright.txt for details.

  This software is distributed WITHOUT ANY WARRANTY; without even the
  implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the License for more information.
============================================================================*/

#ifndef cmCPackTGZGenerator_h
#define cmCPackTGZGenerator_h

#include <cmConfigure.h>

#include "cmCPackArchiveGenerator.h"
#include "cmCPackGenerator.h"
#include "cmTypeMacro.h"

/** \class cmCPackTGZGenerator
 * \brief A generator for TGZ files
 *
 */
class cmCPackTGZGenerator : public cmCPackArchiveGenerator
{
public:
  cmCPackTypeMacro(cmCPackTGZGenerator, cmCPackArchiveGenerator);
  /**
   * Construct generator
   */
  cmCPackTGZGenerator();
  ~cmCPackTGZGenerator() CM_OVERRIDE;

protected:
  const char* GetOutputExtension() CM_OVERRIDE { return ".tar.gz"; }
};

#endif

/*============================================================================
  CMake - Cross Platform Makefile Generator
  Copyright 2000-2009 Kitware, Inc., Insight Software Consortium

  Distributed under the OSI-approved BSD License (the "License");
  see accompanying file Copyright.txt for details.

  This software is distributed WITHOUT ANY WARRANTY; without even the
  implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the License for more information.
============================================================================*/
#ifndef cmDependsJava_h
#define cmDependsJava_h

#include <cmConfigure.h>

#include "cmDepends.h"

#include <iosfwd>
#include <map>
#include <set>
#include <string>

/** \class cmDependsJava
 * \brief Dependency scanner for Java class files.
 */
class cmDependsJava : public cmDepends
{
public:
  /** Checking instances need to know the build directory name and the
      relative path from the build directory to the target file.  */
  cmDependsJava();

  /** Virtual destructor to cleanup subclasses properly.  */
  ~cmDependsJava() CM_OVERRIDE;

protected:
  // Implement writing/checking methods required by superclass.
  bool WriteDependencies(const std::set<std::string>& sources,
                         const std::string& file, std::ostream& makeDepends,
                         std::ostream& internalDepends) CM_OVERRIDE;
  bool CheckDependencies(
    std::istream& internalDepends, const char* internalDependsFileName,
    std::map<std::string, DependencyVector>& validDeps) CM_OVERRIDE;

private:
  cmDependsJava(cmDependsJava const&);  // Purposely not implemented.
  void operator=(cmDependsJava const&); // Purposely not implemented.
};

#endif

/*============================================================================
  CMake - Cross Platform Makefile Generator
  Copyright 2000-2009 Kitware, Inc., Insight Software Consortium

  Distributed under the OSI-approved BSD License (the "License");
  see accompanying file Copyright.txt for details.

  This software is distributed WITHOUT ANY WARRANTY; without even the
  implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the License for more information.
============================================================================*/
#ifndef cmCTestBuildCommand_h
#define cmCTestBuildCommand_h

#include <cmConfigure.h>

#include "cmCTestHandlerCommand.h"
#include "cmTypeMacro.h"

#include <string>
#include <vector>

class cmCTestBuildHandler;
class cmCTestGenericHandler;
class cmCommand;
class cmExecutionStatus;
class cmGlobalGenerator;

/** \class cmCTestBuild
 * \brief Run a ctest script
 *
 * cmCTestBuildCommand defineds the command to build the project.
 */
class cmCTestBuildCommand : public cmCTestHandlerCommand
{
public:
  cmCTestBuildCommand();
  ~cmCTestBuildCommand() CM_OVERRIDE;

  /**
   * This is a virtual constructor for the command.
   */
  cmCommand* Clone() CM_OVERRIDE
  {
    cmCTestBuildCommand* ni = new cmCTestBuildCommand;
    ni->CTest = this->CTest;
    ni->CTestScriptHandler = this->CTestScriptHandler;
    return ni;
  }

  /**
   * The name of the command as specified in CMakeList.txt.
   */
  std::string GetName() const CM_OVERRIDE { return "ctest_build"; }

  bool InitialPass(std::vector<std::string> const& args,
                   cmExecutionStatus& status) CM_OVERRIDE;

  cmTypeMacro(cmCTestBuildCommand, cmCTestHandlerCommand);

  cmGlobalGenerator* GlobalGenerator;

protected:
  cmCTestBuildHandler* Handler;
  enum
  {
    ctb_BUILD = ct_LAST,
    ctb_NUMBER_ERRORS,
    ctb_NUMBER_WARNINGS,
    ctb_TARGET,
    ctb_CONFIGURATION,
    ctb_FLAGS,
    ctb_PROJECT_NAME,
    ctb_LAST
  };

  cmCTestGenericHandler* InitializeHandler() CM_OVERRIDE;
};

#endif

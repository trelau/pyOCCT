/*
This file is part of pyOCCT which provides Python bindings to the OpenCASCADE
geometry kernel.

Copyright (C) 2016-2018  Laughlin Research, LLC (info@laughlinresearch.com)

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/
#include <pyOCCT_Common.hpp>

#include <OSD_SysType.hxx>
#include <Standard_Failure.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_SStream.hxx>
#include <Standard_Handle.hxx>
#include <OSD_OSDError.hxx>
#include <Standard_Type.hxx>
#include <TCollection_AsciiString.hxx>
#include <OSD_Path.hxx>
#include <Standard_OStream.hxx>
#include <OSD_Chronometer.hxx>
#include <OSD_Timer.hxx>
#include <OSD_ThreadFunction.hxx>
#include <OSD_PThread.hxx>
#include <OSD_Thread.hxx>
#include <Standard_ThreadId.hxx>
#include <OSD_Parallel.hxx>
#include <OSD_Function.hxx>
#include <OSD_Error.hxx>
#include <OSD_SingleProtection.hxx>
#include <OSD_Protection.hxx>
#include <Quantity_Date.hxx>
#include <OSD_FileNode.hxx>
#include <OSD_Disk.hxx>
#include <OSD_OpenMode.hxx>
#include <OSD_FromWhere.hxx>
#include <OSD_KindFile.hxx>
#include <OSD_LockType.hxx>
#include <NCollection_SparseArrayBase.hxx>
#include <OSD_File.hxx>
#include <OSD_FileIterator.hxx>
#include <OSD_Directory.hxx>
#include <OSD_DirectoryIterator.hxx>
#include <OSD_OEMType.hxx>
#include <OSD_Host.hxx>
#include <OSD_Environment.hxx>
#include <OSD.hxx>
#include <OSD_Process.hxx>
#include <OSD_LoadMode.hxx>
#include <OSD_SharedLibrary.hxx>
#include <Standard_PCharacter.hxx>
#include <OSD_WhoAmI.hxx>
#include <OSD_Exception.hxx>
#include <OSD_Exception_ACCESS_VIOLATION.hxx>
#include <OSD_Exception_ARRAY_BOUNDS_EXCEEDED.hxx>
#include <OSD_Exception_CTRL_BREAK.hxx>
#include <OSD_Exception_FLT_DENORMAL_OPERAND.hxx>
#include <OSD_Exception_FLT_DIVIDE_BY_ZERO.hxx>
#include <OSD_Exception_FLT_INEXACT_RESULT.hxx>
#include <OSD_Exception_FLT_INVALID_OPERATION.hxx>
#include <OSD_Exception_FLT_OVERFLOW.hxx>
#include <OSD_Exception_FLT_STACK_CHECK.hxx>
#include <OSD_Exception_FLT_UNDERFLOW.hxx>
#include <OSD_Exception_ILLEGAL_INSTRUCTION.hxx>
#include <OSD_Exception_INT_DIVIDE_BY_ZERO.hxx>
#include <OSD_Exception_INT_OVERFLOW.hxx>
#include <OSD_Exception_INVALID_DISPOSITION.hxx>
#include <OSD_Exception_IN_PAGE_ERROR.hxx>
#include <OSD_Exception_NONCONTINUABLE_EXCEPTION.hxx>
#include <OSD_Exception_PRIV_INSTRUCTION.hxx>
#include <OSD_Exception_STACK_OVERFLOW.hxx>
#include <OSD_Exception_STATUS_NO_MEMORY.hxx>
#include <OSD_MAllocHook.hxx>
#include <OSD_MemInfo.hxx>
#include <OSD_OpenFile.hxx>
#include <TCollection_ExtendedString.hxx>
#include <OSD_PerfMeter.hxx>
#include <OSD_Signal.hxx>
#include <OSD_SIGBUS.hxx>
#include <OSD_SIGHUP.hxx>
#include <OSD_SIGILL.hxx>
#include <OSD_SIGINT.hxx>
#include <OSD_SIGKILL.hxx>
#include <OSD_SIGQUIT.hxx>
#include <OSD_SIGSEGV.hxx>
#include <OSD_SIGSYS.hxx>

PYBIND11_MODULE(OSD, mod) {

	// IMPORT
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.TCollection");
	py::module::import("OCCT.Quantity");
	py::module::import("OCCT.NCollection");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS
	// C:\Miniconda\envs\occt\Library\include\opencascade\OSD_SysType.hxx
	py::enum_<OSD_SysType>(mod, "OSD_SysType", "Thisd is a set of possible system types. 'Default' means SysType of machine operating this process. This can be used with the Path class. All UNIX-like are grouped under 'UnixBSD' or 'UnixSystemV'. Such systems are Solaris, NexTOS ... A category of systems accept MSDOS-like path such as WindowsNT and OS2.")
		.value("OSD_Unknown", OSD_SysType::OSD_Unknown)
		.value("OSD_Default", OSD_SysType::OSD_Default)
		.value("OSD_UnixBSD", OSD_SysType::OSD_UnixBSD)
		.value("OSD_UnixSystemV", OSD_SysType::OSD_UnixSystemV)
		.value("OSD_VMS", OSD_SysType::OSD_VMS)
		.value("OSD_OS2", OSD_SysType::OSD_OS2)
		.value("OSD_OSF", OSD_SysType::OSD_OSF)
		.value("OSD_MacOs", OSD_SysType::OSD_MacOs)
		.value("OSD_Taligent", OSD_SysType::OSD_Taligent)
		.value("OSD_WindowsNT", OSD_SysType::OSD_WindowsNT)
		.value("OSD_LinuxREDHAT", OSD_SysType::OSD_LinuxREDHAT)
		.value("OSD_Aix", OSD_SysType::OSD_Aix)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\OSD_WhoAmI.hxx
	py::enum_<OSD_WhoAmI>(mod, "OSD_WhoAmI", "Allows great accuracy for error management. This is private.")
		.value("OSD_WDirectory", OSD_WhoAmI::OSD_WDirectory)
		.value("OSD_WDirectoryIterator", OSD_WhoAmI::OSD_WDirectoryIterator)
		.value("OSD_WEnvironment", OSD_WhoAmI::OSD_WEnvironment)
		.value("OSD_WFile", OSD_WhoAmI::OSD_WFile)
		.value("OSD_WFileNode", OSD_WhoAmI::OSD_WFileNode)
		.value("OSD_WFileIterator", OSD_WhoAmI::OSD_WFileIterator)
		.value("OSD_WPath", OSD_WhoAmI::OSD_WPath)
		.value("OSD_WProcess", OSD_WhoAmI::OSD_WProcess)
		.value("OSD_WProtection", OSD_WhoAmI::OSD_WProtection)
		.value("OSD_WHost", OSD_WhoAmI::OSD_WHost)
		.value("OSD_WDisk", OSD_WhoAmI::OSD_WDisk)
		.value("OSD_WChronometer", OSD_WhoAmI::OSD_WChronometer)
		.value("OSD_WTimer", OSD_WhoAmI::OSD_WTimer)
		.value("OSD_WPackage", OSD_WhoAmI::OSD_WPackage)
		.value("OSD_WEnvironmentIterator", OSD_WhoAmI::OSD_WEnvironmentIterator)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\OSD_LockType.hxx
	py::enum_<OSD_LockType>(mod, "OSD_LockType", "locks for files. NoLock is the default value when opening a file.")
		.value("OSD_NoLock", OSD_LockType::OSD_NoLock)
		.value("OSD_ReadLock", OSD_LockType::OSD_ReadLock)
		.value("OSD_WriteLock", OSD_LockType::OSD_WriteLock)
		.value("OSD_ExclusiveLock", OSD_LockType::OSD_ExclusiveLock)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\OSD_OpenMode.hxx
	py::enum_<OSD_OpenMode>(mod, "OSD_OpenMode", "Specifies the file open mode.")
		.value("OSD_ReadOnly", OSD_OpenMode::OSD_ReadOnly)
		.value("OSD_WriteOnly", OSD_OpenMode::OSD_WriteOnly)
		.value("OSD_ReadWrite", OSD_OpenMode::OSD_ReadWrite)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\OSD_FromWhere.hxx
	py::enum_<OSD_FromWhere>(mod, "OSD_FromWhere", "Used by OSD_File in the method Seek.")
		.value("OSD_FromBeginning", OSD_FromWhere::OSD_FromBeginning)
		.value("OSD_FromHere", OSD_FromWhere::OSD_FromHere)
		.value("OSD_FromEnd", OSD_FromWhere::OSD_FromEnd)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\OSD_KindFile.hxx
	py::enum_<OSD_KindFile>(mod, "OSD_KindFile", "Specifies the type of files.")
		.value("OSD_FILE", OSD_KindFile::OSD_FILE)
		.value("OSD_DIRECTORY", OSD_KindFile::OSD_DIRECTORY)
		.value("OSD_LINK", OSD_KindFile::OSD_LINK)
		.value("OSD_SOCKET", OSD_KindFile::OSD_SOCKET)
		.value("OSD_UNKNOWN", OSD_KindFile::OSD_UNKNOWN)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\OSD_OEMType.hxx
	py::enum_<OSD_OEMType>(mod, "OSD_OEMType", "This is set of possible machine types used in OSD_Host::MachineType")
		.value("OSD_Unavailable", OSD_OEMType::OSD_Unavailable)
		.value("OSD_SUN", OSD_OEMType::OSD_SUN)
		.value("OSD_DEC", OSD_OEMType::OSD_DEC)
		.value("OSD_SGI", OSD_OEMType::OSD_SGI)
		.value("OSD_NEC", OSD_OEMType::OSD_NEC)
		.value("OSD_MAC", OSD_OEMType::OSD_MAC)
		.value("OSD_PC", OSD_OEMType::OSD_PC)
		.value("OSD_HP", OSD_OEMType::OSD_HP)
		.value("OSD_IBM", OSD_OEMType::OSD_IBM)
		.value("OSD_VAX", OSD_OEMType::OSD_VAX)
		.value("OSD_LIN", OSD_OEMType::OSD_LIN)
		.value("OSD_AIX", OSD_OEMType::OSD_AIX)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\OSD_LoadMode.hxx
	py::enum_<OSD_LoadMode>(mod, "OSD_LoadMode", "This enumeration is used to load shareable libraries.")
		.value("OSD_RTLD_LAZY", OSD_LoadMode::OSD_RTLD_LAZY)
		.value("OSD_RTLD_NOW", OSD_LoadMode::OSD_RTLD_NOW)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\OSD_SingleProtection.hxx
	py::enum_<OSD_SingleProtection>(mod, "OSD_SingleProtection", "Access rights for files. R means Read, W means Write, X means eXecute and D means Delete. On UNIX, the right to Delete is combined with Write access. So if 'W'rite is not set and 'D'elete is, 'W'rite will be set and if 'W' is set, 'D' will be too.")
		.value("OSD_None", OSD_SingleProtection::OSD_None)
		.value("OSD_R", OSD_SingleProtection::OSD_R)
		.value("OSD_W", OSD_SingleProtection::OSD_W)
		.value("OSD_RW", OSD_SingleProtection::OSD_RW)
		.value("OSD_X", OSD_SingleProtection::OSD_X)
		.value("OSD_RX", OSD_SingleProtection::OSD_RX)
		.value("OSD_WX", OSD_SingleProtection::OSD_WX)
		.value("OSD_RWX", OSD_SingleProtection::OSD_RWX)
		.value("OSD_D", OSD_SingleProtection::OSD_D)
		.value("OSD_RD", OSD_SingleProtection::OSD_RD)
		.value("OSD_WD", OSD_SingleProtection::OSD_WD)
		.value("OSD_RWD", OSD_SingleProtection::OSD_RWD)
		.value("OSD_XD", OSD_SingleProtection::OSD_XD)
		.value("OSD_RXD", OSD_SingleProtection::OSD_RXD)
		.value("OSD_WXD", OSD_SingleProtection::OSD_WXD)
		.value("OSD_RWXD", OSD_SingleProtection::OSD_RWXD)
		.export_values();

	// FUNCTIONS
	// C:\Miniconda\envs\occt\Library\include\opencascade\OSD_OpenFile.hxx
	mod.def("OSD_OpenFile", (FILE * (*)(const TCollection_ExtendedString &, const char *)) &OSD_OpenFile, "Function opens the file.", py::arg("theName"), py::arg("theMode"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\OSD_OpenFile.hxx
	mod.def("OSD_FileStatCTime", (Standard_Time (*)(const char *)) &OSD_FileStatCTime, "Function retrieves file timestamp.", py::arg("theName"));


	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\OSD_OSDError.hxx
	py::class_<OSD_OSDError, opencascade::handle<OSD_OSDError>, Standard_Failure> cls_OSD_OSDError(mod, "OSD_OSDError", "None");
	cls_OSD_OSDError.def(py::init<>());
	cls_OSD_OSDError.def(py::init<const Standard_CString>(), py::arg("theMessage"));
	cls_OSD_OSDError.def_static("Raise_", (void (*)(const Standard_CString)) &OSD_OSDError::Raise, "None", py::arg("theMessage"));
	cls_OSD_OSDError.def_static("Raise_", (void (*)(Standard_SStream &)) &OSD_OSDError::Raise, "None", py::arg("theMessage"));
	cls_OSD_OSDError.def_static("NewInstance_", (opencascade::handle<OSD_OSDError> (*)(const Standard_CString)) &OSD_OSDError::NewInstance, "None", py::arg("theMessage"));
	cls_OSD_OSDError.def_static("get_type_name_", (const char * (*)()) &OSD_OSDError::get_type_name, "None");
	cls_OSD_OSDError.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &OSD_OSDError::get_type_descriptor, "None");
	cls_OSD_OSDError.def("DynamicType", (const opencascade::handle<Standard_Type> & (OSD_OSDError::*)() const ) &OSD_OSDError::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\OSD_Path.hxx
	py::class_<OSD_Path, std::unique_ptr<OSD_Path, Deleter<OSD_Path>>> cls_OSD_Path(mod, "OSD_Path", "None");
	cls_OSD_Path.def(py::init<>());
	cls_OSD_Path.def(py::init<const TCollection_AsciiString &>(), py::arg("aDependentName"));
	cls_OSD_Path.def(py::init<const TCollection_AsciiString &, const OSD_SysType>(), py::arg("aDependentName"), py::arg("aSysType"));
	cls_OSD_Path.def(py::init<const TCollection_AsciiString &, const TCollection_AsciiString &, const TCollection_AsciiString &, const TCollection_AsciiString &, const TCollection_AsciiString &, const TCollection_AsciiString &, const TCollection_AsciiString &>(), py::arg("aNode"), py::arg("aUsername"), py::arg("aPassword"), py::arg("aDisk"), py::arg("aTrek"), py::arg("aName"), py::arg("anExtension"));
	cls_OSD_Path.def("Values", (void (OSD_Path::*)(TCollection_AsciiString &, TCollection_AsciiString &, TCollection_AsciiString &, TCollection_AsciiString &, TCollection_AsciiString &, TCollection_AsciiString &, TCollection_AsciiString &) const ) &OSD_Path::Values, "Gets each component of a path.", py::arg("aNode"), py::arg("aUsername"), py::arg("aPassword"), py::arg("aDisk"), py::arg("aTrek"), py::arg("aName"), py::arg("anExtension"));
	cls_OSD_Path.def("SetValues", (void (OSD_Path::*)(const TCollection_AsciiString &, const TCollection_AsciiString &, const TCollection_AsciiString &, const TCollection_AsciiString &, const TCollection_AsciiString &, const TCollection_AsciiString &, const TCollection_AsciiString &)) &OSD_Path::SetValues, "Sets each component of a path.", py::arg("aNode"), py::arg("aUsername"), py::arg("aPassword"), py::arg("aDisk"), py::arg("aTrek"), py::arg("aName"), py::arg("anExtension"));
	cls_OSD_Path.def("SystemName", [](OSD_Path &self, TCollection_AsciiString & a0) -> void { return self.SystemName(a0); }, py::arg("FullName"));
	cls_OSD_Path.def("SystemName", (void (OSD_Path::*)(TCollection_AsciiString &, const OSD_SysType) const ) &OSD_Path::SystemName, "Returns system dependent path <aType> is one among Unix,VMS ... This function is not private because you may need to display system dependent path on a front-end. It can be useful when communicating with another system. For instance when you want to communicate between VMS and Unix to transfer files, or to do a remote procedure call using files. example : OSD_Path myPath ('sparc4', 'sga', 'secret_passwd', '$5$dkb100','|users|examples'); Internal ( Dependent_name ); On UNIX sga'secret_passwd':/users/examples On VMS sparc4'sga secret_passwd'::$5$dkb100:[users.examples] Sets each component of a Path giving its system dependent name.", py::arg("FullName"), py::arg("aType"));
	cls_OSD_Path.def("ExpandedName", (void (OSD_Path::*)(TCollection_AsciiString &)) &OSD_Path::ExpandedName, "Returns system dependent path resolving logical symbols.", py::arg("aName"));
	cls_OSD_Path.def_static("IsValid_", [](const TCollection_AsciiString & a0) -> Standard_Boolean { return OSD_Path::IsValid(a0); }, py::arg("theDependentName"));
	cls_OSD_Path.def_static("IsValid_", (Standard_Boolean (*)(const TCollection_AsciiString &, const OSD_SysType)) &OSD_Path::IsValid, "Returns TRUE if <theDependentName> is valid for this SysType.", py::arg("theDependentName"), py::arg("theSysType"));
	cls_OSD_Path.def("UpTrek", (void (OSD_Path::*)()) &OSD_Path::UpTrek, "This removes the last directory name in <aTrek> and returns result. ex: me = '|usr|bin|todo.sh' me.UpTrek() gives me = '|usr|todo.sh' if <me> contains '|', me.UpTrek() will give again '|' without any error.");
	cls_OSD_Path.def("DownTrek", (void (OSD_Path::*)(const TCollection_AsciiString &)) &OSD_Path::DownTrek, "This appends a directory name into the Trek. ex: me = '|usr|todo.sh' me.DownTrek('bin') gives me = '|usr|bin|todo.sh'.", py::arg("aName"));
	cls_OSD_Path.def("TrekLength", (Standard_Integer (OSD_Path::*)() const ) &OSD_Path::TrekLength, "Returns number of components in Trek of <me>. ex: me = '|usr|sys|etc|bin' me.TrekLength() returns 4.");
	cls_OSD_Path.def("RemoveATrek", (void (OSD_Path::*)(const Standard_Integer)) &OSD_Path::RemoveATrek, "This removes a component of Trek in <me> at position <where>. The first component of Trek is numbered 1. ex: me = '|usr|bin|' me.RemoveATrek(1) gives me = '|bin|' To avoid a 'NumericError' because of a bad <where>, use TrekLength() to know number of components of Trek in <me>.", py::arg("where"));
	cls_OSD_Path.def("RemoveATrek", (void (OSD_Path::*)(const TCollection_AsciiString &)) &OSD_Path::RemoveATrek, "This removes <aName> from <me> in Trek. No error is raised if <aName> is not in <me>. ex: me = '|usr|sys|etc|doc' me.RemoveATrek('sys') gives me = '|usr|etc|doc'.", py::arg("aName"));
	cls_OSD_Path.def("TrekValue", (TCollection_AsciiString (OSD_Path::*)(const Standard_Integer) const ) &OSD_Path::TrekValue, "Returns component of Trek in <me> at position <where>. ex: me = '|usr|bin|sys|' me.TrekValue(2) returns 'bin'", py::arg("where"));
	cls_OSD_Path.def("InsertATrek", (void (OSD_Path::*)(const TCollection_AsciiString &, const Standard_Integer)) &OSD_Path::InsertATrek, "This inserts <aName> at position <where> into Trek of <me>. ex: me = '|usr|etc|' me.InsertATrek('sys',2) gives me = '|usr|sys|etc'", py::arg("aName"), py::arg("where"));
	cls_OSD_Path.def("Node", (TCollection_AsciiString (OSD_Path::*)() const ) &OSD_Path::Node, "Returns Node of <me>.");
	cls_OSD_Path.def("UserName", (TCollection_AsciiString (OSD_Path::*)() const ) &OSD_Path::UserName, "Returns UserName of <me>.");
	cls_OSD_Path.def("Password", (TCollection_AsciiString (OSD_Path::*)() const ) &OSD_Path::Password, "Returns Password of <me>.");
	cls_OSD_Path.def("Disk", (TCollection_AsciiString (OSD_Path::*)() const ) &OSD_Path::Disk, "Returns Disk of <me>.");
	cls_OSD_Path.def("Trek", (TCollection_AsciiString (OSD_Path::*)() const ) &OSD_Path::Trek, "Returns Trek of <me>.");
	cls_OSD_Path.def("Name", (TCollection_AsciiString (OSD_Path::*)() const ) &OSD_Path::Name, "Returns file name of <me>. If <me> hasn't been initialized, it returns an empty AsciiString.");
	cls_OSD_Path.def("Extension", (TCollection_AsciiString (OSD_Path::*)() const ) &OSD_Path::Extension, "Returns my extension name. This returns an empty string if path contains no file name.");
	cls_OSD_Path.def("SetNode", (void (OSD_Path::*)(const TCollection_AsciiString &)) &OSD_Path::SetNode, "Sets Node of <me>.", py::arg("aName"));
	cls_OSD_Path.def("SetUserName", (void (OSD_Path::*)(const TCollection_AsciiString &)) &OSD_Path::SetUserName, "Sets UserName of <me>.", py::arg("aName"));
	cls_OSD_Path.def("SetPassword", (void (OSD_Path::*)(const TCollection_AsciiString &)) &OSD_Path::SetPassword, "Sets Password of <me>.", py::arg("aName"));
	cls_OSD_Path.def("SetDisk", (void (OSD_Path::*)(const TCollection_AsciiString &)) &OSD_Path::SetDisk, "Sets Disk of <me>.", py::arg("aName"));
	cls_OSD_Path.def("SetTrek", (void (OSD_Path::*)(const TCollection_AsciiString &)) &OSD_Path::SetTrek, "Sets Trek of <me>.", py::arg("aName"));
	cls_OSD_Path.def("SetName", (void (OSD_Path::*)(const TCollection_AsciiString &)) &OSD_Path::SetName, "Sets file name of <me>. If <me> hasn't been initialized, it returns an empty AsciiString.", py::arg("aName"));
	cls_OSD_Path.def("SetExtension", (void (OSD_Path::*)(const TCollection_AsciiString &)) &OSD_Path::SetExtension, "Sets my extension name.", py::arg("aName"));
	// cls_OSD_Path.def("LocateExecFile", (Standard_Boolean (OSD_Path::*)(OSD_Path &)) &OSD_Path::LocateExecFile, "Finds the full path of an executable file, like the 'which' Unix utility. Uses the path environment variable. Returns False if executable file not found.", py::arg("aPath"));
	cls_OSD_Path.def_static("RelativePath_", (TCollection_AsciiString (*)(const TCollection_AsciiString &, const TCollection_AsciiString &)) &OSD_Path::RelativePath, "Returns the relative file path between the absolute directory path <DirPath> and the absolute file path <AbsFilePath>. If <DirPath> starts with '/', pathes are handled as on Unix, if it starts with a letter followed by ':', as on WNT. In particular on WNT directory names are not key sensitive. If handling fails, an empty string is returned.", py::arg("DirPath"), py::arg("AbsFilePath"));
	cls_OSD_Path.def_static("AbsolutePath_", (TCollection_AsciiString (*)(const TCollection_AsciiString &, const TCollection_AsciiString &)) &OSD_Path::AbsolutePath, "Returns the absolute file path from the absolute directory path <DirPath> and the relative file path returned by RelativePath(). If the RelFilePath is an absolute path, it is returned and the directory path is ignored. If handling fails, an empty string is returned.", py::arg("DirPath"), py::arg("RelFilePath"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\OSD_Chronometer.hxx
	py::class_<OSD_Chronometer, std::unique_ptr<OSD_Chronometer, Deleter<OSD_Chronometer>>> cls_OSD_Chronometer(mod, "OSD_Chronometer", "This class measures CPU time (both user and system) consumed by current process or thread. The chronometer can be started and stopped multiple times, and measures cumulative time.");
	cls_OSD_Chronometer.def(py::init<>());
	cls_OSD_Chronometer.def(py::init<const Standard_Boolean>(), py::arg("ThisThreadOnly"));
	cls_OSD_Chronometer.def("IsStarted", (Standard_Boolean (OSD_Chronometer::*)() const ) &OSD_Chronometer::IsStarted, "Return true if timer has been started.");
	cls_OSD_Chronometer.def("Reset", (void (OSD_Chronometer::*)()) &OSD_Chronometer::Reset, "Stops and Reinitializes the Chronometer.");
	cls_OSD_Chronometer.def("Restart", (void (OSD_Chronometer::*)()) &OSD_Chronometer::Restart, "Restarts the Chronometer.");
	cls_OSD_Chronometer.def("Stop", (void (OSD_Chronometer::*)()) &OSD_Chronometer::Stop, "Stops the Chronometer.");
	cls_OSD_Chronometer.def("Start", (void (OSD_Chronometer::*)()) &OSD_Chronometer::Start, "Starts (after Create or Reset) or restarts (after Stop) the chronometer.");
	cls_OSD_Chronometer.def("Show", (void (OSD_Chronometer::*)() const ) &OSD_Chronometer::Show, "Shows the current CPU user and system time on the standard output stream <cout>. The chronometer can be running (laps Time) or stopped.");
	cls_OSD_Chronometer.def("Show", (void (OSD_Chronometer::*)(Standard_OStream &) const ) &OSD_Chronometer::Show, "Shows the current CPU user and system time on the output stream <os>. The chronometer can be running (laps Time) or stopped.", py::arg("os"));
	cls_OSD_Chronometer.def("Show", [](OSD_Chronometer &self, Standard_Real & theUserSeconds){ self.Show(theUserSeconds); return theUserSeconds; }, "Returns the current CPU user time in a variable. The chronometer can be running (laps Time) or stopped.", py::arg("theUserSeconds"));
	cls_OSD_Chronometer.def("Show", [](OSD_Chronometer &self, Standard_Real & theUserSeconds, Standard_Real & theSystemSeconds){ self.Show(theUserSeconds, theSystemSeconds); return std::tuple<Standard_Real &, Standard_Real &>(theUserSeconds, theSystemSeconds); }, "Returns the current CPU user and system time in variables. The chronometer can be running (laps Time) or stopped.", py::arg("theUserSeconds"), py::arg("theSystemSeconds"));
	cls_OSD_Chronometer.def_static("GetProcessCPU_", [](Standard_Real & UserSeconds, Standard_Real & SystemSeconds){ OSD_Chronometer::GetProcessCPU(UserSeconds, SystemSeconds); return std::tuple<Standard_Real &, Standard_Real &>(UserSeconds, SystemSeconds); }, "Returns CPU time (user and system) consumed by the current process since its start, in seconds. The actual precision of the measurement depends on granularity provided by the system, and is platform-specific.", py::arg("UserSeconds"), py::arg("SystemSeconds"));
	cls_OSD_Chronometer.def_static("GetThreadCPU_", [](Standard_Real & UserSeconds, Standard_Real & SystemSeconds){ OSD_Chronometer::GetThreadCPU(UserSeconds, SystemSeconds); return std::tuple<Standard_Real &, Standard_Real &>(UserSeconds, SystemSeconds); }, "Returns CPU time (user and system) consumed by the current thread since its start. Note that this measurement is platform-specific, as threads are implemented and managed differently on different platforms and CPUs.", py::arg("UserSeconds"), py::arg("SystemSeconds"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\OSD_Timer.hxx
	py::class_<OSD_Timer, std::unique_ptr<OSD_Timer, Deleter<OSD_Timer>>, OSD_Chronometer> cls_OSD_Timer(mod, "OSD_Timer", "Working on heterogeneous platforms we need to use the system call gettimeofday. This function is portable and it measures ELAPSED time and CPU time in seconds and microseconds. Example: OSD_Timer aTimer; aTimer.Start(); // Start the timers (t1). ..... // Do something. aTimer.Stop(); // Stop the timers (t2). aTimer.Show(); // Give the elapsed time between t1 and t2. // Give also the process CPU time between // t1 and t2.");
	cls_OSD_Timer.def(py::init<>());
	cls_OSD_Timer.def("Reset", (void (OSD_Timer::*)(const Standard_Real)) &OSD_Timer::Reset, "Stops and reinitializes the timer with specified elapsed time.", py::arg("theTimeElapsedSec"));
	cls_OSD_Timer.def("Reset", (void (OSD_Timer::*)()) &OSD_Timer::Reset, "Stops and reinitializes the timer with zero elapsed time.");
	cls_OSD_Timer.def("Restart", (void (OSD_Timer::*)()) &OSD_Timer::Restart, "Restarts the Timer.");
	cls_OSD_Timer.def("Show", (void (OSD_Timer::*)() const ) &OSD_Timer::Show, "Shows both the elapsed time and CPU time on the standard output stream <cout>.The chronometer can be running (Lap Time) or stopped.");
	cls_OSD_Timer.def("Show", (void (OSD_Timer::*)(Standard_OStream &) const ) &OSD_Timer::Show, "Shows both the elapsed time and CPU time on the output stream <OS>.", py::arg("os"));
	cls_OSD_Timer.def("Show", [](OSD_Timer &self, Standard_Real & theSeconds, Standard_Integer & theMinutes, Standard_Integer & theHours, Standard_Real & theCPUtime){ self.Show(theSeconds, theMinutes, theHours, theCPUtime); return std::tuple<Standard_Real &, Standard_Integer &, Standard_Integer &, Standard_Real &>(theSeconds, theMinutes, theHours, theCPUtime); }, "returns both the elapsed time(seconds,minutes,hours) and CPU time.", py::arg("theSeconds"), py::arg("theMinutes"), py::arg("theHours"), py::arg("theCPUtime"));
	cls_OSD_Timer.def("Stop", (void (OSD_Timer::*)()) &OSD_Timer::Stop, "Stops the Timer.");
	cls_OSD_Timer.def("Start", (void (OSD_Timer::*)()) &OSD_Timer::Start, "Starts (after Create or Reset) or restarts (after Stop) the Timer.");
	cls_OSD_Timer.def("ElapsedTime", (Standard_Real (OSD_Timer::*)() const ) &OSD_Timer::ElapsedTime, "Returns elapsed time in seconds.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\OSD_Thread.hxx
	py::class_<OSD_Thread, std::unique_ptr<OSD_Thread, Deleter<OSD_Thread>>> cls_OSD_Thread(mod, "OSD_Thread", "A simple platform-intependent interface to execute and control threads.");
	cls_OSD_Thread.def(py::init<>());
	cls_OSD_Thread.def(py::init<const OSD_ThreadFunction &>(), py::arg("func"));
	cls_OSD_Thread.def(py::init([] (const OSD_Thread &other) {return new OSD_Thread(other);}), "Copy constructor", py::arg("other"));
	cls_OSD_Thread.def("Assign", (void (OSD_Thread::*)(const OSD_Thread &)) &OSD_Thread::Assign, "Copy thread handle from other OSD_Thread object.", py::arg("other"));
	cls_OSD_Thread.def("assign", (void (OSD_Thread::*)(const OSD_Thread &)) &OSD_Thread::operator=, py::is_operator(), "None", py::arg("other"));
	cls_OSD_Thread.def("SetPriority", (void (OSD_Thread::*)(const Standard_Integer)) &OSD_Thread::SetPriority, "None", py::arg("thePriority"));
	cls_OSD_Thread.def("SetFunction", (void (OSD_Thread::*)(const OSD_ThreadFunction &)) &OSD_Thread::SetFunction, "Initialize the tool by the thread function. If the current thread handle is not null, nullifies it.", py::arg("func"));
	cls_OSD_Thread.def("Run", [](OSD_Thread &self) -> Standard_Boolean { return self.Run(); });
	cls_OSD_Thread.def("Run", [](OSD_Thread &self, const Standard_Address a0) -> Standard_Boolean { return self.Run(a0); }, py::arg("data"));
	cls_OSD_Thread.def("Run", (Standard_Boolean (OSD_Thread::*)(const Standard_Address, const Standard_Integer)) &OSD_Thread::Run, "Starts a thread with thread function given in constructor, passing the specified input data (as void *) to it. The parameter WNTStackSize (on Windows only) specifies size of the stack to be allocated for the thread (by default - the same as for the current executable). Returns True if thread started successfully", py::arg("data"), py::arg("WNTStackSize"));
	cls_OSD_Thread.def("Detach", (void (OSD_Thread::*)()) &OSD_Thread::Detach, "Detaches the execution thread from this Thread object, so that it cannot be waited. Note that mechanics of this operation is different on UNIX/Linux (the thread is put to detached state) and Windows (the handle is closed). However, the purpose is the same: to instruct the system to release all thread data upon its completion.");
	cls_OSD_Thread.def("Wait", (Standard_Boolean (OSD_Thread::*)()) &OSD_Thread::Wait, "Waits till the thread finishes execution.");
	cls_OSD_Thread.def("Wait", (Standard_Boolean (OSD_Thread::*)(Standard_Address &)) &OSD_Thread::Wait, "Wait till the thread finishes execution. Returns True if wait was successful, False in case of error.", py::arg("theResult"));
	cls_OSD_Thread.def("Wait", (Standard_Boolean (OSD_Thread::*)(const Standard_Integer, Standard_Address &)) &OSD_Thread::Wait, "Waits for some time and if the thread is finished, it returns the result. The function returns false if the thread is not finished yet.", py::arg("time"), py::arg("theResult"));
	cls_OSD_Thread.def("GetId", (Standard_ThreadId (OSD_Thread::*)() const ) &OSD_Thread::GetId, "Returns ID of the currently controlled thread ID, or 0 if no thread is run");
	cls_OSD_Thread.def_static("Current_", (Standard_ThreadId (*)()) &OSD_Thread::Current, "Auxiliary: returns ID of the current thread");

	// C:\Miniconda\envs\occt\Library\include\opencascade\OSD_Parallel.hxx
	py::class_<OSD_Parallel, std::unique_ptr<OSD_Parallel, Deleter<OSD_Parallel>>> cls_OSD_Parallel(mod, "OSD_Parallel", "Simplifies code parallelization.");
	cls_OSD_Parallel.def(py::init<>());
	cls_OSD_Parallel.def_static("NbLogicalProcessors_", (Standard_Integer (*)()) &OSD_Parallel::NbLogicalProcessors, "Returns number of logical proccesrs.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\OSD_Error.hxx
	py::class_<OSD_Error, std::unique_ptr<OSD_Error, Deleter<OSD_Error>>> cls_OSD_Error(mod, "OSD_Error", "Accurate management of OSD specific errors.");
	cls_OSD_Error.def(py::init<>());
	cls_OSD_Error.def("Perror", (void (OSD_Error::*)()) &OSD_Error::Perror, "Raises OSD_Error with accurate error message.");
	cls_OSD_Error.def("SetValue", (void (OSD_Error::*)(const Standard_Integer, const Standard_Integer, const TCollection_AsciiString &)) &OSD_Error::SetValue, "Instantiates error This is only used by OSD methods to instantiates an error code. No description is done for the programmer.", py::arg("Errcode"), py::arg("From"), py::arg("Message"));
	cls_OSD_Error.def("Error", (Standard_Integer (OSD_Error::*)() const ) &OSD_Error::Error, "Returns an accurate error code. To test these values, you must include 'OSD_ErrorList.hxx'");
	cls_OSD_Error.def("Failed", (Standard_Boolean (OSD_Error::*)() const ) &OSD_Error::Failed, "Returns TRUE if an error occurs This is a way to test if a system call succeeded or not.");
	cls_OSD_Error.def("Reset", (void (OSD_Error::*)()) &OSD_Error::Reset, "Resets error counter to zero This allows the user to ignore an error (WARNING).");

	// C:\Miniconda\envs\occt\Library\include\opencascade\OSD_Protection.hxx
	py::class_<OSD_Protection, std::unique_ptr<OSD_Protection, Deleter<OSD_Protection>>> cls_OSD_Protection(mod, "OSD_Protection", "This class provides data to manage file protection Example:These rights are treated in a system dependent manner : On UNIX you have User,Group and Other rights On VMS you have Owner,Group,World and System rights An automatic conversion is done between OSD and UNIX/VMS.");
	cls_OSD_Protection.def(py::init<>());
	cls_OSD_Protection.def(py::init<const OSD_SingleProtection, const OSD_SingleProtection, const OSD_SingleProtection, const OSD_SingleProtection>(), py::arg("System"), py::arg("User"), py::arg("Group"), py::arg("World"));
	cls_OSD_Protection.def("Values", (void (OSD_Protection::*)(OSD_SingleProtection &, OSD_SingleProtection &, OSD_SingleProtection &, OSD_SingleProtection &)) &OSD_Protection::Values, "Retrieves values of fields", py::arg("System"), py::arg("User"), py::arg("Group"), py::arg("World"));
	cls_OSD_Protection.def("SetValues", (void (OSD_Protection::*)(const OSD_SingleProtection, const OSD_SingleProtection, const OSD_SingleProtection, const OSD_SingleProtection)) &OSD_Protection::SetValues, "Sets values of fields", py::arg("System"), py::arg("User"), py::arg("Group"), py::arg("World"));
	cls_OSD_Protection.def("SetSystem", (void (OSD_Protection::*)(const OSD_SingleProtection)) &OSD_Protection::SetSystem, "Sets protection of 'System'", py::arg("priv"));
	cls_OSD_Protection.def("SetUser", (void (OSD_Protection::*)(const OSD_SingleProtection)) &OSD_Protection::SetUser, "Sets protection of 'User'", py::arg("priv"));
	cls_OSD_Protection.def("SetGroup", (void (OSD_Protection::*)(const OSD_SingleProtection)) &OSD_Protection::SetGroup, "Sets protection of 'Group'", py::arg("priv"));
	cls_OSD_Protection.def("SetWorld", (void (OSD_Protection::*)(const OSD_SingleProtection)) &OSD_Protection::SetWorld, "Sets protection of 'World'", py::arg("priv"));
	cls_OSD_Protection.def("System", (OSD_SingleProtection (OSD_Protection::*)() const ) &OSD_Protection::System, "Gets protection of 'System'");
	cls_OSD_Protection.def("User", (OSD_SingleProtection (OSD_Protection::*)() const ) &OSD_Protection::User, "Gets protection of 'User'");
	cls_OSD_Protection.def("Group", (OSD_SingleProtection (OSD_Protection::*)() const ) &OSD_Protection::Group, "Gets protection of 'Group'");
	cls_OSD_Protection.def("World", (OSD_SingleProtection (OSD_Protection::*)() const ) &OSD_Protection::World, "Gets protection of 'World'");
	cls_OSD_Protection.def("Add", (void (OSD_Protection::*)(OSD_SingleProtection &, const OSD_SingleProtection)) &OSD_Protection::Add, "Add a right to a single protection. ex: aProt = RWD me.Add(aProt,X) -> aProt = RWXD", py::arg("aProt"), py::arg("aRight"));
	cls_OSD_Protection.def("Sub", (void (OSD_Protection::*)(OSD_SingleProtection &, const OSD_SingleProtection)) &OSD_Protection::Sub, "Subtract a right to a single protection. ex: aProt = RWD me.Sub(aProt,RW) -> aProt = D But me.Sub(aProt,RWX) is also valid and gives same result.", py::arg("aProt"), py::arg("aRight"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\OSD_FileNode.hxx
	py::class_<OSD_FileNode, std::unique_ptr<OSD_FileNode, py::nodelete>> cls_OSD_FileNode(mod, "OSD_FileNode", "A class for 'File' and 'Directory' grouping common methods (file/directory manipulation tools). The 'file oriented' name means files or directories which are in fact hard coded as files.");
	cls_OSD_FileNode.def("Path", (void (OSD_FileNode::*)(OSD_Path &) const ) &OSD_FileNode::Path, "Gets file name and path.", py::arg("Name"));
	cls_OSD_FileNode.def("SetPath", (void (OSD_FileNode::*)(const OSD_Path &)) &OSD_FileNode::SetPath, "Sets file name and path. If a name is not found, it raises a program error.", py::arg("Name"));
	cls_OSD_FileNode.def("Exists", (Standard_Boolean (OSD_FileNode::*)()) &OSD_FileNode::Exists, "Returns TRUE if <me> exists.");
	cls_OSD_FileNode.def("Remove", (void (OSD_FileNode::*)()) &OSD_FileNode::Remove, "Erases the FileNode from directory");
	cls_OSD_FileNode.def("Move", (void (OSD_FileNode::*)(const OSD_Path &)) &OSD_FileNode::Move, "Moves <me> into another directory", py::arg("NewPath"));
	cls_OSD_FileNode.def("Copy", (void (OSD_FileNode::*)(const OSD_Path &)) &OSD_FileNode::Copy, "Copies <me> to another FileNode", py::arg("ToPath"));
	cls_OSD_FileNode.def("Protection", (OSD_Protection (OSD_FileNode::*)()) &OSD_FileNode::Protection, "Returns access mode of <me>.");
	cls_OSD_FileNode.def("SetProtection", (void (OSD_FileNode::*)(const OSD_Protection &)) &OSD_FileNode::SetProtection, "Changes protection of the FileNode", py::arg("Prot"));
	cls_OSD_FileNode.def("AccessMoment", (Quantity_Date (OSD_FileNode::*)()) &OSD_FileNode::AccessMoment, "Returns last write access. On UNIX, AccessMoment and CreationMoment return the same value.");
	cls_OSD_FileNode.def("CreationMoment", (Quantity_Date (OSD_FileNode::*)()) &OSD_FileNode::CreationMoment, "Returns creation date. On UNIX, AccessMoment and CreationMoment return the same value.");
	cls_OSD_FileNode.def("Failed", (Standard_Boolean (OSD_FileNode::*)() const ) &OSD_FileNode::Failed, "Returns TRUE if an error occurs");
	cls_OSD_FileNode.def("Reset", (void (OSD_FileNode::*)()) &OSD_FileNode::Reset, "Resets error counter to zero");
	cls_OSD_FileNode.def("Perror", (void (OSD_FileNode::*)()) &OSD_FileNode::Perror, "Raises OSD_Error");
	cls_OSD_FileNode.def("Error", (Standard_Integer (OSD_FileNode::*)() const ) &OSD_FileNode::Error, "Returns error number if 'Failed' is TRUE.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\OSD_Disk.hxx
	py::class_<OSD_Disk, std::unique_ptr<OSD_Disk, Deleter<OSD_Disk>>> cls_OSD_Disk(mod, "OSD_Disk", "Disk management (a set of disk oriented tools)");
	cls_OSD_Disk.def(py::init<>());
	cls_OSD_Disk.def(py::init<const OSD_Path &>(), py::arg("Name"));
	cls_OSD_Disk.def(py::init<const Standard_CString>(), py::arg("PathName"));
	cls_OSD_Disk.def("Name", (OSD_Path (OSD_Disk::*)() const ) &OSD_Disk::Name, "Returns disk name of <me>.");
	cls_OSD_Disk.def("SetName", (void (OSD_Disk::*)(const OSD_Path &)) &OSD_Disk::SetName, "Instantiates <me> with <Name>.", py::arg("Name"));
	cls_OSD_Disk.def("DiskSize", (Standard_Integer (OSD_Disk::*)()) &OSD_Disk::DiskSize, "Returns total disk capacity in 512 bytes blocks.");
	cls_OSD_Disk.def("DiskFree", (Standard_Integer (OSD_Disk::*)()) &OSD_Disk::DiskFree, "Returns free available 512 bytes blocks on disk.");
	cls_OSD_Disk.def("DiskQuota", (Standard_Integer (OSD_Disk::*)()) &OSD_Disk::DiskQuota, "Returns user's disk quota (in Bytes).");
	cls_OSD_Disk.def("SetDiskQuota", (void (OSD_Disk::*)(const Standard_Integer)) &OSD_Disk::SetDiskQuota, "Sets user's disk quota (in Bytes). Warning: Needs system administrator privilege.", py::arg("QuotaSize"));
	cls_OSD_Disk.def("SetQuotaOn", (void (OSD_Disk::*)()) &OSD_Disk::SetQuotaOn, "Activates user's disk quota Warning: Needs system administrator privilege.");
	cls_OSD_Disk.def("SetQuotaOff", (void (OSD_Disk::*)()) &OSD_Disk::SetQuotaOff, "Deactivates user's disk quota Warning: Needs system administrator privilege.");
	cls_OSD_Disk.def("Failed", (Standard_Boolean (OSD_Disk::*)() const ) &OSD_Disk::Failed, "Returns TRUE if an error occurs");
	cls_OSD_Disk.def("Reset", (void (OSD_Disk::*)()) &OSD_Disk::Reset, "Resets error counter to zero");
	cls_OSD_Disk.def("Perror", (void (OSD_Disk::*)()) &OSD_Disk::Perror, "Raises OSD_Error");
	cls_OSD_Disk.def("Error", (Standard_Integer (OSD_Disk::*)() const ) &OSD_Disk::Error, "Returns error number if 'Failed' is TRUE.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\OSD_File.hxx
	py::class_<OSD_File, std::unique_ptr<OSD_File, Deleter<OSD_File>>, OSD_FileNode> cls_OSD_File(mod, "OSD_File", "Basic tools to manage files Warning: 'ProgramError' is raised when somebody wants to use the methods Read, Write, Seek, Close when File is not open.");
	cls_OSD_File.def(py::init<>());
	cls_OSD_File.def(py::init<const OSD_Path &>(), py::arg("Name"));
	cls_OSD_File.def("Build", (void (OSD_File::*)(const OSD_OpenMode, const OSD_Protection &)) &OSD_File::Build, "CREATES a file if it doesn't already exists or empties an existing file. After 'Build', the file is open. If no name was given, ProgramError is raised.", py::arg("Mode"), py::arg("Protect"));
	cls_OSD_File.def("Open", (void (OSD_File::*)(const OSD_OpenMode, const OSD_Protection &)) &OSD_File::Open, "Opens a File with specific attributes This works only on already existing file. If no name was given, ProgramError is raised.", py::arg("Mode"), py::arg("Protect"));
	cls_OSD_File.def("Append", (void (OSD_File::*)(const OSD_OpenMode, const OSD_Protection &)) &OSD_File::Append, "Appends data to an existing file. If file doesn't exist, creates it first. After 'Append', the file is open. If no name was given, ProgramError is raised.", py::arg("Mode"), py::arg("Protect"));
	cls_OSD_File.def("Read", (void (OSD_File::*)(TCollection_AsciiString &, const Standard_Integer)) &OSD_File::Read, "Attempts to read Nbyte bytes from the file associated with the object file. Upon successful completion, Read returns the number of bytes actually read and placed in the Buffer. This number may be less than Nbyte if the number of bytes left in the file is less than Nbyte bytes. In this case only number of read bytes will be placed in the buffer.", py::arg("Buffer"), py::arg("Nbyte"));
	cls_OSD_File.def("ReadLine", [](OSD_File &self, TCollection_AsciiString & Buffer, const Standard_Integer NByte, Standard_Integer & NbyteRead){ self.ReadLine(Buffer, NByte, NbyteRead); return NbyteRead; }, "Reads bytes from the data pointed to by the object file into the buffer <Buffer>. Data is read until <NByte-1> bytes have been read, until a newline character is read and transferred into <Buffer>, or until an EOF (End-of-File) condition is encountered. Upon successful completion, Read returns the number of bytes actually read into <NByteRead> and placed into the Buffer <Buffer>.", py::arg("Buffer"), py::arg("NByte"), py::arg("NbyteRead"));
	cls_OSD_File.def("ReadLine", (Standard_Integer (OSD_File::*)(TCollection_AsciiString &, const Standard_Integer)) &OSD_File::ReadLine, "Reads bytes from the data pointed to by the object file into the buffer <Buffer>. Data is read until <NByte-1> bytes have been read, until a newline character is read and transferred into <Buffer>, or until an EOF (End-of-File) condition is encountered. Upon successful completion, Read returns the number of bytes actually read and placed into the Buffer <Buffer>.", py::arg("Buffer"), py::arg("NByte"));
	cls_OSD_File.def("Read", [](OSD_File &self, const Standard_Address Buffer, const Standard_Integer Nbyte, Standard_Integer & Readbyte){ self.Read(Buffer, Nbyte, Readbyte); return Readbyte; }, "Attempts to read Nbyte bytes from the files associated with the object File. Upon successful completion, Read returns the number of bytes actually read and placed in the Buffer. This number may be less than Nbyte if the number of bytes left in the file is less than Nbyte bytes. For this reason the output parameter Readbyte will contain the number of read bytes.", py::arg("Buffer"), py::arg("Nbyte"), py::arg("Readbyte"));
	cls_OSD_File.def("Write", (void (OSD_File::*)(const TCollection_AsciiString &, const Standard_Integer)) &OSD_File::Write, "Attempts to write Nbyte bytes from the AsciiString to the file associated to the object File.", py::arg("Buffer"), py::arg("Nbyte"));
	cls_OSD_File.def("Write", (void (OSD_File::*)(const Standard_Address, const Standard_Integer)) &OSD_File::Write, "Attempts to write Nbyte bytes from the buffer pointed to by Buffer to the file associated to the object File.", py::arg("Buffer"), py::arg("Nbyte"));
	cls_OSD_File.def("Seek", (void (OSD_File::*)(const Standard_Integer, const OSD_FromWhere)) &OSD_File::Seek, "Sets the seek pointer associated with the open file", py::arg("Offset"), py::arg("Whence"));
	cls_OSD_File.def("Close", (void (OSD_File::*)()) &OSD_File::Close, "Closes the file (and deletes a descriptor)");
	cls_OSD_File.def("IsAtEnd", (Standard_Boolean (OSD_File::*)()) &OSD_File::IsAtEnd, "Returns TRUE if the seek pointer is at end of file.");
	cls_OSD_File.def("KindOfFile", (OSD_KindFile (OSD_File::*)() const ) &OSD_File::KindOfFile, "Returns the kind of file. A file can be a file, a directory or a link.");
	cls_OSD_File.def("BuildTemporary", (void (OSD_File::*)()) &OSD_File::BuildTemporary, "Makes a temporary File This temporary file is already open !");
	cls_OSD_File.def("SetLock", (void (OSD_File::*)(const OSD_LockType)) &OSD_File::SetLock, "Locks current file", py::arg("Lock"));
	cls_OSD_File.def("UnLock", (void (OSD_File::*)()) &OSD_File::UnLock, "Unlocks current file");
	cls_OSD_File.def("GetLock", (OSD_LockType (OSD_File::*)()) &OSD_File::GetLock, "Returns the current lock state");
	cls_OSD_File.def("IsLocked", (Standard_Boolean (OSD_File::*)()) &OSD_File::IsLocked, "Returns TRUE if this file is locked.");
	cls_OSD_File.def("Size", (Standard_Size (OSD_File::*)()) &OSD_File::Size, "Returns actual number of bytes of <me>.");
	cls_OSD_File.def("IsOpen", (Standard_Boolean (OSD_File::*)() const ) &OSD_File::IsOpen, "Returns TRUE if <me> is open.");
	cls_OSD_File.def("IsReadable", (Standard_Boolean (OSD_File::*)()) &OSD_File::IsReadable, "returns TRUE if the file exists and if the user has the autorization to read it.");
	cls_OSD_File.def("IsWriteable", (Standard_Boolean (OSD_File::*)()) &OSD_File::IsWriteable, "returns TRUE if the file can be read and overwritten.");
	cls_OSD_File.def("IsExecutable", (Standard_Boolean (OSD_File::*)()) &OSD_File::IsExecutable, "returns TRUE if the file can be executed.");
	cls_OSD_File.def("ReadLastLine", (Standard_Boolean (OSD_File::*)(TCollection_AsciiString &, const Standard_Integer, const Standard_Integer)) &OSD_File::ReadLastLine, "Enables to emulate unix 'tail -f' command. If a line is available in the file <me> returns it. Otherwise attemps to read again aNbTries times in the file waiting aDelay seconds between each read. If meanwhile the file increases returns the next line, otherwise returns FALSE.", py::arg("aLine"), py::arg("aDelay"), py::arg("aNbTries"));
	cls_OSD_File.def("Edit", (Standard_Boolean (OSD_File::*)()) &OSD_File::Edit, "find an editor on the system and edit the given file");
	cls_OSD_File.def("Rewind", (void (OSD_File::*)()) &OSD_File::Rewind, "Set file pointer position to the beginning of the file");
	cls_OSD_File.def("Capture", (int (OSD_File::*)(int)) &OSD_File::Capture, "Redirect a standard handle (fileno(stdout), fileno(stdin) or fileno(stderr) to this OSD_File and return the copy of the original standard handle. Example: OSD_File aTmp; aTmp.BuildTemporary(); int stdfd = _fileno(stdout);", py::arg("theDescr"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\OSD_FileIterator.hxx
	py::class_<OSD_FileIterator, std::unique_ptr<OSD_FileIterator, Deleter<OSD_FileIterator>>> cls_OSD_FileIterator(mod, "OSD_FileIterator", "Manages a breadth-only search for files in the specified Path. There is no specific order of results.");
	cls_OSD_FileIterator.def(py::init<>());
	cls_OSD_FileIterator.def(py::init<const OSD_Path &, const TCollection_AsciiString &>(), py::arg("where"), py::arg("Mask"));
	cls_OSD_FileIterator.def("Destroy", (void (OSD_FileIterator::*)()) &OSD_FileIterator::Destroy, "None");
	cls_OSD_FileIterator.def("Initialize", (void (OSD_FileIterator::*)(const OSD_Path &, const TCollection_AsciiString &)) &OSD_FileIterator::Initialize, "Initializes the current File Iterator", py::arg("where"), py::arg("Mask"));
	cls_OSD_FileIterator.def("More", (Standard_Boolean (OSD_FileIterator::*)()) &OSD_FileIterator::More, "Returns TRUE if there are other items using the 'Tree' method.");
	cls_OSD_FileIterator.def("Next", (void (OSD_FileIterator::*)()) &OSD_FileIterator::Next, "Sets the iterator to the next item. Returns the item value corresponding to the current position of the iterator.");
	cls_OSD_FileIterator.def("Values", (OSD_File (OSD_FileIterator::*)()) &OSD_FileIterator::Values, "Returns the next file found .");
	cls_OSD_FileIterator.def("Failed", (Standard_Boolean (OSD_FileIterator::*)() const ) &OSD_FileIterator::Failed, "Returns TRUE if an error occurs");
	cls_OSD_FileIterator.def("Reset", (void (OSD_FileIterator::*)()) &OSD_FileIterator::Reset, "Resets error counter to zero");
	cls_OSD_FileIterator.def("Perror", (void (OSD_FileIterator::*)()) &OSD_FileIterator::Perror, "Raises OSD_Error");
	cls_OSD_FileIterator.def("Error", (Standard_Integer (OSD_FileIterator::*)() const ) &OSD_FileIterator::Error, "Returns error number if 'Failed' is TRUE.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\OSD_Directory.hxx
	py::class_<OSD_Directory, std::unique_ptr<OSD_Directory, Deleter<OSD_Directory>>, OSD_FileNode> cls_OSD_Directory(mod, "OSD_Directory", "Management of directories (a set of directory oriented tools)");
	cls_OSD_Directory.def(py::init<>());
	cls_OSD_Directory.def(py::init<const OSD_Path &>(), py::arg("Name"));
	cls_OSD_Directory.def("Build", (void (OSD_Directory::*)(const OSD_Protection &)) &OSD_Directory::Build, "Creates (physically) a directory. When a directory of the same name already exists, no error is returned, and only <Protect> is applied to the existing directory.", py::arg("Protect"));
	cls_OSD_Directory.def_static("BuildTemporary_", (OSD_Directory (*)()) &OSD_Directory::BuildTemporary, "Creates a temporary Directory in current directory. This directory is automatically removed when object dies.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\OSD_DirectoryIterator.hxx
	py::class_<OSD_DirectoryIterator, std::unique_ptr<OSD_DirectoryIterator, Deleter<OSD_DirectoryIterator>>> cls_OSD_DirectoryIterator(mod, "OSD_DirectoryIterator", "Manages a breadth-only search for sub-directories in the specified Path. There is no specific order of results.");
	cls_OSD_DirectoryIterator.def(py::init<>());
	cls_OSD_DirectoryIterator.def(py::init<const OSD_Path &, const TCollection_AsciiString &>(), py::arg("where"), py::arg("Mask"));
	cls_OSD_DirectoryIterator.def("Destroy", (void (OSD_DirectoryIterator::*)()) &OSD_DirectoryIterator::Destroy, "None");
	cls_OSD_DirectoryIterator.def("Initialize", (void (OSD_DirectoryIterator::*)(const OSD_Path &, const TCollection_AsciiString &)) &OSD_DirectoryIterator::Initialize, "Initializes the current File Directory", py::arg("where"), py::arg("Mask"));
	cls_OSD_DirectoryIterator.def("More", (Standard_Boolean (OSD_DirectoryIterator::*)()) &OSD_DirectoryIterator::More, "Returns TRUE if other items are found while using the 'Tree' method.");
	cls_OSD_DirectoryIterator.def("Next", (void (OSD_DirectoryIterator::*)()) &OSD_DirectoryIterator::Next, "Sets the iterator to the next item. Returns the item value corresponding to the current position of the iterator.");
	cls_OSD_DirectoryIterator.def("Values", (OSD_Directory (OSD_DirectoryIterator::*)()) &OSD_DirectoryIterator::Values, "Returns the next item found .");
	cls_OSD_DirectoryIterator.def("Failed", (Standard_Boolean (OSD_DirectoryIterator::*)() const ) &OSD_DirectoryIterator::Failed, "Returns TRUE if an error occurs");
	cls_OSD_DirectoryIterator.def("Reset", (void (OSD_DirectoryIterator::*)()) &OSD_DirectoryIterator::Reset, "Resets error counter to zero");
	cls_OSD_DirectoryIterator.def("Perror", (void (OSD_DirectoryIterator::*)()) &OSD_DirectoryIterator::Perror, "Raises OSD_Error");
	cls_OSD_DirectoryIterator.def("Error", (Standard_Integer (OSD_DirectoryIterator::*)() const ) &OSD_DirectoryIterator::Error, "Returns error number if 'Failed' is TRUE.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\OSD_Host.hxx
	py::class_<OSD_Host, std::unique_ptr<OSD_Host, Deleter<OSD_Host>>> cls_OSD_Host(mod, "OSD_Host", "Carries information about a Host System version ,host name, nodename ...");
	cls_OSD_Host.def(py::init<>());
	cls_OSD_Host.def("SystemVersion", (TCollection_AsciiString (OSD_Host::*)()) &OSD_Host::SystemVersion, "Returns system name and version");
	cls_OSD_Host.def("SystemId", (OSD_SysType (OSD_Host::*)() const ) &OSD_Host::SystemId, "Returns the system type (UNIX System V, UNIX BSD, MS-DOS...)");
	cls_OSD_Host.def("HostName", (TCollection_AsciiString (OSD_Host::*)()) &OSD_Host::HostName, "Returns host name.");
	cls_OSD_Host.def("AvailableMemory", (Standard_Integer (OSD_Host::*)()) &OSD_Host::AvailableMemory, "Returns available memory in Kilobytes.");
	cls_OSD_Host.def("InternetAddress", (TCollection_AsciiString (OSD_Host::*)()) &OSD_Host::InternetAddress, "Returns Internet address of current host.");
	cls_OSD_Host.def("MachineType", (OSD_OEMType (OSD_Host::*)()) &OSD_Host::MachineType, "Returns type of current machine.");
	cls_OSD_Host.def("Failed", (Standard_Boolean (OSD_Host::*)() const ) &OSD_Host::Failed, "Returns TRUE if an error occurs");
	cls_OSD_Host.def("Reset", (void (OSD_Host::*)()) &OSD_Host::Reset, "Resets error counter to zero");
	cls_OSD_Host.def("Perror", (void (OSD_Host::*)()) &OSD_Host::Perror, "Raises OSD_Error");
	cls_OSD_Host.def("Error", (Standard_Integer (OSD_Host::*)() const ) &OSD_Host::Error, "Returns error number if 'Failed' is TRUE.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\OSD_Environment.hxx
	py::class_<OSD_Environment, std::unique_ptr<OSD_Environment, Deleter<OSD_Environment>>> cls_OSD_Environment(mod, "OSD_Environment", "Management of system environment variables An environment variable is composed of a variable name and its value.");
	cls_OSD_Environment.def(py::init<>());
	cls_OSD_Environment.def(py::init<const TCollection_AsciiString &>(), py::arg("Name"));
	cls_OSD_Environment.def(py::init<const TCollection_AsciiString &, const TCollection_AsciiString &>(), py::arg("Name"), py::arg("Value"));
	cls_OSD_Environment.def("SetValue", (void (OSD_Environment::*)(const TCollection_AsciiString &)) &OSD_Environment::SetValue, "Changes environment variable value. Raises ConstructionError either if the string contains characters not in range of ' '...'~' or if the string contains the character '$' which is forbiden.", py::arg("Value"));
	cls_OSD_Environment.def("Value", (TCollection_AsciiString (OSD_Environment::*)()) &OSD_Environment::Value, "Gets the value of an environment variable");
	cls_OSD_Environment.def("SetName", (void (OSD_Environment::*)(const TCollection_AsciiString &)) &OSD_Environment::SetName, "Changes environment variable name. Raises ConstructionError either if the string contains characters not in range of ' '...'~' or if the string contains the character '$' which is forbiden.", py::arg("name"));
	cls_OSD_Environment.def("Name", (TCollection_AsciiString (OSD_Environment::*)() const ) &OSD_Environment::Name, "Gets the name of <me>.");
	cls_OSD_Environment.def("Build", (void (OSD_Environment::*)()) &OSD_Environment::Build, "Sets the value of an environment variable into system (physically).");
	cls_OSD_Environment.def("Remove", (void (OSD_Environment::*)()) &OSD_Environment::Remove, "Removes (physically) an environment variable");
	cls_OSD_Environment.def("Failed", (Standard_Boolean (OSD_Environment::*)() const ) &OSD_Environment::Failed, "Returns TRUE if an error occurs");
	cls_OSD_Environment.def("Reset", (void (OSD_Environment::*)()) &OSD_Environment::Reset, "Resets error counter to zero");
	cls_OSD_Environment.def("Perror", (void (OSD_Environment::*)()) &OSD_Environment::Perror, "Raises OSD_Error");
	cls_OSD_Environment.def("Error", (Standard_Integer (OSD_Environment::*)() const ) &OSD_Environment::Error, "Returns error number if 'Failed' is TRUE.");

	/* FIXME
	// C:\Miniconda\envs\occt\Library\include\opencascade\OSD.hxx
	py::class_<OSD_EnvironmentIterator, std::unique_ptr<OSD_EnvironmentIterator, Deleter<OSD_EnvironmentIterator>>> cls_OSD_EnvironmentIterator(mod, "OSD_EnvironmentIterator", "None");
	cls_OSD_EnvironmentIterator.def(py::init<>());
	*/

	// C:\Miniconda\envs\occt\Library\include\opencascade\OSD_Process.hxx
	py::class_<OSD_Process, std::unique_ptr<OSD_Process, Deleter<OSD_Process>>> cls_OSD_Process(mod, "OSD_Process", "A set of system process tools");
	cls_OSD_Process.def(py::init<>());
	cls_OSD_Process.def("Spawn", [](OSD_Process &self, const TCollection_AsciiString & a0) -> Standard_Integer { return self.Spawn(a0); }, py::arg("cmd"));
	cls_OSD_Process.def("Spawn", (Standard_Integer (OSD_Process::*)(const TCollection_AsciiString &, const Standard_Boolean)) &OSD_Process::Spawn, "Issues a shell command ShowWindow : flag to allow show/hide of the window ( only used on WNT )", py::arg("cmd"), py::arg("ShowWindow"));
	cls_OSD_Process.def("TerminalType", (void (OSD_Process::*)(TCollection_AsciiString &)) &OSD_Process::TerminalType, "Returns the terminal used (vt100, vt200 ,sun-cmd ...)", py::arg("Name"));
	cls_OSD_Process.def("SystemDate", (Quantity_Date (OSD_Process::*)()) &OSD_Process::SystemDate, "Gets system date.");
	cls_OSD_Process.def("UserName", (TCollection_AsciiString (OSD_Process::*)()) &OSD_Process::UserName, "Returns the user name.");
	cls_OSD_Process.def("IsSuperUser", (Standard_Boolean (OSD_Process::*)()) &OSD_Process::IsSuperUser, "Returns True if the process user is the super-user.");
	cls_OSD_Process.def("ProcessId", (Standard_Integer (OSD_Process::*)()) &OSD_Process::ProcessId, "Returns the 'Process Id'");
	cls_OSD_Process.def("CurrentDirectory", (OSD_Path (OSD_Process::*)()) &OSD_Process::CurrentDirectory, "Returns the current path where the process is.");
	cls_OSD_Process.def("SetCurrentDirectory", (void (OSD_Process::*)(const OSD_Path &)) &OSD_Process::SetCurrentDirectory, "Changes the current process directory.", py::arg("where"));
	cls_OSD_Process.def("Failed", (Standard_Boolean (OSD_Process::*)() const ) &OSD_Process::Failed, "Returns TRUE if an error occurs");
	cls_OSD_Process.def("Reset", (void (OSD_Process::*)()) &OSD_Process::Reset, "Resets error counter to zero");
	cls_OSD_Process.def("Perror", (void (OSD_Process::*)()) &OSD_Process::Perror, "Raises OSD_Error");
	cls_OSD_Process.def("Error", (Standard_Integer (OSD_Process::*)() const ) &OSD_Process::Error, "Returns error number if 'Failed' is TRUE.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\OSD_SharedLibrary.hxx
	py::class_<OSD_SharedLibrary, std::unique_ptr<OSD_SharedLibrary, Deleter<OSD_SharedLibrary>>> cls_OSD_SharedLibrary(mod, "OSD_SharedLibrary", "Interface to dynamic library loader. Provides tools to load a shared library and retrieve the address of an entry point.");
	cls_OSD_SharedLibrary.def(py::init<>());
	cls_OSD_SharedLibrary.def(py::init<const Standard_CString>(), py::arg("aFilename"));
	cls_OSD_SharedLibrary.def("SetName", (void (OSD_SharedLibrary::*)(const Standard_CString)) &OSD_SharedLibrary::SetName, "Sets a name associated to the shared object.", py::arg("aName"));
	cls_OSD_SharedLibrary.def("Name", (Standard_CString (OSD_SharedLibrary::*)() const ) &OSD_SharedLibrary::Name, "Returns the name associated to the shared object.");
	cls_OSD_SharedLibrary.def("DlOpen", (Standard_Boolean (OSD_SharedLibrary::*)(const OSD_LoadMode)) &OSD_SharedLibrary::DlOpen, "The DlOpen method provides an interface to the dynamic library loader to allow shared libraries to be loaded and called at runtime. The DlOpen function attempts to load Filename, in the address space of the process, resolving symbols as appropriate. Any libraries that Filename depends upon are also loaded. If MODE is RTLD_LAZY, then the runtime loader does symbol resolution only as needed. Typically, this means that the first call to a function in the newly loaded library will cause the resolution of the address of that function to occur. If Mode is RTLD_NOW, then the runtime loader must do all symbol binding during the DlOpen call. The DlOpen method returns a handle that is used by DlSym or DlClose. If there is an error, Standard_False is returned, Standard_True otherwise. If a NULL Filename is specified, DlOpen returns a handle for the main executable, which allows access to dynamic symbols in the running program.", py::arg("Mode"));
	// FIXME cls_OSD_SharedLibrary.def("DlSymb", (OSD_Function (OSD_SharedLibrary::*)(const Standard_CString) const ) &OSD_SharedLibrary::DlSymb, "The dlsym function returns the address of the symbol name found in the shared library. If the symbol is not found, a NULL pointer is returned.", py::arg("Name"));
	cls_OSD_SharedLibrary.def("DlClose", (void (OSD_SharedLibrary::*)() const ) &OSD_SharedLibrary::DlClose, "Deallocates the address space for the library corresponding to the shared object. If any user function continues to call a symbol resolved in the address space of a library that has been since been deallocated by DlClose, the results are undefined.");
	cls_OSD_SharedLibrary.def("DlError", (Standard_CString (OSD_SharedLibrary::*)() const ) &OSD_SharedLibrary::DlError, "The dlerror function returns a string describing the last error that occurred from a call to DlOpen, DlClose or DlSym.");
	cls_OSD_SharedLibrary.def("Destroy", (void (OSD_SharedLibrary::*)()) &OSD_SharedLibrary::Destroy, "Frees memory allocated.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\OSD.hxx
	py::class_<OSD, std::unique_ptr<OSD, Deleter<OSD>>> cls_OSD(mod, "OSD", "Set of Operating Sytem Dependent Tools (O)perating (S)ystem (D)ependent");
	cls_OSD.def(py::init<>());
	cls_OSD.def_static("SetSignal_", []() -> void { return OSD::SetSignal(); });
	cls_OSD.def_static("SetSignal_", (void (*)(const Standard_Boolean)) &OSD::SetSignal, "Sets signal and exception handlers.", py::arg("theFloatingSignal"));
	cls_OSD.def_static("SecSleep_", (void (*)(const Standard_Integer)) &OSD::SecSleep, "Commands the process to sleep for a number of seconds.", py::arg("aDelay"));
	cls_OSD.def_static("MilliSecSleep_", (void (*)(const Standard_Integer)) &OSD::MilliSecSleep, "Commands the process to sleep for a number of milliseconds", py::arg("aDelay"));
	// FIXME cls_OSD.def_static("RealToCString_", (Standard_Boolean (*)(const Standard_Real, Standard_PCharacter &)) &OSD::RealToCString, "Converts aReal into aCstring in exponential format with a period as decimal point, no thousand separator and no grouping of digits. The conversion is independant from the current locale", py::arg("aReal"), py::arg("aString"));
	cls_OSD.def_static("CStringToReal_", [](const Standard_CString aString, Standard_Real & aReal){ Standard_Boolean rv = OSD::CStringToReal(aString, aReal); return std::tuple<Standard_Boolean, Standard_Real &>(rv, aReal); }, "Converts aCstring representing a real with a period as decimal point, no thousand separator and no grouping of digits into aReal . The conversion is independant from the current locale.", py::arg("aString"), py::arg("aReal"));
	cls_OSD.def_static("ControlBreak_", (void (*)()) &OSD::ControlBreak, "since Windows NT does not support 'SIGINT' signal like UNIX, then this method checks whether Ctrl-Break keystroke was or not. If yes then raises Exception_CTRL_BREAK.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\OSD_Exception.hxx
	py::class_<OSD_Exception, opencascade::handle<OSD_Exception>, Standard_Failure> cls_OSD_Exception(mod, "OSD_Exception", "None");
	cls_OSD_Exception.def(py::init<>());
	cls_OSD_Exception.def(py::init<const Standard_CString>(), py::arg("theMessage"));
	cls_OSD_Exception.def_static("Raise_", (void (*)(const Standard_CString)) &OSD_Exception::Raise, "None", py::arg("theMessage"));
	cls_OSD_Exception.def_static("Raise_", (void (*)(Standard_SStream &)) &OSD_Exception::Raise, "None", py::arg("theMessage"));
	cls_OSD_Exception.def_static("NewInstance_", (opencascade::handle<OSD_Exception> (*)(const Standard_CString)) &OSD_Exception::NewInstance, "None", py::arg("theMessage"));
	cls_OSD_Exception.def_static("get_type_name_", (const char * (*)()) &OSD_Exception::get_type_name, "None");
	cls_OSD_Exception.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &OSD_Exception::get_type_descriptor, "None");
	cls_OSD_Exception.def("DynamicType", (const opencascade::handle<Standard_Type> & (OSD_Exception::*)() const ) &OSD_Exception::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\OSD_Exception_ACCESS_VIOLATION.hxx
	py::class_<OSD_Exception_ACCESS_VIOLATION, opencascade::handle<OSD_Exception_ACCESS_VIOLATION>, OSD_Exception> cls_OSD_Exception_ACCESS_VIOLATION(mod, "OSD_Exception_ACCESS_VIOLATION", "None");
	cls_OSD_Exception_ACCESS_VIOLATION.def(py::init<>());
	cls_OSD_Exception_ACCESS_VIOLATION.def(py::init<const Standard_CString>(), py::arg("theMessage"));
	cls_OSD_Exception_ACCESS_VIOLATION.def_static("Raise_", (void (*)(const Standard_CString)) &OSD_Exception_ACCESS_VIOLATION::Raise, "None", py::arg("theMessage"));
	cls_OSD_Exception_ACCESS_VIOLATION.def_static("Raise_", (void (*)(Standard_SStream &)) &OSD_Exception_ACCESS_VIOLATION::Raise, "None", py::arg("theMessage"));
	cls_OSD_Exception_ACCESS_VIOLATION.def_static("NewInstance_", (opencascade::handle<OSD_Exception_ACCESS_VIOLATION> (*)(const Standard_CString)) &OSD_Exception_ACCESS_VIOLATION::NewInstance, "None", py::arg("theMessage"));
	cls_OSD_Exception_ACCESS_VIOLATION.def_static("get_type_name_", (const char * (*)()) &OSD_Exception_ACCESS_VIOLATION::get_type_name, "None");
	cls_OSD_Exception_ACCESS_VIOLATION.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &OSD_Exception_ACCESS_VIOLATION::get_type_descriptor, "None");
	cls_OSD_Exception_ACCESS_VIOLATION.def("DynamicType", (const opencascade::handle<Standard_Type> & (OSD_Exception_ACCESS_VIOLATION::*)() const ) &OSD_Exception_ACCESS_VIOLATION::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\OSD_Exception_ARRAY_BOUNDS_EXCEEDED.hxx
	py::class_<OSD_Exception_ARRAY_BOUNDS_EXCEEDED, opencascade::handle<OSD_Exception_ARRAY_BOUNDS_EXCEEDED>, OSD_Exception> cls_OSD_Exception_ARRAY_BOUNDS_EXCEEDED(mod, "OSD_Exception_ARRAY_BOUNDS_EXCEEDED", "None");
	cls_OSD_Exception_ARRAY_BOUNDS_EXCEEDED.def(py::init<>());
	cls_OSD_Exception_ARRAY_BOUNDS_EXCEEDED.def(py::init<const Standard_CString>(), py::arg("theMessage"));
	cls_OSD_Exception_ARRAY_BOUNDS_EXCEEDED.def_static("Raise_", (void (*)(const Standard_CString)) &OSD_Exception_ARRAY_BOUNDS_EXCEEDED::Raise, "None", py::arg("theMessage"));
	cls_OSD_Exception_ARRAY_BOUNDS_EXCEEDED.def_static("Raise_", (void (*)(Standard_SStream &)) &OSD_Exception_ARRAY_BOUNDS_EXCEEDED::Raise, "None", py::arg("theMessage"));
	cls_OSD_Exception_ARRAY_BOUNDS_EXCEEDED.def_static("NewInstance_", (opencascade::handle<OSD_Exception_ARRAY_BOUNDS_EXCEEDED> (*)(const Standard_CString)) &OSD_Exception_ARRAY_BOUNDS_EXCEEDED::NewInstance, "None", py::arg("theMessage"));
	cls_OSD_Exception_ARRAY_BOUNDS_EXCEEDED.def_static("get_type_name_", (const char * (*)()) &OSD_Exception_ARRAY_BOUNDS_EXCEEDED::get_type_name, "None");
	cls_OSD_Exception_ARRAY_BOUNDS_EXCEEDED.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &OSD_Exception_ARRAY_BOUNDS_EXCEEDED::get_type_descriptor, "None");
	cls_OSD_Exception_ARRAY_BOUNDS_EXCEEDED.def("DynamicType", (const opencascade::handle<Standard_Type> & (OSD_Exception_ARRAY_BOUNDS_EXCEEDED::*)() const ) &OSD_Exception_ARRAY_BOUNDS_EXCEEDED::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\OSD_Exception_CTRL_BREAK.hxx
	py::class_<OSD_Exception_CTRL_BREAK, opencascade::handle<OSD_Exception_CTRL_BREAK>, OSD_Exception> cls_OSD_Exception_CTRL_BREAK(mod, "OSD_Exception_CTRL_BREAK", "None");
	cls_OSD_Exception_CTRL_BREAK.def(py::init<>());
	cls_OSD_Exception_CTRL_BREAK.def(py::init<const Standard_CString>(), py::arg("theMessage"));
	cls_OSD_Exception_CTRL_BREAK.def_static("Raise_", (void (*)(const Standard_CString)) &OSD_Exception_CTRL_BREAK::Raise, "None", py::arg("theMessage"));
	cls_OSD_Exception_CTRL_BREAK.def_static("Raise_", (void (*)(Standard_SStream &)) &OSD_Exception_CTRL_BREAK::Raise, "None", py::arg("theMessage"));
	cls_OSD_Exception_CTRL_BREAK.def_static("NewInstance_", (opencascade::handle<OSD_Exception_CTRL_BREAK> (*)(const Standard_CString)) &OSD_Exception_CTRL_BREAK::NewInstance, "None", py::arg("theMessage"));
	cls_OSD_Exception_CTRL_BREAK.def_static("get_type_name_", (const char * (*)()) &OSD_Exception_CTRL_BREAK::get_type_name, "None");
	cls_OSD_Exception_CTRL_BREAK.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &OSD_Exception_CTRL_BREAK::get_type_descriptor, "None");
	cls_OSD_Exception_CTRL_BREAK.def("DynamicType", (const opencascade::handle<Standard_Type> & (OSD_Exception_CTRL_BREAK::*)() const ) &OSD_Exception_CTRL_BREAK::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\OSD_Exception_FLT_DENORMAL_OPERAND.hxx
	py::class_<OSD_Exception_FLT_DENORMAL_OPERAND, opencascade::handle<OSD_Exception_FLT_DENORMAL_OPERAND>, OSD_Exception> cls_OSD_Exception_FLT_DENORMAL_OPERAND(mod, "OSD_Exception_FLT_DENORMAL_OPERAND", "None");
	cls_OSD_Exception_FLT_DENORMAL_OPERAND.def(py::init<>());
	cls_OSD_Exception_FLT_DENORMAL_OPERAND.def(py::init<const Standard_CString>(), py::arg("theMessage"));
	cls_OSD_Exception_FLT_DENORMAL_OPERAND.def_static("Raise_", (void (*)(const Standard_CString)) &OSD_Exception_FLT_DENORMAL_OPERAND::Raise, "None", py::arg("theMessage"));
	cls_OSD_Exception_FLT_DENORMAL_OPERAND.def_static("Raise_", (void (*)(Standard_SStream &)) &OSD_Exception_FLT_DENORMAL_OPERAND::Raise, "None", py::arg("theMessage"));
	cls_OSD_Exception_FLT_DENORMAL_OPERAND.def_static("NewInstance_", (opencascade::handle<OSD_Exception_FLT_DENORMAL_OPERAND> (*)(const Standard_CString)) &OSD_Exception_FLT_DENORMAL_OPERAND::NewInstance, "None", py::arg("theMessage"));
	cls_OSD_Exception_FLT_DENORMAL_OPERAND.def_static("get_type_name_", (const char * (*)()) &OSD_Exception_FLT_DENORMAL_OPERAND::get_type_name, "None");
	cls_OSD_Exception_FLT_DENORMAL_OPERAND.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &OSD_Exception_FLT_DENORMAL_OPERAND::get_type_descriptor, "None");
	cls_OSD_Exception_FLT_DENORMAL_OPERAND.def("DynamicType", (const opencascade::handle<Standard_Type> & (OSD_Exception_FLT_DENORMAL_OPERAND::*)() const ) &OSD_Exception_FLT_DENORMAL_OPERAND::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\OSD_Exception_FLT_DIVIDE_BY_ZERO.hxx
	py::class_<OSD_Exception_FLT_DIVIDE_BY_ZERO, opencascade::handle<OSD_Exception_FLT_DIVIDE_BY_ZERO>, OSD_Exception> cls_OSD_Exception_FLT_DIVIDE_BY_ZERO(mod, "OSD_Exception_FLT_DIVIDE_BY_ZERO", "None");
	cls_OSD_Exception_FLT_DIVIDE_BY_ZERO.def(py::init<>());
	cls_OSD_Exception_FLT_DIVIDE_BY_ZERO.def(py::init<const Standard_CString>(), py::arg("theMessage"));
	cls_OSD_Exception_FLT_DIVIDE_BY_ZERO.def_static("Raise_", (void (*)(const Standard_CString)) &OSD_Exception_FLT_DIVIDE_BY_ZERO::Raise, "None", py::arg("theMessage"));
	cls_OSD_Exception_FLT_DIVIDE_BY_ZERO.def_static("Raise_", (void (*)(Standard_SStream &)) &OSD_Exception_FLT_DIVIDE_BY_ZERO::Raise, "None", py::arg("theMessage"));
	cls_OSD_Exception_FLT_DIVIDE_BY_ZERO.def_static("NewInstance_", (opencascade::handle<OSD_Exception_FLT_DIVIDE_BY_ZERO> (*)(const Standard_CString)) &OSD_Exception_FLT_DIVIDE_BY_ZERO::NewInstance, "None", py::arg("theMessage"));
	cls_OSD_Exception_FLT_DIVIDE_BY_ZERO.def_static("get_type_name_", (const char * (*)()) &OSD_Exception_FLT_DIVIDE_BY_ZERO::get_type_name, "None");
	cls_OSD_Exception_FLT_DIVIDE_BY_ZERO.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &OSD_Exception_FLT_DIVIDE_BY_ZERO::get_type_descriptor, "None");
	cls_OSD_Exception_FLT_DIVIDE_BY_ZERO.def("DynamicType", (const opencascade::handle<Standard_Type> & (OSD_Exception_FLT_DIVIDE_BY_ZERO::*)() const ) &OSD_Exception_FLT_DIVIDE_BY_ZERO::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\OSD_Exception_FLT_INEXACT_RESULT.hxx
	py::class_<OSD_Exception_FLT_INEXACT_RESULT, opencascade::handle<OSD_Exception_FLT_INEXACT_RESULT>, OSD_Exception> cls_OSD_Exception_FLT_INEXACT_RESULT(mod, "OSD_Exception_FLT_INEXACT_RESULT", "None");
	cls_OSD_Exception_FLT_INEXACT_RESULT.def(py::init<>());
	cls_OSD_Exception_FLT_INEXACT_RESULT.def(py::init<const Standard_CString>(), py::arg("theMessage"));
	cls_OSD_Exception_FLT_INEXACT_RESULT.def_static("Raise_", (void (*)(const Standard_CString)) &OSD_Exception_FLT_INEXACT_RESULT::Raise, "None", py::arg("theMessage"));
	cls_OSD_Exception_FLT_INEXACT_RESULT.def_static("Raise_", (void (*)(Standard_SStream &)) &OSD_Exception_FLT_INEXACT_RESULT::Raise, "None", py::arg("theMessage"));
	cls_OSD_Exception_FLT_INEXACT_RESULT.def_static("NewInstance_", (opencascade::handle<OSD_Exception_FLT_INEXACT_RESULT> (*)(const Standard_CString)) &OSD_Exception_FLT_INEXACT_RESULT::NewInstance, "None", py::arg("theMessage"));
	cls_OSD_Exception_FLT_INEXACT_RESULT.def_static("get_type_name_", (const char * (*)()) &OSD_Exception_FLT_INEXACT_RESULT::get_type_name, "None");
	cls_OSD_Exception_FLT_INEXACT_RESULT.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &OSD_Exception_FLT_INEXACT_RESULT::get_type_descriptor, "None");
	cls_OSD_Exception_FLT_INEXACT_RESULT.def("DynamicType", (const opencascade::handle<Standard_Type> & (OSD_Exception_FLT_INEXACT_RESULT::*)() const ) &OSD_Exception_FLT_INEXACT_RESULT::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\OSD_Exception_FLT_INVALID_OPERATION.hxx
	py::class_<OSD_Exception_FLT_INVALID_OPERATION, opencascade::handle<OSD_Exception_FLT_INVALID_OPERATION>, OSD_Exception> cls_OSD_Exception_FLT_INVALID_OPERATION(mod, "OSD_Exception_FLT_INVALID_OPERATION", "None");
	cls_OSD_Exception_FLT_INVALID_OPERATION.def(py::init<>());
	cls_OSD_Exception_FLT_INVALID_OPERATION.def(py::init<const Standard_CString>(), py::arg("theMessage"));
	cls_OSD_Exception_FLT_INVALID_OPERATION.def_static("Raise_", (void (*)(const Standard_CString)) &OSD_Exception_FLT_INVALID_OPERATION::Raise, "None", py::arg("theMessage"));
	cls_OSD_Exception_FLT_INVALID_OPERATION.def_static("Raise_", (void (*)(Standard_SStream &)) &OSD_Exception_FLT_INVALID_OPERATION::Raise, "None", py::arg("theMessage"));
	cls_OSD_Exception_FLT_INVALID_OPERATION.def_static("NewInstance_", (opencascade::handle<OSD_Exception_FLT_INVALID_OPERATION> (*)(const Standard_CString)) &OSD_Exception_FLT_INVALID_OPERATION::NewInstance, "None", py::arg("theMessage"));
	cls_OSD_Exception_FLT_INVALID_OPERATION.def_static("get_type_name_", (const char * (*)()) &OSD_Exception_FLT_INVALID_OPERATION::get_type_name, "None");
	cls_OSD_Exception_FLT_INVALID_OPERATION.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &OSD_Exception_FLT_INVALID_OPERATION::get_type_descriptor, "None");
	cls_OSD_Exception_FLT_INVALID_OPERATION.def("DynamicType", (const opencascade::handle<Standard_Type> & (OSD_Exception_FLT_INVALID_OPERATION::*)() const ) &OSD_Exception_FLT_INVALID_OPERATION::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\OSD_Exception_FLT_OVERFLOW.hxx
	py::class_<OSD_Exception_FLT_OVERFLOW, opencascade::handle<OSD_Exception_FLT_OVERFLOW>, OSD_Exception> cls_OSD_Exception_FLT_OVERFLOW(mod, "OSD_Exception_FLT_OVERFLOW", "None");
	cls_OSD_Exception_FLT_OVERFLOW.def(py::init<>());
	cls_OSD_Exception_FLT_OVERFLOW.def(py::init<const Standard_CString>(), py::arg("theMessage"));
	cls_OSD_Exception_FLT_OVERFLOW.def_static("Raise_", (void (*)(const Standard_CString)) &OSD_Exception_FLT_OVERFLOW::Raise, "None", py::arg("theMessage"));
	cls_OSD_Exception_FLT_OVERFLOW.def_static("Raise_", (void (*)(Standard_SStream &)) &OSD_Exception_FLT_OVERFLOW::Raise, "None", py::arg("theMessage"));
	cls_OSD_Exception_FLT_OVERFLOW.def_static("NewInstance_", (opencascade::handle<OSD_Exception_FLT_OVERFLOW> (*)(const Standard_CString)) &OSD_Exception_FLT_OVERFLOW::NewInstance, "None", py::arg("theMessage"));
	cls_OSD_Exception_FLT_OVERFLOW.def_static("get_type_name_", (const char * (*)()) &OSD_Exception_FLT_OVERFLOW::get_type_name, "None");
	cls_OSD_Exception_FLT_OVERFLOW.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &OSD_Exception_FLT_OVERFLOW::get_type_descriptor, "None");
	cls_OSD_Exception_FLT_OVERFLOW.def("DynamicType", (const opencascade::handle<Standard_Type> & (OSD_Exception_FLT_OVERFLOW::*)() const ) &OSD_Exception_FLT_OVERFLOW::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\OSD_Exception_FLT_STACK_CHECK.hxx
	py::class_<OSD_Exception_FLT_STACK_CHECK, opencascade::handle<OSD_Exception_FLT_STACK_CHECK>, OSD_Exception> cls_OSD_Exception_FLT_STACK_CHECK(mod, "OSD_Exception_FLT_STACK_CHECK", "None");
	cls_OSD_Exception_FLT_STACK_CHECK.def(py::init<>());
	cls_OSD_Exception_FLT_STACK_CHECK.def(py::init<const Standard_CString>(), py::arg("theMessage"));
	cls_OSD_Exception_FLT_STACK_CHECK.def_static("Raise_", (void (*)(const Standard_CString)) &OSD_Exception_FLT_STACK_CHECK::Raise, "None", py::arg("theMessage"));
	cls_OSD_Exception_FLT_STACK_CHECK.def_static("Raise_", (void (*)(Standard_SStream &)) &OSD_Exception_FLT_STACK_CHECK::Raise, "None", py::arg("theMessage"));
	cls_OSD_Exception_FLT_STACK_CHECK.def_static("NewInstance_", (opencascade::handle<OSD_Exception_FLT_STACK_CHECK> (*)(const Standard_CString)) &OSD_Exception_FLT_STACK_CHECK::NewInstance, "None", py::arg("theMessage"));
	cls_OSD_Exception_FLT_STACK_CHECK.def_static("get_type_name_", (const char * (*)()) &OSD_Exception_FLT_STACK_CHECK::get_type_name, "None");
	cls_OSD_Exception_FLT_STACK_CHECK.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &OSD_Exception_FLT_STACK_CHECK::get_type_descriptor, "None");
	cls_OSD_Exception_FLT_STACK_CHECK.def("DynamicType", (const opencascade::handle<Standard_Type> & (OSD_Exception_FLT_STACK_CHECK::*)() const ) &OSD_Exception_FLT_STACK_CHECK::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\OSD_Exception_FLT_UNDERFLOW.hxx
	py::class_<OSD_Exception_FLT_UNDERFLOW, opencascade::handle<OSD_Exception_FLT_UNDERFLOW>, OSD_Exception> cls_OSD_Exception_FLT_UNDERFLOW(mod, "OSD_Exception_FLT_UNDERFLOW", "None");
	cls_OSD_Exception_FLT_UNDERFLOW.def(py::init<>());
	cls_OSD_Exception_FLT_UNDERFLOW.def(py::init<const Standard_CString>(), py::arg("theMessage"));
	cls_OSD_Exception_FLT_UNDERFLOW.def_static("Raise_", (void (*)(const Standard_CString)) &OSD_Exception_FLT_UNDERFLOW::Raise, "None", py::arg("theMessage"));
	cls_OSD_Exception_FLT_UNDERFLOW.def_static("Raise_", (void (*)(Standard_SStream &)) &OSD_Exception_FLT_UNDERFLOW::Raise, "None", py::arg("theMessage"));
	cls_OSD_Exception_FLT_UNDERFLOW.def_static("NewInstance_", (opencascade::handle<OSD_Exception_FLT_UNDERFLOW> (*)(const Standard_CString)) &OSD_Exception_FLT_UNDERFLOW::NewInstance, "None", py::arg("theMessage"));
	cls_OSD_Exception_FLT_UNDERFLOW.def_static("get_type_name_", (const char * (*)()) &OSD_Exception_FLT_UNDERFLOW::get_type_name, "None");
	cls_OSD_Exception_FLT_UNDERFLOW.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &OSD_Exception_FLT_UNDERFLOW::get_type_descriptor, "None");
	cls_OSD_Exception_FLT_UNDERFLOW.def("DynamicType", (const opencascade::handle<Standard_Type> & (OSD_Exception_FLT_UNDERFLOW::*)() const ) &OSD_Exception_FLT_UNDERFLOW::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\OSD_Exception_ILLEGAL_INSTRUCTION.hxx
	py::class_<OSD_Exception_ILLEGAL_INSTRUCTION, opencascade::handle<OSD_Exception_ILLEGAL_INSTRUCTION>, OSD_Exception> cls_OSD_Exception_ILLEGAL_INSTRUCTION(mod, "OSD_Exception_ILLEGAL_INSTRUCTION", "None");
	cls_OSD_Exception_ILLEGAL_INSTRUCTION.def(py::init<>());
	cls_OSD_Exception_ILLEGAL_INSTRUCTION.def(py::init<const Standard_CString>(), py::arg("theMessage"));
	cls_OSD_Exception_ILLEGAL_INSTRUCTION.def_static("Raise_", (void (*)(const Standard_CString)) &OSD_Exception_ILLEGAL_INSTRUCTION::Raise, "None", py::arg("theMessage"));
	cls_OSD_Exception_ILLEGAL_INSTRUCTION.def_static("Raise_", (void (*)(Standard_SStream &)) &OSD_Exception_ILLEGAL_INSTRUCTION::Raise, "None", py::arg("theMessage"));
	cls_OSD_Exception_ILLEGAL_INSTRUCTION.def_static("NewInstance_", (opencascade::handle<OSD_Exception_ILLEGAL_INSTRUCTION> (*)(const Standard_CString)) &OSD_Exception_ILLEGAL_INSTRUCTION::NewInstance, "None", py::arg("theMessage"));
	cls_OSD_Exception_ILLEGAL_INSTRUCTION.def_static("get_type_name_", (const char * (*)()) &OSD_Exception_ILLEGAL_INSTRUCTION::get_type_name, "None");
	cls_OSD_Exception_ILLEGAL_INSTRUCTION.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &OSD_Exception_ILLEGAL_INSTRUCTION::get_type_descriptor, "None");
	cls_OSD_Exception_ILLEGAL_INSTRUCTION.def("DynamicType", (const opencascade::handle<Standard_Type> & (OSD_Exception_ILLEGAL_INSTRUCTION::*)() const ) &OSD_Exception_ILLEGAL_INSTRUCTION::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\OSD_Exception_INT_DIVIDE_BY_ZERO.hxx
	py::class_<OSD_Exception_INT_DIVIDE_BY_ZERO, opencascade::handle<OSD_Exception_INT_DIVIDE_BY_ZERO>, OSD_Exception> cls_OSD_Exception_INT_DIVIDE_BY_ZERO(mod, "OSD_Exception_INT_DIVIDE_BY_ZERO", "None");
	cls_OSD_Exception_INT_DIVIDE_BY_ZERO.def(py::init<>());
	cls_OSD_Exception_INT_DIVIDE_BY_ZERO.def(py::init<const Standard_CString>(), py::arg("theMessage"));
	cls_OSD_Exception_INT_DIVIDE_BY_ZERO.def_static("Raise_", (void (*)(const Standard_CString)) &OSD_Exception_INT_DIVIDE_BY_ZERO::Raise, "None", py::arg("theMessage"));
	cls_OSD_Exception_INT_DIVIDE_BY_ZERO.def_static("Raise_", (void (*)(Standard_SStream &)) &OSD_Exception_INT_DIVIDE_BY_ZERO::Raise, "None", py::arg("theMessage"));
	cls_OSD_Exception_INT_DIVIDE_BY_ZERO.def_static("NewInstance_", (opencascade::handle<OSD_Exception_INT_DIVIDE_BY_ZERO> (*)(const Standard_CString)) &OSD_Exception_INT_DIVIDE_BY_ZERO::NewInstance, "None", py::arg("theMessage"));
	cls_OSD_Exception_INT_DIVIDE_BY_ZERO.def_static("get_type_name_", (const char * (*)()) &OSD_Exception_INT_DIVIDE_BY_ZERO::get_type_name, "None");
	cls_OSD_Exception_INT_DIVIDE_BY_ZERO.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &OSD_Exception_INT_DIVIDE_BY_ZERO::get_type_descriptor, "None");
	cls_OSD_Exception_INT_DIVIDE_BY_ZERO.def("DynamicType", (const opencascade::handle<Standard_Type> & (OSD_Exception_INT_DIVIDE_BY_ZERO::*)() const ) &OSD_Exception_INT_DIVIDE_BY_ZERO::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\OSD_Exception_INT_OVERFLOW.hxx
	py::class_<OSD_Exception_INT_OVERFLOW, opencascade::handle<OSD_Exception_INT_OVERFLOW>, OSD_Exception> cls_OSD_Exception_INT_OVERFLOW(mod, "OSD_Exception_INT_OVERFLOW", "None");
	cls_OSD_Exception_INT_OVERFLOW.def(py::init<>());
	cls_OSD_Exception_INT_OVERFLOW.def(py::init<const Standard_CString>(), py::arg("theMessage"));
	cls_OSD_Exception_INT_OVERFLOW.def_static("Raise_", (void (*)(const Standard_CString)) &OSD_Exception_INT_OVERFLOW::Raise, "None", py::arg("theMessage"));
	cls_OSD_Exception_INT_OVERFLOW.def_static("Raise_", (void (*)(Standard_SStream &)) &OSD_Exception_INT_OVERFLOW::Raise, "None", py::arg("theMessage"));
	cls_OSD_Exception_INT_OVERFLOW.def_static("NewInstance_", (opencascade::handle<OSD_Exception_INT_OVERFLOW> (*)(const Standard_CString)) &OSD_Exception_INT_OVERFLOW::NewInstance, "None", py::arg("theMessage"));
	cls_OSD_Exception_INT_OVERFLOW.def_static("get_type_name_", (const char * (*)()) &OSD_Exception_INT_OVERFLOW::get_type_name, "None");
	cls_OSD_Exception_INT_OVERFLOW.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &OSD_Exception_INT_OVERFLOW::get_type_descriptor, "None");
	cls_OSD_Exception_INT_OVERFLOW.def("DynamicType", (const opencascade::handle<Standard_Type> & (OSD_Exception_INT_OVERFLOW::*)() const ) &OSD_Exception_INT_OVERFLOW::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\OSD_Exception_INVALID_DISPOSITION.hxx
	py::class_<OSD_Exception_INVALID_DISPOSITION, opencascade::handle<OSD_Exception_INVALID_DISPOSITION>, OSD_Exception> cls_OSD_Exception_INVALID_DISPOSITION(mod, "OSD_Exception_INVALID_DISPOSITION", "None");
	cls_OSD_Exception_INVALID_DISPOSITION.def(py::init<>());
	cls_OSD_Exception_INVALID_DISPOSITION.def(py::init<const Standard_CString>(), py::arg("theMessage"));
	cls_OSD_Exception_INVALID_DISPOSITION.def_static("Raise_", (void (*)(const Standard_CString)) &OSD_Exception_INVALID_DISPOSITION::Raise, "None", py::arg("theMessage"));
	cls_OSD_Exception_INVALID_DISPOSITION.def_static("Raise_", (void (*)(Standard_SStream &)) &OSD_Exception_INVALID_DISPOSITION::Raise, "None", py::arg("theMessage"));
	cls_OSD_Exception_INVALID_DISPOSITION.def_static("NewInstance_", (opencascade::handle<OSD_Exception_INVALID_DISPOSITION> (*)(const Standard_CString)) &OSD_Exception_INVALID_DISPOSITION::NewInstance, "None", py::arg("theMessage"));
	cls_OSD_Exception_INVALID_DISPOSITION.def_static("get_type_name_", (const char * (*)()) &OSD_Exception_INVALID_DISPOSITION::get_type_name, "None");
	cls_OSD_Exception_INVALID_DISPOSITION.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &OSD_Exception_INVALID_DISPOSITION::get_type_descriptor, "None");
	cls_OSD_Exception_INVALID_DISPOSITION.def("DynamicType", (const opencascade::handle<Standard_Type> & (OSD_Exception_INVALID_DISPOSITION::*)() const ) &OSD_Exception_INVALID_DISPOSITION::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\OSD_Exception_IN_PAGE_ERROR.hxx
	py::class_<OSD_Exception_IN_PAGE_ERROR, opencascade::handle<OSD_Exception_IN_PAGE_ERROR>, OSD_Exception> cls_OSD_Exception_IN_PAGE_ERROR(mod, "OSD_Exception_IN_PAGE_ERROR", "None");
	cls_OSD_Exception_IN_PAGE_ERROR.def(py::init<>());
	cls_OSD_Exception_IN_PAGE_ERROR.def(py::init<const Standard_CString>(), py::arg("theMessage"));
	cls_OSD_Exception_IN_PAGE_ERROR.def_static("Raise_", (void (*)(const Standard_CString)) &OSD_Exception_IN_PAGE_ERROR::Raise, "None", py::arg("theMessage"));
	cls_OSD_Exception_IN_PAGE_ERROR.def_static("Raise_", (void (*)(Standard_SStream &)) &OSD_Exception_IN_PAGE_ERROR::Raise, "None", py::arg("theMessage"));
	cls_OSD_Exception_IN_PAGE_ERROR.def_static("NewInstance_", (opencascade::handle<OSD_Exception_IN_PAGE_ERROR> (*)(const Standard_CString)) &OSD_Exception_IN_PAGE_ERROR::NewInstance, "None", py::arg("theMessage"));
	cls_OSD_Exception_IN_PAGE_ERROR.def_static("get_type_name_", (const char * (*)()) &OSD_Exception_IN_PAGE_ERROR::get_type_name, "None");
	cls_OSD_Exception_IN_PAGE_ERROR.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &OSD_Exception_IN_PAGE_ERROR::get_type_descriptor, "None");
	cls_OSD_Exception_IN_PAGE_ERROR.def("DynamicType", (const opencascade::handle<Standard_Type> & (OSD_Exception_IN_PAGE_ERROR::*)() const ) &OSD_Exception_IN_PAGE_ERROR::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\OSD_Exception_NONCONTINUABLE_EXCEPTION.hxx
	py::class_<OSD_Exception_NONCONTINUABLE_EXCEPTION, opencascade::handle<OSD_Exception_NONCONTINUABLE_EXCEPTION>, OSD_Exception> cls_OSD_Exception_NONCONTINUABLE_EXCEPTION(mod, "OSD_Exception_NONCONTINUABLE_EXCEPTION", "None");
	cls_OSD_Exception_NONCONTINUABLE_EXCEPTION.def(py::init<>());
	cls_OSD_Exception_NONCONTINUABLE_EXCEPTION.def(py::init<const Standard_CString>(), py::arg("theMessage"));
	cls_OSD_Exception_NONCONTINUABLE_EXCEPTION.def_static("Raise_", (void (*)(const Standard_CString)) &OSD_Exception_NONCONTINUABLE_EXCEPTION::Raise, "None", py::arg("theMessage"));
	cls_OSD_Exception_NONCONTINUABLE_EXCEPTION.def_static("Raise_", (void (*)(Standard_SStream &)) &OSD_Exception_NONCONTINUABLE_EXCEPTION::Raise, "None", py::arg("theMessage"));
	cls_OSD_Exception_NONCONTINUABLE_EXCEPTION.def_static("NewInstance_", (opencascade::handle<OSD_Exception_NONCONTINUABLE_EXCEPTION> (*)(const Standard_CString)) &OSD_Exception_NONCONTINUABLE_EXCEPTION::NewInstance, "None", py::arg("theMessage"));
	cls_OSD_Exception_NONCONTINUABLE_EXCEPTION.def_static("get_type_name_", (const char * (*)()) &OSD_Exception_NONCONTINUABLE_EXCEPTION::get_type_name, "None");
	cls_OSD_Exception_NONCONTINUABLE_EXCEPTION.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &OSD_Exception_NONCONTINUABLE_EXCEPTION::get_type_descriptor, "None");
	cls_OSD_Exception_NONCONTINUABLE_EXCEPTION.def("DynamicType", (const opencascade::handle<Standard_Type> & (OSD_Exception_NONCONTINUABLE_EXCEPTION::*)() const ) &OSD_Exception_NONCONTINUABLE_EXCEPTION::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\OSD_Exception_PRIV_INSTRUCTION.hxx
	py::class_<OSD_Exception_PRIV_INSTRUCTION, opencascade::handle<OSD_Exception_PRIV_INSTRUCTION>, OSD_Exception> cls_OSD_Exception_PRIV_INSTRUCTION(mod, "OSD_Exception_PRIV_INSTRUCTION", "None");
	cls_OSD_Exception_PRIV_INSTRUCTION.def(py::init<>());
	cls_OSD_Exception_PRIV_INSTRUCTION.def(py::init<const Standard_CString>(), py::arg("theMessage"));
	cls_OSD_Exception_PRIV_INSTRUCTION.def_static("Raise_", (void (*)(const Standard_CString)) &OSD_Exception_PRIV_INSTRUCTION::Raise, "None", py::arg("theMessage"));
	cls_OSD_Exception_PRIV_INSTRUCTION.def_static("Raise_", (void (*)(Standard_SStream &)) &OSD_Exception_PRIV_INSTRUCTION::Raise, "None", py::arg("theMessage"));
	cls_OSD_Exception_PRIV_INSTRUCTION.def_static("NewInstance_", (opencascade::handle<OSD_Exception_PRIV_INSTRUCTION> (*)(const Standard_CString)) &OSD_Exception_PRIV_INSTRUCTION::NewInstance, "None", py::arg("theMessage"));
	cls_OSD_Exception_PRIV_INSTRUCTION.def_static("get_type_name_", (const char * (*)()) &OSD_Exception_PRIV_INSTRUCTION::get_type_name, "None");
	cls_OSD_Exception_PRIV_INSTRUCTION.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &OSD_Exception_PRIV_INSTRUCTION::get_type_descriptor, "None");
	cls_OSD_Exception_PRIV_INSTRUCTION.def("DynamicType", (const opencascade::handle<Standard_Type> & (OSD_Exception_PRIV_INSTRUCTION::*)() const ) &OSD_Exception_PRIV_INSTRUCTION::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\OSD_Exception_STACK_OVERFLOW.hxx
	py::class_<OSD_Exception_STACK_OVERFLOW, opencascade::handle<OSD_Exception_STACK_OVERFLOW>, OSD_Exception> cls_OSD_Exception_STACK_OVERFLOW(mod, "OSD_Exception_STACK_OVERFLOW", "None");
	cls_OSD_Exception_STACK_OVERFLOW.def(py::init<>());
	cls_OSD_Exception_STACK_OVERFLOW.def(py::init<const Standard_CString>(), py::arg("theMessage"));
	cls_OSD_Exception_STACK_OVERFLOW.def_static("Raise_", (void (*)(const Standard_CString)) &OSD_Exception_STACK_OVERFLOW::Raise, "None", py::arg("theMessage"));
	cls_OSD_Exception_STACK_OVERFLOW.def_static("Raise_", (void (*)(Standard_SStream &)) &OSD_Exception_STACK_OVERFLOW::Raise, "None", py::arg("theMessage"));
	cls_OSD_Exception_STACK_OVERFLOW.def_static("NewInstance_", (opencascade::handle<OSD_Exception_STACK_OVERFLOW> (*)(const Standard_CString)) &OSD_Exception_STACK_OVERFLOW::NewInstance, "None", py::arg("theMessage"));
	cls_OSD_Exception_STACK_OVERFLOW.def_static("get_type_name_", (const char * (*)()) &OSD_Exception_STACK_OVERFLOW::get_type_name, "None");
	cls_OSD_Exception_STACK_OVERFLOW.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &OSD_Exception_STACK_OVERFLOW::get_type_descriptor, "None");
	cls_OSD_Exception_STACK_OVERFLOW.def("DynamicType", (const opencascade::handle<Standard_Type> & (OSD_Exception_STACK_OVERFLOW::*)() const ) &OSD_Exception_STACK_OVERFLOW::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\OSD_Exception_STATUS_NO_MEMORY.hxx
	py::class_<OSD_Exception_STATUS_NO_MEMORY, opencascade::handle<OSD_Exception_STATUS_NO_MEMORY>, OSD_Exception> cls_OSD_Exception_STATUS_NO_MEMORY(mod, "OSD_Exception_STATUS_NO_MEMORY", "None");
	cls_OSD_Exception_STATUS_NO_MEMORY.def(py::init<>());
	cls_OSD_Exception_STATUS_NO_MEMORY.def(py::init<const Standard_CString>(), py::arg("theMessage"));
	cls_OSD_Exception_STATUS_NO_MEMORY.def_static("Raise_", (void (*)(const Standard_CString)) &OSD_Exception_STATUS_NO_MEMORY::Raise, "None", py::arg("theMessage"));
	cls_OSD_Exception_STATUS_NO_MEMORY.def_static("Raise_", (void (*)(Standard_SStream &)) &OSD_Exception_STATUS_NO_MEMORY::Raise, "None", py::arg("theMessage"));
	cls_OSD_Exception_STATUS_NO_MEMORY.def_static("NewInstance_", (opencascade::handle<OSD_Exception_STATUS_NO_MEMORY> (*)(const Standard_CString)) &OSD_Exception_STATUS_NO_MEMORY::NewInstance, "None", py::arg("theMessage"));
	cls_OSD_Exception_STATUS_NO_MEMORY.def_static("get_type_name_", (const char * (*)()) &OSD_Exception_STATUS_NO_MEMORY::get_type_name, "None");
	cls_OSD_Exception_STATUS_NO_MEMORY.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &OSD_Exception_STATUS_NO_MEMORY::get_type_descriptor, "None");
	cls_OSD_Exception_STATUS_NO_MEMORY.def("DynamicType", (const opencascade::handle<Standard_Type> & (OSD_Exception_STATUS_NO_MEMORY::*)() const ) &OSD_Exception_STATUS_NO_MEMORY::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\OSD_MAllocHook.hxx
	py::class_<OSD_MAllocHook, std::unique_ptr<OSD_MAllocHook, Deleter<OSD_MAllocHook>>> cls_OSD_MAllocHook(mod, "OSD_MAllocHook", "This class provides the possibility to set callback for memory allocation/deallocation. On MS Windows, it works only in Debug builds. It relies on the debug CRT function _CrtSetAllocHook (see MSDN for help).");
	cls_OSD_MAllocHook.def(py::init<>());
	cls_OSD_MAllocHook.def_static("SetCallback_", (void (*)(OSD_MAllocHook::Callback *)) &OSD_MAllocHook::SetCallback, "Set handler of allocation/deallocation events", py::arg("theCB"));
	cls_OSD_MAllocHook.def_static("GetCallback_", (OSD_MAllocHook::Callback * (*)()) &OSD_MAllocHook::GetCallback, "Get current handler of allocation/deallocation events");
	cls_OSD_MAllocHook.def_static("GetLogFileHandler_", (OSD_MAllocHook::LogFileHandler * (*)()) &OSD_MAllocHook::GetLogFileHandler, "Get static instance of LogFileHandler handler");
	cls_OSD_MAllocHook.def_static("GetCollectBySize_", (OSD_MAllocHook::CollectBySize * (*)()) &OSD_MAllocHook::GetCollectBySize, "Get static instance of CollectBySize handler");

	// C:\Miniconda\envs\occt\Library\include\opencascade\OSD_MemInfo.hxx
	py::class_<OSD_MemInfo, std::unique_ptr<OSD_MemInfo, Deleter<OSD_MemInfo>>> cls_OSD_MemInfo(mod, "OSD_MemInfo", "This class provide information about memory utilized by current process. This information includes: - Private Memory - synthetic value that tries to filter out the memory usage only by the process itself (allocated for data and stack), excluding dynamic libraries. These pages may be in RAM or in SWAP. - Virtual Memory - amount of reserved and committed memory in the user-mode portion of the virtual address space. Notice that this counter includes reserved memory (not yet in used) and shared between processes memory (libraries). - Working Set - set of memory pages in the virtual address space of the process that are currently resident in physical memory (RAM). These pages are available for an application to use without triggering a page fault. - Pagefile Usage - space allocated for the pagefile, in bytes. Those pages may or may not be in memory (RAM) thus this counter couldn't be used to estimate how many active pages doesn't present in RAM.");
	cls_OSD_MemInfo.def(py::init<>());
	cls_OSD_MemInfo.def("Update", (void (OSD_MemInfo::*)()) &OSD_MemInfo::Update, "Update counters");
	cls_OSD_MemInfo.def("ToString", (TCollection_AsciiString (OSD_MemInfo::*)() const ) &OSD_MemInfo::ToString, "Return the string representation for all available counter.");
	cls_OSD_MemInfo.def("Value", (Standard_Size (OSD_MemInfo::*)(const OSD_MemInfo::Counter) const ) &OSD_MemInfo::Value, "Return value or specified counter in bytes. Notice that NOT all counters are available on various systems. Standard_Size(-1) means invalid (unavailable) value.", py::arg("theCounter"));
	cls_OSD_MemInfo.def("ValueMiB", (Standard_Size (OSD_MemInfo::*)(const OSD_MemInfo::Counter) const ) &OSD_MemInfo::ValueMiB, "Return value or specified counter in MiB. Notice that NOT all counters are available on various systems. Standard_Size(-1) means invalid (unavailable) value.", py::arg("theCounter"));
	cls_OSD_MemInfo.def_static("PrintInfo_", (TCollection_AsciiString (*)()) &OSD_MemInfo::PrintInfo, "Return the string representation for all available counter.");
	// C:\Miniconda\envs\occt\Library\include\opencascade\OSD_MemInfo.hxx
	py::enum_<OSD_MemInfo::Counter>(cls_OSD_MemInfo, "Counter", "None")
		.value("MemPrivate", OSD_MemInfo::Counter::MemPrivate)
		.value("MemVirtual", OSD_MemInfo::Counter::MemVirtual)
		.value("MemWorkingSet", OSD_MemInfo::Counter::MemWorkingSet)
		.value("MemWorkingSetPeak", OSD_MemInfo::Counter::MemWorkingSetPeak)
		.value("MemSwapUsage", OSD_MemInfo::Counter::MemSwapUsage)
		.value("MemSwapUsagePeak", OSD_MemInfo::Counter::MemSwapUsagePeak)
		.value("MemHeapUsage", OSD_MemInfo::Counter::MemHeapUsage)
		.value("MemCounter_NB", OSD_MemInfo::Counter::MemCounter_NB)
		.export_values();

	// C:\Miniconda\envs\occt\Library\include\opencascade\OSD_PerfMeter.hxx
	py::class_<OSD_PerfMeter, std::unique_ptr<OSD_PerfMeter, Deleter<OSD_PerfMeter>>> cls_OSD_PerfMeter(mod, "OSD_PerfMeter", "This class enables measuring the CPU time between two points of code execution, regardless of the scope of these points of code. A meter is identified by its name (string). So multiple objects in various places of user code may point to the same meter. The results will be printed on stdout upon finish of the program. For details see OSD_PerfMeter.h");
	cls_OSD_PerfMeter.def(py::init<>());
	cls_OSD_PerfMeter.def(py::init<const char *>(), py::arg("theMeter"));
	cls_OSD_PerfMeter.def(py::init<const char *, const bool>(), py::arg("theMeter"), py::arg("theToAutoStart"));
	cls_OSD_PerfMeter.def("Init", (void (OSD_PerfMeter::*)(const char *)) &OSD_PerfMeter::Init, "Prepares the named meter", py::arg("theMeter"));
	cls_OSD_PerfMeter.def("Start", (void (OSD_PerfMeter::*)() const ) &OSD_PerfMeter::Start, "Starts the meter");
	cls_OSD_PerfMeter.def("Stop", (void (OSD_PerfMeter::*)() const ) &OSD_PerfMeter::Stop, "Stops the meter");
	cls_OSD_PerfMeter.def("Tick", (void (OSD_PerfMeter::*)() const ) &OSD_PerfMeter::Tick, "Increments the counter w/o time measurement");
	cls_OSD_PerfMeter.def("Flush", (void (OSD_PerfMeter::*)() const ) &OSD_PerfMeter::Flush, "Outputs the meter data and resets it to initial state");

	// C:\Miniconda\envs\occt\Library\include\opencascade\OSD_Signal.hxx
	py::class_<OSD_Signal, opencascade::handle<OSD_Signal>, Standard_Failure> cls_OSD_Signal(mod, "OSD_Signal", "None");
	cls_OSD_Signal.def(py::init<>());
	cls_OSD_Signal.def(py::init<const Standard_CString>(), py::arg("theMessage"));
	cls_OSD_Signal.def_static("Raise_", (void (*)(const Standard_CString)) &OSD_Signal::Raise, "None", py::arg("theMessage"));
	cls_OSD_Signal.def_static("Raise_", (void (*)(Standard_SStream &)) &OSD_Signal::Raise, "None", py::arg("theMessage"));
	cls_OSD_Signal.def_static("NewInstance_", (opencascade::handle<OSD_Signal> (*)(const Standard_CString)) &OSD_Signal::NewInstance, "None", py::arg("theMessage"));
	cls_OSD_Signal.def_static("get_type_name_", (const char * (*)()) &OSD_Signal::get_type_name, "None");
	cls_OSD_Signal.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &OSD_Signal::get_type_descriptor, "None");
	cls_OSD_Signal.def("DynamicType", (const opencascade::handle<Standard_Type> & (OSD_Signal::*)() const ) &OSD_Signal::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\OSD_SIGBUS.hxx
	py::class_<OSD_SIGBUS, opencascade::handle<OSD_SIGBUS>, OSD_Signal> cls_OSD_SIGBUS(mod, "OSD_SIGBUS", "None");
	cls_OSD_SIGBUS.def(py::init<>());
	cls_OSD_SIGBUS.def(py::init<const Standard_CString>(), py::arg("theMessage"));
	cls_OSD_SIGBUS.def_static("Raise_", (void (*)(const Standard_CString)) &OSD_SIGBUS::Raise, "None", py::arg("theMessage"));
	cls_OSD_SIGBUS.def_static("Raise_", (void (*)(Standard_SStream &)) &OSD_SIGBUS::Raise, "None", py::arg("theMessage"));
	cls_OSD_SIGBUS.def_static("NewInstance_", (opencascade::handle<OSD_SIGBUS> (*)(const Standard_CString)) &OSD_SIGBUS::NewInstance, "None", py::arg("theMessage"));
	cls_OSD_SIGBUS.def_static("get_type_name_", (const char * (*)()) &OSD_SIGBUS::get_type_name, "None");
	cls_OSD_SIGBUS.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &OSD_SIGBUS::get_type_descriptor, "None");
	cls_OSD_SIGBUS.def("DynamicType", (const opencascade::handle<Standard_Type> & (OSD_SIGBUS::*)() const ) &OSD_SIGBUS::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\OSD_SIGHUP.hxx
	py::class_<OSD_SIGHUP, opencascade::handle<OSD_SIGHUP>, OSD_Signal> cls_OSD_SIGHUP(mod, "OSD_SIGHUP", "None");
	cls_OSD_SIGHUP.def(py::init<>());
	cls_OSD_SIGHUP.def(py::init<const Standard_CString>(), py::arg("theMessage"));
	cls_OSD_SIGHUP.def_static("Raise_", (void (*)(const Standard_CString)) &OSD_SIGHUP::Raise, "None", py::arg("theMessage"));
	cls_OSD_SIGHUP.def_static("Raise_", (void (*)(Standard_SStream &)) &OSD_SIGHUP::Raise, "None", py::arg("theMessage"));
	cls_OSD_SIGHUP.def_static("NewInstance_", (opencascade::handle<OSD_SIGHUP> (*)(const Standard_CString)) &OSD_SIGHUP::NewInstance, "None", py::arg("theMessage"));
	cls_OSD_SIGHUP.def_static("get_type_name_", (const char * (*)()) &OSD_SIGHUP::get_type_name, "None");
	cls_OSD_SIGHUP.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &OSD_SIGHUP::get_type_descriptor, "None");
	cls_OSD_SIGHUP.def("DynamicType", (const opencascade::handle<Standard_Type> & (OSD_SIGHUP::*)() const ) &OSD_SIGHUP::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\OSD_SIGILL.hxx
	py::class_<OSD_SIGILL, opencascade::handle<OSD_SIGILL>, OSD_Signal> cls_OSD_SIGILL(mod, "OSD_SIGILL", "None");
	cls_OSD_SIGILL.def(py::init<>());
	cls_OSD_SIGILL.def(py::init<const Standard_CString>(), py::arg("theMessage"));
	cls_OSD_SIGILL.def_static("Raise_", (void (*)(const Standard_CString)) &OSD_SIGILL::Raise, "None", py::arg("theMessage"));
	cls_OSD_SIGILL.def_static("Raise_", (void (*)(Standard_SStream &)) &OSD_SIGILL::Raise, "None", py::arg("theMessage"));
	cls_OSD_SIGILL.def_static("NewInstance_", (opencascade::handle<OSD_SIGILL> (*)(const Standard_CString)) &OSD_SIGILL::NewInstance, "None", py::arg("theMessage"));
	cls_OSD_SIGILL.def_static("get_type_name_", (const char * (*)()) &OSD_SIGILL::get_type_name, "None");
	cls_OSD_SIGILL.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &OSD_SIGILL::get_type_descriptor, "None");
	cls_OSD_SIGILL.def("DynamicType", (const opencascade::handle<Standard_Type> & (OSD_SIGILL::*)() const ) &OSD_SIGILL::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\OSD_SIGINT.hxx
	py::class_<OSD_SIGINT, opencascade::handle<OSD_SIGINT>, OSD_Signal> cls_OSD_SIGINT(mod, "OSD_SIGINT", "None");
	cls_OSD_SIGINT.def(py::init<>());
	cls_OSD_SIGINT.def(py::init<const Standard_CString>(), py::arg("theMessage"));
	cls_OSD_SIGINT.def_static("Raise_", (void (*)(const Standard_CString)) &OSD_SIGINT::Raise, "None", py::arg("theMessage"));
	cls_OSD_SIGINT.def_static("Raise_", (void (*)(Standard_SStream &)) &OSD_SIGINT::Raise, "None", py::arg("theMessage"));
	cls_OSD_SIGINT.def_static("NewInstance_", (opencascade::handle<OSD_SIGINT> (*)(const Standard_CString)) &OSD_SIGINT::NewInstance, "None", py::arg("theMessage"));
	cls_OSD_SIGINT.def_static("get_type_name_", (const char * (*)()) &OSD_SIGINT::get_type_name, "None");
	cls_OSD_SIGINT.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &OSD_SIGINT::get_type_descriptor, "None");
	cls_OSD_SIGINT.def("DynamicType", (const opencascade::handle<Standard_Type> & (OSD_SIGINT::*)() const ) &OSD_SIGINT::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\OSD_SIGKILL.hxx
	py::class_<OSD_SIGKILL, opencascade::handle<OSD_SIGKILL>, OSD_Signal> cls_OSD_SIGKILL(mod, "OSD_SIGKILL", "None");
	cls_OSD_SIGKILL.def(py::init<>());
	cls_OSD_SIGKILL.def(py::init<const Standard_CString>(), py::arg("theMessage"));
	cls_OSD_SIGKILL.def_static("Raise_", (void (*)(const Standard_CString)) &OSD_SIGKILL::Raise, "None", py::arg("theMessage"));
	cls_OSD_SIGKILL.def_static("Raise_", (void (*)(Standard_SStream &)) &OSD_SIGKILL::Raise, "None", py::arg("theMessage"));
	cls_OSD_SIGKILL.def_static("NewInstance_", (opencascade::handle<OSD_SIGKILL> (*)(const Standard_CString)) &OSD_SIGKILL::NewInstance, "None", py::arg("theMessage"));
	cls_OSD_SIGKILL.def_static("get_type_name_", (const char * (*)()) &OSD_SIGKILL::get_type_name, "None");
	cls_OSD_SIGKILL.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &OSD_SIGKILL::get_type_descriptor, "None");
	cls_OSD_SIGKILL.def("DynamicType", (const opencascade::handle<Standard_Type> & (OSD_SIGKILL::*)() const ) &OSD_SIGKILL::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\OSD_SIGQUIT.hxx
	py::class_<OSD_SIGQUIT, opencascade::handle<OSD_SIGQUIT>, OSD_Signal> cls_OSD_SIGQUIT(mod, "OSD_SIGQUIT", "None");
	cls_OSD_SIGQUIT.def(py::init<>());
	cls_OSD_SIGQUIT.def(py::init<const Standard_CString>(), py::arg("theMessage"));
	cls_OSD_SIGQUIT.def_static("Raise_", (void (*)(const Standard_CString)) &OSD_SIGQUIT::Raise, "None", py::arg("theMessage"));
	cls_OSD_SIGQUIT.def_static("Raise_", (void (*)(Standard_SStream &)) &OSD_SIGQUIT::Raise, "None", py::arg("theMessage"));
	cls_OSD_SIGQUIT.def_static("NewInstance_", (opencascade::handle<OSD_SIGQUIT> (*)(const Standard_CString)) &OSD_SIGQUIT::NewInstance, "None", py::arg("theMessage"));
	cls_OSD_SIGQUIT.def_static("get_type_name_", (const char * (*)()) &OSD_SIGQUIT::get_type_name, "None");
	cls_OSD_SIGQUIT.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &OSD_SIGQUIT::get_type_descriptor, "None");
	cls_OSD_SIGQUIT.def("DynamicType", (const opencascade::handle<Standard_Type> & (OSD_SIGQUIT::*)() const ) &OSD_SIGQUIT::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\OSD_SIGSEGV.hxx
	py::class_<OSD_SIGSEGV, opencascade::handle<OSD_SIGSEGV>, OSD_Signal> cls_OSD_SIGSEGV(mod, "OSD_SIGSEGV", "None");
	cls_OSD_SIGSEGV.def(py::init<>());
	cls_OSD_SIGSEGV.def(py::init<const Standard_CString>(), py::arg("theMessage"));
	cls_OSD_SIGSEGV.def_static("Raise_", (void (*)(const Standard_CString)) &OSD_SIGSEGV::Raise, "None", py::arg("theMessage"));
	cls_OSD_SIGSEGV.def_static("Raise_", (void (*)(Standard_SStream &)) &OSD_SIGSEGV::Raise, "None", py::arg("theMessage"));
	cls_OSD_SIGSEGV.def_static("NewInstance_", (opencascade::handle<OSD_SIGSEGV> (*)(const Standard_CString)) &OSD_SIGSEGV::NewInstance, "None", py::arg("theMessage"));
	cls_OSD_SIGSEGV.def_static("get_type_name_", (const char * (*)()) &OSD_SIGSEGV::get_type_name, "None");
	cls_OSD_SIGSEGV.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &OSD_SIGSEGV::get_type_descriptor, "None");
	cls_OSD_SIGSEGV.def("DynamicType", (const opencascade::handle<Standard_Type> & (OSD_SIGSEGV::*)() const ) &OSD_SIGSEGV::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\OSD_SIGSYS.hxx
	py::class_<OSD_SIGSYS, opencascade::handle<OSD_SIGSYS>, OSD_Signal> cls_OSD_SIGSYS(mod, "OSD_SIGSYS", "None");
	cls_OSD_SIGSYS.def(py::init<>());
	cls_OSD_SIGSYS.def(py::init<const Standard_CString>(), py::arg("theMessage"));
	cls_OSD_SIGSYS.def_static("Raise_", (void (*)(const Standard_CString)) &OSD_SIGSYS::Raise, "None", py::arg("theMessage"));
	cls_OSD_SIGSYS.def_static("Raise_", (void (*)(Standard_SStream &)) &OSD_SIGSYS::Raise, "None", py::arg("theMessage"));
	cls_OSD_SIGSYS.def_static("NewInstance_", (opencascade::handle<OSD_SIGSYS> (*)(const Standard_CString)) &OSD_SIGSYS::NewInstance, "None", py::arg("theMessage"));
	cls_OSD_SIGSYS.def_static("get_type_name_", (const char * (*)()) &OSD_SIGSYS::get_type_name, "None");
	cls_OSD_SIGSYS.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &OSD_SIGSYS::get_type_descriptor, "None");
	cls_OSD_SIGSYS.def("DynamicType", (const opencascade::handle<Standard_Type> & (OSD_SIGSYS::*)() const ) &OSD_SIGSYS::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\OSD_ThreadFunction.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\OSD_PThread.hxx
	other_mod = py::module::import("OCCT.Aspect");
	if (py::hasattr(other_mod, "HANDLE")) {
		mod.attr("OSD_PThread") = other_mod.attr("HANDLE");
	}

	// C:\Miniconda\envs\occt\Library\include\opencascade\OSD_Function.hxx
	other_mod = py::module::import("OCCT.AdvApp2Var");
	if (py::hasattr(other_mod, "U_fp")) {
		mod.attr("OSD_Function") = other_mod.attr("U_fp");
	}


}

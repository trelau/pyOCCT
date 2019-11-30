/*
This file is part of pyOCCT which provides Python bindings to the OpenCASCADE
geometry kernel.

Copyright (C) 2016-2018  Laughlin Research, LLC
Copyright (C) 2019 Trevor Laughlin and the pyOCCT contributors

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
#include <pyOCCT_Common.hxx>
#include <OSD_SysType.hxx>
#include <OSD_SignalMode.hxx>
#include <OSD_WhoAmI.hxx>
#include <OSD_FromWhere.hxx>
#include <OSD_KindFile.hxx>
#include <OSD_LockType.hxx>
#include <OSD_OpenMode.hxx>
#include <OSD_OEMType.hxx>
#include <OSD_LoadMode.hxx>
#include <OSD_SingleProtection.hxx>
#include <TCollection_ExtendedString.hxx>
#include <OSD_OpenFile.hxx>
#include <Standard.hxx>
#include <TCollection_AsciiString.hxx>
#include <Standard_TypeDef.hxx>
#include <OSD_Path.hxx>
#include <Standard_OStream.hxx>
#include <OSD_Chronometer.hxx>
#include <OSD_Timer.hxx>
#include <OSD_ThreadFunction.hxx>
#include <Aspect_Handle.hxx>
#include <OSD_PThread.hxx>
#include <OSD_Thread.hxx>
#include <Standard_ThreadId.hxx>
#include <Standard_Transient.hxx>
#include <Standard_Std.hxx>
#include <OSD_ThreadPool.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Type.hxx>
#include <Standard_Failure.hxx>
#include <Standard_Condition.hxx>
#include <NCollection_Array1.hxx>
#include <OSD_Parallel.hxx>
#include <OSD_Function.hxx>
#include <Standard_PCharacter.hxx>
#include <OSD.hxx>
#include <OSD_Error.hxx>
#include <OSD_Protection.hxx>
#include <Quantity_Date.hxx>
#include <OSD_FileNode.hxx>
#include <OSD_Directory.hxx>
#include <OSD_DirectoryIterator.hxx>
#include <OSD_Disk.hxx>
#include <OSD_Environment.hxx>
#include <OSD_Exception.hxx>
#include <Standard_SStream.hxx>
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
#include <NCollection_SparseArrayBase.hxx>
#include <OSD_File.hxx>
#include <OSD_FileIterator.hxx>
#include <OSD_Host.hxx>
#include <OSD_MAllocHook.hxx>
#include <Standard_Mutex.hxx>
#include <OSD_MemInfo.hxx>
#include <OSD_OSDError.hxx>
#include <OSD_PerfMeter.hxx>
#include <OSD_Process.hxx>
#include <OSD_SharedLibrary.hxx>
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

py::module::import("OCCT.TCollection");
py::module::import("OCCT.Standard");
py::module::import("OCCT.Aspect");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.Quantity");

// ENUM: OSD_SYSTYPE
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


// ENUM: OSD_SIGNALMODE
py::enum_<OSD_SignalMode>(mod, "OSD_SignalMode", "Mode of operation for OSD::SetSignal() function")
	.value("OSD_SignalMode_AsIs", OSD_SignalMode::OSD_SignalMode_AsIs)
	.value("OSD_SignalMode_Set", OSD_SignalMode::OSD_SignalMode_Set)
	.value("OSD_SignalMode_SetUnhandled", OSD_SignalMode::OSD_SignalMode_SetUnhandled)
	.value("OSD_SignalMode_Unset", OSD_SignalMode::OSD_SignalMode_Unset)
	.export_values();


// ENUM: OSD_WHOAMI
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


// ENUM: OSD_FROMWHERE
py::enum_<OSD_FromWhere>(mod, "OSD_FromWhere", "Used by OSD_File in the method Seek.")
	.value("OSD_FromBeginning", OSD_FromWhere::OSD_FromBeginning)
	.value("OSD_FromHere", OSD_FromWhere::OSD_FromHere)
	.value("OSD_FromEnd", OSD_FromWhere::OSD_FromEnd)
	.export_values();


// ENUM: OSD_KINDFILE
py::enum_<OSD_KindFile>(mod, "OSD_KindFile", "Specifies the type of files.")
	.value("OSD_FILE", OSD_KindFile::OSD_FILE)
	.value("OSD_DIRECTORY", OSD_KindFile::OSD_DIRECTORY)
	.value("OSD_LINK", OSD_KindFile::OSD_LINK)
	.value("OSD_SOCKET", OSD_KindFile::OSD_SOCKET)
	.value("OSD_UNKNOWN", OSD_KindFile::OSD_UNKNOWN)
	.export_values();


// ENUM: OSD_LOCKTYPE
py::enum_<OSD_LockType>(mod, "OSD_LockType", "locks for files. NoLock is the default value when opening a file.")
	.value("OSD_NoLock", OSD_LockType::OSD_NoLock)
	.value("OSD_ReadLock", OSD_LockType::OSD_ReadLock)
	.value("OSD_WriteLock", OSD_LockType::OSD_WriteLock)
	.value("OSD_ExclusiveLock", OSD_LockType::OSD_ExclusiveLock)
	.export_values();


// ENUM: OSD_OPENMODE
py::enum_<OSD_OpenMode>(mod, "OSD_OpenMode", "Specifies the file open mode.")
	.value("OSD_ReadOnly", OSD_OpenMode::OSD_ReadOnly)
	.value("OSD_WriteOnly", OSD_OpenMode::OSD_WriteOnly)
	.value("OSD_ReadWrite", OSD_OpenMode::OSD_ReadWrite)
	.export_values();


// ENUM: OSD_OEMTYPE
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


// ENUM: OSD_LOADMODE
py::enum_<OSD_LoadMode>(mod, "OSD_LoadMode", "This enumeration is used to load shareable libraries.")
	.value("OSD_RTLD_LAZY", OSD_LoadMode::OSD_RTLD_LAZY)
	.value("OSD_RTLD_NOW", OSD_LoadMode::OSD_RTLD_NOW)
	.export_values();


// ENUM: OSD_SINGLEPROTECTION
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


// FUNCTION: OSD_OPENSTREAM
mod.def("OSD_OpenStream", (bool (*) (::std::filebuf &, const TCollection_ExtendedString &, const std::ios_base::openmode)) &OSD_OpenStream, "Function opens the file buffer.", py::arg("theFileBuf"), py::arg("theName"), py::arg("theMode"));

// CLASS: OSD_PATH
py::class_<OSD_Path> cls_OSD_Path(mod, "OSD_Path", "None");

// Constructors
cls_OSD_Path.def(py::init<>());
cls_OSD_Path.def(py::init<const TCollection_AsciiString &>(), py::arg("aDependentName"));
cls_OSD_Path.def(py::init<const TCollection_AsciiString &, const OSD_SysType>(), py::arg("aDependentName"), py::arg("aSysType"));
cls_OSD_Path.def(py::init<const TCollection_AsciiString &, const TCollection_AsciiString &, const TCollection_AsciiString &, const TCollection_AsciiString &, const TCollection_AsciiString &, const TCollection_AsciiString &, const TCollection_AsciiString &>(), py::arg("aNode"), py::arg("aUsername"), py::arg("aPassword"), py::arg("aDisk"), py::arg("aTrek"), py::arg("aName"), py::arg("anExtension"));

// Methods
// cls_OSD_Path.def_static("operator new_", (void * (*)(size_t)) &OSD_Path::operator new, "None", py::arg("theSize"));
// cls_OSD_Path.def_static("operator delete_", (void (*)(void *)) &OSD_Path::operator delete, "None", py::arg("theAddress"));
// cls_OSD_Path.def_static("operator new[]_", (void * (*)(size_t)) &OSD_Path::operator new[], "None", py::arg("theSize"));
// cls_OSD_Path.def_static("operator delete[]_", (void (*)(void *)) &OSD_Path::operator delete[], "None", py::arg("theAddress"));
// cls_OSD_Path.def_static("operator new_", (void * (*)(size_t, void *)) &OSD_Path::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_OSD_Path.def_static("operator delete_", (void (*)(void *, void *)) &OSD_Path::operator delete, "None", py::arg(""), py::arg(""));
cls_OSD_Path.def("Values", (void (OSD_Path::*)(TCollection_AsciiString &, TCollection_AsciiString &, TCollection_AsciiString &, TCollection_AsciiString &, TCollection_AsciiString &, TCollection_AsciiString &, TCollection_AsciiString &) const) &OSD_Path::Values, "Gets each component of a path.", py::arg("aNode"), py::arg("aUsername"), py::arg("aPassword"), py::arg("aDisk"), py::arg("aTrek"), py::arg("aName"), py::arg("anExtension"));
cls_OSD_Path.def("SetValues", (void (OSD_Path::*)(const TCollection_AsciiString &, const TCollection_AsciiString &, const TCollection_AsciiString &, const TCollection_AsciiString &, const TCollection_AsciiString &, const TCollection_AsciiString &, const TCollection_AsciiString &)) &OSD_Path::SetValues, "Sets each component of a path.", py::arg("aNode"), py::arg("aUsername"), py::arg("aPassword"), py::arg("aDisk"), py::arg("aTrek"), py::arg("aName"), py::arg("anExtension"));
cls_OSD_Path.def("SystemName", [](OSD_Path &self, TCollection_AsciiString & a0) -> void { return self.SystemName(a0); });
cls_OSD_Path.def("SystemName", (void (OSD_Path::*)(TCollection_AsciiString &, const OSD_SysType) const) &OSD_Path::SystemName, "Returns system dependent path <aType> is one among Unix,VMS ... This function is not private because you may need to display system dependent path on a front-end. It can be useful when communicating with another system. For instance when you want to communicate between VMS and Unix to transfer files, or to do a remote procedure call using files. example : OSD_Path myPath ('sparc4', 'sga', 'secret_passwd', '$5$dkb100','|users|examples'); Internal ( Dependent_name ); On UNIX sga'secret_passwd':/users/examples On VMS sparc4'sga secret_passwd'::$5$dkb100:[users.examples] Sets each component of a Path giving its system dependent name.", py::arg("FullName"), py::arg("aType"));
cls_OSD_Path.def("ExpandedName", (void (OSD_Path::*)(TCollection_AsciiString &)) &OSD_Path::ExpandedName, "Returns system dependent path resolving logical symbols.", py::arg("aName"));
cls_OSD_Path.def_static("IsValid_", [](const TCollection_AsciiString & a0) -> Standard_Boolean { return OSD_Path::IsValid(a0); });
cls_OSD_Path.def_static("IsValid_", (Standard_Boolean (*)(const TCollection_AsciiString &, const OSD_SysType)) &OSD_Path::IsValid, "Returns TRUE if <theDependentName> is valid for this SysType.", py::arg("theDependentName"), py::arg("theSysType"));
cls_OSD_Path.def("UpTrek", (void (OSD_Path::*)()) &OSD_Path::UpTrek, "This removes the last directory name in <aTrek> and returns result. ex: me = '|usr|bin|todo.sh' me.UpTrek() gives me = '|usr|todo.sh' if <me> contains '|', me.UpTrek() will give again '|' without any error.");
cls_OSD_Path.def("DownTrek", (void (OSD_Path::*)(const TCollection_AsciiString &)) &OSD_Path::DownTrek, "This appends a directory name into the Trek. ex: me = '|usr|todo.sh' me.DownTrek('bin') gives me = '|usr|bin|todo.sh'.", py::arg("aName"));
cls_OSD_Path.def("TrekLength", (Standard_Integer (OSD_Path::*)() const) &OSD_Path::TrekLength, "Returns number of components in Trek of <me>. ex: me = '|usr|sys|etc|bin' me.TrekLength() returns 4.");
cls_OSD_Path.def("RemoveATrek", (void (OSD_Path::*)(const Standard_Integer)) &OSD_Path::RemoveATrek, "This removes a component of Trek in <me> at position <where>. The first component of Trek is numbered 1. ex: me = '|usr|bin|' me.RemoveATrek(1) gives me = '|bin|' To avoid a 'NumericError' because of a bad <where>, use TrekLength() to know number of components of Trek in <me>.", py::arg("where"));
cls_OSD_Path.def("RemoveATrek", (void (OSD_Path::*)(const TCollection_AsciiString &)) &OSD_Path::RemoveATrek, "This removes <aName> from <me> in Trek. No error is raised if <aName> is not in <me>. ex: me = '|usr|sys|etc|doc' me.RemoveATrek('sys') gives me = '|usr|etc|doc'.", py::arg("aName"));
cls_OSD_Path.def("TrekValue", (TCollection_AsciiString (OSD_Path::*)(const Standard_Integer) const) &OSD_Path::TrekValue, "Returns component of Trek in <me> at position <where>. ex: me = '|usr|bin|sys|' me.TrekValue(2) returns 'bin'", py::arg("where"));
cls_OSD_Path.def("InsertATrek", (void (OSD_Path::*)(const TCollection_AsciiString &, const Standard_Integer)) &OSD_Path::InsertATrek, "This inserts <aName> at position <where> into Trek of <me>. ex: me = '|usr|etc|' me.InsertATrek('sys',2) gives me = '|usr|sys|etc'", py::arg("aName"), py::arg("where"));
cls_OSD_Path.def("Node", (TCollection_AsciiString (OSD_Path::*)() const) &OSD_Path::Node, "Returns Node of <me>.");
cls_OSD_Path.def("UserName", (TCollection_AsciiString (OSD_Path::*)() const) &OSD_Path::UserName, "Returns UserName of <me>.");
cls_OSD_Path.def("Password", (TCollection_AsciiString (OSD_Path::*)() const) &OSD_Path::Password, "Returns Password of <me>.");
cls_OSD_Path.def("Disk", (TCollection_AsciiString (OSD_Path::*)() const) &OSD_Path::Disk, "Returns Disk of <me>.");
cls_OSD_Path.def("Trek", (TCollection_AsciiString (OSD_Path::*)() const) &OSD_Path::Trek, "Returns Trek of <me>.");
cls_OSD_Path.def("Name", (TCollection_AsciiString (OSD_Path::*)() const) &OSD_Path::Name, "Returns file name of <me>. If <me> hasn't been initialized, it returns an empty AsciiString.");
cls_OSD_Path.def("Extension", (TCollection_AsciiString (OSD_Path::*)() const) &OSD_Path::Extension, "Returns my extension name. This returns an empty string if path contains no file name.");
cls_OSD_Path.def("SetNode", (void (OSD_Path::*)(const TCollection_AsciiString &)) &OSD_Path::SetNode, "Sets Node of <me>.", py::arg("aName"));
cls_OSD_Path.def("SetUserName", (void (OSD_Path::*)(const TCollection_AsciiString &)) &OSD_Path::SetUserName, "Sets UserName of <me>.", py::arg("aName"));
cls_OSD_Path.def("SetPassword", (void (OSD_Path::*)(const TCollection_AsciiString &)) &OSD_Path::SetPassword, "Sets Password of <me>.", py::arg("aName"));
cls_OSD_Path.def("SetDisk", (void (OSD_Path::*)(const TCollection_AsciiString &)) &OSD_Path::SetDisk, "Sets Disk of <me>.", py::arg("aName"));
cls_OSD_Path.def("SetTrek", (void (OSD_Path::*)(const TCollection_AsciiString &)) &OSD_Path::SetTrek, "Sets Trek of <me>.", py::arg("aName"));
cls_OSD_Path.def("SetName", (void (OSD_Path::*)(const TCollection_AsciiString &)) &OSD_Path::SetName, "Sets file name of <me>. If <me> hasn't been initialized, it returns an empty AsciiString.", py::arg("aName"));
cls_OSD_Path.def("SetExtension", (void (OSD_Path::*)(const TCollection_AsciiString &)) &OSD_Path::SetExtension, "Sets my extension name.", py::arg("aName"));
// cls_OSD_Path.def("LocateExecFile", (Standard_Boolean (OSD_Path::*)(OSD_Path &)) &OSD_Path::LocateExecFile, "Finds the full path of an executable file, like the 'which' Unix utility. Uses the path environment variable. Returns False if executable file not found.", py::arg("aPath"));
cls_OSD_Path.def_static("RelativePath_", (TCollection_AsciiString (*)(const TCollection_AsciiString &, const TCollection_AsciiString &)) &OSD_Path::RelativePath, "Returns the relative file path between the absolute directory path <DirPath> and the absolute file path <AbsFilePath>. If <DirPath> starts with '/', paths are handled as on Unix, if it starts with a letter followed by ':', as on WNT. In particular on WNT directory names are not key sensitive. If handling fails, an empty string is returned.", py::arg("DirPath"), py::arg("AbsFilePath"));
cls_OSD_Path.def_static("AbsolutePath_", (TCollection_AsciiString (*)(const TCollection_AsciiString &, const TCollection_AsciiString &)) &OSD_Path::AbsolutePath, "Returns the absolute file path from the absolute directory path <DirPath> and the relative file path returned by RelativePath(). If the RelFilePath is an absolute path, it is returned and the directory path is ignored. If handling fails, an empty string is returned.", py::arg("DirPath"), py::arg("RelFilePath"));
cls_OSD_Path.def_static("FolderAndFileFromPath_", (void (*)(const TCollection_AsciiString &, TCollection_AsciiString &, TCollection_AsciiString &)) &OSD_Path::FolderAndFileFromPath, "Split absolute filepath into folder path and file name. Example: IN theFilePath ='/media/cdrom/image.jpg' OUT theFolder ='/media/cdrom/' OUT theFileName ='image.jpg'", py::arg("theFilePath"), py::arg("theFolder"), py::arg("theFileName"));
cls_OSD_Path.def_static("IsDosPath_", (Standard_Boolean (*)(const char *)) &OSD_Path::IsDosPath, "Detect absolute DOS-path also used in Windows. The total path length is limited to 256 characters. Sample path: C:", py::arg("thePath"));
cls_OSD_Path.def_static("IsNtExtendedPath_", (Standard_Boolean (*)(const char *)) &OSD_Path::IsNtExtendedPath, "Detect extended-length NT path (can be only absolute). Approximate maximum path is 32767 characters. Sample path: \?: long path File I/O functions in the Windows API convert '/' to '' as part of converting the name to an NT-style name, except when using the '\?' prefix.", py::arg("thePath"));
cls_OSD_Path.def_static("IsUncPath_", (Standard_Boolean (*)(const char *)) &OSD_Path::IsUncPath, "UNC is a naming convention used primarily to specify and map network drives in Microsoft Windows. Sample path: \server", py::arg("thePath"));
cls_OSD_Path.def_static("IsUncExtendedPath_", (Standard_Boolean (*)(const char *)) &OSD_Path::IsUncExtendedPath, "Detect extended-length UNC path. Sample path: \?", py::arg("thePath"));
cls_OSD_Path.def_static("IsUnixPath_", (Standard_Boolean (*)(const char *)) &OSD_Path::IsUnixPath, "Detect absolute UNIX-path. Sample path: /media/cdrom/file", py::arg("thePath"));
cls_OSD_Path.def_static("IsContentProtocolPath_", (Standard_Boolean (*)(const char *)) &OSD_Path::IsContentProtocolPath, "Detect special URLs on Android platform. Sample path: content://filename", py::arg("thePath"));
cls_OSD_Path.def_static("IsRemoteProtocolPath_", (Standard_Boolean (*)(const char *)) &OSD_Path::IsRemoteProtocolPath, "Detect remote protocol path (http / ftp / ...). Actually shouldn't be remote... Sample path: http://domain/path/file", py::arg("thePath"));
cls_OSD_Path.def_static("IsRelativePath_", (Standard_Boolean (*)(const char *)) &OSD_Path::IsRelativePath, "Method to recognize path is absolute or not. Detection is based on path syntax - no any filesystem / network access performed.", py::arg("thePath"));
cls_OSD_Path.def_static("IsAbsolutePath_", (Standard_Boolean (*)(const char *)) &OSD_Path::IsAbsolutePath, "Method to recognize path is absolute or not. Detection is based on path syntax - no any filesystem / network access performed.", py::arg("thePath"));

// CLASS: OSD_CHRONOMETER
py::class_<OSD_Chronometer> cls_OSD_Chronometer(mod, "OSD_Chronometer", "This class measures CPU time (both user and system) consumed by current process or thread. The chronometer can be started and stopped multiple times, and measures cumulative time.");

// Constructors
cls_OSD_Chronometer.def(py::init<>());
cls_OSD_Chronometer.def(py::init<Standard_Boolean>(), py::arg("theThisThreadOnly"));

// Methods
// cls_OSD_Chronometer.def_static("operator new_", (void * (*)(size_t)) &OSD_Chronometer::operator new, "None", py::arg("theSize"));
// cls_OSD_Chronometer.def_static("operator delete_", (void (*)(void *)) &OSD_Chronometer::operator delete, "None", py::arg("theAddress"));
// cls_OSD_Chronometer.def_static("operator new[]_", (void * (*)(size_t)) &OSD_Chronometer::operator new[], "None", py::arg("theSize"));
// cls_OSD_Chronometer.def_static("operator delete[]_", (void (*)(void *)) &OSD_Chronometer::operator delete[], "None", py::arg("theAddress"));
// cls_OSD_Chronometer.def_static("operator new_", (void * (*)(size_t, void *)) &OSD_Chronometer::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_OSD_Chronometer.def_static("operator delete_", (void (*)(void *, void *)) &OSD_Chronometer::operator delete, "None", py::arg(""), py::arg(""));
cls_OSD_Chronometer.def("IsStarted", (Standard_Boolean (OSD_Chronometer::*)() const) &OSD_Chronometer::IsStarted, "Return true if timer has been started.");
cls_OSD_Chronometer.def("Reset", (void (OSD_Chronometer::*)()) &OSD_Chronometer::Reset, "Stops and Reinitializes the Chronometer.");
cls_OSD_Chronometer.def("Restart", (void (OSD_Chronometer::*)()) &OSD_Chronometer::Restart, "Restarts the Chronometer.");
cls_OSD_Chronometer.def("Stop", (void (OSD_Chronometer::*)()) &OSD_Chronometer::Stop, "Stops the Chronometer.");
cls_OSD_Chronometer.def("Start", (void (OSD_Chronometer::*)()) &OSD_Chronometer::Start, "Starts (after Create or Reset) or restarts (after Stop) the chronometer.");
cls_OSD_Chronometer.def("Show", (void (OSD_Chronometer::*)() const) &OSD_Chronometer::Show, "Shows the current CPU user and system time on the standard output stream <cout>. The chronometer can be running (laps Time) or stopped.");
cls_OSD_Chronometer.def("Show", (void (OSD_Chronometer::*)(Standard_OStream &) const) &OSD_Chronometer::Show, "Shows the current CPU user and system time on the output stream <os>. The chronometer can be running (laps Time) or stopped.", py::arg("theOStream"));
cls_OSD_Chronometer.def("UserTimeCPU", (Standard_Real (OSD_Chronometer::*)() const) &OSD_Chronometer::UserTimeCPU, "Returns the current CPU user time in seconds. The chronometer can be running (laps Time) or stopped.");
cls_OSD_Chronometer.def("SystemTimeCPU", (Standard_Real (OSD_Chronometer::*)() const) &OSD_Chronometer::SystemTimeCPU, "Returns the current CPU system time in seconds. The chronometer can be running (laps Time) or stopped.");
cls_OSD_Chronometer.def("Show", [](OSD_Chronometer &self, Standard_Real & theUserSeconds){ self.Show(theUserSeconds); return theUserSeconds; }, "Returns the current CPU user time in a variable. The chronometer can be running (laps Time) or stopped.", py::arg("theUserSeconds"));
cls_OSD_Chronometer.def("Show", [](OSD_Chronometer &self, Standard_Real & theUserSec, Standard_Real & theSystemSec){ self.Show(theUserSec, theSystemSec); return std::tuple<Standard_Real &, Standard_Real &>(theUserSec, theSystemSec); }, "Returns the current CPU user and system time in variables. The chronometer can be running (laps Time) or stopped.", py::arg("theUserSec"), py::arg("theSystemSec"));
cls_OSD_Chronometer.def_static("GetProcessCPU_", [](Standard_Real & UserSeconds, Standard_Real & SystemSeconds){ OSD_Chronometer::GetProcessCPU(UserSeconds, SystemSeconds); return std::tuple<Standard_Real &, Standard_Real &>(UserSeconds, SystemSeconds); }, "Returns CPU time (user and system) consumed by the current process since its start, in seconds. The actual precision of the measurement depends on granularity provided by the system, and is platform-specific.", py::arg("UserSeconds"), py::arg("SystemSeconds"));
cls_OSD_Chronometer.def_static("GetThreadCPU_", [](Standard_Real & UserSeconds, Standard_Real & SystemSeconds){ OSD_Chronometer::GetThreadCPU(UserSeconds, SystemSeconds); return std::tuple<Standard_Real &, Standard_Real &>(UserSeconds, SystemSeconds); }, "Returns CPU time (user and system) consumed by the current thread since its start. Note that this measurement is platform-specific, as threads are implemented and managed differently on different platforms and CPUs.", py::arg("UserSeconds"), py::arg("SystemSeconds"));

// CLASS: OSD_TIMER
py::class_<OSD_Timer, OSD_Chronometer> cls_OSD_Timer(mod, "OSD_Timer", "Working on heterogeneous platforms we need to use the system call gettimeofday. This function is portable and it measures ELAPSED time and CPU time in seconds and microseconds. Example: OSD_Timer aTimer; aTimer.Start(); // Start the timers (t1). ..... // Do something. aTimer.Stop(); // Stop the timers (t2). aTimer.Show(); // Give the elapsed time between t1 and t2. // Give also the process CPU time between // t1 and t2.");

// Constructors
cls_OSD_Timer.def(py::init<>());
cls_OSD_Timer.def(py::init<Standard_Boolean>(), py::arg("theThisThreadOnly"));

// Methods
// cls_OSD_Timer.def_static("operator new_", (void * (*)(size_t)) &OSD_Timer::operator new, "None", py::arg("theSize"));
// cls_OSD_Timer.def_static("operator delete_", (void (*)(void *)) &OSD_Timer::operator delete, "None", py::arg("theAddress"));
// cls_OSD_Timer.def_static("operator new[]_", (void * (*)(size_t)) &OSD_Timer::operator new[], "None", py::arg("theSize"));
// cls_OSD_Timer.def_static("operator delete[]_", (void (*)(void *)) &OSD_Timer::operator delete[], "None", py::arg("theAddress"));
// cls_OSD_Timer.def_static("operator new_", (void * (*)(size_t, void *)) &OSD_Timer::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_OSD_Timer.def_static("operator delete_", (void (*)(void *, void *)) &OSD_Timer::operator delete, "None", py::arg(""), py::arg(""));
cls_OSD_Timer.def("Reset", (void (OSD_Timer::*)(const Standard_Real)) &OSD_Timer::Reset, "Stops and reinitializes the timer with specified elapsed time.", py::arg("theTimeElapsedSec"));
cls_OSD_Timer.def("Reset", (void (OSD_Timer::*)()) &OSD_Timer::Reset, "Stops and reinitializes the timer with zero elapsed time.");
cls_OSD_Timer.def("Restart", (void (OSD_Timer::*)()) &OSD_Timer::Restart, "Restarts the Timer.");
cls_OSD_Timer.def("Show", (void (OSD_Timer::*)() const) &OSD_Timer::Show, "Shows both the elapsed time and CPU time on the standard output stream <cout>.The chronometer can be running (Lap Time) or stopped.");
cls_OSD_Timer.def("Show", (void (OSD_Timer::*)(Standard_OStream &) const) &OSD_Timer::Show, "Shows both the elapsed time and CPU time on the output stream <OS>.", py::arg("os"));
cls_OSD_Timer.def("Show", [](OSD_Timer &self, Standard_Real & theSeconds, Standard_Integer & theMinutes, Standard_Integer & theHours, Standard_Real & theCPUtime){ self.Show(theSeconds, theMinutes, theHours, theCPUtime); return std::tuple<Standard_Real &, Standard_Integer &, Standard_Integer &, Standard_Real &>(theSeconds, theMinutes, theHours, theCPUtime); }, "returns both the elapsed time(seconds,minutes,hours) and CPU time.", py::arg("theSeconds"), py::arg("theMinutes"), py::arg("theHours"), py::arg("theCPUtime"));
cls_OSD_Timer.def("Stop", (void (OSD_Timer::*)()) &OSD_Timer::Stop, "Stops the Timer.");
cls_OSD_Timer.def("Start", (void (OSD_Timer::*)()) &OSD_Timer::Start, "Starts (after Create or Reset) or restarts (after Stop) the Timer.");
cls_OSD_Timer.def("ElapsedTime", (Standard_Real (OSD_Timer::*)() const) &OSD_Timer::ElapsedTime, "Returns elapsed time in seconds.");

// TYPEDEF: OSD_THREADFUNCTION

// TYPEDEF: OSD_PTHREAD

// CLASS: OSD_THREAD
py::class_<OSD_Thread> cls_OSD_Thread(mod, "OSD_Thread", "A simple platform-intependent interface to execute and control threads.");

// Constructors
cls_OSD_Thread.def(py::init<>());
cls_OSD_Thread.def(py::init<const OSD_ThreadFunction &>(), py::arg("func"));
cls_OSD_Thread.def(py::init<const OSD_Thread &>(), py::arg("other"));

// Methods
// cls_OSD_Thread.def_static("operator new_", (void * (*)(size_t)) &OSD_Thread::operator new, "None", py::arg("theSize"));
// cls_OSD_Thread.def_static("operator delete_", (void (*)(void *)) &OSD_Thread::operator delete, "None", py::arg("theAddress"));
// cls_OSD_Thread.def_static("operator new[]_", (void * (*)(size_t)) &OSD_Thread::operator new[], "None", py::arg("theSize"));
// cls_OSD_Thread.def_static("operator delete[]_", (void (*)(void *)) &OSD_Thread::operator delete[], "None", py::arg("theAddress"));
// cls_OSD_Thread.def_static("operator new_", (void * (*)(size_t, void *)) &OSD_Thread::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_OSD_Thread.def_static("operator delete_", (void (*)(void *, void *)) &OSD_Thread::operator delete, "None", py::arg(""), py::arg(""));
cls_OSD_Thread.def("Assign", (void (OSD_Thread::*)(const OSD_Thread &)) &OSD_Thread::Assign, "Copy thread handle from other OSD_Thread object.", py::arg("other"));
// cls_OSD_Thread.def("operator=", (void (OSD_Thread::*)(const OSD_Thread &)) &OSD_Thread::operator=, "None", py::arg("other"));
cls_OSD_Thread.def("SetPriority", (void (OSD_Thread::*)(const Standard_Integer)) &OSD_Thread::SetPriority, "None", py::arg("thePriority"));
cls_OSD_Thread.def("SetFunction", (void (OSD_Thread::*)(const OSD_ThreadFunction &)) &OSD_Thread::SetFunction, "Initialize the tool by the thread function. If the current thread handle is not null, nullifies it.", py::arg("func"));
cls_OSD_Thread.def("Run", [](OSD_Thread &self) -> Standard_Boolean { return self.Run(); });
cls_OSD_Thread.def("Run", [](OSD_Thread &self, const Standard_Address a0) -> Standard_Boolean { return self.Run(a0); });
cls_OSD_Thread.def("Run", (Standard_Boolean (OSD_Thread::*)(const Standard_Address, const Standard_Integer)) &OSD_Thread::Run, "Starts a thread with thread function given in constructor, passing the specified input data (as void *) to it. The parameter WNTStackSize (on Windows only) specifies size of the stack to be allocated for the thread (by default - the same as for the current executable). Returns True if thread started successfully", py::arg("data"), py::arg("WNTStackSize"));
cls_OSD_Thread.def("Detach", (void (OSD_Thread::*)()) &OSD_Thread::Detach, "Detaches the execution thread from this Thread object, so that it cannot be waited. Note that mechanics of this operation is different on UNIX/Linux (the thread is put to detached state) and Windows (the handle is closed). However, the purpose is the same: to instruct the system to release all thread data upon its completion.");
cls_OSD_Thread.def("Wait", (Standard_Boolean (OSD_Thread::*)()) &OSD_Thread::Wait, "Waits till the thread finishes execution.");
cls_OSD_Thread.def("Wait", (Standard_Boolean (OSD_Thread::*)(Standard_Address &)) &OSD_Thread::Wait, "Wait till the thread finishes execution. Returns True if wait was successful, False in case of error.", py::arg("theResult"));
cls_OSD_Thread.def("Wait", (Standard_Boolean (OSD_Thread::*)(const Standard_Integer, Standard_Address &)) &OSD_Thread::Wait, "Waits for some time and if the thread is finished, it returns the result. The function returns false if the thread is not finished yet.", py::arg("time"), py::arg("theResult"));
cls_OSD_Thread.def("GetId", (Standard_ThreadId (OSD_Thread::*)() const) &OSD_Thread::GetId, "Returns ID of the currently controlled thread ID, or 0 if no thread is run");
cls_OSD_Thread.def_static("Current_", (Standard_ThreadId (*)()) &OSD_Thread::Current, "Auxiliary: returns ID of the current thread");

// CLASS: OSD_THREADPOOL
py::class_<OSD_ThreadPool, opencascade::handle<OSD_ThreadPool>, Standard_Transient> cls_OSD_ThreadPool(mod, "OSD_ThreadPool", "Class defining a thread pool for executing algorithms in multi-threaded mode. Thread pool allocates requested amount of threads and keep them alive (in sleep mode when unused) during thread pool lifetime. The same pool can be used by multiple consumers, including nested multi-threading algorithms and concurrent threads: - Thread pool can be used either by multi-threaded algorithm by creating OSD_ThreadPool::Launcher. The functor performing a job takes two parameters - Thread Index and Data Index: void operator(int theThreadIndex, int theDataIndex){} Multi-threaded algorithm may rely on Thread Index for allocating thread-local variables in array form, since the Thread Index is guaranteed to be within range OSD_ThreadPool::Lower() and OSD_ThreadPool::Upper(). - Default thread pool (OSD_ThreadPool::DefaultPool()) can be used in general case, but application may prefer creating a dedicated pool for better control. - Default thread pool allocates the amount of threads considering concurrency level of the system (amount of logical processors). This can be overridden during OSD_ThreadPool construction or by calling OSD_ThreadPool::Init() (the pool should not be used!). - OSD_ThreadPool::Launcher reserves specific amount of threads from the pool for executing multi-threaded Job. Normally, single Launcher instance will occupy all threads available in thread pool, so that nested multi-threaded algorithms (within the same thread) and concurrent threads trying to use the same thread pool will run sequentially. This behavior is affected by OSD_ThreadPool::NbDefaultThreadsToLaunch() parameter and Launcher constructor, so that single Launcher instance will occupy not all threads in the pool allowing other threads to be used concurrently. - OSD_ThreadPool::Launcher locks thread one-by-one from thread pool in a thread-safe way. - Each working thread catches exceptions occurred during job execution, and Launcher will throw Standard_Failure in a caller thread on completed execution.");

// Constructors
cls_OSD_ThreadPool.def(py::init<>());
cls_OSD_ThreadPool.def(py::init<int>(), py::arg("theNbThreads"));

// Methods
cls_OSD_ThreadPool.def_static("get_type_name_", (const char * (*)()) &OSD_ThreadPool::get_type_name, "None");
cls_OSD_ThreadPool.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &OSD_ThreadPool::get_type_descriptor, "None");
cls_OSD_ThreadPool.def("DynamicType", (const opencascade::handle<Standard_Type> & (OSD_ThreadPool::*)() const) &OSD_ThreadPool::DynamicType, "None");
cls_OSD_ThreadPool.def_static("DefaultPool_", []() -> const opencascade::handle<OSD_ThreadPool> & { return OSD_ThreadPool::DefaultPool(); });
cls_OSD_ThreadPool.def_static("DefaultPool_", (const opencascade::handle<OSD_ThreadPool> & (*)(int)) &OSD_ThreadPool::DefaultPool, "Return (or create) a default thread pool. Number of threads argument will be considered only when called first time.", py::arg("theNbThreads"));
cls_OSD_ThreadPool.def("HasThreads", (bool (OSD_ThreadPool::*)() const) &OSD_ThreadPool::HasThreads, "Return TRUE if at least 2 threads are available (including self-thread).");
cls_OSD_ThreadPool.def("LowerThreadIndex", (int (OSD_ThreadPool::*)() const) &OSD_ThreadPool::LowerThreadIndex, "Return the lower thread index.");
cls_OSD_ThreadPool.def("UpperThreadIndex", (int (OSD_ThreadPool::*)() const) &OSD_ThreadPool::UpperThreadIndex, "Return the upper thread index (last index is reserved for self-thread).");
cls_OSD_ThreadPool.def("NbThreads", (int (OSD_ThreadPool::*)() const) &OSD_ThreadPool::NbThreads, "Return the number of threads; >= 1.");
cls_OSD_ThreadPool.def("NbDefaultThreadsToLaunch", (int (OSD_ThreadPool::*)() const) &OSD_ThreadPool::NbDefaultThreadsToLaunch, "Return maximum number of threads to be locked by a single Launcher object by default; the entire thread pool size is returned by default.");
cls_OSD_ThreadPool.def("SetNbDefaultThreadsToLaunch", (void (OSD_ThreadPool::*)(int)) &OSD_ThreadPool::SetNbDefaultThreadsToLaunch, "Set maximum number of threads to be locked by a single Launcher object by default. Should be set BEFORE first usage.", py::arg("theNbThreads"));
cls_OSD_ThreadPool.def("IsInUse", (bool (OSD_ThreadPool::*)()) &OSD_ThreadPool::IsInUse, "Checks if thread pools has active consumers.");
cls_OSD_ThreadPool.def("Init", (void (OSD_ThreadPool::*)(int)) &OSD_ThreadPool::Init, "Reinitialize the thread pool with a different number of threads. Should be called only with no active jobs, or exception Standard_ProgramError will be thrown!", py::arg("theNbThreads"));

// CLASS: OSD_PARALLEL
py::class_<OSD_Parallel> cls_OSD_Parallel(mod, "OSD_Parallel", "Simple tool for code parallelization.");

// Methods
cls_OSD_Parallel.def_static("ToUseOcctThreads_", (Standard_Boolean (*)()) &OSD_Parallel::ToUseOcctThreads, "Returns TRUE if OCCT threads should be used instead of auxiliary threads library; default value is FALSE if alternative library has been enabled while OCCT building and TRUE otherwise.");
cls_OSD_Parallel.def_static("SetUseOcctThreads_", (void (*)(Standard_Boolean)) &OSD_Parallel::SetUseOcctThreads, "Sets if OCCT threads should be used instead of auxiliary threads library. Has no effect if OCCT has been built with no auxiliary threads library.", py::arg("theToUseOcct"));
cls_OSD_Parallel.def_static("NbLogicalProcessors_", (Standard_Integer (*)()) &OSD_Parallel::NbLogicalProcessors, "Returns number of logical processors.");

// TYPEDEF: OSD_FUNCTION

// CLASS: OSD
py::class_<OSD> cls_OSD(mod, "OSD", "Set of Operating Sytem Dependent (OSD) Tools");

// Methods
// cls_OSD.def_static("operator new_", (void * (*)(size_t)) &OSD::operator new, "None", py::arg("theSize"));
// cls_OSD.def_static("operator delete_", (void (*)(void *)) &OSD::operator delete, "None", py::arg("theAddress"));
// cls_OSD.def_static("operator new[]_", (void * (*)(size_t)) &OSD::operator new[], "None", py::arg("theSize"));
// cls_OSD.def_static("operator delete[]_", (void (*)(void *)) &OSD::operator delete[], "None", py::arg("theAddress"));
// cls_OSD.def_static("operator new_", (void * (*)(size_t, void *)) &OSD::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_OSD.def_static("operator delete_", (void (*)(void *, void *)) &OSD::operator delete, "None", py::arg(""), py::arg(""));
cls_OSD.def_static("SetSignal_", (void (*)(OSD_SignalMode, Standard_Boolean)) &OSD::SetSignal, "Sets or removes signal and FPE (floating-point exception) handlers. OCCT signal handlers translate signals raised by C subsystem to C++ exceptions inheriting Standard_Failure.", py::arg("theSignalMode"), py::arg("theFloatingSignal"));
cls_OSD.def_static("SetSignal_", []() -> void { return OSD::SetSignal(); });
cls_OSD.def_static("SetSignal_", (void (*)(const Standard_Boolean)) &OSD::SetSignal, "Sets signal and FPE handlers. Short-cut for OSD::SetSignal (OSD_SignalMode_Set, theFloatingSignal).", py::arg("theFloatingSignal"));
cls_OSD.def_static("SetThreadLocalSignal_", (void (*)(OSD_SignalMode, Standard_Boolean)) &OSD::SetThreadLocalSignal, "Initializes thread-local signal handlers. This includes _set_se_translator() on Windows platform, and SetFloatingSignal(). The main purpose of this method is initializing handlers for newly created threads without overriding global handlers (set by application or by OSD::SetSignal()).", py::arg("theSignalMode"), py::arg("theFloatingSignal"));
cls_OSD.def_static("SetFloatingSignal_", (void (*)(Standard_Boolean)) &OSD::SetFloatingSignal, "Enables / disables generation of C signal on floating point exceptions (FPE). This call does NOT register a handler for signal raised in case of FPE - SetSignal() should be called beforehand for complete setup. Note that FPE setting is thread-local, new threads inherit it from parent.", py::arg("theFloatingSignal"));
cls_OSD.def_static("SignalMode_", (OSD_SignalMode (*)()) &OSD::SignalMode, "Returns signal mode set by the last call to SetSignal(). By default, returns OSD_SignalMode_AsIs.");
cls_OSD.def_static("ToCatchFloatingSignals_", (Standard_Boolean (*)()) &OSD::ToCatchFloatingSignals, "Returns true if floating point exceptions will raise C signal according to current (platform-dependent) settings in this thread.");
cls_OSD.def_static("SecSleep_", (void (*)(const Standard_Integer)) &OSD::SecSleep, "Commands the process to sleep for a number of seconds.", py::arg("aDelay"));
cls_OSD.def_static("MilliSecSleep_", (void (*)(const Standard_Integer)) &OSD::MilliSecSleep, "Commands the process to sleep for a number of milliseconds", py::arg("aDelay"));
// cls_OSD.def_static("RealToCString_", (Standard_Boolean (*)(const Standard_Real, Standard_PCharacter &)) &OSD::RealToCString, "Converts aReal into aCstring in exponential format with a period as decimal point, no thousand separator and no grouping of digits. The conversion is independant from the current locale", py::arg("aReal"), py::arg("aString"));
cls_OSD.def_static("CStringToReal_", [](const Standard_CString aString, Standard_Real & aReal){ Standard_Boolean rv = OSD::CStringToReal(aString, aReal); return std::tuple<Standard_Boolean, Standard_Real &>(rv, aReal); }, "Converts aCstring representing a real with a period as decimal point, no thousand separator and no grouping of digits into aReal . The conversion is independant from the current locale.", py::arg("aString"), py::arg("aReal"));
cls_OSD.def_static("ControlBreak_", (void (*)()) &OSD::ControlBreak, "since Windows NT does not support 'SIGINT' signal like UNIX, then this method checks whether Ctrl-Break keystroke was or not. If yes then raises Exception_CTRL_BREAK.");

// CLASS: OSD_ERROR
py::class_<OSD_Error> cls_OSD_Error(mod, "OSD_Error", "Accurate management of OSD specific errors.");

// Constructors
cls_OSD_Error.def(py::init<>());

// Methods
// cls_OSD_Error.def_static("operator new_", (void * (*)(size_t)) &OSD_Error::operator new, "None", py::arg("theSize"));
// cls_OSD_Error.def_static("operator delete_", (void (*)(void *)) &OSD_Error::operator delete, "None", py::arg("theAddress"));
// cls_OSD_Error.def_static("operator new[]_", (void * (*)(size_t)) &OSD_Error::operator new[], "None", py::arg("theSize"));
// cls_OSD_Error.def_static("operator delete[]_", (void (*)(void *)) &OSD_Error::operator delete[], "None", py::arg("theAddress"));
// cls_OSD_Error.def_static("operator new_", (void * (*)(size_t, void *)) &OSD_Error::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_OSD_Error.def_static("operator delete_", (void (*)(void *, void *)) &OSD_Error::operator delete, "None", py::arg(""), py::arg(""));
cls_OSD_Error.def("Perror", (void (OSD_Error::*)()) &OSD_Error::Perror, "Raises OSD_Error with accurate error message.");
cls_OSD_Error.def("SetValue", (void (OSD_Error::*)(const Standard_Integer, const Standard_Integer, const TCollection_AsciiString &)) &OSD_Error::SetValue, "Instantiates error This is only used by OSD methods to instantiates an error code. No description is done for the programmer.", py::arg("Errcode"), py::arg("From"), py::arg("Message"));
cls_OSD_Error.def("Error", (Standard_Integer (OSD_Error::*)() const) &OSD_Error::Error, "Returns an accurate error code. To test these values, you must include 'OSD_ErrorList.hxx'");
cls_OSD_Error.def("Failed", (Standard_Boolean (OSD_Error::*)() const) &OSD_Error::Failed, "Returns TRUE if an error occurs This is a way to test if a system call succeeded or not.");
cls_OSD_Error.def("Reset", (void (OSD_Error::*)()) &OSD_Error::Reset, "Resets error counter to zero This allows the user to ignore an error (WARNING).");

// CLASS: OSD_FILENODE
py::class_<OSD_FileNode, std::unique_ptr<OSD_FileNode, py::nodelete>> cls_OSD_FileNode(mod, "OSD_FileNode", "A class for 'File' and 'Directory' grouping common methods (file/directory manipulation tools). The 'file oriented' name means files or directories which are in fact hard coded as files.");

// Methods
// cls_OSD_FileNode.def_static("operator new_", (void * (*)(size_t)) &OSD_FileNode::operator new, "None", py::arg("theSize"));
// cls_OSD_FileNode.def_static("operator delete_", (void (*)(void *)) &OSD_FileNode::operator delete, "None", py::arg("theAddress"));
// cls_OSD_FileNode.def_static("operator new[]_", (void * (*)(size_t)) &OSD_FileNode::operator new[], "None", py::arg("theSize"));
// cls_OSD_FileNode.def_static("operator delete[]_", (void (*)(void *)) &OSD_FileNode::operator delete[], "None", py::arg("theAddress"));
// cls_OSD_FileNode.def_static("operator new_", (void * (*)(size_t, void *)) &OSD_FileNode::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_OSD_FileNode.def_static("operator delete_", (void (*)(void *, void *)) &OSD_FileNode::operator delete, "None", py::arg(""), py::arg(""));
cls_OSD_FileNode.def("Path", (void (OSD_FileNode::*)(OSD_Path &) const) &OSD_FileNode::Path, "Gets file name and path.", py::arg("Name"));
cls_OSD_FileNode.def("SetPath", (void (OSD_FileNode::*)(const OSD_Path &)) &OSD_FileNode::SetPath, "Sets file name and path. If a name is not found, it raises a program error.", py::arg("Name"));
cls_OSD_FileNode.def("Exists", (Standard_Boolean (OSD_FileNode::*)()) &OSD_FileNode::Exists, "Returns TRUE if <me> exists.");
cls_OSD_FileNode.def("Remove", (void (OSD_FileNode::*)()) &OSD_FileNode::Remove, "Erases the FileNode from directory");
cls_OSD_FileNode.def("Move", (void (OSD_FileNode::*)(const OSD_Path &)) &OSD_FileNode::Move, "Moves <me> into another directory", py::arg("NewPath"));
cls_OSD_FileNode.def("Copy", (void (OSD_FileNode::*)(const OSD_Path &)) &OSD_FileNode::Copy, "Copies <me> to another FileNode", py::arg("ToPath"));
cls_OSD_FileNode.def("Protection", (OSD_Protection (OSD_FileNode::*)()) &OSD_FileNode::Protection, "Returns access mode of <me>.");
cls_OSD_FileNode.def("SetProtection", (void (OSD_FileNode::*)(const OSD_Protection &)) &OSD_FileNode::SetProtection, "Changes protection of the FileNode", py::arg("Prot"));
cls_OSD_FileNode.def("AccessMoment", (Quantity_Date (OSD_FileNode::*)()) &OSD_FileNode::AccessMoment, "Returns last write access. On UNIX, AccessMoment and CreationMoment return the same value.");
cls_OSD_FileNode.def("CreationMoment", (Quantity_Date (OSD_FileNode::*)()) &OSD_FileNode::CreationMoment, "Returns creation date. On UNIX, AccessMoment and CreationMoment return the same value.");
cls_OSD_FileNode.def("Failed", (Standard_Boolean (OSD_FileNode::*)() const) &OSD_FileNode::Failed, "Returns TRUE if an error occurs");
cls_OSD_FileNode.def("Reset", (void (OSD_FileNode::*)()) &OSD_FileNode::Reset, "Resets error counter to zero");
cls_OSD_FileNode.def("Perror", (void (OSD_FileNode::*)()) &OSD_FileNode::Perror, "Raises OSD_Error");
cls_OSD_FileNode.def("Error", (Standard_Integer (OSD_FileNode::*)() const) &OSD_FileNode::Error, "Returns error number if 'Failed' is TRUE.");

// CLASS: OSD_DIRECTORY
py::class_<OSD_Directory, OSD_FileNode> cls_OSD_Directory(mod, "OSD_Directory", "Management of directories (a set of directory oriented tools)");

// Constructors
cls_OSD_Directory.def(py::init<>());
cls_OSD_Directory.def(py::init<const OSD_Path &>(), py::arg("theName"));

// Methods
cls_OSD_Directory.def_static("BuildTemporary_", (OSD_Directory (*)()) &OSD_Directory::BuildTemporary, "Creates a temporary Directory in current directory. This directory is automatically removed when object dies.");
cls_OSD_Directory.def("Build", (void (OSD_Directory::*)(const OSD_Protection &)) &OSD_Directory::Build, "Creates (physically) a directory. When a directory of the same name already exists, no error is returned, and only <Protect> is applied to the existing directory.", py::arg("Protect"));

// CLASS: OSD_DIRECTORYITERATOR
py::class_<OSD_DirectoryIterator> cls_OSD_DirectoryIterator(mod, "OSD_DirectoryIterator", "Manages a breadth-only search for sub-directories in the specified Path. There is no specific order of results.");

// Constructors
cls_OSD_DirectoryIterator.def(py::init<>());
cls_OSD_DirectoryIterator.def(py::init<const OSD_Path &, const TCollection_AsciiString &>(), py::arg("where"), py::arg("Mask"));

// Methods
// cls_OSD_DirectoryIterator.def_static("operator new_", (void * (*)(size_t)) &OSD_DirectoryIterator::operator new, "None", py::arg("theSize"));
// cls_OSD_DirectoryIterator.def_static("operator delete_", (void (*)(void *)) &OSD_DirectoryIterator::operator delete, "None", py::arg("theAddress"));
// cls_OSD_DirectoryIterator.def_static("operator new[]_", (void * (*)(size_t)) &OSD_DirectoryIterator::operator new[], "None", py::arg("theSize"));
// cls_OSD_DirectoryIterator.def_static("operator delete[]_", (void (*)(void *)) &OSD_DirectoryIterator::operator delete[], "None", py::arg("theAddress"));
// cls_OSD_DirectoryIterator.def_static("operator new_", (void * (*)(size_t, void *)) &OSD_DirectoryIterator::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_OSD_DirectoryIterator.def_static("operator delete_", (void (*)(void *, void *)) &OSD_DirectoryIterator::operator delete, "None", py::arg(""), py::arg(""));
cls_OSD_DirectoryIterator.def("Destroy", (void (OSD_DirectoryIterator::*)()) &OSD_DirectoryIterator::Destroy, "None");
cls_OSD_DirectoryIterator.def("Initialize", (void (OSD_DirectoryIterator::*)(const OSD_Path &, const TCollection_AsciiString &)) &OSD_DirectoryIterator::Initialize, "Initializes the current File Directory", py::arg("where"), py::arg("Mask"));
cls_OSD_DirectoryIterator.def("More", (Standard_Boolean (OSD_DirectoryIterator::*)()) &OSD_DirectoryIterator::More, "Returns TRUE if other items are found while using the 'Tree' method.");
cls_OSD_DirectoryIterator.def("Next", (void (OSD_DirectoryIterator::*)()) &OSD_DirectoryIterator::Next, "Sets the iterator to the next item. Returns the item value corresponding to the current position of the iterator.");
cls_OSD_DirectoryIterator.def("Values", (OSD_Directory (OSD_DirectoryIterator::*)()) &OSD_DirectoryIterator::Values, "Returns the next item found .");
cls_OSD_DirectoryIterator.def("Failed", (Standard_Boolean (OSD_DirectoryIterator::*)() const) &OSD_DirectoryIterator::Failed, "Returns TRUE if an error occurs");
cls_OSD_DirectoryIterator.def("Reset", (void (OSD_DirectoryIterator::*)()) &OSD_DirectoryIterator::Reset, "Resets error counter to zero");
cls_OSD_DirectoryIterator.def("Perror", (void (OSD_DirectoryIterator::*)()) &OSD_DirectoryIterator::Perror, "Raises OSD_Error");
cls_OSD_DirectoryIterator.def("Error", (Standard_Integer (OSD_DirectoryIterator::*)() const) &OSD_DirectoryIterator::Error, "Returns error number if 'Failed' is TRUE.");

// CLASS: OSD_DISK
py::class_<OSD_Disk> cls_OSD_Disk(mod, "OSD_Disk", "Disk management (a set of disk oriented tools)");

// Constructors
cls_OSD_Disk.def(py::init<>());
cls_OSD_Disk.def(py::init<const OSD_Path &>(), py::arg("Name"));
cls_OSD_Disk.def(py::init<const Standard_CString>(), py::arg("PathName"));

// Methods
// cls_OSD_Disk.def_static("operator new_", (void * (*)(size_t)) &OSD_Disk::operator new, "None", py::arg("theSize"));
// cls_OSD_Disk.def_static("operator delete_", (void (*)(void *)) &OSD_Disk::operator delete, "None", py::arg("theAddress"));
// cls_OSD_Disk.def_static("operator new[]_", (void * (*)(size_t)) &OSD_Disk::operator new[], "None", py::arg("theSize"));
// cls_OSD_Disk.def_static("operator delete[]_", (void (*)(void *)) &OSD_Disk::operator delete[], "None", py::arg("theAddress"));
// cls_OSD_Disk.def_static("operator new_", (void * (*)(size_t, void *)) &OSD_Disk::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_OSD_Disk.def_static("operator delete_", (void (*)(void *, void *)) &OSD_Disk::operator delete, "None", py::arg(""), py::arg(""));
cls_OSD_Disk.def("Name", (OSD_Path (OSD_Disk::*)() const) &OSD_Disk::Name, "Returns disk name of <me>.");
cls_OSD_Disk.def("SetName", (void (OSD_Disk::*)(const OSD_Path &)) &OSD_Disk::SetName, "Instantiates <me> with <Name>.", py::arg("Name"));
cls_OSD_Disk.def("DiskSize", (Standard_Integer (OSD_Disk::*)()) &OSD_Disk::DiskSize, "Returns total disk capacity in 512 bytes blocks.");
cls_OSD_Disk.def("DiskFree", (Standard_Integer (OSD_Disk::*)()) &OSD_Disk::DiskFree, "Returns free available 512 bytes blocks on disk.");
cls_OSD_Disk.def("Failed", (Standard_Boolean (OSD_Disk::*)() const) &OSD_Disk::Failed, "Returns TRUE if an error occurs");
cls_OSD_Disk.def("Reset", (void (OSD_Disk::*)()) &OSD_Disk::Reset, "Resets error counter to zero");
cls_OSD_Disk.def("Perror", (void (OSD_Disk::*)()) &OSD_Disk::Perror, "Raises OSD_Error");
cls_OSD_Disk.def("Error", (Standard_Integer (OSD_Disk::*)() const) &OSD_Disk::Error, "Returns error number if 'Failed' is TRUE.");

// CLASS: OSD_ENVIRONMENT
py::class_<OSD_Environment> cls_OSD_Environment(mod, "OSD_Environment", "Management of system environment variables An environment variable is composed of a variable name and its value.");

// Constructors
cls_OSD_Environment.def(py::init<>());
cls_OSD_Environment.def(py::init<const TCollection_AsciiString &>(), py::arg("Name"));
cls_OSD_Environment.def(py::init<const TCollection_AsciiString &, const TCollection_AsciiString &>(), py::arg("Name"), py::arg("Value"));

// Methods
// cls_OSD_Environment.def_static("operator new_", (void * (*)(size_t)) &OSD_Environment::operator new, "None", py::arg("theSize"));
// cls_OSD_Environment.def_static("operator delete_", (void (*)(void *)) &OSD_Environment::operator delete, "None", py::arg("theAddress"));
// cls_OSD_Environment.def_static("operator new[]_", (void * (*)(size_t)) &OSD_Environment::operator new[], "None", py::arg("theSize"));
// cls_OSD_Environment.def_static("operator delete[]_", (void (*)(void *)) &OSD_Environment::operator delete[], "None", py::arg("theAddress"));
// cls_OSD_Environment.def_static("operator new_", (void * (*)(size_t, void *)) &OSD_Environment::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_OSD_Environment.def_static("operator delete_", (void (*)(void *, void *)) &OSD_Environment::operator delete, "None", py::arg(""), py::arg(""));
cls_OSD_Environment.def("SetValue", (void (OSD_Environment::*)(const TCollection_AsciiString &)) &OSD_Environment::SetValue, "Changes environment variable value. Raises ConstructionError either if the string contains characters not in range of ' '...'~' or if the string contains the character '$' which is forbiden.", py::arg("Value"));
cls_OSD_Environment.def("Value", (TCollection_AsciiString (OSD_Environment::*)()) &OSD_Environment::Value, "Gets the value of an environment variable");
cls_OSD_Environment.def("SetName", (void (OSD_Environment::*)(const TCollection_AsciiString &)) &OSD_Environment::SetName, "Changes environment variable name. Raises ConstructionError either if the string contains characters not in range of ' '...'~' or if the string contains the character '$' which is forbiden.", py::arg("name"));
cls_OSD_Environment.def("Name", (TCollection_AsciiString (OSD_Environment::*)() const) &OSD_Environment::Name, "Gets the name of <me>.");
cls_OSD_Environment.def("Build", (void (OSD_Environment::*)()) &OSD_Environment::Build, "Sets the value of an environment variable into system (physically).");
cls_OSD_Environment.def("Remove", (void (OSD_Environment::*)()) &OSD_Environment::Remove, "Removes (physically) an environment variable");
cls_OSD_Environment.def("Failed", (Standard_Boolean (OSD_Environment::*)() const) &OSD_Environment::Failed, "Returns TRUE if an error occurs");
cls_OSD_Environment.def("Reset", (void (OSD_Environment::*)()) &OSD_Environment::Reset, "Resets error counter to zero");
cls_OSD_Environment.def("Perror", (void (OSD_Environment::*)()) &OSD_Environment::Perror, "Raises OSD_Error");
cls_OSD_Environment.def("Error", (Standard_Integer (OSD_Environment::*)() const) &OSD_Environment::Error, "Returns error number if 'Failed' is TRUE.");

// CLASS: OSD_EXCEPTION
py::class_<OSD_Exception, opencascade::handle<OSD_Exception>, Standard_Failure> cls_OSD_Exception(mod, "OSD_Exception", "None");

// Constructors
cls_OSD_Exception.def(py::init<>());
cls_OSD_Exception.def(py::init<const Standard_CString>(), py::arg("theMessage"));

// Methods
cls_OSD_Exception.def_static("Raise_", (void (*)(const Standard_CString)) &OSD_Exception::Raise, "None", py::arg("theMessage"));
cls_OSD_Exception.def_static("Raise_", (void (*)(Standard_SStream &)) &OSD_Exception::Raise, "None", py::arg("theMessage"));
cls_OSD_Exception.def_static("NewInstance_", (opencascade::handle<OSD_Exception> (*)(const Standard_CString)) &OSD_Exception::NewInstance, "None", py::arg("theMessage"));
cls_OSD_Exception.def_static("get_type_name_", (const char * (*)()) &OSD_Exception::get_type_name, "None");
cls_OSD_Exception.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &OSD_Exception::get_type_descriptor, "None");
cls_OSD_Exception.def("DynamicType", (const opencascade::handle<Standard_Type> & (OSD_Exception::*)() const) &OSD_Exception::DynamicType, "None");

// CLASS: OSD_EXCEPTION_ACCESS_VIOLATION
py::class_<OSD_Exception_ACCESS_VIOLATION, opencascade::handle<OSD_Exception_ACCESS_VIOLATION>, OSD_Exception> cls_OSD_Exception_ACCESS_VIOLATION(mod, "OSD_Exception_ACCESS_VIOLATION", "None");

// Constructors
cls_OSD_Exception_ACCESS_VIOLATION.def(py::init<>());
cls_OSD_Exception_ACCESS_VIOLATION.def(py::init<const Standard_CString>(), py::arg("theMessage"));

// Methods
cls_OSD_Exception_ACCESS_VIOLATION.def_static("Raise_", (void (*)(const Standard_CString)) &OSD_Exception_ACCESS_VIOLATION::Raise, "None", py::arg("theMessage"));
cls_OSD_Exception_ACCESS_VIOLATION.def_static("Raise_", (void (*)(Standard_SStream &)) &OSD_Exception_ACCESS_VIOLATION::Raise, "None", py::arg("theMessage"));
cls_OSD_Exception_ACCESS_VIOLATION.def_static("NewInstance_", (opencascade::handle<OSD_Exception_ACCESS_VIOLATION> (*)(const Standard_CString)) &OSD_Exception_ACCESS_VIOLATION::NewInstance, "None", py::arg("theMessage"));
cls_OSD_Exception_ACCESS_VIOLATION.def_static("get_type_name_", (const char * (*)()) &OSD_Exception_ACCESS_VIOLATION::get_type_name, "None");
cls_OSD_Exception_ACCESS_VIOLATION.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &OSD_Exception_ACCESS_VIOLATION::get_type_descriptor, "None");
cls_OSD_Exception_ACCESS_VIOLATION.def("DynamicType", (const opencascade::handle<Standard_Type> & (OSD_Exception_ACCESS_VIOLATION::*)() const) &OSD_Exception_ACCESS_VIOLATION::DynamicType, "None");

// CLASS: OSD_EXCEPTION_ARRAY_BOUNDS_EXCEEDED
py::class_<OSD_Exception_ARRAY_BOUNDS_EXCEEDED, opencascade::handle<OSD_Exception_ARRAY_BOUNDS_EXCEEDED>, OSD_Exception> cls_OSD_Exception_ARRAY_BOUNDS_EXCEEDED(mod, "OSD_Exception_ARRAY_BOUNDS_EXCEEDED", "None");

// Constructors
cls_OSD_Exception_ARRAY_BOUNDS_EXCEEDED.def(py::init<>());
cls_OSD_Exception_ARRAY_BOUNDS_EXCEEDED.def(py::init<const Standard_CString>(), py::arg("theMessage"));

// Methods
cls_OSD_Exception_ARRAY_BOUNDS_EXCEEDED.def_static("Raise_", (void (*)(const Standard_CString)) &OSD_Exception_ARRAY_BOUNDS_EXCEEDED::Raise, "None", py::arg("theMessage"));
cls_OSD_Exception_ARRAY_BOUNDS_EXCEEDED.def_static("Raise_", (void (*)(Standard_SStream &)) &OSD_Exception_ARRAY_BOUNDS_EXCEEDED::Raise, "None", py::arg("theMessage"));
cls_OSD_Exception_ARRAY_BOUNDS_EXCEEDED.def_static("NewInstance_", (opencascade::handle<OSD_Exception_ARRAY_BOUNDS_EXCEEDED> (*)(const Standard_CString)) &OSD_Exception_ARRAY_BOUNDS_EXCEEDED::NewInstance, "None", py::arg("theMessage"));
cls_OSD_Exception_ARRAY_BOUNDS_EXCEEDED.def_static("get_type_name_", (const char * (*)()) &OSD_Exception_ARRAY_BOUNDS_EXCEEDED::get_type_name, "None");
cls_OSD_Exception_ARRAY_BOUNDS_EXCEEDED.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &OSD_Exception_ARRAY_BOUNDS_EXCEEDED::get_type_descriptor, "None");
cls_OSD_Exception_ARRAY_BOUNDS_EXCEEDED.def("DynamicType", (const opencascade::handle<Standard_Type> & (OSD_Exception_ARRAY_BOUNDS_EXCEEDED::*)() const) &OSD_Exception_ARRAY_BOUNDS_EXCEEDED::DynamicType, "None");

// CLASS: OSD_EXCEPTION_CTRL_BREAK
py::class_<OSD_Exception_CTRL_BREAK, opencascade::handle<OSD_Exception_CTRL_BREAK>, OSD_Exception> cls_OSD_Exception_CTRL_BREAK(mod, "OSD_Exception_CTRL_BREAK", "None");

// Constructors
cls_OSD_Exception_CTRL_BREAK.def(py::init<>());
cls_OSD_Exception_CTRL_BREAK.def(py::init<const Standard_CString>(), py::arg("theMessage"));

// Methods
cls_OSD_Exception_CTRL_BREAK.def_static("Raise_", (void (*)(const Standard_CString)) &OSD_Exception_CTRL_BREAK::Raise, "None", py::arg("theMessage"));
cls_OSD_Exception_CTRL_BREAK.def_static("Raise_", (void (*)(Standard_SStream &)) &OSD_Exception_CTRL_BREAK::Raise, "None", py::arg("theMessage"));
cls_OSD_Exception_CTRL_BREAK.def_static("NewInstance_", (opencascade::handle<OSD_Exception_CTRL_BREAK> (*)(const Standard_CString)) &OSD_Exception_CTRL_BREAK::NewInstance, "None", py::arg("theMessage"));
cls_OSD_Exception_CTRL_BREAK.def_static("get_type_name_", (const char * (*)()) &OSD_Exception_CTRL_BREAK::get_type_name, "None");
cls_OSD_Exception_CTRL_BREAK.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &OSD_Exception_CTRL_BREAK::get_type_descriptor, "None");
cls_OSD_Exception_CTRL_BREAK.def("DynamicType", (const opencascade::handle<Standard_Type> & (OSD_Exception_CTRL_BREAK::*)() const) &OSD_Exception_CTRL_BREAK::DynamicType, "None");

// CLASS: OSD_EXCEPTION_FLT_DENORMAL_OPERAND
py::class_<OSD_Exception_FLT_DENORMAL_OPERAND, opencascade::handle<OSD_Exception_FLT_DENORMAL_OPERAND>, OSD_Exception> cls_OSD_Exception_FLT_DENORMAL_OPERAND(mod, "OSD_Exception_FLT_DENORMAL_OPERAND", "None");

// Constructors
cls_OSD_Exception_FLT_DENORMAL_OPERAND.def(py::init<>());
cls_OSD_Exception_FLT_DENORMAL_OPERAND.def(py::init<const Standard_CString>(), py::arg("theMessage"));

// Methods
cls_OSD_Exception_FLT_DENORMAL_OPERAND.def_static("Raise_", (void (*)(const Standard_CString)) &OSD_Exception_FLT_DENORMAL_OPERAND::Raise, "None", py::arg("theMessage"));
cls_OSD_Exception_FLT_DENORMAL_OPERAND.def_static("Raise_", (void (*)(Standard_SStream &)) &OSD_Exception_FLT_DENORMAL_OPERAND::Raise, "None", py::arg("theMessage"));
cls_OSD_Exception_FLT_DENORMAL_OPERAND.def_static("NewInstance_", (opencascade::handle<OSD_Exception_FLT_DENORMAL_OPERAND> (*)(const Standard_CString)) &OSD_Exception_FLT_DENORMAL_OPERAND::NewInstance, "None", py::arg("theMessage"));
cls_OSD_Exception_FLT_DENORMAL_OPERAND.def_static("get_type_name_", (const char * (*)()) &OSD_Exception_FLT_DENORMAL_OPERAND::get_type_name, "None");
cls_OSD_Exception_FLT_DENORMAL_OPERAND.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &OSD_Exception_FLT_DENORMAL_OPERAND::get_type_descriptor, "None");
cls_OSD_Exception_FLT_DENORMAL_OPERAND.def("DynamicType", (const opencascade::handle<Standard_Type> & (OSD_Exception_FLT_DENORMAL_OPERAND::*)() const) &OSD_Exception_FLT_DENORMAL_OPERAND::DynamicType, "None");

// CLASS: OSD_EXCEPTION_FLT_DIVIDE_BY_ZERO
py::class_<OSD_Exception_FLT_DIVIDE_BY_ZERO, opencascade::handle<OSD_Exception_FLT_DIVIDE_BY_ZERO>, OSD_Exception> cls_OSD_Exception_FLT_DIVIDE_BY_ZERO(mod, "OSD_Exception_FLT_DIVIDE_BY_ZERO", "None");

// Constructors
cls_OSD_Exception_FLT_DIVIDE_BY_ZERO.def(py::init<>());
cls_OSD_Exception_FLT_DIVIDE_BY_ZERO.def(py::init<const Standard_CString>(), py::arg("theMessage"));

// Methods
cls_OSD_Exception_FLT_DIVIDE_BY_ZERO.def_static("Raise_", (void (*)(const Standard_CString)) &OSD_Exception_FLT_DIVIDE_BY_ZERO::Raise, "None", py::arg("theMessage"));
cls_OSD_Exception_FLT_DIVIDE_BY_ZERO.def_static("Raise_", (void (*)(Standard_SStream &)) &OSD_Exception_FLT_DIVIDE_BY_ZERO::Raise, "None", py::arg("theMessage"));
cls_OSD_Exception_FLT_DIVIDE_BY_ZERO.def_static("NewInstance_", (opencascade::handle<OSD_Exception_FLT_DIVIDE_BY_ZERO> (*)(const Standard_CString)) &OSD_Exception_FLT_DIVIDE_BY_ZERO::NewInstance, "None", py::arg("theMessage"));
cls_OSD_Exception_FLT_DIVIDE_BY_ZERO.def_static("get_type_name_", (const char * (*)()) &OSD_Exception_FLT_DIVIDE_BY_ZERO::get_type_name, "None");
cls_OSD_Exception_FLT_DIVIDE_BY_ZERO.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &OSD_Exception_FLT_DIVIDE_BY_ZERO::get_type_descriptor, "None");
cls_OSD_Exception_FLT_DIVIDE_BY_ZERO.def("DynamicType", (const opencascade::handle<Standard_Type> & (OSD_Exception_FLT_DIVIDE_BY_ZERO::*)() const) &OSD_Exception_FLT_DIVIDE_BY_ZERO::DynamicType, "None");

// CLASS: OSD_EXCEPTION_FLT_INEXACT_RESULT
py::class_<OSD_Exception_FLT_INEXACT_RESULT, opencascade::handle<OSD_Exception_FLT_INEXACT_RESULT>, OSD_Exception> cls_OSD_Exception_FLT_INEXACT_RESULT(mod, "OSD_Exception_FLT_INEXACT_RESULT", "None");

// Constructors
cls_OSD_Exception_FLT_INEXACT_RESULT.def(py::init<>());
cls_OSD_Exception_FLT_INEXACT_RESULT.def(py::init<const Standard_CString>(), py::arg("theMessage"));

// Methods
cls_OSD_Exception_FLT_INEXACT_RESULT.def_static("Raise_", (void (*)(const Standard_CString)) &OSD_Exception_FLT_INEXACT_RESULT::Raise, "None", py::arg("theMessage"));
cls_OSD_Exception_FLT_INEXACT_RESULT.def_static("Raise_", (void (*)(Standard_SStream &)) &OSD_Exception_FLT_INEXACT_RESULT::Raise, "None", py::arg("theMessage"));
cls_OSD_Exception_FLT_INEXACT_RESULT.def_static("NewInstance_", (opencascade::handle<OSD_Exception_FLT_INEXACT_RESULT> (*)(const Standard_CString)) &OSD_Exception_FLT_INEXACT_RESULT::NewInstance, "None", py::arg("theMessage"));
cls_OSD_Exception_FLT_INEXACT_RESULT.def_static("get_type_name_", (const char * (*)()) &OSD_Exception_FLT_INEXACT_RESULT::get_type_name, "None");
cls_OSD_Exception_FLT_INEXACT_RESULT.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &OSD_Exception_FLT_INEXACT_RESULT::get_type_descriptor, "None");
cls_OSD_Exception_FLT_INEXACT_RESULT.def("DynamicType", (const opencascade::handle<Standard_Type> & (OSD_Exception_FLT_INEXACT_RESULT::*)() const) &OSD_Exception_FLT_INEXACT_RESULT::DynamicType, "None");

// CLASS: OSD_EXCEPTION_FLT_INVALID_OPERATION
py::class_<OSD_Exception_FLT_INVALID_OPERATION, opencascade::handle<OSD_Exception_FLT_INVALID_OPERATION>, OSD_Exception> cls_OSD_Exception_FLT_INVALID_OPERATION(mod, "OSD_Exception_FLT_INVALID_OPERATION", "None");

// Constructors
cls_OSD_Exception_FLT_INVALID_OPERATION.def(py::init<>());
cls_OSD_Exception_FLT_INVALID_OPERATION.def(py::init<const Standard_CString>(), py::arg("theMessage"));

// Methods
cls_OSD_Exception_FLT_INVALID_OPERATION.def_static("Raise_", (void (*)(const Standard_CString)) &OSD_Exception_FLT_INVALID_OPERATION::Raise, "None", py::arg("theMessage"));
cls_OSD_Exception_FLT_INVALID_OPERATION.def_static("Raise_", (void (*)(Standard_SStream &)) &OSD_Exception_FLT_INVALID_OPERATION::Raise, "None", py::arg("theMessage"));
cls_OSD_Exception_FLT_INVALID_OPERATION.def_static("NewInstance_", (opencascade::handle<OSD_Exception_FLT_INVALID_OPERATION> (*)(const Standard_CString)) &OSD_Exception_FLT_INVALID_OPERATION::NewInstance, "None", py::arg("theMessage"));
cls_OSD_Exception_FLT_INVALID_OPERATION.def_static("get_type_name_", (const char * (*)()) &OSD_Exception_FLT_INVALID_OPERATION::get_type_name, "None");
cls_OSD_Exception_FLT_INVALID_OPERATION.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &OSD_Exception_FLT_INVALID_OPERATION::get_type_descriptor, "None");
cls_OSD_Exception_FLT_INVALID_OPERATION.def("DynamicType", (const opencascade::handle<Standard_Type> & (OSD_Exception_FLT_INVALID_OPERATION::*)() const) &OSD_Exception_FLT_INVALID_OPERATION::DynamicType, "None");

// CLASS: OSD_EXCEPTION_FLT_OVERFLOW
py::class_<OSD_Exception_FLT_OVERFLOW, opencascade::handle<OSD_Exception_FLT_OVERFLOW>, OSD_Exception> cls_OSD_Exception_FLT_OVERFLOW(mod, "OSD_Exception_FLT_OVERFLOW", "None");

// Constructors
cls_OSD_Exception_FLT_OVERFLOW.def(py::init<>());
cls_OSD_Exception_FLT_OVERFLOW.def(py::init<const Standard_CString>(), py::arg("theMessage"));

// Methods
cls_OSD_Exception_FLT_OVERFLOW.def_static("Raise_", (void (*)(const Standard_CString)) &OSD_Exception_FLT_OVERFLOW::Raise, "None", py::arg("theMessage"));
cls_OSD_Exception_FLT_OVERFLOW.def_static("Raise_", (void (*)(Standard_SStream &)) &OSD_Exception_FLT_OVERFLOW::Raise, "None", py::arg("theMessage"));
cls_OSD_Exception_FLT_OVERFLOW.def_static("NewInstance_", (opencascade::handle<OSD_Exception_FLT_OVERFLOW> (*)(const Standard_CString)) &OSD_Exception_FLT_OVERFLOW::NewInstance, "None", py::arg("theMessage"));
cls_OSD_Exception_FLT_OVERFLOW.def_static("get_type_name_", (const char * (*)()) &OSD_Exception_FLT_OVERFLOW::get_type_name, "None");
cls_OSD_Exception_FLT_OVERFLOW.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &OSD_Exception_FLT_OVERFLOW::get_type_descriptor, "None");
cls_OSD_Exception_FLT_OVERFLOW.def("DynamicType", (const opencascade::handle<Standard_Type> & (OSD_Exception_FLT_OVERFLOW::*)() const) &OSD_Exception_FLT_OVERFLOW::DynamicType, "None");

// CLASS: OSD_EXCEPTION_FLT_STACK_CHECK
py::class_<OSD_Exception_FLT_STACK_CHECK, opencascade::handle<OSD_Exception_FLT_STACK_CHECK>, OSD_Exception> cls_OSD_Exception_FLT_STACK_CHECK(mod, "OSD_Exception_FLT_STACK_CHECK", "None");

// Constructors
cls_OSD_Exception_FLT_STACK_CHECK.def(py::init<>());
cls_OSD_Exception_FLT_STACK_CHECK.def(py::init<const Standard_CString>(), py::arg("theMessage"));

// Methods
cls_OSD_Exception_FLT_STACK_CHECK.def_static("Raise_", (void (*)(const Standard_CString)) &OSD_Exception_FLT_STACK_CHECK::Raise, "None", py::arg("theMessage"));
cls_OSD_Exception_FLT_STACK_CHECK.def_static("Raise_", (void (*)(Standard_SStream &)) &OSD_Exception_FLT_STACK_CHECK::Raise, "None", py::arg("theMessage"));
cls_OSD_Exception_FLT_STACK_CHECK.def_static("NewInstance_", (opencascade::handle<OSD_Exception_FLT_STACK_CHECK> (*)(const Standard_CString)) &OSD_Exception_FLT_STACK_CHECK::NewInstance, "None", py::arg("theMessage"));
cls_OSD_Exception_FLT_STACK_CHECK.def_static("get_type_name_", (const char * (*)()) &OSD_Exception_FLT_STACK_CHECK::get_type_name, "None");
cls_OSD_Exception_FLT_STACK_CHECK.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &OSD_Exception_FLT_STACK_CHECK::get_type_descriptor, "None");
cls_OSD_Exception_FLT_STACK_CHECK.def("DynamicType", (const opencascade::handle<Standard_Type> & (OSD_Exception_FLT_STACK_CHECK::*)() const) &OSD_Exception_FLT_STACK_CHECK::DynamicType, "None");

// CLASS: OSD_EXCEPTION_FLT_UNDERFLOW
py::class_<OSD_Exception_FLT_UNDERFLOW, opencascade::handle<OSD_Exception_FLT_UNDERFLOW>, OSD_Exception> cls_OSD_Exception_FLT_UNDERFLOW(mod, "OSD_Exception_FLT_UNDERFLOW", "None");

// Constructors
cls_OSD_Exception_FLT_UNDERFLOW.def(py::init<>());
cls_OSD_Exception_FLT_UNDERFLOW.def(py::init<const Standard_CString>(), py::arg("theMessage"));

// Methods
cls_OSD_Exception_FLT_UNDERFLOW.def_static("Raise_", (void (*)(const Standard_CString)) &OSD_Exception_FLT_UNDERFLOW::Raise, "None", py::arg("theMessage"));
cls_OSD_Exception_FLT_UNDERFLOW.def_static("Raise_", (void (*)(Standard_SStream &)) &OSD_Exception_FLT_UNDERFLOW::Raise, "None", py::arg("theMessage"));
cls_OSD_Exception_FLT_UNDERFLOW.def_static("NewInstance_", (opencascade::handle<OSD_Exception_FLT_UNDERFLOW> (*)(const Standard_CString)) &OSD_Exception_FLT_UNDERFLOW::NewInstance, "None", py::arg("theMessage"));
cls_OSD_Exception_FLT_UNDERFLOW.def_static("get_type_name_", (const char * (*)()) &OSD_Exception_FLT_UNDERFLOW::get_type_name, "None");
cls_OSD_Exception_FLT_UNDERFLOW.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &OSD_Exception_FLT_UNDERFLOW::get_type_descriptor, "None");
cls_OSD_Exception_FLT_UNDERFLOW.def("DynamicType", (const opencascade::handle<Standard_Type> & (OSD_Exception_FLT_UNDERFLOW::*)() const) &OSD_Exception_FLT_UNDERFLOW::DynamicType, "None");

// CLASS: OSD_EXCEPTION_ILLEGAL_INSTRUCTION
py::class_<OSD_Exception_ILLEGAL_INSTRUCTION, opencascade::handle<OSD_Exception_ILLEGAL_INSTRUCTION>, OSD_Exception> cls_OSD_Exception_ILLEGAL_INSTRUCTION(mod, "OSD_Exception_ILLEGAL_INSTRUCTION", "None");

// Constructors
cls_OSD_Exception_ILLEGAL_INSTRUCTION.def(py::init<>());
cls_OSD_Exception_ILLEGAL_INSTRUCTION.def(py::init<const Standard_CString>(), py::arg("theMessage"));

// Methods
cls_OSD_Exception_ILLEGAL_INSTRUCTION.def_static("Raise_", (void (*)(const Standard_CString)) &OSD_Exception_ILLEGAL_INSTRUCTION::Raise, "None", py::arg("theMessage"));
cls_OSD_Exception_ILLEGAL_INSTRUCTION.def_static("Raise_", (void (*)(Standard_SStream &)) &OSD_Exception_ILLEGAL_INSTRUCTION::Raise, "None", py::arg("theMessage"));
cls_OSD_Exception_ILLEGAL_INSTRUCTION.def_static("NewInstance_", (opencascade::handle<OSD_Exception_ILLEGAL_INSTRUCTION> (*)(const Standard_CString)) &OSD_Exception_ILLEGAL_INSTRUCTION::NewInstance, "None", py::arg("theMessage"));
cls_OSD_Exception_ILLEGAL_INSTRUCTION.def_static("get_type_name_", (const char * (*)()) &OSD_Exception_ILLEGAL_INSTRUCTION::get_type_name, "None");
cls_OSD_Exception_ILLEGAL_INSTRUCTION.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &OSD_Exception_ILLEGAL_INSTRUCTION::get_type_descriptor, "None");
cls_OSD_Exception_ILLEGAL_INSTRUCTION.def("DynamicType", (const opencascade::handle<Standard_Type> & (OSD_Exception_ILLEGAL_INSTRUCTION::*)() const) &OSD_Exception_ILLEGAL_INSTRUCTION::DynamicType, "None");

// CLASS: OSD_EXCEPTION_INT_DIVIDE_BY_ZERO
py::class_<OSD_Exception_INT_DIVIDE_BY_ZERO, opencascade::handle<OSD_Exception_INT_DIVIDE_BY_ZERO>, OSD_Exception> cls_OSD_Exception_INT_DIVIDE_BY_ZERO(mod, "OSD_Exception_INT_DIVIDE_BY_ZERO", "None");

// Constructors
cls_OSD_Exception_INT_DIVIDE_BY_ZERO.def(py::init<>());
cls_OSD_Exception_INT_DIVIDE_BY_ZERO.def(py::init<const Standard_CString>(), py::arg("theMessage"));

// Methods
cls_OSD_Exception_INT_DIVIDE_BY_ZERO.def_static("Raise_", (void (*)(const Standard_CString)) &OSD_Exception_INT_DIVIDE_BY_ZERO::Raise, "None", py::arg("theMessage"));
cls_OSD_Exception_INT_DIVIDE_BY_ZERO.def_static("Raise_", (void (*)(Standard_SStream &)) &OSD_Exception_INT_DIVIDE_BY_ZERO::Raise, "None", py::arg("theMessage"));
cls_OSD_Exception_INT_DIVIDE_BY_ZERO.def_static("NewInstance_", (opencascade::handle<OSD_Exception_INT_DIVIDE_BY_ZERO> (*)(const Standard_CString)) &OSD_Exception_INT_DIVIDE_BY_ZERO::NewInstance, "None", py::arg("theMessage"));
cls_OSD_Exception_INT_DIVIDE_BY_ZERO.def_static("get_type_name_", (const char * (*)()) &OSD_Exception_INT_DIVIDE_BY_ZERO::get_type_name, "None");
cls_OSD_Exception_INT_DIVIDE_BY_ZERO.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &OSD_Exception_INT_DIVIDE_BY_ZERO::get_type_descriptor, "None");
cls_OSD_Exception_INT_DIVIDE_BY_ZERO.def("DynamicType", (const opencascade::handle<Standard_Type> & (OSD_Exception_INT_DIVIDE_BY_ZERO::*)() const) &OSD_Exception_INT_DIVIDE_BY_ZERO::DynamicType, "None");

// CLASS: OSD_EXCEPTION_INT_OVERFLOW
py::class_<OSD_Exception_INT_OVERFLOW, opencascade::handle<OSD_Exception_INT_OVERFLOW>, OSD_Exception> cls_OSD_Exception_INT_OVERFLOW(mod, "OSD_Exception_INT_OVERFLOW", "None");

// Constructors
cls_OSD_Exception_INT_OVERFLOW.def(py::init<>());
cls_OSD_Exception_INT_OVERFLOW.def(py::init<const Standard_CString>(), py::arg("theMessage"));

// Methods
cls_OSD_Exception_INT_OVERFLOW.def_static("Raise_", (void (*)(const Standard_CString)) &OSD_Exception_INT_OVERFLOW::Raise, "None", py::arg("theMessage"));
cls_OSD_Exception_INT_OVERFLOW.def_static("Raise_", (void (*)(Standard_SStream &)) &OSD_Exception_INT_OVERFLOW::Raise, "None", py::arg("theMessage"));
cls_OSD_Exception_INT_OVERFLOW.def_static("NewInstance_", (opencascade::handle<OSD_Exception_INT_OVERFLOW> (*)(const Standard_CString)) &OSD_Exception_INT_OVERFLOW::NewInstance, "None", py::arg("theMessage"));
cls_OSD_Exception_INT_OVERFLOW.def_static("get_type_name_", (const char * (*)()) &OSD_Exception_INT_OVERFLOW::get_type_name, "None");
cls_OSD_Exception_INT_OVERFLOW.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &OSD_Exception_INT_OVERFLOW::get_type_descriptor, "None");
cls_OSD_Exception_INT_OVERFLOW.def("DynamicType", (const opencascade::handle<Standard_Type> & (OSD_Exception_INT_OVERFLOW::*)() const) &OSD_Exception_INT_OVERFLOW::DynamicType, "None");

// CLASS: OSD_EXCEPTION_INVALID_DISPOSITION
py::class_<OSD_Exception_INVALID_DISPOSITION, opencascade::handle<OSD_Exception_INVALID_DISPOSITION>, OSD_Exception> cls_OSD_Exception_INVALID_DISPOSITION(mod, "OSD_Exception_INVALID_DISPOSITION", "None");

// Constructors
cls_OSD_Exception_INVALID_DISPOSITION.def(py::init<>());
cls_OSD_Exception_INVALID_DISPOSITION.def(py::init<const Standard_CString>(), py::arg("theMessage"));

// Methods
cls_OSD_Exception_INVALID_DISPOSITION.def_static("Raise_", (void (*)(const Standard_CString)) &OSD_Exception_INVALID_DISPOSITION::Raise, "None", py::arg("theMessage"));
cls_OSD_Exception_INVALID_DISPOSITION.def_static("Raise_", (void (*)(Standard_SStream &)) &OSD_Exception_INVALID_DISPOSITION::Raise, "None", py::arg("theMessage"));
cls_OSD_Exception_INVALID_DISPOSITION.def_static("NewInstance_", (opencascade::handle<OSD_Exception_INVALID_DISPOSITION> (*)(const Standard_CString)) &OSD_Exception_INVALID_DISPOSITION::NewInstance, "None", py::arg("theMessage"));
cls_OSD_Exception_INVALID_DISPOSITION.def_static("get_type_name_", (const char * (*)()) &OSD_Exception_INVALID_DISPOSITION::get_type_name, "None");
cls_OSD_Exception_INVALID_DISPOSITION.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &OSD_Exception_INVALID_DISPOSITION::get_type_descriptor, "None");
cls_OSD_Exception_INVALID_DISPOSITION.def("DynamicType", (const opencascade::handle<Standard_Type> & (OSD_Exception_INVALID_DISPOSITION::*)() const) &OSD_Exception_INVALID_DISPOSITION::DynamicType, "None");

// CLASS: OSD_EXCEPTION_IN_PAGE_ERROR
py::class_<OSD_Exception_IN_PAGE_ERROR, opencascade::handle<OSD_Exception_IN_PAGE_ERROR>, OSD_Exception> cls_OSD_Exception_IN_PAGE_ERROR(mod, "OSD_Exception_IN_PAGE_ERROR", "None");

// Constructors
cls_OSD_Exception_IN_PAGE_ERROR.def(py::init<>());
cls_OSD_Exception_IN_PAGE_ERROR.def(py::init<const Standard_CString>(), py::arg("theMessage"));

// Methods
cls_OSD_Exception_IN_PAGE_ERROR.def_static("Raise_", (void (*)(const Standard_CString)) &OSD_Exception_IN_PAGE_ERROR::Raise, "None", py::arg("theMessage"));
cls_OSD_Exception_IN_PAGE_ERROR.def_static("Raise_", (void (*)(Standard_SStream &)) &OSD_Exception_IN_PAGE_ERROR::Raise, "None", py::arg("theMessage"));
cls_OSD_Exception_IN_PAGE_ERROR.def_static("NewInstance_", (opencascade::handle<OSD_Exception_IN_PAGE_ERROR> (*)(const Standard_CString)) &OSD_Exception_IN_PAGE_ERROR::NewInstance, "None", py::arg("theMessage"));
cls_OSD_Exception_IN_PAGE_ERROR.def_static("get_type_name_", (const char * (*)()) &OSD_Exception_IN_PAGE_ERROR::get_type_name, "None");
cls_OSD_Exception_IN_PAGE_ERROR.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &OSD_Exception_IN_PAGE_ERROR::get_type_descriptor, "None");
cls_OSD_Exception_IN_PAGE_ERROR.def("DynamicType", (const opencascade::handle<Standard_Type> & (OSD_Exception_IN_PAGE_ERROR::*)() const) &OSD_Exception_IN_PAGE_ERROR::DynamicType, "None");

// CLASS: OSD_EXCEPTION_NONCONTINUABLE_EXCEPTION
py::class_<OSD_Exception_NONCONTINUABLE_EXCEPTION, opencascade::handle<OSD_Exception_NONCONTINUABLE_EXCEPTION>, OSD_Exception> cls_OSD_Exception_NONCONTINUABLE_EXCEPTION(mod, "OSD_Exception_NONCONTINUABLE_EXCEPTION", "None");

// Constructors
cls_OSD_Exception_NONCONTINUABLE_EXCEPTION.def(py::init<>());
cls_OSD_Exception_NONCONTINUABLE_EXCEPTION.def(py::init<const Standard_CString>(), py::arg("theMessage"));

// Methods
cls_OSD_Exception_NONCONTINUABLE_EXCEPTION.def_static("Raise_", (void (*)(const Standard_CString)) &OSD_Exception_NONCONTINUABLE_EXCEPTION::Raise, "None", py::arg("theMessage"));
cls_OSD_Exception_NONCONTINUABLE_EXCEPTION.def_static("Raise_", (void (*)(Standard_SStream &)) &OSD_Exception_NONCONTINUABLE_EXCEPTION::Raise, "None", py::arg("theMessage"));
cls_OSD_Exception_NONCONTINUABLE_EXCEPTION.def_static("NewInstance_", (opencascade::handle<OSD_Exception_NONCONTINUABLE_EXCEPTION> (*)(const Standard_CString)) &OSD_Exception_NONCONTINUABLE_EXCEPTION::NewInstance, "None", py::arg("theMessage"));
cls_OSD_Exception_NONCONTINUABLE_EXCEPTION.def_static("get_type_name_", (const char * (*)()) &OSD_Exception_NONCONTINUABLE_EXCEPTION::get_type_name, "None");
cls_OSD_Exception_NONCONTINUABLE_EXCEPTION.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &OSD_Exception_NONCONTINUABLE_EXCEPTION::get_type_descriptor, "None");
cls_OSD_Exception_NONCONTINUABLE_EXCEPTION.def("DynamicType", (const opencascade::handle<Standard_Type> & (OSD_Exception_NONCONTINUABLE_EXCEPTION::*)() const) &OSD_Exception_NONCONTINUABLE_EXCEPTION::DynamicType, "None");

// CLASS: OSD_EXCEPTION_PRIV_INSTRUCTION
py::class_<OSD_Exception_PRIV_INSTRUCTION, opencascade::handle<OSD_Exception_PRIV_INSTRUCTION>, OSD_Exception> cls_OSD_Exception_PRIV_INSTRUCTION(mod, "OSD_Exception_PRIV_INSTRUCTION", "None");

// Constructors
cls_OSD_Exception_PRIV_INSTRUCTION.def(py::init<>());
cls_OSD_Exception_PRIV_INSTRUCTION.def(py::init<const Standard_CString>(), py::arg("theMessage"));

// Methods
cls_OSD_Exception_PRIV_INSTRUCTION.def_static("Raise_", (void (*)(const Standard_CString)) &OSD_Exception_PRIV_INSTRUCTION::Raise, "None", py::arg("theMessage"));
cls_OSD_Exception_PRIV_INSTRUCTION.def_static("Raise_", (void (*)(Standard_SStream &)) &OSD_Exception_PRIV_INSTRUCTION::Raise, "None", py::arg("theMessage"));
cls_OSD_Exception_PRIV_INSTRUCTION.def_static("NewInstance_", (opencascade::handle<OSD_Exception_PRIV_INSTRUCTION> (*)(const Standard_CString)) &OSD_Exception_PRIV_INSTRUCTION::NewInstance, "None", py::arg("theMessage"));
cls_OSD_Exception_PRIV_INSTRUCTION.def_static("get_type_name_", (const char * (*)()) &OSD_Exception_PRIV_INSTRUCTION::get_type_name, "None");
cls_OSD_Exception_PRIV_INSTRUCTION.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &OSD_Exception_PRIV_INSTRUCTION::get_type_descriptor, "None");
cls_OSD_Exception_PRIV_INSTRUCTION.def("DynamicType", (const opencascade::handle<Standard_Type> & (OSD_Exception_PRIV_INSTRUCTION::*)() const) &OSD_Exception_PRIV_INSTRUCTION::DynamicType, "None");

// CLASS: OSD_EXCEPTION_STACK_OVERFLOW
py::class_<OSD_Exception_STACK_OVERFLOW, opencascade::handle<OSD_Exception_STACK_OVERFLOW>, OSD_Exception> cls_OSD_Exception_STACK_OVERFLOW(mod, "OSD_Exception_STACK_OVERFLOW", "None");

// Constructors
cls_OSD_Exception_STACK_OVERFLOW.def(py::init<>());
cls_OSD_Exception_STACK_OVERFLOW.def(py::init<const Standard_CString>(), py::arg("theMessage"));

// Methods
cls_OSD_Exception_STACK_OVERFLOW.def_static("Raise_", (void (*)(const Standard_CString)) &OSD_Exception_STACK_OVERFLOW::Raise, "None", py::arg("theMessage"));
cls_OSD_Exception_STACK_OVERFLOW.def_static("Raise_", (void (*)(Standard_SStream &)) &OSD_Exception_STACK_OVERFLOW::Raise, "None", py::arg("theMessage"));
cls_OSD_Exception_STACK_OVERFLOW.def_static("NewInstance_", (opencascade::handle<OSD_Exception_STACK_OVERFLOW> (*)(const Standard_CString)) &OSD_Exception_STACK_OVERFLOW::NewInstance, "None", py::arg("theMessage"));
cls_OSD_Exception_STACK_OVERFLOW.def_static("get_type_name_", (const char * (*)()) &OSD_Exception_STACK_OVERFLOW::get_type_name, "None");
cls_OSD_Exception_STACK_OVERFLOW.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &OSD_Exception_STACK_OVERFLOW::get_type_descriptor, "None");
cls_OSD_Exception_STACK_OVERFLOW.def("DynamicType", (const opencascade::handle<Standard_Type> & (OSD_Exception_STACK_OVERFLOW::*)() const) &OSD_Exception_STACK_OVERFLOW::DynamicType, "None");

// CLASS: OSD_EXCEPTION_STATUS_NO_MEMORY
py::class_<OSD_Exception_STATUS_NO_MEMORY, opencascade::handle<OSD_Exception_STATUS_NO_MEMORY>, OSD_Exception> cls_OSD_Exception_STATUS_NO_MEMORY(mod, "OSD_Exception_STATUS_NO_MEMORY", "None");

// Constructors
cls_OSD_Exception_STATUS_NO_MEMORY.def(py::init<>());
cls_OSD_Exception_STATUS_NO_MEMORY.def(py::init<const Standard_CString>(), py::arg("theMessage"));

// Methods
cls_OSD_Exception_STATUS_NO_MEMORY.def_static("Raise_", (void (*)(const Standard_CString)) &OSD_Exception_STATUS_NO_MEMORY::Raise, "None", py::arg("theMessage"));
cls_OSD_Exception_STATUS_NO_MEMORY.def_static("Raise_", (void (*)(Standard_SStream &)) &OSD_Exception_STATUS_NO_MEMORY::Raise, "None", py::arg("theMessage"));
cls_OSD_Exception_STATUS_NO_MEMORY.def_static("NewInstance_", (opencascade::handle<OSD_Exception_STATUS_NO_MEMORY> (*)(const Standard_CString)) &OSD_Exception_STATUS_NO_MEMORY::NewInstance, "None", py::arg("theMessage"));
cls_OSD_Exception_STATUS_NO_MEMORY.def_static("get_type_name_", (const char * (*)()) &OSD_Exception_STATUS_NO_MEMORY::get_type_name, "None");
cls_OSD_Exception_STATUS_NO_MEMORY.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &OSD_Exception_STATUS_NO_MEMORY::get_type_descriptor, "None");
cls_OSD_Exception_STATUS_NO_MEMORY.def("DynamicType", (const opencascade::handle<Standard_Type> & (OSD_Exception_STATUS_NO_MEMORY::*)() const) &OSD_Exception_STATUS_NO_MEMORY::DynamicType, "None");

// CLASS: OSD_FILE
py::class_<OSD_File, OSD_FileNode> cls_OSD_File(mod, "OSD_File", "Basic tools to manage files Warning: 'ProgramError' is raised when somebody wants to use the methods Read, Write, Seek, Close when File is not open.");

// Constructors
cls_OSD_File.def(py::init<>());
cls_OSD_File.def(py::init<const OSD_Path &>(), py::arg("Name"));

// Methods
cls_OSD_File.def("Build", (void (OSD_File::*)(const OSD_OpenMode, const OSD_Protection &)) &OSD_File::Build, "CREATES a file if it doesn't already exists or empties an existing file. After 'Build', the file is open. If no name was given, ProgramError is raised.", py::arg("Mode"), py::arg("Protect"));
cls_OSD_File.def("Open", (void (OSD_File::*)(const OSD_OpenMode, const OSD_Protection &)) &OSD_File::Open, "Opens a File with specific attributes This works only on already existing file. If no name was given, ProgramError is raised.", py::arg("Mode"), py::arg("Protect"));
cls_OSD_File.def("Append", (void (OSD_File::*)(const OSD_OpenMode, const OSD_Protection &)) &OSD_File::Append, "Appends data to an existing file. If file doesn't exist, creates it first. After 'Append', the file is open. If no name was given, ProgramError is raised.", py::arg("Mode"), py::arg("Protect"));
cls_OSD_File.def("Read", (void (OSD_File::*)(TCollection_AsciiString &, const Standard_Integer)) &OSD_File::Read, "Attempts to read Nbyte bytes from the file associated with the object file. Upon successful completion, Read returns the number of bytes actually read and placed in the Buffer. This number may be less than Nbyte if the number of bytes left in the file is less than Nbyte bytes. In this case only number of read bytes will be placed in the buffer.", py::arg("Buffer"), py::arg("Nbyte"));
cls_OSD_File.def("ReadLine", [](OSD_File &self, TCollection_AsciiString & Buffer, const Standard_Integer NByte, Standard_Integer & NbyteRead){ self.ReadLine(Buffer, NByte, NbyteRead); return NbyteRead; }, "Reads bytes from the data pointed to by the object file into the buffer <Buffer>. Data is read until <NByte-1> bytes have been read, until a newline character is read and transferred into <Buffer>, or until an EOF (End-of-File) condition is encountered. Upon successful completion, Read returns the number of bytes actually read into <NByteRead> and placed into the Buffer <Buffer>.", py::arg("Buffer"), py::arg("NByte"), py::arg("NbyteRead"));
cls_OSD_File.def("ReadLine", (Standard_Integer (OSD_File::*)(TCollection_AsciiString &, const Standard_Integer)) &OSD_File::ReadLine, "Reads bytes from the data pointed to by the object file into the buffer <Buffer>. Data is read until <NByte-1> bytes have been read, until a newline character is read and transferred into <Buffer>, or until an EOF (End-of-File) condition is encountered. Upon successful completion, Read returns the number of bytes actually read and placed into the Buffer <Buffer>.", py::arg("Buffer"), py::arg("NByte"));
cls_OSD_File.def("Read", [](OSD_File &self, const Standard_Address Buffer, const Standard_Integer Nbyte, Standard_Integer & Readbyte){ self.Read(Buffer, Nbyte, Readbyte); return Readbyte; }, "Attempts to read Nbyte bytes from the files associated with the object File. Upon successful completion, Read returns the number of bytes actually read and placed in the Buffer. This number may be less than Nbyte if the number of bytes left in the file is less than Nbyte bytes. For this reason the output parameter Readbyte will contain the number of read bytes.", py::arg("Buffer"), py::arg("Nbyte"), py::arg("Readbyte"));
cls_OSD_File.def("Write", (void (OSD_File::*)(const TCollection_AsciiString &, const Standard_Integer)) &OSD_File::Write, "Attempts to write theNbBytes bytes from the AsciiString to the file.", py::arg("theBuffer"), py::arg("theNbBytes"));
cls_OSD_File.def("Write", (void (OSD_File::*)(const Standard_Address, const Standard_Integer)) &OSD_File::Write, "Attempts to write theNbBytes bytes from the buffer pointed to by theBuffer to the file associated to the object File.", py::arg("theBuffer"), py::arg("theNbBytes"));
cls_OSD_File.def("Seek", (void (OSD_File::*)(const Standard_Integer, const OSD_FromWhere)) &OSD_File::Seek, "Sets the seek pointer associated with the open file", py::arg("Offset"), py::arg("Whence"));
cls_OSD_File.def("Close", (void (OSD_File::*)()) &OSD_File::Close, "Closes the file (and deletes a descriptor)");
cls_OSD_File.def("IsAtEnd", (Standard_Boolean (OSD_File::*)()) &OSD_File::IsAtEnd, "Returns TRUE if the seek pointer is at end of file.");
cls_OSD_File.def("KindOfFile", (OSD_KindFile (OSD_File::*)() const) &OSD_File::KindOfFile, "Returns the kind of file. A file can be a file, a directory or a link.");
cls_OSD_File.def("BuildTemporary", (void (OSD_File::*)()) &OSD_File::BuildTemporary, "Makes a temporary File This temporary file is already open !");
cls_OSD_File.def("SetLock", (void (OSD_File::*)(const OSD_LockType)) &OSD_File::SetLock, "Locks current file", py::arg("Lock"));
cls_OSD_File.def("UnLock", (void (OSD_File::*)()) &OSD_File::UnLock, "Unlocks current file");
cls_OSD_File.def("GetLock", (OSD_LockType (OSD_File::*)() const) &OSD_File::GetLock, "Returns the current lock state");
cls_OSD_File.def("IsLocked", (Standard_Boolean (OSD_File::*)() const) &OSD_File::IsLocked, "Returns TRUE if this file is locked.");
cls_OSD_File.def("Size", (Standard_Size (OSD_File::*)()) &OSD_File::Size, "Returns actual number of bytes of <me>.");
cls_OSD_File.def("IsOpen", (Standard_Boolean (OSD_File::*)() const) &OSD_File::IsOpen, "Returns TRUE if <me> is open.");
cls_OSD_File.def("IsReadable", (Standard_Boolean (OSD_File::*)()) &OSD_File::IsReadable, "returns TRUE if the file exists and if the user has the autorization to read it.");
cls_OSD_File.def("IsWriteable", (Standard_Boolean (OSD_File::*)()) &OSD_File::IsWriteable, "returns TRUE if the file can be read and overwritten.");
cls_OSD_File.def("IsExecutable", (Standard_Boolean (OSD_File::*)()) &OSD_File::IsExecutable, "returns TRUE if the file can be executed.");
cls_OSD_File.def("ReadLastLine", (Standard_Boolean (OSD_File::*)(TCollection_AsciiString &, const Standard_Integer, const Standard_Integer)) &OSD_File::ReadLastLine, "Enables to emulate unix 'tail -f' command. If a line is available in the file <me> returns it. Otherwise attemps to read again aNbTries times in the file waiting aDelay seconds between each read. If meanwhile the file increases returns the next line, otherwise returns FALSE.", py::arg("aLine"), py::arg("aDelay"), py::arg("aNbTries"));
cls_OSD_File.def("Edit", (Standard_Boolean (OSD_File::*)()) &OSD_File::Edit, "find an editor on the system and edit the given file");
cls_OSD_File.def("Rewind", (void (OSD_File::*)()) &OSD_File::Rewind, "Set file pointer position to the beginning of the file");

// CLASS: OSD_FILEITERATOR
py::class_<OSD_FileIterator> cls_OSD_FileIterator(mod, "OSD_FileIterator", "Manages a breadth-only search for files in the specified Path. There is no specific order of results.");

// Constructors
cls_OSD_FileIterator.def(py::init<>());
cls_OSD_FileIterator.def(py::init<const OSD_Path &, const TCollection_AsciiString &>(), py::arg("where"), py::arg("Mask"));

// Methods
// cls_OSD_FileIterator.def_static("operator new_", (void * (*)(size_t)) &OSD_FileIterator::operator new, "None", py::arg("theSize"));
// cls_OSD_FileIterator.def_static("operator delete_", (void (*)(void *)) &OSD_FileIterator::operator delete, "None", py::arg("theAddress"));
// cls_OSD_FileIterator.def_static("operator new[]_", (void * (*)(size_t)) &OSD_FileIterator::operator new[], "None", py::arg("theSize"));
// cls_OSD_FileIterator.def_static("operator delete[]_", (void (*)(void *)) &OSD_FileIterator::operator delete[], "None", py::arg("theAddress"));
// cls_OSD_FileIterator.def_static("operator new_", (void * (*)(size_t, void *)) &OSD_FileIterator::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_OSD_FileIterator.def_static("operator delete_", (void (*)(void *, void *)) &OSD_FileIterator::operator delete, "None", py::arg(""), py::arg(""));
cls_OSD_FileIterator.def("Destroy", (void (OSD_FileIterator::*)()) &OSD_FileIterator::Destroy, "None");
cls_OSD_FileIterator.def("Initialize", (void (OSD_FileIterator::*)(const OSD_Path &, const TCollection_AsciiString &)) &OSD_FileIterator::Initialize, "Initializes the current File Iterator", py::arg("where"), py::arg("Mask"));
cls_OSD_FileIterator.def("More", (Standard_Boolean (OSD_FileIterator::*)()) &OSD_FileIterator::More, "Returns TRUE if there are other items using the 'Tree' method.");
cls_OSD_FileIterator.def("Next", (void (OSD_FileIterator::*)()) &OSD_FileIterator::Next, "Sets the iterator to the next item. Returns the item value corresponding to the current position of the iterator.");
cls_OSD_FileIterator.def("Values", (OSD_File (OSD_FileIterator::*)()) &OSD_FileIterator::Values, "Returns the next file found .");
cls_OSD_FileIterator.def("Failed", (Standard_Boolean (OSD_FileIterator::*)() const) &OSD_FileIterator::Failed, "Returns TRUE if an error occurs");
cls_OSD_FileIterator.def("Reset", (void (OSD_FileIterator::*)()) &OSD_FileIterator::Reset, "Resets error counter to zero");
cls_OSD_FileIterator.def("Perror", (void (OSD_FileIterator::*)()) &OSD_FileIterator::Perror, "Raises OSD_Error");
cls_OSD_FileIterator.def("Error", (Standard_Integer (OSD_FileIterator::*)() const) &OSD_FileIterator::Error, "Returns error number if 'Failed' is TRUE.");

// CLASS: OSD_HOST
py::class_<OSD_Host> cls_OSD_Host(mod, "OSD_Host", "Carries information about a Host System version ,host name, nodename ...");

// Constructors
cls_OSD_Host.def(py::init<>());

// Methods
// cls_OSD_Host.def_static("operator new_", (void * (*)(size_t)) &OSD_Host::operator new, "None", py::arg("theSize"));
// cls_OSD_Host.def_static("operator delete_", (void (*)(void *)) &OSD_Host::operator delete, "None", py::arg("theAddress"));
// cls_OSD_Host.def_static("operator new[]_", (void * (*)(size_t)) &OSD_Host::operator new[], "None", py::arg("theSize"));
// cls_OSD_Host.def_static("operator delete[]_", (void (*)(void *)) &OSD_Host::operator delete[], "None", py::arg("theAddress"));
// cls_OSD_Host.def_static("operator new_", (void * (*)(size_t, void *)) &OSD_Host::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_OSD_Host.def_static("operator delete_", (void (*)(void *, void *)) &OSD_Host::operator delete, "None", py::arg(""), py::arg(""));
cls_OSD_Host.def("SystemVersion", (TCollection_AsciiString (OSD_Host::*)()) &OSD_Host::SystemVersion, "Returns system name and version");
cls_OSD_Host.def("SystemId", (OSD_SysType (OSD_Host::*)() const) &OSD_Host::SystemId, "Returns the system type (UNIX System V, UNIX BSD, MS-DOS...)");
cls_OSD_Host.def("HostName", (TCollection_AsciiString (OSD_Host::*)()) &OSD_Host::HostName, "Returns host name.");
cls_OSD_Host.def("AvailableMemory", (Standard_Integer (OSD_Host::*)()) &OSD_Host::AvailableMemory, "Returns available memory in Kilobytes.");
cls_OSD_Host.def("InternetAddress", (TCollection_AsciiString (OSD_Host::*)()) &OSD_Host::InternetAddress, "Returns Internet address of current host.");
cls_OSD_Host.def("MachineType", (OSD_OEMType (OSD_Host::*)()) &OSD_Host::MachineType, "Returns type of current machine.");
cls_OSD_Host.def("Failed", (Standard_Boolean (OSD_Host::*)() const) &OSD_Host::Failed, "Returns TRUE if an error occurs");
cls_OSD_Host.def("Reset", (void (OSD_Host::*)()) &OSD_Host::Reset, "Resets error counter to zero");
cls_OSD_Host.def("Perror", (void (OSD_Host::*)()) &OSD_Host::Perror, "Raises OSD_Error");
cls_OSD_Host.def("Error", (Standard_Integer (OSD_Host::*)() const) &OSD_Host::Error, "Returns error number if 'Failed' is TRUE.");

// CLASS: OSD_MALLOCHOOK
py::class_<OSD_MAllocHook> cls_OSD_MAllocHook(mod, "OSD_MAllocHook", "This class provides the possibility to set callback for memory allocation/deallocation. On MS Windows, it works only in Debug builds. It relies on the debug CRT function _CrtSetAllocHook (see MSDN for help).");

// Methods
cls_OSD_MAllocHook.def_static("SetCallback_", (void (*)(OSD_MAllocHook::Callback *)) &OSD_MAllocHook::SetCallback, "Set handler of allocation/deallocation events", py::arg("theCB"));
cls_OSD_MAllocHook.def_static("GetCallback_", (OSD_MAllocHook::Callback * (*)()) &OSD_MAllocHook::GetCallback, "Get current handler of allocation/deallocation events");
cls_OSD_MAllocHook.def_static("GetLogFileHandler_", (OSD_MAllocHook::LogFileHandler * (*)()) &OSD_MAllocHook::GetLogFileHandler, "Get static instance of LogFileHandler handler");
cls_OSD_MAllocHook.def_static("GetCollectBySize_", (OSD_MAllocHook::CollectBySize * (*)()) &OSD_MAllocHook::GetCollectBySize, "Get static instance of CollectBySize handler");

// CLASS: OSD_MEMINFO
py::class_<OSD_MemInfo> cls_OSD_MemInfo(mod, "OSD_MemInfo", "This class provide information about memory utilized by current process. This information includes: - Private Memory - synthetic value that tries to filter out the memory usage only by the process itself (allocated for data and stack), excluding dynamic libraries. These pages may be in RAM or in SWAP. - Virtual Memory - amount of reserved and committed memory in the user-mode portion of the virtual address space. Notice that this counter includes reserved memory (not yet in used) and shared between processes memory (libraries). - Working Set - set of memory pages in the virtual address space of the process that are currently resident in physical memory (RAM). These pages are available for an application to use without triggering a page fault. - Pagefile Usage - space allocated for the pagefile, in bytes. Those pages may or may not be in memory (RAM) thus this counter couldn't be used to estimate how many active pages doesn't present in RAM.");

// Constructors
cls_OSD_MemInfo.def(py::init<>());
cls_OSD_MemInfo.def(py::init<const Standard_Boolean>(), py::arg("theImmediateUpdate"));

// Methods
cls_OSD_MemInfo.def("Clear", (void (OSD_MemInfo::*)()) &OSD_MemInfo::Clear, "Clear counters");
cls_OSD_MemInfo.def("Update", (void (OSD_MemInfo::*)()) &OSD_MemInfo::Update, "Update counters");
cls_OSD_MemInfo.def("ToString", (TCollection_AsciiString (OSD_MemInfo::*)() const) &OSD_MemInfo::ToString, "Return the string representation for all available counter.");
cls_OSD_MemInfo.def("Value", (Standard_Size (OSD_MemInfo::*)(const OSD_MemInfo::Counter) const) &OSD_MemInfo::Value, "Return value of specified counter in bytes. Notice that NOT all counters are available on various systems. Standard_Size(-1) means invalid (unavailable) value.", py::arg("theCounter"));
cls_OSD_MemInfo.def("ValueMiB", (Standard_Size (OSD_MemInfo::*)(const OSD_MemInfo::Counter) const) &OSD_MemInfo::ValueMiB, "Return value of specified counter in MiB. Notice that NOT all counters are available on various systems. Standard_Size(-1) means invalid (unavailable) value.", py::arg("theCounter"));
cls_OSD_MemInfo.def("ValuePreciseMiB", (Standard_Real (OSD_MemInfo::*)(const OSD_MemInfo::Counter) const) &OSD_MemInfo::ValuePreciseMiB, "Return floating value of specified counter in MiB. Notice that NOT all counters are available on various systems. Standard_Real(-1) means invalid (unavailable) value.", py::arg("theCounter"));
cls_OSD_MemInfo.def_static("PrintInfo_", (TCollection_AsciiString (*)()) &OSD_MemInfo::PrintInfo, "Return the string representation for all available counter.");

// Enums
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

// CLASS: OSD_OSDERROR
py::class_<OSD_OSDError, opencascade::handle<OSD_OSDError>, Standard_Failure> cls_OSD_OSDError(mod, "OSD_OSDError", "None");

// Constructors
cls_OSD_OSDError.def(py::init<>());
cls_OSD_OSDError.def(py::init<const Standard_CString>(), py::arg("theMessage"));

// Methods
cls_OSD_OSDError.def_static("Raise_", (void (*)(const Standard_CString)) &OSD_OSDError::Raise, "None", py::arg("theMessage"));
cls_OSD_OSDError.def_static("Raise_", (void (*)(Standard_SStream &)) &OSD_OSDError::Raise, "None", py::arg("theMessage"));
cls_OSD_OSDError.def_static("NewInstance_", (opencascade::handle<OSD_OSDError> (*)(const Standard_CString)) &OSD_OSDError::NewInstance, "None", py::arg("theMessage"));
cls_OSD_OSDError.def_static("get_type_name_", (const char * (*)()) &OSD_OSDError::get_type_name, "None");
cls_OSD_OSDError.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &OSD_OSDError::get_type_descriptor, "None");
cls_OSD_OSDError.def("DynamicType", (const opencascade::handle<Standard_Type> & (OSD_OSDError::*)() const) &OSD_OSDError::DynamicType, "None");

// CLASS: OSD_PERFMETER
py::class_<OSD_PerfMeter> cls_OSD_PerfMeter(mod, "OSD_PerfMeter", "This class enables measuring the CPU time between two points of code execution, regardless of the scope of these points of code. A meter is identified by its name (string). So multiple objects in various places of user code may point to the same meter. The results will be printed on stdout upon finish of the program. For details see OSD_PerfMeter.h");

// Constructors
cls_OSD_PerfMeter.def(py::init<>());
cls_OSD_PerfMeter.def(py::init<const char *>(), py::arg("theMeter"));
cls_OSD_PerfMeter.def(py::init<const char *, const bool>(), py::arg("theMeter"), py::arg("theToAutoStart"));

// Methods
cls_OSD_PerfMeter.def("Init", (void (OSD_PerfMeter::*)(const char *)) &OSD_PerfMeter::Init, "Prepares the named meter", py::arg("theMeter"));
cls_OSD_PerfMeter.def("Start", (void (OSD_PerfMeter::*)() const) &OSD_PerfMeter::Start, "Starts the meter");
cls_OSD_PerfMeter.def("Stop", (void (OSD_PerfMeter::*)() const) &OSD_PerfMeter::Stop, "Stops the meter");
cls_OSD_PerfMeter.def("Tick", (void (OSD_PerfMeter::*)() const) &OSD_PerfMeter::Tick, "Increments the counter w/o time measurement");
cls_OSD_PerfMeter.def("Flush", (void (OSD_PerfMeter::*)() const) &OSD_PerfMeter::Flush, "Outputs the meter data and resets it to initial state");

// CLASS: OSD_PROCESS
py::class_<OSD_Process> cls_OSD_Process(mod, "OSD_Process", "A set of system process tools");

// Constructors
cls_OSD_Process.def(py::init<>());

// Methods
cls_OSD_Process.def_static("ExecutablePath_", (TCollection_AsciiString (*)()) &OSD_Process::ExecutablePath, "Return full path to the current process executable.");
cls_OSD_Process.def_static("ExecutableFolder_", (TCollection_AsciiString (*)()) &OSD_Process::ExecutableFolder, "Return full path to the folder containing current process executable with trailing separator.");
// cls_OSD_Process.def_static("operator new_", (void * (*)(size_t)) &OSD_Process::operator new, "None", py::arg("theSize"));
// cls_OSD_Process.def_static("operator delete_", (void (*)(void *)) &OSD_Process::operator delete, "None", py::arg("theAddress"));
// cls_OSD_Process.def_static("operator new[]_", (void * (*)(size_t)) &OSD_Process::operator new[], "None", py::arg("theSize"));
// cls_OSD_Process.def_static("operator delete[]_", (void (*)(void *)) &OSD_Process::operator delete[], "None", py::arg("theAddress"));
// cls_OSD_Process.def_static("operator new_", (void * (*)(size_t, void *)) &OSD_Process::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_OSD_Process.def_static("operator delete_", (void (*)(void *, void *)) &OSD_Process::operator delete, "None", py::arg(""), py::arg(""));
cls_OSD_Process.def("TerminalType", (void (OSD_Process::*)(TCollection_AsciiString &)) &OSD_Process::TerminalType, "Returns the terminal used (vt100, vt200 ,sun-cmd ...)", py::arg("Name"));
cls_OSD_Process.def("SystemDate", (Quantity_Date (OSD_Process::*)()) &OSD_Process::SystemDate, "Gets system date.");
cls_OSD_Process.def("UserName", (TCollection_AsciiString (OSD_Process::*)()) &OSD_Process::UserName, "Returns the user name.");
cls_OSD_Process.def("IsSuperUser", (Standard_Boolean (OSD_Process::*)()) &OSD_Process::IsSuperUser, "Returns True if the process user is the super-user.");
cls_OSD_Process.def("ProcessId", (Standard_Integer (OSD_Process::*)()) &OSD_Process::ProcessId, "Returns the 'Process Id'");
cls_OSD_Process.def("CurrentDirectory", (OSD_Path (OSD_Process::*)()) &OSD_Process::CurrentDirectory, "Returns the current path where the process is.");
cls_OSD_Process.def("SetCurrentDirectory", (void (OSD_Process::*)(const OSD_Path &)) &OSD_Process::SetCurrentDirectory, "Changes the current process directory.", py::arg("where"));
cls_OSD_Process.def("Failed", (Standard_Boolean (OSD_Process::*)() const) &OSD_Process::Failed, "Returns TRUE if an error occurs");
cls_OSD_Process.def("Reset", (void (OSD_Process::*)()) &OSD_Process::Reset, "Resets error counter to zero");
cls_OSD_Process.def("Perror", (void (OSD_Process::*)()) &OSD_Process::Perror, "Raises OSD_Error");
cls_OSD_Process.def("Error", (Standard_Integer (OSD_Process::*)() const) &OSD_Process::Error, "Returns error number if 'Failed' is TRUE.");

// CLASS: OSD_PROTECTION
py::class_<OSD_Protection> cls_OSD_Protection(mod, "OSD_Protection", "This class provides data to manage file protection Example:These rights are treated in a system dependent manner : On UNIX you have User,Group and Other rights On VMS you have Owner,Group,World and System rights An automatic conversion is done between OSD and UNIX/VMS.");

// Constructors
cls_OSD_Protection.def(py::init<>());
cls_OSD_Protection.def(py::init<const OSD_SingleProtection, const OSD_SingleProtection, const OSD_SingleProtection, const OSD_SingleProtection>(), py::arg("System"), py::arg("User"), py::arg("Group"), py::arg("World"));

// Methods
// cls_OSD_Protection.def_static("operator new_", (void * (*)(size_t)) &OSD_Protection::operator new, "None", py::arg("theSize"));
// cls_OSD_Protection.def_static("operator delete_", (void (*)(void *)) &OSD_Protection::operator delete, "None", py::arg("theAddress"));
// cls_OSD_Protection.def_static("operator new[]_", (void * (*)(size_t)) &OSD_Protection::operator new[], "None", py::arg("theSize"));
// cls_OSD_Protection.def_static("operator delete[]_", (void (*)(void *)) &OSD_Protection::operator delete[], "None", py::arg("theAddress"));
// cls_OSD_Protection.def_static("operator new_", (void * (*)(size_t, void *)) &OSD_Protection::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_OSD_Protection.def_static("operator delete_", (void (*)(void *, void *)) &OSD_Protection::operator delete, "None", py::arg(""), py::arg(""));
cls_OSD_Protection.def("Values", (void (OSD_Protection::*)(OSD_SingleProtection &, OSD_SingleProtection &, OSD_SingleProtection &, OSD_SingleProtection &)) &OSD_Protection::Values, "Retrieves values of fields", py::arg("System"), py::arg("User"), py::arg("Group"), py::arg("World"));
cls_OSD_Protection.def("SetValues", (void (OSD_Protection::*)(const OSD_SingleProtection, const OSD_SingleProtection, const OSD_SingleProtection, const OSD_SingleProtection)) &OSD_Protection::SetValues, "Sets values of fields", py::arg("System"), py::arg("User"), py::arg("Group"), py::arg("World"));
cls_OSD_Protection.def("SetSystem", (void (OSD_Protection::*)(const OSD_SingleProtection)) &OSD_Protection::SetSystem, "Sets protection of 'System'", py::arg("priv"));
cls_OSD_Protection.def("SetUser", (void (OSD_Protection::*)(const OSD_SingleProtection)) &OSD_Protection::SetUser, "Sets protection of 'User'", py::arg("priv"));
cls_OSD_Protection.def("SetGroup", (void (OSD_Protection::*)(const OSD_SingleProtection)) &OSD_Protection::SetGroup, "Sets protection of 'Group'", py::arg("priv"));
cls_OSD_Protection.def("SetWorld", (void (OSD_Protection::*)(const OSD_SingleProtection)) &OSD_Protection::SetWorld, "Sets protection of 'World'", py::arg("priv"));
cls_OSD_Protection.def("System", (OSD_SingleProtection (OSD_Protection::*)() const) &OSD_Protection::System, "Gets protection of 'System'");
cls_OSD_Protection.def("User", (OSD_SingleProtection (OSD_Protection::*)() const) &OSD_Protection::User, "Gets protection of 'User'");
cls_OSD_Protection.def("Group", (OSD_SingleProtection (OSD_Protection::*)() const) &OSD_Protection::Group, "Gets protection of 'Group'");
cls_OSD_Protection.def("World", (OSD_SingleProtection (OSD_Protection::*)() const) &OSD_Protection::World, "Gets protection of 'World'");
cls_OSD_Protection.def("Add", (void (OSD_Protection::*)(OSD_SingleProtection &, const OSD_SingleProtection)) &OSD_Protection::Add, "Add a right to a single protection. ex: aProt = RWD me.Add(aProt,X) -> aProt = RWXD", py::arg("aProt"), py::arg("aRight"));
cls_OSD_Protection.def("Sub", (void (OSD_Protection::*)(OSD_SingleProtection &, const OSD_SingleProtection)) &OSD_Protection::Sub, "Subtract a right to a single protection. ex: aProt = RWD me.Sub(aProt,RW) -> aProt = D But me.Sub(aProt,RWX) is also valid and gives same result.", py::arg("aProt"), py::arg("aRight"));

// CLASS: OSD_SHAREDLIBRARY
py::class_<OSD_SharedLibrary> cls_OSD_SharedLibrary(mod, "OSD_SharedLibrary", "Interface to dynamic library loader. Provides tools to load a shared library and retrieve the address of an entry point.");

// Constructors
cls_OSD_SharedLibrary.def(py::init<>());
cls_OSD_SharedLibrary.def(py::init<const Standard_CString>(), py::arg("aFilename"));

// Methods
// cls_OSD_SharedLibrary.def_static("operator new_", (void * (*)(size_t)) &OSD_SharedLibrary::operator new, "None", py::arg("theSize"));
// cls_OSD_SharedLibrary.def_static("operator delete_", (void (*)(void *)) &OSD_SharedLibrary::operator delete, "None", py::arg("theAddress"));
// cls_OSD_SharedLibrary.def_static("operator new[]_", (void * (*)(size_t)) &OSD_SharedLibrary::operator new[], "None", py::arg("theSize"));
// cls_OSD_SharedLibrary.def_static("operator delete[]_", (void (*)(void *)) &OSD_SharedLibrary::operator delete[], "None", py::arg("theAddress"));
// cls_OSD_SharedLibrary.def_static("operator new_", (void * (*)(size_t, void *)) &OSD_SharedLibrary::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_OSD_SharedLibrary.def_static("operator delete_", (void (*)(void *, void *)) &OSD_SharedLibrary::operator delete, "None", py::arg(""), py::arg(""));
cls_OSD_SharedLibrary.def("SetName", (void (OSD_SharedLibrary::*)(const Standard_CString)) &OSD_SharedLibrary::SetName, "Sets a name associated to the shared object.", py::arg("aName"));
cls_OSD_SharedLibrary.def("Name", (Standard_CString (OSD_SharedLibrary::*)() const) &OSD_SharedLibrary::Name, "Returns the name associated to the shared object.");
cls_OSD_SharedLibrary.def("DlOpen", (Standard_Boolean (OSD_SharedLibrary::*)(const OSD_LoadMode)) &OSD_SharedLibrary::DlOpen, "The DlOpen method provides an interface to the dynamic library loader to allow shared libraries to be loaded and called at runtime. The DlOpen function attempts to load Filename, in the address space of the process, resolving symbols as appropriate. Any libraries that Filename depends upon are also loaded. If MODE is RTLD_LAZY, then the runtime loader does symbol resolution only as needed. Typically, this means that the first call to a function in the newly loaded library will cause the resolution of the address of that function to occur. If Mode is RTLD_NOW, then the runtime loader must do all symbol binding during the DlOpen call. The DlOpen method returns a handle that is used by DlSym or DlClose. If there is an error, Standard_False is returned, Standard_True otherwise. If a NULL Filename is specified, DlOpen returns a handle for the main executable, which allows access to dynamic symbols in the running program.", py::arg("Mode"));
cls_OSD_SharedLibrary.def("DlSymb", (OSD_Function (OSD_SharedLibrary::*)(const Standard_CString) const) &OSD_SharedLibrary::DlSymb, "The dlsym function returns the address of the symbol name found in the shared library. If the symbol is not found, a NULL pointer is returned.", py::arg("Name"));
cls_OSD_SharedLibrary.def("DlClose", (void (OSD_SharedLibrary::*)() const) &OSD_SharedLibrary::DlClose, "Deallocates the address space for the library corresponding to the shared object. If any user function continues to call a symbol resolved in the address space of a library that has been since been deallocated by DlClose, the results are undefined.");
cls_OSD_SharedLibrary.def("DlError", (Standard_CString (OSD_SharedLibrary::*)() const) &OSD_SharedLibrary::DlError, "The dlerror function returns a string describing the last error that occurred from a call to DlOpen, DlClose or DlSym.");
cls_OSD_SharedLibrary.def("Destroy", (void (OSD_SharedLibrary::*)()) &OSD_SharedLibrary::Destroy, "Frees memory allocated.");

// CLASS: OSD_SIGNAL
py::class_<OSD_Signal, opencascade::handle<OSD_Signal>, Standard_Failure> cls_OSD_Signal(mod, "OSD_Signal", "None");

// Constructors
cls_OSD_Signal.def(py::init<>());
cls_OSD_Signal.def(py::init<const Standard_CString>(), py::arg("theMessage"));

// Methods
cls_OSD_Signal.def_static("Raise_", (void (*)(const Standard_CString)) &OSD_Signal::Raise, "None", py::arg("theMessage"));
cls_OSD_Signal.def_static("Raise_", (void (*)(Standard_SStream &)) &OSD_Signal::Raise, "None", py::arg("theMessage"));
cls_OSD_Signal.def_static("NewInstance_", (opencascade::handle<OSD_Signal> (*)(const Standard_CString)) &OSD_Signal::NewInstance, "None", py::arg("theMessage"));
cls_OSD_Signal.def_static("get_type_name_", (const char * (*)()) &OSD_Signal::get_type_name, "None");
cls_OSD_Signal.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &OSD_Signal::get_type_descriptor, "None");
cls_OSD_Signal.def("DynamicType", (const opencascade::handle<Standard_Type> & (OSD_Signal::*)() const) &OSD_Signal::DynamicType, "None");

// CLASS: OSD_SIGBUS
py::class_<OSD_SIGBUS, opencascade::handle<OSD_SIGBUS>, OSD_Signal> cls_OSD_SIGBUS(mod, "OSD_SIGBUS", "None");

// Constructors
cls_OSD_SIGBUS.def(py::init<>());
cls_OSD_SIGBUS.def(py::init<const Standard_CString>(), py::arg("theMessage"));

// Methods
cls_OSD_SIGBUS.def_static("Raise_", (void (*)(const Standard_CString)) &OSD_SIGBUS::Raise, "None", py::arg("theMessage"));
cls_OSD_SIGBUS.def_static("Raise_", (void (*)(Standard_SStream &)) &OSD_SIGBUS::Raise, "None", py::arg("theMessage"));
cls_OSD_SIGBUS.def_static("NewInstance_", (opencascade::handle<OSD_SIGBUS> (*)(const Standard_CString)) &OSD_SIGBUS::NewInstance, "None", py::arg("theMessage"));
cls_OSD_SIGBUS.def_static("get_type_name_", (const char * (*)()) &OSD_SIGBUS::get_type_name, "None");
cls_OSD_SIGBUS.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &OSD_SIGBUS::get_type_descriptor, "None");
cls_OSD_SIGBUS.def("DynamicType", (const opencascade::handle<Standard_Type> & (OSD_SIGBUS::*)() const) &OSD_SIGBUS::DynamicType, "None");

// CLASS: OSD_SIGHUP
py::class_<OSD_SIGHUP, opencascade::handle<OSD_SIGHUP>, OSD_Signal> cls_OSD_SIGHUP(mod, "OSD_SIGHUP", "None");

// Constructors
cls_OSD_SIGHUP.def(py::init<>());
cls_OSD_SIGHUP.def(py::init<const Standard_CString>(), py::arg("theMessage"));

// Methods
cls_OSD_SIGHUP.def_static("Raise_", (void (*)(const Standard_CString)) &OSD_SIGHUP::Raise, "None", py::arg("theMessage"));
cls_OSD_SIGHUP.def_static("Raise_", (void (*)(Standard_SStream &)) &OSD_SIGHUP::Raise, "None", py::arg("theMessage"));
cls_OSD_SIGHUP.def_static("NewInstance_", (opencascade::handle<OSD_SIGHUP> (*)(const Standard_CString)) &OSD_SIGHUP::NewInstance, "None", py::arg("theMessage"));
cls_OSD_SIGHUP.def_static("get_type_name_", (const char * (*)()) &OSD_SIGHUP::get_type_name, "None");
cls_OSD_SIGHUP.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &OSD_SIGHUP::get_type_descriptor, "None");
cls_OSD_SIGHUP.def("DynamicType", (const opencascade::handle<Standard_Type> & (OSD_SIGHUP::*)() const) &OSD_SIGHUP::DynamicType, "None");

// CLASS: OSD_SIGILL
py::class_<OSD_SIGILL, opencascade::handle<OSD_SIGILL>, OSD_Signal> cls_OSD_SIGILL(mod, "OSD_SIGILL", "None");

// Constructors
cls_OSD_SIGILL.def(py::init<>());
cls_OSD_SIGILL.def(py::init<const Standard_CString>(), py::arg("theMessage"));

// Methods
cls_OSD_SIGILL.def_static("Raise_", (void (*)(const Standard_CString)) &OSD_SIGILL::Raise, "None", py::arg("theMessage"));
cls_OSD_SIGILL.def_static("Raise_", (void (*)(Standard_SStream &)) &OSD_SIGILL::Raise, "None", py::arg("theMessage"));
cls_OSD_SIGILL.def_static("NewInstance_", (opencascade::handle<OSD_SIGILL> (*)(const Standard_CString)) &OSD_SIGILL::NewInstance, "None", py::arg("theMessage"));
cls_OSD_SIGILL.def_static("get_type_name_", (const char * (*)()) &OSD_SIGILL::get_type_name, "None");
cls_OSD_SIGILL.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &OSD_SIGILL::get_type_descriptor, "None");
cls_OSD_SIGILL.def("DynamicType", (const opencascade::handle<Standard_Type> & (OSD_SIGILL::*)() const) &OSD_SIGILL::DynamicType, "None");

// CLASS: OSD_SIGINT
py::class_<OSD_SIGINT, opencascade::handle<OSD_SIGINT>, OSD_Signal> cls_OSD_SIGINT(mod, "OSD_SIGINT", "None");

// Constructors
cls_OSD_SIGINT.def(py::init<>());
cls_OSD_SIGINT.def(py::init<const Standard_CString>(), py::arg("theMessage"));

// Methods
cls_OSD_SIGINT.def_static("Raise_", (void (*)(const Standard_CString)) &OSD_SIGINT::Raise, "None", py::arg("theMessage"));
cls_OSD_SIGINT.def_static("Raise_", (void (*)(Standard_SStream &)) &OSD_SIGINT::Raise, "None", py::arg("theMessage"));
cls_OSD_SIGINT.def_static("NewInstance_", (opencascade::handle<OSD_SIGINT> (*)(const Standard_CString)) &OSD_SIGINT::NewInstance, "None", py::arg("theMessage"));
cls_OSD_SIGINT.def_static("get_type_name_", (const char * (*)()) &OSD_SIGINT::get_type_name, "None");
cls_OSD_SIGINT.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &OSD_SIGINT::get_type_descriptor, "None");
cls_OSD_SIGINT.def("DynamicType", (const opencascade::handle<Standard_Type> & (OSD_SIGINT::*)() const) &OSD_SIGINT::DynamicType, "None");

// CLASS: OSD_SIGKILL
py::class_<OSD_SIGKILL, opencascade::handle<OSD_SIGKILL>, OSD_Signal> cls_OSD_SIGKILL(mod, "OSD_SIGKILL", "None");

// Constructors
cls_OSD_SIGKILL.def(py::init<>());
cls_OSD_SIGKILL.def(py::init<const Standard_CString>(), py::arg("theMessage"));

// Methods
cls_OSD_SIGKILL.def_static("Raise_", (void (*)(const Standard_CString)) &OSD_SIGKILL::Raise, "None", py::arg("theMessage"));
cls_OSD_SIGKILL.def_static("Raise_", (void (*)(Standard_SStream &)) &OSD_SIGKILL::Raise, "None", py::arg("theMessage"));
cls_OSD_SIGKILL.def_static("NewInstance_", (opencascade::handle<OSD_SIGKILL> (*)(const Standard_CString)) &OSD_SIGKILL::NewInstance, "None", py::arg("theMessage"));
cls_OSD_SIGKILL.def_static("get_type_name_", (const char * (*)()) &OSD_SIGKILL::get_type_name, "None");
cls_OSD_SIGKILL.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &OSD_SIGKILL::get_type_descriptor, "None");
cls_OSD_SIGKILL.def("DynamicType", (const opencascade::handle<Standard_Type> & (OSD_SIGKILL::*)() const) &OSD_SIGKILL::DynamicType, "None");

// CLASS: OSD_SIGQUIT
py::class_<OSD_SIGQUIT, opencascade::handle<OSD_SIGQUIT>, OSD_Signal> cls_OSD_SIGQUIT(mod, "OSD_SIGQUIT", "None");

// Constructors
cls_OSD_SIGQUIT.def(py::init<>());
cls_OSD_SIGQUIT.def(py::init<const Standard_CString>(), py::arg("theMessage"));

// Methods
cls_OSD_SIGQUIT.def_static("Raise_", (void (*)(const Standard_CString)) &OSD_SIGQUIT::Raise, "None", py::arg("theMessage"));
cls_OSD_SIGQUIT.def_static("Raise_", (void (*)(Standard_SStream &)) &OSD_SIGQUIT::Raise, "None", py::arg("theMessage"));
cls_OSD_SIGQUIT.def_static("NewInstance_", (opencascade::handle<OSD_SIGQUIT> (*)(const Standard_CString)) &OSD_SIGQUIT::NewInstance, "None", py::arg("theMessage"));
cls_OSD_SIGQUIT.def_static("get_type_name_", (const char * (*)()) &OSD_SIGQUIT::get_type_name, "None");
cls_OSD_SIGQUIT.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &OSD_SIGQUIT::get_type_descriptor, "None");
cls_OSD_SIGQUIT.def("DynamicType", (const opencascade::handle<Standard_Type> & (OSD_SIGQUIT::*)() const) &OSD_SIGQUIT::DynamicType, "None");

// CLASS: OSD_SIGSEGV
py::class_<OSD_SIGSEGV, opencascade::handle<OSD_SIGSEGV>, OSD_Signal> cls_OSD_SIGSEGV(mod, "OSD_SIGSEGV", "None");

// Constructors
cls_OSD_SIGSEGV.def(py::init<>());
cls_OSD_SIGSEGV.def(py::init<const Standard_CString>(), py::arg("theMessage"));

// Methods
cls_OSD_SIGSEGV.def_static("Raise_", (void (*)(const Standard_CString)) &OSD_SIGSEGV::Raise, "None", py::arg("theMessage"));
cls_OSD_SIGSEGV.def_static("Raise_", (void (*)(Standard_SStream &)) &OSD_SIGSEGV::Raise, "None", py::arg("theMessage"));
cls_OSD_SIGSEGV.def_static("NewInstance_", (opencascade::handle<OSD_SIGSEGV> (*)(const Standard_CString)) &OSD_SIGSEGV::NewInstance, "None", py::arg("theMessage"));
cls_OSD_SIGSEGV.def_static("get_type_name_", (const char * (*)()) &OSD_SIGSEGV::get_type_name, "None");
cls_OSD_SIGSEGV.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &OSD_SIGSEGV::get_type_descriptor, "None");
cls_OSD_SIGSEGV.def("DynamicType", (const opencascade::handle<Standard_Type> & (OSD_SIGSEGV::*)() const) &OSD_SIGSEGV::DynamicType, "None");

// CLASS: OSD_SIGSYS
py::class_<OSD_SIGSYS, opencascade::handle<OSD_SIGSYS>, OSD_Signal> cls_OSD_SIGSYS(mod, "OSD_SIGSYS", "None");

// Constructors
cls_OSD_SIGSYS.def(py::init<>());
cls_OSD_SIGSYS.def(py::init<const Standard_CString>(), py::arg("theMessage"));

// Methods
cls_OSD_SIGSYS.def_static("Raise_", (void (*)(const Standard_CString)) &OSD_SIGSYS::Raise, "None", py::arg("theMessage"));
cls_OSD_SIGSYS.def_static("Raise_", (void (*)(Standard_SStream &)) &OSD_SIGSYS::Raise, "None", py::arg("theMessage"));
cls_OSD_SIGSYS.def_static("NewInstance_", (opencascade::handle<OSD_SIGSYS> (*)(const Standard_CString)) &OSD_SIGSYS::NewInstance, "None", py::arg("theMessage"));
cls_OSD_SIGSYS.def_static("get_type_name_", (const char * (*)()) &OSD_SIGSYS::get_type_name, "None");
cls_OSD_SIGSYS.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &OSD_SIGSYS::get_type_descriptor, "None");
cls_OSD_SIGSYS.def("DynamicType", (const opencascade::handle<Standard_Type> & (OSD_SIGSYS::*)() const) &OSD_SIGSYS::DynamicType, "None");


}

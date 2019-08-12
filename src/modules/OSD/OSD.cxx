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

void bind_OSD_SysType(py::module &);
void bind_OSD_WhoAmI(py::module &);
void bind_OSD_FromWhere(py::module &);
void bind_OSD_KindFile(py::module &);
void bind_OSD_LockType(py::module &);
void bind_OSD_OpenMode(py::module &);
void bind_OSD_OEMType(py::module &);
void bind_OSD_LoadMode(py::module &);
void bind_OSD_SingleProtection(py::module &);
void bind_OSD_OpenStream(py::module &);
void bind_OSD_Path(py::module &);
void bind_OSD_Chronometer(py::module &);
void bind_OSD_Timer(py::module &);
void bind_OSD_Parallel(py::module &);
void bind_OSD_ThreadFunction(py::module &);
void bind_OSD_PThread(py::module &);
void bind_OSD_Thread(py::module &);
void bind_OSD_Function(py::module &);
void bind_OSD(py::module &);
void bind_OSD_Error(py::module &);
void bind_OSD_FileNode(py::module &);
void bind_OSD_Directory(py::module &);
void bind_OSD_DirectoryIterator(py::module &);
void bind_OSD_Disk(py::module &);
void bind_OSD_Environment(py::module &);
void bind_OSD_Exception(py::module &);
void bind_OSD_Exception_ACCESS_VIOLATION(py::module &);
void bind_OSD_Exception_ARRAY_BOUNDS_EXCEEDED(py::module &);
void bind_OSD_Exception_CTRL_BREAK(py::module &);
void bind_OSD_Exception_FLT_DENORMAL_OPERAND(py::module &);
void bind_OSD_Exception_FLT_DIVIDE_BY_ZERO(py::module &);
void bind_OSD_Exception_FLT_INEXACT_RESULT(py::module &);
void bind_OSD_Exception_FLT_INVALID_OPERATION(py::module &);
void bind_OSD_Exception_FLT_OVERFLOW(py::module &);
void bind_OSD_Exception_FLT_STACK_CHECK(py::module &);
void bind_OSD_Exception_FLT_UNDERFLOW(py::module &);
void bind_OSD_Exception_ILLEGAL_INSTRUCTION(py::module &);
void bind_OSD_Exception_INT_DIVIDE_BY_ZERO(py::module &);
void bind_OSD_Exception_INT_OVERFLOW(py::module &);
void bind_OSD_Exception_INVALID_DISPOSITION(py::module &);
void bind_OSD_Exception_IN_PAGE_ERROR(py::module &);
void bind_OSD_Exception_NONCONTINUABLE_EXCEPTION(py::module &);
void bind_OSD_Exception_PRIV_INSTRUCTION(py::module &);
void bind_OSD_Exception_STACK_OVERFLOW(py::module &);
void bind_OSD_Exception_STATUS_NO_MEMORY(py::module &);
void bind_OSD_File(py::module &);
void bind_OSD_FileIterator(py::module &);
void bind_OSD_Host(py::module &);
void bind_OSD_MAllocHook(py::module &);
void bind_OSD_MemInfo(py::module &);
void bind_OSD_OSDError(py::module &);
void bind_OSD_PerfMeter(py::module &);
void bind_OSD_Process(py::module &);
void bind_OSD_Protection(py::module &);
void bind_OSD_SharedLibrary(py::module &);
void bind_OSD_Signal(py::module &);
void bind_OSD_SIGBUS(py::module &);
void bind_OSD_SIGHUP(py::module &);
void bind_OSD_SIGILL(py::module &);
void bind_OSD_SIGINT(py::module &);
void bind_OSD_SIGKILL(py::module &);
void bind_OSD_SIGQUIT(py::module &);
void bind_OSD_SIGSEGV(py::module &);
void bind_OSD_SIGSYS(py::module &);

PYBIND11_MODULE(OSD, mod) {

py::module::import("OCCT.TCollection");
py::module::import("OCCT.Standard");
py::module::import("OCCT.Aspect");
py::module::import("OCCT.Quantity");
py::module::import("OCCT.NCollection");

bind_OSD_SysType(mod);
bind_OSD_WhoAmI(mod);
bind_OSD_FromWhere(mod);
bind_OSD_KindFile(mod);
bind_OSD_LockType(mod);
bind_OSD_OpenMode(mod);
bind_OSD_OEMType(mod);
bind_OSD_LoadMode(mod);
bind_OSD_SingleProtection(mod);
bind_OSD_OpenStream(mod);
bind_OSD_Path(mod);
bind_OSD_Chronometer(mod);
bind_OSD_Timer(mod);
bind_OSD_Parallel(mod);
bind_OSD_ThreadFunction(mod);
bind_OSD_PThread(mod);
bind_OSD_Thread(mod);
bind_OSD_Function(mod);
bind_OSD(mod);
bind_OSD_Error(mod);
bind_OSD_FileNode(mod);
bind_OSD_Directory(mod);
bind_OSD_DirectoryIterator(mod);
bind_OSD_Disk(mod);
bind_OSD_Environment(mod);
bind_OSD_Exception(mod);
bind_OSD_Exception_ACCESS_VIOLATION(mod);
bind_OSD_Exception_ARRAY_BOUNDS_EXCEEDED(mod);
bind_OSD_Exception_CTRL_BREAK(mod);
bind_OSD_Exception_FLT_DENORMAL_OPERAND(mod);
bind_OSD_Exception_FLT_DIVIDE_BY_ZERO(mod);
bind_OSD_Exception_FLT_INEXACT_RESULT(mod);
bind_OSD_Exception_FLT_INVALID_OPERATION(mod);
bind_OSD_Exception_FLT_OVERFLOW(mod);
bind_OSD_Exception_FLT_STACK_CHECK(mod);
bind_OSD_Exception_FLT_UNDERFLOW(mod);
bind_OSD_Exception_ILLEGAL_INSTRUCTION(mod);
bind_OSD_Exception_INT_DIVIDE_BY_ZERO(mod);
bind_OSD_Exception_INT_OVERFLOW(mod);
bind_OSD_Exception_INVALID_DISPOSITION(mod);
bind_OSD_Exception_IN_PAGE_ERROR(mod);
bind_OSD_Exception_NONCONTINUABLE_EXCEPTION(mod);
bind_OSD_Exception_PRIV_INSTRUCTION(mod);
bind_OSD_Exception_STACK_OVERFLOW(mod);
bind_OSD_Exception_STATUS_NO_MEMORY(mod);
bind_OSD_File(mod);
bind_OSD_FileIterator(mod);
bind_OSD_Host(mod);
bind_OSD_MAllocHook(mod);
bind_OSD_MemInfo(mod);
bind_OSD_OSDError(mod);
bind_OSD_PerfMeter(mod);
bind_OSD_Process(mod);
bind_OSD_Protection(mod);
bind_OSD_SharedLibrary(mod);
bind_OSD_Signal(mod);
bind_OSD_SIGBUS(mod);
bind_OSD_SIGHUP(mod);
bind_OSD_SIGILL(mod);
bind_OSD_SIGINT(mod);
bind_OSD_SIGKILL(mod);
bind_OSD_SIGQUIT(mod);
bind_OSD_SIGSEGV(mod);
bind_OSD_SIGSYS(mod);

}

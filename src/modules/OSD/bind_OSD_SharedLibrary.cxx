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
#include <Standard.hxx>
#include <Standard_TypeDef.hxx>
#include <OSD_LoadMode.hxx>
#include <OSD_Function.hxx>
#include <Standard_PCharacter.hxx>
#include <OSD_SharedLibrary.hxx>

void bind_OSD_SharedLibrary(py::module &mod){

py::class_<OSD_SharedLibrary, std::unique_ptr<OSD_SharedLibrary, Deleter<OSD_SharedLibrary>>> cls_OSD_SharedLibrary(mod, "OSD_SharedLibrary", "Interface to dynamic library loader. Provides tools to load a shared library and retrieve the address of an entry point.");

// Constructors
cls_OSD_SharedLibrary.def(py::init<>());
cls_OSD_SharedLibrary.def(py::init<const Standard_CString>(), py::arg("aFilename"));

// Fields

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

// Enums

}
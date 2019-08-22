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
#include <Standard_Handle.hxx>
#include <IGESData_ReadWriteModule.hxx>
#include <IGESData_Protocol.hxx>
#include <Standard_Transient.hxx>
#include <Standard_TypeDef.hxx>
#include <IGESData_IGESEntity.hxx>
#include <IGESData_NodeOfWriterLib.hxx>
#include <IGESData_WriterLib.hxx>

void bind_IGESData_WriterLib(py::module &mod){

py::class_<IGESData_WriterLib> cls_IGESData_WriterLib(mod, "IGESData_WriterLib", "None");

// Constructors
cls_IGESData_WriterLib.def(py::init<const opencascade::handle<IGESData_Protocol> &>(), py::arg("aprotocol"));
cls_IGESData_WriterLib.def(py::init<>());

// Fields

// Methods
// cls_IGESData_WriterLib.def_static("operator new_", (void * (*)(size_t)) &IGESData_WriterLib::operator new, "None", py::arg("theSize"));
// cls_IGESData_WriterLib.def_static("operator delete_", (void (*)(void *)) &IGESData_WriterLib::operator delete, "None", py::arg("theAddress"));
// cls_IGESData_WriterLib.def_static("operator new[]_", (void * (*)(size_t)) &IGESData_WriterLib::operator new[], "None", py::arg("theSize"));
// cls_IGESData_WriterLib.def_static("operator delete[]_", (void (*)(void *)) &IGESData_WriterLib::operator delete[], "None", py::arg("theAddress"));
// cls_IGESData_WriterLib.def_static("operator new_", (void * (*)(size_t, void *)) &IGESData_WriterLib::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESData_WriterLib.def_static("operator delete_", (void (*)(void *, void *)) &IGESData_WriterLib::operator delete, "None", py::arg(""), py::arg(""));
cls_IGESData_WriterLib.def_static("SetGlobal_", (void (*)(const opencascade::handle<IGESData_ReadWriteModule> &, const opencascade::handle<IGESData_Protocol> &)) &IGESData_WriterLib::SetGlobal, "Adds a couple (Module-Protocol) into the global definition set for this class of Library.", py::arg("amodule"), py::arg("aprotocol"));
cls_IGESData_WriterLib.def("AddProtocol", (void (IGESData_WriterLib::*)(const opencascade::handle<Standard_Transient> &)) &IGESData_WriterLib::AddProtocol, "Adds a couple (Module-Protocol) to the Library, given the class of a Protocol. Takes Resources into account. (if <aprotocol> is not of type TheProtocol, it is not added)", py::arg("aprotocol"));
cls_IGESData_WriterLib.def("Clear", (void (IGESData_WriterLib::*)()) &IGESData_WriterLib::Clear, "Clears the list of Modules of a library (can be used to redefine the order of Modules before action : Clear then refill the Library by calls to AddProtocol)");
cls_IGESData_WriterLib.def("SetComplete", (void (IGESData_WriterLib::*)()) &IGESData_WriterLib::SetComplete, "Sets a library to be defined with the complete Global list (all the couples Protocol/Modules recorded in it)");
cls_IGESData_WriterLib.def("Select", [](IGESData_WriterLib &self, const opencascade::handle<IGESData_IGESEntity> & obj, opencascade::handle<IGESData_ReadWriteModule> & module, Standard_Integer & CN){ Standard_Boolean rv = self.Select(obj, module, CN); return std::tuple<Standard_Boolean, Standard_Integer &>(rv, CN); }, "Selects a Module from the Library, given an Object. Returns True if Select has succeeded, False else. Also Returns (as arguments) the selected Module and the Case Number determined by the associated Protocol. If Select has failed, <module> is Null Handle and CN is zero. (Select can work on any criterium, such as Object DynamicType)", py::arg("obj"), py::arg("module"), py::arg("CN"));
cls_IGESData_WriterLib.def("Start", (void (IGESData_WriterLib::*)()) &IGESData_WriterLib::Start, "Starts Iteration on the Modules (sets it on the first one)");
cls_IGESData_WriterLib.def("More", (Standard_Boolean (IGESData_WriterLib::*)() const) &IGESData_WriterLib::More, "Returns True if there are more Modules to iterate on");
cls_IGESData_WriterLib.def("Next", (void (IGESData_WriterLib::*)()) &IGESData_WriterLib::Next, "Iterates by getting the next Module in the list If there is none, the exception will be raised by Value");
cls_IGESData_WriterLib.def("Module", (const opencascade::handle<IGESData_ReadWriteModule> & (IGESData_WriterLib::*)() const) &IGESData_WriterLib::Module, "Returns the current Module in the Iteration");
cls_IGESData_WriterLib.def("Protocol", (const opencascade::handle<IGESData_Protocol> & (IGESData_WriterLib::*)() const) &IGESData_WriterLib::Protocol, "Returns the current Protocol in the Iteration");

// Enums

}